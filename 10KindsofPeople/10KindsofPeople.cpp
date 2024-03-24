#include <iostream>
#include <string>
#include <stack>


void printWorld(uint32_t **world, uint32_t rows, uint32_t cols) {
    std::cout << "------------" << std::endl;
    for(uint32_t row = 0; row < rows; row++) {
        for(uint32_t col = 0; col < cols; col++) {
            std::cout << world[row][col];
        }
        std::cout << std::endl;
    }
    std::cout << "------------" << std::endl;
}

void compare(uint32_t firstLocation, uint32_t secondLocation, char startingPoint) {
    if (firstLocation != secondLocation) {
        std::cout << "neither" << std::endl;
    } else {
        if (startingPoint == 0) {
            std::cout << "binary" << std::endl;
        } else {
            std::cout << "decimal" << std::endl;
        }
    }
}

bool isValid(uint32_t **coloredWorld, uint32_t r, uint32_t c, uint32_t **visited, uint32_t row, uint32_t column, uint32_t targetColor) {
    if (row < 0 || row >= r) {
        return false;
    }
    if (column < 0 || column >= c) {
        return false;
    }
    if (coloredWorld[row][column] != targetColor || visited[row][column]) {
        return false;
    }
    return true;
}

void colorArea(uint32_t **coloredWorld, uint32_t r, uint32_t c, uint32_t newColor, uint32_t r1, uint32_t c1) {
    int delta_c[4] = {1, -1, 0, 0};
    int delta_r[4] = {0, 0, 1, -1};
    uint32_t targetColor = coloredWorld[r1][c1];

    uint32_t **visited = new uint32_t*[r];
    for (uint32_t row = 0; row < r; row++) {
        visited[row] = new uint32_t[c];

        for (uint32_t col = 0; col < c; col++) {
            visited[row][col] = 0;
        }
    }

    std::stack<std::pair<uint32_t, uint32_t> *> queue;
    std::pair<uint32_t, uint32_t> *pair = new std::pair<uint32_t, uint32_t>(r1, c1);
    queue.push(pair);
    visited[r1][c1] = 1;

    while (!queue.empty()) {
        std::pair<uint32_t, uint32_t> *current = queue.top();
        queue.pop();
        coloredWorld[current->first][current->second] = newColor;

        for (int i = 0; i < 4; i++) {
            uint32_t nextRow = current->first + delta_r[i];
            uint32_t nextColumn = current->second + delta_c[i];

            if (isValid(coloredWorld, r, c, visited, nextRow, nextColumn, targetColor)) {
                visited[nextRow][nextColumn] = 1;
                std::pair<uint32_t, uint32_t> *newPair = new std::pair<uint32_t, uint32_t>(nextRow, nextColumn);
                queue.push(newPair);
            }
        }
        delete current;
    }

    for (uint32_t i = 0; i < r; i++) {
        delete[] visited[i];
    }
    delete[] visited;
}


int main()
{
    uint32_t r, c;
    std::cin >> r >> c;

    uint32_t **world = new uint32_t*[r];
    uint32_t **coloredWorld = new uint32_t*[r];
    for (uint32_t row = 0; row < r; row++) {
        coloredWorld[row] = new uint32_t[c];
        world[row] = new uint32_t[c];
        std::string temp;
        std::cin >> temp;

        for (uint32_t col = 0; col < c; col++) {
            uint32_t digit = static_cast<uint32_t>(temp[col] - 48);
            coloredWorld[row][col] = digit;
            world[row][col] = digit;
        }
    }

    uint32_t startColor = 2;
    uint32_t color = startColor;
    uint32_t r1, c1, r2, c2;

    int numberOfQueries;
    std::cin >> numberOfQueries;

    for (int i = 0; i < numberOfQueries; i++) {
        std::cin >> r1 >> c1 >> r2 >> c2;

        char startingPoint = world[r1 - 1][c1 - 1];

        if (coloredWorld[r1 - 1][c1 - 1] < startColor) {
            colorArea(coloredWorld, r, c, color, r1 - 1, c1 - 1);
        }

        int firstLocation = coloredWorld[r1 - 1][c1 - 1];
        int secondLocation = coloredWorld[r2 - 1][c2 - 1];
        compare(firstLocation, secondLocation, startingPoint);

        color++;
        // printWorld(coloredWorld, r, c);
        // printWorld(world, r, c);
    }
}
