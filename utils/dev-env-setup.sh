#!/bin/bash
set -e 

sudo whoami &> /dev/null

sudo apt-get -y install nlohmann-json3-dev libwebsocketpp-dev libboost-all-dev graphviz

mv ../config/c_cpp_properties.json ../.vscode/
