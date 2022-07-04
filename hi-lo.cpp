#include <iostream>
#include <random>
#include <limits>

constexpr int max_number{ 100 }; 
constexpr int guesses{ 7 };

int getInput() {
	int x{};

	while(!(std::cin >> x) || x < 1 || x > max_number) {
		std::cout << "Please enter a valid number between 0 and 100: ";
		std::cin.clear();		
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	return x;
}

bool won(int guesses, int number) {
	for(int i{ 0 }; i < guesses; ++i) {
		int input{ getInput() };
		if (input < number) {
			std::cout << "Too low\n";
		}
		else if (input > number) { 
			std::cout << "Too high\n";
		}
		else {
			return true;
		}
	}

	return false;
}

int main() {
	char proceed{};
	std::random_device rd;
	std::seed_seq ss{ rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd()};
	std::mt19937 mt{ ss };
	std::uniform_int_distribution getInt{ 1, max_number };

	do {
		int randomNum{ getInt(mt) };

		std::cout << "Let's play a game. I'm thinking of a number between 1 "
		"and 100 (inclusive). You have " << guesses << " tries to guess what it is.\n";			
		
		if (won(guesses, randomNum)) {
			std::cout << "Correct! You win!\n";
		}
		else {
			std::cout << "Sorry, you lose. The correct number was " << randomNum << "\n";			
		}

		do {
			std::cout << "Would you like to play again (y/n)? ";
			std::cin >> proceed;
		}
		while(proceed != 'y' && proceed != 'n');
	}
	while(proceed == 'y');

	std::cout << "Thank you for playing.\n";

	return 0;
}