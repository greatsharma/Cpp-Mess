#include <iostream>

using namespace std;
int top = -1;
char *stack;

void push(char ch)
{
    stack[++top] = ch;
}

char pop()
{
    return stack[top--];
}

void stackFunction()
{
    cout << "\n";
    for (int i = 0; i <= top; i++)
        cout << "  " << stack[i];
}

string functionInfixToPostfix(string infix_Str)
{
    string postfix_str = "";

    stack = new char[infix_Str.length()];

    for (int i = 0; i < infix_Str.length(); i++)
    {
        if (infix_Str[i] == '(')
        {
            push(infix_Str[i]);
        }
        else if (infix_Str[i] == '+' || infix_Str[i] == '-')
        {
            while (1)
            {
                if (stack[top] == '+' || stack[top] == '-' || stack[top] == '*' || stack[top] == '/' || stack[top] == '^')
                    postfix_str += pop();
                else
                    break;
            }
            push(infix_Str[i]);
        }
        else if (infix_Str[i] == '*' || infix_Str[i] == '/')
        {
            while (1)
            {
                if (stack[top] == '*' || stack[top] == '/' || stack[top] == '^')
                    postfix_str += pop();
                else
                    break;
            }
            push(infix_Str[i]);
        }
        else if (infix_Str[i] == '^')
        {
            while (1)
            {
                if (stack[top] == '^')
                    postfix_str += pop();
                else
                    break;
            }
            push(infix_Str[i]);
        }
        else if (infix_Str[i] == ')')
        {
            while (1)
            {
                if (stack[top] != '(')
                    postfix_str += pop();
                else
                {
                    pop();
                    break;
                }
            }
        }
        else
        {
            postfix_str += infix_Str[i];
        }
        stackFunction();
    }

    return postfix_str;
}

int main()
{
    cout << "\nenter infix : ";
    string infix_Str;
    getline(cin, infix_Str);

    cout << "\n\npostfix : " << functionInfixToPostfix(infix_Str);

    cout << endl;
    system("pause");
    return 0;
}