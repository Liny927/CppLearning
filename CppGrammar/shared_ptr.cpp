/*
 * @Author: Hellcat
 * @Date: 2020-04-05 10:42:31
 */
#include <iostream>
#include <memory>
#include <vector>
#include <string>
using namespace std;

int main() {
    shared_ptr<string> pNico(new string("nico"),
                            [](string* p) {
                                cout<<"delete: "<<*p<<endl;
                                delete p;
                            });
    shared_ptr<string> pJutta(new string("jutta"));
    (*pNico)[0] = 'N';
    pJutta->replace(0, 2, "JJ"); // substring
    cout<<*pNico<<" "<<*pJutta<<endl;
    vector<shared_ptr<string>> whoMadeCoffee;
    whoMadeCoffee.push_back(pJutta);
    whoMadeCoffee.push_back(pJutta);
    whoMadeCoffee.push_back(pNico);
    whoMadeCoffee.push_back(pJutta);
    whoMadeCoffee.push_back(pNico);
    for(auto ptr : whoMadeCoffee) {
        cout<<*ptr<<" ";
    }
    puts("");
    *pNico = "Nicolai";
    for(auto ptr : whoMadeCoffee) {
        cout<<*ptr<<" ";
    }
    puts("");
    // print some internal data
    // use_count() yields the current number of owners an object referred to by shared pointers has.
    cout<<"use count: "<<whoMadeCoffee[0].use_count()<<endl;
    pNico = nullptr;
    whoMadeCoffee.resize(2);
    // Dealing with Arrays
    shared_ptr<int> p(new int[10],
                    [](int* p) {
                        delete[] p;
                    });
    p.get()[3] = 10;
}
