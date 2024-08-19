#include "Model.h"

Model::Model() {
    stage = 1; loop = 1; total = 0; start_time = 0; end_time = 0;
}

Model::~Model() {
    
}

int Model::UD_Collision(int px, int py, Pos p1) {
    if ((px == p1.GetX() && py == p1.GetY()) || (px == p1.GetX() + 1 && py == p1.GetY()) || (px == p1.GetX() && py + 1 == p1.GetY()) || (px == p1.GetX() + 1 && py + 1 == p1.GetY())) {
        return 1;
    }
    return 0;
}

int Model::LR_Collision(int px, int py, Pos p1) {
    if ((px == p1.GetX() && py == p1.GetY()) || (px == p1.GetX() && py == p1.GetY() + 1) || (px + 1 == p1.GetX() && py == p1.GetY() + 1) || (px + 1 == p1.GetX() && py == p1.GetY())) {
        return 1;
    }
    return 0;
}