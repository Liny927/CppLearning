/*
 * @Author: Hellcat
 * @Date: 2020-04-05 15:22:48
 */
// Dealing with Other Destruction Policies
#include <iostream>
#include <string>
#include <fstream> // for ofstream
#include <memory> // for shared_ptr
#include <cstdio> // for remove()
using namespace std;

class FileDeleter {
private:
    string filename;
public:
    FileDeleter (const string& fn): filename(fn) {}
    void operator () (ofstream* fp) {
        cout<<"REMOVE"<<endl;
        fp->close(); // close.file
        remove(filename.c_str()); // delete file
    }
};

int main() {
    // create and open temporary
    shared_ptr<ofstream> fp(new ofstream("tmpfile.txt"),
                                        FileDeleter("tmpfile.txt"));
}
