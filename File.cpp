#include "File.h"

#include <utility>
#include <iostream>

File::File(string path, string name, const string& createDate) : _name(std::move(name)), _createDate(createDate),
                                                                 _changeDate(createDate),
                                                                 _path(std::move(path)){}

File::~File() {
    _name.erase();
    _createDate.erase();
    _changeDate.erase();
}

const string &File::getName() const {
    return _name;
}

void File::setName(const string &name) {
    File::_name = name;
}

const string &File::getCreateDate() const {
    return _createDate;
}


const string &File::getChangeDate() const {
    return _changeDate;
}

void File::relocate(const string &changeDate) {
    File::_changeDate = changeDate;
}

bool File::operator==(const File &rhs) const {
    return _path == rhs._path &&
           _name == rhs._name;
}

bool File::operator!=(const File &rhs) const {
    return !(rhs == *this);
}

bool File::operator==(const string &rhs) const {
    return this->_name == rhs;
}

bool File::operator!=(const string &rhs) const {
    return this->_name != rhs;
}

void File::print(string& tab) {
    cout << tab+" " <<"folder "<< _name << ", "<< _path << ", "<< _createDate << ", " << _changeDate << endl;
}
