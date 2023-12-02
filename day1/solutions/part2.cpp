#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <map>


int main(int argc, char * argv[])
{
    std::map<std::string, char> spelledDigitMap = {
        {"one", '1'},
        {"two", '2'},
        {"three", '3'},
        {"four", '4'},
        {"five", '5'},
        {"six", '6'},
        {"seven", '7'},
        {"eight", '8'},
        {"nine", '9'}
    };

    std::string input = "../input/text_part2.txt";
    std::string line;
    std::fstream file(input);

    int total = 0;
    // std::string s1;
    // std::string s2;
    // std::string str;

    while (std::getline(file, line))
    {
        char firstDigit = '\0';
        char lastDigit = '\0';

        // Iterate through each character in the string
        for (size_t i = 0; i < line.size(); ++i)
        {
            //Check if the character is a digit
            if (std::isdigit(line[i])) 
            {
                //Update the first and last digit if not set
                if (firstDigit == '\0')
                {
                    firstDigit = line[i];
                }
                lastDigit = line[i];
            }
            else 
            {
                // Check if the substring starting at the current position represents a spelled-out digit
                for (const auto& entry : spelledDigitMap)
                {
                    const std::string& spelledDigit = entry.first;
                    const char digit = entry.second;

                    if (line.compare(i, spelledDigit.size(), spelledDigit) == 0)
                    {
                        //Update the first and last digit if not set
                        if (firstDigit == '\0')
                        {
                            firstDigit = digit;
                        }
                        lastDigit = digit;

                        // Move the index to the end of the spelled-out digit
                        i += spelledDigit.size() - 1;
                        break;
                    }
                }
            }
        }

        // Check if digits were found for the current line
        if (firstDigit != '\0' && lastDigit != '\0')
        {
            // Concatenate the two dights into a pair
            std::string digitPair = std::string(1, firstDigit) + std::string(1, lastDigit);

            // Convert the digit pair to an integer and add it to the sum
            total += std::stoi(digitPair);
        }

        // str = s1 + s2;
        // total += std::stoi(str);
    }
    std::cout << total << std::endl;
    return total;
}
