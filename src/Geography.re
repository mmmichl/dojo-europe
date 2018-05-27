[@bs.deriving abstract]
type geographyT = {
  id: string,
};


[@bs.deriving abstract]
type styleT = {
  default: ReactDOMRe.Style.t,
  hover: ReactDOMRe.Style.t,
  pressed: ReactDOMRe.Style.t,
};

[@bs.deriving abstract]
type jsProps = {
  geography: geographyT,
  projection: string,
  style: styleT,
};

/* [@bs.module] external zoomableGroup: ReasonReact.reactClass = "../node_modules/react-simple-maps/lib/ZoomableGroup.js"; */
[@bs.module "../node_modules/react-simple-maps/lib/Geography.js"] external geographyComp : ReasonReact.reactClass = "default";

let make = (~geography, ~projection, ~style, children) => {
  ReasonReact.wrapJsForReason(
    ~reactClass=geographyComp,
    ~props=jsProps(
      ~geography,
      ~projection,
      ~style,
    ),
    children,
  );
};