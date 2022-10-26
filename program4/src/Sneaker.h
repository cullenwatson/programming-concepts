#include <iostream>
#include <string>

using namespace std;

#ifndef SNEAKER_H
#define SNEAKER_H

class Sneaker {
private:
    string ItemNumber;
    string ItemName;
    double BidPrice;
public:
    // constructor
    Sneaker(string itemNumber, string itemName, double bidPrice);
    // get info about sneaker
    void getInfo();

    // get and set values
    string getItemNumber();
    void setItemNumber(string itemNumber);
    string getItemName();
    void setItemName(string itemName);
    double getBidPrice();
    void setBidPrice(double bidPrice);
};

#endif
