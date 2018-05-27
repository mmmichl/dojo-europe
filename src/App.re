let component = ReasonReact.statelessComponent("Hello");

let geographyStyles =
  Geography.styleT(
    ~default=
      ReactDOMRe.Style.make(
        ~fill="#ECEFF1",
        ~stroke="#607D8B",
        ~strokeWidth="0.75",
        ~outline="none",
        (),
      ),
    ~hover=
      ReactDOMRe.Style.make(
        ~fill="#607D8B",
        ~stroke="#607D8B",
        ~strokeWidth="0.75",
        ~outline="none",
        (),
      ),
    ~pressed=
      ReactDOMRe.Style.make(
        ~fill="#FF5722",
        ~stroke="#607D8B",
        ~strokeWidth="0.75",
        ~outline="none",
        (),
      ),
  );
let markerStyles =
  Marker.styleT(
    ~default=
      ReactDOMRe.Style.make(
        ~fill="papayawhip",
        ~stroke="#607D8B",
        ~strokeWidth="0.75",
        (),
      ),
    ~hover=ReactDOMRe.Style.make(~fill="#999", ()),
    ~pressed=ReactDOMRe.Style.make(~fill="#000", ()),
  );

let make = (~locations: array(Entry.t), _children) => {
  ...component,
  render: _self => {
    Js.log(locations);
    let projectionConfig =
      ComposableMap.projectionConfigT(~scale=205, ~rotation=[|(-11), 0, 0|]);

    <div>
      <ComposableMap projectionConfig>
        <ZoomableGroup>
          <Geographies geography="../world-50m.json">
            (
              (geographies, projection) =>
                Array.mapi(
                  (i, geography) =>
                    <Geography
                      key=(string_of_int(i))
                      geography
                      projection
                      style=geographyStyles
                    />,
                  geographies,
                )
            )
          </Geographies>
          <Markers>
            (
              Array.mapi(
                (i, user) => {
                  let (long, lat) = user.Entry.location;
                  let marker = Marker.markerT(~coordinates=[|lat, long|]);
                  <Marker key=(string_of_int(i)) marker style=markerStyles>
                    <circle cx="0" cy="0" r="5px" />
                    <text
                      textAnchor="middle"
                      y="8px"
                      style=(
                        ReactDOMRe.Style.make(
                          ~fontFamily="Roboto, sans-serif",
                          ~fontSize="0.25rem",
                          ~strokeWidth="0",
                          ~fill="#607D8B",
                          (),
                        )
                      )>
                      (ReasonReact.string(user.Entry.username))
                    </text>
                  </Marker>;
                },
                locations,
              )
            )
          </Markers>
        </ZoomableGroup>
      </ComposableMap>
      <div>
        <PostLocation/>
      </div>
    </div>;
  },
};