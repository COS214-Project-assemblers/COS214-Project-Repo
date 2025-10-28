"use strict";

var _express = _interopRequireDefault(require("express"));
var _path = _interopRequireDefault(require("path"));
var _cors = _interopRequireDefault(require("cors"));
var _xmlhttprequest = require("xmlhttprequest");
function _interopRequireDefault(e) { return e && e.__esModule ? e : { "default": e }; }
var app = (0, _express["default"])();
var port = 3000;
var _dirname = _path["default"].resolve();
app.use((0, _cors["default"])());
app.use(_express["default"].urlencoded({
  extended: false
}));
app.use(_express["default"].json());
app.use(_express["default"]["static"](_path["default"].join(_dirname, 'frontend', 'public')));
app.get(/^\/(?!api).*/, function (req, res) {
  res.sendFile(_path["default"].resolve('frontend', 'public', 'index.html'));
});
app.listen(port, function () {
  console.log("Listening on http://localhost:".concat(port));
});