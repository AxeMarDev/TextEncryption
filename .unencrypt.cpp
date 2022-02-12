#include <iostream>
#include <string>
#include <vector>

using namespace std;

class operators
{
public:
	static float divide(float target, float divideby)
	{
		return target * divideby;
	}
	static float multiply(float target, float divideby)
	{
		return target / divideby;
	}

	static float add(float target, float divideby)
	{
		return target - divideby;
	}

	static float subtract(float target, float divideby)
	{
		return target + divideby;
	}

	static float power(float target, float divideby)
	{
		return target / 2;
	}
};

class unencrypt
{
	string message;
	string key;
	vector<string> floatLi;
	vector<float> array;
	string messagereturn;

public:
	void setter(string one, string two)
	{
		message = one;
		key = two;
	}
	void translate()
	{

		string transribe = message;

		for (int i = 0; i < transribe.size(); i++)
		{

			switch (transribe[i])
			{
			case '~':
				transribe[i] = '0';
				break;
			case '=':
				transribe[i] = '1';
				break;
			case '%':
				transribe[i] = '2';
				break;
			case '*':
				transribe[i] = '3';
				break;
			case '#':
				transribe[i] = '4';
				break;
			case '@':
				transribe[i] = '5';
				break;
			case '+':
				transribe[i] = '6';
				break;
			case '^':
				transribe[i] = '7';
				break;
			case '(':
				transribe[i] = '8';
				break;
			case ')':
				transribe[i] = '9';
				break;
			case '?':
				transribe[i] = '-';
				break;
			case '>':
				transribe[i] = '.';
				break;
			case '&':
				transribe[i] = ' ';
				break;
			case ']':
				transribe[i] = '0';
				break;
			default:
				transribe[i] = '0';
			}
		}
		message = transribe;
	}
	void cutString()
	{
		string s = message;
		string delimiter = " ";
		int x = 0;
		size_t pos = 0;
		string token;
		while ((pos = s.find(delimiter)) != std::string::npos)
		{
			token = s.substr(0, pos);

			floatLi.push_back(token);
			s.erase(0, pos + delimiter.length());
			x++;
		}
	}

	void stofhelp()
	{
		int x = 0;
		while (x < floatLi.size())
		{
			float holder = stof(floatLi[x]);
			array.push_back(holder);
			x++;
		}
	}

	void print()
	{

		for (int i = 0; i < array.size(); i++)
		{

			cout << array[i] << endl;
		}
	}

	void unencryptor()
	{
		char operation;
		float operateby;

		for (int i = 0; i < array.size(); i++)
		{

			for (int j = key.size() - 2; j >= 0; j = j -= 2)
			{
				operation = key[j];
				// cout << operation << endl;
				operateby = key[j + 1] - '0';
				// cout << operateby << endl;

				switch (operation)
				{

				case 'A':
				case 'a':
					array[i] = operators::divide(array[i], operateby);
					break;
				case 'B':
				case 'b':
					array[i] = operators::multiply(array[i], operateby);
					break;
				case 'C':
				case 'c':
					array[i] = operators::add(array[i], operateby);
					break;
				case 'D':
				case 'd':
					array[i] = operators::subtract(array[i], operateby);
					break;
				case 'E':
				case 'e':
					array[i] = operators::power(array[i], operateby);
					break;
				default:

					cout << "notvalid" << endl;
				}
			}
		}
	}

	void itochar()
	{

		for (int i = 0; i < array.size(); i++)
		{

			string holder = "0";
			holder[0] = array[i] - 0;
			messagereturn += holder;
		}
	}

	void getter()
	{

		cout << messagereturn << endl;
	}
};

int main()
{

	string encryptMessage;
	string encryptkey;
	cout << "enter encrypted message: ";
	cin >> encryptMessage;
	cout << "enter encryption key: ";
	cin >> encryptkey;
	unencrypt uncrypt;
	uncrypt.setter(encryptMessage, encryptkey);
	uncrypt.translate();
	uncrypt.cutString();
	uncrypt.stofhelp();
	uncrypt.unencryptor();
	// uncrypt.print();
	uncrypt.itochar();
	uncrypt.getter();
}
