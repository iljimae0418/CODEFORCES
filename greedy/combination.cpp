#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector> 
using namespace std; 
typedef pair<int,int> P;  
P a[1001];   
bool cmp(P &p1,P &p2){
	return ((p1.second > p2.second) || (p1.second == p2.second && p1.first > p2.first)); 
}
int main(){
	int n; 
	cin >> n; 
	for (int i = 0; i < n; i++){
		cin >> a[i].first >> a[i].second;  
	}
	sort(a,a+n,cmp); 
	int idx = 0; 
	long long draw = 1LL; 
	long long points = 0LL;   
	while (draw > 0 && idx < n){
		draw = draw-1+a[idx].second;  
		points += a[idx].first;  
		idx++;  
	}
	cout << points << endl; 
	return 0;  
}
