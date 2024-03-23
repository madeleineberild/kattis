#include <iostream>
#include <string>
#include <vector>
#include <stack>


class Query {
    public:
        int r1;
        int c1;
        int r2;
        int c2;
};

void colorTheWorld(std::vector<std::vector<int>> &coloredWorld) {
    std::stack<std::pair<int, int>> queue;
// Flood-fill (node):
//  1. If node is not Inside return.
//  2. Set the node
//  3. Perform Flood-fill one step to the south of node.
//  4. Perform Flood-fill one step to the north of node
//  5. Perform Flood-fill one step to the west of node
//  6. Perform Flood-fill one step to the east of node
//  7. Return.
}

int main()
{
    // getting input
    int r, c;
    std::cin >> r >> c;
    std::vector<std::string> world(r, "");
    for(int i = 0; i < r; i++){
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
    std::vector<std::vector<int>> coloredWorld;
    for (std::string row : world) {
        std::vector<int> temp;
        for (char col : row) {
            temp.push_back((int)col);
        }
        coloredWorld.push_back(temp);
    }

    colorTheWorld(coloredWorld);

    for (Query query : queries) {
        char startingPoint = world[query.r1 - 1][query.c1 - 1];

        int coloredFirstLocation = coloredWorld[query.r1 - 1][query.c1 - 1];
        int coloredSecondLocation = coloredWorld[query.r2 - 1][query.c2 - 1];

        if (coloredFirstLocation != coloredSecondLocation) {
            std::cout << "neither" << std::endl;
        } else {
            if (startingPoint == '0') {
                std::cout << "binary" << std::endl;
            } else {
                std::cout << "decimal" << std::endl;
            }
        }
    }
}
