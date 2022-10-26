#include <iostream>
#include <string>

using namespace std;

#ifndef BIDDER_H
#define BIDDER_H

class Bidder {
private:
    string ItemNumber;
    string BidderID;
    double Bid;
public:
    // constructor
    Bidder(string itemNumber, string bidderID, double bid);
    // get values about bidder
    void getInfo();
    // determines which bidder has higher bid
    bool operator<(Bidder& p);

    // get and set values
    string getItemNumber();
    void setItemNumber(string itemNumber);
    string getBidderID();
    void setBidderID(string bidderID);
    double getBid();
    void setBid(double bid);


};
#endif
