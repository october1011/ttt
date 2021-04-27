#pragma once
#include <algorithm>
//#include "io.h"
//#include "data.h"
//#include "helpfunction.h"

int gamechk(Field& field, PLAYER dot, const std::string& winString);


void tictactoe() {
    Field field;
    
    while (true) {
        init(field);
        print(field);
        while (true) {
            human(field);
            print(field);
            if (gamechk(field, HUMAN, "Human win!")) break;
            ai(field);
            print(field);
            if (gamechk(field, AI, "AI win!")) break;
        }
       

        std::string answer;
        std::cout << "Play again? ";
        // one word to separator
        std::cin >> answer;


        // STL <algorithm>
        transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
        // only "y"
        // if (answer != "y")


        if (answer.find('y') != 0) // consider y, yo, ya, yes, yeah, yep, yay, etc
            break;
    }
}

int gamechk(Field& field, PLAYER dot, const std::string& winString) {
    if (winchk(field, dot)) {
        std::cout << winString << std::endl;
        return 1;
    }
    if (isdraw(field)) {
        std::cout << "draw" << std::endl;
        return 1;
    }
    return 0;
}


