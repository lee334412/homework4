#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// 基類
class Creature {
private:
    int strength; // 能夠造成的傷害
    int hitpoints; // 能夠承受的傷害
public:
    Creature() : strength(10), hitpoints(10) {}
    Creature(int newStrength, int newHitpoints) : strength(newStrength), hitpoints(newHitpoints) {}

    virtual string getSpecies() const = 0; // 純虛函數

    int getStrength() const { return strength; }
    int getHitpoints() const { return hitpoints; }

    void setStrength(int newStrength) { strength = newStrength; }
    void setHitpoints(int newHitpoints) { hitpoints = newHitpoints; }

    virtual int getDamage() const {
        int damage = (rand() % strength) + 1;
        cout << getSpecies() << " 造成 " << damage << " 點傷害!" << endl;
        return damage;
    }
};

// 派生類 Human
class Human : public Creature {
public:
    Human() : Creature() {}
    Human(int newStrength, int newHitpoints) : Creature(newStrength, newHitpoints) {}

    string getSpecies() const override {
        return "Human";
    }
};

// 派生類 Elf
class Elf : public Creature {
public:
    Elf() : Creature() {}
    Elf(int newStrength, int newHitpoints) : Creature(newStrength, newHitpoints) {}

    string getSpecies() const override {
        return "Elf";
    }

    int getDamage() const override {
        int damage = Creature::getDamage();
        if ((rand() % 10) == 0) { // 10% 機率造成魔法攻擊
            cout << "魔法攻擊造成額外 " << damage << " 點傷害!" << endl;
            damage *= 2;
        }
        return damage;
    }
};

// 派生類 Demon
class Demon : public Creature {
public:
    Demon() : Creature() {}
    Demon(int newStrength, int newHitpoints) : Creature(newStrength, newHitpoints) {}

    int getDamage() const override {
        int damage = Creature::getDamage();
        if ((rand() % 100) < 5) { // 5% 機率造成惡魔攻擊
            cout << "惡魔攻擊造成額外 50 點傷害!" << endl;
            damage += 50;
        }
        return damage;
    }
};

// 派生類 Cyberdemon
class Cyberdemon : public Demon {
public:
    Cyberdemon() : Demon() {}
    Cyberdemon(int newStrength, int newHitpoints) : Demon(newStrength, newHitpoints) {}

    string getSpecies() const override {
        return "Cyberdemon";
    }
};

// 派生類 Balrog
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
        cout << "Balrog 的快速攻擊造成額外 " << damage2 << " 點傷害!" << endl;
        damage += damage2;
        return damage;
    }
};

// 戰鬥函數
void battleArena(Creature& creature1, Creature& creature2) {
    while (creature1.getHitpoints() > 0 && creature2.getHitpoints() > 0) {
        int damage1 = creature1.getDamage();
        int damage2 = creature2.getDamage();
        creature1.setHitpoints(creature1.getHitpoints() - damage2);
        creature2.setHitpoints(creature2.getHitpoints() - damage1);
        cout << creature1.getSpecies() << " 剩餘 " << creature1.getHitpoints() << " 點生命值。" << endl;
        cout << creature2.getSpecies() << " 剩餘 " << creature2.getHitpoints() << " 點生命值。" << endl;
        if (creature1.getHitpoints() <= 0 && creature2.getHitpoints() <= 0) {
            cout << "戰鬥結果: 平手!" << endl;
            return;
        }
        if (creature1.getHitpoints() <= 0) {
            cout << creature2.getSpecies() << " 獲勝!" << endl;
            return;
        }
        if (creature2.getHitpoints() <= 0) {
            cout << creature1.getSpecies() << " 獲勝!" << endl;
            return;
        }
    }
}

// 主函數
int main() {
    srand(static_cast<unsigned>(time(0))); // 隨機數生成器的種子

    // 創建每種類型生物的物件
    Human human(20, 20);
    Elf elf(20, 20);
    Cyberdemon cyberdemon(20, 20);
    Balrog balrog(20, 20);

    // 測試 getDamage() 方法
    cout << "測試 Human:" << endl;
    for (int i = 0; i < 5; ++i) {
        human.getDamage();
        cout << endl;
    }

    cout << "測試 Elf:" << endl;
    for (int i = 0; i < 5; ++i) {
        elf.getDamage();
        cout << endl;
    }

    cout << "測試 Cyberdemon:" << endl;
    for (int i = 0; i < 5; ++i) {
        cyberdemon.getDamage();
        cout << endl;
    }

    cout << "測試 Balrog:" << endl;
    for (int i = 0; i < 5; ++i) {
        balrog.getDamage();
        cout << endl;
    }

    // 測試 battleArena 函數
    cout << "測試戰鬥: Human vs Balrog" << endl;
    battleArena(human, balrog);
    cout << endl;

    cout << "測試戰鬥: Elf vs Cyberdemon" << endl;
    battleArena(elf, cyberdemon);
    cout << endl;

    return 0;
}
