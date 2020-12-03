//
//  PayoutTable.hpp
//  program_2
//
//  Created by Emmanuel Amoh on 10/14/20.
//

#ifndef PayoutTable_hpp
#define PayoutTable_hpp

#include "SlotMachine.hpp"

class PayoutTable {
private:
    // {} sets value to zero
    int playerEarnings{};         // cash player recieves from spin
    
public:
    void DisplayPayout();
    int CashEarned() const;
};

#endif /* PayoutTable_hpp */
