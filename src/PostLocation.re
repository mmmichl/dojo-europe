let registerLocation = (username: string, success: unit => unit) => {
  Fetcher.fetchPost(
    ~url="https://immense-river-25513.herokuapp.com/add-location",
    ~body=username,
  );
  username;
};

let credits = ["werkzeugh", "aried3r", "mmmichl"];
/* State declaration */
type state =
  | Entering
  | Submitting
  | Finished;

/* Action declaration */
type action =
  | Submit
  | Done;

/* Component template declaration.
   Needs to be **after** state and action declarations! */
let component = ReasonReact.reducerComponent("PostLocation");

let make = _children => {
  ...component,
  initialState: () => Entering,
  reducer: (action, _state) =>
    switch (action) {
    | Submit =>
      ReasonReact.UpdateWithSideEffects(
        Submitting,
        (
          self => {
            List.map(
              c => registerLocation(c, () => self.send(Done)),
              credits,
            );
            ();
          }
        ),
      )
    | Done => ReasonReact.Update(Finished)
    },
  render: self =>
    switch (self.state) {
    | Entering =>
      <span>
        <button onClick=(_event => self.send(Submit))>
          (ReasonReact.string("entering"))
        </button>
      </span>
    | Submitting => <span> (ReasonReact.string("Sending...")) </span>
    | Finished => <span> (ReasonReact.string("Submitted")) </span>
    },
};