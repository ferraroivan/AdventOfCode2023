#include <iostream>
#include <string>
#include <fstream>
#include <cctype>

int main(int argc, char * argv[])
{
    std::string input = "../input/input_day1.txt";

    std::string line;
    std::fstream file(input);

    int total = 0;
    std::string s1;
    std::string s2;
    std::string str;

    while (std::getline(file, line))
    {
        
        // Inizialize array
        char arr1[line.length() + 1];
        char arr2[line.length() + 1];

        // Left to right 
        for (int i = 0; i < line.size(); i++)
        {
            // Copy string converted in char to arr1
            std::strcpy(arr1, line.c_str());

            // Check digit in string
            if (std::isdigit(arr1[i]))
            {
                s1 = arr1[i];
                std::cout << "Left to right: " << s1 << std::endl;
                break;
            }
        }

        // Right to left
        for (int i = line.size() - 1 ; i >=0 ; i--)
        {
            // Copy string converted in char to arr2
            std::strcpy(arr2, line.c_str());

            // Check digit in string
            if (std::isdigit(arr2[i]))
            {
                s2 = arr2[i];
                std::cout << "Right to left: " << s2 << std::endl;
                break;
            }
        }

        // Concatenate the 2 digits
        str = s1 + s2;

        std::cout << "Concatenated: " << str << std::endl;

        total += std::stoi(str);
        std::cout << total << std::endl;
    }
    std::cout << total << std::endl;
    return total;
}

// Solution: 55538
