#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

////// SET UP PRIMARY GLOBAL VARIABLES AND SETS

bool pterm;                    // TERMINATOR FOR MAIN POLLING
bool pterm_stp;                // TERMINATOR FOR GAME SETUP POLLING
bool pterm_alt;                // TERMINATOR FOR ANY ADDITIONAL POLLINGS
bool err;                      // INDICATOR FOR POSSIBLE ERROR RETURN AT SELECTION MENUS
int opt;                       // STORES USER-CHOSEN OPTION AT SELECTION MENUS
std::string bopt;              // STORES USER-CHOSEN "Y/N" SELECTION
std::vector<int> opt_list;     // STORES THE LEGAL SELECTION OF OPTIONS AT A GIVEN PROMPT

int grid_size;                 // STORES THE SIZE OF THE BOARD           - 1 = NORMAL SIZE (7 x 7), 2 = LARGE SIZE (9 x 9)
int game_mode;                 // STORES THE GAMEMODE                    - 1 = COMPUTER MULTIPLAYER, 2 = VERSUS MULTIPLAYER
std::string player_a;          // STORES THE NAME OF PLAYER ONE
std::string player_b;          // STORES THE NAME OF PLAYER TWO
int marker_a;                  // STORES THE MARKER USED BY PLAYER ONE   - 1 = RED, 2 = YELLOW, 3 = BLUE, 4 = GREEN
int marker_b;                  // STORES THE MARKER USED BY PLAYER TWO   - 1 = RED, 2 = YELLOW, 3 = BLUE, 4 = GREEN

std::vector<std::vector<std::string>> a_grid;    // STORES THE ACTIVE GAME GRID

////// SET UP SPRITES AND GRAPHICAL ITEMS
        
// INDIVIDUAL MARKER ATTRIBUTES
std::vector<std::string> labels_col = {"NULL", "Red", "Yellow", "Blue", "Green"};    // STORES THE NAMES OF THE MARKER TYPES
std::vector<std::string> tags_col = {"[ ]", "[#]", "[$]", "[%]", "[&]"};             // STORES THE SYMBOLS WHICH REPRESENT EACH MARKER TYPE
std::vector<std::string> mk_select;                                                  // STORES A LIST OF AVAILABLE CHIP/MARKER COLORS (FOR COLOR SELECTION)

// SIZED GRIDS
std::vector<std::vector<std::string>> ns_grid = {{"|A|", "|B|", "|C|", "|D|", "|E|", "|F|", "|G|"}, 
                                                 {"---", "---", "---", "---", "---", "---", "---"}, 
                                                 {"[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]"}, 
                                                 {"[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]"}, 
                                                 {"[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]"}, 
                                                 {"[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]"}, 
                                                 {"[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]"}, 
                                                 {"[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]"}, 
                                                 {"[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]"}, 
                                                 {"---", "---", "---", "---", "---", "---", "---"}, 
                                                 {"|=|", "   ", "   ", "|=|", "   ", "   ", "|=|"}};
std::vector<std::vector<std::string>> ls_grid = {{"|A|", "|B|", "|C|", "|D|", "|E|", "|F|", "|G|", "|H|", "|I|"}, 
                                                 {"---", "---", "---", "---", "---", "---", "---", "---", "---"}, 
                                                 {"[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]"}, 
                                                 {"[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]"}, 
                                                 {"[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]"}, 
                                                 {"[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]"}, 
                                                 {"[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]"}, 
                                                 {"[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]"}, 
                                                 {"[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]"}, 
                                                 {"[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]"}, 
                                                 {"[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]"}, 
                                                 {"---", "---", "---", "---", "---", "---", "---", "---", "---"}, 
                                                 {"|=|", "   ", "|=|", "   ", "|=|", "   ", "|=|", "   ", "|=|"}};

// RENDERING FOR GAME BOARDS + ADDITIONAL CUSTOM SCREEN COMMANDS
void s_pause() { std::cin.get(); }                         // SHORTCUT FOR PAUSING THE SCREEN
void s_clear() { std::cout << "\033[2J\033[1;1H"; }        // SHORTCUT FOR CLEARING THE SCREEN

void ren_grid() {
    for (int i = 0; i < a_grid.size(); i++) {
        std::cout << "::::\t";
        for (int j = 0; j < a_grid[i].size(); j++) { std::cout << a_grid[i][j]; }
        std::cout << "\t::::" << std::endl;
    }
}

////// SET UP SCREENS

