#include <bits/stdc++.h>
using namespace std;

int main()
{

    char gameOver;
    int players, i = 0;
    cout << "Enter the number of players: ";
    cin >> players;
    cout << "\n";
    string playersName[players];
    int scores[100][players], totalScores[players];
    for (int j = 0; j < players; j++)
    {
        cout << "Enter the Name of player No." << j + 1 << " : ";
        cin >> playersName[j];
    }
    do
    {
        string winner;
        int total = 0, indexWinner;

        cout << "\n\nRound No. " << i + 1 << endl;
        cout << "Enter the Name of the winner: ";
        cin >> winner;
        cout << "\n";
        for (int j = 0; j < players; j++)
        {
            if (playersName[j] != winner)
            {
                cout << "Enter score of " << playersName[j] << ": ";
                cin >> scores[i][j];
                total += abs(scores[i][j]);
            }
            else
            {
                indexWinner = j;
            }
        }
        scores[i][indexWinner] = total;

        cout << "The score of " << winner << " is: " << total;

        for (int j = 0; j < players; j++)
        {
            int sum = 0;
            for (int k = 0; k < i + 1; k++)
            {
                sum += scores[k][j];
            }
            totalScores[j] = sum;
        }

        cout << "\n\n";
        for (int j = 0; j < players; j++)
        {
            cout << "\t" << playersName[j] << "\t";
        }

        cout << "\n";
        for (int k = 0; k < i + 1; k++)
        {
            cout << k + 1 << ". ";
            for (int j = 0; j < players; j++)
            {
                cout << "\t" << scores[k][j] << "\t";
            }
            cout << "\n";
        }

        cout << "\n";

        for (int j = 0; j < players; j++)
        {
            cout << "Total:"
                 << "\t" << totalScores[j] << "\t";
        }

        cout << "\n\nDo you want to continue?(Y/N): ";
        cin >> gameOver;
        if (gameOver == 'n' || gameOver == 'N')
        {
            sort(totalScores, totalScores + players);
            cout << "\tLeader Board\t\n";
            for (int j = 0; j < players; j++)
            {
                cout << j + 1 << "\t" << totalScores[j] << "\n";
            }
        }
        i++;
    } while (gameOver == 'y' || gameOver == 'Y');

    return 0;
}