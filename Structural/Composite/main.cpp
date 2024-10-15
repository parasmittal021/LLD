#include<string>
#include<iostream>
#include<vector>
using namespace std;

class FileSystem {
    public:
        virtual void getDetails() = 0;
        virtual int getSize() = 0;
        virtual ~FileSystem() {}
};

class File: public FileSystem {
    string name;
    int size = 0;
    public:
        File(string name, int size){
            this->name = name;
            this->size = size;
        }
        void getDetails() {
            cout<<"File "<<name<<" of size "<<size<<endl;
        }
        int getSize() {
            return size;
        }  
};

class Directory: public FileSystem {
    string name;
    vector<FileSystem*> files;
    public:
        Directory(string name) {
            this->name = name;
        }
        void add(FileSystem* file){
            files.push_back(file);
        }
        void getDetails() {
            cout<<"Folder "<<name<<endl;
            for(auto file: files){
                file->getDetails();
            }
        }
        int getSize() {
            int size = 0;
            for(auto file: files) {
                size+=file->getSize();
            }
            return size;
        }   
};
int main() {
    FileSystem* file1 = new File("data.txt", 1024);
    FileSystem* file2 = new File("photo.ping", 10240);
    FileSystem* file3 = new File("report.pdf", 102400);
    Directory* folder1 = new Directory("Office");
    folder1->add(file1);
    folder1->add(file2);
    Directory* folder2 = new Directory("Documents");
    folder2->add(folder1);
    folder2->add(file3);
    folder2->getDetails();
    cout<<folder2->getSize()<<endl;
    return 0;
}