//
// Created by ura on 24.05.16.
//



#include "thread_pool.h"
#include "utils.h"

#include <functional>
#include <vector>
#include <mutex>
#include <thread>

namespace ImGen {

    void ThreadPool::execute(ThreadPool &pool) {
        pool.task_mutex.lock();
        while (pool.tasks.size() > 0) {
            FunctionT task = pool.tasks.back();
            pool.tasks.pop_back();
            pool.task_mutex.unlock();
            task();
            pool.task_mutex.lock();
        }
        pool.task_mutex.unlock();
    }

    void ThreadPool::addTask(FunctionT task) {
        tasks.push_back(task);
    }

    void ThreadPool::executeAll(int threadsCount) {
        std::vector<std::thread> ts(threadsCount);
        for (int t = 1; t < threadsCount; t++)
            ts[t] = std::thread(
                    [this]() {
                        execute(*this);
                    });
        execute(*this);
        for (int t = 1; t < threadsCount; t++)
            ts[t].join();
    }

    ThreadPool::ThreadPool() { }

};