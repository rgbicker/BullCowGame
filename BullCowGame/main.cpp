#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
void PlayGame();
string GetGuess();



// the entry point for our application
int main()
{
	PrintIntro();

	PlayGame();

	// exit the application
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

// get a guess from the player
string GetGuess()
{

	cout << "Enter your guess: ";
	string Guess = "";
	getline(cin, Guess);
	return Guess;


}


void PlayGame()
{
	//Loop for number of turns asking for guesses
	constexpr int GuessTimes = 4;
	for (int count = 0; count <= GuessTimes; count++)
	{
		string Guess = GetGuess();
		cout << "Your guess was: " << Guess << " \n";
		cout << endl;

	}
}