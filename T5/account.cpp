#include "account.h"
account::account(string _firstname, string _lastname, int _arbitrary):
                firstname(_firstname),lastname(_lastname),arbitrary(_arbitrary)
{
    if (arbitrary==0)
        throw invalid_argument("arbitrary is Zero");

}
