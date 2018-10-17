// approach as if solving a diophantine equation 
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector> 
#include <cassert> 
using namespace std;  
typedef pair<int,int> P;  
bool cmp(P &p1,P &p2){
	return (p1.first+p1.second < p2.first+p2.second);  
}
int main(){
	int n; 
	cin >> n; 
	vector<P> v;   
	for (int i = 0; i < 1000000; i++){
		if (n-7*i >= 0 && (n-7*i)%4 == 0){
			int j = (n-7*i)/4;  
			v.push_back(P(j,i));  
		}
	}
	sort(v.begin(),v.end(),cmp);  
	if (v.empty()){
		cout << -1 << endl; 
		return 0;  
	}
	assert(v.size() >= 1);  
	int four_cnt = v[0].first, seven_cnt = v[0].second; 
	for (int i = 0; i < four_cnt; i++){
		cout << "4";  
	} 
	for (int i = 0; i < seven_cnt; i++){
		cout << "7"; 
	}
	cout << endl;   
	return 0;  
}
