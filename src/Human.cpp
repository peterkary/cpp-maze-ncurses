#include "Human.h"

Human::Human(int x,int y,char color,char letter): Pawn (x,y,color,letter)
{
    //cout<<"Human General Constructor"<<endl;
}

Human::~Human(){}

void Human::setX(int x){
    this->x = x;
}

void Human::setY(int y){
    this->y = y;
}

void Human::setColor(char c){
    color = c;
}

void Human::setLetter(char l){
    letter = l;
}

int Human::getX(){
    return x;
}

int Human::getY(){
    return y;
}

char Human::getColor(){
    return color;
}
char Human::getLetter(){
    return letter;
}

// INPUT Human (M) (green)

int Human::getMove(std::vector<std::string> v){

    keypad(stdscr, TRUE);
    int move = 0;

    while(!move){

        switch(getch()){
            case KEY_LEFT:
                move = 1;
                break;
            case KEY_RIGHT:
                move = 2;
                break;
            case KEY_UP:
                move = 3;
                break;
            case KEY_DOWN:
                move = 4;
                break;
            case ' ':
                move = 5;
                break;
            case 27:    // 27 = Escape (Press Escape to shutdown game)
                move = 6;
                break;
        }
    }
    return move;
}