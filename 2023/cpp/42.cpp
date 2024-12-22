#include <bits/stdc++.h>
using namespace std;

vector<string> winningNum, myNum;

void splitfunc(string card)
{
    string part;
    vector<string> cp;

    istringstream iss(card);
    while (iss >> part) cp.emplace_back(part);

    //begin()+2 means we are skipping card and cardno. 
    vector<string>::iterator it;
    for (it = cp.begin()+2; (*it) != "|"; it++)
    {
        winningNum.emplace_back(*it);
    }

    while (it != cp.end())
    {
        myNum.emplace_back(*(it+1));
        it++;
    }
}

int main()
{
    ifstream inpfile;
    inpfile.open("../test-cases/inp4.txt");

    string card;
    vector<string> cards;

    while (getline(inpfile, card)) cards.emplace_back(card);

    unordered_map<int, int> hashmap;
    for (int i = 1; i < cards.size()+1; i++)
    {
        hashmap[i] = 1;
    }

    int cNo, totalScratchCards;
    cNo = totalScratchCards = 0;

    for (auto card : cards)
    {
        cNo++;
        splitfunc(card);

        int numOfMatch = 0;
        for (int i = 0; i < winningNum.size(); i++)
        {
            for (int j = 0; j < myNum.size(); j++)
            {
                if (myNum[j] == winningNum[i]) numOfMatch++;
            }
        }

        int cnt = hashmap[cNo];

        while (cnt > 0)
        {
            int st = cNo+1, end = st+numOfMatch;
            for (int k = st; k < end; k++)
            {
                hashmap[k]++;
            }
            cnt--;
        }
    }

    for (int i = 1; i < cards.size()+1; i++)
    {
        totalScratchCards += hashmap[i];
    }

    cout << "Total Scratch Cards are: " << totalScratchCards;
    cout << endl;
    inpfile.close();
    return 0;
}