#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <algorithm>
#include <map>
#include <tuple>

int min_position_spelled_digit(std::string s)
{
    std::map<int, std::string> m1;
    std::string num[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    for (int i = 0; i < sizeof(num); i++)
    {
        // Find the position of the spelled digit in the line
        int found = s.find(num[i]);
        std::string temp = num[i];

        if (found != std::string::npos)
        {
            // Insert in the map where the spelled digit is found, and the spelled digit
            m1[found] = temp;
        }
    }

    int min = m1.begin()->first; // min position of spelled digit in line

    return min;
}

std::string spelled_digit_in_min_position(std::string s)
{
    std::map<int, std::string> m1;
    std::string num[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    for (int i = 0; i < sizeof(num); i++)
    {
        // Find the position of the spelled digit in the line
        int found = s.find(num[i]);
        std::string temp = num[i];

        if (found != std::string::npos)
        {
            // Insert in the map where the spelled digit is found, and the spelled digit
            m1[found] = temp;
        }
    }
    std::string digit = m1.begin()->second; // spelled digit in string format

    return digit;
}

int max_position_spelled_digit(std::string s)
{
    std::map<int, std::string> m1;
    std::string num[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    for (int i = 0; i < sizeof(num); i++)
    {
        // Find the position of the spelled digit in the line
        int found = s.find(num[i]);

        std::string temp = num[i];

        if (found != std::string::npos)
        {
            // Insert in the map where the spelled digit is found, and the spelled digit
            m1[found] = temp;
        }
    }

    int max = m1.rbegin()->first; // max position of spelled digit in line

    return max;
}

std::string spelled_digit_in_max_position(std::string s)
{
    std::map<int, std::string> m1;
    std::string num[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    for (int i = 0; i < sizeof(num); i++)
    {
        // Find the position of the spelled digit in the line
        int found = s.find(num[i]);

        std::string temp = num[i];

        if (found != std::string::npos)
        {
            // Insert in the map where the spelled digit is found, and the spelled digit
            m1[found] = temp;
        }
    }

    std::string digit = m1.rbegin()->second; // spelled digit in string format

    return digit; 
}

int conversion_to_int(std::string s)
{
    std::map<std::string, int> numbers {{"one", 1},{"two", 2},{"three", 3},{"four", 4},{"five", 5},{"six", 6},{"seven", 7},{"eight", 8},{"nine", 9}};

    return numbers[s];
}

bool is_spelled_digit(std::string s)
{
    std::map<std::string, int> numbers {{"one", 1},{"two", 2},{"three", 3},{"four", 4},{"five", 5},{"six", 6},{"seven", 7},{"eight", 8},{"nine", 9}};
    
    if (numbers[s])
    {
        return true;
    }
    
    return false;
}

int spelled_digit(std::string s)
{
    // Conversion from spelled_digit to digit
    std::map<std::string, int> myMap {{"one", 1},{"two", 2},{"three", 3},{"four", 4},{"five", 5},{"six", 6},{"seven", 7},{"eight", 8},{"nine", 9}};
    int value = myMap.at(s);

    // Position

}

int main(int argc, char * argv[])
{
    std::string input = "../input/test_part2.txt";

    std::string line;
    std::fstream file(input);

    int total = 0;
    int first_digit;
    int second_digit;
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

            int min_position = min_position_spelled_digit(line);
            std::string digit = spelled_digit_in_min_position(line);

            if (std::isdigit(arr1[i]) || is_spelled_digit(line))
            {
                if (i < min_position)
                {
                    s1 = arr1[i]; 
                    std::cout << "Left to right1: " << s1 << std::endl;
                    break;
                }
                else if (i > min_position)
                {
                    first_digit = conversion_to_int(digit);
                    std::cout << "Left to right2: " << first_digit << std::endl;
                    s1 = std::to_string(first_digit); 
                    break;
                }
            }
            else if (!(std::isdigit(arr1[i])) && is_spelled_digit(line))
            {
                first_digit = conversion_to_int(digit);
                std::cout << "Left to right3: " << first_digit << std::endl;
                s1 = std::to_string(first_digit);
                break;
            }
        }

        // Right to left
        for (int i = line.size() - 1; i >= 0; i--)
        {
            std::strcpy(arr2, line.c_str());       

            int max_position = max_position_spelled_digit(line);
            std::string digit = spelled_digit_in_max_position(line);

            if (std::isdigit(arr2[i]) || is_spelled_digit(line))
            {
                if (i > max_position)
                {
                    s2 = arr2[i];
                    std::cout << "Right to left1: " << s2 << std::endl;
                    break;
                }
                else if (i < max_position)
                {
                    second_digit = conversion_to_int(digit);
                    std::cout << "Right to left2: " << second_digit << std::endl;
                    s2 = std::to_string(second_digit);
                    break;
                }
            }
            else if (!(std::isdigit(arr2[i])) && is_spelled_digit(line))
            {
                second_digit = conversion_to_int(digit);
                std::cout << "Right to left2: " << second_digit << std::endl;
                s2 = std::to_string(second_digit);
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

/*
if isdigit or is_spelled_digit

*/
