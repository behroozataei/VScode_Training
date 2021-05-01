#include <iostream>
#include <string>
#include "Logger.h"
using namespace std;
int main(int argc, char *argv[])
{
    string message1 = "logg message 1 ...";
    string message2 = "logg message 2 ...";
    int    nNum = 10;
    CLogger::GetLogger()->Log("message to be logged");
    CLogger::GetLogger()->Log(message1);
    LOGGER->Log("Message is:%s Number is:%d", message2.c_str(), nNum);
    LOGGER->Log("Message is:"+ message2 +" Number is:"+to_string(nNum));
    return 0;
}