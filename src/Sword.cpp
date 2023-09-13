#include "Sword.h"

Sword::Sword(int x,int y,char color,char letter): Pawn (x,y,color,letter)
{
    //cout<<"Sword General Constructor"<<endl;
}

Sword::~Sword(){}

void Sword::setX(int x){
    this->x = x;
}

void Sword::setY(int y){
    this->y = y;
}

void Sword::setColor(char c){
    color = c;
}

void Sword::setLetter(char l){
    letter = l;
}

int Sword::getX(){
    return x;
}

int Sword::getY(){
    return y;
}

char Sword::getColor(){
    return color;
}
char Sword::getLetter(){
    return letter;
}

// Sword (random position every random rounds number)
int Sword::getMove(std::vector<std::string> v){

    int y,x;
    while(1){
        y = rand() % v.size();
        x = rand() % v[y].size();
        if(v[y][x]=='.'){
            mvaddch(this->getY(),this->getX(),'.');
            this->setY(y);
            this->setX(x);
            mvaddch(this->getY(),this->getX(),this->getLetter());
            break;
        }
    }
    return 0;
}