/*
 * @Author: Hellcat
 * @Date: 2020-04-01 21:10:07
 */
#include <iostream>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    char a[] = {'a', 'b', 'c', 'd', 'e', 'f',
                'g', 'h', 'i', 'j', 'k', 'l',
                'm', 'n', 'o', 'p', 'q', 'r',
                's', 't', 'u', 'v', 'w', 'x',
                'y', 'z',
    };
    cout<<a[rand()%26]<<endl;
}
