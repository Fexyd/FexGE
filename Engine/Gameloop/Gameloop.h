//
// Created by fexyd on 22/05/26.
//

#ifndef FEXGE_GAMELOOP_H
#define FEXGE_GAMELOOP_H
#include <memory>
#include <chrono>

#include "Time.h"
#include "../GameObj/GameObjManager.h"


namespace FexGE::Engine
{
    class CGameloop
    {
    private:
        FexGE::Engine::Gameloop::Time Time;
        float accumulator;

        float MAX_FRAME_TIME = 0.25f;
        float FIXED_DT = 1.0f / 60.0f;

        GameObjManager* _GameObjManager;
    public:
        CGameloop();
        ~CGameloop();
        void Initialize(Plataform::CWindow& win );
        void Run();
    };
}


#endif //FEXGE_GAMELOOP_H
