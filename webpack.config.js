const path = require("path");
const NodePolyfillPlugin = require("node-polyfill-webpack-plugin");
const CopyPlugin = require('copy-webpack-plugin');

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
      },
        {
        test: /\.(png|jpe?g|gif|svg|webp)$/i,
        type: 'asset/resource',                 // replaces file-loader
        generator: {
          filename: 'assets/[name][contenthash][ext]'  // output path
        }}]
    },
    resolve: {
            fallback: {
              "vm": false,
              "crypto": false
            }
    },
    devServer: {
        static: path.resolve(__dirname, 'frontend', 'public'),
        historyApiFallback: true,   // React Router: serve index.html on refresh
        port: 3000,
        open: true,
        proxy: [
            {
                context: ['/api/'],
                target: 'http://localhost:8000',
                changeOrigin: true,
                secure: false,
                pathRewrite: { '^/api': '' },
                logLevel: 'debug',
            },
            {
                context: ['/ws/'],
                target: 'http://localhost:8001',
                changeOrigin: true,
                secure: false,
                ws: true,
                pathRewrite: { '^/ws': '' },
                logLevel: 'debug',
            },
        ]
    },
    plugins: [
        new NodePolyfillPlugin(),
        new CopyPlugin({
    patterns: [
        {
            from: require('path').resolve(__dirname, 'frontend', 'public', 'assets'),
            to: 'assets'
        }
        ]
    })
    ]
}
