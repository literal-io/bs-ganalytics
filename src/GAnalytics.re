type t;

[@bs.new] external make : string => t = "GAnalytics";

[@bs.deriving jsConverter]
type eventType = [ | [@bs.as "event"] `Event | [@bs.as "pageview"] `Pageview];

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
    unit
  ) =>
  _ =
  "";

[@bs.send.pipe : t] external send : (string, {..}) => unit = "";

let send = (eventType, opts) => send(eventTypeToJs(eventType), opts);