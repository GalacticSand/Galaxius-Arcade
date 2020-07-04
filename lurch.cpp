#include <iostream>
#include <vector>
#include <string>

void pr_titleScr() {
  system("clear");
  std::cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
  std::cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
  std::cout << ":::                                                      :::\n";
  std::cout << ":::                        ______     ____               :::\n";
  std::cout << ":::    |        |      |  |      |   /    \\  |      |    :::\n";
  std::cout << ":::    |        |      |  |_____/   |        |______|    :::\n";
  std::cout << ":::    |        |      |  |     \\   |        |      |    :::\n";
  std::cout << ":::    |______   \\____/   |      |   \\____/  |      |    :::\n";
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

void go_titleScr() {
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

void go_optionScr() {
  int opt;
  pr_optionScr();
  std::cin >> opt;
  switch(opt) {
    case 1 :
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
  go_titleScr();
  while (true) {
    go_optionScr();
    break;
  }
}
