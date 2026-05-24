//
// Created by fexyd on 22/05/26.
//

#include "GameObjManager.h"

FexGE::Engine::GameObjManager::~GameObjManager()
{
    for (auto gameObj : _gameObjs)
    {
        delete gameObj;
    }
}



void FexGE::Engine::GameObjManager::Initialize()
{

}

void FexGE::Engine::GameObjManager::Update(int dt)
{
    //Process List Of Destroy
    for (auto gameObj : _pendingDestroy)
    {
        gameObj->Destroy();
        delete gameObj;
    }
    _pendingDestroy.clear();

    //Process List of Creation
    for (auto gameObj : _pendingCreate)
    {
        gameObj->Start();
        _gameObjs.push_back(gameObj);
    }
    _pendingCreate.clear();

    for (auto gameObj : _gameObjs)
    {
        gameObj->Update(dt);
    }
}

void FexGE::Engine::GameObjManager::Render(int dt)
{
    for (auto gameObj : _gameObjs)
    {
        gameObj->Render(dt);
    }
}

FexGE::Engine::GameObj* FexGE::Engine::GameObjManager::CreateGameObj(std::string name)
{
    GameObj* obj = new GameObj(name);
    _pendingCreate.push_back(obj);
    return obj;
}

void FexGE::Engine::GameObjManager::DestroyGameObj(GameObj* gameObj)
{
    _pendingDestroy.push_back(gameObj);
}
