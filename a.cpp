/*
 * @Author: Hellcat
 * @Date: 2020-03-28 11:13:41
 */
#include <bits/stdc++.h>
using namespace std;

class CDucument {
public:
    void OnFileOpen() {
        Serialize();
    }
    //virtual void Serialize() { } // Ðéº¯Êý
    virtual void Serialize() = 0; // ´¿Ðéº¯Êý
};

class CMyDoc: public CDucument {
public:
    virtual void Serialize() {
        cout<<"CMyDoc::Serialize()"<<endl;
    }
};

int main() {
    CMyDoc myDoc;
    myDoc.OnFileOpen();
}
