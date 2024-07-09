#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

int minimumDifference = INT_MAX;
vector<vector<int>> skillMatrix(20, vector<int>(20));

int calculateTeamSkill(vector<int> team) {
    int teamSize = team.size();
    int totalSkill = 0;
    for (int i = 0; i < teamSize; i++) {
        for (int j = 0; j < teamSize; j++) {
            if (i == j) { continue; }
            totalSkill += skillMatrix[team[i]][team[j]];
        }
    }
    return totalSkill;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int numPlayers;
    cin >> numPlayers;

    for (int i = 0; i < numPlayers; i++) {
        for (int j = 0; j < numPlayers; j++) {
            cin >> skillMatrix[i][j];
        }
    }

    for (int teamSize = 1; teamSize <= numPlayers / 2; teamSize++) {
        vector<int> teamSelection;
        for (int j = 0; j < numPlayers - teamSize; j++) { teamSelection.push_back(0); }
        for (int j = 0; j < teamSize; j++) { teamSelection.push_back(1); }

        do {
            vector<int> teamA;
            vector<int> teamB;
            for (int j = 0; j < numPlayers; j++) {
                if (teamSelection[j]) { teamA.push_back(j); }
                else { teamB.push_back(j); }
            }

            int currentDifference = abs(calculateTeamSkill(teamA) - calculateTeamSkill(teamB));
            if (currentDifference < minimumDifference) { minimumDifference = currentDifference; }
        } while (next_permutation(teamSelection.begin(), teamSelection.end()));
    }

    cout << minimumDifference << '\n';
}
