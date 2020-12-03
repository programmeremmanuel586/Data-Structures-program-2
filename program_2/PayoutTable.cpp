//
//  PayoutTable.cpp
//  program_2
//
//  Created by Emmanuel Amoh on 10/14/20.
//

#include "PayoutTable.hpp"
#include "SlotMachine.hpp"
#include "Item.hpp"
#include <iostream>

void PayoutTable::DisplayPayout() {
    
    // Create a slot machine instance
    SlotMachine sm;
    sm.Spin();
    
    std::cout << std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout << "| Combination | Payout  |" << std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout << "|    A A A    |  $6     |" << std::endl;
    std::cout << "|    B B B    |  $15    |" << std::endl;
    std::cout << "|    C C C    |  $50    |" << std::endl;
    std::cout << "|    7 7 7    |  $500   |" << std::endl;
    std::cout << "-------------------------" << std::endl;
    
    std::cout << "Your reel results: " << sm.getReelItem1().getValue() << " " << sm.getReelItem2().getValue() << " " << sm.getReelItem3().getValue() << std::endl;
    
    // Space
    std::cout << std::endl;

    // Player earnings from Spin
    playerEarnings = 0;

    std::cout << "Message: ";

    // check if combination is met
    if (sm.getReelItem1().getValue()  == 'A' && sm.getReelItem2().getValue() == 'A' && sm.getReelItem3().getValue() == 'A') {
        std::cout << "Congrats! You earned $6!" << std::endl << std::endl;
        playerEarnings += 6;
    } else if (sm.getReelItem1().getValue()  == 'B' && sm.getReelItem2().getValue() == 'B' && sm.getReelItem3().getValue() == 'B') {
        std::cout << "Congrats! You earned $15!" << std::endl << std::endl;
        playerEarnings += 15;
    } else if (sm.getReelItem1().getValue()  == 'C' && sm.getReelItem2().getValue() == 'C' && sm.getReelItem3().getValue() == 'C') {
        std::cout << "Congrats! You earned $50!" << std::endl << std::endl;
        playerEarnings += 50;
    } else if (sm.getReelItem1().getValue()  == '7' && sm.getReelItem2().getValue() == '7' && sm.getReelItem3().getValue() == '7') {
        std::cout << "Jackpot!!! You earned $500!!!" << std::endl << std::endl;
        playerEarnings += 500;
    } else {
        std::cout << "Sorry, no cash earned. Maybe next time?" << std::endl << std::endl;
    }
}

// Return player earnings
int PayoutTable::CashEarned() const {
    return playerEarnings;
}
