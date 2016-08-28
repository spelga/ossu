/**
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;



// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);

int main(int argc, string argv[])
{


    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE* file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(void)
{
    // variable to hold board number. Initialised to d * d - 1
    int number = d * d - 1;
    
    // build board array
    // iterate rows in array
    for (int i = 0; i < d; i++)
    {
        // iterate for columns in array
        for (int j = 0; j < d; j++)
        {
            board[i][j] = number;
            number --;
        }
    }
    
    // correct board to set edge cases
    
    // set bottom right square to 0 to represent the free space
    board[d - 1][d - 1] = 0;
    
    // swap last two digits if board dimensions are even for both rows and columns
    if (d % 2 == 0)
    {
        board[d - 1][d - 2] = 2;
        board[d - 1][d - 3] = 1;
    }
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            printf("%2i   ", board[i][j]);
        }
        printf("\n");
    }
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
    // variables
    int space_row = d - 1;
    int space_col = d - 1;
    int tile_row = 0;
    int tile_col = 0;
    int space = 0;
    
    // find selected tile in array
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (board[i][j] == tile)
            {
                tile_row = i;
                tile_col = j;
                break;
            }
        }
    }
    
    // find space in array
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (board[i][j] == 0)
            {
                space_row = i;
                space_col = j;
                break;
            }
        }
    }
    
    // check if there is a valid move
    
    if (tile_row + 1 == space_row && tile_col == space_col)
    {
        board[tile_row][tile_col] = space;
        board[space_row][space_col] = tile;
        return true;
    }
    else if (tile_row == space_row && tile_col + 1 == space_col)
    {
        board[tile_row][tile_col] = space;
        board[space_row][space_col] = tile;
        return true;
    }
    else if (tile_row - 1 == space_row && tile_col == space_col)
    {
        board[tile_row][tile_col] = space;
        board[space_row][space_col] = tile;
        return true;
    }
    else if (tile_row == space_row && tile_col - 1 == space_col)
    {
        board[tile_row][tile_col] = space;
        board[space_row][space_col] = tile;
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
    bool won(void)
    {
        // variable to count from 1 upwards
        int counter = 1;
        
        // outer loop which runs d times
        for (int i = 0; i < d; i++)
        {
            // inner loop which runs d times.
            // will maximally run d * d times
            for (int j = 0; j < d; j++)
            {
                // returns true if the counter == number of tiles on the board + space
                // which is the number of elements in the array which d * d
                if (counter == d * d)
                {
                    return true;
                }
                // checks if the counter != tile on the board at the position checked
                // and returns false if it's not.
                else if (board[i][j] != counter)
                {
                    return false;
                }
                // increments the counter by 1 to continue through the loops to
                // check for a winning state.
                else
                {
                    counter++;
                }
            }
        }
        return true;
    }
