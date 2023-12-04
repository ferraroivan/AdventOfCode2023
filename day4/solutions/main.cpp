#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

struct Cards {
    std::vector<int> v1;
    std::vector<int> v2;
    int wins = 0;
    int copies = 1;
};

std::vector<Cards> cards;

void read_data(const std::string &filename) {
    // Open the input file
    std::ifstream file(filename);
    std::string line;

    // Reach each line from the file
    while (std::getline(file, line)) {

        // Add a new instance of Cards to the cards vector
        cards.push_back(Cards());

        // Reference to the last added Cards instance
        auto &sc = cards.back();

        // Find positions of colon and bar in the line
        auto colon = line.find(':');
        auto bar = line.find('|');
        auto n = 0;

        // Extract numbers between colon and bar, store in v1
        std::istringstream is(line.substr(colon + 1, bar - colon - 1));
        while (is >> n) {
            sc.v1.push_back(n);
        }

        // Extract numbers after the bar, store in v2
        is = std::istringstream(line.substr(bar + 1));
        while (is >> n) {
            sc.v2.push_back(n);

            // Check if the number is in v1; if so increment wins
            if (find(sc.v1.begin(), sc.v1.end(), n) != sc.v1.end()) {
                sc.wins++;
            }
        }
    }
}

auto do_part1() {
    auto total = 0;

    for (auto &c : cards) {
        if (c.wins) {

            // Left bitwise operation of 1 bit
            // Calculate powers of 2
            total += 1 << (c.wins - 1);
        }
    }
    return total;
}

auto do_part2() {
    for (auto i = 0; i < cards.size(); i++) {
        for (auto j = 1; j <= cards[i].wins; j++) {

            // cards[0 + 1].copies += cards[0].copies
            cards[i + j].copies += cards[i].copies;
        }
    }
    
    auto total = 0;

    for (auto &sc : cards) {
        total += sc.copies;
    }

    return total;
}

int main(int argc, char * argv[]) {
    read_data("../input/input_day4.txt");

    auto part1 = do_part1();
    std::cout << "Part 1: " << part1 << std::endl;

    auto part2 = do_part2();
    std::cout << "Part 2: " << part2 << std::endl;

    return 0;
}
