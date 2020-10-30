#include <iostream>
#include "dictionary.hpp"
int main() {
    Dictionary d;
    // Puts the words from the dictionary.txt file into the map
    d.storeWords();
    bool inMenu = true;
    while (inMenu) {
        bool digit = true;
        string choice;
        int choiceInt;
        cout << "1 - Print Dictionary" << endl << "2 - Find word definition" << endl
                << "3 - Enter new word and definition" << endl << "4 - Exit" << endl;
        cin >> choice;
        cin.ignore();
        for (int i = 0; i < choice.length(); i++) {
            if (!isdigit(choice.at(i))) {
                digit = false;
                break;
            }
        }
        if (digit) {
            choiceInt = stoi(choice);
            switch (choiceInt) {
                case 1:
                    d.printDictionary();
                    break;
                case 2: {
                    cout << "Enter a word to find its definition" << endl;
                    string s;
                    getline(cin, s);
                    cout << d.findWordDef(s);
                    break;
                }
                case 3: {
                    cout << "Enter the word to enter into the dictionary" << endl;
                    string word;
                    getline(cin, word);
                    if (d.inDictionary(word)) {
                        cout << "The word already exists in the dictionary" << endl;
                    } else {
                        cout << "Enter the definition of that word" << endl;
                        string def;
                        getline(cin, def);
                        d.enterNewWord(word, def);
                    }
                    break;
                }
                case 4:
                    inMenu = false;
                    break;
                default:
                    break;
            }
        }
    }
    return 0;
}
