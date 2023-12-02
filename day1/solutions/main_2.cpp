#include <iostream>
#include <string>
#include <fstream>
#include <cctype>

int main(int argc, char * argv[])
{
    std::string input = "../input/input_day1.txt";

    std::string line;
    std::fstream file(input);

    int sum = 0;

    std::string str;

    std::string first_digit;
    std::string last_digit;

    while (std::getline(file, line))
    {
        for (size_t i = 0; i < line.length(); i++)
        {
            if (std::isdigit(line[i]))
            {
                first_digit = line[i];
                break;
            }
            else if (line[i] == 'o' && line[i + 1] == 'n' && line[i + 2] == 'e')
            {
                first_digit = "1";
                break;
            }
            else if (line[i] == 't' && line[i + 1] == 'w' && line[i+2] == 'o')
            {
                first_digit = "2";
                break;
            }
            else if (line[i] == 't' && line[i + 1] == 'h' && line[i+2]=='r' && line[i+3] =='e' && line[i+4]=='e')
            {
                first_digit = "3";
                break;
            }
            else if (line[i] == 'f' && line[i + 1] == 'o' && line[i+2] == 'u' && line[i+3] == 'r')
            {
                first_digit = "4";
                break;
            }
            else if (line[i] == 'f' && line[i + 1] == 'i' && line[i+2] == 'v' && line[i+3] == 'e')
            {
                first_digit = "5";
                break;
            }
            else if (line[i] == 's' && line[i + 1] == 'i' && line[i+2] == 'x')
            {
                first_digit = "6";
                break;
            }
            else if (line[i] == 's' && line[i + 1] == 'e' && line[i+2] == 'v' && line[i+3] == 'e' && line[i+4] == 'n')
            {
                first_digit = "7";
                break;
            }
            else if (line[i] == 'e' && line[i + 1] == 'i' && line[i+2] == 'g' && line[i+3] == 'h' && line[i+4]=='t')
            {
                first_digit = "8";
                break;
            }
            else if (line[i] == 'n' && line[i + 1] == 'i' && line[i+2] == 'n' && line[i+3] == 'e')
            {
                first_digit = "9";
                break;
            }

        }

        for (size_t i = line.length() - 1; i >= 0; i--)
        {

            if (std::isdigit(line[i]))
            {
                last_digit = line[i];
                break;
            }
            else if (line[i] == 'e' && line[i - 1] == 'n' && line[i - 2] == 'o')
            {
                last_digit = "1";
                break;
            }
            else if (line[i] == 'o' && line[i - 1] == 'w' && line[i-2] == 't')
            {
                last_digit = "2";
                break;
            }
            else if (line[i] == 'e' && line[i - 1] == 'e' && line[i-2] == 'r' && line[i-3] == 'h' && line[i-4] == 't')
            {
                last_digit = "3";
                break;
            }
            else if (line[i] == 'r' && line[i - 1] == 'u' && line[i-2] == 'o' && line[i-3] == 'f')
            {
                last_digit = "4";
                break;
            }
            else if (line[i] == 'e' && line[i - 1] == 'v' && line[i-2] == 'i' && line[i-3] == 'f')
            {
                last_digit = "5";
                break;
            }
            else if (line[i] == 'x' && line[i - 1] == 'i' && line[i-2] == 's')
            {
                last_digit = "6";
                break;
            }
            else if (line[i] == 'n' && line[i - 1] == 'e' && line[i-2] == 'v' && line[i-3] == 'e' && line[i-4] == 's')
            {
                last_digit = "7";
                break;
            }
            else if (line[i] == 't' && line[i - 1] == 'h' && line[i-2] == 'g' && line[i-3]=='i' && line[i-4]=='e')
            {
                last_digit = "8";
                break;
            }
            else if (line[i] == 'e' && line[i - 1] == 'n' && line[i - 2] == 'i' && line[i - 3] == 'n')
            {
                last_digit = "9";
                break;
            }
 
        }
        str = first_digit + last_digit;
        sum += std::stoi(str);
        
    }
    std::cout << "Sum: " << sum << std::endl;
    return sum;
}

// 54875
