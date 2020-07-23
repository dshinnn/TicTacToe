/*************************************************************************
 * AUTHOR           :  David Shin
 * Project          :  Tic Tat Toe
 ************************************************************************/
#include <vector>
#include <iostream>
/*************************************************************************
* Project - Tic Tat Toe
* _________________________________________________________________________
* Simulates a console game of tic tat toe.
* _________________________________________________________________________
* INPUT:
*   pos     :  grabs the location in which the player wants to put their
*              mark
*__________________________________________________________________________
*************************************************************************/
using namespace std;

const bool CLEAR_SCREEN = true;

/// @brief Utilizes an escape character sequence to clear the screen
void clearScreen()
{
    cout << endl;

    if (CLEAR_SCREEN)
    {
        cout << "\033c";
    }

    cout << endl;
}


/// @brief Draws the provided tic-tac-toe board to the screen
//  @param board is the tic-tac-toe board that should be drawn
void drawBoard(const vector <char> &board)
{
    clearScreen();
    for (int i = 0; i < 9; i += 3)
    {
        cout << "  " << board.at(i) << "  |  " << board.at(i + 1) << "  |  "
            << board.at(i + 2) << "  " << endl;
        if (i < 6)
            cout << "-----|-----|-----" << endl;
    }
    cout << endl;
}



/// @brief Fills vector with characters starting at lower case a to lower case i
/// @param v the vector to initialize
void initVector(vector <char> &v)
{
    int a = 97;

    for(int i = 0; i < 9; i++)
    {
        v[i] = a++;
    }

    v.resize(v.size());
}


/// @brief Converts a character representing a cell to associated vector index
/// @param the position to be converted to a vector index
/// @return the integer index in the vector, should be 0 to (vector size - 1)
int convertPosition(char position)
{
    return position -= 97;;
}

/// @brief Predicate function to determine if a spot in board is available.
/// @param board the current tic-tac-toe board
/// @param position is an index into vector to check if available
/// @return true if position's state is available (not marked) AND is in bounds
bool validPlacement(const vector <char> &board, int position)
{
    if(position <= board.size())
    {
        if(board[position] == 'x' || board[position] == 'o')
            return false;
        else
            return true;
    }
    else
        return false;

}

/// @brief Acquires a play from the user as to where to put their mark
///
///     Utilizes convertPosition and validPlacement functions to convert the
///     user input and then determine if the converted input is a valid play.
///
/// @param board the current tic-tac-toe board
/// @return an integer index in board vector of a chosen available board spot
int getPlay(const vector <char> &board)
{
    char pos;

    cout << "Please choose a position: \n";
    cin >> pos;
    if (validPlacement(board, convertPosition(pos)) == true)
        return convertPosition(pos);
    else
        return -1;
}


/// @brief Predicate function to determine if the game has been won
///
///     Winning conditions in tic-tac-toe require three marks from same
///     player in a single row, column or diagonal.
///
/// @param board the current tic-tac-toe board
/// @return true if the game has been won, false otherwise
bool gameWon(const vector <char> &board)
{
    if(board[0] == 'x' && board[1] == 'x' && board[2] == 'x' ||
            board[3] == 'x' && board[4] == 'x' && board[5] == 'x' ||
            board[6] == 'x' && board[7] == 'x' && board[8] == 'x' ||
            board[0] == 'x' && board[4] == 'x' && board[8] == 'x' ||
            board[2] == 'x' && board[4] == 'x' && board[6] == 'x' ||           
            board[0] == 'x' && board[3] == 'x' && board[6] == 'x' ||
            board[1] == 'x' && board[4] == 'x' && board[7] == 'x' ||
            board[2] == 'x' && board[5] == 'x' && board[8] == 'x' ||
            board[0] == 'o' && board[3] == 'o' && board[6] == 'o' ||
            board[1] == 'o' && board[4] == 'o' && board[7] == 'o' ||
            board[2] == 'o' && board[5] == 'o' && board[8] == 'o' ||
            board[0] == 'o' && board[1] == 'o' && board[2] == 'o' ||
            board[3] == 'o' && board[4] == 'o' && board[5] == 'o' ||
            board[6] == 'o' && board[7] == 'o' && board[8] == 'o' ||
            board[0] == 'o' && board[4] == 'o' && board[8] == 'o' ||
            board[2] == 'o' && board[4] == 'o' && board[6] == 'o')
        return true;
    else
        return false;
}


/// @brief Predicate function to determine if the board is full
/// @param board the current tic-tac-toe board
/// @return true if and only if the board is full (no cell is available)
bool boardFull(const vector <char> &board)
{
    for(int i = 0; i < board.size(); i++)
    {
        if(board[i] != 'x' && board[i] != 'o')
        {
            return false;
        }
    }
    return true;
}


// Global constants for player representation
const int PLAYER1 = 0;
const int PLAYER2 = 1;

int main()
{
    // Variables that you may find useful to utilize
    vector <char> board(9);
    int curPlay;
    int turn = PLAYER1; // Player 1 always goes first and is 'x'

    initVector(board);
    drawBoard(board);

    while(gameWon(board) == false && boardFull(board) == false)
    {
        curPlay = getPlay(board);
        if(curPlay != -1)
        {

            if(turn == PLAYER1)
            {
                board[curPlay] = 'x';
                turn = PLAYER2;
            }
            else if (turn == PLAYER2)
            {
                board[curPlay] = 'o';
                turn = PLAYER1;
            }
            //  clearScreen();
            drawBoard(board);
        }
    }
    if(gameWon(board) == false && boardFull(board) == true)
        cout << "No one wins.\n";

    else if(turn == PLAYER2)
        cout << "Player 1 wins!!\n";
    else if(turn == PLAYER1)
        cout << "Player 2 wins!!\n";

}
