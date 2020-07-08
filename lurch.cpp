#include <iostream>
#include <vector>
#include <string>

// Define necessary initial global variables
int opt;
std::string decs;
bool termin;
bool termin_alt = false;

// Define the default blank grid layouts for the normal-sized grid and large-sized grid
int bsize;
int gamemode;
std::string plrname;
std::string cpuname;
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

// Set the markers for blank space, miss, and hit
std::string gs_blank = "( )";
std::string gs_miss = "(~)";
std::string gs_hit = "(#)";

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

// Define the ship types that will be placed on the board
// Formatted (<ship_name>, <ship_tag>, <ship_size>)
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
  switch (n) {
    case 1 :
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
    case 2 :
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

void pr_setupGameSure() {
  system("clear");
  std::cout << ":::    \n";
  std::cout << ":::    \n";
  std::cout << ":::    \n";
  std::cout << ":::    \n";
  std::cout << ":::    Begin Game with these settings? (Y/N): ";
  std::cin >> decs;
  if (decs == "Y" || decs == "y") { termin_alt = true; }

void setupGame() {
  while (true) {
    pr_setupGame(1);
    pr_setupGameSure();
    if (termin_alt) { break; }
  }
}

void startGame() {
  // add code later
}

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
      break;
  }
}

// The main code space where primary functions are laid out and polling takes place
int main() {
  titleScr();
  termin = false;
  while (true) {
    optionScr();
    if (termin) {
      system("clear");
      break;
    }
  }
}
