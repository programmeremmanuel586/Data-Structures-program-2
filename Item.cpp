//
//  Item.cpp
//  program_2
//
//  Created by Emmanuel Amoh on 10/14/20.
//

#include "Item.hpp"

std::ostream& operator<<(std::ostream& os, const Item& i){
    os << "Item: [" << i.getValue() << "]";
    return os;
}

//bool Item::operator< (const Item& other){
//    return key < other.key;
//}
//
//bool Item::operator== (const Item& other){
//    return key == other.key;
//}
