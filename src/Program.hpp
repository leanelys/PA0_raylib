#pragma once

#include <iostream>
#include <string>
#include "raylib-cpp/raylib-cpp.hpp"

class Program {
  private:
    std::string bouncingText;  // Text that will be bouncing around the screen
    int xPos;                  // Position of the bouncing text in the x axis
    int yPos;                  // Position of the bouncing text in the y axis
    int xSpeed;                // Speed of the bouncing text in the x axis (horizontal)
    int ySpeed;                // Speed of the bouncing text in the y axis (vertical)

    std::string titleText;          // Text displayed in the center of the screen
    raylib::Vector2 titleTextSize;  // Size of title text

    raylib::Vector2 bouncingTextSize;  // Size of bouncing text
    raylib::Font scary;                // Font of all text
    raylib::Sound bounce;              // Text bounce sound effect
    raylib::Texture wabbit;            // Image
    
  public:
    Program();   // Program constructor
    ~Program();  // Program desctructor

    void Update();
    void Draw();
    void Unload();    
};