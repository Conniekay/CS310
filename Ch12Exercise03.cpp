// This program allows the user to enter the last names of five candidates and 
// the number of votes received by each candidate. The program then outputs each 
// candidate's name, the number of votes received, and the percentage of the total 
// votes received as well as the winner of the election.

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    int numCandidates;
    cout << "Enter the number of candidates: ";
    cin >> numCandidates;

    // Dynamically allocate arrays for names, votes, and percentages
    string* names = new string[numCandidates];
    int* votes = new int[numCandidates];
    double* percentages = new double[numCandidates];

    double totalVotes = 0;
    int winnerIndex = 0;

    // Get candidate names and votes from the user
    for (int i = 0; i < numCandidates; i++) {
        bool duplicate;
        do {
            duplicate = false;  // Assume no duplicate initially
            cout << "Enter the last name of candidate " << i + 1 << ": ";
            cin >> names[i];

            // Check for duplicate names in the already entered candidates
            for (int j = 0; j < i; j++) {
                if (names[i] == names[j]) {
                    cout << "Error: The name \"" << names[i] << "\" has already been entered. Please enter a different name." << endl;
                    duplicate = true;
                    break;
                }
            }
        } while (duplicate);

        // Get votes for the candidate
        cout << "Enter the number of votes received by " << names[i] << ": ";
        cin >> votes[i];
        totalVotes += votes[i];
    }
    

    // Calculate percentages and determine the winner
    for (int i = 0; i < numCandidates; i++) {
        percentages[i] = (votes[i] / totalVotes) * 100;

        if (votes[i] > votes[winnerIndex]) {
            winnerIndex = i;
        }
    }

    // Output the results
    cout << endl << "Candidate\t\tVotes\t\tPercentage" << endl;
    for (int i = 0; i < numCandidates; i++) {
        cout << names[i] << "\t\t" << votes[i] << "\t\t";
        cout << fixed << setprecision(2) << percentages[i] << "%" << endl;
    }

    cout << "The winner of the election is: " << names[winnerIndex] << endl;

    return 0;
}