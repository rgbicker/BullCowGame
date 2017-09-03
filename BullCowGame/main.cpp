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

	
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram (a word with no repeating letters) I'm thinking of?\n";
	return;
}


void PlayGame()
{	
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	// loop for number of turns asking for guesses
	std::cout << "Max tries: " << (MaxTries) << std::endl << std::endl;	
	for (int32 count = 1; count <= MaxTries; count++) //TODO change from FOR to WHILE loop once validating tries
	{
		FText Guess = GetGuess(); 

		EGuessStatus Status = BCGame.CheckGuessValidity(Guess);

		// submit valid guess to game and receive counts
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		
		// print number of bulls and cows
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << "  Cows = " << BullCowCount.Cows << std::endl;

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


FText GetGuess() // get a guess from the player
{
	int32 CurrentTry = BCGame.GetCurrentTry();

	// get a guess from the player
	std::cout << "Try " << CurrentTry << ". Enter your guess: ";
	FText Guess = "";
	std::getline(std::cin, Guess);
	return Guess;

}