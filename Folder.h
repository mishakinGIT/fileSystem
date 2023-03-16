#ifndef FILESYSTEM_FOLDER_H
#define FILESYSTEM_FOLDER_H
#include <string>
#include <vector>
#include "File.h"

using namespace std;


class Folder {
    string _name;
    string _path;
    string _createDate;
    string _changeDate;

    vector<Folder> folders;
    vector<File> files;

public:
    const string &getName() const;

    virtual ~Folder();

    void setName(const string &name);

    const string &getPath() const;

    void relocate(const string &path);

    const string &getCreateDate() const;

    void addFolder(const Folder& folder);

    void print(string& tab);

    const string &getChangeDate() const;

    void setChangeDate(const string &changeDate);

    bool createFolder(string &name, const string &createDate);
    bool createFile(string &name, const string &createDate);

    bool removeFolder(string& name);
    bool removeFile(string& name);

    bool findFolder(string& name);
    bool findFile(string& name);

    Folder* getFolder(string& name);
    Folder* getFile(string& name);



    Folder(string name, string path, const string &createDate);

    bool operator==(const Folder &rhs) const;

    bool operator==(const string& name2) const;

    bool operator!=(const Folder &rhs) const;

    bool operator!=(const string& name2) const;


};


#endif //FILESYSTEM_FOLDER_H