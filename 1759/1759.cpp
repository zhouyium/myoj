//1623£ºSherlock and His Girlfriend
//http://47.110.135.197/problem.php?id=1759
#include<bits/stdc++.h>
using namespace std;
using LL=long long;
int const N=1e5+5;
LL s[N],p[N],n,cnt;
void sprime()
{
    for(int i=2;i<=n+1;i++)
    {
        if(!p[i])p[i]=i,s[++cnt]=i;
        for(int j=1;j<=cnt&&p[j]<=p[i]&&i<=(n+1)/s[j];j++)
            p[i*s[j]]=s[j];
    }
}
int main(){
    scanf("%d",&n);
    sprime();
    if(n<3)printf("1\n");
    else printf("2\n");
    for(LL i=1;i<=n;i++)
        if(p[i+1]==i+1)printf("1 ");
        else printf("2 ");
    return 0;
}
