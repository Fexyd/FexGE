//
// Created by fexyd on 22/05/26.
//

#include "Gameloop.h"

#include <iostream>


FexGE::Engine::CGameloop::CGameloop()
{
    _GameObjManager = new GameObjManager();
}

void FexGE::Engine::CGameloop::Run()
{
    float dt = Time.GetDeltaTime();
    accumulator += dt;

    if (accumulator >= MAX_FRAME_TIME) accumulator = MAX_FRAME_TIME;

    while (accumulator >= FIXED_DT)
    {
        _GameObjManager->Update(dt);
        std::cout << "me estoy corriendo bien rico" << std::endl;
        accumulator -= FIXED_DT;
    }


}
