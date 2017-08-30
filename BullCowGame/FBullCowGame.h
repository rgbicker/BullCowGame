#pragma once
#include <string>

class FBullCowGame
{
public:
	void Reset(); // TODO make a more rich value.
	int GetMaxTries();
	int GetCurrentTry();
	bool IsGameWon();
	bool ValidGuess(std::string);


private:
	int MyCurrentTry;
	int MyMaxTries;
	

};