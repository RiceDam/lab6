//
// Created by eric on 2020-10-27.
//
#include <fstream>
#include <iostream>
#include "dictionary.hpp"

// Inserts words from the dictionary.txt file into the map
void Dictionary::storeWords() {
    ifstream txt;
    txt.open("../dictionary.txt");
    string line;
    string word;
    string define;
    int count = 1;
    if (txt.is_open()) {
        while (getline(txt, line)) {
            if (count == 1) {
                if (line.find("\r") != string::npos) {
                    word = line.substr(0, line.length()-1);
                } else {
                    word = line;
                }
                count++;
            } else if (count == 2) {
                if (line.find("\r") != string::npos) {
                    define = line.substr(0, line.length()-1);
                } else {
                    define = line;
                }
                words.insert(pair<string, string>(word, define));
                count = 1;
            }
        }
        txt.close();
    } else {
        cout << "Unable to open file" << endl;
    }
}

// Prints the contents of the map
void Dictionary::printDictionary() {
    if (words.empty()) {
        cout << "The dictionary is empty" << endl;
    } else {
        map<string, string>::iterator iter;
        string s = "";
        for (iter = words.begin(); iter != words.end(); iter++) {
            s += iter->first + ": " + iter->second + "\n";
        }
        cout << s << endl;
    }
}

// Checks to see if a word is in the dictionary
bool Dictionary::inDictionary(string word) {
    map<string, string>::iterator iter;
    bool in = false;
    for (iter = words.begin(); iter != words.end(); iter++) {
        if (iter->first == word) {
            in = true;
            break;
        }
    }
    return in;
}

// Inserts the word and its definition into both the dictionary.txt file and the map
void Dictionary::enterNewWord(string word, string def) {
    words.insert(pair<string, string>(word, def));
    ofstream txt;
    txt.open("../dictionary.txt", ofstream::out | ofstream::app);
    if (txt.is_open()) {
        txt << word << "\n";
        txt << def << "\n";
    } else {
        cout << "Unable to open file" << endl;
    }
}

// Iterates through the map to search for a word's definition if it exists
string Dictionary::findWordDef(string word) {
    map<string, string>::iterator iter;
    string s = "Definition: ";
    for (iter = words.begin(); iter != words.end(); iter++) {
        if (iter->first == word) {
            s += iter->second + "\n";
            return s;
        }
    }
    return "Word does not exist in the dictionary\n";
}
