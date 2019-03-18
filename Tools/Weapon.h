//
// Created by morga on 10/03/2019.
//

#ifndef MONK_WEAPON_H
#define MONK_WEAPON_H
#include <String>

using namespace std;
class Weapon {
public:
    Weapon();

    Weapon(int id, const string &name, const string &type, int attackDamage);

    int getId() const;

    void setId(int id);

    const string &getName() const;

    void setName(const string &name);

    const string &getType() const;

    void setType(const string &type);

    int getAttackDamage() const;

    void setAttackDamage(int attackDamage);

    void print();

    int id;
    string name, type;
    int attackDamage; /* this is a value out of 5 and that is how much deal the weapon will deal*/

};


#endif //MONK_WEAPON_H
