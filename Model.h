#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "Pos.h"
#include <iostream>
#include <string>

class Model {
private:
	int stage, loop, total, start_time, end_time;
    const char* cellsymbol[3] = { "  ", "¡á", "¡å" };;
    char name[100];
    const int mapData[10][10] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 2, 1, 1, 1, 1}
    };
public:
    Model();
    ~Model();
    const char* Getcellsymbol(int n) { return cellsymbol[n];  }
    int Getmapdata(int row, int col) { return mapData[row][col]; }
    void SetStage(int s) { stage = s; }
    int GetStage() { return stage;  }
    void Setloop(int i) { loop = i; }
    int Getloop() { return loop; }
    void SetEnd(int t) { end_time = t; }
    void SetStart(int t) { start_time = t; }
    int GetTime() { return end_time - start_time; }
    void SetTotal(int a) { total = a; }
    void AddTotal(int s) { total += s; }
    int GetTotal() { return total; }
    char* Getname() { return name; }
    void Setname(char* n) { strcpy_s(name, sizeof(name), n); }
    int UD_Collision(int px, int py, Pos p1);
    int LR_Collision(int px, int py, Pos p1);
};

