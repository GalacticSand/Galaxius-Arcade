#include <iostream>
#include <vector>
#include <string>

int opt;
std::string decs;

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
  std::cout << ":::       (c)2018-2020 Galaxius Computer Software        :::\n";
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

int bsize;
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
std::string gs_blank = "( )";
std::string gs_miss = "( )";
std::string gs_hit = "( )";

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
      bsize = opt;
    case 2 :
      system("clear");
      std::cout << ":::    \n";
      std::cout << ":::    \n";
      std::cout << ":::    === Start New Game of Lurch ===\n";
      std::cout << ":::    \n";
      std::cout << ":::    \n";
      std::cout << ":::    
    case 3 :
      // add code later
      break;
  }
}

void setupGame() {
  pr_setupGame(1);
}

void startGame() {
  // add code later
}

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
      break;
    default :
      break;
  }
}

int main() {
  titleScr();
  while (true) {
    optionScr();
    break;
  }
}
