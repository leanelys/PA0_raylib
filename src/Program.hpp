#pragma once

#include <iostream>
#include <string>
#include "raylib-cpp/raylib-cpp.hpp"

class Program {
  private:
    std::string text;  // Text that will be bouncing around the screen
    int xPos;          // Position of the text in the x axis
    int yPos;          // Position of the text in the y axis
    int xSpeed;        // Speed of the text in the x axis (horizontal)
    int ySpeed;        // Speed of the text in the y axis (vertical)

    raylib::Vector2 textSize;  // Size of bouncing text
    raylib::Font scary;        // Font of text
    raylib::Sound bounce;      // Text bounce sound effect
    raylib::Texture wabbit;    // Image
    
  public:
    Program();   // Program constructor
    ~Program();  // Program desctructor

    void Update();
    void Draw();
    void Unload();    
};