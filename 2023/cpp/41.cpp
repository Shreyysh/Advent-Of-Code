#include <bits/stdc++.h>
using namespace std;

vector<string> winningNum, myNum;

void splitfunc(string card) 
{
    string part;
    vector<string> cp;
    istringstream iss(card);
    while (iss >> part) cp.emplace_back(part);

    vector<string>::iterator it;
    for (it = cp.begin()+2; *it != "|"; it++) {
        winningNum.emplace_back(*(it));
    }

    while (it != cp.end()) {
        myNum.emplace_back(*(it+1));
        it++;
    }
}

int main(void)
{
    ifstream inpfile;
    inpfile.open("../test-cases/inp4.txt");

    string card;
    vector<string> cards;
    while (getline(inpfile, card)) cards.emplace_back(card);

    int totalPoints = 0;

    for (auto card : cards) {
        int cardVal = 0;
        splitfunc(card);
        
        for (auto mn : myNum) {
            for (auto wn : winningNum) {
                if (wn == mn) {
                    cardVal = cardVal==0 ? 1 : cardVal*2;
                }
            }
        }

        winningNum.clear();
        myNum.clear();

        totalPoints += cardVal;
    }

    cout << "Total points are: " << totalPoints << endl;
    inpfile.close();
    return 0;
}