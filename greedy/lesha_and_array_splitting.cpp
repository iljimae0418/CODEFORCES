#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector> 
using namespace std; 
typedef pair<int,int> P; 
int a[105]; 
bool allZero(int n){
	for (int i = 1; i <= n; i++){
		if (a[i] != 0) return false; 
	}
	return true;  
}
bool noZero(int n){
	for (int i = 1; i <= n; i++){
		if (a[i] == 0) return false; 
	}
	return true;  
}
int main(){
	int n,cnt = 0; 
	cin >> n; 
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	if (allZero(n)){
		cout << "NO" << endl; 
	}else if (!allZero(n) && !noZero(n)){
		cout << "YES" << endl; 
		int cur = 1, sum = 0; 
		vector<P> ans; 
		for (int i = 1; i <= n; i++){
			if (a[i] == 0) continue; 
			sum += a[i];  
			if (sum == 0){
				cnt++;  
				ans.push_back(P(cur,i-1));  
				sum = a[i];  
				cur = i; 
			}
		}
		cnt++; 
		ans.push_back(P(cur,n)); 
		cout << cnt << endl; 
		for (int i = 0; i < ans.size(); i++){
			cout << ans[i].first << " " << ans[i].second << endl; 
		}
	}else if (noZero(n)){
		cout << "YES" << endl; 
		vector<P> ans; 
		int cur = 1, sum = 0;  
		for (int i = 1; i <= n; i++){
			sum += a[i]; 
			if (sum == 0){
				cnt++; 
				ans.push_back(P(cur,i-1)); 
				sum = a[i];  
				cur = i;  
			}
		}
		cnt++; 
		ans.push_back(P(cur,n)); 
		cout << cnt << endl; 
		for (int i = 0; i < ans.size(); i++){
			cout << ans[i].first << " " << ans[i].second << endl; 
		}
	}
	return 0; 
}
