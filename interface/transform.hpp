#pragma once

namespace project
{
    class FRect;
    class Vec;

    class ITransform
    {
        public:
            virtual FRect getGlobalBounds() const = 0;
            virtual void setPosition(float, float) = 0;
            virtual void setPosition(const Vec&) = 0;
            virtual Vec getPosition() const = 0;
            virtual void move(float, float) = 0;
            virtual void move(const Vec&) = 0;
            virtual ~ITransform() = default;
    };
};
