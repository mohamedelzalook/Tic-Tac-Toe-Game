#include <iostream>
using namespace std;

char game[3][3] = { '1', '2', '3','4', '5', '6', '7', '8', '9' };
char player = 'X';

void draw()
{
    system("cls");
    for (int row = 0; row < 3; row++)
    {
        cout << " | ";
        for (int column = 0; column < 3; column++)
        {
            cout << game[row][column] << " | ";
        }
        cout << endl;
    }
}

void takeInput()
{
    char pos;
    cout << endl << "Player (" << player << "), Enter your position: ";
    cin >> pos;
    for (int row = 0; row < 3; row++)
    {
        for (int column = 0; column < 3; column++)
        {
            if (game[row][column] == pos)
            {
                game[row][column] = player;
            }
        }
    }
    if (player == 'X')
    {
        player = 'O';
    }
    else
    {
        player = 'X';
    }
}

char checkWinner()
{
    int x = 0, o = 0, counter = 0;

    for (int i = 0; i < 3; i++)
    {
        if (game[0][i] == game[1][i] && game[1][i] == game[2][i])
        {
            return game[0][i];
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if (game[i][0] == game[i][1] && game[i][1] == game[i][2])
        {
            return game[i][0];
        }
    }
    if (game[0][0] == game[1][1] && game[1][1] == game[2][2])
    {
        return game[0][0];
    }
    if (game[0][2] == game[1][1] && game[1][1] == game[2][0])
    {
        return game[0][2];
    }
    for (int row = 0; row < 3; row++)
    {
        for (int column = 0; column < 3; column++)
        {
            if (game[row][column] != 'X' && game[row][column] != 'O')
            {
                return '*';
            }
        }
    }
    return '=';
}

int main()
{
    do
    {
        draw();
        takeInput();
        checkWinner();
    } while (checkWinner() == '*');
     
    
    if (checkWinner() == 'X')
    {
        cout << endl << "Player X won" << endl;
    }
    else if (checkWinner() == 'O')
    {
        cout << endl << "Player O won" << endl;
    }
    else
    {
        cout << endl << "Draw" << endl;
    }
    return 0;
}