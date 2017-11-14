#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

template<typename T>
void getInput(const char* prompt, T& varToSet)
{
    T input;
    std::cout << prompt << std::endl;

    do
    {
        std::cin >> input;

        if (std::cin.fail())
        {
            std::cout << "Invalid input! Please try again.";
            std::cin.clear();
        }
    } while (std::cin.fail());

    varToSet = input;    
}

template<typename T>
void getInput(const char* prompt, std::vector<T>& varToSet)
{
    T input;
    std::cout << prompt << std::endl;

    do
    {
        std::cin >> input;

        if (std::cin.fail())
        {
            std::cout << "Invalid input! Please try again.";
            std::cin.clear();
        }
    } while (std::cin.fail());

    varToSet.push_back(input);
}

int main(int argc, char** argv[])
{
    bool cont = false;

    do
    {
        int numOfJoints = 0;
        bool trisAreSimilar = true;
        std::vector<double>innerAngles;

        std::string firstJointVisual =
            "       ^\n"
            "      / \\\n"
            "     /   \\\n"
            "    /     \\\n"
            "   /       \\\n"
            "  /         \\\n"
            " / A         \\\n"
            " -------------\n";
        std::string secondJointVisual =
            "       ^\n"
            "      / \\\n"
            "     / B \\\n"
            "    /     \\\n"
            "   /       \\\n"
            "  /         \\\n"
            " /           \\\n"
            " -------------\n";

        getInput("How many joints are in the truss?", numOfJoints);
        
        bool anglesAreValid = true;
        do
        {
            std::cout << firstJointVisual;
            getInput("What is the angle of the first joint?", innerAngles);

            std::cout << secondJointVisual;
            getInput("What is the angle of the second joint?", innerAngles);

            if (0 > (innerAngles[0] + innerAngles[1]) || (innerAngles[0] + innerAngles[1]) > 180)
            {
                anglesAreValid = false;
            }
            else
            {
                innerAngles.push_back(180 - innerAngles[0] - innerAngles[1]);
            }
        } while (!anglesAreValid);
        
        getInput("All triangles are similar. (1 = yes / 0 = false)", trisAreSimilar);

        if (trisAreSimilar)
        {

        }
        else
        {

        }

        getInput("Calculate again? (1 = yes / 0 = no)", cont);

    } while (cont);
}