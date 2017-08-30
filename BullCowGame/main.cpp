#include <iostream>
#include <string>


void PrintIntro();
void PlayGame();
std::string GetGuess();
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
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter isogram (a word with no repeating letters) I'm thinking of?\n";
	std::cout << std::endl;
	return;
}

// get a guess from the player
std::string GetGuess()
{

	std::cout << "Enter your guess: ";
	std::string Guess = "";
	getline(std::cin, Guess);
	return Guess;


}



// loop for number of turns asking for guesses
void PlayGame()
{
	
	constexpr int GuessTimes = 4;
	for (int count = 0; count <= GuessTimes; count++)
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

