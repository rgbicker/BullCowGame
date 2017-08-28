#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
string GetAndPrintGuess();


// the entry point for our application
int main()
{
	PrintIntro();

	constexpr int GuessTimes = 4;
	for (int count = 0; count <= GuessTimes; count++)
	{
		GetAndPrintGuess();

	}

	return 0;
}

// introduce the game
void PrintIntro()
{

	constexpr int WORD_LENGTH = 5;
	cout << "Welcome to Bulls and Cows, a fun word game.\n";
	cout << "Can you guess the " << WORD_LENGTH;
	cout << " letter isogram (a word with no repeating letters) I'm thinking of?\n";
	cout << endl;
	return;
}

// get a guess from the player and print it back
string GetAndPrintGuess()
{

	cout << "Enter your guess: ";
	string Guess = "";
	getline(cin, Guess);

	cout << "Your guess was: " << Guess << " \n";
	cout << endl;
	return Guess;
}