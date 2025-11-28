#include "program.hpp"

Program::Program(){
    // Load audio from the resources directory
    bounce.Load("audio/bounce.mp3");
    // Setting volume
    bounce.SetVolume(0.5f);
    // Load a font from from the resources directory
    scary.Load("fonts/Scary.ttf");
    // Text that will be moving
    text = "PA0";
    textSize = scary.MeasureText(text, 20.0f, 0.0f);
    
    // Load a texture from the resources directory
	wabbit = LoadTexture("images/wabbit_alpha.png");

    xSpeed = 2;
    ySpeed = 2;
    xPos = GetRandomValue(0, GetScreenWidth()-textSize.x);
    yPos = GetRandomValue(0, GetScreenHeight()-textSize.y);

}

void Program::Update(){
    // Avoid text from going offscreen
    // If text hits a wall, go the opposite direction
    if (xPos + textSize.x >= GetScreenWidth() || xPos <= 0){
        xSpeed *= -1;
        PlaySound(bounce);
    }
    if (yPos + textSize.y >= GetScreenHeight() || yPos <= 0){
        ySpeed *= -1;
        PlaySound(bounce);
    }

    xPos += xSpeed;
    yPos += ySpeed;
    
    // For debugging
    // std::cout << xPos << " x " << yPos << "y " << GetScreenHeight() << " yScr " << GetScreenWidth() << " xScr " << std::endl ;
}

void Program::Draw(){
    // Set background color
    ClearBackground(GRAY);
    // Draw title text in the middle of the screen
    std::string topText = "Welcome to Advanced Programming!";
    raylib::Vector2 topTextSize = MeasureTextEx(scary, topText.c_str(), 20, 0);
    scary.DrawText(topText, (GetScreenWidth()/2 - topTextSize.GetX()/2), GetScreenHeight()/2.0f, 20.0f, 0.0f, WHITE);
    // Draw the moving text
    scary.DrawText(text, xPos, yPos, 20.0f, 0.0f, WHITE);
    // Bunny :)
    wabbit.Draw(GetScreenWidth()/2 - wabbit.width/2, GetScreenHeight()/2 - wabbit.height/2 + 40, WHITE);
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