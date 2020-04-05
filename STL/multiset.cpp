/*
 * @Author: Hellcat
 * @Date: 2020-04-04 21:46:29
 */
// set和multiset通常以红黑树实现
#include <iostream>
#include <unordered_set>
#include <ctime>
#include <algorithm>
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

void test_unordered_multiset(long& value) {
	cout << "\ntest_unordered_multiset().......... \n";

    unordered_multiset<string> c;
    char buf[10];

    clock_t timeStart = clock();
    for(long i = 0; i < value; i++) {
    	try {
    		snprintf(buf, 10, "%d", rand());
        	c.insert(string(buf));
		}
		catch(exception& p) {
			cout << "i=" << i << " " << p.what() << endl;
			abort();
		}
	}
	cout << "milli-seconds : " << (clock()-timeStart) << endl;
	cout << "unordered_multiset.size()= " << c.size() << endl;
	cout << "unordered_multiset.max_size()= " << c.max_size() << endl;	// 384307168202282325
	// cout << "unordered_multiset.bucket_count()= " << c.bucket_count() << endl;
	// cout << "unordered_multiset.load_factor()= " << c.load_factor() << endl;
	// cout << "unordered_multiset.max_load_factor()= " << c.max_load_factor() << endl;
	// cout << "unordered_multiset.max_bucket_count()= " << c.max_bucket_count() << endl;
  	// for (unsigned i = 0; i < 20; i++) {
    // 	cout << "bucket #" << i << " has " << c.bucket_size(i) << " elements.\n";
  	// }
    string target = get_a_target_string();
    timeStart = clock();
    auto pItem1 = ::find(c.begin(), c.end(), target);
    cout<<"find() milli-seconds: "<<(clock()-timeStart)<<endl;
    if(pItem1 != c.end())
        cout<<"found, "<<*pItem1<<endl;
    else
        cout<<"not found"<<endl;

    timeStart = clock();
    auto pItem2 = c.find(target); // 快很多
    cout<<"c.find() milli-seconds: "<<(clock() - timeStart)<<endl;
    if(pItem2 != c.end())
        cout<<"found, "<<*pItem2<<endl;
    else
        cout<<"not found"<<endl;
}

int main() {
    long v = 1e6;
    test_unordered_multiset(v);
}
