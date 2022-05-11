#ifndef MONSTER_H
#define MONSTER_H
#include "character.h"
class monster
{
public:
    monster(int l, bool r);

    static int mq;
    int life;
    bool ready;

    void attack(character *character);
    void lifetest();
};
#endif // MONSTER_H