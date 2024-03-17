#include <iostream>
#include <fstream>
#include <vector>

void writeMatrixToFile(const std::string &filename, const std::vector<std::vector<int>> &matrix)
{
    std::ofstream file(filename);

    if (file.is_open())
    {
        for (const auto &row : matrix)
        {
            for (const int &element : row)
            {
                file << element << " ";
            }
            file << std::endl;
        }

        file.close();
        std::cout << "Matrix has been written to file: " << filename << std::endl;
    }
    else
    {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}

int main()
{
    std::vector<std::vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    std::string filename = "matrix.txt";

    writeMatrixToFile(filename, matrix);

    return 0;
}