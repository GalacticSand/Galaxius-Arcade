#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

////// SET UP PRIMARY GLOBAL VARIABLES AND SETS

bool pterm;                    // TERMINATOR FOR MAIN POLLING
bool pterm_alt;                // TERMINATOR FOR ANY SECONDARY POLLINGS
int opt;                       // STORES USER-CHOSEN OPTION AT SELECTION MENUS
std::vector<int> opt_list;     // STORES THE LEGAL SELECTION OF OPTIONS AT A GIVEN PROMPT

int grid_size;                 // STORES THE SIZE OF THE BOARD   - 1. NORMAL SIZE (7 x 7), 2. LARGE SIZE (9 x 9)
int game_mode;                 // STORES THE GAMEMODE            - 1. COMPUTER MULTIPLAYER, 2. VERSUS MULTIPLAYER

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
};

// INDIVIDUAL MARKER TYPES
Marker mk_b("NULL", "[ ]");        // MARKER FOR BLANK SPACE
Marker mk_r("red", "[R]");         // MARKER FOR RED CHIP
Marker mk_y("yellow", "[Y]");      // MARKER FOR YELLOW CHIP

// GRID SIZE TYPES
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
                                                 {"|_|", "   ", "   ", "|_|", "   ", "   ", "|_|"}};
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
                                                 {"|_|", "   ", "   ", "   ", "|_|", "   ", "   ", "   ", "|_|"}};

// RENDERING FOR GAME BOARDS
void ren_grid() {
    for (int i = 0; i < a_grid.size(); i++) {
        std::cout << "::::\t";
        for (int j = 0; j < a_grid[i].size(); j++) {
            std::cout << a_grid[i][j];
        }
        std::cout << "\t::::" << std::endl;
    }
}

////// MAIN SPACE WHERE GAME INITIALIZES AND PRIMARY POLLING TAKES PLACE

int main() {
    pterm = false;
    while (true) {
        if (pterm) { break; }
    }
}
