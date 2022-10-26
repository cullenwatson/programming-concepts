#include "Friend.h"
#include <vector>

Friend::Friend(){

}
Friend::Friend(int i, string n){
    id=i;
    name=n;
}
void Friend::display() {
    cout<<id<<" ("<<name<<"): [";
    for(int i=0; i<friendsList.size(); i++)
        cout<<" "<< friendsList[i];
    cout<<" ]"<<endl;
}
void Friend::addFriend(Friend &f) {
    friendsList.push_back(f.id);
    f.friendsList.push_back(id);
}
bool Friend::isFriend(Friend &f){
    for(int i=0; i<friendsList.size();i++){
        if(friendsList[i]==f.id)
            return true;
    }
    return false;
}
int Friend::getId(){
    return id;
}
vector<int> Friend::getVector(){
    return friendsList;
}

void Friend::addToVector(int id){
    friendsList.push_back(id);
}