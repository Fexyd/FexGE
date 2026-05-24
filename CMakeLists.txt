cmake_minimum_required(VERSION 4.2)
project(FexGE)

set(CMAKE_CXX_STANDARD 17)

add_executable(Fennex_Game_Engine___FexGE main.cpp
        Engine/Plataform/Window.h
        Engine/Plataform/Impl_SFML/Impl_SFML_window.cpp
        Engine/Input/Input.h
        Engine/Input/InputKeys.h
        Engine/Input/Impl_SFML/Impl_SFML_input.cpp
        Engine/Gameloop/Gameloop.cpp
        Engine/Gameloop/Gameloop.h
        Engine/GameObj/GameObj.cpp
        Engine/GameObj/GameObj.h
        Engine/GameObj/GameCom.h
        Engine/GameObj/GameObjManager.cpp
        Engine/GameObj/GameObjManager.h
        Engine/GameObj/GameCom.cpp
        Engine/Gameloop/Time.cpp
        Engine/Gameloop/Time.h
)

find_package(SFML REQUIRED COMPONENTS graphics window system)

target_link_libraries(Fennex_Game_Engine___FexGE PRIVATE
        sfml-graphics
        sfml-window
        sfml-system
)