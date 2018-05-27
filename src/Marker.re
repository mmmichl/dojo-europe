[@bs.deriving abstract]
type styleT = {
  default: ReactDOMRe.Style.t,
  hover: ReactDOMRe.Style.t,
  pressed: ReactDOMRe.Style.t,
};

[@bs.deriving abstract]
type markerT = {
  coordinates: array(float)
};

[@bs.deriving abstract]
type jsProps = {
  style: styleT,
  marker: markerT,
};

/* [@bs.module] external zoomableGroup: ReasonReact.reactClass = "../node_modules/react-simple-maps/lib/ZoomableGroup.js"; */
[@bs.module "../node_modules/react-simple-maps/lib/Marker.js"] external markerComp : ReasonReact.reactClass = "default";

let make = (~marker, ~style, children) => {
  ReasonReact.wrapJsForReason(
    ~reactClass=markerComp,
    ~props=jsProps(
      ~marker,
      ~style,
    ),
    children,
  );
};