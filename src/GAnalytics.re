type t;

[@bs.new] [@bs.module "ganalytics"] external make : string => t = "default";

[@bs.deriving jsConverter]
type eventType = [ | [@bs.as "event"] `Event | [@bs.as "pageview"] `Pageview];

type options = {
  .
  "ec": Js.undefined(string),
  "ea": Js.undefined(string),
  "ev": Js.undefined(string),
  "el": Js.undefined(string),
  "dt": Js.undefined(string),
  "dl": Js.undefined(string),
  "dh": Js.undefined(string),
  "dp": Js.undefined(string),
  "uid": Js.undefined(string),
  "an": Js.undefined(string),
  "aid": Js.undefined(string)
};

[@bs.obj]
external makeOptions :
  (
    ~ec: string=?, /* event category */
    ~ea: string=?, /* event action */
    ~el: string=?, /* event label */
    ~ev: string=?, /* event value */
    ~dt: string=?, /* document title */
    ~dl: string=?, /* document url */
    ~dh: string=?, /* document host */
    ~dp: string=?, /* document path */
    ~uid: string=?, /* user id */
    ~an: string=?, /* application name */
    ~aid: string=?, /* application id */
    unit
  ) =>
  options =
  "";

[@bs.send.pipe : t] external send : (string, options) => unit = "";

let send = (eventType, opts) => send(eventTypeToJs(eventType), opts);