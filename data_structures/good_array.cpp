// using priority queue 
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <vector> 
using namespace std;  
int n; 
int a[200005];  
int main(){
	priority_queue< int, vector<int>, less<int>  > pq;  
	cin >> n; 
	long long sum = 0;  
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		pq.push(a[i]); 
		sum += a[i];   
	}
	vector<int> ans; 
	for (int i = 1; i <= n; i++){
		if (a[i] == pq.top()){
			// we are removing the max element 
			sum -= a[i]; 
			pq.pop();  
			int newMax = pq.top();  
			if (newMax*2 == sum){
				ans.push_back(i); 
			}
			sum += a[i]; 
			pq.push(a[i]); 
		}else{
			int maxval = pq.top(); 
			sum -= a[i]; 
			if (maxval*2 == sum){
				ans.push_back(i); 
			}
			sum += a[i]; 
		}
	}
	cout << ans.size() << endl; 
	for (int i = 0; i < ans.size(); i++){
		cout << ans[i] << " "; 
	}
	cout << endl; 
	return 0; 
}
