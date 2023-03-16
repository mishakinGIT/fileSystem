#include "Folder.h"

#include <utility>
#include <algorithm>
#include <iostream>

const string &Folder::getName() const {
    return _name;
}

void Folder::setName(const string &name) {
    Folder::_name = name;
}

const string &Folder::getPath() const {
    return _path;
}

void Folder::relocate(const string &path) {
    Folder::_path = path;
}

const string &Folder::getCreateDate() const {
    return _createDate;
}


const string &Folder::getChangeDate() const {
    return _changeDate;
}

void Folder::setChangeDate(const string &changeDate) {
    Folder::_changeDate = changeDate;
}

bool Folder::createFolder(string &name, const string &createDate) {
    auto* folder = new Folder(name, _path  +  _name + "/", createDate);
    if(find(folders.begin(), folders.end(), *folder) != folders.end()){
        return false;
    }
    folders.emplace_back(*folder);
    cout<<"folder created: "<< folder->_name << endl;
    return true;
}





Folder::Folder(string name, string path, const string &createDate) : _name(std::move(name)), _path(std::move(path)),
                                                                     _createDate(createDate),
                                                                     _changeDate(createDate){}

bool Folder::operator==(const Folder &rhs) const {
    return _name == rhs._name &&
           _path == rhs._path;
}

bool Folder::operator==(const string &name2) const {
    return this->_name == name2;
}

bool Folder::operator!=(const Folder &rhs) const {
    return !(rhs == *this);
}

bool Folder::createFile(string &name, const string &createDate) {
    File *file = new File(_path, _name, createDate);
    if(find(files.begin(), files.end(), *file) != files.end()){
        delete file;
        return false;
    }
    files.emplace_back(*file);
    return true;
}

bool Folder::operator!=(const string &name2) const {
    return !(this->_name == name2);
}

Folder::~Folder() {
    _name.erase();
    _path.erase();
    _changeDate.erase();
    _createDate.erase();
    files.clear();
    files.shrink_to_fit();

    folders.clear();
    folders.shrink_to_fit();
}

bool Folder::removeFolder(string& name) {
    for(auto it = folders.begin(); it!= folders.end(); ++it){
        if(*it == name){
            folders.erase(it);
            return true;
        }
    }
    return false;
}

bool Folder::removeFile(string &name) {
    for(auto it = files.begin(); it!=files.end(); ++it){
        if(*it == name){
            files.erase(it);
            return true;
        }

    }
    return false;
}

bool Folder::findFolder(string &name) {
    for(auto & folder : folders){
        if(folder == name){

            return true;
        }
    }
    return false;
}

bool Folder::findFile(string &name) {
    for(auto it = files.begin(); it!=files.end(); ++it){
        if(*it == name){

            return true;
        }

    }
    return false;
}

Folder *Folder::getFolder(string &name) {
    for(auto & folder : folders){
        if(folder == name){

            return &folder;
        }
    }
    return nullptr;
}

Folder *Folder::getFile(string &name) {
    for(auto & folder : folders){
        if(folder == name){

            return &folder;
        }
    }
    return nullptr;
}

void Folder::addFolder(const Folder& folder) {
    folders.emplace_back(folder);
}

void Folder::print(string &tab) {
    cout <<tab <<"folder "<< _name << ", "<< _path << ", "<< _createDate << ", " << _changeDate << endl;
    for( auto it: files){
        it.print(tab);
    }
    tab = tab + " ";
    for(auto it: folders){

        it.print(tab);
    }
}