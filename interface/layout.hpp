#pragma once

#include "./drawable.hpp"

namespace project
{
    class ILayout : public IDrawable
    {
        public:
            virtual void update(float dt) = 0;
            virtual void init(float rectLeft, float rectTop, float rectWidth, float rectHeight) = 0;
            virtual void update_view(float rectLeft, float rectTop, float rectWidth, float rectHeight) = 0;

            virtual ~ILayout() = default;
    };
};
