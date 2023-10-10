#include <iostream>
#include <iomanip>
#include <cstdio>

using namespace std;

int main() 
{
    int i;
    float fMoney = 0;
    
    cin >> i;
    
    if (i > 400)
    {
        fMoney += 0.5663 * (i - 400);
        i = 400;
    }
    if ((i >= 151) && (i <= 400))
    {
        fMoney += 0.4663 * (i - 150);
        i = 150;
    }
    if (i <= 150)
    {
        fMoney += 0.4463 * i;
    }
    
    cout.setf(ios::fixed);
    cout << setprecision(1) << fMoney;
    
    return 0;
}
