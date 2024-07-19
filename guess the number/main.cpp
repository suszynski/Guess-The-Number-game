#include <iostream>
#include <limits>
#include "random.h" // learncpp.com random header for random number generation


using ll = long long; // Defining a type alias for long long

void ignoreLine() // Clears the input buffer.
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Clears bad input and returns true if the input was invalid.
bool clearInput()
{
	if (!std::cin)
	{
		std::cin.clear();	// Clear the error flag on cin
		ignoreLine();		// Clear the input buffer
		return true;		// Indicate that input was invalid
	}
	return false;			 // Indicate that input was valid
}



// Function to ask the user for a range of positive numbers
ll askRange()
{
	ll range{};
	while (true)
	{
		std::cout << "What range of positive numbers do you want?\n";
		std::cout << "Minimum range is 2: ";

		std::cin >> range;
		if (clearInput() || range < 2) // Check for invalid input or if range is less than 2
		{
			std::cout << "Wrong input.\n\n";
			continue;
		}

		ignoreLine(); // Clear the input buffer

		std::cout << '\n';

		return range; // Return the valid range
	}

}


// Function to generate a random number within the given range
ll generateNumber(ll range)
{
	return Random::get<ll>(1, range); // Generate a random number between 1 and range (inclusive)
}


// Function to take the user's guess
ll takeGuess()
{
	ll guess{};
	while (true)
	{
		std::cout << "Enter your guess: ";
		std::cin >> guess;
		
		if (clearInput() || guess <= 0) // Check for invalid input or if guess is non-positive
		{
			std::cout << "Please enter a valid number.\n\n";
			continue;
		}

		return guess; // Return the valid guess

	}

}




int main()
{

	std::cout << "Welcome to guess the number game!\n\n";

	while (true) // Main game loop
	{

		ll numberToGuess{ generateNumber(askRange()) };

		while (true) // Loop for guessing the number
		{

			ll guess{ takeGuess() }; // Take the user's guess


			if (guess > numberToGuess)
			{
				std::cout << "Your number is too big! Try again.\n";
			}
			else if(guess < numberToGuess)
			{
				std::cout << "Your number is too small! Try again.\n";
			}
			else
			{
				std::cout << "\nCongratulations! You entered a good number.\n";
				std::cout << "Do you want to try again? (y/n) ";
				char choice{};




				while (true) // Loop for getting user's choice to continue or exit
				{

					std::cin >> choice;
					if (clearInput() || (choice != 'y' && choice != 'n')) // Check for invalid input or if choice is not 'y' or 'n'
					{
						std::cout << "Wrong input given! Try again.\n";
						ignoreLine();
						continue;
					}
					else if (choice == 'n') // If the user chooses to exit
					{
						std::cout << "Exiting...";
						return 0;
					}

					break; // Break out of the choice loop

				}


				ignoreLine(); // Clear the input buffer
				std::cout << "Starting a new game...\n\n";
				break; // Break out of the guessing loop to start a new game



			}


		}
	}


	return 0;
}