#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void writeMatrixToFile(string filename, const vector<vector<int>> &matrix)
{

    std::ofstream file("files/" + filename);

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

void createRandMatrix(string file_name, int size)
{
    vector<vector<int>> matrix(size, vector<int>(size));

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.size(); j++)
        {
            matrix[i][j] = rand() % 500;
        }
    }
    writeMatrixToFile(file_name, matrix);
}

int main()
{
    std::initializer_list<int> SIZE = {100, 250, 500, 750, 1000, 1500, 2000};
    int index = 1;

    for (const auto &size : SIZE)
    {
        std::vector<std::vector<int>> matrix_1(size, std::vector<int>(size));
        std::vector<std::vector<int>> matrix_2(size, std::vector<int>(size));
        std::vector<std::vector<int>> matrix_res(size, std::vector<int>(size));

        createRandMatrix("matrix1_" + std::to_string(size) + ".txt", size);
        createRandMatrix("matrix2_" + std::to_string(size) + ".txt", size);

        index++;
    }
    return 0;
}