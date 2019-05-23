#ifndef __WARRIOR_H__
#define __WARRIOR_H__

class Warrior
{
public:
    Warrior(int num, int strength)
        : _numbering(num),
        _strength(strength)
    {}
private:
    int _numbering;
    int _strength;
};

class Dragon
: protected Warrior
{
public:
    Dragon(int num, int strength, int remain)
        : Warrior(num, strength),
        _weapon(num % 3),
        _morale((float)remain / strength) 
    {}
    int weaponGet() { return _weapon; }
    int moraleGet() { return _morale; }
private:
    int _weapon;
    float _morale;
};

class Ninja
: protected Warrior
{
public:
    Ninja(int num, int strength)
        : Warrior(num, strength),
        _weapon1(num % 3),
        _weapon2((num + 1) % 3)
    {}
    int weapon1Get() { return _weapon1; }
    int weapon2Get() { return _weapon2; }
private:
    int _weapon1;
    int _weapon2;
};

class Iceman
: protected Warrior
{
public:
    Iceman(int num, int strength)
        : Warrior(num, strength),
        _weapon(num % 3)
    {}
    int weaponGet() { return _weapon; }
private:
    int _weapon;
};

class Lion
: protected Warrior
{
public:
    Lion(int num, int strength, int remain)
        : Warrior(num, strength),
        _loyalty(remain)
    {}
    int loyaltyGet() { return _loyalty; }
private:
    int _loyalty;
};

class Wolf
: protected Warrior
{
public:
    Wolf(int num, int strength)
        : Warrior(num, strength)
    {}
private:
};

#endif
