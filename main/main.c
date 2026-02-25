#include "raylib.h"

#include "include/window_codes.h"
#include "include/main_menu.h"


void DrawCustomCursor()
{
    float screen_width = GetRenderWidth();
    float screen_height = GetRenderHeight();

    float cursor_size = 5.0f;
    DrawRectangle((screen_width + cursor_size)/2,
                  (screen_height + cursor_size)/2,
                  cursor_size - 1, cursor_size - 1, BLACK);
    DrawRectangleLines((screen_width + cursor_size)/2,
                       (screen_height + cursor_size)/2,
                       cursor_size, cursor_size, WHITE);
}

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screen_width = 800;
    int screen_height = 450;

    InitWindow(screen_width, screen_height, "raylib [core] example - basic window");
    HideCursor();
    
    Camera3D camera = { 0 };
    camera.position = (Vector3){ 0.0f, 2.0f, 10.0f };  // Camera position
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 75.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;             // Camera mode type

    int camera_mode = CAMERA_FIRST_PERSON;

    float step = 0.5f;
    int current_window = MAIN_MENU_CODE;

    DisableCursor();
    
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        screen_width = GetRenderWidth();
        screen_height = GetRenderHeight();

        if (current_window == MAIN_MENU_CODE)
        {
            current_window = DrawMainMenu();
            continue;
        }
        
        // Update
        //---------------------------------------------------------------------------------

        // if (IsKeyDown(KEY_S))
        // {
        //     camera.position.x += step;
        // }

        // if (IsKeyDown(KEY_W))
        // {
        //     camera.position.x -= step;
        // }

        // if (IsKeyDown(KEY_A))
        // {
        //     camera.position.z += step;
        // }

        // if (IsKeyDown(KEY_D))
        // {
        //     camera.position.z -= step;
        // }
        
        UpdateCamera(&camera, camera_mode);            
        
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(DARKGRAY);

            BeginMode3D(camera);
            
                static Vector3 cube_position = { 0.0f, 0.0f, 0.0f };
                DrawCube(cube_position, 2.0f, 2.0f, 2.0f, RED);
                // DrawCubeWires(cubePosition, 2.0f, 2.0f, 2.0f, MAROON);

                DrawGrid(20, 1.0f);

            EndMode3D();

            DrawFPS(10, 10);
            DrawText(TextFormat("- Screen Width: %i", screen_width), 30, 30, 20, WHITE);
            DrawText(TextFormat("- Screen Height: %i", screen_height), 30, 60, 20, WHITE);
            DrawText(TextFormat("- Position: (%06.3f, %06.3f, %06.3f)", camera.position.x, camera.position.y, camera.position.z)
                   , 30, 90, 20, WHITE);
            DrawText(TextFormat("- Target: (%06.3f, %06.3f, %06.3f)", camera.target.x, camera.target.y, camera.target.z)
                   , 30, 120, 20, WHITE);
            DrawText(TextFormat("- Up: (%06.3f, %06.3f, %06.3f)", camera.up.x, camera.up.y, camera.up.z)
                   , 30, 150, 20, WHITE);

            DrawCustomCursor();
            
        EndDrawing();
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
