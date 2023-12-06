#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

int main(int argc, char * argv[]) {

    std::string input = "input/input_day6.txt";
    std::ifstream file(input);
    std::string line;

    std::vector<int> time;
    std::vector<int> distance;
    std::vector<int> results;
    auto product = 1;

    while (std::getline(file, line)) {
        
        size_t colon = line.find(':');
        int n = 0;

        if (line.find("Time") != std::string::npos) {
            std::istringstream is(line.substr(colon + 9));
            while (is >> n) {
                time.push_back(n);   
            }
        } else if (line.find("Distance") != std::string::npos) {
            std::istringstream iss(line.substr(colon + 4));
            while (iss >> n) {
                distance.push_back(n);
            }
        }        
    }

    int counter = 0;
    for (size_t i = 0; i < time.size(); i++) {
        for (int j = 0; j < time[i]; j++) {
            int remaining_time = time[i] - j;
            if (remaining_time * j > distance[i]) {
                counter++;
            }
        }
        results.push_back(counter);
        counter = 0;
    }

    std::cout << "Results: ";
    for (const auto &r : results) {
        std::cout << r << " ";
        product *= r;
    }

    std::cout << std::endl;
    std::cout << "Product: " << product << std::endl;

    return 0;
}
