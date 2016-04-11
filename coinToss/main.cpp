/*--------------------------------------------------
    Lab1 TNM098
    Authors: Jens Jakobsson and Jonathan Bosson
    Date: 2016-04-11
---------------------------------------------------*/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string line;
    ifstream file;
    vector<string> data;
    vector<int> peopleData;
    vector<string> RNGdata;
    vector<int> idRNG;
    file.open("CoinToss.txt");

    const int MAX_HEAD = 110;
    const int MAX_TAIL = 90;
    const int REPETETIVE_NUMBERS = 7;

    //Open file and store every line in a vector
    if (file.is_open())
    {
        while( getline (file,line) )
        {
            data.push_back(line);
        }
        file.close();
    }

    cout << "Data length: " << data.size() << endl;

    //1. Check deviation between ones and zeros
    for (int i = 0; i < data.size(); i++)
    {
        int head = 0;
        int tails = 0;

        string process = data[i];
        for (std::string::iterator it=process.begin(); it!=process.end(); ++it)
        {

            if (*it == '1')
                head++;
            else
                tails++;
        }
        cout << (i+1) << ".  " << head << " / " << tails << endl;

        if (head > MAX_HEAD || head < MAX_TAIL)
        {
            peopleData.push_back(i);
        }
        else
        {
            RNGdata.push_back(process);
            idRNG.push_back(i);
        }

    }

    cout << "New peopleData length first evaluation: " << peopleData.size() << endl;

    // 2. Check 0 or 1 patterns
    for (int i = 0; i < RNGdata.size(); i++)
    {
        int nrHead = 0;
        int seqHead = 0;
        int nrTails = 0;

        for (std::string::iterator it=RNGdata[i].begin(); it!=RNGdata[i].end(); ++it)
        {
            //If nrTails is higher than REPETETIVE_NUMBERS it is a RNG
            if (*it == '1')
            {
                if (nrTails >= REPETETIVE_NUMBERS)
                {
                    peopleData.push_back(idRNG[i]);
                    break;
                }
                nrTails = 0;
                nrHead++;
            }
            else if (*it == '0')
            {
                if (nrHead >= REPETETIVE_NUMBERS)
                {
                    peopleData.push_back(idRNG[i]);
                    break;
                }
                nrHead = 0;
                nrTails++;
            }
            if (++it == RNGdata[i].end())
            {
                if (nrHead >= REPETETIVE_NUMBERS || nrTails >= REPETETIVE_NUMBERS)
                {
                    peopleData.push_back(idRNG[i]);
                }
            }
        }
    }

    cout << "New peopleData length second evaluation: " << peopleData.size() << endl;

    cout << "The following datapoints are humans: " << endl;
    sort(peopleData.begin(), peopleData.end());
    for (int i = 0; i < peopleData.size() -1; i++)
    {
        cout << peopleData[i]+1 << ", ";
    }
    cout << peopleData[peopleData.size()-1];

    return 0;
}
