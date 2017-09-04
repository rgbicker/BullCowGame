
#pragma once
#include <string>

using FString = std::string;
using int32 = int;

// all values intitialized at 0
struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus
{
	Invalid_Status,
	OK,
	Not_Isogram,
	Letters_Only,
	Not_Lowercase,
	Wrong_Length,

};



class FBullCowGame
{
public:
	FBullCowGame(); // constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;

	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(FString) const;

	void Reset(); // TODO make a more rich return value.

	FBullCowCount SubmitValidGuess(FString);

private:
	// see constructor for innitialization
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString  MyHiddenWord;

};