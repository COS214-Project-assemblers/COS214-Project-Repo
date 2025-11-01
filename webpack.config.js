const path = require("path");
const NodePolyfillPlugin = require("node-polyfill-webpack-plugin");

module.exports = {
    entry: "./frontend/src/index.js",
    output: {
        path: path.resolve('frontend', 'public'),
        publicPath: '/',
        filename: "bundle.js"
    },
    mode: "development",
    module: {
        rules: [{
            test: /\.js$/,
            exclude: /node_modules/,
            use: {
            loader: "babel-loader",
            },
        },
        {
            test: /\.css$/,
            use: ["style-loader", "css-loader"],
      },]
    },
    resolve: {
            fallback: {
              "vm": false,
              "crypto": false
            }
    },
    plugins: [
        new NodePolyfillPlugin()
    ]
}
