#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int,int> P; 
P x[100005];   
int find_lowest_set_bit(int n){
	return (~(n-1)) & n;  
}
int main(){
	int sum,limit,accum = 0; 
	cin >> sum >> limit; 
	for (int i = 1; i <= limit; i++){
		x[i] = P(find_lowest_set_bit(i),i); 
		accum += x[i].first;  
	}
	if (accum < sum){
		cout << -1 << "\n"; 
		return 0;  
	}
	sort(x+1,x+limit+1); 
	vector<int> ans; 
	for (int i = limit; i >= 1; i--){
		if (sum-x[i].first >= 0){
			ans.push_back(x[i].second); 
			sum -= x[i].first;  
		}
	}
	if (sum == 0){
		cout << ans.size() << endl; 
		for (int i = 0; i < ans.size(); i++){
			cout << ans[i] << " "; 
		}
		cout << endl; 
	}else{
		cout << -1 << endl; 
	}
	return 0; 
}
