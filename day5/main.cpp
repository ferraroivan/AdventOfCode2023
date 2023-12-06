#include <iostream>
#include <vector>
#include <fstream>
#include <vector>
#include <sstream>
#include <unordered_map>

struct Map {
    int from;
    int to;
    int length;
};

int apply_map(int number, const Map &map) {
    if (number >= map.from && number < map.from + map.length) {
        int offset = number - map.from;
        return map.to + offset;
    } else {
        return number;
    }
}

int main(int argc, char * argv[]) {
    std::ifstream file("input/input_day5.txt");

    if (!file.is_open()) {
        std::cerr << "Error opening the file." << std::endl;
        return 1;
    }

    std::string line;
    std::getline(file, line);

    std::vector<int> seed_values;
    int seed;
    while (file >> seed) {
        seed_values.push_back(seed);
    }

    std::unordered_map<std::string, Map> category_map;
    while (std::getline(file, line)) {
        if (line.empty()) {
            continue;
        }
        if (line.find("map") != std::string::npos) {
            std::istringstream iss(line);
            std::string category;
            iss >> category;
            Map map;
            iss >> map.to >> map.from >> map.length;
            category_map[category] = map;
        }
    }

    file.close();

    int lowest_location = std::numeric_limits<int>::max();
    for (int seed : seed_values) {
        int current = seed;
        for (const auto &entry : category_map) {
            current = apply_map(current, entry.second);
        }
        if (current < lowest_location) {
            lowest_location = current;
        }
    }

    std::cout << "Lowest Location Number: " << lowest_location << std::endl;

    return 0;
}
