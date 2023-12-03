#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

int global_a = 0;     // user input
int randomnumbers[3]; // to compare the user input with displayed shapes
int score = 0;

// void move(board);
void box1()
{
    printf("* *  \n");
    printf("*\n");
    printf("* *  \n\n");
}

void box2()
{
    printf("     \n");
    printf("*   *\n");
    printf("* * *\n\n");
}

void box3()
{
    printf("*    \n");
    printf("*    \n");
    printf("* * * \n\n");
}

void box4()
{
    printf("     \n");
    printf("    *\n");
    printf("  * *\n\n");
}

void box5()
{
    printf("  * *\n");
    printf("    *\n");
    printf("     \n\n");
}

void box6()
{
    printf("    * \n");
    printf("    * \n");
    printf("    * \n\n");
}

void box7()
{
    printf("    * \n");
    printf("    * \n");
    printf("    * \n");
    printf("    * \n\n");
}

void box8()
{
    printf("     \n");
    printf("   * \n");
    printf("     \n\n");
}

void box9()
{
    printf("        \n");
    printf("* * * * \n");
    printf("        \n\n");
}

void box10()
{
    printf("      \n");
    printf("* * * \n");
    printf("      \n\n");
}

int rnum()
{
    int number;
    number = rand() % 11;
    return number;
}
int randshp()
{
    switch (rnum())
    {
    case 1:
        printf("1\n");
        box1();
        break;
    case 2:
        printf("2\n");
        box2();
        break;
    case 3:
        printf("3\n");
        box3();
        break;
    case 4:
        printf("4\n");
        box4();
        break;
    case 5:
        printf("5\n");
        box5();
        break;
    case 6:
        printf("6\n");
        box6();
        break;
    case 7:
        printf("7\n");
        box7();
        break;
    case 8:
        printf("8\n");
        box8();
        break;
    case 9:
        printf("9\n");
        box9();
        break;
    case 10:
        printf("10\n");
        box10();
        break;

    default:
        break;
    }
}
void rshape()
{
    randshp();
}

int selectedbox()
{
    int a;
    printf("\nSCORE: %d\n", score);
    printf("Enter the no of the box you want to select: ");
    scanf("%d", &a);
    global_a = a;

    system("cls");

    switch (global_a)
    {
    case 1:
        printf("You selected %d box\n", global_a);
        box1();
        break;
    case 2:
        printf("You selected %d box\n", global_a);
        box2();
        break;
    case 3:
        printf("You selected %d box\n", global_a);
        box3();
        break;
    case 4:
        printf("You selected %d box\n", global_a);
        box4();
        break;
    case 5:
        printf("You selected %d box\n", global_a);
        box5();
        break;
    case 6:
        printf("You selected %d box\n", global_a);
        box6();
        break;
    case 7:
        printf("You selected %d box\n", global_a);
        box7();
        break;
    case 8:
        printf("You selected %d box\n", global_a);
        box8();
        break;
    case 9:
        printf("You selected %d box\n", global_a);
        box9();
        break;
    case 10:
        printf("You selected %d box\n", global_a);
        box10();
        break;
    default:
        printf("Invalid selection\n");
        break;
    }
}
void printBoard(char board[9][9])
{
    system("cls");
    printf("                                  \33[0;32m"); // Start green color with added padding for top border
    for (int i = 0; i < 9; i++)
        printf("-----|");
    printf("\33[0m\n"); // End green color

    for (int i = 0; i < 9; i++)
    {
        printf("                                 \33[0;32m|\33[0m"); // Green left border with added padding
        for (int j = 0; j < 9; j++)
        {
            if (j == 2 || j == 5)
                printf("  %c  \33[96m|\33[0m", board[i][j]); // Blue vertical line for 3x3 grid
            else if (j == 8)
                printf("  %c  \33[0;32m|\33[0m", board[i][j]); // Green vertical line for right border
            else
                printf("  %c  |", board[i][j]);
        }
        printf("\n                                 \33[0;32m|\33[0m"); // Green left border with added padding
        for (int k = 0; k < 9; k++)
        {
            if (i == 2 || i == 5)
                printf("\33[96m-----|\33[0m"); // Blue horizontal line for 3x3 grid
            else if (k == 2 || k == 5)
                printf("-----\33[96m|\33[0m"); // Blue vertical line at end of 3x3 grid
            else if (k == 8)
                printf("-----\33[0;32m|\33[0m"); // Green vertical line for right border
            else
                printf("-----|");
        }
        printf("\n");
    }
    printf("                                  \33[0;32m"); // Start green color with added padding for bottom border
    for (int i = 0; i < 9; i++)
        printf("-----|");
    printf("\33[0m\n"); // End green color
}
int checkgameover(char board[9][9])
{
    if (board[0][0] == '*' || board[0][1] == '*' || board[0][2] == '*' || board[1][0] == '*' || board[2][0] == '*')
    {
        return 1;
    }
    return 0;
}

