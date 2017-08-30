#include <iostream>
#include <string>
#include "FBullCowGame.h"


void PrintIntro();
void PlayGame();
std::string GetGuess();
bool PlayAgain();

FBullCowGame BCGame; // instantiate a new game

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
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter isogram (a word with no repeating letters) I'm thinking of?\n";
	std::cout << std::endl;
	return;
}

// get a guess from the player
std::string GetGuess()
{
	int CurrentTry = BCGame.GetCurrentTry();
	std::cout << "Try " << CurrentTry;
	std::cout << ". Enter your guess: ";
	std::string Guess = "";
	getline(std::cin, Guess);
	return Guess;


}


void PlayGame()
{	
	int MaxTries = BCGame.GetMaxTries();
	std::cout << "Max tries: " << (MaxTries + 1) << std::endl;
	 // loop for number of turns asking for guesses
	for (int count = 0; count <= MaxTries; count++)
	{
		std::string Guess = GetGuess();
		std::cout << "Your guess was: " << Guess << " \n";
		std::cout << std::endl;

	}
}

// asks the player if they want to play again
bool PlayAgain()
{
	std::cout << "Do you want to play again (y/n)? ";
	std::string Response = "";
	getline(std::cin, Response);	
	return (Response[0] == 'y') || (Response[0] == 'Y');


}

