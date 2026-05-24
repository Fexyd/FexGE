//
// Created by fexyd on 22/05/26.
//

#ifndef FEXGE_GAMECOM_H
#define FEXGE_GAMECOM_H


namespace FexGE::Engine
{
    class GameObj;

    class GameCom
    {
    private:
        GameObj* parent;
    public:
        GameCom() : parent(nullptr) {};
        virtual ~GameCom() = default;

        virtual void Start() {}
        virtual void OnEnable() {}
        virtual void OnDisable() {}

        virtual void Update(float dt) {}

        virtual void Render(float dt) {}

        virtual void Destroy() {}

        void SetParent(GameObj* parent);
    };
}

#endif //FEXGE_GAMECOM_H
