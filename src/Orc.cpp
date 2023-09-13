#include "Orc.h"

Orc::Orc(int x,int y,char color,char letter): Pawn (x,y,color,letter)
{
    //cout<<"Orc General Constructor"<<endl;
}

Orc::~Orc(){}

void Orc::setX(int x){
    this->x = x;
}

void Orc::setY(int y){
    this->y = y;
}

void Orc::setColor(char c){
    color = c;
}

void Orc::setLetter(char l){
    letter = l;
}

int Orc::getX(){
    return x;
}

int Orc::getY(){
    return y;
}

char Orc::getColor(){
    return color;
}
char Orc::getLetter(){
    return letter;
}

// Orc (O) (red) AI MOVEMENT (as smart as possible)

int Orc::getMove(std::vector<std::string> v){
    
//TODO: make the Orc smarter
/*     //1. scans map to find gems' position (segmentation fault)
    int i,j,y,x;
    bool g;
    for(i=0;i<v.size();i++){
        for(j=0;v[i].size();j++){
            if (v[i][j] == 'G'){
                    //printw("FOUND IT!");
                    y = i;
                    x = j;
                    g = true;
            }
        }
        if(g == true) i == v.size();
    }

    // random moves based on gems' position
    int move = rand() % 3;
    switch(move){
        case 0:
            if ((x < this->getX()) && (mvinch(this->getY(),this->getX()-1) != '*')){
                move = 1;
            }
        case 1:
            if ((x > this->getX()) && (mvinch(this->getY(),this->getX()+1) != '*')){
                move = 2;
            }
        case 2:
            if ((y < this->getY()) && (mvinch(this->getY()-1,this->getX()) != '*')){
                move = 3;
            }
        case 3:
            if ((y > this->getY()) && (mvinch(this->getY()+1,this->getX()) != '*')){
                move = 3;
            }
    } */

    // fully random moves

    int move = rand() % 3;
    switch(move){
        case 0:
            if (mvinch(this->getY(),this->getX()-1) != '*'){
                move = 1;
                break;
            }
        case 1:
            if (mvinch(this->getY(),this->getX()+1) != '*'){
                move = 2;
                break;
            }
        case 2:
            if (mvinch(this->getY()-1,this->getX()) != '*'){
                move = 3;
                break;
            }        
        case 3:
            if (mvinch(this->getY()+1,this->getX()) != '*'){
                move = 4;
                break;
            }
    }
    return move;
}