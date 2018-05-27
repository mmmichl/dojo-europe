[@bs.deriving abstract]
type jsProps = {
  /* TODO rest */
  disablePanning: bool,
};

/* [@bs.module] external zoomableGroup: ReasonReact.reactClass = "../node_modules/react-simple-maps/lib/ZoomableGroup.js"; */
[@bs.module "../node_modules/react-simple-maps/lib/ZoomableGroup.js"] external zoomableGroup : ReasonReact.reactClass = "default";

let make = (~disablePanning=false, children) => {
  ReasonReact.wrapJsForReason(
    ~reactClass=zoomableGroup,
    ~props=jsProps(
      ~disablePanning
    ),
    children,
  );
};