int rowcheck(char board[9][9])
{
    int stars;
    for (int i = 0; i < 9; i++)
    {
        stars = 0;
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == '*')
            {
                stars++;
            }
            if (stars == 9)
            {
                return i;
            }
        }
    }
    return 0;
}
int colcheck(char board[9][9])
{
    int stars;
    for (int i = 0; i < 9; i++)
    {
        stars = 0;
        for (int j = 0; j < 9; j++)
        {
            if (board[j][i] == '*')
            {
                stars++;
            }
            if (stars == 9)
            {
                return i;
            }
        }
    }
    return 0;
}

int boxindexes[2]; // global array to store the base index of the boxcheck function
int boxcheck(char board[9][9])
{
    for (int i = 0; i <= 6; i += 3)
    {
        for (int j = 0; j <= 6; j += 3)
        {
            int stars = 0;
            for (int k = i; k < i + 3; k++)
            {
                for (int l = j; l < j + 3; l++)
                {
                    if (board[k][l] == '*')
                    {
                        stars++;
                    }
                }
            }
            if (stars == 9)
            {
                boxindexes[0] = i;
                boxindexes[1] = j;
                return 1;
            }
        }
    }
    return 0;
}

void initializebox1(char board[9][9])
{
    int x = 0, y = 0;
    if (global_a == 1)
    {
        int row_index_full_of_stars = rowcheck(board);

        if (row_index_full_of_stars != 0)
        {
            for (int j = 0; j < 9; j++)
            {
                board[row_index_full_of_stars][j] = ' ';
            }
            score += 18;
        }
        int col_index_full_of_stars = colcheck(board);
        if (col_index_full_of_stars != 0)
        {

            for (int i = 0; i < 9; i++)
            {
                board[i][col_index_full_of_stars] = ' ';
            }
            score += 18;
        }

        if (boxcheck(board) != 0)
        {
            for (int i = boxindexes[0]; i < boxindexes[0] + 3; i++)
            {
                for (int j = boxindexes[1]; j < boxindexes[1] + 3; j++)
                {
                    board[i][j] = ' ';
                }
            }
        }

        if (rowcheck(board) == 0 || colcheck(board) == 0)
        {
            score += 4;
        }
        if (checkgameover(board))
        {
            system("cls");
            printf("Game over!");
            printf("Your score : (%d)", score);
            exit(0);
        }
        // Check if the initial position is free
        if (board[y][x] == ' ' && board[y][x + 1] == ' ' && board[y + 1][x] == ' ' && board[y + 2][x] == ' ' && board[y + 2][x + 1] == ' ')
        {
            board[y][x] = '*';
            board[y][x + 1] = '*';
            board[y + 1][x] = '*';
            board[y + 2][x] = '*';
            board[y + 2][x + 1] = '*';
        }
        int space = 0;
        printBoard(board); // Call printBoard initially
        while (space == 0)
        {
            if (_kbhit())
            {
                // Clear the pattern from its current position
                board[y][x] = ' ';
                board[y][x + 1] = ' ';
                board[y + 1][x] = ' ';
                board[y + 2][x] = ' ';
                board[y + 2][x + 1] = ' ';
                space = 0;

                int tempX = x;
                int tempY = y;
                // Get the key pressed
                switch (_getch())
                {
                case 72: // Up Arrow Key
                    if (tempY > 0)
                        tempY--;
                    break;
                case 80: // Down Arrow Key
                    if (tempY < 6)
                        tempY++;
                    break;
                case 75: // Left Arrow Key
                    if (tempX > 0)
                        tempX--;
                    break;
                case 77: // Right Arrow Key
                    if (tempX < 7)
                        tempX++;
                    break;
                case 32:
                    space++;
                    break;
                default:
                    break;
                }

                // Check if the new position is free
                if (board[tempY][tempX] == ' ' && board[tempY][tempX + 1] == ' ' && board[tempY + 1][tempX] == ' ' && board[tempY + 2][tempX] == ' ' && board[tempY + 2][tempX + 1] == ' ')
                {
                    // If the new position is free, move the pattern
                    x = tempX;
                    y = tempY;
                    board[y][x] = '*';
                    board[y][x + 1] = '*';
                    board[y + 1][x] = '*';
                    board[y + 2][x] = '*';
                    board[y + 2][x + 1] = '*';
                    printBoard(board); // Call printBoard after a move is made
                }
                else
                {
                    // If the new position is not free, put the pattern back to its original position
                    board[y][x] = '*';
                    board[y][x + 1] = '*';
                    board[y + 1][x] = '*';
                    board[y + 2][x] = '*';
                    board[y + 2][x + 1] = '*';
                }
            }
        }
    }
}
void initializebox2(char board[9][9])
{
    int x = 0, y = 0;
    if (global_a == 2)
    {
        int row_index_full_of_stars = rowcheck(board);
        if (row_index_full_of_stars != 0)
        {
            for (int j = 0; j < 9; j++)
            {
                board[row_index_full_of_stars][j] = ' ';
            }
            score += 18;
        }
        int col_index_full_of_stars = colcheck(board);
        if (col_index_full_of_stars != 0)
        {
            for (int i = 0; i < 9; i++)
            {
                board[i][col_index_full_of_stars] = ' ';
            }
            score += 18;
        }
        if (boxcheck(board) != 0)
        {
            for (int i = boxindexes[0]; i < boxindexes[0] + 3; i++)
            {
                for (int j = boxindexes[1]; j < boxindexes[1] + 3; j++)
                {
                    board[i][j] = ' ';
                }
            }
        }
        if (rowcheck(board) == 0 || colcheck(board) == 0)
        {
            score += 4;
        }
        if (checkgameover(board))
        {
            system("cls");
            printf("Game over!");
            printf("Your score : (%d)", score);

        } // Check if the initial position is free
        if (board[y][x] == ' ' && board[y][x + 1] == ' ' && board[y + 1][x] == ' ' && board[y + 1][x + 1] == ' ' && board[y + 1][x + 2] == ' ')
        {
            // Initialize the pattern
            board[y][x] = '*';
            board[y][x + 1] = ' ';
            board[y][x + 2] = '*';
            board[y + 1][x] = '*';
            board[y + 1][x + 1] = '*';
            board[y + 1][x + 2] = '*';
        }
        int space = 0;
        printBoard(board); // Call printBoard initially
        while (space == 0)
        {
            if (_kbhit())
            {
                // Clear the pattern from its current position
                board[y][x] = ' ';
                board[y][x + 1] = ' ';
                board[y][x + 2] = ' ';
                board[y + 1][x] = ' ';
                board[y + 1][x + 1] = ' ';
                board[y + 1][x + 2] = ' ';
                space = 0;

                int tempX = x;
                int tempY = y;
                // Get the key pressed
                switch (_getch())
                {
                case 72: // Up Arrow Key
                    if (tempY > 0)
                        tempY--;
                    break;
                case 80: // Down Arrow Key
                    if (tempY < 7)
                        tempY++;
                    break;
                case 75: // Left Arrow Key
                    if (tempX > 0)
                        tempX--;
                    break;
                case 77: // Right Arrow Key
                    if (tempX < 6)
                        tempX++;
                    break;
                case 32:
                    space++;
                    break;
                default:
                    break;
                }

                // Check if the new position is free
                if (board[tempY][tempX] == ' ' && board[tempY][tempX + 1] == ' ' && board[tempY][tempX + 2] == ' ' && board[tempY + 1][tempX] == ' ' && board[tempY + 1][tempX + 1] == ' ' && board[tempY + 1][tempX + 2] == ' ')
                {
                    // If the new position is free, move the pattern
                    x = tempX;
                    y = tempY;
                    board[y][x] = '*';
                    board[y][x + 1] = ' ';
                    board[y][x + 2] = '*';
                    board[y + 1][x] = '*';
                    board[y + 1][x + 1] = '*';
                    board[y + 1][x + 2] = '*';
                    printBoard(board); // Call printBoard after a move is made
                }
                else
                {
                    // If the new position is not free, put the pattern back to its original position
                    board[y][x] = '*';
                    board[y][x + 1] = ' ';
                    board[y][x + 2] = '*';
                    board[y + 1][x] = '*';
                    board[y + 1][x + 1] = '*';
                    board[y + 1][x + 2] = '*';
                }
            }
        }
    }
}
void initializebox3(char board[9][9])
{
    int x = 0, y = 0;
    if (global_a == 3)
    {
        int row_index_full_of_stars = rowcheck(board);
        if (row_index_full_of_stars != 0)
        {
            for (int j = 0; j < 9; j++)
            {
                board[row_index_full_of_stars][j] = ' ';
            }
            score += 18;
        }
        int col_index_full_of_stars = colcheck(board);
        if (col_index_full_of_stars != 0)
        {
            for (int i = 0; i < 9; i++)
            {
                board[i][col_index_full_of_stars] = ' ';
            }
            score += 18;
        }
        if (boxcheck(board) != 0)
        {
            for (int i = boxindexes[0]; i < boxindexes[0] + 3; i++)
            {
                for (int j = boxindexes[1]; j < boxindexes[1] + 3; j++)
                {
                    board[i][j] = ' ';
                }
            }
        }
        if (rowcheck(board) == 0 || colcheck(board) == 0)
        {
            score += 4;
        }
        if (checkgameover(board))
        {
            system("cls");
            printf("Game over!");
            printf("Your score : (%d)", score);
        }
        if (board[y][x] == ' ' && board[y + 1][x] == ' ' && board[y + 2][x] == ' ' && board[y + 2][x + 1] == ' ' && board[y + 2][x + 2] == ' ')
        {
            board[y][x] = '*';
            board[y + 1][x] = '*';
            board[y + 2][x] = '*';
            board[y + 2][x + 1] = '*';
            board[y + 2][x + 2] = '*';
        }
        int space = 0;
        printBoard(board);
        while (space == 0)
        {
            if (_kbhit())
            {
                board[y][x] = ' ';
                board[y + 1][x] = ' ';
                board[y + 2][x] = ' ';
                board[y + 2][x + 1] = ' ';
                board[y + 2][x + 2] = ' ';
                space = 0;

                int tempX = x;
                int tempY = y;
                switch (_getch())
                {
                case 72: // Up Arrow Key
                    if (tempY > 0)
                        tempY--;
                    break;
                case 80: // Down Arrow Key
                    if (tempY < 6)
                        tempY++;
                    break;
                case 75: // Left Arrow Key
                    if (tempX > 0)
                        tempX--;
                    break;
                case 77: // Right Arrow Key
                    if (tempX < 6)
                        tempX++;
                    break;
                case 32:
                    space++;
                    break;
                default:
                    break;
                }
                if (board[tempY][tempX] == ' ' && board[tempY + 1][tempX] == ' ' && board[tempY + 2][tempX] == ' ' && board[tempY + 2][tempX + 1] == ' ' && board[tempY + 2][tempX + 2] == ' ')
                {
                    x = tempX;
                    y = tempY;
                    board[y][x] = '*';
                    board[y + 1][x] = '*';
                    board[y + 2][x] = '*';
                    board[y + 2][x + 1] = '*';
                    board[y + 2][x + 2] = '*';
                    printBoard(board);
                }
                else
                {
                    board[y][x] = '*';
                    board[y + 1][x] = '*';
                    board[y + 2][x] = '*';
                    board[y + 2][x + 1] = '*';
                    board[y + 2][x + 2] = '*';
                }
            }
        }
    }
}
void initializebox4(char board[9][9])
{
    int x = 0, y = 0;
    if (global_a == 4)
    {
        int row_index_full_of_stars = rowcheck(board);
        if (row_index_full_of_stars != 0)
        {
            for (int j = 0; j < 9; j++)
            {
                board[row_index_full_of_stars][j] = ' ';
            }
            score += 18;
        }
        int col_index_full_of_stars = colcheck(board);
        if (col_index_full_of_stars != 0)
        {
            for (int i = 0; i < 9; i++)
            {
                board[i][col_index_full_of_stars] = ' ';
            }
            score += 18;
        }
        if (boxcheck(board) != 0)
        {
            for (int i = boxindexes[0]; i < boxindexes[0] + 3; i++)
            {
                for (int j = boxindexes[1]; j < boxindexes[1] + 3; j++)
                {
                    board[i][j] = ' ';
                }
            }
        }
        if (rowcheck(board) == 0 || colcheck(board) == 0)
        {
            score += 4;
        }
        if (checkgameover(board))
        {
            system("cls");
            printf("Game over!");
            printf("Your score : (%d)", score);
        }
        if (board[y][x + 1] == ' ' && board[y + 1][x] == ' ' && board[y + 1][x + 1] == ' ')
        {
            board[y][x + 1] = '*';
            board[y + 1][x] = '*';
            board[y + 1][x + 1] = '*';
        }

        int space = 0;
        printBoard(board);
        while (space == 0)
        {
            if (_kbhit())
            {
                board[y][x + 1] = ' ';
                board[y + 1][x] = ' ';
                board[y + 1][x + 1] = ' ';
                space = 0;

                int tempX = x;
                int tempY = y;
                switch (_getch())
                {
                case 72: // Up Arrow Key
                    if (tempY > 0)
                        tempY--;
                    break;
                case 80: // Down Arrow Key
                    if (tempY < 7)
                        tempY++;
                    break;
                case 75: // Left Arrow Key
                    if (tempX > 0)
                        tempX--;
                    break;
                case 77: // Right Arrow Key
                    if (tempX < 7)
                        tempX++;
                    break;
                case 32:
                    space++;
                    break;
                default:
                    break;
                }
                if (board[tempY][tempX + 1] == ' ' && board[tempY + 1][tempX] == ' ' && board[tempY + 1][tempX + 1] == ' ')
                {
                    x = tempX;
                    y = tempY;
                    board[y][x + 1] = '*';
                    board[y + 1][x] = '*';
                    board[y + 1][x + 1] = '*';
                    printBoard(board);
                }
                else
                {
                    board[y][x + 1] = '*';
                    board[y + 1][x] = '*';
                    board[y + 1][x + 1] = '*';
                }
            }
        }
    }
}
void initializebox5(char board[9][9])
{
    int x = 0, y = 0;
    if (global_a == 5)
    {
        int row_index_full_of_stars = rowcheck(board);
        if (row_index_full_of_stars != 0)
        {
            for (int j = 0; j < 9; j++)
            {
                board[row_index_full_of_stars][j] = ' ';
            }
            score += 18;
        }
        int col_index_full_of_stars = colcheck(board);
        if (col_index_full_of_stars != 0)
        {
            for (int i = 0; i < 9; i++)
            {
                board[i][col_index_full_of_stars] = ' ';
            }
            score += 18;
        }
        if (boxcheck(board) != 0)
        {
            for (int i = boxindexes[0]; i < boxindexes[0] + 3; i++)
            {
                for (int j = boxindexes[1]; j < boxindexes[1] + 3; j++)
                {
                    board[i][j] = ' ';
                }
            }
        }
        if (rowcheck(board) == 0 || colcheck(board) == 0)
        {
            score += 4;
        }
        if (checkgameover(board))
        {
            system("cls");
            printf("Game over!");
            printf("Your score : (%d)", score);
        }
        if (board[y][x] == ' ' && board[y][x + 1] == ' ' && board[y + 1][x + 1] == ' ')
        {
            board[y][x] = '*';
            board[y][x + 1] = '*';
            board[y + 1][x + 1] = '*';
        }
        int space = 0;
        printBoard(board);
        while (space == 0)
        {
            if (_kbhit())
            {
                board[y][x] = ' ';
                board[y][x + 1] = ' ';
                board[y + 1][x + 1] = ' ';
                space = 0;

                int tempX = x;
                int tempY = y;
                switch (_getch())
                {
                case 72: // Up Arrow Key
                    if (tempY > 0)
                        tempY--;
                    break;
                case 80: // Down Arrow Key
                    if (tempY < 7)
                        tempY++;
                    break;
                case 75: // Left Arrow Key
                    if (tempX > 0)
                        tempX--;
                    break;
                case 77: // Right Arrow Key
                    if (tempX < 7)
                        tempX++;
                    break;
                case 32:
                    space++;
                    break;
                default:
                    break;
                }
                if (board[tempY][tempX] == ' ' && board[tempY][tempX + 1] == ' ' && board[tempY + 1][tempX + 1] == ' ')
                {
                    x = tempX;
                    y = tempY;
                    board[y][x] = '*';
                    board[y][x + 1] = '*';
                    board[y + 1][x + 1] = '*';
                    printBoard(board);
                }
                else
                {
                    board[y][x] = '*';
                    board[y][x + 1] = '*';
                    board[y + 1][x + 1] = '*';
                }
            }
        }
    }
}
void initializebox6(char board[9][9])
{
    int x = 0, y = 0;
    if (global_a == 6)
    {
        int row_index_full_of_stars = rowcheck(board);
        if (row_index_full_of_stars != 0)
        {
            for (int j = 0; j < 9; j++)
            {
                board[row_index_full_of_stars][j] = ' ';
            }
            score += 18;
        }
        int col_index_full_of_stars = colcheck(board);
        if (col_index_full_of_stars != 0)
        {
            for (int i = 0; i < 9; i++)
            {
                board[i][col_index_full_of_stars] = ' ';
            }
            score += 18;
        }
        if (boxcheck(board) != 0)
        {
            for (int i = boxindexes[0]; i < boxindexes[0] + 3; i++)
            {
                for (int j = boxindexes[1]; j < boxindexes[1] + 3; j++)
                {
                    board[i][j] = ' ';
                }
            }
        }
        if (rowcheck(board) == 0 || colcheck(board) == 0)
        {
            score += 4;
        }
        if (checkgameover(board))
        {
            system("cls");
            printf("Game over!");
            printf("Your score : (%d)", score);
        }
        if (rowcheck(board) == 0 || colcheck(board) == 0)
        {
            score += 4;
        }
        if (board[y][x] == ' ' && board[y + 1][x] == ' ' && board[y + 2][x] == ' ')
        {
            board[y][x] = '*';
            board[y + 1][x] = '*';
            board[y + 2][x] = '*';
        }
        int space = 0;
        printBoard(board);
        while (space == 0)
        {
            if (_kbhit())
            {
                board[y][x] = ' ';
                board[y + 1][x] = ' ';
                board[y + 2][x] = ' ';
                space = 0;

                int tempX = x;
                int tempY = y;
                switch (_getch())
                {
                case 72: // Up Arrow Key
                    if (tempY > 0)
                        tempY--;
                    break;
                case 80: // Down Arrow Key
                    if (tempY < 6)
                        tempY++;
                    break;
                case 75: // Left Arrow Key
                    if (tempX > 0)
                        tempX--;
                    break;
                case 77: // Right Arrow Key
                    if (tempX < 8)
                        tempX++;
                    break;
                case 32:
                    space++;
                    break;
                default:
                    break;
                }
                if (board[tempY][tempX] == ' ' && board[tempY + 1][tempX] == ' ' && board[tempY + 2][tempX] == ' ')
                {
                    x = tempX;
                    y = tempY;
                    board[y][x] = '*';
                    board[y + 1][x] = '*';
                    board[y + 2][x] = '*';
                    printBoard(board);
                }
                else
                {
                    board[y][x] = '*';
                    board[y + 1][x] = '*';
                    board[y + 2][x] = '*';
                }
            }
        }
    }
}
void initializebox7(char board[9][9])
{
    int x = 0, y = 0;
    if (global_a == 7)
    {
        int row_index_full_of_stars = rowcheck(board);
        if (row_index_full_of_stars != 0)
        {
            for (int j = 0; j < 9; j++)
            {
                board[row_index_full_of_stars][j] = ' ';
            }
            score += 18;
        }
        int col_index_full_of_stars = colcheck(board);
        if (col_index_full_of_stars != 0)
        {
            for (int i = 0; i < 9; i++)
            {
                board[i][col_index_full_of_stars] = ' ';
            }
            score += 18;
        }
        if (boxcheck(board) != 0)
        {
            for (int i = boxindexes[0]; i < boxindexes[0] + 3; i++)
            {
                for (int j = boxindexes[1]; j < boxindexes[1] + 3; j++)
                {
                    board[i][j] = ' ';
                }
            }
        }
        if (rowcheck(board) == 0 || colcheck(board) == 0)
        {
            score += 4;
        }
        if (checkgameover(board))
        {
            system("cls");
            printf("Game over!");
            printf("Your score : (%d)", score);
        }
        if (board[y][x] == ' ' && board[y + 1][x] == ' ' && board[y + 2][x] == ' ' && board[y + 3][x] == ' ')
        {
            board[y][x] = '*';
            board[y + 1][x] = '*';
            board[y + 2][x] = '*';
            board[y + 3][x] = '*';
        }
        int space = 0;
        printBoard(board);
        while (space == 0)
        {
            if (_kbhit())
            {
                board[y][x] = ' ';
                board[y + 1][x] = ' ';
                board[y + 2][x] = ' ';
                board[y + 3][x] = ' ';
                space = 0;

                int tempX = x;
                int tempY = y;
                switch (_getch())
                {
                case 72: // Up Arrow Key
                    if (tempY > 0)
                        tempY--;
                    break;
                case 80: // Down Arrow Key
                    if (tempY < 5)
                        tempY++;
                    break;
                case 75: // Left Arrow Key
                    if (tempX > 0)
                        tempX--;
                    break;
                case 77: // Right Arrow Key
                    if (tempX < 8)
                        tempX++;
                    break;
                case 32:
                    space++;
                    break;
                default:
                    break;
                }
                if (board[tempY][tempX] == ' ' && board[tempY + 1][tempX] == ' ' && board[tempY + 2][tempX] == ' ' && board[tempY + 3][tempX] == ' ')
                {
                    x = tempX;
                    y = tempY;
                    board[y][x] = '*';
                    board[y + 1][x] = '*';
                    board[y + 2][x] = '*';
                    board[y + 3][x] = '*';
                    printBoard(board);
                }
                else
                {
                    board[y][x] = '*';
                    board[y + 1][x] = '*';
                    board[y + 2][x] = '*';
                    board[y + 3][x] = '*';
                }
            }
        }
    }
}
void initializebox8(char board[9][9])
{
    int x = 0, y = 0;
    if (global_a == 8)
    {
        int row_index_full_of_stars = rowcheck(board);
        if (row_index_full_of_stars != 0)
        {
            for (int j = 0; j < 9; j++)
            {
                board[row_index_full_of_stars][j] = ' ';
            }
            score += 18;
        }
        int col_index_full_of_stars = colcheck(board);
        if (col_index_full_of_stars != 0)
        {
            for (int i = 0; i < 9; i++)
            {
                board[i][col_index_full_of_stars] = ' ';
            }
            score += 18;
        }
        if (boxcheck(board) != 0)
        {
            for (int i = boxindexes[0]; i < boxindexes[0] + 3; i++)
            {
                for (int j = boxindexes[1]; j < boxindexes[1] + 3; j++)
                {
                    board[i][j] = ' ';
                }
            }
        }
        if (rowcheck(board) == 0 || colcheck(board) == 0)
        {
            score += 4;
        }
        if (checkgameover(board))
        {
            system("cls");
            printf("Game over!");
            printf("Your score : (%d)", score);
        }

        if (board[y][x] == ' ')
        {
            board[y][x] = '*';
        }
        int space = 0;
        printBoard(board);
        while (space == 0)
        {
            if (_kbhit())
            {
                board[y][x] = ' ';
                space = 0;

                int tempX = x;
                int tempY = y;
                switch (_getch())
                {
                case 72: // Up Arrow Key
                    if (tempY > 0)
                        tempY--;
                    break;
                case 80: // Down Arrow Key
                    if (tempY < 8)
                        tempY++;
                    break;
                case 75: // Left Arrow Key
                    if (tempX > 0)
                        tempX--;
                    break;
                case 77: // Right Arrow Key
                    if (tempX < 8)
                        tempX++;
                    break;
                case 32:
                    space++;
                    break;
                default:
                    break;
                }
                if (board[tempY][tempX] == ' ')
                {
                    x = tempX;
                    y = tempY;
                    board[y][x] = '*';
                    printBoard(board);
                }
                else
                {
                    board[y][x] = '*';
                }
            }
        }
    }
}
void initializebox9(char board[9][9])
{
    int x = 0, y = 0;
    if (global_a == 9)
    {
        int row_index_full_of_stars = rowcheck(board);
        if (row_index_full_of_stars != 0)
        {
            for (int j = 0; j < 9; j++)
            {
                board[row_index_full_of_stars][j] = ' ';
            }
            score += 18;
        }
        int col_index_full_of_stars = colcheck(board);
        if (col_index_full_of_stars != 0)
        {
            for (int i = 0; i < 9; i++)
            {
                board[i][col_index_full_of_stars] = ' ';
            }
            score += 18;
        }
        if (boxcheck(board) != 0)
        {
            for (int i = boxindexes[0]; i < boxindexes[0] + 3; i++)
            {
                for (int j = boxindexes[1]; j < boxindexes[1] + 3; j++)
                {
                    board[i][j] = ' ';
                }
            }
        }
        if (rowcheck(board) == 0 || colcheck(board) == 0)
        {
            score += 4;
        }
        if (checkgameover(board))
        {
            system("cls");
            printf("Game over!");
            printf("Your score : (%d)", score);
        }
        if (board[y][x] == ' ' && board[y][x + 1] == ' ' && board[y][x + 2] == ' ' && board[y][x + 3] == ' ')
        {
            board[y][x] = '*';
            board[y][x + 1] = '*';
            board[y][x + 2] = '*';
            board[y][x + 3] = '*';
        }
        int space = 0;
        printBoard(board);
        while (space == 0)
        {
            if (_kbhit())
            {
                board[y][x] = ' ';
                board[y][x + 1] = ' ';
                board[y][x + 2] = ' ';
                board[y][x + 3] = ' ';
                space = 0;

                int tempX = x;
                int tempY = y;
                switch (_getch())
                {
                case 72: // Up Arrow Key
                    if (tempY > 0)
                        tempY--;
                    break;
                case 80: // Down Arrow Key
                    if (tempY < 8)
                        tempY++;
                    break;
                case 75: // Left Arrow Key
                    if (tempX > 0)
                        tempX--;
                    break;
                case 77: // Right Arrow Key
                    if (tempX < 5)
                        tempX++;
                    break;
                case 32:
                    space++;
                    break;
                default:
                    break;
                }
                if (board[tempY][tempX] == ' ' && board[tempY][tempX + 1] == ' ' && board[tempY][tempX + 2] == ' ' && board[tempY][tempX + 3] == ' ')
                {
                    x = tempX;
                    y = tempY;
                    board[y][x] = '*';
                    board[y][x + 1] = '*';
                    board[y][x + 2] = '*';
                    board[y][x + 3] = '*';
                    printBoard(board);
                }
                else
                {
                    board[y][x] = '*';
                    board[y][x + 1] = '*';
                    board[y][x + 2] = '*';
                    board[y][x + 3] = '*';
                }
            }
        }
    }
}
void initializebox10(char board[9][9])
{
    int x = 0, y = 0;
    if (global_a == 10)
    {
        int row_index_full_of_stars = rowcheck(board);
        if (row_index_full_of_stars != 0)
        {
            for (int j = 0; j < 9; j++)
            {
                board[row_index_full_of_stars][j] = ' ';
            }
            score += 18;
        }
        int col_index_full_of_stars = colcheck(board);
        if (col_index_full_of_stars != 0)
        {
            for (int i = 0; i < 9; i++)
            {
                board[i][col_index_full_of_stars] = ' ';
            }
            score += 18;
        }
        if (boxcheck(board) != 0)
        {
            for (int i = boxindexes[0]; i < boxindexes[0] + 3; i++)
            {
                for (int j = boxindexes[1]; j < boxindexes[1] + 3; j++)
                {
                    board[i][j] = ' ';
                }
            }
        }
        if (rowcheck(board) == 0 || colcheck(board) == 0)
        {
            score += 4;
        }
        if (checkgameover(board))
        {
            system("cls");
            printf("Game over!");
            printf("Your score : (%d)", score);
        }
        if (board[y][x] == ' ' && board[y][x + 1] == ' ' && board[y][x + 2] == ' ')
        {
            board[y][x] = '*';
            board[y][x + 1] = '*';
            board[y][x + 2] = '*';
        }
        int space = 0;
        printBoard(board);
        while (space == 0)
        {
            if (_kbhit())
            {
                board[y][x] = ' ';
                board[y][x + 1] = ' ';
                board[y][x + 2] = ' ';
                space = 0;

                int tempX = x;
                int tempY = y;
                switch (_getch())
                {
                case 72: // Up Arrow Key
                    if (tempY > 0)
                        tempY--;
                    break;
                case 80: // Down Arrow Key
                    if (tempY < 8)
                        tempY++;
                    break;
                case 75: // Left Arrow Key
                    if (tempX > 0)
                        tempX--;
                    break;
                case 77: // Right Arrow Key
                    if (tempX < 6)
                        tempX++;
                    break;
                case 32:
                    space++;
                    break;
                default:
                    break;
                }
                if (board[tempY][tempX] == ' ' && board[tempY][tempX + 1] == ' ' && board[tempY][tempX + 2] == ' ')
                {
                    x = tempX;
                    y = tempY;
                    board[y][x] = '*';
                    board[y][x + 1] = '*';
                    board[y][x + 2] = '*';
                    printBoard(board);
                }
                else
                {
                    board[y][x] = '*';
                    board[y][x + 1] = '*';
                    board[y][x + 2] = '*';
                }
            }
        }
    }
}
void move(char board[9][9])
{
    if (global_a == 1)
    {
        initializebox1(board);
    }
    else if (global_a == 2)
    {
        initializebox2(board);
    }
    else if (global_a == 3)
    {
        initializebox3(board);
    }
    else if (global_a == 4)
    {
        initializebox4(board);
    }
    else if (global_a == 5)
    {
        initializebox5(board);
    }
    else if (global_a == 6)
    {
        initializebox6(board);
    }
    else if (global_a == 7)
    {
        initializebox7(board);
    }
    else if (global_a == 8)
    {
        initializebox8(board);
    }
    else if (global_a == 9)
    {
        initializebox9(board);
    }
    else if (global_a == 10)
    {
        initializebox10(board);
    }
}
int main()
{
    srand(time(NULL));

    char board[9][9] = {
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}};

    while (1)

    {
        for (int i = 0; i < 3; i++)
        {
            rshape();
        }

        selectedbox();

        printf("\n\n\n\n\n\n\n\n\n\n\n");
        move(board);
    }
    return 0;
}