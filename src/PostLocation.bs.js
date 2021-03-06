// Generated by BUCKLESCRIPT VERSION 3.1.4, PLEASE EDIT WITH CARE
'use strict';

var List = require("bs-platform/lib/js/list.js");
var Block = require("bs-platform/lib/js/block.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var Fetcher$MyProjectName = require("./Fetcher.bs.js");

function registerLocation(username, _) {
  Fetcher$MyProjectName.fetchPost("https://immense-river-25513.herokuapp.com/add-location", username);
  return username;
}

var credits = /* :: */[
  "werkzeugh",
  /* :: */[
    "aried3r",
    /* :: */[
      "mmmichl",
      /* [] */0
    ]
  ]
];

var component = ReasonReact.reducerComponent("PostLocation");

function make() {
  return /* record */[
          /* debugName */component[/* debugName */0],
          /* reactClassInternal */component[/* reactClassInternal */1],
          /* handedOffState */component[/* handedOffState */2],
          /* willReceiveProps */component[/* willReceiveProps */3],
          /* didMount */component[/* didMount */4],
          /* didUpdate */component[/* didUpdate */5],
          /* willUnmount */component[/* willUnmount */6],
          /* willUpdate */component[/* willUpdate */7],
          /* shouldUpdate */component[/* shouldUpdate */8],
          /* render */(function (self) {
              var match = self[/* state */1];
              switch (match) {
                case 0 : 
                    return React.createElement("span", undefined, React.createElement("button", {
                                    onClick: (function () {
                                        return Curry._1(self[/* send */3], /* Submit */0);
                                      })
                                  }, "entering"));
                case 1 : 
                    return React.createElement("span", undefined, "Sending...");
                case 2 : 
                    return React.createElement("span", undefined, "Submitted");
                
              }
            }),
          /* initialState */(function () {
              return /* Entering */0;
            }),
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */(function (action, _) {
              if (action) {
                return /* Update */Block.__(0, [/* Finished */2]);
              } else {
                return /* UpdateWithSideEffects */Block.__(2, [
                          /* Submitting */1,
                          (function () {
                              List.map((function (c) {
                                      Fetcher$MyProjectName.fetchPost("https://immense-river-25513.herokuapp.com/add-location", c);
                                      return c;
                                    }), credits);
                              return /* () */0;
                            })
                        ]);
              }
            }),
          /* subscriptions */component[/* subscriptions */13],
          /* jsElementWrapped */component[/* jsElementWrapped */14]
        ];
}

exports.registerLocation = registerLocation;
exports.credits = credits;
exports.component = component;
exports.make = make;
/* component Not a pure module */
