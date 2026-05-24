//
// Created by fexyd on 22/05/26.
//

#include "Gameloop.h"
#include <iostream>

#include "../Input/Input.h"

class GameObjTEST : public FexGE::Engine::GameCom
{
private:
    FexGE::Plataform::CWindow* win;
public:

    GameObjTEST(FexGE::Plataform::CWindow* window);

    FexGE::Input::CInput* input = new FexGE::Input::CInput();
    std::vector<float> vertexArray = {10, 0, 0, 10, -10, 0};

    std::pair<float, float> POS = {100, 100};

    void Update(float dt) override
    {
        input->in_update();
        if (input->in_is_key_pressed(FexGE::Input::KEY_S))
        {
            std::cout << "W" << std::endl;
            POS.second += 1;
        }
    }

    void Render(float dt) override
    {
        win->win_draw(3, vertexArray, POS.first, POS.second);
    }
};

GameObjTEST::GameObjTEST(FexGE::Plataform::CWindow* window) : win(window) {}

FexGE::Engine::CGameloop::CGameloop()
{
    _GameObjManager = new GameObjManager();
}

FexGE::Engine::CGameloop::~CGameloop()
{
    delete _GameObjManager;
}

void FexGE::Engine::CGameloop::Initialize(FexGE::Plataform::CWindow& win)
{
    _GameObjManager->Initialize();
    GameObjTEST* _gameComTEST = new GameObjTEST(&win);
    GameObj* gameTestOBJ = _GameObjManager->CreateGameObj("GameObjTEST");
    gameTestOBJ->AddComponent(_gameComTEST);
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