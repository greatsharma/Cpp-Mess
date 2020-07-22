#include <iostream>
#include <math.h>
using namespace std;

string copyString(string str, int start, int end)
{
    string s = "";
    for (int i = start; i <= end; i++)
        s += str[i];
    return s;
}

string reverse(string str)
{
    if (str.size() == 1)
        return str;
    else
    {
        int mid = ceil(str.size() / 2);
        string str1 = copyString(str, mid, str.size() - 1);
        string str2 = copyString(str, 0, mid - 1);
        return reverse(str1) + reverse(str2);
    }
}

int main()
{
    cout << "\nEnter string : ";
    string str;
    getline(cin, str);

    cout << "\nstr is : " << str;
    cout << "\nrev is : " << reverse(str);

    return 0;
}