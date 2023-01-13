#pragma once

#include "dynamic.hpp"
#include "rect.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <vector>

namespace project
{
    class Anim : public IDynamic
    {
        private:
            struct Frame
            {
                IRect rect;
                float duration;
            };

            std::vector<Frame> timeline_;
            sf::Sprite sprite_;

            double total_;
            bool loop_;
            bool play_;

        public:
            Anim(sf::Sprite sprite);
            Anim() = default;
            std::unique_ptr<IDynamic> clone() const override;
            FRect getGlobalBounds() const override;
            void move(float, float) override;
            void move(const Vec&) override;
            void setPosition(float, float) override;
            void setPosition(const Vec&) override;
            Vec getPosition() const override;
            void draw(sf::RenderTarget* target) const override;

            void update(float dt) override;

            void loop(bool);
            void play(bool);

            void set(sf::Sprite sprite);
            void addFrame(IRect frame, float duration);
    };
};
