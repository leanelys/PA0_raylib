#include "program.hpp"

Program::Program(){
    // Load a audio from the resources directory
    bounce.Load("audio/bounce.mp3");
    // Setting volume
    bounce.SetVolume(0.5f);
    // Load a from from the resources directory
    scary.Load("fonts/Scary.ttf");
    // Text that will be moving
    text = "Welcome Project Master!!";
    textSize = scary.MeasureText(text, 20.0f, 0.0f);
    
    // Load a texture from the resources directory
	wabbit = LoadTexture("images/wabbit_alpha.png");
    xSpeed = 2;
    ySpeed = 2;
    xPos = GetRandomValue(0, GetScreenWidth()-textSize.x);
    yPos = GetRandomValue(0, GetScreenHeight()-textSize.y);

}

void Program::Update(){
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
    
    //debug
    // std::cout << xPos << " x " << yPos << "y " << GetScreenHeight() << " yScr " << GetScreenWidth() << " xScr " << std::endl ;
}

void Program::Draw(){
    ClearBackground(GRAY);
    std::string topText = "Base Project";
    scary.DrawText(topText, (GetScreenWidth()/2 - raylib::TextLength(topText)/2), GetScreenHeight()/2.0f, 20.0f, 0.0f, WHITE);
    scary.DrawText(text, xPos, yPos, 20.0f, 0.0f, WHITE);

    wabbit.Draw(GetScreenWidth()/2 - wabbit.width/2, GetScreenHeight()/2 - wabbit.height/2 + 40, WHITE);

}

void Program::Unload(){
    // cleanup
    // unload our sound so it can be cleaned up
    bounce.Unload();
    // unload our font so it can be cleaned up
    scary.Unload();
	// unload our texture so it can be cleaned 
    wabbit.Unload();
}

Program::~Program() {
    Unload();
}