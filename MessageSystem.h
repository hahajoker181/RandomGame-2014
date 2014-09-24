#ifndef MESSAGESYSTEM_H
#define MESSAGESYSTEM_H

#include <cstdlib>
#include <iostream>

using namespace std;

class MessageSystem
{
    public:
        void firstMessage(string username);
        void welcomeMessage(string username);
        void clearMessage();
        void goodbyeMessage();
        void welcomeShop();
    protected:
    private:
};

#endif // MESSAGESYSTEM_H
