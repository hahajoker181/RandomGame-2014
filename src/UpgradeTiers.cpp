#include "UpgradeTiers.h"
GameCharacters gc1;


//TODO (user#3#): Finish upgrade and add price
void UpgradeTiers::upgradeWeapon()
{
    /*(Accuracy (20-95%), Strength Bonus (lvl of weapon + 10), Attack Bonus (lvl wep/2 + 3) )
    1   Bronze  20%     11      3.5     7.7

    10  Iron    24%     20      13      62.4
    20  Steel   30%     30      18      162.0

    30  Mithril 38%     40      23      486.4
    40  Adamant 48%     50      28      672.0

    50  Rune    60%     60      33      1188.0
    60  Dragon  74%     70      38      1968.4

    iron+
    default_dmg = sqrt(accuracy * lvl_wep+10 * (lvl_wep/2)+3 )
    */
    double new_dmg = 0;

    //Default damage for base weapons
    double DEFAULT_DMG[6] = {62.4, 162.0, 486.4, 672.0, 1188.0, 1968.4};
    double tier_weapon[5] = {1, 1.3, 1.35, 1.40, 1.45}; //Tier Weapon

    //Price
    int tier_price[5] = {4225, 6414, 9736, 14780, 34063};

    int attack_lvl = 99;
    int strength_lvl = 99;

    int user_option = 0;
    int weapon_option = 0;

    //Name of weapon
    string weapon_name[6] = {"Iron", "Steel", "Mithril", "Adamant", "Rune", "Dragon"};

    cout << "What weapon would you like to upgrade?\n1. Bronze\t5. Adamant\n2. Iron\t\t6. Rune\n3. Steel\t7. Dragon\n4. Mithril\nUser option: ";
    cin >> user_option;

    //Bronze
    if (user_option == 1)
    {
        cout << "Would you like to upgrade Bronze Weapon?\n1. Yes\t2. No\t3. Cancel\nUser Option: ";
        cin >> weapon_option;

        //Upgrades the weapon
        if (weapon_option == 1)
        {
            new_dmg = 7.7 + (((double)attack_lvl/10) * (double)strength_lvl/15) * tier_weapon[0];
            new_dmg += 7.7/5;
            cout << new_dmg;
        }

        //No will exit the person.
        if (weapon_option == 2)
        {
            goodbyeMessage();
        }

        //Cancel goes back to the person message.
        if (weapon_option == 3)
        {
            gc1.NPC_xavier();
        }
    }

    //Iron+
    else
    {
        cout << "Would you like to upgrade " << weapon_name[user_option-2] << "?\n1. Yes\t2. No\t3. Cancel\nUser Option: ";

        new_dmg = (sqrtf(DEFAULT_DMG[0]) * 1.9) + ((double)attack_lvl/10 * (double)strength_lvl/15 * tier_weapon[0]);
        new_dmg += DEFAULT_DMG[user_option-2]/14;

        cout << new_dmg;
    }
}

//FIXME (user#4#): Finish upgrade spells function: WORKABLE (dmg no update)
///Sorry you did not unlock this spell yet (consideration).
void UpgradeTiers::upgradeSpells()
{
    //STORED IN A TEXT DOCUMENT
    double spell_dmg[4][4] = {
        {4.1, 4.21, 4.33, 4.52}, // Strike
        {5.19, 5.30, 5.43, 5.57}, // Blast
        {6.24, 6.33, 6.42, 6.63}, // Wave
        {7.11, 7.29, 7.46, 7.81} // Surge
    };

    double dmg[4][4] = {
        {0.50, 0.60, 0.70, 0.80}, //Strike, Blast, Wave, Surge
        {0.75, 0.80, 0.85, 0.90},  //Power
        {1.3, 1.35, 1.40, 1.45},  //Additional Damage
        {0.30, 0.40, 0.50, 0.6} //Air, Earth, Water, Fire
    };

    // New Damage, Element Type: Air, Earth, Water, Fire, Element tier: strike, blast, wave, surge
    double new_dmg = 0;
    int element_type, element_tier = 0;

    //Option that user enters
    int user_option = 0;

    //FIXME (user#6#): Keep stored in text document cash and tier spell
    ///Issue keep in track of the user cash not the shop.
    int item_id = 995;
    int user_amount = 99999;
    int tier_user = 1;

    //Upgrade tier price
    int price[5] = {5621, 8662, 13339, 20542, 48714};

    //Keep track of name of spell
    string name_spell[2][4] = {
        {"Air ", "Earth ", "Water ", "Fire "},
        {"Strike", "Blast", "Wave", "Surge"}
    };

    cout <<"1. Air\n2. Earth\n3. Water\n4. Fire\nChoose option: ";
    cin >> element_type;
    clearMessage();

    cout << "1. Strike\n2. Blast\n3. Wave\n4. Surge\nChoose option: ";
    cin >> element_tier;
    clearMessage();

    new_dmg = (pow(dmg[1][element_tier-1], 3.0)) * dmg[0][element_type-1] * spell_dmg[element_tier-1][element_type-1] *
    (dmg[2][element_tier-1] + dmg[3][element_type-1]);

    cout << "Would you like to upgrade " << name_spell[0][element_type-1] << name_spell[1][element_tier-1] << "?";
    cout << "\n1. Yes\t2. No\t3. Cancel\nChoose option: ";

    cin >> user_option;
    clearMessage();

    //TODO (user#7#): Able to get user tier in order to get other options.
    //FIXME (user#7#): Able to update the damage in the text document.
    if (user_option == 1)
    {
        //Upgrade Tier 1
        if (item_id == 995 && user_amount >= price[0] && tier_user == 1)
        {
            user_amount -= price[0];
            cout << "New damage: " << new_dmg + spell_dmg[element_tier-1][element_type-1] << endl;
            cout << "Gold: " << user_amount;
        }


        //Upgrade Tier 2
        if (item_id == 995 && user_amount >= price[1] && tier_user == 2)
        {
            user_amount -= price[1];
            cout << "Upgrade Tier 2" << endl;
            cout << "Gold: " << user_amount;
        }

        //Upgrade Tier 3
        if (item_id == 995 && user_amount >= price[2] && tier_user == 3)
        {
            user_amount -= price[2];
            cout << "Upgrade Tier 3" << endl;
            cout << "Gold: " << user_amount;
        }

        //Upgrade Tier 4http://gyazo.com/1e563e0c8412fc65c1acc0ee47e2a86d
        if (item_id == 995 && user_amount >= price[3] && tier_user == 4)
        {
            user_amount -= price[3];
            cout << "Upgrade Tier 4" << endl;
            cout << "Gold: " << user_amount;
        }


        //Upgrade Tier 5
        if (item_id == 995 && user_amount >= price[4] && tier_user == 5)
        {
            user_amount -= price[4];
            cout << "Upgrade Tier 5" << endl;
            cout << "Gold: " << user_amount;
        }
    }
    if (user_option == 2)
        goodbyeMessage();

    if (user_option == 3)
        gc1.NPC_rondolf();
}

