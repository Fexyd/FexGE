//
// Created by fexyd on 22/05/26.
//

#include "Gameloop.h"



FexGE::Engine::CGameloop::CGameloop()
{
    _GameObjManager = new GameObjManager();
}

FexGE::Engine::CGameloop::~CGameloop()
{
    delete _GameObjManager;
}



void FexGE::Engine::CGameloop::Run()
{
    float dt = Time.GetDeltaTime();
    accumulator += dt;

    if (accumulator >= MAX_FRAME_TIME) accumulator = MAX_FRAME_TIME;

    while (accumulator >= FIXED_DT)
    {
        _GameObjManager->Update(dt);

        accumulator -= FIXED_DT;
    }

    _GameObjManager->Render(dt);
}