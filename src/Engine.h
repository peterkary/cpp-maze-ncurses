#ifndef Engine_h
#define Engine_h

#include <ncurses.h>
#include <vector>
#include <time.h>
#include <stdlib.h>

#include "Human.h"
#include "Orc.h"
#include "Sword.h"

class Engine{
        std::vector<std::string> v;
    public:
        Engine(std::vector<std::string>);
        virtual ~Engine();
        void init();
        void initPos(Human &,Orc &,Sword &,std::vector<std::string>);
        int nextRound(Human &,Orc &,Sword &);
};
#endif