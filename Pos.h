#pragma once
class Pos {
private:
    int x, y;
public:
    Pos() { x = 0; y = 0; }
    ~Pos(){ }
    int GetX() { return x; }
    void SetXY(int px, int py) { x = px; y = py; }
    int GetY() { return y; }
};
