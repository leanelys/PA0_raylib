#include "raylib.h"

#include "resource_dir.h"	// utility header for SearchAndSetResourceDir
#include "program.hpp"

int main () {
    // Utility function from resource_dir.h to find the resources folder and set it as the current working directory so we can load from it
	SearchAndSetResourceDir("resources");

	// Used to load sounds
    InitAudioDevice();

    // Create the window and tell the window to use vsync and work on high DPI displays
	raylib::Window window(1280, 800, "Hello Project Master!!", FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

    // Create program (if we were loading images & fonts, then you need to make sure that you load() them after window creation)
	Program program;

	if (!IsWindowReady()) {
    	TraceLog(LOG_ERROR, "Window failed to initialize!");
    	return 1;
	}

	// Game loop
	while (!WindowShouldClose())  // Run the game until the user presses ESCAPE or the Close button on the window
	{
		BeginDrawing();
		
		program.Update();

		program.Draw();

		// End the frame and get ready for the next one (display frame, poll input, etc...)
		EndDrawing();
	}

	// End the audio device
	CloseAudioDevice();

	// Destroy the window and cleanup the OpenGL context
	window.Close();
	return 0;
}
