#include<bits/stdc++.h>
using namespace std;

int main() {
	int t; cin>>t;
	while(t--){
	    
	    int n, w;
	    cin>>n>>w;
	    int weights[n];
	    int items[n];
	    
	    for(int i = 0; i<n; i++) cin>>items[i];
	    for(int i = 0; i<n; i++) cin>>weights[i];
	    
	    int dp[n+1][w+1];
	    
	    for(int i = 0; i<n+1; i++){
	        for(int j = 0; j<w+1; j++){
	            if(i == 0 or j == 0){
	                dp[i][j] = 0;
	            }
	        }
	    }
	    for(int i = 1; i<n+1; i++){
	        for(int j = 0; j<w+1; j++){
	            if(weights[i-1] <= j){
	                dp[i][j] = max(items[i-1] + dp[i-1][j-weights[i-1]], dp[i-1][j]);
	            }
	            else{
	                dp[i][j] = dp[i-1][j];
	            }
	        }
	    }
	    
	    cout<<dp[n][w];
	    cout<<"\n";
	}
	
	return 0;
}