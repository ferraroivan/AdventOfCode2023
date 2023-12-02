#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int main(int argc, char * argv[])
{
    std::string input = "../input/input_part1.txt";

    std::string line;
    std::fstream file(input);

    std::string red = "red";
    std::string blue = "blue";
    std::string green = "green";

    // ID 
    // std::string id_string;
    // std::string first_digit_id;
    // std::string second_digit_id;
    // std::string third_digit_id;

    // Red Cube Value
    std::string red_cube_string;
    std::string first_digit_red;
    std::string second_digit_red;

    // Blue Cube Value
    std::string blue_cube_string;
    std::string first_digit_blue;
    std::string second_digit_blue;

    // Green Cube Value
    std::string green_cube_string;
    std::string first_digit_green;
    std::string second_digit_green;

    char temp;

    // Total sum of IDs
    int sum = 0;
    
    // RGB cubes of each line
    int blue_cubes_int;
    int red_cubes_int;
    int green_cubes_int;

    // Max value of RGB cubes
    int red_cube_max;
    int green_cube_max;
    int blue_cube_max;

    int power;

    while (std::getline(file, line))
    {
        // Vector for positions of each cube color in a line
        std::vector<size_t> position_red_vector;
        std::vector<size_t> position_green_vector;
        std::vector<size_t> position_blue_vector;

        // Vectors for no. of RGB cubes
        std::vector<size_t> red_vector;
        std::vector<size_t> blue_vector;
        std::vector<size_t> green_vector;


        //BLUE CUBES
        //===============================
        // Search blue
        size_t pos_blue = line.find(blue);
        
        // Find all positions of blue cubes in a line
        while (pos_blue != std::string::npos)
        {
            // Position of blue cube into the map
            position_blue_vector.push_back(pos_blue);
            pos_blue = line.find(blue, pos_blue + 1);
        }

        // Iterate through the vector that hold blue cubes position in line
        for (size_t i = 0; i < position_blue_vector.size(); i++)
        {
            // consider 2 digit value per cube
            int j = position_blue_vector.at(i) - 3; 
            int counter_digit_blue = 0;

            // Check and convert blue cubes digits
            while (j < position_blue_vector.at(i))
            {
                // Parsing digits for blue cube
                if (std::isdigit(line[j]))
                {
                    counter_digit_blue++;
                    if (counter_digit_blue == 1)
                    {
                        temp = line[j];
                        first_digit_blue = temp;
                    }
                    else if (counter_digit_blue == 2)
                    {
                        temp = line[j];
                        second_digit_blue = temp;
                    }
                }
                j++;
            }

            blue_cube_string = first_digit_blue + second_digit_blue;
            blue_cubes_int = std::stoi(blue_cube_string);

            blue_vector.push_back(blue_cubes_int);

            first_digit_blue = " ";
            second_digit_blue = " ";
        }

        std::sort(blue_vector.begin(), blue_vector.end());
        
        // Last element of the vector is the biggest
        blue_cube_max = blue_vector.back();

        //GREEN CUBES
        //===============================
        // Search green
        size_t pos_green = line.find(green);

        // Find all positions of green cubes in a line
        while (pos_green != std::string::npos)
        {
            position_green_vector.push_back(pos_green);
            pos_green = line.find(green, pos_green + 1);
        }

        // Iterate through the vector that hold green cubes position in line 
        for (size_t i = 0; i < position_green_vector.size(); i++)
        {
            // Consider 2 digit value per cube
            int f = position_green_vector.at(i) - 3; 
            int counter_digit_green = 0;

            // Check and convert green cubes digits
            while (f < position_green_vector.at(i))
            {
                // Parsing digits for green cube
                if (std::isdigit(line[f]))
                {
                    counter_digit_green++;
                    if (counter_digit_green == 1)
                    {
                        temp = line[f];
                        first_digit_green = temp;
                    }
                    else if (counter_digit_green == 2)
                    {
                        temp = line[f];
                        second_digit_green = temp;
                    }
                }
                f++;
            }

            green_cube_string = first_digit_green + second_digit_green;
            green_cubes_int = std::stoi(green_cube_string); 

            green_vector.push_back(green_cubes_int);

            first_digit_green = " ";
            second_digit_green = " ";
        }

        std::sort(green_vector.begin(), green_vector.end());
        green_cube_max = green_vector.back();

        
        //RED CUBES
        //===============================
        // Search red 
        size_t pos_red = line.find(red);

        // Find all positions of red cubes in a line
        while (pos_red != std::string::npos)
        {
            position_red_vector.push_back(pos_red);
            pos_red = line.find(red, pos_red + 1);
        }

        // Iterate through the vector that hold red cubes position in line
        for (size_t i = 0; i < position_red_vector.size(); i++)
        {
            // Consider 2 digit value per cube
            int h = position_red_vector.at(i) - 3;             
            int counter_digit_red = 0;

            // Check and convert red cube digits
            while (h < position_red_vector.at(i))
            {
                // Parsing digits for red cube
                if (std::isdigit(line[h]))
                {
                    counter_digit_red++;
                    if (counter_digit_red == 1)
                    {
                        temp = line[h];
                        first_digit_red = temp;
                    }
                    else if (counter_digit_red == 2)
                    {
                        temp = line[h];
                        second_digit_red = temp;
                    }
                }
                h++;
            }

            red_cube_string = first_digit_red + second_digit_red;
            red_cubes_int = std::stoi(red_cube_string); 

            red_vector.push_back(red_cubes_int);

            first_digit_red = " ";
            second_digit_red = " ";
        }

        std::sort(red_vector.begin(), red_vector.end());
        red_cube_max = red_vector.back();

        // to compute the power
        power = red_cube_max * green_cube_max * blue_cube_max;
        sum += power;

        // Clear the vectors that hold the position of the RGB cubes
        if (position_red_vector.empty() != 0 || red_vector.empty() != 0)
        {
            position_red_vector.clear();
            red_vector.clear();
        }
        else if (position_blue_vector.empty() != 0 || blue_vector.empty() != 0)
        {
            position_blue_vector.clear();
            blue_vector.clear();
        }
        else if (position_green_vector.empty() != 0 || green_vector.empty() != 0)
        {
            position_green_vector.clear();
            green_vector.clear();
        }

        blue_cubes_int = 0;
        red_cubes_int = 0;
        green_cubes_int = 0;
    }
    
    std::cout << "IDs sum: " << sum << std::endl;
    return 0;
}

// Solution 2617
