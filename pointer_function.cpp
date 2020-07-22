#include <iostream>
using namespace std;

typedef int *(*p)(int *, int *);
int *sum(int *, int *);
int *double_number(int *(ptr)(int *, int *), int, int);
p function();

int *(my_func)(int *a, int *b)
{
    int c = *a + *b;
    int *c_pt = &c;
    return c_pt;
}

int main(void)
{
    int *(*sum_ptr)(int *, int *) = &sum;
    cout << "\naddress sum : " << (void *)sum_ptr;
    cout << "\naddress double_number : " << (void *)&double_number;
    cout << "\naddress function : " << (void *)&function;
    int num_one, num_two;
    cout << "\n\nEnter two numbers : ";
    cin >> num_one >> num_two;
    int *sum_result = double_number(sum, num_one, num_two);
    cout << "\nsum is : " << *(sum_result);
    cout << endl;
    cout << *function()(&num_one, &num_two);

    cout << endl;

    cout << "\naddress sum : " << (void *)sum_ptr;
    cout << "\naddress double_number : " << (void *)&double_number;
    cout << "\naddress function : " << (void *)&function;
    cout << endl;
    system("pause");
    return 0;
}

int *sum(int *a, int *b)
{
    int c = *a + *b;
    int *ptr = &c;
    return ptr;
}

int *double_number(int *(ptr)(int *, int *), int num_one, int num_two)
{

    int *result = ptr(&num_one, &num_two);
    return (result);
}

p function()
{
    return sum;
}