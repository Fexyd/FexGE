//
// Created by fexyd on 20/05/26.
//

#include <unordered_map>

#include "../Input.h"
#include <SFML/Graphics.hpp>

struct FexGE::Input::CInput::Impl
{
    std::unordered_map<KeyCode, sf::Keyboard::Key> sfmlMap;

    std::unordered_map<KeyCode, bool> current_state;
    std::unordered_map<KeyCode, bool> previous_state;
};

FexGE::Input::CInput::CInput() : m_impl(std::make_unique<Impl>())
{
    // Letras
    m_impl->sfmlMap[KeyCode::KEY_A] = sf::Keyboard::A;
    m_impl->sfmlMap[KeyCode::KEY_B] = sf::Keyboard::B;
    m_impl->sfmlMap[KeyCode::KEY_C] = sf::Keyboard::C;
    m_impl->sfmlMap[KeyCode::KEY_D] = sf::Keyboard::D;
    m_impl->sfmlMap[KeyCode::KEY_E] = sf::Keyboard::E;
    m_impl->sfmlMap[KeyCode::KEY_F] = sf::Keyboard::F;
    m_impl->sfmlMap[KeyCode::KEY_G] = sf::Keyboard::G;
    m_impl->sfmlMap[KeyCode::KEY_H] = sf::Keyboard::H;
    m_impl->sfmlMap[KeyCode::KEY_I] = sf::Keyboard::I;
    m_impl->sfmlMap[KeyCode::KEY_J] = sf::Keyboard::J;
    m_impl->sfmlMap[KeyCode::KEY_K] = sf::Keyboard::K;
    m_impl->sfmlMap[KeyCode::KEY_L] = sf::Keyboard::L;
    m_impl->sfmlMap[KeyCode::KEY_M] = sf::Keyboard::M;
    m_impl->sfmlMap[KeyCode::KEY_N] = sf::Keyboard::N;
    m_impl->sfmlMap[KeyCode::KEY_O] = sf::Keyboard::O;
    m_impl->sfmlMap[KeyCode::KEY_P] = sf::Keyboard::P;
    m_impl->sfmlMap[KeyCode::KEY_Q] = sf::Keyboard::Q;
    m_impl->sfmlMap[KeyCode::KEY_R] = sf::Keyboard::R;
    m_impl->sfmlMap[KeyCode::KEY_S] = sf::Keyboard::S;
    m_impl->sfmlMap[KeyCode::KEY_T] = sf::Keyboard::T;
    m_impl->sfmlMap[KeyCode::KEY_U] = sf::Keyboard::U;
    m_impl->sfmlMap[KeyCode::KEY_V] = sf::Keyboard::V;
    m_impl->sfmlMap[KeyCode::KEY_W] = sf::Keyboard::W;
    m_impl->sfmlMap[KeyCode::KEY_X] = sf::Keyboard::X;
    m_impl->sfmlMap[KeyCode::KEY_Y] = sf::Keyboard::Y;
    m_impl->sfmlMap[KeyCode::KEY_Z] = sf::Keyboard::Z;

    // Números
    m_impl->sfmlMap[KeyCode::KEY_0] = sf::Keyboard::Num0;
    m_impl->sfmlMap[KeyCode::KEY_1] = sf::Keyboard::Num1;
    m_impl->sfmlMap[KeyCode::KEY_2] = sf::Keyboard::Num2;
    m_impl->sfmlMap[KeyCode::KEY_3] = sf::Keyboard::Num3;
    m_impl->sfmlMap[KeyCode::KEY_4] = sf::Keyboard::Num4;
    m_impl->sfmlMap[KeyCode::KEY_5] = sf::Keyboard::Num5;
    m_impl->sfmlMap[KeyCode::KEY_6] = sf::Keyboard::Num6;
    m_impl->sfmlMap[KeyCode::KEY_7] = sf::Keyboard::Num7;
    m_impl->sfmlMap[KeyCode::KEY_8] = sf::Keyboard::Num8;
    m_impl->sfmlMap[KeyCode::KEY_9] = sf::Keyboard::Num9;

    // Modificadores
    m_impl->sfmlMap[KeyCode::KEY_SHIFT] = sf::Keyboard::LShift;
    m_impl->sfmlMap[KeyCode::KEY_CONTROL] = sf::Keyboard::LControl;
    m_impl->sfmlMap[KeyCode::KEY_ALT] = sf::Keyboard::LAlt;
    m_impl->sfmlMap[KeyCode::KEY_SUPER] = sf::Keyboard::LSystem;

    // Especiales
    m_impl->sfmlMap[KeyCode::KEY_SPACE] = sf::Keyboard::Space;
    m_impl->sfmlMap[KeyCode::KEY_ENTER] = sf::Keyboard::Enter;
    m_impl->sfmlMap[KeyCode::KEY_ESCAPE] = sf::Keyboard::Escape;
    m_impl->sfmlMap[KeyCode::KEY_TAB] = sf::Keyboard::Tab;
    m_impl->sfmlMap[KeyCode::KEY_BACKSPACE] = sf::Keyboard::Backspace;

    // Flechas
    m_impl->sfmlMap[KeyCode::KEY_UP] = sf::Keyboard::Up;
    m_impl->sfmlMap[KeyCode::KEY_DOWN] = sf::Keyboard::Down;
    m_impl->sfmlMap[KeyCode::KEY_LEFT] = sf::Keyboard::Left;
    m_impl->sfmlMap[KeyCode::KEY_RIGHT] = sf::Keyboard::Right;

    // F keys
    m_impl->sfmlMap[KeyCode::KEY_F1] = sf::Keyboard::F1;
    m_impl->sfmlMap[KeyCode::KEY_F2] = sf::Keyboard::F2;
    m_impl->sfmlMap[KeyCode::KEY_F3] = sf::Keyboard::F3;
    m_impl->sfmlMap[KeyCode::KEY_F4] = sf::Keyboard::F4;
    m_impl->sfmlMap[KeyCode::KEY_F5] = sf::Keyboard::F5;
    m_impl->sfmlMap[KeyCode::KEY_F6] = sf::Keyboard::F6;
    m_impl->sfmlMap[KeyCode::KEY_F7] = sf::Keyboard::F7;
    m_impl->sfmlMap[KeyCode::KEY_F8] = sf::Keyboard::F8;
    m_impl->sfmlMap[KeyCode::KEY_F9] = sf::Keyboard::F9;
    m_impl->sfmlMap[KeyCode::KEY_F10] = sf::Keyboard::F10;
    m_impl->sfmlMap[KeyCode::KEY_F11] = sf::Keyboard::F11;
    m_impl->sfmlMap[KeyCode::KEY_F12] = sf::Keyboard::F12;

    // Símbolos
    m_impl->sfmlMap[KeyCode::KEY_COMMA] = sf::Keyboard::Comma;
    m_impl->sfmlMap[KeyCode::KEY_PERIOD] = sf::Keyboard::Period;
    m_impl->sfmlMap[KeyCode::KEY_SLASH] = sf::Keyboard::Slash;
    m_impl->sfmlMap[KeyCode::KEY_SEMICOLON] = sf::Keyboard::Semicolon;
    m_impl->sfmlMap[KeyCode::KEY_APOSTROPHE] = sf::Keyboard::Apostrophe;
    m_impl->sfmlMap[KeyCode::KEY_BRACKET_L] = sf::Keyboard::LBracket;
    m_impl->sfmlMap[KeyCode::KEY_BRACKET_R] = sf::Keyboard::RBracket;
    m_impl->sfmlMap[KeyCode::KEY_BACKSLASH] = sf::Keyboard::Backslash;
    m_impl->sfmlMap[KeyCode::KEY_MINUS] = sf::Keyboard::Hyphen;
    m_impl->sfmlMap[KeyCode::KEY_EQUALS] = sf::Keyboard::Equal;
}


void FexGE::Input::CInput::in_update()
{
    m_impl->previous_state = m_impl->current_state;

    for (int i = 0; i < static_cast<int>(KeyCode::KEY_COUNT); ++i)
    {
        KeyCode key = static_cast<KeyCode>(i);
        sf::Keyboard::Key sfmlKey = m_impl->sfmlMap[key];
        bool isPressed = sf::Keyboard::isKeyPressed(sfmlKey);

        // Guardar en current_state
        m_impl->current_state[key] = isPressed;
    }
}


FexGE::Input::CInput::~CInput() = default;

bool FexGE::Input::CInput::in_is_key_down(KeyCode key)
{
    return m_impl->current_state[key] ? true : false;
}

bool FexGE::Input::CInput::in_is_key_up(KeyCode key)
{
    return m_impl->current_state[key] ? false : true;
}

bool FexGE::Input::CInput::in_is_key_pressed(KeyCode key)
{
    return m_impl->current_state[key];
}
