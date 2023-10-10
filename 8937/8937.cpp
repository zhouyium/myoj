#include <bits/stdc++.h>
using namespace std;
int n;
int s;
int a[12][4100][4100];//a[i][j][k]代表第i轮，第j行，第k列的值
int main() {
    //freopen("10.in", "r", stdin);
    //freopen("00.out", "w", stdout);
    cin>>n;
    cin>>s;
    a[0][1][1]=s;//初始化第0轮
    for (int i=1;i<=n;i++){//循环n轮
        int t=(1<<(i-1));//t为n-1轮的范围（2的i-1次方）
        if(i==n){
        	//cout<<"t="<<t<<"\n";
		}
        for (int j=1;j<=t;j++){//循环t行
            for (int k=1;k<=t;k++){//循环k列
                if (a[i-1][j][k]==0){//如果扩张0
                    a[i][j*2][k*2]=1;//右下角为1
                }else{//否则扩张1
                    a[i][j*2][k*2-1]=1;//左下角为1
                    a[i][j*2-1][k*2]=1;//右上角为1
                    a[i][j*2-1][k*2-1]=1;//左上角为1
                }
            }
        }
    }
    for (int i=1;i<=(1<<n);i++){//循环打印第n轮的结果
        for (int j=1;j<=(1<<n);j++){
            cout<<a[n][i][j];
        }
        cout<<"\n";
    }
    return 0;
}
