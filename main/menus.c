#include "include/menus.h"

#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#include "include/window_codes.h"

int DrawMainMenu()
{
    float screen_width = GetRenderWidth();
    float screen_height = GetRenderHeight();
  
    BeginDrawing();

        ClearBackground(DARKGRAY);

        DrawText("Wecome to the game!"
               , screen_width/2, screen_height/2 - 20, 20, MAGENTA);

        if (GuiButton((Rectangle){ screen_width/2, screen_height/2 + 20, 100, 20},
                      "Play"))
        {
          HideCursor();
          DisableCursor();
          return START_GAME_CODE;
        }

    EndDrawing();

    return MAIN_MENU_CODE;
}

int DrawPauseMenu()
{
    float screen_width = GetRenderWidth();
    float screen_height = GetRenderHeight();
  
    BeginDrawing();

        ClearBackground(DARKBROWN);

        if (GuiButton((Rectangle){ screen_width/2 - 50, screen_height/2 - 20, 100, 20},
                      "Main menu"))
        {
          return MAIN_MENU_CODE;
        }

        if (GuiButton((Rectangle){ screen_width/2 - 50, screen_height/2 + 20, 100, 20},
                      "Continue"))
        {
          HideCursor();
          DisableCursor();
          return CONTINUE_GAME_CODE;
        }

    EndDrawing();

    return PAUSE_MENU_CODE;
}
