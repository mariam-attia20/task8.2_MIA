// libraries to include
#include <iostream>
#include <string>



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
    std:: string name;
   int health;
   Weapon weapon ;
    Character(std::string n, int h , Weapon w):name(n),health(h),weapon(w){ // change the order bec.of we use weapon in the character

    }
    bool Alive(){
        if(health>0){
            return true;
        }
        else{
            return false;
        }
    }
    void attack(Character &opponent){
        std::cout << name << " attacks with " << weapon.name << "!" ;
        if(weapon.tryToHit()){
            opponent.health -= weapon.damage;
            std::cout<<"ITS A HIT!"<<opponent.name<<" takes"<<weapon.damage<<"damage and now has"<<opponent.health<<"health left."<<std::endl;
        }

    }
    
};

// class inheritance for eagh character type
// one for optimuseprime
class optimusprime: public Character{
    public:
    optimusprime():Character( "Optimus Prime",100,Weapon("iron blaster",20)){

    }
};

// one for megatron
class megatron: public Character{
    public:
    megatron():Character( "Optimus Prime",100,Weapon("iron blaster",20)){

    }
};
//main function
int main(){
    optimusprime op;
    megatron mg;
    while(op.Alive() && mg.Alive()){
        op.attack(mg);
        if(mg.Alive()){
            mg.attack(op);
        }
    }
    if(op.Alive()){
        std::cout<<op.name<<"wins!"<<std::endl;
    }
    else{
        std::cout<<mg.name<<"wins!"<<std::endl;
    }
    return 0;
}
