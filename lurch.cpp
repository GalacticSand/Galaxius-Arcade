#include <iostream>
#include <vector>
#include <string>

// Define necessary initial global variables
int opt;
std::vector<int> n_opt_list;
std::vector<std::string> s_opt_list;
std::string decs;
bool termin = false;
bool termin_alt = false;
bool err = false;
int bsize;
int gamemode;
std::string plrname;
std::string cpuname;
std::vector<std::vector<std::string>> plr_grid;
std::vector<std::vector<std::string>> opp_grid;

// Define the default blank grid layouts for the normal-sized grid and large-sized grid
std::vector<std::vector<std::string>> n_size_grid_t = {{"   ", "[A]", "[B]", "[C]", "[D]", "[E]", "[F]", "[G]", "[H]", "[I]", "[J]"}, 
                                                       {"01|", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )"}, 
                                                       {"02|", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )"}, 
                                                       {"03|", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )"}, 
                                                       {"04|", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )"}, 
                                                       {"05|", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )"}, 
                                                       {"06|", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )"}, 
                                                       {"07|", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )"}, 
                                                       {"08|", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )"}, 
                                                       {"09|", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )"}, 
                                                       {"10|", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )"}};
std::vector<std::vector<std::string>> l_size_grid_t = {{"   ", "[A]", "[B]", "[C]", "[D]", "[E]", "[F]", "[G]", "[H]", "[I]", "[J]", "[K]", "[L]"}, 
                                                       {"01|", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )"}, 
                                                       {"02|", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )"}, 
                                                       {"03|", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )"}, 
                                                       {"04|", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )"}, 
                                                       {"05|", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )"}, 
                                                       {"06|", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )"}, 
                                                       {"07|", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )"}, 
                                                       {"08|", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )"}, 
                                                       {"09|", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )"}, 
                                                       {"10|", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )"}, 
                                                       {"11|", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )"}, 
                                                       {"12|", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )", "( )"}};

// Defining the "Marker" class for general-use markers on the board
class Marker {
    std::string tag;
  public:
    Marker(std::string t) {
      tag = t;
    }
};

// Defining the "Ship" class for classification of ship types
class Ship {
    std::string name;
    std::string tag;
    int size;
  public:
    Ship(std::string n, std::string t, int s) {
      name = n;
      tag = t;
      size = s;
    }
};

// Define the function that will allow printing of the boards
void gen_grid(std::vector<std::vector<std::string>> g) {
  for (int i = 0; i < g.size(); i++) {
    for (int j = 0; j < g[i].size(); j++) {
      std::cout << g[i][j];
    }
    std::cout << std::endl;
  }
}

// Define the types of standard markers that will be placed on the board (blank space, miss, hit)
// Formatted marker_obj(<marker_tag>)
Marker gs_blank("( )");
Marker gs_miss("(~)");
Marker gs_hit("(#)");

// Define the ship types that will be placed on the board
// Formatted ship_obj(<ship_name>, <ship_tag>, <ship_size>)
Ship s_carr("Carrier", "(C)", 5);
Ship s_batt("Battleship", "(B)", 4);
Ship s_dest("Destroyer", "(D)", 3);
Ship s_subm("Submarine", "(S)", 3);
Ship s_ptbt("Patrol Boat", "(P)", 2);

// Some screen layout/art stuff for the title screen and other options at the main menu
void pr_titleScr() {
  system("clear");
  std::cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
  std::cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
  std::cout << ":::                                                      :::\n";
  std::cout << ":::                        _____      ____               :::\n";
  std::cout << ":::    |        |      |  |     \\    /    \\  |      |    :::\n";
  std::cout << ":::    |        |      |  |_____/   |        |______|    :::\n";
  std::cout << ":::    |        |      |  |     \\   |        |      |    :::\n";
  std::cout << ":::     \\_____   \\____/   |      |   \\____/  |      |    :::\n";
  std::cout << ":::    ______________________________________________    :::\n";
  std::cout << ":::    ______________________________________________    :::\n";
  std::cout << ":::                                                      :::\n";
  std::cout << ":::                                                      :::\n";
  std::cout << ":::               Created by GalacticSand                :::\n";
  std::cout << ":::        (c) 2020 - Galaxius Computer Software         :::\n";
  std::cout << ":::                                                      :::\n";
  std::cout << ":::                                                      :::\n";
  std::cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
  std::cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
}

void titleScr() {
  pr_titleScr();
  std::cout << "\n===== Press Enter to Start =====" << std::endl;
  std::cin.get();
}

// Allow checking for a certain option in the opt_list
bool in_opt(int ch) {
  int p = 0;
  for (int i < 0; i < n_opt_list.size(); i++) {
    if (n_opt_list[i] == ch) { p = 1; }
  }
  if (p = 1) { return true; }
  else { return false; }
}

// Define the error system that will be used to prevent the program from going ape if the user does something wrong
// I may eventually find a way to get rid of this and structure my code to prevent these errors
void r_error(int s) {
  system("clear");
  switch(s) {
    case 1 :
      std::cout << ":::    \n";
      std::cout << ":::    \n";
      std::cout << ":::    ERROR 0001\n";
      std::cout << ":::    \n";
      std::cout << ":::    \n";
      std::cout << ":::    You have selected an option which is not present in the current menu.\n";
      std::cout << ":::    Press Enter to return to The Main Menu.\n";
      std::cin.get();
      break;
    case 2 :
      break;
    default :
      break;
  }
}

// The layout for the main menu
void pr_optionScr() {
  system("clear");
  std::cout << ":::    \n";
  std::cout << ":::    \n";
  std::cout << ":::    === Lurch Main Menu ===\n";
  std::cout << ":::    \n";
  std::cout << ":::    \n";
  std::cout << ":::\t 1. Start Game\n";
  std::cout << ":::\t 2. Settings\n";
  std::cout << ":::\t 3. Credits\n";
  std::cout << ":::\t 4. Exit\n";
  std::cout << ":::    \n";
  std::cout << ":::    \n";
  std::cout << ":::    \n";
  std::cout << ":::    \n";
  std::cout << ":::    Select Option: ";
}

// Screen layouts for when starting a new game
void pr_setupGame(int n) {
  err = false;
  switch (n) {
    case 1 :
      n_opt_list = {1, 2};
      system("clear");
      std::cout << ":::    \n";
      std::cout << ":::    \n";
      std::cout << ":::    === Start New Game of Lurch ===\n";
      std::cout << ":::    \n";
      std::cout << ":::    \n";
      std::cout << ":::    Select Board Size:\n";
      std::cout << ":::\t 1. Normal (10 x 10)\n";
      std::cout << ":::\t 2. Large (12 x 12)\n";
      std::cout << ":::    \n";
      std::cout << ":::    \n";
      std::cout << ":::    \n";
      std::cout << ":::    \n";
      std::cout << ":::    Select Option: ";
      std::cin >> bsize;
      if (!in_opt(bsize)) { 
        err = true; 
        break;
      }
      // if
    case 2 :
      n_opt_list = {1, 2};
      system("clear");
      std::cout << ":::    \n";
      std::cout << ":::    \n";
      std::cout << ":::    === Start New Game of Lurch ===\n";
      std::cout << ":::    \n";
      std::cout << ":::    \n";
      std::cout << ":::    Select Gamemode:\n";
      std::cout << ":::\t 1. Target Practice\n";
      std::cout << ":::\t 2. Battle Against The CPU\n";
      std::cout << ":::    \n";
      std::cout << ":::    \n";
      std::cout << ":::    \n";
      std::cout << ":::    \n";
      std::cout << ":::    Select Option: ";
      std::cin >> gamemode;
      if (!in_opt(gamemode)) { 
        err = true; 
        break;
      }
    case 3 :
      system("clear");
      std::cout << ":::    \n";
      std::cout << ":::    \n";
      std::cout << ":::    === Start New Game of Lurch ===\n";
      std::cout << ":::    \n";
      std::cout << ":::    \n";
      std::cout << ":::    \n";
      std::cout << ":::    \n";
      std::cout << ":::    Enter your Screen Name: ";
      std::cin >> plrname;
      system("clear");
      std::cout << ":::    \n";
      std::cout << ":::    \n";
      std::cout << ":::    === Start New Game of Lurch ===\n";
      std::cout << ":::    \n";
      std::cout << ":::    \n";
      std::cout << ":::    \n";
      std::cout << ":::    \n";
      std::cout << ":::    Enter your Screen Name: " << plrname << "\n";
      std::cout << ":::    Enter your Opponent's Name: ";
      std::cin >> cpuname;
      break;
  }
}

// This prompt allows the user to redo the setup process if necessary
void pr_setupGameSure() {
  system("clear");
  std::cout << ":::    \n";
  std::cout << ":::    \n";
  std::cout << ":::    \n";
  std::cout << ":::    \n";
  std::cout << ":::    Begin Game with these settings? (Y/N): ";
  std::cin >> decs;
  if (decs == "Y" || decs == "y") { termin_alt = true; }
}

// Navigation for the game setup with additional polling in case setup needs to be redone
void setupGame() {
  while (true) {
    pr_setupGame(1);
    if (!err) { pr_setupGameSure(); }
    if (termin_alt) { break; }
  }
  termin_alt = false;
  switch(bsize) {
    case 1 :
      plr_grid = n_size_grid_t;
      opp_grid = n_size_grid_t;
      break;
    case 2 :
      plr_grid = l_size_grid_t;
      opp_grid = l_size_grid_t;
      break;
    default :
      r_error();
      break;
}

// Initializes a new game
void startGame() {
  // add code later
}

// Layout for Settings Menu
void settingScr() { }  

// Layout for Credits Screen
void creditScr() { }

// Layout for Quit Screen
void quitProg() {
  system("clear");
  std::cout << ":::    \n";
  std::cout << ":::    \n";
  std::cout << ":::    \n";
  std::cout << ":::    \n";
  std::cout << ":::    Are you sure you want to quit? (Y/N): ";
  std::cin >> decs;
  if (decs == "Y" || decs == "y") {
    termin = true;
  }
}

// Navigation for Main Menu with additional primary functions
void optionScr() {
  pr_optionScr();
  std::cin >> opt;
  switch(opt) {
    case 1 :
      setupGame();
      startGame();
      break;
    case 2 :
      break;
    case 3 :
      break;
    case 4 :
      quitProg();
      break;
    default :
      r_error(1);
      break;
  }
}

// The main code space where primary functions are laid out and the primary polling takes place
int main() {
  titleScr();
  while (true) {
    optionScr();
    if (termin) {
      system("clear");
      break;
    }
  }
}
