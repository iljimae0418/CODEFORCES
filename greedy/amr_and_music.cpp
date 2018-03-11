#include <iostream>
#include <cstdlib>
#include <algorithm> 
#include <cstring> 
#include <vector> 
using namespace std; 
typedef pair<int,int> P; 
P a[101]; 
int main(){
	int n,k; 
	cin >> n >> k; 
	for (int i = 0; i < n; i++){
		cin >> a[i].first; 
		a[i].second = i+1;   
	} 
	sort(a,a+n);
	int sum = 0,cnt = 0; 
	vector<int> ans;  	
	for (int i = 0; i < n; i++){
		sum += a[i].first;  
		if (sum > k){
			break;
		}else{
			cnt++; 
			ans.push_back(a[i].second);  
		}
	}
	cout << cnt << endl; 
	if (ans.size() > 0){
		for (int i = 0; i < ans.size(); i++){
			cout << ans[i] << " "; 
		}
	}
	return 0;  
}
