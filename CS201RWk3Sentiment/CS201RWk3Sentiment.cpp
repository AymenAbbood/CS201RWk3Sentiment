// CS201RWk3Sentiment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;


struct sentInfo {
    string word;
    float value;
};

bool isValid(string str) {
    return str.find_first_not_of("0123456789.-") == string::npos;
}

void readFile(vector<sentInfo>& wordV, vector<sentInfo>& posV, vector<sentInfo>& negV) {
    ifstream inFile;
    inFile.open("sentiment.txt");
    if (!inFile.is_open()){
        cout << "Input file invalid\n";
        return;
    }
    string inStr, wordStr, valueStr;
    sentInfo tempInfo;
    int commaPos;
    while (inFile >> inStr) {                   // Read file into a string
        commaPos = inStr.find(',');             // Find location of comma
        wordStr = inStr.substr(0, commaPos);    // set wordStr to inStr up to the comma
        valueStr = inStr.substr(commaPos + 1);  // set valueStr to the end of inStr
        if (isValid(valueStr)) {                // check valueStr has valid numbers
            tempInfo.word = wordStr;            // load a sentInfo type with this data
            tempInfo.value = stof(valueStr);    
            wordV.push_back(tempInfo);          // push it onto the vector
            if (tempInfo.value > 1.5)
                posV.push_back(tempInfo);
            else if (tempInfo.value < -1.5)
                negV.push_back(tempInfo);
        }
        else {
            cout << "Input value not valid\n";
            continue;
        }
    }
}

void printVector(vector<sentInfo> v1) {
    for (int i = 0; i < v1.size(); i++) {
        cout << v1[i].word << v1[i].value << endl;
    }
}


int main()
{
    vector<sentInfo> wordV, posV, negV;
    readFile(wordV, posV, negV);
    printVector(negV);
}

