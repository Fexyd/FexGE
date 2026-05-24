#include <iostream>
#include <SFML/Window/Window.hpp>

#include "Engine/Gameloop/Gameloop.h"
#include "Engine/Plataform/Window.h"

using namespace FexGE;



int main()
{
    // Inicializar ventana
    Plataform::CWindow win(900, 900, "FexGE");
    FexGE::Engine::CGameloop* gameloop = new FexGE::Engine::CGameloop();
    gameloop->Initialize(win);
    // Game loop
    while (win.win_is_open())
    {
        win.win_pollEvent();

        win.win_clear();

        gameloop->Run();

        win.win_display();
    }
    delete gameloop;
    return 0;
}