//
//  SlotMachine.cpp
//  program_2
//
//  Created by Emmanuel Amoh on 10/14/20.
//

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "SlotMachine.hpp"
#include "ReelList.hpp"
#include "ReelNode.hpp"
#include "Item.hpp"

void SlotMachine::Spin() {
    
    // initialize random seed
    srand(static_cast<unsigned int>(time(nullptr)));
    
    char values[] = {'A', 'A', 'A', 'A', 'B', 'B', 'B', 'C', 'C', '7'};
    
    // initialize lists
    for (int i = 0; i < 10; i++) {
        reel1.PutItem(Item(values[i]));
    }
    for (int i = 0; i < 10; i++) {
        reel2.PutItem(Item(values[i]));
    }
    for (int i = 0; i < 10; i++) {
        reel3.PutItem(Item(values[i]));
    }
    
    // Random numbers generated each for their perspective reels
    int randReel1, randReel2, randReel3;
    
    // Random numbers generated
    randReel1 = rand() % 100 + 1;
    randReel2 = rand() % 100 + 1;
    randReel3 = rand() % 100 + 1;
    
    // Reset lists so that currentPos pointer is at start of each list (currentPos is assigned to head of that list)
    reel1.ResetList();
    reel2.ResetList();
    reel3.ResetList();
    
    // figure out how to iterate over a linked list in another class member function
    
    // Reel 1
    int i = 0;
    while (i != randReel1) {
        reel1.GetNextItem();
        i++;
    }
    reelItem1 = reel1.GetCurrentItem();
    
    // Reel 2
    i = 0;
    while (i != randReel2) {
        reel2.GetNextItem();
        i++;
    }
    reelItem2 = reel2.GetCurrentItem();
    
    // Reel 3
    i = 0;
    // Work on this
    while (i != randReel3) {
        reel3.GetNextItem();
        i++;
    }
    reelItem3 = reel3.GetCurrentItem();
}

const Item& SlotMachine::getReelItem1() const {
    return reelItem1;
}
    
const Item& SlotMachine::getReelItem2() const {
    return reelItem2;
}
    
const Item& SlotMachine::getReelItem3() const {
    return reelItem3;
}
