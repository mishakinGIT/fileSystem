#include "FileSystem.h"

#include <utility>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp> // Include boost::for is_any_of
using namespace std;
#include <iostream>


FileSystem::FileSystem() : root("root", "", "time"){
}

FileSystem::~FileSystem() {
    delete &root;
}

bool FileSystem::removeFolder(string path, string name) {
    std::vector<std::string> pathFolders;
    boost::split(pathFolders, path, boost::is_any_of("/"), boost::token_compress_on);
    for(auto & pathFolder : pathFolders){
        cout << pathFolder <<endl;
    }
    Folder *curr = &root;
    for(auto it = pathFolders.begin(); it != pathFolders.end(); ++it){
        if((*it).empty()){
            continue;
        }
        if(!curr->findFolder(*it)){
            return false;
        } else curr = curr->getFolder(*it);
    }

    if(curr->findFolder(name)){
        curr->removeFolder(name);
        return true;
    } else{
        return false;
    }
}

bool FileSystem::addFolder(string path, string name, const string& date) {
    std::vector<std::string> pathFolders;
    boost::split(pathFolders, path, boost::is_any_of("/"), boost::token_compress_on);

    cout << pathFolders.size() << endl;
    if(pathFolders.size() == 2){
        root.createFolder(name, date);
        return true;
    }
    Folder *curr = &root;
    for(auto it = pathFolders.begin(); it != pathFolders.end(); ++it){
        if((*it).empty()){
            continue;
        }
        if(!curr->findFolder(*it)){
            cout<< "didnt find" << endl;
            return false;
        } else curr = curr->getFolder(*it);
        cout<< curr->getName() <<endl;
    }
    if(!curr->findFolder(name)){

        curr->createFolder(name, date);

        return true;
    } else{
        return false;
    }
}

bool FileSystem::relocateFolder(string oldPath, string name, string newPath) {
    std::vector<std::string> pathFolders;
    boost::split(pathFolders, oldPath, boost::is_any_of("/"), boost::token_compress_on);
    for(auto & pathFolder : pathFolders){
        cout << pathFolder <<endl;
    }
    Folder *curr = &root;
    for(auto it = pathFolders.begin(); it != pathFolders.end(); ++it){
        if((*it).empty()){
            continue;
        }
        if(!curr->findFolder(*it)){
            return false;
        } else curr = curr->getFolder(*it);
    }

    std::vector<std::string> newPathFolders;
    boost::split(newPathFolders, newPath, boost::is_any_of("/"), boost::token_compress_on);

    Folder* res = &root;
    for(auto it = newPathFolders.begin(); it != newPathFolders.end(); ++it){
        if((*it).empty()){
            continue;
        }
        if(!res->findFolder(*it)){
            return false;
        } else res = res->getFolder(*it);
    }
    if(curr->findFolder(name)){

        Folder* temp = curr->getFolder(name);
        curr->removeFolder(name);
        temp->relocate(newPath);
        res->addFolder(*curr);
        return true;
    } else{
        return false;
    }
}

void FileSystem::printAll() {
    string tab = " ";
    root.print(tab);
}