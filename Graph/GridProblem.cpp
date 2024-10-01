#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define N 2*10e5
using namespace std;
template <typename T> T gcd(T a, T b) { return __gcd(a, b); }
template <typename T> T lcm(T a, T b) { return a * b / gcd(a, b); }
template <typename T> bool checkPrime(T n) { return (n <= 1) ? false : (n <= 3) ? true : (n % 2 != 0 && n % 3 != 0 && (n == 5 || n % 6 == 1 || n % 6 == 5)); }
template <typename T> bool CheckSquare(T n) { if(sqrt(n) * sqrt(n) == n) {return true;} return false ; }
template <typename T> T rev(T n) { T rev = 0; while (n != 0) { rev = rev * 10 + n % 10; n /= 10; } return rev; }
template <typename T> T numberDigits(T n){ T cnt = 0; while(n != 0){ T rem = n %10; cnt++;  n /= 10; } return cnt; }
///----------------------------------------------------------------------------------------------------------------------------------------------------------------

int main() {
    int n;
    cin>>n;
    vector<vector<char>> arr(n,vector<char>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    vector<vector<int>>dp(n,vector<int>(n,0));

for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
        if(i==0 && j==0 && arr[i][j] != '*') dp[i][j] =1 ;
        else if(arr[i][j] == '*') dp[i][j] = 0;
        else{
            int up = (i > 0) ? dp[i-1][j] : 0;
            int left = (j > 0) ? dp[i][j-1] : 0;
            dp[i][j] =(up + left) % mod;
        }
    }
}
    cout<<dp[n-1][n-1]<<endl;

    return 0;
}