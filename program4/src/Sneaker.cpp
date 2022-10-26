#include "Sneaker.h"
#include <iomanip>
Sneaker::Sneaker(string itemNumber, string itemName, double bidPrice) {
    ItemNumber = itemNumber;
    ItemName = itemName;
    BidPrice = bidPrice;
}
void Sneaker::getInfo() {
    cout << endl << setw(30) << left << ItemName << endl;
    cout << "Ticker: " << ItemNumber << " | Bid Price: $" << BidPrice << endl << endl;
}
string Sneaker::getItemNumber() {
    return ItemNumber;
}
void Sneaker::setItemNumber(string itemNumber) {
    ItemNumber = itemNumber;
}
string Sneaker::getItemName() {
    return ItemName;
}
void Sneaker::setItemName(string itemName) {
    ItemName = itemName;
}
double Sneaker::getBidPrice() {
    return BidPrice;
}
void Sneaker::setBidPrice(double bidPrice) {
    BidPrice = bidPrice;
}
