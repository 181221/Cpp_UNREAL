#include <iostream>
#include <string>
#include "FBullCowGame.h"


void PrintIntro();
void PlayGame();
bool AskToPlayAgain();
std :: string GetGuess();
FBullCowGame BCGame; //Instantiate a new game. Global variable



//Entry point for our application
int main() {
	
	bool bPlayAgain = false;
	do {
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);
	
	return 0; //exit the application
}


//Introduce the game
void PrintIntro() {

	int constexpr WORD_LENGTH = 5;
	std :: cout << "Welcome to Bulls and Cows, a fun word game." << std :: endl;
	std :: cout << "Can you guess the " << WORD_LENGTH;
	std :: cout << " letter isogram I'm thinking of?\n";
	std :: cout << std :: endl;
	return;
}

//Play the game
void PlayGame() {
	
	BCGame.Reset();

	int MaxTries = BCGame.GetMaxTries();

	//loop for the number of turns asking for guesses

	//TODO change from for to while loop
	for (int i = 1; i <= MaxTries; i++) {
		std :: string Guess = GetGuess(); //TODO check valid guesses
		//Submit valid guess to the game
		//print number of bulls and cows
		std :: cout << "Your guess is " << Guess << std :: endl;
		std :: cout << std :: endl;
	}

	// TODO add a game summary
	return;
}

//Get a guess from the player
std :: string GetGuess() {
	
	int GuessNumber = BCGame.GetCurrentTry();
	std::cout << "Try " << GuessNumber << "." << " Enter your guess: ";
	std :: string Guess = "";
	std :: getline(std :: cin, Guess);
	return Guess;
}

//Ask the player if they want to play again
bool AskToPlayAgain() {

	std :: cout << "Do you want to play again (y/n)?";
	std :: string Response = "";
	std :: getline(std :: cin, Response);
	std :: cout << std :: endl;
	return (Response[0] == 'y') || (Response[0] == 'Y');
}
