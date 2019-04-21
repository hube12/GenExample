#include <iostream>
#include "httplib.hpp"
int main()
{
    system("curl -X POST https://api.telegram.org/bot830618853:AAGbhpAtk0RJgQ97KmCTQpxeyB6vveD2OJU/sendMessage "
           "-d chat_id=616875529 -d text=\"test\"");
}