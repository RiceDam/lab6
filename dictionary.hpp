//
// Created by eric on 2020-10-27.
//
#ifndef LAB6_DICTIONARY_HPP
#define LAB6_DICTIONARY_HPP

#include <map>

using namespace std;
class Dictionary {
private:
    map<string, string> words;

public:
    void storeWords();
    void printDictionary();
    void enterNewWord(string word, string def);
    string findWordDef(string word);
    bool inDictionary(string word);
};


#endif //LAB6_DICTIONARY_HPP
