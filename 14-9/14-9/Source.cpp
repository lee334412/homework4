#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Base class
class Creature {
private:
    int strength; // How much damage we can inflict
    int hitpoints; // How much damage we can sustain
public:
    Creature() : strength(10), hitpoints(10) {}
    Creature(int newStrength, int newHitpoints) : strength(newStrength), hitpoints(newHitpoints) {}

    virtual string getSpecies() const = 0; // Pure virtual function

    int getStrength() const { return strength; }
    int getHitpoints() const { return hitpoints; }

    void setStrength(int newStrength) { strength = newStrength; }
    void setHitpoints(int newHitpoints) { hitpoints = newHitpoints; }

    virtual int getDamage() const {
        int damage = (rand() % strength) + 1;
        cout << getSpecies() << " attacks for " << damage << " points!" << endl;
        return damage;
    }
};

// Derived classes
class Human : public Creature {
public:
    Human() : Creature() {}
    Human(int newStrength, int newHitpoints) : Creature(newStrength, newHitpoints) {}

    string getSpecies() const override {
        return "Human";
    }
};

class Elf : public Creature {
public:
    Elf() : Creature() {}
    Elf(int newStrength, int newHitpoints) : Creature(newStrength, newHitpoints) {}

    string getSpecies() const override {
        return "Elf";
    }

    int getDamage() const override {
        int damage = Creature::getDamage();
        if ((rand() % 10) == 0) { // 10% chance of magical attack
            cout << "Magical attack inflicts " << damage << " additional damage points!" << endl;
            damage *= 2;
        }
        return damage;
    }
};

class Demon : public Creature {
public:
    Demon() : Creature() {}
    Demon(int newStrength, int newHitpoints) : Creature(newStrength, newHitpoints) {}

    int getDamage() const override {
        int damage = Creature::getDamage();
        if ((rand() % 100) < 5) { // 5% chance of demonic attack
            cout << "Demonic attack inflicts 50 additional damage points!" << endl;
            damage += 50;
        }
        return damage;
    }
};

class Cyberdemon : public Demon {
public:
    Cyberdemon() : Demon() {}
    Cyberdemon(int newStrength, int newHitpoints) : Demon(newStrength, newHitpoints) {}

    string getSpecies() const override {
        return "Cyberdemon";
    }
};

class Balrog : public Demon {
public:
    Balrog() : Demon() {}
    Balrog(int newStrength, int newHitpoints) : Demon(newStrength, newHitpoints) {}

    string getSpecies() const override {
        return "Balrog";
    }

    int getDamage() const override {
        int damage = Demon::getDamage();
        int damage2 = (rand() % getStrength()) + 1;
        cout << "Balrog speed attack inflicts " << damage2 << " additional damage points!" << endl;
        damage += damage2;
        return damage;
    }
};

// Main function to test the classes
int main() {
    srand(static_cast<unsigned>(time(0))); // Seed for random number generator

    // Create objects for each type of creature
    Human human(20, 20);
    Elf elf(20, 20);
    Cyberdemon cyberdemon(20, 20);
    Balrog balrog(20, 20);

    // Test getDamage() method for each creature
    cout << "Testing Human:" << endl;
    for (int i = 0; i < 5; ++i) {
        human.getDamage();
        cout << endl;
    }

    cout << "Testing Elf:" << endl;
    for (int i = 0; i < 5; ++i) {
        elf.getDamage();
        cout << endl;
    }

    cout << "Testing Cyberdemon:" << endl;
    for (int i = 0; i < 5; ++i) {
        cyberdemon.getDamage();
        cout << endl;
    }

    cout << "Testing Balrog:" << endl;
    for (int i = 0; i < 5; ++i) {
        balrog.getDamage();
        cout << endl;
    }

    return 0;
}
