/*
 * @Author: Hellcat
 * @Date: 2020-04-05 17:40:13
 */
#include <iostream>
#include <ctime>
#include <map>
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

void test_multimap(long& value) {
	cout << "\ntest_multimap().......... \n";

    multimap<long, string> c;
    char buf[10];

    clock_t timeStart = clock();
    for(long i = 0; i < value; i++) {
    	try {
    		snprintf(buf, 10, "%d", rand());
        	c.insert({i, buf});
		}
		catch(exception& p) {
			cout << "i=" << i << " " << p.what() << endl;
			abort();
		}
	}
	cout << "milli-seconds : " << (clock()-timeStart) << endl;
	cout << "unordered_multiset.size()= " << c.size() << endl;
	cout << "unordered_multiset.max_size()= " << c.max_size() << endl;
    long target = get_a_target_long();
    cout<<"target: "<<target<<endl;
    timeStart = clock();
    auto pItem = c.find(target); // ¿ìºÜ¶à
    cout<<"c.find() milli-seconds: "<<(clock() - timeStart)<<endl;
    if(pItem != c.end())
        cout<<"found, value = "<<pItem->second<<endl;
    else
        cout<<"not found"<<endl;
}

int main() {
    long a = 1e6;
    test_multimap(a);
}
