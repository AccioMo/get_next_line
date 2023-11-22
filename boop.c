

// C Program to illustrate the static variable lifetime
#include <stdio.h>
 
// function with static variable
void fun()
{
    static int count;
    count = 2;
}
 
int main()
{
    static int count = 0;
	fun();
	printf("%d\n", count);
    return 0;
}
