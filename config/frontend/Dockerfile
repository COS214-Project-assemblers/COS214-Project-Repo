FROM node:jod-alpine3.21 AS build

WORKDIR /app
COPY package*.json ./
COPY webpack* ./
COPY .babelrc ./
RUN npm ci
COPY frontend ./frontend
RUN npm run build 

# Serve with Nginx
FROM nginx:alpine
COPY config/frontend/default.conf /etc/nginx/conf.d/default.conf
COPY --from=build /app/frontend/public /usr/share/nginx/html
CMD ["nginx", "-g", "daemon off;"]