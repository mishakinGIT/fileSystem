#include <iostream>
#include "FileSystem.h"

int main() {
    FileSystem* fs = new FileSystem();
    fs->addFolder("/", "a", "date");
    fs->addFolder("/a/", "b", "date");
    fs->addFolder("/a/b/", "c", "date");
    fs->addFolder("/a/b/c/", "d", "date");
    fs->addFolder("/a/b/c/d/", "name", "date");
    fs->printAll();
    fs->removeFolder("a/b/c/d/", "name");
    fs->printAll();
    return 0;
}