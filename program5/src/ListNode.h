//
// Created by pc on 4/30/2021.
//

#ifndef PROGRAM5_LISTNODE_H
#define PROGRAM5_LISTNODE_H
#include <iostream>
#include "Friend.h"
using namespace std;

class ListNode {

public:
    ListNode(){
        next = nullptr;
    }

    ~ListNode(){
        //cout  << "In  ListNode Destructor... Value: " << value<< endl;
    }

    Friend getValue(){ return value; }
    void setValue(Friend val){ value = val; }
    ListNode* getNext(){ return next; }
    void setNext(ListNode * nxt){ next = nxt; }

private:
    Friend value;
    ListNode *next;
};
#endif //PROGRAM5_LISTNODE_H
