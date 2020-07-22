
#include <iostream>

using namespace std;

template <class T1, class T2>
class Babel
{
    T1 numOne;
    T2 numTwo;

  public:
    Babel(T1 numOne, T2 numTwo) : numOne(numOne), numTwo(numTwo) {}
    T2 greater();
};

template <>
class Babel<char, char>
{
    char varOne, varTwo;

  public:
    Babel(char varOne, char varTwo) : varOne(varOne), varTwo(varTwo) { display(); }
    void display()
    {
        cout << varOne << " & " << varTwo << " cannot be added...";
    }
};

template <class T1, class T2>
T2 Babel<T1, T2>::greater()
{
    return numOne > numTwo ? numOne : numTwo;
}

int main()
{

    Babel<int, float> objOneBabel(2, 3.5);
    cout << objOneBabel.greater() << "\n";
    Babel<float, int> objTwoBabel(5.5, 4);
    cout << objTwoBabel.greater();
    cout << endl;

    Babel<char, char> objThreeBabel('a', 'b');

    // cout << objThreeBabel.display();

    cout << endl;
    system("pause");

    return 0;
}