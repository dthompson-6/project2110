#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include "StudentList.h"

class FileManager {
public:
    bool loadStudents(const std::string& filename, StudentList& list);

    bool saveStudent(const std::string& filename, const Student& s);

    bool saveAllStudents(const std::string& filename, StudentList& list);
};

#endif