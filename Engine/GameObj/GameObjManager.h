//
// Created by fexyd on 22/05/26.
//

#ifndef FEXGE_GAMEOBJMANAGER_H
#define FEXGE_GAMEOBJMANAGER_H
#include <vector>

#include "GameObj.h"

namespace FexGE::Engine
{
    class GameObjManager
    {
    private:
        std::vector<GameObj*> _gameObjs; // for everything on this proyect ( for now )

        std::vector<GameObj*> _pendingCreate;
        std::vector<GameObj*> _pendingDestroy;
    public:
        ~GameObjManager();

        void Initialize();
        void Update(int dt);

        GameObj* CreateGameObj(std::string name);
        void DestroyGameObj(GameObj* gameObj);
    };
}

#endif //FEXGE_GAMEOBJMANAGER_H
