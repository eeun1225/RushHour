#pragma once
#include "Model.h"
#include "Pos.h"

class View {
private:
	Model m1;
public:
    View();
    ~View();
    int getkey();
    void playBackgroundMusic();
    void putxy(int x, int y, const char* str, int color);
    void fillbox(int x1, int y1, int x2, int y2, int color);
    void drawCell(int col, int row);
    void drawMap();
    void drawChar(Pos p);
    void drawCar1(Pos p, int n);
    void drawCar2(Pos p, int n);
    void draw1(Pos p, Pos c1, Pos c2);
    void draw2(Pos p, Pos c1, Pos c2, Pos c3);
    void draw3(Pos m, Pos c1, Pos c2, Pos c3, Pos c4);
    void draw4(Pos m, Pos c1, Pos c2, Pos c3, Pos c4, Pos c5);
    void draw5(Pos m, Pos c1, Pos c2, Pos c3, Pos c4, Pos c5, Pos c6);
    void Stop();
    void start_title();
    void clear_title();
    void end_title();
    void manual();
};

