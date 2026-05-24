//
// Created by fexyd on 20/05/26.
//

#ifndef FEXGE_INPUT_H
#define FEXGE_INPUT_H
#include <memory>
#include <vector>

#include "InputKeys.h"

namespace FexGE::Input
{
    class CInput
    {
    private:
        // Input Impl
        // Event - SFML

        struct Impl;
        std::unique_ptr<Impl> m_impl;

    public:
        CInput();
        ~CInput();

        void in_update();

        // ID del INPUT
        int in_get_axisRaw(KeyCode key1, KeyCode key2);

        bool in_is_key_down(KeyCode key);
        bool in_is_key_up(KeyCode key1);
        bool in_is_key_pressed(KeyCode key1);

    };
}

#endif //FEXGE_INPUT_H

