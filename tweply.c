#include "include/raylib.h"
#include <stdbool.h>
#include <stdio.h>
#include "raylib.h"
#include <stdlib.h>

struct Node {
    struct Track *track;
    struct Node* next;
};
struct Node *list = NULL;

struct Track {
    char * name;
    int playing;
};
void create(char *array[] ,int n){
    struct Node *node , *last;
    list = (struct Node *)malloc(sizeof(struct Node));
    struct Track *temp = NULL;
    temp = (struct Track *)malloc(sizeof(struct Track));
    temp->name = array[0];
    temp->playing = 1;
    list->track = temp;
    list->next = NULL;
    last = list;
    temp = NULL;
    for(int i = 1 ; i < n ; i++){
        node  = (struct Node *)malloc(sizeof(struct Node));
        temp  = (struct Track *)malloc(sizeof(struct Track));
        temp->name = array[i];
        temp->playing = 0;
        node->track = temp;
        node->next = NULL;
        last->next = node;
        last = node;
    }
}

int main(void){
    char *musics[] = {"music/trackone.mp3","music/tracktwo.mp3","music/trackthree.mp3"};
    InitWindow(800,600,"Tweply");
    SetTargetFPS(60);
    InitAudioDevice();
    create(musics, sizeof(musics)/sizeof(musics[0]));
    Music music;
    struct Node * MusicList = list;
    while(MusicList){
        if(MusicList->track->playing){
            music = LoadMusicStream(MusicList->track->name);
        }
        MusicList = MusicList->next;
    }
    PlayMusicStream(music);
    while (!WindowShouldClose()) {
        struct Node *playlist = list;
        UpdateMusicStream(music);
        if(IsKeyPressed(KEY_Q)){
            WindowShouldClose();
            return 0;
        }
        BeginDrawing();
        ClearBackground(DARKGRAY);
        DrawText("Press q to quit",20, 5, 14, WHITE);
        int pos = 40;
        while (playlist) {
            if (playlist->track->playing) {
                DrawText(TextFormat("-> %s",playlist->track->name), 20, pos, 30 ,WHITE);
            }else {
                DrawText(playlist->track->name, 20, pos, 30 ,WHITE);
            }
            pos = pos + 30;
            playlist = playlist->next;
        }
        EndDrawing();
    }
    return 0;
}
