#ifndef Sword_h
#define Sword_h

#include <ncurses.h>
#include "Pawn.h"

class Sword: public Pawn{
    public:
        Sword(int,int,char,char);
        ~Sword();

        void setX(int);
        void setY(int);
        void setColor(char);
        void setLetter(char);

        int getX();
        int getY();
        char getColor();
        char getLetter();   

        int getMove(std::vector<std::string>);
};
#endif