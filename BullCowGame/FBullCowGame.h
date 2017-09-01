#pragma once
#include <string>

class FBullCowGame
{
public:
	FBullCowGame(); // constructor

	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset(); // TODO make a more rich value.
	bool ValidGuess(std::string); // TODO make a more rich value.


private:
	// see constructor for innitialization
	int MyCurrentTry;
	int MyMaxTries;
	

};