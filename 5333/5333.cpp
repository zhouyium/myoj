//http://47.110.135.197/problem.php?id=5333
#include <iostream>
using namespace std;
int main() {
    int t;
    cin>>t;
    for (int i=1; i<=t; i++) {
        int n,m;
        cin>>n>>m;
        
        int sz[4];
        for (int i=1; i<=m; i++) {
            cin>>sz[i];
        }
        
        //分类讨论
        if (2==n) {
            cout<<"-1";
        } else if (1==m) {
            //一层
            cout<<sz[1];
        } else if (3==m) {
            //三层
            cout<<sz[2];
        } else {
            //二层
            if (1==sz[1]) {
                cout<<sz[1];
            } else if (n==sz[2]) {
                cout<<sz[2];
            } else {
                cout<<"-1";
            }
        }
        cout<<"\n";
    }
    return 0;
}