#include <iostream>
#include <algorithm>

using namespace std;

template <class T1, class T2>
T2 bigger(T1 numOne, T2 numTwo)
{
    return numOne > numTwo ? numOne : numTwo;
}

bool isEven(int num) // unary predicate
{
    return !(num % 2);
}

int main()
{

    cout << bigger(2, 3) << "\n";
    cout << bigger(2.5, 1.90) << "\n";
    cout << bigger(2, 2.5) << "\n";

    cout << boolalpha << isEven(4) << "\n";

    cout << [](int num) { return num % 2; }(5);

    float varOne = 5.7, varTwo = 8.6;

    cout << "\ngreater : " << [=]() { return (varOne / varTwo) > 1 ? varOne : varTwo; }();

    cout << "\nEnter two numbers : ";
    cin >> varOne >> varTwo;

    cout << "\n smaller : " << [](float a, float b) { return a / b < 1 ? a : b; }(varOne, varTwo);

    [&varOne, varTwo]() { ++varOne; }();

    cout << "\n"
         << [=]() { return varOne == varTwo; }();

    cout << "\n";
    system("pause");
    return 0;
}