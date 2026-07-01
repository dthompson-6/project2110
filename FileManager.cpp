#include "FileManager.h"
#include <fstream>
#include <iostream>

using namespace std;

bool FileManager::loadCampusMap(const string& filename,
       vector<vector<char>>& campusMap,
  int& rows,
  int& cols)
{
    ifstream inputFile(filename);

    if (!inputFile.is_open())
    {
        cout << "Error: Could not open file." << endl;
        return false;
    }

    inputFile >> rows >> cols;

    campusMap.resize(rows, vector<char>(cols));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            inputFile >> campusMap[i][j];
        }
    }

    inputFile.close();
    return true;
}

