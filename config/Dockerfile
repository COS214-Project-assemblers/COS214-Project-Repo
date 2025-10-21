FROM ubuntu:24.04

# install build tools
RUN apt-get update && \
    apt-get install -y cmake build-essential git entr

# clone oatpp modules
RUN git clone https://github.com/oatpp/oatpp.git /oatpp && cd /oatpp && cmake . && make install
# Dotenv library
RUN curl -sfS https://dotenvx.sh | sudo sh

WORKDIR /app
COPY backend/dev.sh /usr/local/bin/dev.sh
RUN chmod +x /usr/local/bin/dev.sh