// SOME ADDITIONAL SELECTION COMMANDS
bool in_opt(int n) {
    bool qu = false;
    for (int i = 0; i < opt_list.size(); i++) { if (opt_list[i] == n) { qu = true; } }
    return qu;
}

void ren_s(int o) {
    err = false;
    opt_list = {};
    for (int i = 0; i < o; i++) { opt_list.push_back(i + 1); }
    s_clear();
}

void ch_err(int c) { if (!in_opt(c)) { err = true; } }

// SCREEN RENDERS
void p_titlescr() {
    ren_s(1);
    std::cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
    std::cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
    std::cout << "::::                                                                     ::::\n";
    std::cout << "::::      ___    ___                  _____   ___  _______               ::::\n";
    std::cout << "::::     /   \\  /   \\  |\\   | |\\   | |       /   \\    |       |   |      ::::\n";
    std::cout << "::::    |      |     | | \\  | | \\  | |_____ |         |       |   |      ::::\n";
    std::cout << "::::    |      |     | |  \\ | |  \\ | |      |         |       |___|__    ::::\n";
    std::cout << "::::     \\___/  \\___/  |   \\| |   \\| |_____  \\___/    |           |      ::::\n";
    std::cout << "::::    _____________________________________________________________    ::::\n";
    std::cout << "::::    _____________________________________________________________    ::::\n";
    std::cout << "::::                                                                     ::::\n";
    std::cout << "::::                                                                     ::::\n";
    std::cout << "::::                      Programmed by GalacticSand                     ::::\n";
    std::cout << "::::                (c) 2020 - Galaxius Computer Software                ::::\n";
    std::cout << "::::                                                                     ::::\n";
    std::cout << "::::                                                                     ::::\n";
    std::cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
    std::cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n"; 
    std::cout << "\n\n";
    std::cout << " -=-=-=-=  Press Enter to Start  =-=-=-=- \n";
    s_pause();
}

void p_menuscr() {
    ren_s(3);
    std::cout << "::::\n";
    std::cout << "::::\n";
    std::cout << "::::    === Connect 4 - Main Menu ===\n";
    std::cout << "::::\n";
    std::cout << "::::\n";
    std::cout << "::::    1. Begin Game \n";
    std::cout << "::::    2. Settings \n";
    std::cout << "::::    3. Quit \n";
    std::cout << "::::\n";
    std::cout << "::::\n";
    std::cout << "::::\n";
    std::cout << "::::\n";
    std::cout << "::::    Option: ";
    std::cin >> opt;
    ch_err(opt);
}

