#include "Header.h"
#include "View.h"

View::View() {

}

View::~View() {

}

void View::playBackgroundMusic() {
    PlaySound(TEXT("bg_music.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP | SND_NODEFAULT);
}

int View::getkey() {
    int ch = _getch();
    return (ch != 0xe0) ? ch : (0xe000 | _getch());
}

void View::putxy(int x, int y, const char* str, int color) {
    textcolor(color);
    _setcursortype(_NOCURSOR);
    gotoxy(x, y);
    cout << str;
}

void View::fillbox(int x1, int y1, int x2, int y2, int color) {
    textbackground(color);
    for (int row = y1; row < y2; row++) {
        for (int col = x1; col < x2; col++) {
            putxy(col, row, " ", NULL);
        }
    }
}

void View::drawCell(int col, int row) {
    int cell = m1.Getmapdata(row, col);
    gotoxy((MAP_X1 + col + 1) * 2, MAP_Y1 + row + 1);
    puts(m1.Getcellsymbol(cell));
}

void View::drawMap() {
    for (int row = 0; row < 10; row++) {
        for (int col = 0; col < 10; col++) {
            drawCell(col, row);
        }
    }
}

void View::drawChar(Pos p) {
    gotoxy((MAP_X1 + p.GetX() + 1) * 2, MAP_Y1 + p.GetY() + 1);
    cout << "��";
    gotoxy((MAP_X1 + p.GetX() + 1) * 2, MAP_Y1 + p.GetY() + 2);
    cout << "��";
}

void View::drawCar1(Pos c, int n) {
    gotoxy((MAP_X1 + c.GetX() + 1) * 2, MAP_Y1 + c.GetY() + 1);
    cout << n << " " << n;
}

void View::drawCar2(Pos c, int n) {
    gotoxy((MAP_X1 + c.GetX() + 1) * 2, MAP_Y1 + c.GetY() + 1);
    cout << n;
    gotoxy((MAP_X1 + c.GetX() + 1) * 2, MAP_Y1 + c.GetY() + 2);
    cout << n;
}

void View::draw1(Pos p, Pos c1, Pos c2) {
    drawMap(); drawChar(p); drawCar1(c1, 1);  drawCar2(c2, 2);
}

void View::draw2(Pos p, Pos c1, Pos c2, Pos c3) {
    drawMap(); drawChar(p); drawCar1(c1, 1); drawCar2(c2, 2); drawCar1(c3, 3);
}

void View::draw3(Pos m, Pos c1, Pos c2, Pos c3, Pos c4) {
    drawMap(); drawChar(m); drawCar1(c1, 1); drawCar2(c2, 2); 
    drawCar1(c3, 3); drawCar2(c4, 4);

}

void View::draw4(Pos m, Pos c1, Pos c2, Pos c3, Pos c4, Pos c5) {
    drawMap(); drawChar(m); drawCar1(c1, 1); drawCar2(c2, 2);
    drawCar1(c3, 3); drawCar2(c4, 4); drawCar1(c5, 5);
}

void View::draw5(Pos m, Pos c1, Pos c2, Pos c3, Pos c4, Pos c5, Pos c6) {
    drawMap(); drawChar(m); drawCar1(c1, 1); drawCar2(c2, 2);
    drawCar1(c3, 3); drawCar2(c4, 4); drawCar1(c5, 5); drawCar2(c6, 6);
}

void View::Stop() {
    m1.Setloop(2);
    PlaySound(NULL, NULL, 0);
    system("cls");
    putxy(5, 3, " ##      ##    ", WHITE);
    putxy(5, 4, " ##      ##    ", WHITE);
    putxy(5, 5, " ##      ##    ", WHITE);
    putxy(5, 6, " ##      ##    ", WHITE);
    putxy(5, 7, " ##      ##    ", WHITE);

    int key = getkey();
    if (key == KEY_SPACE) {
        m1.Setloop(1);
        playBackgroundMusic();
        return;
    }
}

void View::manual() {
    system("cls");
    putxy(18, 2, "��뼳��", WHITE);
    putxy(3, 5, " �� ��ֹ� ��ȣ�� ���� �� ����Ű�� �̿��� �̵����Ѷ�. ", YELLOW);
    putxy(3, 6, " ex) 1�� ��ֹ��� ��� 1�� ���� �� ", YELLOW);
    putxy(3, 7, " ����Ű�� ���� �̵���ų �� �ִ�. ", YELLOW);
    putxy(3, 9, " ���� ��� Q,q Ű�� ���� �� �̵������ϴ�.", YELLOW);
    putxy(3, 11, " ���� ��ֹ��� ��� ���Ϸθ� �̵� �����ϴ�.", YELLOW);
    putxy(3, 12, " ���� ��ֹ��� ��� �¿�θ� �̵� �����ϴ�.", YELLOW);
    putxy(3, 14, " !!�� ���ηθ� ������ �� �ִ�!!", YELLOW);
    putxy(3, 16, " �ִ� �ð� �� �������� �����Ͽ���~!", YELLOW);
    putxy(50, 18, "Back 1", WHITE);
}


void View::start_title() {
    system("cls");
    putxy(3, 1, " ####   #   #   ###   #   #", WHITE);
    putxy(3, 2, " #   #  #   #  #   #  #   #", WHITE);
    putxy(3, 3, " #   #  #   #  #      #   #", WHITE);
    putxy(3, 4, " ####   #   #   ###   #####", WHITE);
    putxy(3, 5, " # #    #   #      #  #   #", WHITE);
    putxy(3, 6, " #  #   #   #  #   #  #   #", WHITE);
    putxy(3, 7, " #   #   ###    ###   #   #", WHITE);
    putxy(3, 8, "  ", BLUE);
    putxy(3, 9, "    #   #   ###   #   #  ####  ", WHITE);
    putxy(3, 10, "    #   #  #   #  #   #  #   # ", WHITE);
    putxy(3, 11, "    #   #  #   #  #   #  #   # ", WHITE);
    putxy(3, 12, "    #####  #   #  #   #  ####  ", WHITE);
    putxy(3, 13, "    #   #  #   #  #   #  # #   ", WHITE);
    putxy(3, 14, "    #   #  #   #  #   #  #  #  ", WHITE);
    putxy(3, 15, "    #   #   ###    ###   #   # ", WHITE);

    putxy(10, 18, "���ӽ��� 1��", WHITE);
    putxy(10, 19, "���Ӽ��� 2��", WHITE);
}

void View::end_title() {
    system("cls");
    putxy(3, 2, "  ###  #     ####    ##    ###  ", WHITE);
    putxy(3, 3, " #     #     #      #  #   #  # ", WHITE);
    putxy(3, 4, " #     #     ###    #  #   ###  ", WHITE);
    putxy(3, 5, " #     #     #      ####   # #  ", WHITE);
    putxy(3, 6, "  ###  ####  ####   #  #   #  # ", WHITE);
}

void View::clear_title() {
    system("cls");
    putxy(3, 2, " ##    #  #####  ##   ##  ####### ", WHITE);
    putxy(3, 3, " # #   #  #        # #      ###", WHITE);
    putxy(3, 4, " #  #  #  ####      #        #   ", WHITE);
    putxy(3, 5, " #   # #  #        # #       #    ", WHITE);
    putxy(3, 6, " #    ##  #####  ##   ##     #    ", WHITE);

}
