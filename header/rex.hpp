#pragma once

#include "anim.hpp"
#include "dynamic.hpp"
#include "keyboard.hpp"
#include <unordered_map>

namespace project
{
    class Rex : public IDynamic
    {
        private:
            Anim default_;
            Anim* currentFrame_;
            std::unordered_map<Keyboard::Keys, Anim> anims_;

            void changeAnim(Keyboard::Keys);
        public:
            Rex(Anim);
            Rex() = default;
            std::unique_ptr<IDynamic> clone() const override;
            FRect getGlobalBounds() const override;
            void move(float, float) override;
            void move(const Vec&) override;
            void setPosition(float, float) override;
            void setPosition(const Vec&) override;
            Vec getPosition() const override;
            void draw(sf::RenderTarget* target) const override;

            void bindAnim(Keyboard::Keys, Anim);

            void update(float dt) override;
    };
};
