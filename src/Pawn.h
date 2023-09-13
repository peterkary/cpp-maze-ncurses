#ifndef Pawn_h
#define Pawn_h
#include <iostream>
#include <vector>

// abstract (inherited by classes Malfoy Potter and Gem), has at least one virtual function
class Pawn{
    protected:
        int x;
        int y;
        char color;
        char letter;
        virtual ~Pawn();
        Pawn(int,int,char,char);
    public:
        virtual int getMove(std::vector<std::string>) = 0;
};
#endif