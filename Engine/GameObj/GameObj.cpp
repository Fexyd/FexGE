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

void FexGE::Engine::GameObj::AddComponent(FexGE::Engine::GameCom* component)
{
    component->SetParent(this);
    components.push_back(component);
}

void FexGE::Engine::GameObj::SetActive(bool active)
{
    isEnabled = active;
}

void FexGE::Engine::GameObj::Start()
{
    for (auto& component : components) {
        component->Start();
    }
}

void FexGE::Engine::GameObj::OnEnable()
{
    for (auto& component : components)
    {
        component->OnEnable();
    }
}

void FexGE::Engine::GameObj::OnDisable()
{
    for (auto& component : components)
    {
        component->OnDisable();
    }
}


void FexGE::Engine::GameObj::Update(float dt)
{
    for (auto& component : components) {
        component->Update(dt);
    }
}

void FexGE::Engine::GameObj::Render(float dt)
{
    for (auto& component : components) {
        component->Render(dt);
    }
}

void FexGE::Engine::GameObj::Destroy()
{
    for (auto& component : components)
    {
        component->Destroy();
    }
}
