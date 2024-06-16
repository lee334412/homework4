#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// ����
class Creature {
private:
    int strength; // ����y�����ˮ`
    int hitpoints; // ����Ө����ˮ`
public:
    Creature() : strength(10), hitpoints(10) {}
    Creature(int newStrength, int newHitpoints) : strength(newStrength), hitpoints(newHitpoints) {}

    virtual string getSpecies() const = 0; // �µ���

    int getStrength() const { return strength; }
    int getHitpoints() const { return hitpoints; }

    void setStrength(int newStrength) { strength = newStrength; }
    void setHitpoints(int newHitpoints) { hitpoints = newHitpoints; }

    virtual int getDamage() const {
        int damage = (rand() % strength) + 1;
        cout << getSpecies() << " �y�� " << damage << " �I�ˮ`!" << endl;
        return damage;
    }
};

// ������ Human
class Human : public Creature {
public:
    Human() : Creature() {}
    Human(int newStrength, int newHitpoints) : Creature(newStrength, newHitpoints) {}

    string getSpecies() const override {
        return "Human";
    }
};

// ������ Elf
class Elf : public Creature {
public:
    Elf() : Creature() {}
    Elf(int newStrength, int newHitpoints) : Creature(newStrength, newHitpoints) {}

    string getSpecies() const override {
        return "Elf";
    }

    int getDamage() const override {
        int damage = Creature::getDamage();
        if ((rand() % 10) == 0) { // 10% ���v�y���]�k����
            cout << "�]�k�����y���B�~ " << damage << " �I�ˮ`!" << endl;
            damage *= 2;
        }
        return damage;
    }
};

// ������ Demon
class Demon : public Creature {
public:
    Demon() : Creature() {}
    Demon(int newStrength, int newHitpoints) : Creature(newStrength, newHitpoints) {}

    int getDamage() const override {
        int damage = Creature::getDamage();
        if ((rand() % 100) < 5) { // 5% ���v�y���c�]����
            cout << "�c�]�����y���B�~ 50 �I�ˮ`!" << endl;
            damage += 50;
        }
        return damage;
    }
};

// ������ Cyberdemon
class Cyberdemon : public Demon {
public:
    Cyberdemon() : Demon() {}
    Cyberdemon(int newStrength, int newHitpoints) : Demon(newStrength, newHitpoints) {}

    string getSpecies() const override {
        return "Cyberdemon";
    }
};

// ������ Balrog
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
        cout << "Balrog ���ֳt�����y���B�~ " << damage2 << " �I�ˮ`!" << endl;
        damage += damage2;
        return damage;
    }
};

// �԰����
void battleArena(Creature& creature1, Creature& creature2) {
    while (creature1.getHitpoints() > 0 && creature2.getHitpoints() > 0) {
        int damage1 = creature1.getDamage();
        int damage2 = creature2.getDamage();
        creature1.setHitpoints(creature1.getHitpoints() - damage2);
        creature2.setHitpoints(creature2.getHitpoints() - damage1);
        cout << creature1.getSpecies() << " �Ѿl " << creature1.getHitpoints() << " �I�ͩR�ȡC" << endl;
        cout << creature2.getSpecies() << " �Ѿl " << creature2.getHitpoints() << " �I�ͩR�ȡC" << endl;
        if (creature1.getHitpoints() <= 0 && creature2.getHitpoints() <= 0) {
            cout << "�԰����G: ����!" << endl;
            return;
        }
        if (creature1.getHitpoints() <= 0) {
            cout << creature2.getSpecies() << " ���!" << endl;
            return;
        }
        if (creature2.getHitpoints() <= 0) {
            cout << creature1.getSpecies() << " ���!" << endl;
            return;
        }
    }
}

// �D���
int main() {
    srand(static_cast<unsigned>(time(0))); // �H���ƥͦ������ؤl

    // �ЫبC�������ͪ�������
    Human human(20, 20);
    Elf elf(20, 20);
    Cyberdemon cyberdemon(20, 20);
    Balrog balrog(20, 20);

    // ���� getDamage() ��k
    cout << "���� Human:" << endl;
    for (int i = 0; i < 5; ++i) {
        human.getDamage();
        cout << endl;
    }

    cout << "���� Elf:" << endl;
    for (int i = 0; i < 5; ++i) {
        elf.getDamage();
        cout << endl;
    }

    cout << "���� Cyberdemon:" << endl;
    for (int i = 0; i < 5; ++i) {
        cyberdemon.getDamage();
        cout << endl;
    }

    cout << "���� Balrog:" << endl;
    for (int i = 0; i < 5; ++i) {
        balrog.getDamage();
        cout << endl;
    }

    // ���� battleArena ���
    cout << "���վ԰�: Human vs Balrog" << endl;
    battleArena(human, balrog);
    cout << endl;

    cout << "���վ԰�: Elf vs Cyberdemon" << endl;
    battleArena(elf, cyberdemon);
    cout << endl;

    return 0;
}
