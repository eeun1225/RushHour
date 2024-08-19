#define _CRT_SECURE_NO_WARNINGS
#include "Controller.h"
#include "Header.h"

Controller::Controller() {
    m1 = new Model();
    v1 = new View();
    p.SetXY(0, 0); c1.SetXY(0, 0);  c2.SetXY(0, 0);  c3.SetXY(0, 0); c4.SetXY(0, 0); c5.SetXY(0, 0); c6.SetXY(0, 0);
}

Controller::~Controller() {
    delete m1;
    delete v1;
}


void Controller::pressKey(int key) {
    switch (key) {
    case KEY_1: LEFT_RIGHT(c1, p, c2, c4, c6); break;
    case KEY_2: UP_DOWN(c2, c1, c3, c5); break;
    case KEY_3: LEFT_RIGHT(c3, p, c2, c4, c6); break;
    case KEY_4: UP_DOWN(c4, c1, c3, c5); break;
    case KEY_5: LEFT_RIGHT(c5, p, c2, c4, c6); break;
    case KEY_6: UP_DOWN(c6, c1, c3, c5); break;
    case KEY_Q:
    case KEY_q: moveChar(p, c1, c3, c5); break;
    case KEY_SPACE: v1->Stop(); break;
    case KEY_esc: system("cls"); exit(0); break;
    default: break;
    }
}

void Controller::Name() {
    char* name = new char[100];
    v1->putxy(3, 5, "NAME : ", WHITE);
    cin >> name;
    m1->Setname(name);
    Game1();
    delete[] name;
}

void Controller::drawStage() {
    switch (m1->GetStage()) {
    case 1: v1->draw1(p, c1, c2); break;
    case 2: v1->draw2(p, c1, c2, c3); break;
    case 3: v1->draw3(p, c1, c2, c3, c4); break;
    case 4: v1->draw4(p, c1, c2, c3, c4, c5); break;
    case 5: v1->draw5(p, c1, c2, c3, c4, c5, c6); break;
    }
}

void Controller::moveChar(Pos& p, Pos& p1, Pos& p2, Pos& p3) {
    while (m1->Getloop() == 1) {
        drawStage();
        int px = p.GetX();
        int py = p.GetY();
        int oldx = p.GetX();
        int oldy = p.GetY();

        int key = v1->getkey();
        switch (key) {
        case KEY_UP: if (py > MAP_Y1 + 1) py--; break;
        case KEY_DOWN: if (py < MAP_Y2 - 2) py++; break;
        default: pressKey(key);
        }

        switch (m1->Getmapdata(py + 1, px)) {
        case 0:
            break;
        case 1:
            py = oldy;
            break;
        case 2:
            m1->Setloop(0);
            Clear();
            break;
        }

        if (m1->UD_Collision(px, py, p1) || m1->UD_Collision(px, py, p2) || m1->UD_Collision(px, py, p3)) {
            px = oldx;
            py = oldy;
        }

        if (oldx != px || oldy != py) {
            v1->drawCell(oldx, oldy);
        }

        p.SetXY(px, py);
    }
}

void Controller::UP_DOWN(Pos& p1, Pos& p2, Pos& p3, Pos& p4) {
    while (m1->Getloop() == 1) {
        drawStage();

        int px = p1.GetX();
        int py = p1.GetY();
        int oldx = px;
        int oldy = py;

        int key = v1->getkey();
        switch (key) {
        case KEY_UP: if (py > MAP_Y1 + 1) py--; break;
        case KEY_DOWN: if (py < MAP_Y2 - 3) py++; break;
        default: pressKey(key);
        }

        switch (m1->Getmapdata(py, px)) {
        case 0:
            break;
        case 1:
        case 2:
            px = oldx;
            py = oldy;
            break;
        }

        if (m1->UD_Collision(px, py, p2) || m1->UD_Collision(px, py, p3) || m1->UD_Collision(px, py, p4)) {
            px = oldx;
            py = oldy;
        }

        if (oldx != px || oldy != py) {
            v1->drawCell(oldx, oldy);
        }

        p1.SetXY(px, py);
    }

}

void Controller::LEFT_RIGHT(Pos& p1, Pos& p2, Pos& p3, Pos& p4, Pos& p5) {
    while (m1->Getloop() == 1) {
        drawStage();

        int px = p1.GetX();
        int py = p1.GetY();
        int oldx = px;
        int oldy = py;

        int key = v1->getkey();
        switch (key) {
        case KEY_RIGHT: if (px < MAP_X2 - 3) px++; break;
        case KEY_LEFT: if (px > MAP_X1) px--; break;
        default: pressKey(key);
        }

        switch (m1->Getmapdata(py, px)) {
        case 0:
            break;
        case 1:
        case 2:
            px = oldx;
            py = oldy;
            break;
        }

        if (m1->LR_Collision(px, py, p2) || m1->LR_Collision(px, py, p3)
            || m1->LR_Collision(px, py, p4) || m1->LR_Collision(px, py, p5)) {
            px = oldx;
            py = oldy;
        }

        if (oldx != px || oldy != py) {
            v1->drawCell(oldx, oldy);
        }

        p1.SetXY(px, py);
    }
}

