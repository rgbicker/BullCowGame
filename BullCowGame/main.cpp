/* This is the console executable that makes use of the BullCow class
This acts as the view in a MVC pattern, and is responsible for all
user interaction. Forgame logic see the FBullCowGame class.
*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
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

	constexpr int32 WORD_LENGTH = 5;
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter isogram (a word with no repeating letters) I'm thinking of?\n";
	std::cout << std::endl;
	return;
}


void PlayGame()
{	
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	// loop for number of turns asking for guesses
	//TODO change from FOR to WHILE loop once validating tries
	std::cout << "Max tries: " << (MaxTries) << std::endl;
	for (int32 count = 1; count <= MaxTries; count++)
	{
		FText Guess = GetGuess(); //TODO make loop checking valid

		// submit valid guess to game and receive counts
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		// print number of bulls and cows

		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << "  Cows = " << BullCowCount.Cows;

		std::cout << std::endl;

	}
	// TODO add a game summary

}

// asks the player if they want to play again
bool PlayAgain()
{
	std::cout << "Do you want to play again (y/n)? ";
	FText Response = "";
	std::getline(std::cin, Response);	
	return (Response[0] == 'y') || (Response[0] == 'Y');


}

// get a guess from the player
FText GetGuess()
{
	int32 CurrentTry = BCGame.GetCurrentTry();
	std::cout << "Try " << CurrentTry;
	std::cout << ". Enter your guess: ";
	FText Guess = "";
	std::getline(std::cin, Guess);
	return Guess;


}