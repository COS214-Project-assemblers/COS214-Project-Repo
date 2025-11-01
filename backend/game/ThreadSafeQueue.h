#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <string>
#include <atomic>

// A simple thread-safe queue
class SafeQueue {
    std::queue<std::string> q;
    std::mutex mtx;
    std::condition_variable cv;

public:
    void push(const std::string& value) {
        {
            std::lock_guard<std::mutex> lock(mtx);
            q.push(value);
        }
        cv.notify_one(); // wake up worker thread
    }

    bool pop(std::string& out) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [&]{ return !q.empty(); }); // wait until item available
        out = q.front();
        q.pop();
        return true;
    }

    bool try_pop(std::string& out) {
        std::lock_guard<std::mutex> lock(mtx);
        if (q.empty()) return false;
        out = q.front();
        q.pop();
        return true;
    }
};

// Worker that processes queue items while running
// class Plant {
//     SafeQueue tasks;
//     std::atomic<bool> running{false};
//     std::thread worker;

//     void run() {
//         std::cout << "[Plant] Worker started.\n";
//         std::string task;
//         while (running) {
//             if (tasks.pop(task)) {
//                 if (task == "stop") break;
//                 std::cout << "[Plant] Processing task: " << task << std::endl;
//                 std::this_thread::sleep_for(std::chrono::milliseconds(500));
//             }
//         }
//         std::cout << "[Plant] Worker exiting.\n";
//     }

// public:
//     void start() {
//         running = true;
//         worker = std::thread(&Plant::run, this);
//     }

//     void stop() {
//         running = false;
//         tasks.push("stop"); // wake worker so it can exit
//     }

//     void join() {
//         if (worker.joinable()) worker.join();
//     }

//     void addTask(const std::string& t) {
//         tasks.push(t);
//     }
// };

// int main() {
//     Plant plant;
//     plant.start();

//     plant.addTask("water");
//     plant.addTask("fertilize");
//     plant.addTask("prune");

//     std::this_thread::sleep_for(std::chrono::seconds(3));
//     plant.stop();
//     plant.join();
// }