void Controller::Game1() {
    system("cls");
    textcolor(WHITE);
    _setcursortype(_NOCURSOR);

    p.SetXY(5, 1); c1.SetXY(4, 4); c2.SetXY(6, 4);
    
    while (m1->Getloop() == 1) {
        drawStage();
        m1->SetStart(clock());
        pressKey(v1->getkey());
    }
}

void Controller::Game2() {
    system("cls");
    textcolor(WHITE);
    _setcursortype(_NOCURSOR);

    p.SetXY(5, 1); c1.SetXY(4, 5); c2.SetXY(7, 5); c3.SetXY(5, 6);

    m1->Setloop(1);
    while (m1->Getloop() == 1) {
        drawStage();
        m1->SetStart(clock());
        pressKey(v1->getkey());
    }
}

void Controller::Game3() {
    system("cls");
    textcolor(WHITE);
    _setcursortype(_NOCURSOR);

    p.SetXY(5, 1); c1.SetXY(4, 3); c2.SetXY(7, 3); 
    c3.SetXY(5, 4); c4.SetXY(3, 3);

    m1->Setloop(1);
    while (m1->Getloop() == 1) {
        drawStage();
        m1->SetStart(clock());
        pressKey(v1->getkey());
    }
}

void Controller::Game4() {
    system("cls");
    textcolor(WHITE);
    _setcursortype(_NOCURSOR);

    p.SetXY(5, 1); c1.SetXY(5, 3); c2.SetXY(7, 2); 
    c3.SetXY(4, 5); c4.SetXY(3, 5); c5.SetXY(6, 4);

    m1->Setloop(1);
    while (m1->Getloop() == 1) {
        drawStage();
        m1->SetStart(clock());
        pressKey(v1->getkey());
    }
}

void Controller::Game5() {
    system("cls");
    textcolor(WHITE);
    _setcursortype(_NOCURSOR);

    p.SetXY(5, 1); c1.SetXY(4, 3); c2.SetXY(6, 2); c3.SetXY(5, 4);  
    c4.SetXY(3, 3); c5.SetXY(4, 5); c6.SetXY(7, 4);
   
    m1->Setloop(1);
    while (m1->Getloop() == 1) {
        drawStage();
        m1->SetStart(clock());
        pressKey(v1->getkey());
    }
}

void Controller::Start() {
    v1->start_title();

    if (v1->getkey() == KEY_1) {
        system("cls");
        Name();
    }
    else if (v1->getkey() == KEY_2) {
        v1->manual();
        while (v1->getkey() != KEY_1) {
            v1->getkey();
            if (v1->getkey() == KEY_esc) {
                exit(0);
            }
        }
        system("cls");
        Start();
    }
    else if (v1->getkey() == KEY_esc) {
        system("cls");
        exit(0);
    }
    else {
        Start();
    }
}

void Controller::Clear() {
    if (m1->Getloop() == 0) {
        v1->clear_title();
        m1->SetEnd(clock());
        int dur = m1->GetTime();

        int minutes = (dur / CLOCKS_PER_SEC) / 60;
        int seconds = (dur / CLOCKS_PER_SEC) % 60;

        v1->putxy(12, 10, "최종 시간: ", BLUE);
        cout << (minutes < 10 ? "0" : "") << minutes << ":" << (seconds < 10 ? "0" : "") << seconds << endl;

        int score = 0;
        if (seconds < 10) {
            score = 100;
        }
        else if (seconds >= 10 && minutes < 1) {
            score = 100 - (int)((seconds - 10) * 0.5);
        }
        else if (seconds >= 10 && minutes > 1) {
            score = 100 - (int)(minutes * 10 + (seconds - 10) * 0.5);
        }

        m1->AddTotal(score);

        v1->putxy(14, 12, "SCORE : ", BLUE);
        cout << score << endl;
        v1->putxy(14, 14, "TOTAL : ", BLUE);
        cout << m1->GetTotal() << endl;

        v1->putxy(14, 17, "PRESS ENTER", BLUE);

        int k = v1->getkey();
        while (k != KEY_ENTER) {
            k = v1->getkey();
            if (k == KEY_esc) {
                system("cls");
                exit(0);
            }
        }

        int s = m1->GetStage();
        m1->SetStage(++s);
        if (s == 2) Game2();
        else if (s == 3) Game3();
        else if (s == 4) Game4();
        else if (s == 5) Game5();
        else if (s == 6) End();
    }
}

void Controller::End() {
    v1->end_title();

    gotoxy(9, 10);
    cout << m1->Getname() << " 님 축하드려요!";
    v1->putxy(8, 11, "모든 단계를 성공했습니다.", WHITE);
    v1->putxy(13, 12, "TOTAL : ", WHITE);
    cout << m1->GetTotal();
    v1->putxy(10, 16, "시작 화면으로 1번", WHITE);
    v1->putxy(14, 17, "종료 esc", WHITE);

    if (v1->getkey() == KEY_1) {
        system("cls");
        ~Controller();
        Controller();
        Start();
    }
    else if (v1->getkey() == KEY_esc) {
        system("cls");
        exit(0);
    }
    else {
        End();
    }        
}
