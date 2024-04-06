#include "include/raylib.h"
#include "raylib.h"
#include <stdio.h>

int main(int argc, char **argv){
    if(!argv[1]){
        printf("Error:No file provided\n");
        return 1;
    }
    InitWindow(800,600,"Tweply");
    SetTargetFPS(60);
    InitAudioDevice();
    char *file = argv[1];
    Music music = LoadMusicStream(file);
    PlayMusicStream(music);
    while (!WindowShouldClose()) {
        UpdateMusicStream(music);
        if(IsKeyDown(81)){
            WindowShouldClose();
            return 0;
        }
        BeginDrawing();
        ClearBackground(DARKGRAY);
        DrawText("Press q to quit",20, 5, 14, WHITE);
        DrawText("Now Playing",20, 40, 24, WHITE);
        DrawText(file,20, 70, 24, WHITE);
        EndDrawing();
    }
    return 0;
}
