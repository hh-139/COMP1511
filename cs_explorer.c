// CS Explorer
// cs_explorer.c
//
// This program was written by YOUR-NAME-HERE (z5555555)
// on INSERT-DATE-HERE
//
// Version 1.0.0 (2022-03-08): Assignment Released.
//
// TODO: Description of your program.

#include <stdio.h>

// Additional libraries here


// Provided constants 
#define SIZE 8
#define PLAYER_STARTING_ROW (SIZE - 1)
#define PLAYER_STARTING_COL 0
#define EMPTY_POINTS 0
#define EMPTY_TYPE 'E'
#define PLAYER_TYPE 'P'
#define MONSTER_TYPE 'M'
#define HEALING_TYPE 'H'
#define BOULDER_TYPE 'B'

// Your constants here

// Provided struct
struct location {
    char occupier;
    int points;
};

// Your structs here

// Provided functions use for game setup
// You do not need to use these functions yourself.
void init_map(struct location map[SIZE][SIZE]);
void place_player_on_starting_location(struct location map[SIZE][SIZE]);

// You will need to use these functions for stage 1.
void print_cheat_map(struct location map[SIZE][SIZE]);
void print_game_play_map(struct location map[SIZE][SIZE]);

// Your functions prototypes here

int main(void) {

    struct location map[SIZE][SIZE];
    init_map(map);

    printf("Welcome Explorer!!\n");
    printf("How many game pieces are on the map?\n");
    
    // TODO: Add code to scan in the number of game pieces here.
    
    // TODO: Add code to scan in the details of each game piece and place them
    //       on the map

    // After the game pieces have been added to the map print out the map.
    print_game_play_map(map);
    printf("\nEXPLORE!\n");
    printf("Enter command: ");

    // TODO: keep scanning in commands from the user until the user presses
    // ctrl + d
    
    return 0;
}


////////////////////////////////////////////////////////////////////////////////
///////////////////////////// ADDITIONAL FUNCTIONS /////////////////////////////
////////////////////////////////////////////////////////////////////////////////

// TODO: you may need to add additional functions here

////////////////////////////////////////////////////////////////////////////////
////////////////////////////// PROVIDED FUNCTIONS //////////////////////////////
/////////////////////////// (DO NOT EDIT BELOW HERE) ///////////////////////////
////////////////////////////////////////////////////////////////////////////////

// Provided Function
// Initalises all elements on the map to be empty to prevent access errors.
void init_map(struct location map[SIZE][SIZE]) {
    int row = 0;
    while (row < SIZE) {
        int col = 0;
        while (col < SIZE) {
            struct location curr_loc;
            curr_loc.occupier = EMPTY_TYPE;
            curr_loc.points = EMPTY_POINTS;
            map[row][col] = curr_loc;
            col++;
        }
        row++;
    }

    place_player_on_starting_location(map);
}

// Provided Function
// Places the player in the bottom left most location.
void place_player_on_starting_location(struct location map[SIZE][SIZE]) {
    map[PLAYER_STARTING_ROW][PLAYER_STARTING_COL].occupier = PLAYER_TYPE;
}

// Provided Function
// Prints out map with alphabetic values. Monsters are represented with 'M',
// healing potions in 'H', boulders with 'B' and the player with 'P'.
void print_game_play_map(struct location map[SIZE][SIZE]) {
    printf(" -----------------\n");
    int row = 0;
    while (row < SIZE) {
        printf("| ");
        int col = 0;
        while (col < SIZE) {
            if (map[row][col].occupier == EMPTY_TYPE) {
                printf("- ");
            } else {
                printf("%c ", map[row][col].occupier);
            }
            col++;
        }
        printf("|\n");
        row++;
    }
    printf(" -----------------\n");
}

// Provided Function
// Prints out map with numerical values. Monsters are represented in red,
// healing potions in blue, boulder in green and the player in yellow.
//
// We use some functionality you have not been taught to make sure that
// colours do not appear during testing.
void print_cheat_map(struct location map[SIZE][SIZE]) {

    printf(" -----------------\n");
    int row = 0;
    while (row < SIZE) {
        printf("| ");
        int col = 0;
        while (col < SIZE) {
            if (map[row][col].occupier == PLAYER_TYPE) {
                // print the player in purple
                // ----------------------------------------
                // YOU DO NOT NEED TO UNDERSTAND THIS CODE.
                #ifndef NO_COLORS
                printf("\033[1;35m");
                #endif
                // ----------------------------------------
                printf("%c ", PLAYER_TYPE);
            } else if (map[row][col].occupier == HEALING_TYPE) {
                // print healing potion in green
                // ----------------------------------------
                // YOU DO NOT NEED TO UNDERSTAND THIS CODE.
                #ifndef NO_COLORS
                printf("\033[1;32m");
                #endif
                // ----------------------------------------
                printf("%d ", map[row][col].points);
            } else if (map[row][col].occupier == MONSTER_TYPE) {
                // print monsters in red
                // ----------------------------------------
                // YOU DO NOT NEED TO UNDERSTAND THIS CODE.
                #ifndef NO_COLORS
                printf("\033[1;31m");
                #endif
                // ----------------------------------------
                printf("%d ", -map[row][col].points);
            } else if (map[row][col].occupier == BOULDER_TYPE) {
                // print boulder in blue
                // ----------------------------------------
                // YOU DO NOT NEED TO UNDERSTAND THIS CODE.
                #ifndef NO_COLORS
                printf("\033[1;34m");
                #endif
                // ----------------------------------------
                printf("%d ", map[row][col].points);
            } else {
                // print empty squares in the default colour
                printf("- ");
            }
            // ----------------------------------------
            // YOU DO NOT NEED TO UNDERSTAND THIS CODE.
            // reset the colour back to default
            #ifndef NO_COLORS
            printf("\033[0m");
            #endif
            // ----------------------------------------
            col++;
        }
        printf("|\n");
        row++;
    }
    printf(" -----------------\n");
}
