/*
 * Cullen Watson
 * 
 * Program to recommend a suggested friend to a user based on mutual friends
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <sstream>
#include "Friend.h"
#include "LinkList.h"
#include "ListNode.h"
using namespace std;
int users=0;
ifstream open_file();
LinkList *read_file(ifstream &);
void recommend_user(LinkList *network);

int main() {
    cout<<"Welcome to the Social Network!\n\n";
    ifstream receive = open_file();
    LinkList *ll = read_file(receive);

    recommend_user(ll);
    cout<<"\nGoodbye!\n";
}

ifstream open_file() {
    string filename = "../";
    cout << "Enter file name: ";
    cin >> filename;
    ifstream receive;
    receive.open("../" + filename);
    cout<<"Reading in the network file...\n\n";
    if (!receive.is_open()) {
        cout << "Invalid file";
        exit(EXIT_FAILURE);
    }
    cout<<"Successfully read in network file!\n\n";


    return receive;
}
LinkList *read_file(ifstream &receive) {
    LinkList *ll = new LinkList;
    ListNode *current = nullptr;
    // get number of friends
    int n;
    string line;
    getline(receive, line);
    stringstream ss(line);
    ss>>n;
    users = n;
    // read in the names
    string name = "";
    Friend friendArray[n];
    for (int i = 0; i < n; i++) {
        getline(receive, name);
        if(name.find("\r") != string::npos)
        {
            name.erase(name.size()-1);
        }

        friendArray[i] = Friend(i, name);
    }
    int temp1 = 0, temp2 = 0;
    while (true) {
        receive >> temp1 >> temp2;
        if(receive.eof()) break;
        friendArray[temp1].addFriend(friendArray[temp2]);
    }
    // add to linked list
    for (int i = 0; i < n; i++)
        ll->add(friendArray[i]);

    receive.close();
    return ll;
}
void recommend_user(LinkList *network){

    int n=-1, count;
    bool check;
    string loop;
    do{
        count=0;
        do{
            if(count>0)
                cout<<"Error: input must be an integer between 0 and "<<users-1<<endl;
            cout<<"Enter an integer in the range 0 to " <<users-1<<": ";
            cin>>n;

            count++;
        } while(n<0 || n>users-1);

        Friend recommendFriend = network->get_recommendation(n);
        cout<<"The suggested friend for "<<n<<" is "<<recommendFriend.getId()<<"\n\n";
        cout<<"Do you want to continue (yes/no)? ";
        cin>>loop;
        if((loop=="no")|| (loop=="No")||(loop=="NO")||(loop=="nO"))
            check = false;
        else
            check = true;
    } while(check);
}