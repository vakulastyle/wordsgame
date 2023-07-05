#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

// Array of words to be guessed
std::string words[] = {
    "apple",
    "banana",
    "orange",
    "grape",
    "melon",
    "peach"
};

int main() {
    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(0)));

    // Generate a random index to select a word from the array
    int randomIndex = std::rand() % (sizeof(words) / sizeof(words[0]));
    std::string selectedWord = words[randomIndex];

    int numLetters = selectedWord.length();
    int attempts = 5;
    std::string guessedWord(numLetters, '_');

    std::cout << "Welcome to the Word Guessing Game!" << std::endl;
    std::cout << "The word has " << numLetters << " letters." << std::endl;

    while (attempts > 0) {
        std::cout << "Attempts remaining: " << attempts << std::endl;
        std::cout << "Guess the word: " << guessedWord << std::endl;

        std::string guess;
        std::cout << "Enter your guess: ";
        std::cin >> guess;

        if (guess == selectedWord) {
            std::cout << "Congratulations! You guessed the word correctly!" << std::endl;
            break;
        } else {
            std::cout << "Incorrect guess." << std::endl;
            attempts--;
        }
    }

    if (attempts == 0) {
        std::cout << "Game over. You ran out of attempts. The word was: " << selectedWord << std::endl;
    }

    return 0;
}
