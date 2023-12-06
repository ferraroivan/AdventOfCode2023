#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

int main(int argc, char * argv[]) {

    std::string input = "input/input_day6.txt";
    std::ifstream file(input);
    std::string line;

    std::string temp = "";
    long time, distance;

    while (std::getline(file, line)) {
        
        size_t colon = line.find(':');
        std::string n;
  
        if (line.find("Time") != std::string::npos) {
            std::istringstream is(line.substr(colon + 9));
            while (is >> n) {
                temp += n;
            }
            time = std::stol(temp);
            //std::cout << time << std::endl;
            temp = "";
        } else if (line.find("Distance") != std::string::npos) {
            std::istringstream iss(line.substr(colon + 4));
            while (iss >> n) {
                temp += n;
            }
            distance = std::stol(temp);
            //std::cout << distance << std::endl;
        }        
    }

    int counter = 0;
    for (long j = 0; j < time; j++) {
        long remaining_time = time - j;
        if (remaining_time * j > distance) {
            counter++;
        }
    }
    std::cout << counter << std::endl;

    return 0;
}

// 33149631
