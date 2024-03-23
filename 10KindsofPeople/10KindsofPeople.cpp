#include <iostream>
#include <string>
#include <vector>

class Query {
    public:
        int r1;
        int c1;
        int r2;
        int c2;
};

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
    for (Query query : queries) {
        char firstLocation = world[query.r1 - 1][query.c1 - 1];
        char secondLocation = world[query.r2 - 1][query.c2 - 1];

        if (firstLocation != secondLocation) {
            std::cout << "neither" << std::endl;
        }

        // find way between the points, or not
    }
}
