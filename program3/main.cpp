#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <locale>
#include <vector>
#include <iomanip>

using namespace std;

//function declaration
string tolowercase(string);

vector<vector<string>> readFile(ifstream &);

int singles(int, int, int, int);

int totalbases(int, int, int, int);

double battingavg(int, int);

double slugging(int, int);

void printStats(vector<vector<string>>, int);

void sortAlpha(vector<vector<string>> &, int, int);

void sortSlug(vector<vector<string>> &, int, int);

void sortBat(vector<vector<string>> &, int, int);


int main() {
    //sports stats
    vector<vector<string>> stats;
    //user input
    string line;
    //program power
    bool power = true;
    //loop through menu until user quits
    while (power) {
        cout << "Please enter a command: ";
        //get user input
        getline(cin, line);
        //get first word
        string word;
        stringstream ss(line);
        ss >> word;
        //change to lowercase
        word = tolowercase(word);
        //if input has input file
        if (word == "input") {
            ifstream file;
            //get file
            ss >> word;
            //open file
            cout << endl << "Reading " << word << "..." << endl;
            //open users table file
            file.open(word);
            //check if it was opened properly
            if (!file.is_open()) {
                cout << "Could not open file " << word << ". Please try again..." << endl;
            }
            //read file
            stats = readFile(file);
            //close file
            file.close();
            cout << "Completed reading in players data!" << endl << endl;
        }
            //if input is team request
        else if (word == "team") {
            //get team
            ss >> word;
            //find players on team
            vector<vector<string>> results;
            for (int x = 0; x < stats.size(); x++) {
                //to lowercase
                string temp = tolowercase(stats[x][1]);
                word = tolowercase(word);
                //if match found add to results subvector
                if (temp == word) {
                    results.push_back(stats[x]);
                }
            }
            //if no players were found
            if (results.size() == 0) {
                cout << endl << "No players were found under this team name. :(" << endl;
            } else {
                //sort results in alphabetical order
                sortAlpha(results, 0, results.size() - 1);
                //print results
                printStats(results, results.size());
            }
        }
            //if input is report
        else if (word == "report") {
            //get num
            int num;
            ss >> num;
            //get next word
            ss >> word;
            word = tolowercase(word);
            //if input is batting
            if (word == "batting") {
                //sort results in bat avg order
                sortBat(stats, 0, stats.size() - 1);
                //print results
                printStats(stats, num);
            }
                //if input is slugging
            else if (word == "slugging") {
                //sort results in slugging order
                sortSlug(stats, 0, stats.size() - 1);
                //print results
                printStats(stats, num);
            }
                //other
            else {
                cout << endl << "Command is invalid! Please try again..." << endl;
            }
        }
            //if input is quit
        else if (word == "quit") {
            cout << "Goodbye!" << endl;
            power = false;
        }
            //invalid input
        else {
            cout << endl << "Command is invalid! Please try again..." << endl;
        }
    }
}

//convert strings to lowercase
string tolowercase(string original) {
    //copy string
    string output = original;
    locale loc;
    //convert each char to lowercase
    for (string::size_type i = 0; i < original.length(); ++i) {
        output[i] = tolower(original[i], loc);
    }
    //return lowercase string
    return output;
}

