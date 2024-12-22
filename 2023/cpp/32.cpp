#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool isnum(string s)
{
    for (char c : s) if (!isdigit(c)) return false;
    return true;
}

void checkforgears(int start, int end, string line, vector<int> *gears)
{
    int len = line.size();
    string num;
    for (int j = max(0, start); j < min(end, len); j++)
    {
        if (isnum(line.substr(j,3))) 
            num = line.substr(j,3);

        else if ((isnum(line.substr(j,2))) && (!isdigit(line[j-1]))) 
            num = line.substr(j,2);

        else if (isdigit(line[j]) && !isdigit(line[j-1])) 
            num = line[j];

        else continue;

        (*gears).push_back(stoi(num)); 
    }
}

int main()
{
    ifstream inpfile;
    inpfile.open("../test-cases/inp3.txt");

    int sumOfGearRatios = 0;
    string line;
    vector<string> lines;

    while (getline(inpfile, line)) lines.push_back(line);

    for (int i = 0; i < lines.size(); i++)
    {
        string pL = i-1 >= 0 ? lines[i-1] : "";
        string mL = lines[i];
        string nL = i+1 < lines.size() ? lines[i+1] : "";

        for (int j = 0; j < mL.size(); j++)
        {
            vector<int> gears;
            if (string(1,mL[j]) == "*")
            {
                int x = j;

                if (isdigit(pL[x-1])) 
                    checkforgears(x-3, x+2, pL, &gears);
                else if (isdigit(pL[x]) || isdigit(pL[x+1]))
                    checkforgears(x, x+2, pL, &gears);
                
                if (isdigit(mL[x-1])) 
                    checkforgears(x-3, x+2, mL, &gears);
                else if (isdigit(mL[x+1])) 
                    checkforgears(x+1, x+2, mL, &gears);
                
                if (isdigit(nL[x-1])) 
                    checkforgears(x-3, x+2, nL, &gears);
                else if (isdigit(nL[x]) || isdigit(nL[x+1])) 
                    checkforgears(x, x+2, nL, &gears); 
            }
            else continue;

            if (gears.size() == 2) 
            {
                int gearRatio = gears[1]*gears[0];
                sumOfGearRatios += gearRatio;
            }
            else continue;
        }
    }

    cout << "Sum of Gear Ratios: " << sumOfGearRatios;
    cout << endl;

    inpfile.close();
    return 0;
}