#include <iostream>
#include "Board.h"
#include <string>
#include <iostream>

int main() {
    Board board;
    std::string s;
    board.getFenString(s);
    std::cout << s;
    std::cin.get();
}