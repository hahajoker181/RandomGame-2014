#ifndef LOGINUSER_H
#define LOGINUSER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "CreateUser.h"
#include "MessageSystem.h"
#include "LoginTrue.h"

using namespace std;

class LoginUser : public CreateUser
{
    public:
        void loginAccount();
        void createAccount();
        void exit();
        void logoff();
        void display();
    private:
};

#endif // LOGINUSER_H