void p_gsetup(int scr) {      // RENDERS ALL OF THE SCREENS NEEDED FOR INITIALIZING A NEW GAME, EXCEPT FOR COLOR SELECTION (SEE BELOW)
    switch(scr) {
      case 1 :
        ren_s(2);
        std::cout << "::::\n";
        std::cout << "::::\n";
        std::cout << "::::    === Begin Game ===\n";
        std::cout << "::::\n";
        std::cout << "::::\n";
        std::cout << "::::    Select Board Size \n";
        std::cout << "::::\n";
        std::cout << "::::    1. Normal (7 x 7)\n";
        std::cout << "::::    2. Large (9 x 9)\n";
        std::cout << "::::\n";
        std::cout << "::::\n";
        std::cout << "::::    Option: ";
        std::cin >> grid_size;
        ch_err(grid_size);
        break;
      case 2 :
        ren_s(2);
        std::cout << "::::\n";
        std::cout << "::::\n";
        std::cout << "::::    === Begin Game ===\n";
        std::cout << "::::\n";
        std::cout << "::::\n";
        std::cout << "::::    Select Gamemode \n";
        std::cout << "::::\n";
        std::cout << "::::    1. CPU Multiplayer\n";
        std::cout << "::::    2. Versus Multiplayer\n";
        std::cout << "::::\n";
        std::cout << "::::\n";
        std::cout << "::::    Option: ";
        std::cin >> game_mode;
        ch_err(game_mode);
        break;
      case 3 :
        ren_s(1);
        std::cout << "::::\n";
        std::cout << "::::\n";
        std::cout << "::::    === Begin Game ===\n";
        std::cout << "::::\n";
        std::cout << "::::\n";
        std::cout << "::::    Current Players \n";
        std::cout << "::::\n";
        std::cout << "::::    Player 1 - \n";
        std::cout << "::::    Player 2 - \n";
        std::cout << "::::\n";
        std::cout << "::::\n";
        std::cout << "::::    Enter Player 1 Name: ";
        std::cin >> player_a;
        break;
      case 4 :
        ren_s(1);
        std::cout << "::::\n";
        std::cout << "::::\n";
        std::cout << "::::    === Begin Game ===\n";
        std::cout << "::::\n";
        std::cout << "::::\n";
        std::cout << "::::    Current Players \n";
        std::cout << "::::\n";
        std::cout << "::::    Player 1 - " << player_a << " \n";
        std::cout << "::::    Player 2 - \n";
        std::cout << "::::\n";
        std::cout << "::::\n";
        std::cout << "::::    Enter Player 2 Name: ";
        std::cin >> player_b;
        break;
      case 5 :
        ren_s(1);
        std::cout << "::::\n";
        std::cout << "::::\n";
        std::cout << "::::    === Begin Game ===\n";
        std::cout << "::::\n";
        std::cout << "::::\n";
        std::cout << "::::    Current Players \n";
        std::cout << "::::\n";
        std::cout << "::::    Player 1 - " << player_a << " \n";
        std::cout << "::::    Player 2 - " << player_b << " \n";
        std::cout << "::::\n";
        std::cout << "::::\n";
        std::cout << "::::    Continue with these settings? (Y/N) ";
        std::cin >> bopt;
        break;
      case 6 :
        ren_s(1);
        std::cout << "::::\n";
        std::cout << "::::\n";
        std::cout << "::::    === Begin Game ===\n";
        std::cout << "::::\n";
        std::cout << "::::\n";
        std::cout << "::::    Current Players \n";
        std::cout << "::::\n";
        std::cout << "::::    Player 1 - \n";
        std::cout << "::::    Player 2 - The Computer \n";
        std::cout << "::::\n";
        std::cout << "::::\n";
        std::cout << "::::    Enter Player 1 Name: ";
        std::cin >> player_a;
        break;
      case 7 :
        ren_s(1);
        std::cout << "::::\n";
        std::cout << "::::\n";
        std::cout << "::::    === Begin Game ===\n";
        std::cout << "::::\n";
        std::cout << "::::\n";
        std::cout << "::::    Current Players \n";
        std::cout << "::::\n";
        std::cout << "::::    Player 1 - " << player_a << " \n";
        std::cout << "::::    Player 2 - The Computer \n";
        std::cout << "::::\n";
        std::cout << "::::\n";
        std::cout << "::::    Continue with these settings? (Y/N) ";
        std::cin >> bopt;
        break;
    }
}

void p_colorsel(int scr) {      // RENDERS THE COLOR SELECTION, DEFINITION SEPRATE FROM REGULAR RENDERS PREVENTS TWO PLAYERS FROM PICKING THE SAME COLOR
    mk_select = {};
    std::string conc_str;
    for (int i = 0; i < tags_col.size(); i++) { 
        conc_str = (i + 1) + ". " + labels_col[i + 1] + " " + tags_col[i + 1];
        mk_select.push_back(conc_str);
    }
    switch(scr) {
      case 1 :
        ren_s(4);
        std::cout << "::::\n";
        std::cout << "::::\n";
        std::cout << "::::    === Begin Game ===\n";
        std::cout << "::::\n";
        std::cout << "::::\n";
        std::cout << "::::    Chip Colors \n";
        std::cout << "::::\n";
        for (int i = 0; i < mk_select.size(); i++) { std::cout << "::::    " << mk_select[i] << std::endl; }
        std::cout << "::::\n";
        std::cout << "::::\n";
        std::cout << "::::    Select Player 1 Color: ";
        std::cin >> marker_a;
        ch_err(marker_a);
        mk_select[marker_a] = "[ALREADY SELECTED]";
      case 2 :
        std::cout << "::::\n";
        std::cout << "::::\n";
        std::cout << "::::    === Begin Game ===\n";
        std::cout << "::::\n";
        std::cout << "::::\n";
        std::cout << "::::    Chip Colors \n";
        std::cout << "::::\n";
        for (int i = 0; i < mk_select.size(); i++) { std::cout << "::::    " << mk_select[i] << std::endl; }
        std::cout << "::::\n";
        std::cout << "::::\n";
        std::cout << "::::    Select Player 2 Color: ";
        std::cin >> marker_b;
        ch_err(marker_b);
        break;
    }
}

////// SET UP FUNCTIONS AND GAMEPLAY

void menuscr() {
    while (true) {    
        p_menuscr();
        if (!err) { break; }
    }
}

////// MAIN SPACE WHERE GAME INITIALIZES AND PRIMARY POLLING TAKES PLACE

int main() {
    p_titlescr();
    pterm = false;
    while (true) {
        menuscr();
        if (pterm) { break; }
    }
}
