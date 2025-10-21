#!/bin/bash

set -e 

DOTENV_DIR="${DOTENV_DIR:-$HOME/dotenv}"  # default: ~/oatpp if not set externally

# Ensure dir exists
mkdir -p "$DOTENV_DIR"

echo "Cloning repo..."
cd "$DOTENV_DIR"
git clone https://github.com/laserpants/dotenv-cpp.git

echo "Installing library..."
cd dotenv-cpp
mkdir -p build
cd build
cmake ..
make
sudo make install

