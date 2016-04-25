/*--------------------------------------------------
    Lab3 Part 2 TNM098
    Authors: Jens Jakobsson and Jonathan Bosson
    Date: 2016-04-25
---------------------------------------------------*/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <sstream>

using namespace std;

char easytolower(char in){
  if(in<='Z' && in>='A')
    return in-('Z'-'z');
  return in;
}


int main()
{
    unordered_map<string, int> hashTable;

    string line;
    ifstream file;
    ofstream newfile;
    vector<string> data;
    string word;
    string filePath = "data/01.txt";
    string destPath = "translated/01.txt";
    int textsRead = 1;
    cout << "Open textfile data/0" << textsRead << ".txt" << endl;
    file.open(filePath);
    newfile.open(destPath);
    int pos = 0;
    size_t period;


    //Open file and store every line in a vector
    while (textsRead < 11) // t = 10
    {
        if (file.is_open() && newfile.is_open())
        {
            while( file >> word )
            {
                // Linear replacement and manip of string
                transform(word.begin(),word.end(), word.begin(), easytolower);
                word.erase(remove(word.begin(), word.end(), '"'), word.end());
                word.erase(remove(word.begin(), word.end(), ':'), word.end());
                word.erase(remove(word.begin(), word.end(), ' '), word.end());
                word.erase(remove(word.begin(), word.end(), ','), word.end());
                word.erase(remove(word.begin(), word.end(), '!'), word.end());
                word.erase(remove(word.begin(), word.end(), '?'), word.end());
                word.erase(remove(word.begin(), word.end(), '-'), word.end());
                word.erase(remove(word.begin(), word.end(), '*'), word.end());
                word.erase(remove(word.begin(), word.end(), '_'), word.end());
                word.erase(remove(word.begin(), word.end(), '\''), word.end());
                word.erase(remove(word.begin(), word.end(), ' .'), word.end());

                // if period is found, write new line
                period = word.find('.');
                word.erase(remove(word.begin(), word.end(), '.'), word.end());

                //cout << word << " ";

                auto got = hashTable.find(word);
                if (got == hashTable.end()) // word wasn't found, insert it into hashTable.
                {
                    hashTable.insert(std::pair<string, int>(word, pos));
                    newfile << pos << " ";
                    if (period != std::string::npos)
                        newfile << "\n";
                } else {
                    newfile << got->second << " ";
                    if (period != std::string::npos)
                        newfile << "\n";
                }
                pos++;
            }
        file.close();
        newfile.close();
        textsRead++;
        }
        else {
            ostringstream os;
            os << "data/0" << textsRead << ".txt";
            filePath = os.str();

            ostringstream ws;
            ws << "translated/0" << textsRead << ".txt";
            destPath = ws.str();

            if (textsRead == 10) {
                destPath = "translated/10.txt";
                filePath = "data/10.txt";
                cout << "Open textfile data/" << textsRead << ".txt" << endl;
            } else
                cout << "Open textfile data/0" << textsRead << ".txt" << endl;

            file.open(filePath);
            newfile.open(destPath);
        }
    }
    int maxi = 0;
    for (auto& x: hashTable) {
        if (maxi < x.second)
            maxi = x.second;

        //cout << x.second << " ";
    }

    cout << endl << "Unique words in hashtable: " << hashTable.size() << endl
    << "Maximum id: " << maxi;


    return 0;
}
