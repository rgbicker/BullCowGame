#include "FBullCowGame.h"

using int32 = int;
using FString = std::string;

FBullCowGame::FBullCowGame()
{
	Reset();
}

int32 FBullCowGame::GetMaxTries() const
{
	return MyMaxTries;
}

int32 FBullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}

int32 FBullCowGame::GetHiddenWordLength() const
{
	return MyHiddenWord.length();
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	
	return;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString) const
{

	// if the guess isn't an isogram, return an error
	if (false)
	{ 
		return EGuessStatus::Not_Isogram;
	}
	// if the guess isn't all lowercase, return an error
	else if (false)
	{
		return EGuessStatus::Not_Lowercase;
	}
	// if the gues length is wrong, return an error
	else if (false)
	{
		return EGuessStatus::Wrong_Length;
	}
	// if the guess isn't letters, return an eror
	else if (false)
	{
		return EGuessStatus::Letters_Only;
	}
	// otherwise return ok
	else
	{
		return EGuessStatus::OK;
	}
}

// receives a VALID guess, increments turn, and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	// increment turn number
	MyCurrentTry++;

	// setup a return variable 
	FBullCowCount BullCowCount;

	// loop through all letters in the guess
	int32 HiddenWordLength = MyHiddenWord.length();
	for (int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++)
	{
		// compare letters agianst the hidden word
		for (int32 GChar = 0; GChar < HiddenWordLength; GChar++)
		{
			// if they match then
			if (Guess[GChar] == MyHiddenWord[MHWChar])
			{
			// if they're in the same place
				if (MHWChar == GChar)
				{
					// increment bulls
					BullCowCount.Bulls++;
				}
				else 
				{
					// increment cows
					BullCowCount.Cows++;
				}
			}
				
		}
	}
	return BullCowCount;
}
