//
// Created by fexyd on 22/05/26.
//

#ifndef FEXGE_GAMEOBJ_H
#define FEXGE_GAMEOBJ_H
#include <map>
#include <string>
#include <vector>

#include "GameCom.h"

namespace FexGE::Engine
{
    class GameObj
    {
    private:
        std::vector<GameCom*> components;
        int id;
        bool isEnabled;
    public:
        std::string name;

        GameObj(std::string& name);
        ~GameObj();

        void AddComponent(GameCom* component);
        void RemoveComponent(GameCom* component);

        void SetActive(bool active);

        void Update(float dt);

    };
}
#endif //FEXGE_GAMEOBJ_H
