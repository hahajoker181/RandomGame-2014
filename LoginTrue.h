#ifndef LOGINTRUE_H
#define LOGINTRUE_H

#include <iostream>
#include "MessageSystem.h"

using namespace std;


class LoginTrue : public MessageSystem
{
    public:
        void userInfo(string username);
    protected:
    private:
};

#endif // LOGINTRUE_H
