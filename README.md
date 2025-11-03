# 🌱 GreenFingers — The Nursery Simulation Game

### Team: **Assemblers**
**Members:**
- Megan Norval (u24575764)
- Morgan Wattrus (u23541068)
- Ané Burger (u24565068)
- Allyson Andre (u23525984)
- Gerard Jordaan (u24568385)
## 🔗 Links
- [Report](https://docs.google.com/document/d/1H16BtzwTWtz6L3_rqmbMIYY68kvFfwOo7rMHRozlUmo/edit?usp=sharing)
- [Doxygen](https://cos214-project-assemblers.github.io/COS214-Project-Repo/files.html)
- [Notion](https://www.notion.so/COS-214-Final-Project-27cd746b5e5f8007a722c42b0529a6e2?source=copy_link)
## 🚀 How to Run

### **1. Clone the Repository**

```bash
https://github.com/COS214-Project-assemblers/COS214-Project-Repo.git
cd COS214-Project-Repo
```
### 2. Prerequisites
- **Docker** installed 
	- https://docs.docker.com/engine/install/
- No existing services should listen on these **ports**:
	- `8000`
	- `8001`
	- `8080`
## 3. `.env` file
Example (recommended) `.env` file, should be placed in `COS214-Project-Repo/config/API/.env`

```sh
LOG_FILE="/var/log/greenfingers/log.txt"
GAME_CONFIG_PATH="/app/GameConfig.json"
```
### 4. Run the Docker Compose

```sh
docker compose up
```
### 4. Access the App
The app is served on http://localhost:8080
## 📖 Project Overview

GreenFingers is a gamified plant nursery simulator developed in C++17 for the COS 214 – Software Design and Patterns module at the University of Pretoria.

The project models the core systems of a functioning nursery: plants, staff, and customers—each represented through object-oriented design and ten (10+) design patterns.
Players interact with an evolving ecosystem where proper plant care, stock management, and customer satisfaction drive success.
## 🎯 Objectives

- Demonstrate mastery of **object-oriented design** and **software architecture**.
- Apply **design patterns** to achieve **flexibility**, **maintainability**, and **scalability**.
- Build an **interactive, extensible simulation** backed by REST API and WebSocket.
- Collaborate effectively using **Git & GitHub** with disciplined version control and testing.
## 🧩 Design Approach

We approached the project using a **gamified simulation model**, emphasizing system interactions and growth mechanics.
Our design prioritizes clarity, pattern cohesion, and responsiveness.
## ⚙️ Technologies Used

### 🖥 Backend

- **Language:** C++ 17
- **Build System:** CMake
- **Libraries:**
    - [Oat++](https://oatpp.io/) REST API
    - [nlohmann/json](https://github.com/nlohmann/json) JSON serialization
    - [GoogleTest](https://github.com/google/googletest) Unit testing
    - [Websocketpp](https://github.com/zaphoyd/websocketpp) Websocket 
- **Documentation:** Doxygen
### 🏗 Infrastructure
- **Docker** containers
- **NGINX** reverse proxy
- **Ubuntu** base image for API runtime
- **Node.js** bridge for frontend integration
### 🌐 Frontend
- **React**
- **IndexedDB support** for local caching
- **WebSocket** real-time updates
## 🧪 Development Practices

- Minimum 10 commits per member
- Branching strategy documented in report (Feature Branching)
* **Automated Testing:** Implemented via GoogleTest
* **Documentation:** Generated using Doxygen
* **CI/CD**:
	* GoogleTest integration testing
	* valgrind memory checks integration testing
	* OpenAI Codex for automated code review and summary on PR open
	* Continuous Doxygen deployment to a remote server when pushed to `dev`, `main`
## 📂 Repository Structure

```
GreenFingers/
├── backend/
│   ├── API/             # Oat++ controllers and DTOs
│   ├── customer/        # Builder & Visitor patterns for customers
│   ├── game/            # Game loop, logger, menu, transactions
│   ├── greenhouse/      # Staff, inventory, manager, sales floor
│   ├── plant/           # Plant types and state patterns
│   ├── WS/              # WebSocket implementation (GreenSock)
│   ├── main.cpp
│   └── server.js
│
├── frontend/            # React app and assets
├── config/              # JSON configs & Docker compose files
├── tests/               # GoogleTest unit tests
├── utils/               # Shared modules and scripts
├── docker-compose.yaml
├── CMakeLists.txt
├── Doxyfile
└── README.md

```

