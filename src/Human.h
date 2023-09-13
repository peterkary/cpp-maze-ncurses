#ifndef Human_h
#define Human_h
#include <ncurses.h>

#include "Pawn.h"

class Human: public Pawn{
    public:
        Human(int,int,char,char);
        ~Human();

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