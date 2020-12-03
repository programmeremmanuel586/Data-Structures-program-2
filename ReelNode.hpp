//
//  ReelNode.hpp
//  program_2
//
//  Created by Emmanuel Amoh on 10/14/20.
//

#ifndef ReelNode_h
#define ReelNode_h

#include "Item.hpp"

template <typename T>
struct ReelNode {
    T data;
    ReelNode* next;
};

#endif /* ReelNode_h */
