//
//  ReelList.hpp
//  program_2
//
//  Created by Emmanuel Amoh on 10/14/20.
//

#ifndef ReelList_h
#define ReelList_h

#include <iostream>
#include "ReelNode.hpp"

template <typename T>
class ReelList{
private:
    int length;
    ReelNode<T>* currentPos;             // Node that points to item in the list
    ReelNode<T>* head;                   // intialization of a list

public:
    // nullptr means that the beginning of the list points to nothing bc the list is empty
    ReelList(): length{0}, currentPos{nullptr}, head{nullptr}{}
    ~ReelList();
    void MakeEmpty();       // reel is entire list, image is node of list
    void PutItem(T item);
    T GetItem(T item);
    void DeleteItem(T item);
    void ResetList();
    T GetNextItem();
    T GetCurrentItem();
    int GetLength();
    
    // to access currentPos for slot machine
    T* getCurrentPos() {
        return currentPos;
    }
    
};


template <typename T>
void ReelList<T>::MakeEmpty(){
    // Make list empty
    ReelNode<T>* temp = head;   // assign temp pointer to the node at eh head pointer.
    while(length != 0){         // while list is not empty
        head = temp;
        temp = head->next;      // assigned temp to the node after the head
        delete head;            // delete the head node pointed at
        length--;
    }
    head = nullptr;
}

template <typename T>
void ReelList<T>::PutItem(T item){
    // Always create a temp pointer and assign node data to item
    ReelNode<T>* temp = new ReelNode<T>;
    temp->data = item;
    // Add node according to list length
    if (length == 0) {
        temp->next = temp;
        head = temp;
    }
    if (length == 1) {
        head->next = temp;
        temp->next = head;
    }
    if (length > 1) {
        ReelNode<T>* temp2 = head->next;
        head->next = temp;
        temp->next = temp2;
    }
    length++;
}

template <typename T>
T ReelList<T>::GetItem(T item){
    // If head pointer points at item
    ReelNode<T>* temp = head;                 // temp pointer points at the node head points to
    if (temp->data == item) {       // if the node temp is pointing to has data equal to item
        return temp->data;
    }
    // If item is anywhere else
    temp = head->next;              // assign temp pointer to the second node from the head node
    while(temp != head){
        if(temp->data == item){
            return temp->data;
        }
        temp = temp->next;            // move to next node in list
    }
    throw "not found";
}

template <typename T>
void ReelList<T>::DeleteItem(T item){
    // Empty case
    if(head == nullptr)                // if head equals nullptr, then list is empty
        return;

    ReelNode<T>* temp, temp2;                 // Create two pointers
    // Deleting head                // Goal: temp points at node after head, temp2 points at node before head
    temp = head->next;              // temp equals node after head node
    temp2 = head->next;             // assign temp2 to node temp points to for iteration, we want the node right before head.
    while (temp2->next != head) {
        temp2 = temp2->next;        // traverse through linked list until temp2->next is head node
    }
    temp2->next = temp;             // node before head points to node after head
    delete head;                    // delete head node
    head = temp;
    length--;
    return;

    // Deleting any other node in the list
    temp = head->next;
    while(temp != head){                        // while item after current node isn't equal to nullptr
        if(temp->next->data == item){            // if the node after the current node is equal to item
            ReelNode<T>* temp2 = temp->next;        // create a temporary variable to store the node after the current one
            temp->next = temp->next->next;        // node after current node now points to the node after the node after the current node
            delete temp2;                        // the node after the current node is deleted
            length--;                            // list length is substracted by one
            return;                                // exit function (doesn't run line 64)
        }
        temp = temp->next;                        // moves to next node (like length++)
    }
}

template <typename T>
void ReelList<T>::ResetList(){
    currentPos = head;                            // sets the node pointing to the items in the list to the very beginning
}

template <typename T>
T ReelList<T>::GetNextItem(){
    if(currentPos == nullptr)                    // if list is empty (which means there is nothing to check)
        throw "Out of range";

    T data = currentPos->data;                    // creates and assigns new item
    currentPos = currentPos->next;                // assigns next node to current position
    return data;                                  // returns data (which is the item)
}

template <typename T>
T ReelList<T>::GetCurrentItem() {
    return currentPos->data;
}

template <typename T>
int ReelList<T>::GetLength(){
    return length;
}

template <typename T>
ReelList<T>::~ReelList(){
    MakeEmpty();        // deletes each node in the list
}

// I am using a template (T) class for ReelNode or any node that can be
// used to fill this circular linked list


#endif /* ReelList_h */
