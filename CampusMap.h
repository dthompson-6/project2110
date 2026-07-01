#ifndef CAMPUSMAP_H
#define CAMPUSMAP_H

#include <vector>
#include <string>
using namespace std;

class CampusMap
{
private:
    vector<vector<char>> map;
    int rows;
    int cols;

public:
    CampusMap();

    bool loadMap(string filename);
    void displayMap();

    char getLocation(int row, int col);
    string getLocationType(int row, int col);
    bool isBlocked(int row, int col);
    void displayNeighbors(int row, int col);
    void countObjects();
};

#endif