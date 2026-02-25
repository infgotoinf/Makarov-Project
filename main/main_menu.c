#include "include/main_menu.h"

#include "raylib.h"

#include "include/window_codes.h"

// Returns exit code dependig on pressed button
int DrawMainMenu()
{
    float screen_width = GetRenderWidth();
    float screen_height = GetRenderHeight();
  
    BeginDrawing();

        ClearBackground(DARKGRAY);

        DrawText("Wecome to the game!"
               , screen_width/2, screen_height/2 - 20, 20, MAGENTA);

        DrawText("Press ENTER to play"
               , screen_width/2, screen_height/2 + 20, 20, GOLD);

    EndDrawing();

    if (IsKeyPressed(KEY_ENTER))
    {
        return GAME_CODE;
    }

    return MAIN_MENU_CODE;
}
