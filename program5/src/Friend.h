//
// Created by pc on 4/30/2021.
//

#ifndef PROGRAM5_FRIEND_H
#define PROGRAM5_FRIEND_H


#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Friend {
private:
    int id;
    string name;
    vector<int> friendsList;
public:
    Friend();
    Friend(int, string);
    void display();
    void addFriend(Friend &f);
    bool isFriend(Friend &f);
    int getId();
    vector<int> getVector();
    void addToVector(int id);
};


#endif //PROGRAM5_FRIEND_H
