#include <iostream>
using namespace std;

void myStartupFun(void) __attribute__((constructor)); //constructor attribute

void myCleanupFun(void) __attribute__((destructor)); //destructor attribute

void myStartupFun(void)
{
    cout << "startup code before main()\n";
}

void myCleanupFun(void)
{
    cout << "cleanup code after main()\n";
}

int main(void)
{
    cout << "hello\n";

    system("pause");
    return 0;
}
