#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{

	public:
	int minDiffernce(int arr[], int n) 
	{ 
	    int sum = 0, mn = INT_MAX;
	    for(int i = 0; i<n; i++){
	        sum+=arr[i];
	    }
	    
	    vector<int> v;
	    bool dp[n+1][sum+1];
	    
	    for(int i = 0; i<=sum; i++){
            dp[0][i] = 0;
        }
        for(int i = 0; i<=n; i++){
            dp[i][0] = 1;
        }
        
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<= sum; j++){
                if(arr[i-1] <= j){
                    dp[i][j] = (dp[i-1][j] or dp[i-1][j-arr[i-1]]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        for(int i = 0; i<=sum; i++){
            if(dp[n][i]){
                v.push_back(i);
            }
        }
        
        for(int i = 0; i<v.size(); i++){
            mn = min(mn, abs(sum - 2*v[i]));
        }
        
	    return mn;
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDiffernce(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends
