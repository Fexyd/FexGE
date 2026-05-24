//
// Created by fexyd on 20/05/26.
//

#ifndef FENNEX_GAME_ENGINE___FEXGE_WINDOW_H
#define FENNEX_GAME_ENGINE___FEXGE_WINDOW_H

#include <memory>
#include <vector>
#include <string>

namespace FexGE::Plataform
{
    class CWindow
    {
    private:
        struct Impl;
        std::unique_ptr<Impl> m_impl;
    public:
        CWindow(int w, int h, const std::string& title);
        ~CWindow();

        Impl *getImpl();

        // Window
        void create_Window();

        bool win_is_open();
        void win_close();

        // Render
        void win_clear();
        void win_display();
        void win_draw(int vertexCount, std::vector<float>& vertexArray, float posX, float posY);

        // Input
        void win_pollEvent();

    };
}


#endif //FENNEX_GAME_ENGINE___FEXGE_WINDOW_H
