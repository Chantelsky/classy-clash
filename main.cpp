#include "Raylib.h"
#include "raymath.h"
#include "Character.h"

int main()
{
    // window dimensions
    const int windowWidth = 384;
    const int windowHeight = 384;
    InitWindow(windowWidth, windowHeight, "classy-clash");

    // background texture
    Texture2D map = LoadTexture("nature_tileset/background.png");
    Vector2 mapPos{0.0, 0.0};

    Character knight;
    knight.setScreenPos(windowWidth, windowHeight);

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        // start drawing
        BeginDrawing();
        ClearBackground(WHITE);

        mapPos = Vector2Scale(knight.getWorldPos(), -1.f);

        // draw map texture
        DrawTextureEx(map, mapPos, 0.0, 4.0, WHITE);
        knight.tick(GetFrameTime());

        EndDrawing();
    }
    CloseWindow();
}