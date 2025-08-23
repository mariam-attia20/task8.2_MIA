// libraries to include
#include <iostream>
#include <string>
#include <vector> // for using vector
#include <cstdlib> // for rand()
#include <ctime>   // for time()

// creat a class for weapons
// attributes: name , damage
// functions: try to hit
class Weapon
{
public:
    std::string name;
    int damage;
     int accuracy;

    Weapon(std::string n, int d , int a) : name(n), damage(d), accuracy(a) {}

    bool tryToHit()
    {                                 // have a pattern (hit, miss, hit, miss,....)
       int result = rand() % 100;    // Flip for next attack
        return result ;                // Return current result (true = hit)
    }
};

// create a class for the characters
// attributes: health , weapon , name
// functions ; attack , if they are alive

class Character
{
public:
    std::string name;
    int health;
    std::vector<Weapon> weapons;

    Character(std::string n, int h, std::vector<Weapon> w) : name(n), health(h), weapons(w)
    { // change the order bec.of we use weapon in the character
    }
    bool Alive()
    {
        if (health > 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    Weapon chooseWeapon() // to choose a weapon randomly
    {
        int index = rand() % weapons.size(); // Random index
        return weapons[index];
    }

    void attack(Character &opponent)
    {
        Weapon currentWeapon = chooseWeapon();

        std::cout << name << " attacks with " << currentWeapon.name << "!"<<" with accuracy : " << currentWeapon.accuracy ;
        if (currentWeapon.tryToHit())
        {
            opponent.health -= currentWeapon.damage;

            if (opponent.health < 0)
                opponent.health = 0;

            std::cout << "ITS A HIT!" << opponent.name << " takes" << currentWeapon.damage << "damage and now has" << opponent.health << "health left." << std::endl;
        }
        else
        {
            std::cout << "MISSED!" << std::endl;
        }
        std::cout << opponent.name << "'s health: " << opponent.health << "\n"
                  << std::endl;
    }
};

// class inheritance for eagh character type
// one for optimuseprime
class optimusprime : public Character
{
public:
    optimusprime()
        : Character( "OptimusPrime", 100, { 
            Weapon("Ion rifle", 6 , 100), 
            Weapon("Energon swords", 12 , 80),
            Weapon("Shoulder Cannon", 45 , 25) 
        }) {}
};

// one for megatron
class megatron : public Character
{
public:
    megatron() : Character( "Megatron", 100, {
            Weapon("Fusion Cannon", 9 , 90),
            Weapon("fusion sword", 18 , 70),
            Weapon("tank mode", 60, 15)
        }) {}

};
// main function
int main()
{
    srand(static_cast<unsigned int>(time(0))); //we use it to generate a rondom numbers every time we run the code

    //robotes...
    optimusprime op;
    megatron mg;

    std::cout << "Battle begins "<< std::endl;

    while (op.Alive() && mg.Alive())
    {
        op.attack(mg);
        if (mg.Alive())
        {
            mg.attack(op);
        }
    }
     std::cout << "Battle ended!" << std::endl;
    if (op.Alive())
    {
        std::cout << op.name << "WINS! with health" << op.health << std::endl;
    }
    else
    {
        std::cout << mg.name << "WINS! with health" << mg.health << std::endl;
    }
    return 0;
}
