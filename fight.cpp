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

    Weapon(std::string n, int d) : name(n), damage(d) {}

    bool tryToHit()
    {                                 // have a pattern (hit, miss, hit, miss,....)
        static bool hitToggle = true; // Keeps track of hit/miss pattern
        bool result = hitToggle;      // Save current state
        hitToggle = !hitToggle;       // Flip for next attack
        return result;                // Return current result (true = hit)
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

        std::cout << name << " attacks with " << currentWeapon.name << "!";
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
            Weapon("Ion rifle", 6), 
            Weapon("Energon swords", 12),
            Weapon("Shoulder Cannon", 45) 
        }) {}
};

// one for megatron
class megatron : public Character
{
public:
    megatron() : Character( "Megatron", 100, {
            Weapon("Fusion Cannon", 9),
            Weapon("fusion sword", 18),
            Weapon("tank mode", 60)
        }) {}

};
// main function
int main()
{
    srand(time(0));

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
