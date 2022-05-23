#include "monster.h"
#include "character.h"

#include <iostream>
#include <stdlib.h>
#include <ctime>

int main(){
    std::srand(std::time(NULL));
    monster m1(100, true);
    monster m2(100, true);
    character player(100);
    while(player.life > 0 && monster::mq > 0){
        
        bool playerturn=true;
        std::cout << "-------------------\n";
        std::cout << "monster 1 life: " <<m1.life << "\n" <<"monster 2 life: " <<  m2.life << "\n" << "player life: " << player.life << "\n";
        
        while (playerturn==true)
        {   
            char choice;
            std::cout << "a)ttack / h)eal:";
            std::cin >> choice;
            if(choice=='a'){
                if (monster::mq==2){
                    int monsterchoice;
                    std::cout << "Attack monster [1/2]:";
                    std::cin >> monsterchoice;
                    if(monsterchoice==1) player.attack(&m1);
                    else if(monsterchoice==2) player.attack(&m2);
                }

                if (monster::mq==1){
                    if (m1.ready==true) player.attack(&m1);
                    else player.attack(&m2);
                }
                playerturn=false;
            }
            else if (choice=='h'){
                player.heal();
                playerturn=false;
            }

            else std::cout << "not a valid choice \n";
        }


        while (playerturn==false)
        {
            m1.lifetest();
            m2.lifetest();
            if (m1.ready==true) {std::cout << "player got attacked by monster 1, it dealt "; m1.attack(&player);}
            if (m2.ready==true) {std::cout << "player got attacked by monster 2, it dealt "; m2.attack(&player);}
            playerturn=true;
        }
    }
    std::cout << "game ended! Press any key to exit \n";
    int wait;
    std::cin >> wait;
    return 0;
}
