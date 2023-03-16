#ifndef FILESYSTEM_FILESYSTEM_H
#define FILESYSTEM_FILESYSTEM_H


#include <map>
#include "Folder.h"

class FileSystem {
public:

    bool removeFolder(string path, string name);

    bool relocateFolder(string oldPath, string name, string newPath);

    FileSystem();

    bool addFolder(string path, string name, const string& date);

    virtual ~FileSystem();

    void printAll();

private:
    Folder root;
    map<string, Folder> simFolderMap;
    map<string, File> simFileMap;

};


#endif //FILESYSTEM_FILESYSTEM_H