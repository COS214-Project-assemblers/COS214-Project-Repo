#!/usr/bin/env bash
set -euo pipefail

# 1) Configure once (out-of-source)
cmake -S . -B /app/build 

while true; do
  # Collect watch list 
  find /app/backend -type f \( -name '*.cpp' -o -name '*.hpp' -o -name '*.h' \) -print \
    && echo /app/CMakeLists.txt \
  | entr -n -r /bin/sh -c '
      echo ">> Rebuilding..."
      if cmake --build /app/build -j; then
        echo ">> Build OK. (Re)starting server"
        exec /app/build/main
      else
        echo ">> Build failed. Waiting for changes..."
        sleep 0.5
      fi
    '
done
