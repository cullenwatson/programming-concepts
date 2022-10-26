#include "Bidder.h"
#include "iomanip"
Bidder:: Bidder(string itemNumber, string bidderID, double bid) {
    ItemNumber = itemNumber;
    BidderID = bidderID;
    Bid = bid;
}
void Bidder::getInfo() {
    cout << "$" << setw(9) << left << Bid << setw(10) << right << BidderID << endl;
    cout << "--------------------" << endl;
}
bool Bidder::operator<(Bidder& p) {
    return Bid > p.Bid;
}
string Bidder::getItemNumber() {
    return ItemNumber;
}
void Bidder::setItemNumber(string itemNumber) {
    ItemNumber = itemNumber;
}
string Bidder::getBidderID() {
    return BidderID;
}
void Bidder::setBidderID(string bidderID) {
    BidderID = bidderID;
}
double Bidder::getBid() {
    return Bid;
}
void Bidder::setBid(double bid) {
    Bid = bid;
}
