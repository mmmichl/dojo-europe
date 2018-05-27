[@bs.deriving abstract]
type projectionConfigT = {
  scale: int,
  rotation: array(int),
};

[@bs.deriving abstract]
type jsProps = {
  projectionConfig: projectionConfigT,
  [@bs.optional]
  width: int,
  [@bs.optional]
  height: int
};


[@bs.module "../node_modules/react-simple-maps/lib/ComposableMap.js"] external composableMap : ReasonReact.reactClass = "default";

let make = (~projectionConfig, ~width=100, ~height=100, children) => {
  ReasonReact.wrapJsForReason(
    ~reactClass=composableMap,
    ~props=jsProps(
      ~projectionConfig,
      ~width,
      ~height,
    ),
    children,
  );
};