#include "CampusMap.h"
#include <fstream>
#include <iostream>

using namespace std;

CampusMap::CampusMap() {
    rows = 0;
    cols = 0;
}

bool CampusMap::loadMap(string filename) {
    ifstream file(filename);

    if (!file) {
        cout << "Could not open map file.\n";
        return false;
    }

    file >> rows >> cols;
    map.clear();

    for (int i = 0; i < rows; i++) {
        vector<char> row;
        for (int j = 0; j < cols; j++) {
            char c;
            file >> c;
            row.push_back(c);
        }
        map.push_back(row);
    }

    return true;
}

void CampusMap::displayMap() {
    for (auto &row : map) {
        for (char c : row) {
            cout << c << " ";
        }
        cout << endl;
    }
}

char CampusMap::getLocation(int r, int c) {
    if (r < 0 || r >= rows || c < 0 || c >= cols) return '\0';
    return map[r][c];
}

string CampusMap::getLocationType(int r, int c) {
    char x = getLocation(r, c);

    switch (x) {
        case 'R': return "Road";
        case 'B': return "Building";
        case 'C': return "Classroom";
        case 'L': return "Library";
        case 'P': return "Parking";
        case 'X': return "Blocked";
        default: return "Invalid";
    }
}

bool CampusMap::isBlocked(int r, int c) {
    return getLocation(r, c) == 'X';
}

void CampusMap::displayNeighbors(int r, int c) {
    cout << "Up: " << getLocationType(r - 1, c) << endl;
    cout << "Down: " << getLocationType(r + 1, c) << endl;
    cout << "Left: " << getLocationType(r, c - 1) << endl;
    cout << "Right: " << getLocationType(r, c + 1) << endl;
}

void CampusMap::countObjects() {
    int r=0,b=0,c=0,l=0,p=0,x=0;

    for (auto &row : map) {
        for (char ch : row) {
            if (ch=='R') r++;
            else if (ch=='B') b++;
            else if (ch=='C') c++;
            else if (ch=='L') l++;
            else if (ch=='P') p++;
            else if (ch=='X') x++;
        }
    }

    cout << "Roads: " << r << endl;
    cout << "Buildings: " << b << endl;
    cout << "Classrooms: " << c << endl;
    cout << "Libraries: " << l << endl;
    cout << "Parking: " << p << endl;
    cout << "Blocked: " << x << endl;
}