#include <iostream>
#include <cctype>
#include "square.cpp"

class board {

    square values[3][3];
    int xScore = 0;
    int yScore = 0;

    int strToRow(std::string selectedSquare) {
        if (isdigit(selectedSquare[1])) {
            //minus 49 because we subtract 48 to convert from ASCII code
            //we want to subtract another 1 to convert from the labeled postion to the index
            return selectedSquare[1] - 49;
        } else {
            std::cout << "Error with row input.\n";
            return 504;
        }
    }

    int strToCol(std::string selectedSquare) {
        switch(tolower(selectedSquare[0])) {
            case 'a':
                return 0;
            case 'b':
                return 1;
            case 'c':
                return 2;
            default:
                std::cout << "Error with column input.\n";
                return 504;
        }
    }

    bool isValidSquare(std::string selectedSquare) {
        bool hasWorked;

        try {
            int row = strToRow(selectedSquare);
            int col = strToCol(selectedSquare);

            if(row == 504 || col == 504) {
                throw "Error";
            }
            
            //status of 0 means unfilled square
            if (values[row][col].checkStatus() != 0) {
                std::cout << "That square has already been taken. Status is " << values[row][col].checkStatus() << " (" << values[row][col].getValue() << ")\n";
            }
            if (selectedSquare.length() != 2) {
                std::cout << "The length of your input should be 2 characters. You inputted " << selectedSquare.length() << " characters.\n";
            }
            hasWorked = (values[row][col].checkStatus() == 0 && selectedSquare.length() == 2);
        } 
        catch (...) {
            //std::cout << "one of the functions threw an error\n";
            hasWorked = false;
        }

        return hasWorked;

    }

public:


    void renderBoard(){
        int row = 0;

        std::cout << "     A   B   C \n";

        std::cout << "  1  " << values[row][0].getValue() << " | " << values[row][1].getValue() << " | " << values[row][2].getValue() << " \n";
        std::cout << "    ———+———+———\n";
        
        row++;
        std::cout << "  2  " << values[row][0].getValue() << " | " << values[row][1].getValue() << " | " << values[row][2].getValue() << " \n";
        std::cout << "    ———+———+———\n";

        row++;
        std::cout << "  3  " << values[row][0].getValue() << " | " << values[row][1].getValue() << " | " << values[row][2].getValue() << " \n";

    }


    void promptMove(bool isX) {
        std::string selectedSquare;     

        if (isX){
            std::cout << "X's turn, select your square: ";
        } else {
            std::cout << "O's turn, select your square: ";
        }

        std::cin >> selectedSquare;

        while(!isValidSquare(selectedSquare)) {
            std::cout << "\"" << selectedSquare << "\" is an invalid square, please try again: ";
            std::cin >> selectedSquare;
        }

        int row = strToRow(selectedSquare);
        int col = strToCol(selectedSquare);

        /*std::cout << "Row: " << row << "\n";
        std::cout << "Col: " << col << "\n";*/


        values[strToRow(selectedSquare)][strToCol(selectedSquare)].setValue((isX) ? 'X' : 'O');
        //std::cout << "Set Square at position " << row << " , " << col << ") to " << values[row][col].getValue() << std::endl;
        this->renderBoard();

    }

    //0 is for ongoing
    //1 is for X victory
    //2 is for O victory
    int gameStatus() {
        //check horizontally for a win
        for(auto row : values){
            if(row[0].checkStatus() == row[1].checkStatus() && row[0].checkStatus() == row[2].checkStatus() && row[0].checkStatus() > 0) {
                return row[0].checkStatus();
            }
        }

        //check vertically
        for (int i = 0; i < 3; i++){
            if (values[0][i].checkStatus() == values[1][i].checkStatus() && values[0][i].checkStatus() == values[2][i].checkStatus() && values[0][i].checkStatus() > 0) {
                return values[i][0].checkStatus();
            }
        }

        //check diagonally:
        //top left to bottom right first
        if (values[0][0].checkStatus() == values[1][1].checkStatus() && values[0][0].checkStatus() == values[2][2].checkStatus() && values[0][0].checkStatus() > 0) {
            return values[0][0].checkStatus();
        }

        if (values[0][2].checkStatus() == values[1][1].checkStatus() && values[0][2].checkStatus() == values[2][0].checkStatus() && values[0][0].checkStatus() > 0) {
            return values[0][2].checkStatus();
        }

        //if none of the victory checks are successful then return ongoing status code;
        return 0;

    }
};