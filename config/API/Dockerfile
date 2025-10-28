FROM ubuntu:24.04

# install build tools
RUN apt-get update && \
    apt-get install -y cmake build-essential git entr nlohmann-json3-dev libwebsocketpp-dev libboost-all-dev

# clone oatpp modules
RUN git clone https://github.com/oatpp/oatpp.git /oatpp && cd /oatpp && cmake . && make install
# Dotenv library
RUN mkdir -p /var/log/greenfingers && touch /var/log/greenfingers/log.txt && chmod 666 /var/log/greenfingers/log.txt

WORKDIR /app
COPY backend/dev.sh /usr/local/bin/dev.sh
RUN chmod +x /usr/local/bin/dev.sh