//TODO (user#9#): Add upgrade algorithm to staff and price
void UpgradeTiers::upgradeStaff()
{
/*
1 Novice Staff: 2   6%     200 God Staff: 75 * level/10   175%

10 Tier 1 Staff: 4      15%
30 Tier 2 Staff: 10     35%
50 Tier 3 Staff: 22     55%
90 Tier 4 Staff: 34     95%
120 Tier 5 Staff: 50    125%

default_dmg = base_dmg * (accuracy: magic_lvl/2) * staff_accuracy
*/
    int staff_option = 0;
    int user_option = 0;

    int item_id = 995;
    int user_amount = 99999;

    //Default damage at tier 1.
    int staff_dmg[5] = {4, 10, 222, 34, 50};
    int staff_price[5] = {4225, 6414, 9736, 14780, 34063};

    cout << "What staff would you like to upgrade?\n1. Tier 1\t4. Tier 4\n2. Tier 2\t5. Tier 5\n3. Tier 3\nUser Option: ";
    cin >> staff_option;
    clearMessage();

    cout << "Would you like to upgrade Tier " << staff_option << " Staff?\n1. Yes\t2. No\t3. Cancel\nUser Option: ";
    cin >> user_option;
    clearMessage();

    //FIXME (user#1#): LOGICAL ERROR: not the same logic as upgrading spells.
    if (user_option == 1)
    {
        if (user_option == 1)
        {
            //Tier 1 Staff upgrade
            if (item_id == 995 && staff_option == 1 && user_amount >= staff_price[0])
            {
                user_amount -= staff_price[0];

                cout << "Tier 1" << endl;
                cout << "Gold: " << user_amount;
            }

            //Tier 2 Staff upgrade
            if (item_id == 995 && staff_option == 2 && user_amount >= staff_price[1])
            {
                user_amount -= staff_price[1];

                cout << "Tier 2" << endl;
                cout << "Gold: " << user_amount;
            }

            //Tier 3 Staff upgrade
            if (item_id == 995 && staff_option == 3 && user_amount >= staff_price[2])
            {
                user_amount -= staff_price[2];

                cout << "Tier 3" << endl;
                cout << "Gold: " << user_amount;
            }

            //Tier 4 Staff upgrade
            if (item_id == 995 && staff_option == 4 && user_amount >= staff_price[3])
            {
                user_amount -= staff_price[3];

                cout << "Tier 4" << endl;
                cout << "Gold: " << user_amount;
            }

            //Tier 5 Staff upgrade
            if (item_id == 995 && staff_option == 5 && user_amount >= staff_price[4])
            {
                user_amount -= staff_price[4];

                cout << "Tier 5" << endl;
                cout << "Gold: " << user_amount;
            }
        }
    }
    if (user_option == 2)
        goodbyeMessage();

    if (user_option == 3)
        gc1.NPC_rondolf();
}

//TODO (user#4#): Add upgrade algorithm to bow and price
void UpgradeTiers::upgradeBows()
{
/*(Accuracy (25-95%), Ranged Bonus (lvl of bow + 20), max arrow )
    1 Shortbow      25%         21      5.25       Iron
    15 Oak          30%         35      10.50      Steel
    30 Willow       35%         50      17.50      Mithril
    40 Maple        40%         70      28.00      Adamant
    60 Yew          45%         80      36.00      Rune
    75 Magic        65%         95      61.75      Dragon
    85 Elder        75%         105     78.75      Dark
    94 Crystal      80%         114     91.20      Crystal
*/
    int tier_price[5] = {4225, 6414, 9736, 14780, 34063};
}

//TODO (user#4#): Add upgrade algorithm to arrows and price
void UpgradeTiers::upgradeArrows()
{
/*(Accuracy (25-100%), Ranged Bonus (lvl of arrow + 5)
   1 Bronze         25%         6       1.5
   1 Iron           30%         6       1.8
   15 Steel         35%         20      7
   30 Mithril       40%         35      14
   40 Adamant       45%         45      20.25
   60 Rune          55%         65      35.75
   75 Dragon        70%         80      56
   85 Dark          85%         90      76.5
   94 Crystal       100%        99      99
*/
    double tier_price[5] = {2.07, 2.95, 4.22, 6.02, 10.25};
}
