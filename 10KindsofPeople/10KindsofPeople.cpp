#include <iostream>
#include <string>
#include <vector>
#include <stack>


class Query {
    public:
        uint32_t r1;
        uint32_t c1;
        uint32_t r2;
        uint32_t c2;
};

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
        if (startingPoint == '0') {
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

    std::stack<std::pair<uint32_t, uint32_t>> queue;
    queue.push(std::make_pair(r1, c1));
    visited[r1][c1] = 1;

    while (!queue.empty()) {
        std::pair<uint32_t, uint32_t> current = queue.top();
        queue.pop();
        coloredWorld[current.first][current.second] = newColor;

        for (int i = 0; i < 4; i++) {
            uint32_t nextRow = current.first + delta_r[i];
            uint32_t nextColumn = current.second + delta_c[i];

            if (isValid(coloredWorld, r, c, visited, nextRow, nextColumn, targetColor)) {
                visited[nextRow][nextColumn] = 1;
                queue.push(std::make_pair(nextRow, nextColumn));
            }
        }
    }
    //printWorld(visited, r, c);
}


int main()
{
    // getting input
    uint32_t r, c;
    std::cin >> r >> c;
    std::vector<std::string> world(r, "");
    for(uint32_t i = 0; i < r; i++){
        std::cin >> world[i];
    }

    int numberOfQueries;
    std::cin >> numberOfQueries;
    std::vector<Query> queries;
    for (int i = 0; i < numberOfQueries; i++) {
        Query query;
        std::cin >> query.r1 >> query.c1 >> query.r2 >> query.c2;
        queries.push_back(query);
    }

    // actual algorithm
    uint32_t **coloredWorld = new uint32_t*[r];
    for (uint32_t row = 0; row < r; row++) {
        coloredWorld[row] = new uint32_t[c];

        for (uint32_t col = 0; col < c; col++) {
            coloredWorld[row][col] = static_cast<uint32_t>(world[row][col] - 48);
        }
    }

    // printWorld(coloredWorld, r, c);

    uint32_t startColor = 2;
    uint32_t color = startColor;

    for (Query query : queries) {
        char startingPoint = world[query.r1 - 1][query.c1 - 1];

        if (coloredWorld[query.r1 - 1][query.c1 - 1] < startColor) {
            colorArea(coloredWorld, r, c, color, query.r1 - 1, query.c1 - 1);
        }

        int firstLocation = coloredWorld[query.r1 - 1][query.c1 - 1];
        int secondLocation = coloredWorld[query.r2 - 1][query.c2 - 1];
        compare(firstLocation, secondLocation, startingPoint);

        color++;
        //printWorld(coloredWorld, r, c);
    }
}
