#include <iostream>
#include "math.h"

using namespace std;

int top = -1;
int *array;
bool flagNeg = false;

void push(int);

void operation(char operate)
{
	switch (operate)
	{
	case '/':
	{
		int var1 = array[top--];
		int var2 = array[top--];

		push(var1 / var2);
		break;
	}

	case '%':
	{
		int var1 = array[top--];
		int var2 = array[top--];

		push(var1 % var2);

		break;
	}

	case '+':
	{
		int var1 = array[top--];
		int var2 = array[top--];

		push(var1 + var2);
		break;
	}

	case '-':
	{
		int var1 = array[top--];
		int var2 = array[top--];

		push(var1 - var2);

		break;
	}

	case '*':
	{
		int var1 = array[top--];
		int var2 = array[top--];

		push(var1 * var2);

		break;
	}
	}
}

// void stringToInt(string strEquivalent)
// {
// 	int intEquivalent = 0;
// 	int localVar;

// 	for (int i = (strEquivalent.length() - 1), j = 0; i >= 0; i--, j++)
// 	{
// 		localVar = strEquivalent[i] - '0';
// 		intEquivalent += (localVar * pow(10, j));
// 	}

// 	if (flagNeg)
// 		intEquivalent *= (-1);
// 	flagNeg = false;
// 	push(intEquivalent);
// }

void push(int data)
{
	array[++top] = data;
}

int main()
{
	bool flag = false;

	cout << "\nEnter postfix exp(End the exp with a space, compulsory to work):";
	string strPostfix;
	getline(cin, strPostfix);

	array = new int[strPostfix.length()];

	for (int i = 0; i < strPostfix.length(); i++)
	{
		string bufferVar;

		while (strPostfix[i] != ' ')
		{

			if (strPostfix[i] == '/' || strPostfix[i] == '+' || strPostfix[i] == '*' || strPostfix[i] == '%')
			{
				flag = true;
				operation(strPostfix[i]);
				break;
			}

			else if (strPostfix[i] == '-')
			{
				if (strPostfix[i + 1] == ' ')
				{
					flag = true;
					operation(strPostfix[i]);
					break;
				}
				else
				{
					flagNeg = true;
					//	++i;
				}
			}
			else
			{
				bufferVar += strPostfix[i];
				flag = false;
			}
			++i;
		}

		if (!flag)
		{
			// stringToInt(bufferVar);
			int h = stoi(bufferVar);
			push(h);
			flag = false;
		}
		//cout<<"\nStack: "<<array[top];
		//cout<<"\ntop: "<<top<<"  "<<"value: "<<array[top];
	}

	cout << "\n\ntop: " << top << endl;
	cout << "final answer after evaluating: " << array[top];

	system("pause");
	return 0;
}