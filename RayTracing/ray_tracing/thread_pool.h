//
// Created by ura on 24.05.16.
//

#ifndef RAYTRACING_THREAD_POOL_H_H
#define RAYTRACING_THREAD_POOL_H_H

#include <functional>
#include <vector>
#include <mutex>

namespace ImGen {

    class ThreadPool {
        typedef std::function<void()> FunctionT;

        std::mutex task_mutex;
        std::vector<FunctionT> tasks;

        static void execute(ThreadPool &pool);

    public:
        void addTask(FunctionT task);

        void executeAll(int threadsCount);

        ThreadPool();
    };
};


#endif //RAYTRACING_THREAD_POOL_H_H
