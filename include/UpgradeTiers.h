#ifndef UPGRADETIERS_H
#define UPGRADETIERS_H

#include <iostream>
#include <cstdlib>
#include "math.h"

#include "MessageSystem.h"
#include "GameCharacters.h"

using namespace std;

class UpgradeTiers : MessageSystem
{
    public:
        void upgradeWeapon();
        void upgradeSpells();
        void upgradeStaff();
        void upgradeBows();
        void upgradeArrows();
};

#endif // UPGRADETIERS_H
