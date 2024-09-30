#include <iostream>

using namespace std;

char randomLetter() {
    char letters[] = "abcdefghijklmnopqrstuvwxyz";
    return letters[rand() % 26];
}

string randomWord() {
    string word = "";

    for (int i = 0; i < rand() % 10; i++) {
        word += randomLetter();
    }
    return word;
}

string randomSentence() {
    string sentence = "";

    for (int i = 0; i < rand() % 30; i++) {
        sentence += randomWord() + " ";
    }
     return sentence;
}

int main() {

    cout << "I've invented a new word! " << randomWord() << "." << endl;

    cout << "Here is a sentence with all the new words I've invented: " << randomSentence() << endl;

    return 0;
}