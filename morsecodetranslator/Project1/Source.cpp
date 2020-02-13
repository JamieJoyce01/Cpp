#include <iostream>
#include <string>
using namespace std;

void encrypt(char alpha[], string morse[]) {
	string str;
	cout << "Please enter what you would like to translate.\n>>> ";
	getline(cin, str);
	cin.clear();
	for (int z = 0; z < str.length(); z++) {

		for (int i = 0; i < 26; i++) {
			if (tolower(str[z]) == alpha[i]) {
				cout << morse[i] << " ";
			}
		}
	}
}

void decrypt(char alpha[], string morse[]) {
	string str;
	string separated[100];
	cout << "Please enter what you would like to translate (With spaces).\n>>> ";
	getline(cin, str);
	cin.clear();
	str = str + " ";
	string temp[20];
	int i = 0;
	while (!str.empty()) {
		temp[i] = str.substr(0, str.find(" "));
		str.erase(0, str.find(" ")+1);
		i++;
	}

	for (int z = 0; z < i; z++) {
		for (int y = 0; y < 26; y++) {
			if (temp[z] == morse[y]) {
				cout << alpha[y];
			}
		}
	}
}

void menu(char alpha[],string morse[]) {
	string choice;
	cout << "Welcome to the morse code program";
	while (1)
	{
		cout << "\nPlease select an option.\n1) Encrypt\n2) Decrypt\n3) Exit\n>>> ";
		getline(cin, choice);
		cin.clear();
		if (choice == "1" || choice == "Encrypt") {
			encrypt(alpha,morse);
		}
		else if (choice == "2" || choice == "Decrypt") {
			decrypt(alpha,morse);
		}
		else if (choice == "3" || choice == "Exit") {
			break;
		}
		else {
			cout << "Please select a valid option";
		}
	}
}

int main()                 
{
	char alpha[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	string morse[26] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };
	menu(alpha,morse);
}