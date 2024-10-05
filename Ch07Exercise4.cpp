//This program prompts the user for a string, then outputs the string without the vowels.

#include <iostream>
using namespace std;

//Function to remove vowels from a string
string removeVowels(string str) {
    string result = "";
    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u')
            result += c;
}
    
    return result;
}

//Function to check if a character is a vowel
bool isVowel(char ch) {
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
        
}
int main() {
    cout << "Enter a string: ";
    string str;
    getline(cin, str);
    cout << "The string without vowels is: " << removeVowels(str) << endl;

    
    return 0;
}