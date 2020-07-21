#include <iostream>
#include <vector>
#include <string>

// SET UP PRIMARY GLOBAL VARIABLES AND SETS

bool pterm;          // TERMINATOR FOR MAIN POLLING
bool pterm_alt;      // TERMINATOR FOR ANY SECONDARY POLLINGS
int opt;             // STORES USER-CHOSEN OPTION AT SELECTION MENUS

// SET UP SPRITES AND GRAPHICAL ITEMS

std::string m_blank = "[ ]";      // 
std::string m_rs = "[R]";         // 
std::string m_ys = "[Y]";         // 

std::vector<int> opt_list;
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
                                                 {"---", "---", "---", "---", "---", "---", "---", "---", "---"}, 
                                                 {"|_|", "   ", "   ", "   ", "|_|", "   ", "   ", "   ", "|_|"}};

// MAIN SPACE WHERE GAME INITIALIZES AND PRIMARY POLLING TAKES PLACE

int main() {
    pterm = false;
    while (true) {
        if (pterm) { break; }
    }
}
