/**************************************************************************
 * This work originally copyright David J. Malan of Harvard University, or-
 * iginally released under:
 * CC BY-NC-SA 3.0  http://creativecommons.org/licenses/by-nc-sa/3.0/
 * licensing.
 *
 * It has been adapted for use in csci 1730.  Per the share-alike
 * clause of this license, this document is also released under the
 * same license.
 **************************************************************************/
/**
 * fifteen.c
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
int isInBounds(int);
int tileLocation(int);
int move(int);
int won(void);

int main(int argc, char* argv[])
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
    while (1)
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
            printf("win!\n");
            break;
        }

        // prompt for move
        printf("Tile to move (0 to exit): ");
        int tile;
		scanf("%d", &tile);
		getchar();

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
            usleep(50000);
        }

        // sleep thread for animation's sake
        usleep(50000);
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
    usleep(200000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).
 */
void init(void)
{
    // calculates the amount of tiles
    int count = d * d - 1;
    // assigns every one tile
    for (int i = 0; i < d; i++) {
        for ( int j = 0; j < d; j++) {
            board[i][j] = count;
            count--;
        } // for
    } // for
    // checks if the board size is even or not
    if (d % 2 == 0) {
        board[d - 1][d - 3] = 1;
        board[d - 1][d - 2] = 2;
    } // if
} // init

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    int boardNum = d * d - 1;

// loops through the 2d array
    for (int i = 0; i < d; i++) {

        for (int j = 0; j < d; j++) {
            boardNum = board[i][j];
            // prints a '_' since the 0 represents an empty space
            if ( boardNum == 0 ) {
                printf(" _");
            } else {
                if( board[i][j] < 10) {
                    printf("% d", boardNum); // print the number with a space before
                } else {
                    printf("%d ", boardNum); // print the number
                } // if

            } // if
            // prints a space after the number only if the number is not the last in the row
            if ( j < d - 1 && boardNum < 10 ) {
                printf(" ");
            } // if

        } // for
            printf("\n"); // separates the rows
    } // for
}

/**
 *  Checks if the tile is in bounds.
 *
 *  @param tile the number on the board
 *  @return 1 if the tile is in bounds, 0 otherwise
 */
int isInBounds(int tile) {

    int tileLoc = tileLocation(tile);

    // gets the row and col
    int col = tileLoc % 10;
    int row = tileLoc / 10;

    // checks if the row is in bounds
    if (row >= d || row < 0) {
        return 0;
    } // checks if the column is in bounds
    if (col >= d || col < 0) {
        return 0;
    }
    return 1;

} // isInBounds

/**
 * Finds the position of the tile.
 *
 * @param tile the number on the board
 * @return the location of the tile on the array
 */
int tileLocation(int tile) {
    // search through entire board
    int tileLocation = 0;

    // iterates through entire array
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < d; j++) {

            // finds the location of the tile
            if (board[i][j] == tile) {
                tileLocation += i * 10; // stores the row in the 10s place
                tileLocation += j; // stores the col in the 1s place
            } // if
        } // for
    } // for

    return tileLocation;
} // tileLocation

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false.
 *
 * @param tile the number which is being switched.
 * @return true if tile is moved, false if not
 */
int move(int tile)
{
    // prevents a 0, negative, or number greater than the max value from being input
    if (!isInBounds(tile)) {
        return 0;
    } // if

    // gets the row and col of the _
    int lofSpace = tileLocation(0);
    int spaceCol = lofSpace % 10;
    int spaceRow = lofSpace / 10;

    // gets the row and column of the tile to be changed
    int lofTile = tileLocation(tile);
    int tileCol = lofTile % 10;
    int tileRow = lofTile / 10;

    // checks if the space and the value selected are within a 1 tile radius
    if (abs(spaceCol - tileCol) == 1 || abs(spaceRow - tileRow) == 1) {

        int hold; // holds the value to be moved

        // checks for values that are to the left or right of the selected value
        if (abs(spaceCol - tileCol) == 1 && abs(spaceRow - tileRow) == 0) {
            hold = tile;
            board[tileRow][tileCol] = 0; // reassigns the _
            board[spaceRow][spaceCol] = hold; // switchs the value

            return 1;
        } // if

        // checks for values that are to the top or bottom of the selected values
        if (abs(spaceRow - tileRow) == 1 && abs(spaceCol - tileCol) == 0) {
            hold = tile;
            board[tileRow][tileCol] = 0;
            board[spaceRow][spaceCol] = hold;

            return 1;
        } // if
    } // if

    return 0;

} // move

/**
 * Returns true if game is won (i.e., board is in winning configuration),
 * else false.
 */
int won(void)
{
    int val = 1;
    int winCount = 0;
    // checks if the values of the board are in the correct position
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < d; j++) {
            if (val == board[i][j]) {
                winCount++;
            } // if
            val++; // increase value of comparison
        } // for
    } // for

    // checks if the win count has been reached
    if ( winCount >= d*d - 1) {
        return 1;
    } // if
    return 0;
}
