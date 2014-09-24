#include "GameCharacters.h"

UpgradeTiers ut;
MessageSystem ms;

//Person who upgrades magic stuff
void GameCharacters::NPC_rondolf()
{
    int id_rondolf = 1000;

    int user_option = 0;
    int rondolf_option = 0;

    ms.welcomeShop();
    cin >> user_option;
    ms.clearMessage();

    if (user_option == 1)
    {
        cout << "What would you like to upgrade?\n1. Staff\t2. Spells\t3. Say Goodbye!\nUser Option: ";
        cin >> rondolf_option;
        ms.clearMessage();

        //Upgrade staff
        if (rondolf_option == 1)
            ut.upgradeStaff();

        //Upgrade spells
        if (rondolf_option == 2)
            ut.upgradeSpells();

        //Goodbye exit
        if (rondolf_option == 3)
            ms.goodbyeMessage();
    }

    if (user_option == 2)
        ms.goodbyeMessage();
}

void GameCharacters::NPC_xavier()
{
    int id_xavier = 1001;

    int user_option = 0;
    int xavier_option = 0;

    ms.welcomeShop();
    cin >> user_option;
    ms.clearMessage();

    if (user_option == 1)
    {
        cout << "Would you like to upgrade your sword?\n1. Yes\t2. No\t3. Say Goodbye!\nUser Option: ";
        cin >> xavier_option;
        ms.clearMessage();

        if (xavier_option == 1)
            ut.upgradeWeapon();

        if (xavier_option == 2)
            ms.goodbyeMessage();
    }

    if (user_option == 2)
        ms.goodbyeMessage();
}
//Person who upgrades bows and arrows
void GameCharacters::NPC_robinhood()
{
    int id_robinhood = 1002;

    int user_option = 0;
    int robinhood_option = 0;

    ms.welcomeShop();
    cin >> user_option;

    if (user_option == 1)
    {
        cout << "What would you like to upgrade?\n1. Bows\t2. Arrows\t3. Say Goodbye!\nUser Option: ";
        cin >> robinhood_option;

        if (robinhood_option == 1)
            ut.upgradeBows();

        if (robinhood_option == 2)
            ut.upgradeArrows();

        if (robinhood_option == 3)
            ms.goodbyeMessage();
    }

    if (user_option == 2)
        ms.goodbyeMessage();
}
