[@bs.module "../node_modules/react-simple-maps/lib/Markers.js"] external markers : ReasonReact.reactClass = "default";

let make = (children) => {
  ReasonReact.wrapJsForReason(
    ~reactClass=markers,
    ~props=Js.Obj.empty(),
    children,
  );
};