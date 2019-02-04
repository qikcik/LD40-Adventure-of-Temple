#pragma once

class Scene
{
    public:
        Scene() = default;
        virtual ~Scene() = default;

        virtual void onStart() =0;

        virtual void onEvent() =0;
        virtual void onUpdate() =0;
        virtual void onDraw() =0;
};
