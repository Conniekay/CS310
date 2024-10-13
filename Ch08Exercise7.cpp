//This program allows the user to enter the last names of five candidates and the number of votes received by each candidate. The program will then output each candidate's name, the number of votes received, and the percentage of the total votes received as well as the winner of the election.

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
int main() {
    const int NUM_CANDIDATES = 5;
    string names[NUM_CANDIDATES];
    int votes[NUM_CANDIDATES];
    double totalVotes = 0;
    int winnerIndex = 0;

    // Get candidate names and votes from user
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        cout << "Enter the last name of candidate " << i+1 << ": ";
        cin >> names[i];
        cout << "Enter the number of votes received by " << names[i]
            << ": ";
        cin >> votes[i];
        totalVotes += votes[i];
    }
    // Calculate percentages and find winner
    double percentages[NUM_CANDIDATES];
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        percentages[i] = votes[i] / totalVotes * 100;
    
        if (votes[i] > votes[winnerIndex])
            winnerIndex = i;
        } 

    //Output the results
    cout << endl << "Candidate\t\tVotes\t\tPercentage" << endl;
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        cout << names[i] << "\t\t" << votes[i] << "\t\t" << fixed;
        cout << setprecision(2) << percentages[i] << "%" << endl;
    }     
        

    cout << "The winner of the election is: " << names[winnerIndex] << endl;

    return 0;
}