#include <iostream>

#include "Engine/Gameloop/Gameloop.h"
#include "Engine/Plataform/Window.h"

using namespace FexGE;


int main()
{
    // Inicializar ventana
    Plataform::CWindow win(900, 900, "FexGE");
    FexGE::Engine::CGameloop* gameloop = new FexGE::Engine::CGameloop();
    // Game loop
    while (win.win_is_open())
    {
        win.win_pollEvent();


        win.win_clear();

        gameloop->Run();

        win.win_display();
    }

    return 0;
}