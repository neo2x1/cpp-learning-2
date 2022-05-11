#ifndef CHARACTER
#define CHARACTER
class monster;
class character
{
public:
    int life;

    character(int l);

    void attack(monster *monster);

    void heal();
};

#endif