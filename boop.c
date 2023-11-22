

// C Program to illustrate the static variable lifetime
#include <stdio.h>
 
// function with static variable
int fun()
{
    static int count = 0;
    static int count1;
	static char c[10];
    count++;
    return count;
}
 
int main()
{
    return 0;
}
