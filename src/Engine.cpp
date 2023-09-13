#include "Engine.h"

Engine::Engine(std::vector<std::string> v){
    this->v = v;
}

Engine::~Engine(){}

//TODO colors, better AI

// Engine function that starts game
void Engine::init(){
    
    // create objects
    Human m(0,0,'G','H');
    Orc p(0,0,'R','O');
    Sword s(0,0,'B','S');

    // ncurses starting point
    initscr();
    curs_set(0); // invisible cursor
    noecho();   // invisible char inputs

/*     // colors
    start_color();
    init_pair(1,COLOR_GREEN,COLOR_GREEN);
    attron(COLOR_PAIR(1));
    attroff(COLOR_PAIR(1)); */
    
    // ncurses: print vector map
    for(std::vector<std::string>::const_iterator i = v.begin(); i != v.end(); i++){
        printw("%s\n",i->c_str());
    }
    
    // print title
    mvprintw(25,10,"Find The sword and beat the Orc!");

    // random seed every run
    srand (time(NULL));
    
    // Game on
    initPos(m,p,s,v);

    // nextRound return: 1 = Human wins, 2 = Orc wins, 3 = player hits Escape
    int r = 0;
    while((r!=1) || (r!=2) || (r!=3)){
        r = nextRound(m,p,s);
        //TODO
        // every r out of 3 in a new ncurses window
        if(r==1){
            getch();
            endwin();
        }
        if(r==2){
            move(23,7);
            printw("GAME OVER! Orc found the Sword first!");
            getch();
            endwin();
        }
        if(r==3){
            move (23,7);
            printw("Do you really want to quit? (y/n)");
            switch(getch()){
                case 'y':
                    endwin();
                    break;
                case 'n':
                    r=0;
                    //TODO
                    // erase message from screen, get back into game
                    //erase();
                    break;
                default:
                    r=3;
            }
        }
    }
}

// draws random (different) initial positions for 3 Human Orc and Sword objects
void Engine::initPos(Human &m,Orc &p,Sword &s,std::vector<std::string> v){

    int y,x;    
    while(1){
        y = rand() % v.size();
        x = rand() % v[y].size();
        if(v[y][x]=='.'){
            m.setY(y);
            m.setX(x);
            mvaddch(y,x,m.getLetter());
            break;
        }
    }

    while(1){
        y = rand() % v.size();
        x = rand() % v[y].size();
        if(v[y][x]=='.' && (x != m.getX() || y != m.getY())){
            p.setY(y);
            p.setX(x);
            mvaddch(y,x,p.getLetter());
            break;
        }
    }
    while(1){
        y = rand() % v.size();
        x = rand() % v[y].size();
        if(v[y][x]=='.'){
            s.setY(y);
            s.setX(x);
            mvaddch(y,x,s.getLetter());
            break;
        }
    }
}

