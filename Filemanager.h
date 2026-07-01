#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <vector>
#include <string>

class FileManager {
public:
    bool loadCampusMap(const std::string& filename,
                       std::vector<std::vector<char>>& campusMap,
                       int& rows,
                       int& cols);
};

#endif
