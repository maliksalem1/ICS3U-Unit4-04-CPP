// Copyright (c) 2022 maliksalem
//
// Created on: Oct 2022
// This program checks if you guess the right number

#include <iostream>
#include <random>
#include <string>

int main() {
    // This function sees if you guessed right or wrong
    std::string guessedNumberString;
    int guessedNumberInt;
    int randomNumber;
    while (true) {
        std::random_device rseed;
        std::mt19937 rgen(rseed());
        std::uniform_int_distribution<int> idist(0, 9);
        randomNumber = idist(rgen);

        // Input
        std::cout << "Enter the number between 0-9: ";
        std::cin >> guessedNumberString;
        std::cout << std::endl;

        // Process and Output
        try {
            guessedNumberInt = std::stoi(guessedNumberString);
            if (guessedNumberInt == randomNumber) {
                std::cout << "You guessed right" << std::endl;
                break;
            } else {
                std::cout << "You guessed wrong, try again." << std::endl;
                std::cout << std::endl;
            }
        } catch (std::invalid_argument) {
            std::cout << "That is not an integer, try again." << std::endl;
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
    std::cout << "Done.";
}
