/*
 * @Author: Hellcat
 * @Date: 2020-03-31 13:25:03
 */
#include <bits/stdc++.h>
// #include <iostream>
// #include <array>
// #include <string>
// #include <ctime>
// #include <cstdlib>
// #include <vector>
// #include <list>
// #include <forward_list>
// #include <algorithm>
// #include <ext/slist>
// #include <deque>
const int ASIZE = 5e5 + 10;
using namespace std;

long get_a_target_long() {
    long target = 0;
    cout<<"target(0~"<<RAND_MAX<<"):";
    cin>>target;
    return target;
}

string get_a_target_string() {
    long target = 0;
    char buf[10];
    cout<<"target(0~"<<RAND_MAX<<"):";
    cin>>target;
    snprintf(buf, 10, "%d", target);
    return string(buf);
}

int compareLongs(const void* a, const void* b) {
    return (*(long*) a - *(long*)b);
}

int compareStrings(const void* a, const void* b) {
    if(*(string*)a > *(string*)b)
        return 1;
    else if(*(string*)a < *(string*)b)
        return -1;
    else
        return 0;
}

namespace ly01 {
    void test_array() {
        cout<<"\n......test_array()......"<<endl;
        array<long, ASIZE> c;
        clock_t timeStart = clock();
        for(long i = 0; i < ASIZE; i++)
            c[i] = rand();
        cout<<"insert milli-seconds: "<<(clock() - timeStart)<<endl;
        cout<<"array.size() = "<<c.size()<<endl;
        cout<<"array.front() = "<<c.front()<<endl;
        cout<<"array.back() = "<<c.back()<<endl;
        cout<<"array.data() = "<<c.data()<<endl;

        long target = get_a_target_long();
        timeStart = clock();
        qsort(c.data(), ASIZE, sizeof(long), compareLongs);
        long* pItem = (long*)bsearch(&target, c.data(), ASIZE, sizeof(long), compareLongs);
        cout<<"sort + bsearch, milli-seconds: "<<(clock() - timeStart)<<endl;
        if(pItem != nullptr)
            cout<<"found, "<<*pItem<<endl;
        else
            cout<<"Not found!"<<endl;
    }
    void test_vector(long &value) {
        vector<string> c;
        char buf[10];
        clock_t timeStart = clock();
        cout<<"\n......test_vector()......"<<endl;
        for(long i = 0; i < value; i++) {
            try {
                snprintf(buf, 10, "%d", rand());
                c.push_back(string(buf));
            }
            catch(exception& p) {
                cout<<"i = "<<i<<' '<<p.what()<<endl;
                abort();
            }
        }
        cout<<"insert milli-seconds: "<<(clock() - timeStart)<<endl;
        cout<<"vector.size() = "<<c.size()<<endl;
        cout<<"vector.front() = "<<c.front()<<endl;
        cout<<"vector.back() = "<<c.back()<<endl;
        cout<<"vector.data() = "<<c.data()<<endl;
        cout<<"vector.capacity() = "<<c.capacity()<<endl;

        string target = get_a_target_string();
        timeStart = clock();
        auto pItem1 = ::find(c.begin(), c.end(), target);
        cout<<"::find(), milli-seconds: "<<(clock() - timeStart)<<endl;
        if(pItem1 != c.end())
            cout<<"found, "<<*pItem1<<endl;
        else
            cout<<"Not found!"<<endl;

        timeStart = clock();
        sort(c.begin(), c.end());
        cout<<"sort used time: "<<(clock()-timeStart)<<endl;
        auto pItem2 = (string*)bsearch(&target, c.data(), c.size(), sizeof(string), compareStrings);
        cout<<"sort() + bsearch(), milli-seconds: "<<(clock() - timeStart)<<endl;
        if(pItem2 != NULL)
            cout<<"found, "<<*pItem2<<endl;
        else
            cout<<"Not found!"<<endl;
    }
    void test_list(long &value) {
        list<string> c;
        char buf[10];
        clock_t timeStart = clock();
        cout<<"\n......test_list()......"<<endl;
        for(long i = 0; i < value; i++) {
            try {
                snprintf(buf, 10, "%d", rand());
                c.push_back(string(buf));
            }
            catch(exception& p) {
                cout<<"i = "<<i<<' '<<p.what()<<endl;
                abort();
            }
        }
        cout<<"insert milli-seconds: "<<(clock() - timeStart)<<endl;
        cout<<"list.front() = "<<c.front()<<endl;
        cout<<"list.back() = "<<c.back()<<endl;
        cout<<"list.size() = "<<c.size()<<endl;
        cout<<"list.maxsize() = "<<c.max_size()<<endl;

        string target = get_a_target_string();
        timeStart = clock();
        auto pItem1 = ::find(c.begin(), c.end(), target);
        cout<<"::find(), milli-seconds: "<<(clock() - timeStart)<<endl;
        if(pItem1 != c.end())
            cout<<"found, "<<*pItem1<<endl;
        else
            cout<<"Not found!"<<endl;

        timeStart = clock();
        c.sort(); // 容器自带的sort
        cout<<"sort used time: "<<(clock()-timeStart)<<endl;
    }
    void test_forward_list(long &value) {
        forward_list<string> c;
        char buf[10];
        clock_t timeStart = clock();
        cout<<"\n......test_forward_list()......"<<endl;
        for(long i = 0; i < value; i++) {
            try {
                snprintf(buf, 10, "%d", rand());
                c.push_front(string(buf));
            }
            catch(exception& p) {
                cout<<"i = "<<i<<' '<<p.what()<<endl;
                abort();
            }
        }
        cout<<"insert milli-seconds: "<<(clock() - timeStart)<<endl;
        cout<<"forward_list.front() = "<<c.front()<<endl;
        // cout<<"forward_list.back() = "<<c.back()<<endl;
        // cout<<"forward_list.size() = "<<c.size()<<endl;
        cout<<"forward_list.maxsize() = "<<c.max_size()<<endl;

        string target = get_a_target_string();
        timeStart = clock();
        auto pItem1 = ::find(c.begin(), c.end(), target);
        cout<<"::find(), milli-seconds: "<<(clock() - timeStart)<<endl;
        if(pItem1 != c.end())
            cout<<"found, "<<*pItem1<<endl;
        else
            cout<<"Not found!"<<endl;

        timeStart = clock();
        c.sort(); // 容器自带的sort
        cout<<"sort used time: "<<(clock()-timeStart)<<endl;
    }
    void test_deque(long &value) {
        deque<string> c;
        char buf[10];
        clock_t timeStart = clock();
        cout<<"\n......test_deque()......"<<endl;
        for(long i = 0; i < value; i++) {
            try {
                snprintf(buf, 10, "%d", rand());
                c.push_front(string(buf));
            }
            catch(exception& p) {
                cout<<"i = "<<i<<' '<<p.what()<<endl;
                abort();
            }
        }
        cout<<"insert milli-seconds: "<<(clock() - timeStart)<<endl;
        cout<<"deque.front() = "<<c.front()<<endl;
        cout<<"deque.back() = "<<c.back()<<endl;
        cout<<"deque.size() = "<<c.size()<<endl;
        cout<<"deque.maxsize() = "<<c.max_size()<<endl;

        string target = get_a_target_string();
        timeStart = clock();
        auto pItem1 = ::find(c.begin(), c.end(), target);
        cout<<"::find(), milli-seconds: "<<(clock() - timeStart)<<endl;
        if(pItem1 != c.end())
            cout<<"found, "<<*pItem1<<endl;
        else
            cout<<"Not found!"<<endl;

        timeStart = clock();
        ::sort(c.begin(), c.end());
        cout<<"sort used time: "<<(clock()-timeStart)<<endl;
    }
    // deque stack略
}

int main() {
    srand(time(NULL));
    // ly01::test_array();
    long a = 1e6;
    //ly01::test_vector(a);
    ly01::test_deque(a);
}
