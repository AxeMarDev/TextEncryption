#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <fstream>

using namespace std;

class operators // posible encryption operation
{
public:
	static float divide(float target, float divideby)
	{
		return target / divideby;
	}
	static float multiply(float target, float divideby)
	{
		return target * divideby;
	}

	static float add(float target, float divideby)
	{
		return target + divideby;
	}

	static float subtract(float target, float divideby)
	{
		return target - divideby;
	}

	static float power(float target, float divideby)
	{
		return target * 2;
	}
};

class encrypt // encryption  class that will hold every encrytpion function
{
	string inputed;
	string outputed;
	string key;
	vector<char> transfer_stal;
	vector<float> converted_ctf;
	string final1;

public:
	void getter()
	{
		cout << final1 << endl;
		ofstream outfile;
		outfile.open("output.smtxt");
		outfile << final1 << endl;
	}

	void setter(string input1, string key1)
	{
		inputed = input1;
		key = key1;
	}

	void transfer_sta()
	{

		for (int i = 0; i < inputed.size(); i++)
		{
			transfer_stal.push_back(inputed[i]);
		}
	}

	void convert_ctil()
	{

		for (int i = 0; i < transfer_stal.size(); i++)
		{
			float converted = transfer_stal[i] - 0;

			converted_ctf.push_back(converted);
		}
	}

	void encryptor()
	{

		char operation;
		float operateby;

		for (int i = 0; i < converted_ctf.size(); i++)
		{

			for (int j = 0; j < key.size(); j = j + 2)
			{
				operation = key[j];
				operateby = key[j + 1] - '0';

				switch (operation)
				{

				case 'A':
				case 'a':
					converted_ctf[i] = operators::divide(converted_ctf[i], operateby);
					break;
				case 'B':
				case 'b':
					converted_ctf[i] = operators::multiply(converted_ctf[i], operateby);
					break;
				case 'C':
				case 'c':
					converted_ctf[i] = operators::add(converted_ctf[i], operateby);
					break;
				case 'D':
				case 'd':
					converted_ctf[i] = operators::subtract(converted_ctf[i], operateby);
					break;
				case 'E':
				case 'e':
					converted_ctf[i] = operators::power(converted_ctf[i], operateby);
					break;
				default:

					cout << "notvalid" << endl;
				}
			}
		}
	}

	void transcribe()
	{
		for (int i = 0; i < final1.size(); i++)
		{
			char postition = final1[i];
			switch (postition)
			{
			case '0':
				final1[i] = '~';
				break;
			case '1':
				final1[i] = '=';
				break;
			case '2':
				final1[i] = '%';
				break;
			case '3':
				final1[i] = '*';
				break;
			case '4':
				final1[i] = '#';
				break;
			case '5':
				final1[i] = '@';
				break;
			case '6':
				final1[i] = '+';
				break;
			case '7':
				final1[i] = '^';
				break;
			case '8':
				final1[i] = '(';
				break;
			case '9':
				final1[i] = ')';
				break;
			case '-':
				final1[i] = '?';
				break;
			case '.':
				final1[i] = '>';
				break;
			case '&':
				final1[i] = '&';
				break;
			case ']':
				final1[i] = ']';
				break;
			default:
				final1[i] = '[';
			}
		}
	}

	void messageCapsule()
	{

		final1 = "[";
		cout << "ecrypted message is: ";
		for (int i = 0; i < converted_ctf.size(); i++)
		{
			// cout << converted_ctf[i] << "&";
			string float_string(to_string(converted_ctf[i]));
			final1 += float_string;

			final1 += "&";
		}
		final1 += "]";
	}
};

int main()
{
	system("touch output.smtxt");
	encrypt stringenc;
	string userInput, keyE;
	system("clear");
	cout << "please inpute a string of characters to encrypt: ";
	getline(cin, userInput);
	system("clear");
	cout << "please input a encryption key( one letter A-D followed by digit 1-9 ex: ";
	getline(cin, keyE);
	stringenc.setter(userInput, keyE);
	stringenc.transfer_sta();
	stringenc.convert_ctil();
	stringenc.encryptor();
	system("clear");
	stringenc.messageCapsule();
	stringenc.transcribe();
	stringenc.getter();
	return 0;
}
