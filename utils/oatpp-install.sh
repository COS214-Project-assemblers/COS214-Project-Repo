#!/bin/bash
set -e 

sudo whoami &> /dev/null

# Usage ($ denotes beginning terminal line):
# with default dir (~/oatpp) - $ sudo ./oatpp-install.sh
# with custom dir OATPP_DIR=custom_dir $ sudo ./oatpp-install.sh

# Directory where Oat++ will be cloned
OATPP_DIR="${OATPP_DIR:-$HOME/oatpp}"  # default: ~/oatpp if not set externally

# Ensure dir exists
mkdir -p "$OATPP_DIR"

echo "Cloning Oat++ into: $OATPP_DIR"

git clone https://github.com/oatpp/oatpp.git "$OATPP_DIR"

# Build and install
cd "$OATPP_DIR"
mkdir -p build && cd build
cmake ..
make install
