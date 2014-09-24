#include "MessageSystem.h"

//TODO (user#1#): Get username from text document
void MessageSystem::firstMessage(string username)
{
    int user_option = 0;

    cout << "Welcome to Asgarnia, " << username << "!";

    cout << "Would you like us to show around?\n1. Yes\t2. No\nUser Option: ";
    cin >> user_option;

    if (user_option == 1)
    {
        //TUTORIAL
    }
    if (user_option == 2)
    {
        //NO TUTORIAL
    }
}

//TODO (user#1#): Get username from text document
void MessageSystem::welcomeMessage(string username)
{
    if (username != "Admin")
        cout << "Welcome Noob " << username << "!";
    else
        cout << "Admin has logged in.";
}

void MessageSystem::clearMessage()
{
    system("cls");
}

void MessageSystem::goodbyeMessage()
{
    cout << "Please come back soon <username>!";
}

//FIXME (user#1#): Improve Welcome Shop message
void MessageSystem::welcomeShop()
{
    cout << "Welcome <username>, would you like to check my shop?\n1. Yes\t2. No\nUser Option: ";
}
