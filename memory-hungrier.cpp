#include <iostream>    //Not necessary , Just By convention
int main()
{
    while(true)
        int*x=new int;
}
/*
Everything stops responding :)
After that std::bad_alloc exception is thrown which terminates the program :
*/
