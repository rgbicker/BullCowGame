#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
void PlayGame();
string GetGuess();
bool PlayAgain();


// the entry point for our application
int main()
{
	bool bPlayAgain = false;
	do
	{ 
	PrintIntro();
	PlayGame();
	bPlayAgain = PlayAgain();	
	} 
	while (bPlayAgain);
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



// loop for number of turns asking for guesses
void PlayGame()
{
	
	constexpr int GuessTimes = 4;
	for (int count = 0; count <= GuessTimes; count++)
	{
		string Guess = GetGuess();
		cout << "Your guess was: " << Guess << " \n";
		cout << endl;

	}
}

// asks the player if they want to play again
bool PlayAgain()
{
	cout << "Do you want to play again (y/n)? ";
	string Response = "";
	getline(cin, Response);	
	return (Response[0] == 'y') || (Response[0] == 'Y');


}

