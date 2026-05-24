//
// Created by fexyd on 22/05/26.
//

#include "GameObj.h"

FexGE::Engine::GameObj::GameObj(std::string& name)
{
    this->name = name;
}

FexGE::Engine::GameObj::~GameObj() {
    for (auto component : components)
    {
        delete component;
    }
};

void FexGE::Engine::GameObj::Update(float dt)
{
    for (auto& component : components) {
        component->Update(dt);
    }
}
void FexGE::Engine::GameObj::AddComponent(FexGE::Engine::GameCom* component)
{
    component->SetParent(this);
    components.push_back(component);
}