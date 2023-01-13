#include "../header/keyboard.hpp"

namespace project
{
    bool Keyboard::keys[Key_COUNT] = {0};

    bool Keyboard::is_key_pressed(Keyboard::Keys key)
    {
        int keyI = static_cast<int>(key);
        if(keyI < 0 && keyI >= Keyboard::Key_COUNT) return false;

        return keys[keyI];
    }

    void Keyboard::on_key_event(Keyboard::Keys key, bool state)
    {
        int keyI = static_cast<int>(key);

        switch (key)
        {
            case Keys::VK_LEFT:
                keys[keyI] = state;
            case Keys::VK_RIGHT:
                keys[keyI] = state;
            case Keys::VK_DOWN:
                keys[keyI] = state;
            case Keys::VK_UP:
                keys[keyI] = state;
            case Keys::VK_ESCAPE:
                keys[keyI] = state;
            case Keys::VK_SPACE:
                keys[keyI] = state;
            case Keys::VK_RETURN:
                keys[keyI] = state;
            break;
        }
    }
};
