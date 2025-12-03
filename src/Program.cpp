#include "program.hpp"

Program::Program(){
    // Load audio from the resources directory
    bounce.Load("audio/bounce.mp3");
    // Setting volume
    bounce.SetVolume(0.5f);

    // Load a font from the resources directory
    scary.Load("fonts/Scary.ttf");

    // Title text at center of screen
    titleText = "Welcome to Advanced Programming!";
    titleTextSize = MeasureTextEx(scary, titleText.c_str(), 20, 0);

    // Text that will be moving
    bouncingText = "PA0";
    bouncingTextSize = scary.MeasureText(bouncingText, 20.0f, 0.0f);
    
    // Speed and position of moving text
    xSpeed = 2;
    ySpeed = 2;
    xPos = GetRandomValue(0, GetScreenWidth()-bouncingTextSize.x);
    yPos = GetRandomValue(0, GetScreenHeight()-bouncingTextSize.y);

    // Load a texture from the resources directory
	wabbit = LoadTexture("images/wabbit_alpha.png");
}

void Program::Update(){
    // Avoid text from going offscreen
    // If text hits a wall, go the opposite direction
    if (xPos + bouncingTextSize.x >= GetScreenWidth() || xPos <= 0){
        xSpeed *= -1;
        PlaySound(bounce);
    }
    if (yPos + bouncingTextSize.y >= GetScreenHeight() || yPos <= 0){
        ySpeed *= -1;
        PlaySound(bounce);
    }

    xPos += xSpeed;
    yPos += ySpeed;    
}

void Program::Draw(){
    // Set background color
    ClearBackground(GRAY);

    // Draw title text in the middle of the screen
    raylib::Vector2 position = raylib::Vector2((GetScreenWidth()/2 - titleTextSize.GetX()/2), (GetScreenHeight()/2 - titleTextSize.GetY()/2));
    scary.DrawText(titleText, position, 20.0f, 0.0f, WHITE);

    // Draw the moving text
    scary.DrawText(bouncingText, xPos, yPos, 20.0f, 0.0f, WHITE);

    // Bunny :)
    wabbit.Draw(GetScreenWidth()/2 - wabbit.width/2, GetScreenHeight()/2 - wabbit.height/2 + 40, WHITE);

    // Coordinate plane used to check if text and image are centered (uncomment to see)
    // DrawLine(0, GetScreenHeight()/2, GetScreenWidth(), GetScreenHeight()/2, WHITE);
    // DrawLine(GetScreenWidth()/2, 0, GetScreenWidth()/2, GetScreenHeight(), WHITE);
}

void Program::Unload(){
    // Cleanup / Unloading assets (fonts, sounds, images/textures)
    bounce.Unload();
    scary.Unload();
    wabbit.Unload();
}

Program::~Program() {
    Unload();
}