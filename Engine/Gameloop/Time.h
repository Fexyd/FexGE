//
// Created by fexyd on 22/05/26.
//

#ifndef FEXGE_TIME_H
#define FEXGE_TIME_H

#include <chrono>

namespace FexGE::Engine::Gameloop
{
    class Time
    {
    private:
        float dt;
        std::chrono::steady_clock::time_point previousTime;
    public:
        Time();
        ~Time();
        float GetDeltaTime();
    };
} // FexGE

#endif //FEXGE_TIME_H
