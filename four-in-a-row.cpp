#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

////// SET UP PRIMARY GLOBAL VARIABLES AND SETS

bool pterm;                    // TERMINATOR FOR MAIN POLLING
bool pterm_alt;                // TERMINATOR FOR ANY SECONDARY POLLINGS
bool err;                      // INDICATOR FOR POSSIBLE ERROR RETURN AT SELECTION MENUS
int opt;                       // STORES USER-CHOSEN OPTION AT SELECTION MENUS
std::vector<int> opt_list;     // STORES THE LEGAL SELECTION OF OPTIONS AT A GIVEN PROMPT

int grid_size;                 // STORES THE SIZE OF THE BOARD   - 1 = NORMAL SIZE (7 x 7), 2 = LARGE SIZE (9 x 9)
int game_mode;                 // STORES THE GAMEMODE            - 1 = COMPUTER MULTIPLAYER, 2 = VERSUS MULTIPLAYER

std::vector<std::vector<std::string>> a_grid;

////// SET UP SPRITES AND GRAPHICAL ITEMS

// CLASS FOR MARKER TYPES
class Marker {
        std::string label;
        std::string tag;
    public:
        Marker(std::string l, std::string t) {
            label = l;
            tag = t;
        }
        std::string get_l() { return label; }
        std::string get_t() { return tag; }
        void change_l(std::string n_label) { label = n_label; }
        void change_t(std::string n_tag) { tag = n_tag; }
};

// INDIVIDUAL MARKER TYPES
Marker mk_blank("NULL", "[ ]");         // MARKER FOR BLANK SPACE
Marker mk_red("red", "[#]");            // MARKER FOR RED CHIP
Marker mk_yellow("yellow", "[$]");      // MARKER FOR YELLOW CHIP

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

void ren_sel(int o) {
    err = false;
    opt_list = {};
    for (int i = 0; i < o; i++) { opt_list.push(i + 1); }
    s_clear();
}

void ch_err() { if (!in_opt(opt)) { err = true; } }

// SCREEN RENDERS
void print_titlescr() {
    ren_sel(1);
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

void print_menuscr() {
    ren_sel(3);
    std::cout << "::::\n";
    std::cout << "::::\n";
    std::cout << "::::    Connect 4 - Main Menu\n";
    std::cout << "::::\n";
    std::cout << "::::\n";
    std::cout << "::::    1. Begin Game \n";
    std::cout << "::::    2. Settings \n";
    std::cout << "::::    3. Quit \n";
    std::cout << "::::\n";
    std::cout << "::::\n";
    std::cout << "::::\n";
    std::cout << "::::\n";
    std::cout << "::::    Select Option: ";
    std::cin >> opt;
    ch_err();
}

////// SET UP FUNCTIONS AND GAMEPLAY

////// MAIN SPACE WHERE GAME INITIALIZES AND PRIMARY POLLING TAKES PLACE

int main() {
    pterm = false;
    while (true) {
        if (pterm) { break; }
    }
}
