//Problem - Given two sequences, find the length of longest subsequence present in both of them.

#include<bits/stdc++.h>
using namespace std;

int main() {
	int tt; cin>>tt;
	while(tt--){
	    
	    int n, m; cin>>n>>m;
	    string s1, s2;
	    cin>>s1>>s2;
	    long long dp[n+1][m+1];
	    for(int i = 0; i<=n; i++) dp[i][0] = 0;
	    for(int i = 0; i<=m; i++) dp[0][i] = 0;
	    
	    for(int i = 1; i< n+1; i++){
	        for(int j = 1; j<m+1; j++){
	            if(s1[i-1] == s2[j-1]){
	                dp[i][j] = 1+dp[i-1][j-1];
	            }
	            else
	                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
	        }
	    }
	    cout<<dp[n][m]<<"\n";
	}
	return 0;
}











