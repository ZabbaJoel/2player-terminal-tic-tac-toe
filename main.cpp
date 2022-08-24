#include <iostream>
#include "board.cpp"

//int 

 int main() {
    int xWins = 0;
    int oWins = 0;
    int totalGames = 0;
    bool keepPlaying = true;

    do {
        board mainboard;
        bool isGameOver = false;

        std::cout << "Welcome to console tic-tac-toe!\n";
        mainboard.renderBoard();

        int movenum = 0;
        do {

            mainboard.promptMove(movenum % 2 == 0);

            std::cout << "Status: " << mainboard.gameStatus() << "\n";

            movenum++;
        } while(mainboard.gameStatus() == 0 && movenum < 9);

        totalGames++;

        switch(mainboard.gameStatus()) {
            case 1:
                xWins++;
                std::cout << "X wins!\n";
                break;
            case 2:
                oWins++;
                std::cout << "O wins!\n";
                break;
            case 0:
                std::cout << "Tie!\n";
        }

        
        std::cout << "The socre is now " << xWins << " (X) to " << oWins << " (O). In " << totalGames <<" total games.\n";
        
        char uinpt;
        std::cout << "Play again? [y/n]: ";
        std::cin >> uinpt;

        keepPlaying = (tolower(uinpt) == 'y');

    } while(keepPlaying);



    std::cout << "Thank you for playing. Here are the final stats: \n";
    std::cout << "X won " << xWins << " times.\n";
    std::cout << "O won " << oWins << " times.\n";
    std::cout << "You guys tied " << totalGames - xWins - oWins << " times.\n";
    std::cout << "You played " << totalGames << " total games.\n";
    return 0;
 }