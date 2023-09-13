#ifndef Orc_h
#define Orc_h

#include <ncurses.h>
#include "Pawn.h"

class Orc: public Pawn{
    public:
        Orc(int,int,char,char);
        ~Orc();

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