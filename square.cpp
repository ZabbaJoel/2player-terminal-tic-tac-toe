#include <cctype>
#include <iostream>

class square {
    bool taken = false;
    bool isX = false;

public:

    //returns an integer (0, 1, 2)
    //corresponding to (empty, X, O) respectively
    int checkStatus() {
        if (isX){
            //1 means X
            //std::cout << isX;
            return 1;
        } else if(taken) {
            //2 means O
            return 2;
        } else {
            //check that it's unoccupied
            return 0;
        }
    }

    //returns if the square was propperly set
    bool setValue(char move) {
        switch (tolower(move)) {
            case 'x':
                std::cout << "We set the square to X just now\n";
                isX = true;
            case 'o':
                taken = true;
                return true;
            default:
                std::cout << "Please enter a valid move: ";
                return false;
        }
    }

    //returns a char for rendering the board
    char getValue() {
        switch(this->checkStatus()){
            case 0:
                return '-';
            case 1:
                return 'X';
            case 2:
                return 'O';
        }
    }

};