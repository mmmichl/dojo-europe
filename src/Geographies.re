[@bs.deriving abstract]
type jsProps = {
  /* TODO rest */
  disableOptimization: bool,
  geography: string,
};

/* [@bs.module] external zoomableGroup: ReasonReact.reactClass = "../node_modules/react-simple-maps/lib/ZoomableGroup.js"; */
[@bs.module "../node_modules/react-simple-maps/lib/Geographies.js"] external geographies : ReasonReact.reactClass = "default";

let make = (~disableOptimization=false, ~geography, children) => {
  ReasonReact.wrapJsForReason(
    ~reactClass=geographies,
    ~props=jsProps(
      ~disableOptimization,
      ~geography,
    ),
    children,
  );
};