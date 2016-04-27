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

    ifstream file;
    ofstream newfile;
    string word;
    string filePath = "data/01.txt";
    string destPath = "translated/01.txt";
    int textsRead = 1;
    cout << "Open textfile data/0" << textsRead << ".txt\n";
    file.open(filePath);
    newfile.open(destPath);
    int pos = 0;
    int maxI = 0;
    size_t period;


    // Translate texts
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
                    if (pos > maxI) maxI = pos;
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
                cout << "Open textfile data/" << textsRead << ".txt\n";
            } else
                cout << "Open textfile data/0" << textsRead << ".txt\n";

            file.open(filePath);
            newfile.open(destPath);
        }
    }
    cout << "\nUnique words in hashtable: " << hashTable.size() << "\n"
    << "Maximum id: " << maxI << "\n";

    // Compare translated texts    
    string line, comparedLine;
    ifstream comparedFile;
    int readLines = 0; int atLine = 0; int numWords = 0;
    filePath = "translated/01.txt";
    newfile.open("result.txt");

    if (!newfile.is_open()) return 0;
    // need to loop it around all texts to compare everything
    for (int t = 1; t < 11; ++t) {
        ostringstream ns;
        ns << "translated/0" << t << ".txt";
        filePath = ns.str();

        if (t == 10) {
            filePath = "translated/10.txt";
            newfile << "\n*** Compare textfile translated/" << t << ".txt ***\n\n";
            cout << "Compare textfile translated/" << t << ".txt\n";
        } else {
            newfile << "\n*** Compare textfile translated/0" << t << ".txt ***\n\n";
            cout << "Compare textfile translated/0" << t << ".txt\n";
        }
        file.open(filePath);
        if (file.is_open()) {
            atLine = 0; numWords = 0;
            while (getline(file, line)) {
                // check witha ll other text's lines to see how it compares
                istringstream stream(line);
                numWords = distance(istream_iterator<string>(stream), istream_iterator<string>());
                atLine++;
                for (int i = 1; i < 11; ++i) {
                    if (i == t) continue; // skip comparing a text with itself
                    ostringstream cs;
                    cs << "translated/0" << i << ".txt";
                    destPath = cs.str();
                    if (i == 10) destPath = "translated/10.txt";
                    comparedFile.open(destPath);
                    if (comparedFile.is_open()) {
                        while (getline(comparedFile, comparedLine)) {
                            readLines++;
                            if (numWords > 1 && comparedLine == line) {
                                if (i == 10)
                                    newfile << "Line " << atLine << " is similar to " << i << ".txt at line " << readLines << "\n";
                                else 
                                    newfile << "Line " << atLine << " is similar to 0" << i << ".txt at line " << readLines << "\n";

                                newfile << "\"";
                                istringstream stream(line);
                                for (string currWord; stream >> currWord; ) {
                                    for (auto it = hashTable.begin(), end = hashTable.end(); 
                                        it != end; ++it) {
                                        if (it->second == stoi(currWord)){
                                            newfile << it->first << " ";
                                            break;
                                        }
                                    }
                                }
                                //newfile << line << " ";    
                                newfile << "\"\n\n";

                                // can't decode since we have a map data structure, can only find Key (string word)
                                // hashTable.find(currWord)->first
                                // make an estimate on how similar it is? better if statement?
                            }
                        }
                        comparedFile.close();
                        readLines = 0;
                    }
                }
            }
            file.close();
        }
    }
    newfile.close();



    return 0;
}
