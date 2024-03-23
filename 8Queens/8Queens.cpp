#include <iostream>
#include <string>
#include <vector>

bool diagonal(int x1, int x2, int y1, int y2) {
    return x1 - x2 == y1 - y2 || x1 - x2 == y2 - y1;
}

bool straight(int x1, int x2, int y1, int y2) {
    return x1 == x2 || y1 == y2;
}

int main()
{
    // getting input
    std::vector<std::string> board(8, "");
    for(int i = 0; i < 8; i++){
        std::cin >> board[i];
    }

    std::vector<int> xQueens;
    std::vector<int> yQueens;
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            if (board[y][x] == '*') {
                xQueens.push_back(x);
                yQueens.push_back(y);
            }
        }
    }

    // actual algorithm
    bool valid = true;
    for (int queen = 0; queen < 8; queen++) {
        for (int otherQueen = 0; otherQueen < 8; otherQueen++) {
            if (queen == otherQueen) {
                continue;
            }

            if (diagonal(xQueens[queen], xQueens[otherQueen], yQueens[queen], yQueens[otherQueen])
                || straight(xQueens[queen], xQueens[otherQueen], yQueens[queen], yQueens[otherQueen])) {
                valid = false;
                break;
            }
        }
    }

    // output
    if (valid) {
        std::cout << "valid" << std::endl;
    } else {
        std::cout << "invalid" << std::endl;
    }
}
