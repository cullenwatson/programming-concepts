/*
* Cullen Watson ()
* Due
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "Sneaker.h"
#include "Bidder.h"
using namespace std;
void showMenu(vector<Sneaker> sneakers, vector<Bidder> bidders);
void sortFile(string filename, vector<Sneaker> &sneakers);
void sortFile(string filename, vector<Bidder> &bidders);
int main() {

    // create vectors for sneakers and bidders
    vector<Sneaker> sneakers;
    vector<Bidder> bidders;

    // open and add sneakers/bidders to corresponding vectors
    sortFile("../Sneakers.txt", sneakers);
    sortFile("../Bidders.txt", bidders);

    // output the menu
    showMenu(sneakers, bidders);

    return 0;
}
void sortFile(string filename, vector<Sneaker> &sneakers) {

    // open file
    ifstream file;
    file.open(filename);

    double bidPrice;
    string input, itemNumber, itemName;

    // organize data from file
    while (getline(file, input)) {
        itemNumber = input.substr(0, input.find(','));
        input = input.substr(input.find(',') + 1);
        itemName = input.substr(0, input.find(','));
        input = input.substr(input.find(',') + 1);
        bidPrice = stod(input);

        // add data to Sneaker vector
        Sneaker sneaker(itemNumber, itemName, bidPrice);
        sneakers.push_back(sneaker);
    }
    file.close();
}
void sortFile(string filename, vector<Bidder> &bidders) {
    // // open file
    ifstream file;
    file.open(filename);

    double bidPrice;
    string input, itemNumber, itemName;

    // organize data from file
    while (getline(file, input)) {
        itemNumber = input.substr(0, input.find(','));
        input = input.substr(input.find(',') + 1);
        itemName = input.substr(0, input.find(','));
        input = input.substr(input.find(',') + 1);
        bidPrice = stod(input);

        // add data to Bidder vector
        Bidder bidder(itemNumber, itemName, bidPrice);
        bidders.push_back(bidder);
    }
    file.close();
}
void showMenu(vector<Sneaker> sneakers, vector<Bidder> bidders) {

    // have user enter sneaker id
    string id;
    cout << "Enter Sneaker Item Number: ";
    while (cin >> id) {
        // exit if user enters quit
        if (id == "quit" || id == "QUIT")
            break;

        // find bidders for item id
        vector<Bidder> bidsForItem;
        for (Bidder bidder : bidders) {
            if (bidder.getItemNumber() == id) {
                bidsForItem.push_back(bidder);
            }
        }

        // sort bids largest to smallest
        sort(bidsForItem.begin(), bidsForItem.end());

        // print info for each sneaker
        for (Sneaker sneaker : sneakers) {
            if (sneaker.getItemNumber() == id) {
                sneaker.getInfo();
                break;
            }
        }
        // output the bids and bidder id
        cout << setw(10) << "All Bids | Bidder ID" << endl;
        cout << "--------------------" << endl;
        for (Bidder b : bidsForItem) {
            b.getInfo();
        }

        cout << endl << "Enter Sneaker Item Number: ";
    }
}