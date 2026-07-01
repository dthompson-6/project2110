#include "CampusMap.h"
#include <fstream>
#include <iostream>

using namespace std;

CampusMap::CampusMap()
{
    rows = 0;
    cols = 0;
}

bool CampusMap::loadMap(string filename)
{
    ifstream file(filename);

    if (!file)
    {
        cout << "Could not open map file." << endl;
        return false;
    }

    file >> rows >> cols;
    map.clear();

    for (int i = 0; i < rows; i++)
    {
        vector<char> rowData;

        for (int j = 0; j < cols; j++)
        {
            char spot;
            file >> spot;
            rowData.push_back(spot);
        }

        map.push_back(rowData);
    }

    file.close();
    return true;
}

void CampusMap::displayMap()
{
    cout << "Campus Map:" << endl;

    for (int i = 0; i < map.size(); i++)
    {
        for (int j = 0; j < map[i].size(); j++)
        {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}

char CampusMap::getLocation(int row, int col)
{
    if (row < 0 || row >= rows || col < 0 || col >= cols)
    {
        return '\0';
    }

    return map[row][col];
}

string CampusMap::getLocationType(int row, int col)
{
    char place = getLocation(row, col);

    if (place == 'R')
        return "Road";
    else if (place == 'B')
        return "Building";
    else if (place == 'C')
        return "Classroom";
    else if (place == 'L')
        return "Library";
    else if (place == 'P')
        return "Parking Lot";
    else if (place == 'X')
        return "Blocked Area";
    else
        return "Invalid Location";
}

bool CampusMap::isBlocked(int row, int col)
{
    return getLocation(row, col) == 'X';
}

void CampusMap::displayNeighbors(int row, int col)
{
    cout << "Neighboring Locations:" << endl;

    cout << "Up: " << getLocationType(row - 1, col) << endl;
    cout << "Down: " << getLocationType(row + 1, col) << endl;
    cout << "Left: " << getLocationType(row, col - 1) << endl;
    cout << "Right: " << getLocationType(row, col + 1) << endl;
}

void CampusMap::countObjects()
{
    int roads = 0;
    int buildings = 0;
    int classrooms = 0;
    int libraries = 0;
    int parkingLots = 0;
    int blocked = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (map[i][j] == 'R')
                roads++;
            else if (map[i][j] == 'B')
                buildings++;
            else if (map[i][j] == 'C')
                classrooms++;
            else if (map[i][j] == 'L')
                libraries++;
            else if (map[i][j] == 'P')
                parkingLots++;
            else if (map[i][j] == 'X')
                blocked++;
        }
    }

    cout << "Map Object Counts:" << endl;
    cout << "Roads: " << roads << endl;
    cout << "Buildings: " << buildings << endl;
    cout << "Classrooms: " << classrooms << endl;
    cout << "Libraries: " << libraries << endl;
    cout << "Parking Lots: " << parkingLots << endl;
    cout << "Blocked Areas: " << blocked << endl;
}