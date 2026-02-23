#include "raylib.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    HideCursor();
    
    Vector2 pos;

    Camera3D camera = { 0 };
    camera.position = (Vector3){ 0.0f, 10.0f, 10.0f };  // Camera position
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;             // Camera mode type

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //---------------------------------------------------------------------------------

        if (IsKeyDown(KEY_S))
        {
            camera.position.y -= 1;
        }

        if (IsKeyDown(KEY_W))
        {
            camera.position.y += 1;
        }

        if (IsKeyDown(KEY_A))
        {
            camera.position.x -= 1;
        }

        if (IsKeyDown(KEY_D))
        {
            camera.position.x += 1;
        }
        
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            BeginMode3D(camera);
            
                static Vector3 cubePosition = { 0.0f, 0.0f, 0.0f };
                DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, RED);
                DrawCubeWires(cubePosition, 2.0f, 2.0f, 2.0f, MAROON);

                DrawGrid(10, 1.0f);

            EndMode3D();

            // DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

            pos = GetMousePosition();
            static float size = 5.0f;
            DrawRectangle(pos.x, pos.y, size-1, size-1, BLACK);
            DrawRectangleLines(pos.x, pos.y, size, size, WHITE);

        EndDrawing();
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
