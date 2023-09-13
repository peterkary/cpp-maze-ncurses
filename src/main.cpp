#include <fstream>
#include <vector>

#include "Engine.h"

std::vector<std::string> readMapToVector(const std::string& filename){
    std::ifstream source;
    source.open(filename);
    std::vector<std::string> map;
    std::string mapline;
    while(getline(source, mapline)){
        map.push_back(mapline);
    }
    return map;
}

int main (int argc,char **argv){

    // take map filename from argv[1], save it in a vector
    std::vector<std::string> map = readMapToVector(argv[1]);

    // create Engine object, run init()
    Engine e(map);
    e.init();
}