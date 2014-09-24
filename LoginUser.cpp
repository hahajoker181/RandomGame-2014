#include "LoginUser.h"

LoginTrue lt;

void LoginUser::loginAccount()
{
    //Username and Password
    string getUsername, getPassword;

    //Get file name and store lines in vectors
    string file_name, line;
    vector<string> myLines;

    cout << "Username: ";
    cin >> getUsername;
    file_name = getUsername + ".txt";

    cout << "Password: ";
    cin >> getPassword;

    clearMessage();

    //FIXME (user#4#): Add condition if the file does not exist.
    ifstream myFile(file_name.c_str());

    while (getline(myFile, line))
        myLines.push_back(line);

    if (getUsername == myLines[0] && getPassword == myLines[1])
    {
        cout << "Initializing pixels! HEUHUEHUEHUEHUE" << endl;
        lt.userInfo(getUsername);
    }

    else
    {
        while (getUsername != myLines[0] || getPassword != myLines[1])
        {
            cout << "Either username or password is invalid!\n            <<CaSe SeNsItIvE>>" << endl;
            cout << "Username: ";
            cin >> getUsername;

            cout << "Password: ";
            cin >> getPassword;

            clearMessage();

            if (getUsername == myLines[0] && getPassword == myLines[1])
            {
                cout << "Initializing pixels! HEUHUEHUEHUEHUE" << endl;
                lt.userInfo(getUsername);
            }
        }
        clearMessage();
    }
    myFile.close();
}

void LoginUser::createAccount()
{
    createUsername();
}

void LoginUser::exit()
{
    cout << "Exit account";
}

void LoginUser::logoff()
{
    cout << "Logoff";
}

void LoginUser::display()
{
    int user_option = 0;

    cout << "1. Login\t2. Create Account\t3. Exit\nUser Option: ";
    cin >> user_option;

    clearMessage();

    switch(user_option)
    {
        case 1:
            loginAccount();
            break;
        case 2:
            createAccount();
            break;
        case 3:
            exit();
            break;
        default:
            cout << "Please enter one of the options";
    }
}
