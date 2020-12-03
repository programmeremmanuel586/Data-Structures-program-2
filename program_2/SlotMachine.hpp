//
//  SlotMachine.hpp
//  program_2
//
//  Created by Emmanuel Amoh on 10/14/20.
//

#ifndef SlotMachine_hpp
#define SlotMachine_hpp

#include "ReelList.hpp"
#include "Item.hpp"

class SlotMachine {
private:
    ReelList<Item> reel1;      // reel one
    ReelList<Item> reel2;      // reel two
    ReelList<Item> reel3;      // reel three
    
    // To store item in
    Item reelItem1 {};
    Item reelItem2 {};
    Item reelItem3 {};
    
public:
    void Spin();
    
    // Set item equal to item stored in selected reelnode
    // void setReelItem1(ReelNode item) { reelItem1 = item; }
    // void setReelItem2(ReelNode item) { reelItem2 = item; }
    // void setReelItem3(ReelNode item) { reelItem3 = item; }
    
    void setReelItem1(Item item) { reelItem1 = item; }
    void setReelItem2(Item item) { reelItem2 = item; }
    void setReelItem3(Item item) { reelItem3 = item; }
    
    // Get item stored in list from list pointer
    // ReelNode getReelItem1() const;
    // ReelNode getReelItem2() const;
    // ReelNode getReelItem3() const;
    
    const Item& getReelItem1() const;
    const Item& getReelItem2() const;
    const Item& getReelItem3() const;
};

#endif /* SlotMachine_hpp */
