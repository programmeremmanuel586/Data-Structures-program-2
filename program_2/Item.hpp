//
//  Item.hpp
//  program_2
//
//  Created by Emmanuel Amoh on 10/14/20.
//

#ifndef Item_hpp
#define Item_hpp

#include <iostream>
//#include <string>

class Item{

private:
    // int key;
    char value;
    
public:
    Item(){}
    Item(char value): value{value}{}

    // int getKey() const{ return key; }
    char getValue() const { return value; }
    bool operator< (const Item& other);
    bool operator== (const Item& other);
};
std::ostream& operator<<(std::ostream& os, const Item& i);

#endif /* Item_hpp */
