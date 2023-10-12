#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN=5e5+4;
int tz[MAXN];
int n;

//
bool check(int mid) {
   for (int i=1; i<=mid; i++) {
      if (tz[i+n-mid]<tz[i]*2) {
         return false;
      }
   }
   return true;
}

int main() {
   cin>>n;

   int x;
   for (int i=1; i<=n; i++) {
      cin>>tz[i];
   }
   sort(tz+1, tz+n+1);   

   //二分查找答案
   int l=0;
   int r=n/2;
   int mid;
   int ans=0;
   while (l<=r) {
      mid=(l+r)/2;
      if (check(mid)) {
         l=mid+1;
         ans=mid;
      } else {
         r=mid-1;
      }
   }

   cout<<n-ans<<"\n";

   return 0;
}
