#include<bits/stdc++.h>
using namespace std;

int main() {
	
	int tt; cin>>tt;
	while(tt--){
	    
	    string a, b; cin>>a>>b;
	    int n = a.length();
	    int m = b.length();
	    
	    int dp[n+1][m+1];
	    for(int i = 0; i<=n; i++) dp[i][0] = 0; 
	    for(int i = 0; i<=m; i++) dp[0][i] = 0;
	    
	    for(int i = 1; i<n+1; i++){
	        for(int j = 1; j<m+1; j++){
	            if(a[i-1] == b[j-1]){
	                dp[i][j] = 1 + dp[i-1][j-1];
	            }
	            else
	               dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
	        }
	    }
	    
	    cout<<n+m-dp[n][m]<<"\n";
	    
	}
	
	return 0;
}
