type t;

[@bs.new] external make : (string, {..}) => t = "GAnalytics";

type sendType =
  | Event
  | Pageview;

[@bs.send.pipe : t] external send : (sendType, {..}) => unit = "";