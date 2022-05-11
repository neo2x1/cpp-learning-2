#include "character.h"
#include "monster.h"

#include <iostream>
#include <stdlib.h>
#include <ctime>
int monster::mq = 0;

monster::monster(int l, bool r){
    life = l;
    ready = r;
    mq++;
}

void monster::attack(character *character){
    int dmg=std::rand()%20+1;
    std::cout << dmg << "\n";
    character->life= character->life - dmg;
}

void monster::lifetest(){
    if(life<=0){
        if (ready==true) { mq--;
        std::cout << "monster fainted! \n";}
        ready=false;
    }
}