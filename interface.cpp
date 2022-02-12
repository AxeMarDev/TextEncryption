#include <iostream>

using namespace std;

int main()
{

	cout << "================================================" << endl;
	cout << "* encrypt / decrypt                            *" << endl;
	cout << "================================================" << endl;
	cout << endl;
	cout << "user$ -";
	string request;
	cin >> request;
	cout << endl;
	if (request == "request.incrypt")
	{

		system("./compile");
	}
	else
	{

		cout << "not an argument, did you mean 'request.incrypt'?" << endl;
	}

	return 0;
}
