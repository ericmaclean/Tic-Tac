#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3
const char PLAYER = 'X';
const char COMPUTER = 'O';

void resetBoard(char board[ROWS][COLS]);
int checkFreeSpaces(char board[ROWS][COLS]);
void printBoard(char board[ROWS][COLS]);
int checkWinner(char board[ROWS][COLS]);
void computerMove(char board[ROWS][COLS]);
void playerMove(char board[ROWS][COLS]);
int Block(char board[ROWS][COLS]);
int Attack(char board[ROWS][COLS]);
int Fork(char board[ROWS][COLS]);
int isCenterFree(char board[ROWS][COLS]);
int cornerPlay(char board[ROWS][COLS]);

int main()
{
    printf("\n\n");
    printf("****************************************************\n");
    printf("                        HOWDY!                      \n");
    printf("****************************************************\n");
    printf("\n* Instructions \n\n");
    printf("\tPlayer symbol = X\n");
    printf("\tComputer symbol = O\n\n");
    srand(time(NULL));
    char board[ROWS][COLS] = {0};
    int turn = rand() % 2;
    resetBoard(board);

    while (1)
    {
        if (checkFreeSpaces(board))
        {
            if (turn)
            {
                playerMove(board);
            }
            else
            {
                computerMove(board);
            }
            turn ^= 1;
            printBoard(board);
            if (checkWinner(board))
            {
                break;
            }
        }
        else
        {
            if (checkWinner(board))
            {
                break;
            }
            else
            {
                printf("\033[33mTIE GAME\033[0m\n");
                break;
            }
        }
    }
    printf("\n\n");
    printf("****************************************************\n");
    printf("                      GAME OVER                     \n");
    printf("****************************************************\n");
    printf("\n\n");
}
void resetBoard(char board[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            board[i][j] = ' ';
        }
    }
}
int checkFreeSpaces(char board[ROWS][COLS])
{
    int FreeSpace = 0;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (board[i][j] == ' ')
            {
                FreeSpace++;
            }
        }
    }
    return FreeSpace;
}
void printBoard(char board[ROWS][COLS])
{
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n\n", board[2][0], board[2][1], board[2][2]);
}
int checkWinner(char board[ROWS][COLS])
{
    int winnaFlag1 = 1;
    int winnaFlag2 = 1;
    char firstInstance;
    // check for row 0 horizontal and col 0 vertical
    for (int i = 0; i < COLS; i++)
    {
        firstInstance = board[0][0];
        if (firstInstance == ' ')
        {
            winnaFlag1 = 0;
            winnaFlag2 = 0;
        }
        if (board[0][i] != firstInstance)
        {
            winnaFlag1 = 0;
        }
        if (board[i][0] != firstInstance)
        {
            winnaFlag2 = 0;
        }
    }
    if (winnaFlag1 == 1 || winnaFlag2 == 1)
    {
        if (firstInstance == PLAYER)
        {
            printf("\033[32mCONGRATS YOU WON!\033[0m\n");
            resetBoard(board);
            return 1;
        }
        else if (firstInstance == COMPUTER)
        {
            printf("\033[31mYOU LOST LOSER!\033[0m\n");
            resetBoard(board);
            return 1;
        }
    }
    winnaFlag1 = 1;
    winnaFlag2 = 1;
    // check for row 2 horizontal and col 2 veritcal
    for (int i = 0; i < COLS; i++)
    {
        firstInstance = board[2][2];
        if (firstInstance == ' ')
        {
            winnaFlag1 = 0;
            winnaFlag2 = 0;
        }
        if (board[2][i] != firstInstance)
        {
            winnaFlag1 = 0;
        }
        if (board[i][2] != firstInstance)
        {
            winnaFlag2 = 0;
        }
    }
    if (winnaFlag1 == 1 || winnaFlag2 == 1)
    {
        if (firstInstance == PLAYER)
        {
            printf("\033[32mCONGRATS YOU WON!\033[0m\n");
            resetBoard(board);
            return 1;
        }
        else if (firstInstance == COMPUTER)
        {
            printf("\033[31mYOU LOST LOSER!\033[0m\n");
            resetBoard(board);
            return 1;
        }
    }
    winnaFlag1 = 1;
    winnaFlag2 = 1;
    // check the diagonals
    int j = 2;
    for (int i = 0; i < COLS; i++)
    {

        firstInstance = board[1][1];
        if (firstInstance == ' ')
        {
            winnaFlag1 = 0;
            winnaFlag2 = 0;
        }
        if (board[i][i] != firstInstance)
        {
            winnaFlag1 = 0;
        }
        if (board[i][j] != firstInstance)
        {
            winnaFlag2 = 0;
        }
        j--;
    }
    if (winnaFlag1 == 1 || winnaFlag2 == 1)
    {
        if (firstInstance == PLAYER)
        {
            printf("\033[32mCONGRATS YOU WON!\033[0m\n");
            resetBoard(board);
            return 1;
        }
        else if (firstInstance == COMPUTER)
        {
            printf("\033[31mYOU LOST LOSER!\033[0m\n");
            resetBoard(board);
            return 1;
        }
    }
    winnaFlag1 = 1;
    winnaFlag2 = 1;
    // check for row 1 horizontal and col 1 vertical
    for (int i = 0; i < COLS; i++)
    {
        firstInstance = board[1][1];
        if (firstInstance == ' ')
        {
            winnaFlag1 = 0;
            winnaFlag2 = 0;
        }
        if (board[1][i] != firstInstance)
        {
            winnaFlag1 = 0;
        }
        if (board[i][1] != firstInstance)
        {
            winnaFlag2 = 0;
        }
    }
    if (winnaFlag1 == 1 || winnaFlag2 == 1)
    {
        if (firstInstance == PLAYER)
        {
            printf("\033[32mCONGRATS YOU WON!\033[0m\n");
            resetBoard(board);
            return 1;
        }
        else if (firstInstance == COMPUTER)
        {
            printf("\033[31mYOU LOST LOSER!\033[0m\n");
            resetBoard(board);
            return 1;
        }
    }
    else
    {
        return 0;
    }
}
void computerMove(char board[ROWS][COLS])
{
    srand(time(NULL));
    int rowRand;
    int colRand;
    if (!Attack(board))
    {
        if (!Block(board))
        {
            if (!Fork(board))
            {
                if (!isCenterFree(board))
                {
                    if (!cornerPlay(board))
                    {
                        while (1)
                        {
                            rowRand = rand() % 3;
                            colRand = rand() % 3;

                            if (board[rowRand][colRand] == ' ')
                            {
                                board[rowRand][colRand] = COMPUTER;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
}
int Block(char board[ROWS][COLS])
{
    // check row blocks
    for (int i = 0; i < ROWS; i++)
    {
        if (board[i][0] == PLAYER && board[i][1] == PLAYER && board[i][2] == ' ')
        {
            board[i][2] = COMPUTER;
            printf("\n\033[45mGET BLOCKED MF!\033[0m\n\n");
            return 1;
        }
        else if (board[i][1] == PLAYER && board[i][2] == PLAYER && board[i][0] == ' ')
        {
            board[i][0] = COMPUTER;
            printf("\n\033[45mGET BLOCKED MF!\033[0m\n\n");
            return 1;
        }
        else if (board[i][0] == PLAYER && board[i][2] == PLAYER && board[i][1] == ' ')
        {
            board[i][1] = COMPUTER;
            printf("\n\033[45mGET BLOCKED MF!\033[0m\n\n");
            return 1;
        }
    }
    // check col blocks
    for (int i = 0; i < COLS; i++)
    {
        if (board[0][i] == PLAYER && board[1][i] == PLAYER && board[2][i] == ' ')
        {
            board[2][i] = COMPUTER;
            printf("\n\033[45mGET BLOCKED MF!\033[0m\n\n");
            return 1;
        }
        else if (board[1][i] == PLAYER && board[2][i] == PLAYER && board[0][i] == ' ')
        {
            board[0][i] = COMPUTER;
            printf("\n\033[45mGET BLOCKED MF!\033[0m\n\n");
            return 1;
        }
        else if (board[0][i] == PLAYER && board[2][i] == PLAYER && board[1][i] == ' ')
        {
            board[1][i] = COMPUTER;
            printf("\n\033[45mGET BLOCKED MF!\033[0m\n\n");
            return 1;
        }
    }
    // check diagonal blocks
    for (int i = 0; i < COLS; i++)
    {
        if (board[0][0] == PLAYER && board[1][1] == PLAYER && board[2][2] == ' ')
        {
            board[2][2] = COMPUTER;
            printf("\n\033[45mGET BLOCKED MF!\033[0m\n\n");
            return 1;
        }
        else if (board[1][1] == PLAYER && board[2][2] == PLAYER && board[0][0] == ' ')
        {
            board[0][0] = COMPUTER;
            printf("\n\033[45mGET BLOCKED MF!\033[0m\n\n");
            return 1;
        }
        else if (board[0][0] == PLAYER && board[2][2] == PLAYER && board[1][1] == ' ')
        {
            board[1][1] = COMPUTER;
            printf("\n\033[45mGET BLOCKED MF!\033[0m\n\n");
            return 1;
        }
    }

    if (board[2][0] == PLAYER && board[1][1] == PLAYER && board[0][2] == ' ')
    {
        board[0][2] = COMPUTER;
        printf("\n\033[45mGET BLOCKED MF!\033[0m\n\n");
        return 1;
    }
    else if (board[1][1] == PLAYER && board[0][2] == PLAYER && board[2][0] == ' ')
    {
        board[2][0] = COMPUTER;
        printf("\n\033[45mGET BLOCKED MF!\033[0m\n\n");
        return 1;
    }
    else if (board[2][0] == PLAYER && board[0][2] == PLAYER && board[1][1] == ' ')
    {
        board[1][1] = COMPUTER;
        printf("\n\033[45mGET BLOCKED MF!\033[0m\n\n");
        return 1;
    }
    return 0;
}
int Attack(char board[ROWS][COLS])
{
    // check row blocks
    for (int i = 0; i < ROWS; i++)
    {
        if (board[i][0] == COMPUTER && board[i][1] == COMPUTER && board[i][2] == ' ')
        {
            board[i][2] = COMPUTER;
            printf("\n\033[46mATTACK!\033[0m\n\n");
            return 1;
        }
        else if (board[i][1] == COMPUTER && board[i][2] == COMPUTER && board[i][0] == ' ')
        {
            board[i][0] = COMPUTER;
            printf("\n\033[46mATTACK!\033[0m\n\n");
            return 1;
        }
        else if (board[i][0] == COMPUTER && board[i][2] == COMPUTER && board[i][1] == ' ')
        {
            board[i][1] = COMPUTER;
            printf("\n\033[46mATTACK!\033[0m\n\n");
            return 1;
        }
    }
    // check col blocks
    for (int i = 0; i < COLS; i++)
    {
        if (board[0][i] == COMPUTER && board[1][i] == COMPUTER && board[2][i] == ' ')
        {
            board[2][i] = COMPUTER;
            printf("\n\033[46mATTACK!\033[0m\n\n");
            return 1;
        }
        else if (board[1][i] == COMPUTER && board[2][i] == COMPUTER && board[0][i] == ' ')
        {
            board[0][i] = COMPUTER;
            printf("\n\033[46mATTACK!\033[0m\n\n");
            return 1;
        }
        else if (board[0][i] == COMPUTER && board[2][i] == COMPUTER && board[1][i] == ' ')
        {
            board[1][i] = COMPUTER;
            printf("\n\033[46mATTACK!\033[0m\n\n");
            return 1;
        }
    }
    // check diagonal blocks
    for (int i = 0; i < COLS; i++)
    {
        if (board[0][0] == COMPUTER && board[1][1] == COMPUTER && board[2][2] == ' ')
        {
            board[2][2] = COMPUTER;
            printf("\n\033[46mATTACK!\033[0m\n\n");
            return 1;
        }
        else if (board[1][1] == COMPUTER && board[2][2] == COMPUTER && board[0][0] == ' ')
        {
            board[0][0] = COMPUTER;
            printf("\n\033[46mATTACK!\033[0m\n\n");
            return 1;
        }
        else if (board[0][0] == COMPUTER && board[2][2] == COMPUTER && board[1][1] == ' ')
        {
            board[1][1] = COMPUTER;
            printf("\n\033[46mATTACK!\033[0m\n\n");
            return 1;
        }
    }
    if (board[2][0] == COMPUTER && board[1][1] == COMPUTER && board[0][2] == ' ')
    {
        board[0][2] = COMPUTER;
        printf("\n\033[46mATTACK!\033[0m\n\n");
        return 1;
    }
    else if (board[1][1] == COMPUTER && board[0][2] == COMPUTER && board[2][0] == ' ')
    {
        board[2][0] = COMPUTER;
        printf("\n\033[46mATTACK!\033[0m\n\n");
        return 1;
    }
    else if (board[2][0] == COMPUTER && board[0][2] == COMPUTER && board[1][1] == ' ')
    {
        board[1][1] = COMPUTER;
        printf("\n\033[46mATTACK!\033[0m\n\n");
        return 1;
    }

    return 0;
}
int Fork(char board[ROWS][COLS])
{
    for (int x = 0; x < ROWS; x++)
    {
        for (int z = 0; z < COLS; z++)
        {
            if (board[x][z] == ' ')
            {
                board[x][z] = COMPUTER;
                int forkscore = 0;
                // check row blocks
                for (int i = 0; i < ROWS; i++)
                {
                    if (board[i][0] == COMPUTER && board[i][1] == COMPUTER && board[i][2] == ' ')
                    {
                        forkscore++;
                    }
                    else if (board[i][1] == COMPUTER && board[i][2] == COMPUTER && board[i][0] == ' ')
                    {
                        forkscore++;
                    }
                    else if (board[i][0] == COMPUTER && board[i][2] == COMPUTER && board[i][1] == ' ')
                    {
                        forkscore++;
                    }
                }
                // check col blocks
                for (int i = 0; i < COLS; i++)
                {
                    if (board[0][i] == COMPUTER && board[1][i] == COMPUTER && board[2][i] == ' ')
                    {
                        forkscore++;
                    }
                    else if (board[1][i] == COMPUTER && board[2][i] == COMPUTER && board[0][i] == ' ')
                    {
                        forkscore++;
                    }
                    else if (board[0][i] == COMPUTER && board[2][i] == COMPUTER && board[1][i] == ' ')
                    {
                        forkscore++;
                        ;
                    }
                }
                // check diagonal blocks
                if (board[0][0] == COMPUTER && board[1][1] == COMPUTER && board[2][2] == ' ')
                {
                    forkscore++;
                }
                else if (board[1][1] == COMPUTER && board[2][2] == COMPUTER && board[0][0] == ' ')
                {
                    forkscore++;
                }
                else if (board[0][0] == COMPUTER && board[2][2] == COMPUTER && board[1][1] == ' ')
                {
                    forkscore++;
                }
                if (board[2][0] == COMPUTER && board[1][1] == COMPUTER && board[0][2] == ' ')
                {
                    forkscore++;
                }
                else if (board[1][1] == COMPUTER && board[0][2] == COMPUTER && board[2][0] == ' ')
                {
                    forkscore++;
                }
                else if (board[2][0] == COMPUTER && board[0][2] == COMPUTER && board[1][1] == ' ')
                {
                    forkscore++;
                }
                if (forkscore > 1)
                {
                    printf("\n\033[43mGET FORKED!\033[0m\n\n");
                    return 1;
                }
                board[x][z] = ' ';
            }
        }
    }
    return 0;
}
void playerMove(char board[ROWS][COLS])
{
    int row;
    int col;
    while (1)
    {
        printf("Enter row (1-3): ");
        scanf("%d", &row);
        printf("Enter col (1-3): ");
        scanf("%d", &col);
        printf("\n");
        row--;
        col--;
        if (row > 2 || row < 0 || col > 2 || col < 0)
        {
            printf("\033[31mOutside of bounds of the game, try again: \033[0m\n");
        }
        else
        {
            if (board[row][col] == PLAYER || board[row][col] == COMPUTER)
            {
                printf("\033[31mThis Space already taken, pick an availible space: \033[0m\n");
            }
            else
            {
                board[row][col] = PLAYER;
                break;
            }
        }
    }
}
int isCenterFree(char board[ROWS][COLS])
{
    if (board[1][1] == ' ')
    {
        board[1][1] = COMPUTER;
        printf("\n\033[43mCENTER PLAY\033[0m\n\n");
        return 1;
    }
    else
    {
        return 0;
    }
}
int cornerPlay(char board[ROWS][COLS])
{
    // check opposite corners
    if (board[0][0] == PLAYER && board[2][2] == ' ')
    {
        board[2][2] = COMPUTER;
        printf("\n\033[43mCORNER PLAY\033[0m\n\n");
        return 1;
    }
    if (board[2][2] == PLAYER && board[0][0] == ' ')
    {
        board[0][0] = COMPUTER;
        printf("\n\033[43mCORNER PLAY\033[0m\n\n");
        return 1;
    }
    if (board[0][2] == PLAYER && board[2][0] == ' ')
    {
        board[2][0] = COMPUTER;
        printf("\n\033[43mCORNER PLAY\033[0m\n\n");
        return 1;
    }
    if (board[2][0] == PLAYER && board[0][2] == ' ')
    {
        board[0][2] = COMPUTER;
        printf("\n\033[43mCORNER PLAY\033[0m\n\n");
        return 1;
    }
    //place move in one of the corners dosnt really mnatter which one
    if (board[0][0] == ' ')
    {
        board[0][0] = COMPUTER;
        printf("\n\033[43mCORNER PLAY\033[0m\n\n");
        return 1;
    }
    else if(board[0][2] == ' ')
    {
        board[0][2] = COMPUTER;
        printf("\n\033[43mCORNER PLAY\033[0m\n\n");
        return 1;
    }
    else if(board[2][0] == ' ')
    {
        board[2][0] = COMPUTER;
        printf("\n\033[43mCORNER PLAY\033[0m\n\n");
        return 1;
    }
    else if(board[2][2] == ' ')
    {
        board[2][2] = COMPUTER;
        printf("\n\033[43mCORNER PLAY\033[0m\n\n");
        return 1;
    }
    return 0;
}
