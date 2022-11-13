//A self replicating piece of code which can be written incredibly simply in almost all programming languages and will grind most machines to a halt in no time at all due to the nature of exponential increase.

//Here it is in basic C. All the program does is create another program, over and over again until all resources are extinguished - usually by simply filling up the Operating System’s process table.

#include <unistd.h>
int main(void)
{
    while(1) fork();
}

//As noted in the Wikipedia example, careful use of ulimits for non root users on *nix machines can help protect against this.
/*
Oh yes, save all your work before you try running any of these examples… you may be surprised how quickly they lock you out.
(No really, I didn’t bother the first time I tried, and regretted it.)

As pointed out by User's answer to What is the most dangerous piece of code ever written? there are of course lots of definitions of “dangerous” and he points out an example directly to life and limb.

Another example of mostly unintentionally dangerous code is the humble Off-by-one error
which is probably one of the most common causes of security flaws in modern software.
This is where programmers pay insufficient attention to the extent of memory they have allocated,
or don’t guard its limits correctly and someone is able to (accidentally or deliberately) inject bytes where they should not be,
with unpredictable errors resulting, or crashes, or potentially full exploits of the host machine.
*/
