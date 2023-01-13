#pragma once

#include "../interface/layout.hpp"
#include "dynamic.hpp"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>

namespace project
{
    class Main final : public ILayout
    {
        private:
            ILayout* d_;
            sf::FloatRect view_;
            std::unique_ptr<IDynamic> sprite_;

        public:
            Main(std::unique_ptr<IDynamic>);
            void add_sublayout(ILayout* other);
            void update(float dt) override;
            void init(float rectLeft, float rectTop, float rectWidth, float rectHeight) override;
            void update_view(float rectLeft, float rectTop, float rectWidth, float rectHeight) override;
            void draw(sf::RenderTarget* target) const override;
    };
};
