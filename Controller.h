#pragma once
#include "View.h"

class Controller {
private:
	View* v1;
	Model* m1;
	Pos p, c1, c2, c3, c4, c5, c6;
public:
	Controller();
	~Controller();
	void pressKey(int key);
	void Start();
	void Clear();
	void moveChar(Pos& p, Pos& p1, Pos& p2, Pos& p3);
	void UP_DOWN(Pos& p1, Pos& p2, Pos& p3, Pos& p4);
	void LEFT_RIGHT(Pos& p1, Pos& p2, Pos& p3, Pos& p4, Pos& p5);
	void Game1();
	void Game2();
	void Game3();
	void Game4();
	void Game5();
	void End();
	void Name();
	void drawStage();
};