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
        cout<<"CDocument:�ɹ�����"<<endl;
    };
};

class CMyDoc: public CDocument {
public:
    virtual void Serialize() {
        cout<<"CMyDoc:�ɹ�����"<<endl;
    };
};

void CDocument:: OnFileOpen() {
    cout<<"�����ļ�"<<endl;
    Serialize();
}

int main() {
    CMyDoc myDoc;
    myDoc.OnFileOpen();
    char ch; cin >> ch;
}
