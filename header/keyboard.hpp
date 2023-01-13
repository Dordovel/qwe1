#pragma once

namespace project
{
    class Keyboard
    {
        public:
            static const unsigned Key_COUNT = 7;
            enum class Keys
            {
                VK_LEFT,
                VK_RIGHT,
                VK_DOWN,
                VK_UP,
                VK_ESCAPE,
                VK_SPACE,
                VK_RETURN
            };

            static void on_key_event(Keys key, bool state);
            static bool is_key_pressed(Keys key);

        private:
            static bool keys[Key_COUNT];
    };
};
