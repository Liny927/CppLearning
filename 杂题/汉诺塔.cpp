/*
 * @Author: Hellcat
 * @Date: 2020-02-10 20:37:34
 */
#include <bits/stdc++.h>
typedef long long ll;

ll f[65][8];

int main() {
    f[1][1] = 0, f[1][2] = 1, f[1][3] = 0, f[1][4] = 0, f[1][5] = 0, f[1][6] = 0, f[1][7] = 1;
    f[2][1] = 1, f[2][2] = 1, f[2][3] = 0, f[2][4] = 1, f[2][5] = 0, f[2][6] = 0, f[2][7] = 3;
    f[3][1] = 1, f[3][2] = 3, f[3][3] = 1, f[3][4] = 1, f[3][5] = 0, f[3][6] = 1, f[3][7] = 8;
    f[4][1] = 4, f[4][2] = 3, f[4][3] = 1, f[4][4] = 4, f[4][5] = 2, f[4][6] = 1;
    f[5][1] = 4, f[5][2] = 9, f[5][3] = 6, f[5][4] = 4, f[5][5] = 2, f[5][6] = 6;
    f[6][1] = 15, f[6][2] = 9, f[6][3] = 6, f[6][4] = 15, f[6][5] = 12, f[6][6] = 6;
    f[7][1] = 15, f[7][2] = 31, f[7][3] = 27, f[7][4] = 15, f[7][5] = 12, f[7][6] = 27;
    int n;
    scanf("%d", &n);
    ll sum = 8;
    for(int i = 3; i <= n; i++) {
        if(i&1) {
            f[i][1] = f[i-1][1];
            f[i][4] = f[i-1][4];
            f[i][5] = f[i-1][5];
            f[i][3] = f[i][6] = f[i][4] + f[i][5];
            f[i][2] = f[i][1] + f[i][4] + 1;
        }
        else {
            f[i][2] = f[i-1][2];
            f[i][3] = f[i-1][3];
            f[i][6] = f[i-1][6];
            f[i][1] = f[i][4] = f[i][2] + f[i][3];
            f[i][5] = f[i][3] + f[i][6];
        }
        f[i][7] = sum - 1;
        sum <<= 1;
    }
    printf("A->B:%lld\nA->C:%lld\nB->A:%lld\nB->C:%lld\nC->A:%lld\nC->B:%lld\nSUM:%lld\n",f[n][1], f[n][2], f[n][3], f[n][4], f[n][5], f[n][6], f[n][7]);
}

// #include <bits/stdc++.h>
// using namespace std;

// int cnt = 0, res1 = 0, res2 = 0, res3 = 0, res4 = 0, res5 = 0, res6 = 0;

// void Hanoi(int n, char a, char b, char c) {
//     if(n == 0) return;
//     Hanoi(n-1, a, c, b);
//     cnt++;
//     if(a == 'A' && c == 'B') res1++;
//     if(a == 'A' && c == 'C') res2++;
//     if(a == 'B' && c == 'A') res3++;
//     if(a == 'B' && c == 'C') res4++;
//     if(a == 'C' && c == 'A') res5++;
//     if(a == 'C' && c == 'B') res6++;
//     Hanoi(n-1, b, a, c);
// }

// int main() {
//     int n;
//     scanf("%d", &n);
//     Hanoi(n, 'A', 'B', 'C');
//     printf("A->B:%d\nA->C:%d\nB->A:%d\nB->C:%d\nC->A:%d\nC->B:%d\nSUM:%d\n",res1,res2,res3,res4,res5,res6,cnt);
// }