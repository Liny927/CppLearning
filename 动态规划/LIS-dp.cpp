/*
 * @Author: Hellcat
 * @Date: 2020-03-03 22:01:04
 */
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int a[1010], f[1010];

int main() {
    int n; scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++) {
        f[i] = a[i];
        for(int j = 1; j < i; j++)
            if(a[i] > a[j])
            f[i] = max(f[i], f[j] + a[i]);
    }
    int res = 0;
    for(int i = 1; i <= n; i++)
        res = max(res, f[i]);
    printf("%d\n", res);
}