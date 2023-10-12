#include <bits/stdc++.h>
using namespace std;
int n;
string s;
char a[105][105];//填数的数组
int main() {
    cin>>n;
    cin>>s;
    int x=1;//开始位置的行
    int y=1;//开始位置的列
    for (int i=0;i<s.length();i++){//把s字串所有字符填进去
        a[x][y]=s[i];//填字符
        if ((x+y)%2==0){//如果行列相加为偶数，则左下向右上
            x--;
            y++;
            if (y>n){//如果列越界，换下一斜线开始
                y-=1;
                x+=2;
            }
            if(x<1){//如果X越界，换下一斜线开始
                x++;
            }
        }else{//x+y为奇数，右上向左下
            x++;
            y--;
            if (x>n){//如果x越界，换下一斜线
                x-=1;
                y+=2;
            }
            if (y<1){//如果y越界，换下一斜线
                y++;
            }
        }
    }
    for (int i=1;i<=n;i++){//循环打印
        for (int j=1;j<=n;j++){
            cout<<a[i][j];
        }
        cout<<endl;
    }
    return 0;
}
