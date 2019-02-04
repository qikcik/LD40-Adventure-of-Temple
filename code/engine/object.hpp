#pragma once

class Object
{
    public:
        Object();
        virtual ~Object();

        void onStart();
        virtual void update() {};
        virtual void draw() {};

}
