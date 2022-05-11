#include "monster.h"

#include <iostream>
#include <stdlib.h>
#include <ctime>
character::character(int l){
    life = l;
}

void character::attack(monster *monster){
    int dmg=std::rand()%20+1;
    monster->life= monster->life - dmg;
}

void character::heal(){
    std::cout << "player healed 30 hp \n";
    life=life+30;
    if (life > 100){
        int overheal = life - 100;
        life=life-overheal;
    }
}