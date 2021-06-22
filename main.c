#define _CRT_SECURE_NO_WARNINGS 
#include "raylib.h"
#pragma comment(lib, "raylib.lib")

#include "book.h"

int main() {
    int screenWidth = 1500;
    int screenHeight = 540;

    InitWindow(screenWidth, screenHeight, "House Oblonskih...");
   
    const char message[128] = "This sample illustrates a text writing\nanimation effect! Check it out! ;)";
    SetTargetFPS(60);

    setlocale(LC_ALL, "ru");
    FILE* in;
    char book[maxSize] = { 0 };
    safeOpenFile(&in, "BOOOK.txt", "r");
    isEmpty(in);
    int lines = checkLines(in);
    int* mass = (int*)malloc(lines * sizeof(int));
    int* tmp = (int*)malloc(lines * sizeof(int));
    complet(tmp, lines);
    int  lentght = lineSize(in, mass);
    bubbleSort(mass, lines, tmp);
    rewind(in);

    Font fontTtf = LoadFontEx("times.ttf", 22, 0, 500);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        for (int i = 0; i < lines; ++i) {
            memStr(in, tmp[i] - 1);
            fgets(book, 150, in);
            DrawTextEx(fontTtf, book, (Vector2) { 10.0f, 10.0f + i*20.0 }, (float)fontTtf.baseSize, 2, GREEN);
            rewind(in);
        }
        EndDrawing();
    }
    CloseWindow();
    fclose(in);
    free(mass);
    free(tmp);
    return 0;
}