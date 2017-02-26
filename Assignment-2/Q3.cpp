#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int fun(int arr[],int n,int pos){
        vector<int> LIS;
        int j,x;
	    for(j=pos;j<pos+n;j++){
	        if(LIS.empty()){
	            LIS.push_back(arr[j]);
	            continue;
	        }
	        x=upper_bound(LIS.begin(),LIS.end(),arr[j])-LIS.begin();
	        if(x==LIS.size() && LIS[x-1]!=arr[j])
	            LIS.push_back(arr[j]);
	        else if(LIS[x-1]!=arr[j])
	            LIS[x]=arr[j];
	    }
	    return LIS.size();
}
int main() {
	int t,i,n,j,arr[20000],x,mx;
	cin>>t;
	
	for(i=0;i<t;i++){
	    cin>>n;
	    for(j=0;j<n;j++){
	        cin>>arr[j];
	        arr[j+n]=arr[j];
	    }
	    mx=0;
    for(j=0;j<n;j++)
	  mx=max(fun(arr,n,j),mx);
	    cout<<mx<<endl;
	}
	return 0;
} 