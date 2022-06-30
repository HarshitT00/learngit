#include<bits/stdc++.h>
#define int long long int 
using namespace std;

// const int N=300010; 
// vector<int> tr[N] ;
// int arr[N] ;

void dfs(int ver ,int par , vector<int>&arr ,  vector<vector<int>> &tr ){
   int count=0 ;
    for(auto d:tr[ver]){
    	if(d==par) continue ;
    	 dfs(d,ver,arr,tr) ;
       count+=arr[d]+1 ;
    }
    arr[ver]=count ;
}

int fun(int ver, int par , vector<int> &dp ,vector<int>&arr ,  vector<vector<int>> &tr){
	 if(dp[ver]!=-1) return dp[ver] ;
    if(tr[ver].size()==1 && tr[ver][0]==par) return 0 ;
    if(tr[ver].size()==1 && tr[ver][0]!=par) return arr[tr[ver][0]] ;
   
    int ans=0 ;
    if(tr[ver].size()==2 && ver!=1){
        int q=tr[ver][0] ;
        if(q==par) q=tr[ver][1] ;
        ans+=arr[q] ;
    }
    else if(tr[ver].size()==2 && ver==1){
    	int q=tr[ver][0] ;
     	int w=tr[ver][1] ;
    	ans+=max(arr[q]+fun(w,ver,dp,arr,tr),arr[w]+fun(q,ver,dp,arr,tr)) ;
    }
     else {
     	int q=tr[ver][0] ;
     	int w=tr[ver][1] ;
     	if(q==par){
     		q=tr[ver][1];
     		w=tr[ver][2];
     	}
     	else if(w==par){
     		q=tr[ver][0];
     		w=tr[ver][2];
     	}
     	ans+=max(arr[q]+fun(w,ver,dp,arr,tr),arr[w]+fun(q,ver,dp,arr,tr)) ;
     }
     return dp[ver]=ans ;
}

int32_t main()
{
   int t;
   cin >> t ;
   while(t--){
    int n ;
    cin >> n ;
    vector<int> dp(n+1,-1) ;
    vector<vector<int>> tr(n) ;
    for(int i=0 ; i<n-1 ; i++){
        int x , y ;
        cin >> x >> y ;
        tr[x].push_back(y) ;
        tr[y].push_back(x) ;
    }
    vector<int> arr(n) ;
    dfs(1,0,arr,tr) ;
    int ans=fun(1,0,dp,arr,tr) ;
    cout << ans ;
    // cout << arr[1] ;
  cout << endl ; 
  
   } 
}