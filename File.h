#ifndef FILESYSTEM_FILE_H
#define FILESYSTEM_FILE_H
#include <string>
using namespace std;


class File {
    string _path;
    string _name;
    string _createDate;
    string _changeDate;

public:

    bool operator==(const File &rhs) const;

    bool operator!=(const File &rhs) const;

    const string &getName() const;

    void setName(const string &name);

    const string &getCreateDate() const;

    const string &getChangeDate() const;

    void relocate(const string &changeDate);

    File(string path, string name, const string& createDate);

    virtual ~File();

    bool operator==(const string &rhs) const;

    bool operator!=(const string &rhs) const;

    void print(string& tab);
};


#endif //FILESYSTEM_FILE_H