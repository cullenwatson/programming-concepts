//
// Created by pc on 4/30/2021.
//

#include "LinkList.h"#include "LinkList.h"
#include <iostream>
#include <vector>
using namespace std;
void LinkList::display_network()
{
    ListNode * current = head;
    if (current == nullptr)
        cout << "Link List is empty" << endl;
    else

        // iterate over the list and display each value
    {   while(current != nullptr)
        {
            current->getValue().display();
            current = current->getNext();
        }
    }
    cout<<endl;
}
void LinkList::add(Friend friendObj)
{
    ListNode * current = head;
    if (current == nullptr) // create a newNode
    { ListNode *newNode = new ListNode;
        newNode->setValue(friendObj);
        newNode->setNext(nullptr);
        head=newNode;
    }
    else
    {  // iterate until we get to the end of the list
        while(current->getNext() != nullptr)
            current = current->getNext();

        // now create a new ListNode
        ListNode * newNode = new ListNode;
        newNode->setValue(friendObj);
        newNode->setNext(nullptr);
        current->setNext(newNode);
    }  // end else
} // end of method add
Friend LinkList::get_recommendation(int id){
    Friend recommendedFriend;
    ListNode * firstUser = head, *secondUser = head;
    // find node of firstUser based on id
    while(secondUser!=NULL){
        if(secondUser->getValue().getId() == id) {
            firstUser = secondUser;
            break;
        }
        secondUser=secondUser->getNext();
    }
    secondUser = head;
    int mostInCommon;

    // loop through secondUser
    while(secondUser != nullptr) {
        // check if the two persons are the same or friends already
        int occurrences = 0;
        Friend friend1 = firstUser->getValue();
        Friend friend2 = secondUser->getValue();
        vector<int> vec1= friend1.getVector();
        vector<int> vec2= friend2.getVector();
        if (!(friend1.getId() == friend2.getId()) && !(friend1.isFriend(friend2))) {
            // loop through first persons friends vector
            for (int i = 0; i < vec1.size(); i++) {
                // loop through second persons friends vector
                for (int j = 0; j < vec2.size(); j++) {
                    // check if the id's match
                    if (vec1[i] == vec2[j]) {
                        occurrences++;
                        break;
                    }
                }
            }
            if(occurrences>mostInCommon){
                recommendedFriend = secondUser->getValue();
                mostInCommon = occurrences;
            }
        }
        secondUser = secondUser->getNext();
    }
    return recommendedFriend;
}
void LinkList::add_friend(int u, int v){
    ListNode * traverse = head;
    while(traverse!=NULL){
        Friend obj = traverse->getValue();
        if(obj.getId()==u){
            obj.addToVector(v);
            break;
        }
        traverse = traverse->getNext();
    }
}

LinkList::~LinkList()
{
    cout << "In LinkList Destructor..." << endl;

    ListNode* current = head;
    ListNode * previous = nullptr;
    while(current != nullptr)
    { previous = current;
        current = current->getNext();
        delete previous;
    } // end while loop
} // end of destructor
