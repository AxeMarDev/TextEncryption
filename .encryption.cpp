#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <fstream>

using namespace std;

class operators
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

class encrypt
{
private:
	string inputed;
	string outputed;
	string key;

public:
	void setterE(string key1)
	{

		key = key1;
	}
	string getter()
	{
		outputed = inputed;
		return outputed;
	}
	void setter(string input1)
	{
		inputed = input1;
	}

	void transfer_sta(string inputed, vector<char> &trasfer_sta)
	{

		for (int i = 0; i < inputed.size(); i++)
		{
			trasfer_sta.push_back(inputed[i]);
		}
	}

	void convert_cti(vector<char> &trasfer_sta, vector<float> &convert_cti)
	{

		for (int i = 0; i < trasfer_sta.size(); i++)
		{
			float converted = trasfer_sta[i] - 0;

			convert_cti.push_back(converted);
		}
	}

	void encryptor(vector<float> &transfer_cti)
	{

		char operation;
		float operateby;
		for (int i = 0; i < transfer_cti.size(); i++)
		{

			for (int j = 0; j < key.size(); j = j + 2)
			{
				operation = key[j];
				operateby = key[j + 1] - '0';

				switch (operation)
				{

				case 'A':
				case 'a':
					transfer_cti[i] = operators::divide(transfer_cti[i], operateby);
					break;
				case 'B':
				case 'b':
					transfer_cti[i] = operators::multiply(transfer_cti[i], operateby);
					break;
				case 'C':
				case 'c':
					transfer_cti[i] = operators::add(transfer_cti[i], operateby);
					break;
				case 'D':
				case 'd':
					transfer_cti[i] = operators::subtract(transfer_cti[i], operateby);
					break;
				case 'E':
				case 'e':
					transfer_cti[i] = operators::power(transfer_cti[i], operateby);
					break;
				default:

					cout << "notvalid" << endl;
				}
			}
		}
	}
	static void transcribe(string &transribe)
	{
		for (int i = 0; i < transribe.size(); i++)
		{
			char postition = transribe[i];
			switch (postition)
			{
			case '0':
				transribe[i] = '~';
				break;
			case '1':
				transribe[i] = '=';
				break;
			case '2':
				transribe[i] = '%';
				break;
			case '3':
				transribe[i] = '*';
				break;
			case '4':
				transribe[i] = '#';
				break;
			case '5':
				transribe[i] = '@';
				break;
			case '6':
				transribe[i] = '+';
				break;
			case '7':
				transribe[i] = '^';
				break;
			case '8':
				transribe[i] = '(';
				break;
			case '9':
				transribe[i] = ')';
				break;
			case '-':
				transribe[i] = '?';
				break;
			case '.':
				transribe[i] = '>';
				break;
			case '&':
				transribe[i] = '&';
				break;
			case ']':
				transribe[i] = ']';
				break;
			default:
				transribe[i] = '[';
			}
		}
	}
};

int main()
{
	system("touch output.txt");
	// setup string input

	encrypt stringenc;
	string userInput;
	cout << endl;
	cout << "please inputed a string of characters to encrypt: ";
	getline(cin, userInput);
	stringenc.setter(userInput);
	vector<char> transfer_sta(0);
	stringenc.transfer_sta(userInput, transfer_sta);

	// convert vector elements to floating point numbers

	vector<float> converted_ctf(0);
	stringenc.convert_cti(transfer_sta, converted_ctf);

	// encript key
	cout << endl;
	cout << "please input a encryption key( one letter A-D followed by digit 1-9 ex: A2B3D7A9E6): " << endl;
	cout << "( A cannot be followed by a odd number):";
	string keyE;
	getline(cin, keyE);
	cout << endl;
	stringenc.setterE(keyE);

	// ecriptProcess

	stringenc.encryptor(converted_ctf);

	// prin
	string final1 = "[";
	cout << "ecrypted message is: ";
	for (int i = 0; i < converted_ctf.size(); i++)
	{
		// cout << converted_ctf[i] << "&";
		string float_string(to_string(converted_ctf[i]));
		final1 += float_string;

		final1 += "&";
	}
	final1 += "]";
	stringenc.transcribe(final1);
	cout << final1 << endl;
	cout << endl;

	ofstream outfile;
	outfile.open("output.txt");
	outfile << final1 << endl;
}
