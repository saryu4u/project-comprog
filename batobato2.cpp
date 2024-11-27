#include <bits/stdc++.h>
using namespace std;

class RockPaperScissorsGame {
private:
    char playerChoice;
    char computerChoice;

public:
    void getUserChoice() {
        do {
            cout << "ROCK-PAPER-SCISSORS GAME" << endl;
            cout << "1. ROCK" << endl;
            cout << "2. PAPER" << endl;
            cout << "3. SCISSORS" << endl;
            cout << "CHOOSE YOUR PICK: ";
            cin >> playerChoice;
        } while (playerChoice != '1' && playerChoice != '2' && playerChoice != '3');
    }

    void getComputerChoice() {
        srand(time(NULL));
        int num = rand() % 3 + 1;

        switch (num) {
            case 1:
                computerChoice = '1';
                break;
            case 2:
                computerChoice = '2';
                break;
            case 3:
                computerChoice = '3';
                break;
        }
    }

    void showChoice(char choice) {
        switch (choice) {
            case '1':
                cout << "ROCK" << endl;
                break;
            case '2':
                cout << "PAPER" << endl;
                break;
            case '3':
                cout << "SCISSORS" << endl;
                break;
        }
    }

    void chooseWinner() {
        if (playerChoice == computerChoice) {
            cout << "IT'S A TIE!!" << endl;
        } else if ((playerChoice == '1' && computerChoice == '3') ||
                   (playerChoice == '2' && computerChoice == '1') ||
                   (playerChoice == '3' && computerChoice == '2')) {
            cout << "YOU WINNNNN!!!" << endl;
        } else {
            cout << "YOU LOSE!! BETTER LUCK NEXT TIME!" << endl;
        }
    }

    char continuePlaying() {
        char choice;
        cout << "I MISS YOU KITA NA TAYO ULET :> \n";
        cout << "DO YOU WANT TO CONTINUE PLAYING? (y/n): ";
        cin >> choice;
        if (choice == 'n' || choice == 'N') {
            return 'n';
        } else if (choice == 'y' || choice == 'Y') {
            return 'y';
        } else {
            return continuePlaying();
        }
    }

    void playGame() {
        char continueChoice;
        do {
            getUserChoice();
            cout << "YOUR CHOICE IS ";
            showChoice(playerChoice);

            getComputerChoice();
            cout << "COMPUTER CHOICE IS ";
            showChoice(computerChoice);

            chooseWinner();
            cout << endl;

            continueChoice = continuePlaying();
            if (continueChoice == 'n') {
                cout << "THANK YOU FOR PLAYING" << endl;
            } else if (continueChoice != 'y') {
                cout << "WRONG INPUT" << endl;
            }
        } while (continueChoice == 'y');
    }
};

int main() {
    RockPaperScissorsGame game;
    game.playGame();
    return 0;
}