// runs getMove() of objects, checks if they're legal and moves them
int Engine::nextRound(Human &m,Orc &p,Sword &s){
    
    // Human input
    int n = m.getMove(v);
    if(n==1){
        if (mvinch(m.getY(),m.getX()-1) != '*'){
            if(mvinch(m.getY(),m.getX()-1) == 'S'){
                mvaddch(m.getY(),m.getX(),'.');
                m.setX(m.getX()-1);
                mvaddch(m.getY(),m.getX(),m.getLetter());
                move(22,7);
                printw("Congratulations! You found the Sword!");
                return 1;
            }
            else if(mvinch(m.getY(),m.getX()-1) == 'O'){
                return 0;
            }
            else{
                mvaddch(m.getY(),m.getX(),'.');
                m.setX(m.getX()-1);
                mvaddch(m.getY(),m.getX(),m.getLetter());
            }
        }
    }
    if(n==2){
        if (mvinch(m.getY(),m.getX()+1) != '*'){
            if(mvinch(m.getY(),m.getX()+1) == 'S'){
                mvaddch(m.getY(),m.getX(),'.');
                m.setX(m.getX()+1);
                mvaddch(m.getY(),m.getX(),m.getLetter());
                move(22,7);
                printw("Congratulations! You found the Sword!");
                return 1;
            }
            else if(mvinch(m.getY(),m.getX()+1) == 'O'){
                return 0;
            }
            else{
                mvaddch(m.getY(),m.getX(),'.');
                m.setX(m.getX()+1);
                mvaddch(m.getY(),m.getX(),m.getLetter());
            }
        }
    }
    if(n==3){
        if (mvinch(m.getY()-1,m.getX()) != '*'){
            if(mvinch(m.getY()-1,m.getX()) == 'S'){
                mvaddch(m.getY(),m.getX(),'.');
                m.setY(m.getY()-1);
                mvaddch(m.getY(),m.getX(),m.getLetter());
                move(22,7);
                printw("Congratulations! You found the Sword!");
                return 1;
            }
            else if(mvinch(m.getY()-1,m.getX()) == 'O'){
                return 0;
            }
            else{
                mvaddch(m.getY(),m.getX(),'.');
                m.setY(m.getY()-1);
                mvaddch(m.getY(),m.getX(),m.getLetter());
            }
        }
    }
    if(n==4){
        if (mvinch(m.getY()+1,m.getX()) != '*'){
            if(mvinch(m.getY()+1,m.getX()) == 'S'){
                mvaddch(m.getY(),m.getX(),'.');
                m.setY(m.getY()+1);
                mvaddch(m.getY(),m.getX(),m.getLetter());
                move(22,7);
                printw("Congratulations! You found the Sword!");
                return 1;
            }
            else if(mvinch(m.getY()+1,m.getX()) == 'O'){
                return 0;
            }
            else{
                mvaddch(m.getY(),m.getX(),'.');
                m.setY(m.getY()+1);
                mvaddch(m.getY(),m.getX(),m.getLetter());
            }
        }
    }
    if(n==5){
        //mvaddch(m.getY(),m.getX(),m.getLetter());
    }
    if(n==6){
        return 3;
    }
    //refresh();

    // Orc input
    int n1 = p.getMove(v);
    if(n1==1){
        if (mvinch(p.getY(),p.getX()-1) != '*'){
            if(mvinch(p.getY(),p.getX()-1) == 'S'){
                mvaddch(p.getY(),p.getX(),'.');
                p.setX(p.getX()-1);
                mvaddch(p.getY(),p.getX(),p.getLetter());
                move(22,7);
                printw("Oh NO! Filthy Orc has a Sword!");
                return 2;
            }
            else if(mvinch(p.getY(),p.getX()-1) == 'H'){
                return 0;
            }
            else{
                mvaddch(p.getY(),p.getX(),'.');
                p.setX(p.getX()-1);
                mvaddch(p.getY(),p.getX(),p.getLetter());
            }
        }
    }
    if(n1==2){
        if (mvinch(p.getY(),p.getX()+1) != '*'){
            if(mvinch(p.getY(),p.getX()+1) == 'S'){
                mvaddch(p.getY(),p.getX(),'.');
                p.setX(p.getX()+1);
                mvaddch(p.getY(),p.getX(),p.getLetter());
                move(22,7);
                printw("Oh NO! Filthy Orc has a Sword!");
                return 2;
            }
            else if(mvinch(p.getY(),p.getX()+1) == 'H'){
                return 0;
            }
            else{
                mvaddch(p.getY(),p.getX(),'.');
                p.setX(p.getX()+1);
                mvaddch(p.getY(),p.getX(),p.getLetter());
            }
        }
    }
    if(n1==3){
        if (mvinch(p.getY()-1,p.getX()) != '*'){
            if(mvinch(p.getY()-1,p.getX()) == 'S'){
                mvaddch(p.getY(),p.getX(),'.');
                p.setY(p.getY()-1);
                mvaddch(p.getY(),p.getX(),p.getLetter());
                move(22,7);
                printw("Oh NO! Filthy Orc has a Sword!");
                return 2;
            }
            else if(mvinch(p.getY()-1,p.getX()) == 'H'){
                return 0;
            }
            else{
                mvaddch(p.getY(),p.getX(),'.');
                p.setY(p.getY()-1);
                mvaddch(p.getY(),p.getX(),p.getLetter());
            }
        }
    }
    if(n1==4){
        if (mvinch(p.getY()+1,p.getX()) != '*'){
            if(mvinch(p.getY()+1,p.getX()) == 'S'){
                mvaddch(p.getY(),p.getX(),'.');
                p.setY(p.getY()+1);
                mvaddch(p.getY(),p.getX(),p.getLetter());
                move(22,7);
                printw("Oh NO! Filthy Orc has a Sword!");
                return 2;
            }
            else if(mvinch(p.getY()+1,p.getX()) == 'H'){
                return 0;
            }
            else{
                mvaddch(p.getY(),p.getX(),'.');
                p.setY(p.getY()+1);
                mvaddch(p.getY(),p.getX(),p.getLetter());
            }
        }
    }
    //refresh();

    // Sword input
    int w;
    w = rand() % 20;
    if (w==1){
        s.getMove(v);
    }

    refresh();
    return 0;
}