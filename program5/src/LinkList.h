//
// Created by pc on 4/30/2021.
//

#ifndef PROGRAM5_LINKLIST_H
#define PROGRAM5_LINKLIST_H


#include "ListNode.h"
#include "Friend.h"

class LinkList {

public:
    LinkList(){
        head = nullptr;
    }

    ~LinkList();
    void add(Friend);
    void display_network();
    Friend get_recommendation(int id);
    int getCount(){ return count;}
    void add_friend(int u, int v);

private:
    ListNode * head;
    int count;
};


#endif //PROGRAM5_LINKLIST_H
