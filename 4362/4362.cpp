/*
ID: your_id_here
PROG: beads
LANG: C++                
*/
//Broken Necklace
//https://train.usaco.org/usacoprob2?a=cjtzbRDL8Yz&S=beads
#include <bits/stdc++.h>
using namespace std;

/*
8
rrwwwwbb
*/
const int MAXN = 350*2 + 2;
char data[MAXN] = {};

int main() {
    freopen("beads.in", "r", stdin);
    freopen("beads.out", "w", stdout);

    //读入n
    int n;
    cin >> n;

    int i, j;
    for (i=0; i<n; i++) {
        cin >> data[i];
        data[n+i] = data[i];
    }

    int ans = 0;
    for (i=0; i<2*n-1; ) {
        //从第i个开始分。
        if (data[i]==data[i+1]) {
            i++;
            continue;
        }

        //向前找
        int t0 = 1;
        int t1 = 1;
        char ch0 = data[i];
        char ch1 = data[i+1];
        if ('w'==ch0) {
            if ('r'==ch1) {
                ch0 = 'b';
            } else {
                ch0 = 'r';
            }
        } else if ('w'==ch1) {
            if ('r'==ch0) {
                ch1 = 'b';
            } else {
                ch1 = 'r';
            }
        }
        for (j=i-1; j>=0; j--) {
            if (data[j]==ch0 || 'w'==data[j]) {
                t0++;
            } else {
                break;
            }
        }

        //向后找
        for (j=i+2; j<2*n; j++) {
            if (data[j]==ch1 || 'w'==data[j]) {
                t1++;
            } else {
                break;
            }
        }
        i = j-1;

        if (t0+t1>ans) {
            ans = t0+t1;
        }
    }

    if (0==ans) {
        ans = n;
    }
    cout << min(ans, n) << endl;

    //fclose(stdin);
    //fclose(stdout);

    return 0;
}
