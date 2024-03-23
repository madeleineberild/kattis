#include <iostream>
#include <string>
#include <vector>
#include <fstream>

int main()
{
/*     std::cout << "This is 1-DFrogger (Easy)" << std::endl;
    std::cout << "-------------------------" << std::endl; */

    // getting input
    std::string configLine;
    std::string boardSquareLine;

    int numberOfBoardSquares, startSquareIndex, magicNumber;
    std::cin >> numberOfBoardSquares >> startSquareIndex >> magicNumber;

    std::vector<int> boardSquares(numberOfBoardSquares);
    for(int i = 0; i < numberOfBoardSquares; i++){
        std::cin >> boardSquares[i];
    }

    // actual algorithm
    int numberOfHops = 0;
    std::string fate = "";

    bool done = false;
    int currentIndex = startSquareIndex;
    std::vector<int> visited(boardSquares.size(), 0);
    while (!done) {
        if (currentIndex < 1) {
            fate = "left";
            done = true;
        } else if (currentIndex > numberOfBoardSquares) {
            fate = "right";
            done = true;
        } else if (boardSquares[currentIndex - 1] == magicNumber) {
            fate = "magic";
            done = true;
        } else if (visited[currentIndex]) {
            fate = "cycle";
            done = true;
        }

        if(done) {
            break;
        }

        visited[currentIndex] = 1;
        currentIndex += boardSquares[currentIndex - 1];
        numberOfHops++;
    }

    // output
    std::cout << fate << std::endl;
    std::cout << numberOfHops << std::endl;
}
