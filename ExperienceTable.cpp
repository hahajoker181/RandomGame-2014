#include "ExperienceTable.h"

//Prints out all the experience
void ExperienceTable::showTrueExp()
{
    for (int i = 0; i < 201; i++)
    {
        cout << "Level: " << i << "|\t" << (pow(3.1, 0.00001)*83) * (pow(1.15,i)) << endl;
    }
}

//Gets user experience
void ExperienceTable::getSkillUsername(string username)
{
    ///Gets user skills into vectors
}
