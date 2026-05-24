//
// Created by fexyd on 22/05/26.
//

#include "Time.h"

FexGE::Engine::Gameloop::Time::Time()
{
    previousTime = std::chrono::steady_clock::now();
}

FexGE::Engine::Gameloop::Time::~Time() = default;

float FexGE::Engine::Gameloop::Time::GetDeltaTime()
{

    std::chrono::steady_clock::time_point currentTime = std::chrono::steady_clock::now();

    std::chrono::duration<float> delta = currentTime - previousTime;

    previousTime = currentTime;

    return delta.count();
}