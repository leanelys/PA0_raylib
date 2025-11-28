#pragma once

#include <iostream>
#include <string>
#include "raylib-cpp/raylib-cpp.hpp"


class Program {
    private:
    int xPos;
    int yPos;
    int xSpeed;
    int ySpeed;
    std::string text;

    //raylib methods
    raylib::Sound bounce;
    raylib::Font scary;
    raylib::Vector2 textSize;
    raylib::Texture wabbit;
    
    public:
    Program();
    ~Program();

    void Update();
    void Draw();
    void Unload();    
};