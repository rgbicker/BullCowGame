#pragma once
#include <string>

using Fstring = std::string;
using int32 = int;

class FBullCowGame
{
public:
	FBullCowGame(); // constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset(); // TODO make a more rich value.
	bool ValidGuess(Fstring); // TODO make a more rich value.
	// provide a method for counting bulls and cows, and increasing try number


private:
	// see constructor for innitialization
	int32 MyCurrentTry;
	int32 MyMaxTries;
	

};