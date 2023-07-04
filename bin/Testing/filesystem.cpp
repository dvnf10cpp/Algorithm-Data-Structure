#include <bits/stdc++.h>

using namespace std;
//demo file system as far as i know
class FileSystem {
    public:
    string name;
    
    virtual ~FileSystem() {}
};

class File : public FileSystem {
    public:
    string ext;
    File(string name, string ext) { this->name = name + "." + ext; this->ext = ext; }
};

class Folder : public FileSystem{
    public:
    vector<FileSystem*> child;

    Folder(string name) { this->name = name; }

    void add(FileSystem *folder) {
        child.push_back(folder);
    }

    void printTree(int level = 0) {
        for (const auto &item : child) {
            for (int i = 0; i < level - 1; i++) {
                cout << "|  ";
            }
            if (level > 0) {
                cout << "|--";
            }
            cout << item->name << endl;
            Folder* folder = dynamic_cast<Folder*>(item);
            if (folder) {
                folder->printTree(level + 1);
            }
        }
    }
};

int main() {
    cout << "\n\n\n\n\n\n\n";
    Folder* root    = new Folder("root");

    vector<string> names = {"Documents", "Desktop", "Pictures", "Downloads", "Music"};
    vector<Folder*> folders;
    
    for(const auto &name : names) {
        Folder* folder = new Folder(name);
        folders.push_back(folder);
        root->add(folder);
    }

    Folder* uni         = new Folder("University");
    Folder* code        = new Folder("Programming");
    Folder* sem1        = new Folder("SEMESTER 1");
    Folder* sem2        = new Folder("SEMESTER 2");
    Folder* pemdas      = new Folder("Pemrograman Dasar");
    Folder* aok         = new Folder("Arsitektur dan Organisasi Komputer");
    Folder* pbo         = new Folder("Pemrograman Berorientasi Objek");
    Folder* masterclass = new Folder("Masterclass");
    Folder* nodeModules = new Folder("node_modules");
    Folder* controllers = new Folder("controllers");
    Folder* models      = new Folder("models");

    File* app            = new File("app", "js");
    File* userController = new File("UserController", "js");

    folders[0]->add(uni);
    folders[0]->add(code);
    code->add(masterclass);
    masterclass->add(nodeModules);
    masterclass->add(app);
    masterclass->add(controllers);
    masterclass->add(models);
    controllers->add(userController);
    uni->add(sem1);
    uni->add(sem2);
    sem1->add(pemdas);
    sem1->add(aok);


    root->printTree();

    // clean memory
    delete root;
    for(const auto &folder : folders) {
        delete folder;
    }
    delete uni;
    delete code;
    delete sem1;
    delete sem2;
    delete pemdas;
    delete aok;
    delete pbo;
    delete masterclass;
    delete nodeModules;
    delete app;
    delete controllers;
    delete models;
    delete userController;
    return 0;
}