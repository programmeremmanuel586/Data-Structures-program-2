//
//  Game.cpp
//  program_2
//
//  Created by Emmanuel Amoh on 10/14/20.
//

#include <iostream>
#include <string>
#include "Game.hpp"
#include "SlotMachine.hpp"
#include "PayoutTable.hpp"
#include "ReelList.hpp"
#include "ReelNode.hpp"

void Game::PlayGame() {
    
    // To spin
    SlotMachine sm;

    // Calls slot machine function in payout class and accesses points earned
    PayoutTable table;
    
    // String variables
    std::string userChoice, choice, nickname;
    
    // To allow space
    std::cout << std::endl << std::endl;
    
    // Welcome/Intro
    std::cout << "Please enter your nickname: ";
    getline(std::cin, nickname);
    std::cout << std::endl << std::endl;
    std::cout << "Hello, " << nickname << "! Welcome to my Slot Machine Game!\nWhat would you like to do today?" << std::endl;
    std::cout << "Here are your options:" << std::endl;
    std::cout << " - Enter 'Spin' to test your luck" << std::endl;
    std::cout << " - Enter 'Quit' to quit the game" << std::endl;
    std::cout << std::endl << "What would you like to do?: " << std::endl;
    std::cout << "> ";
    getline(std::cin, userChoice);
    
    // Check user response (do while loop starts here)
    while (userChoice != "Spin" && userChoice != "Quit") {
        std::cout << "Your input is incorrect. Please enter one of the following options:" << std::endl;
        std::cout << " - Enter 'Spin' to test your luck" << std::endl;
        std::cout << " - Enter 'Quit' to quit the game" << std::endl;
        std::cout << std::endl << "What would you like to do?: " << std::endl;
        std::cout << "> ";
        getline(std::cin, userChoice);
    }

    do {
    
        if (userChoice == "Spin" || choice == "y") {
            // Generates numbers for circular linked list
            sm.Spin();
            
            // takes 1 dollar from user bank
            userBank--;
            
            // display combo chart, what the user results were, and how much money they got
            table.DisplayPayout();
            
            // Results
            std::cout << "You have a total of $" << (userBank + table.CashEarned()) << " left in your bank." << std::endl << std::endl;
        }
        if (userChoice == "Quit" || choice == "q") {
            std::cout << "We are sad to see you go! Or maybe you're just unlucky. Come again soon!" << std::endl;
             break;
        }
        // When user runs out of cash
        if (userBank == 0) {
            std::cout << "You now have $0 and therefore have no use or busniess playing this game. Goodbye." << std::endl;
             break;
        }

        // Ask the user if they want to keep playing
        std::cout << "Would you like to take another spin? Type 'y' to go for\nanother round or type 'q' to leave the game: " << std::endl;
        std::cout << "> ";
        getline(std::cin, choice);

        if (userChoice == "Quit" || choice == "q") {
            std::cout << "We are sad to see you go, " << nickname << "! Or manybe you're just unlucky. Come again soon!" << std::endl;
        }
    } while (choice != "q");
}