//read file
vector<vector<string>> readFile(ifstream &file) {
    vector<vector<string>> table;
    //read through all lines of file
    while (!file.eof()) {
        //row of table
        vector<string> row;
        string line;
        //get line from file
        getline(file, line);
        //check if line is empty
        if (line == "") {
            break;
        }
        //put line into string
        stringstream ss(line);
        //read line
        string name, team, temp;
        int played, bats, runs, hits, doubles, triples, homeruns;
        for (int x = 0; x < 9; x++) {
            //check for name
            if (x == 0) {
                getline(ss, name, ';');
            }
                //check for team
            else if (x == 1) {
                ss >> team;
                //drop semicolon
                team = team.substr(0, team.size() - 1);
            }
                //get played
            else if (x == 2) {
                ss >> temp;
                //store val
                played = stoi(temp);
            }
                //get bats
            else if (x == 3) {
                ss >> temp;
                //store val
                bats = stoi(temp);
            }
                //get runs
            else if (x == 4) {
                ss >> temp;
                //store val
                runs = stoi(temp);
            }
                //get hits
            else if (x == 5) {
                ss >> temp;
                //store val
                hits = stoi(temp);
            }
                //get doubles
            else if (x == 6) {
                ss >> temp;
                //store val
                doubles = stoi(temp);
            }
                //get triples
            else if (x == 7) {
                ss >> temp;
                //store val
                triples = stoi(temp);
            }
                //get homeruns
            else if (x == 8) {
                ss >> homeruns;
            }
        }
        //get singles
        int single = singles(hits, doubles, triples, homeruns);
        //get total bases
        int totalbase = totalbases(single, doubles, triples, homeruns);
        //get batting average
        double bat_avg = battingavg(hits, bats);
        //get slugging percentage
        double slug = slugging(totalbase, bats);
        //place stats in vector
        vector<string> stats;
        stats.push_back(name);
        stats.push_back(team);
        stats.push_back(to_string(bat_avg));
        stats.push_back(to_string(slug));
        //add to table
        table.push_back(stats);
    }
    return table;
}

//calculate singles
int singles(int hits, int doubles, int triples, int homeruns) {
    return hits - (doubles + triples + homeruns);
}

//calculate total bases
int totalbases(int singles, int doubles, int triples, int homeruns) {
    return singles + 2 * doubles + 3 * triples + 4 * homeruns;
}

//calculate batting averatge
double battingavg(int hits, int bats) {
    return (double) hits / (double) bats;
}

//calculate slugging
double slugging(int totalbases, int bats) {
    return (double) totalbases / (double) bats;
}

//display player stats
void printStats(vector<vector<string>> stats, int num) {
    cout << setprecision(3);
    cout << fixed;
    //print header
    cout << "Name\t\t\t\tTeam\t\tBattling %\tSlugging %" << endl;
    //print player stats
    for (int x = 0; x < num; x++) {
        //print with formating
        printf("%-19s %-11s %-11.3f %.3f\n", stats[x][0].c_str(), stats[x][1].c_str(), stod(stats[x][2]),
               stod(stats[x][3]));
    }
    cout << endl;
}

//sort players by name
void sortAlpha(vector<vector<string>> &stats, int left, int right) {
    //end sort if size is less than or equal to 1
    if (left >= right) {
        return;
    }
    //quicksort vector
    vector<string> pivot = stats[right];
    int num = left;
    for (int i = left; i <= right; i++) {
        //swap elements in alphabetical order
        if (stats[i][0] <= pivot[0]) {
            vector<string> temp = stats[num];
            stats[num] = stats[i];
            stats[i] = temp;
            num++;
        }
    }
    //sort left side
    sortAlpha(stats, left, num - 2);
    //sort right side
    sortAlpha(stats, num, right);
}

//sort players by slug
void sortSlug(vector<vector<string>> &stats, int left, int right) {
    //end sort if size is less than or equal to 1
    if (left >= right) {
        return;
    }
    //quicksort vector
    vector<string> pivot = stats[right];
    int num = left;
    for (int i = left; i <= right; i++) {
        //swap elements by slug
        if (stod(stats[i][3]) >= stod(pivot[3])) {
            vector<string> temp = stats[num];
            stats[num] = stats[i];
            stats[i] = temp;
            num++;
        }
    }
    //sort left side
    sortSlug(stats, left, num - 2);
    //sort right side
    sortSlug(stats, num, right);
}

//sort players by bat
void sortBat(vector<vector<string>> &stats, int left, int right) {
    //end sort if size is less than or equal to 1
    if (left >= right) {
        return;
    }
    //quicksort vector
    vector<string> pivot = stats[right];
    int num = left;
    for (int i = left; i <= right; i++) {
        //swap elements by bat avg
        if (stod(stats[i][2]) >= stod(pivot[2])) {
            vector<string> temp = stats[num];
            stats[num] = stats[i];
            stats[i] = temp;
            num++;
        }
    }
    //sort left side
    sortBat(stats, left, num - 2);
    //sort right side
    sortBat(stats, num, right);
}