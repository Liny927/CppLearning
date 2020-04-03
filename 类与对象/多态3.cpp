/*
 * @Author: Hellcat
 * @Date: 2020-03-31 21:14:10
 */
#include <iostream>
using namespace std;

class CDocument {
public:
    void OnFileOpen();
    virtual void Serialize() {
        cout<<"CDocument:成功载入"<<endl;
    };
};

class CMyDoc: public CDocument {
public:
    virtual void Serialize() {
        cout<<"CMyDoc:成功载入"<<endl;
    };
};

void CDocument:: OnFileOpen() {
    cout<<"打开了文件"<<endl;
    Serialize();
}

int main() {
    CMyDoc myDoc;
    myDoc.OnFileOpen();
    char ch; cin >> ch;
}
