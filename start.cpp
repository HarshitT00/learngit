#include<bits/stdc++.h> 
# define int long long int 
using namespace std;




   
int32_t main(){
   int t ;
   cin >> t ;
   while(t--){
   	int n , k;
   	cin >> n >> k;
   	vector<int> arr(n) ;
   	for(int i=0 ; i<n ; i++){
   		cin >> arr[i] ;
   	}
   	if(k==1) cout << (n-1)/2 ;
   	else{
   		int count=0 ;
   		for(int i=1 ; i<n-1 ; i++){
   			if(arr[i]>arr[i-1]+arr[i+1]) count++ ;
   		}
   		cout << count ;
   	}
   	cout << endl ;
   }
  }