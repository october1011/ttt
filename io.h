#pragma once
#include <windows.h>
#include <iostream>
#include <random>
#include "helpfunction.h"


int linechk(Field& field, int y, int x, int vx, int vy, int len, PLAYER c);
void print(Field& field);
void human(Field& field);
void ai(Field& field);
int winchk(Field& field, PLAYER c);
int isdraw(Field& field);



//начать новую игру
void init(Field& field) {
    std::cout << " Enter the field length : ";
    std::cout << "\n";
    int val;
    std::cin >> val;
    
    field.towin = val;
    field.szY = val;
    field.szX = val;
    field.map = (PLAYER**)calloc(sizeof(PLAYER*), field.szY);
    for (int y = 0; y < field.szY; ++y) {
        *(field.map + y) = (PLAYER*)calloc(sizeof(PLAYER), field.szX);
        for (int x = 0; x < field.szX; ++x) {
            setval(field.map, y, x, EMPTY);
        }
    }
}
//вывод текущего состояния поля
void print(Field& field) {
    //#include <windows.h>
    
    
    system("cls");
    //std::system("clear");
    printf("-------\n");
    for (int i = 0; i < field.szY; ++i) {
        std::cout << "|";
        for (int j = 0; j < field.szX; ++j) {
            printf("%c|", getval(field.map, i, j));
        }
        std::cout << std::endl;
    }
}
//ход игрока
void human(Field& field) {
    int x;
    int y;
    do {
        printf("Введите координаты хода X и Y (от 1 до %d) через пробел >>", field.szY);
        std::cin >> x >> y;
        // C-style
        // scanf("%d %d", &x, &y);

        // need to check if numbers are entered
        x--; y--;
    } while (!isvalid(field, x, y) || !isempty(field, x, y));
    setval(field.map, y, x, HUMAN);
}
//ход компьютера
void ai(Field& field) {
    int x, y;
    //C++11 <random>
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(0, 3);
    do {
        // C-style
        // x = rand() % field->szX;
        // y = rand() % field->szY;
        x = dist(mt);
        y = dist(mt);
    } while (!isempty(field, x, y));
    setval(field.map, y, x, AI);
}



//проверка победы делающего ход
int winchk(Field& field, PLAYER c) {
    for (int y = 0; y < field.szX; y++) {
        for (int x = 0; x < field.szY; x++) {
            if (linechk(field, y, x, 1, 0, field.towin, c)) return 1;
            if (linechk(field, y, x, 1, 1, field.towin, c)) return 1;
            if (linechk(field, y, x, 0, 1, field.towin, c)) return 1;
            if (linechk(field, y, x, 1, -1, field.towin, c)) return 1;
        }
    }
    return 0;
}

int linechk(Field& field, int y, int x, int vx, int vy, int len, PLAYER c) {
    const int endx = x + (len - 1) * vx;
    const int endy = y + (len - 1) * vy;
    if (!isvalid(field, endx, endy))
        return 0;
    for (int i = 0; i < len; i++)
        if (getval(field.map, (y + i * vy), (x + i * vx)) != c)
            return 0;
    return 1;
}

//проверка на ничью
int isdraw(Field& field) {
    for (int y = 0; y < field.szY; y++)
        for (int x = 0; x < field.szX; x++)
            if (isempty(field, x, y))
                return 0;
    return 1;
}




