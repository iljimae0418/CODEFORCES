#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector> 
#include <deque> 
#include <set>
using namespace std; 
#define IOFAST() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);  
deque<int> d1,d2; 
typedef pair< deque<int>,deque<int> > PD; // pair of deques   
set<PD> visited;  
int solve(int &cnt){
	if (visited.count(PD(d1,d2))){
		return -1;  
	}
	if (d1.empty()) return 2;  
	if (d2.empty()) return 1; 
	visited.insert(PD(d1,d2)); 
	int x1 = d1[0]; d1.pop_front();  
	int x2 = d2[0]; d2.pop_front();  
	if (x1 > x2){
		// first card is greater than second 
		d1.push_back(x2); 
		d1.push_back(x1); 
	}else if (x1 < x2){
		d2.push_back(x1); 
		d2.push_back(x2);  
	}
	cnt++;  
	return solve(cnt); 
} 
int main(){
	IOFAST();  
	int n,k1,k2;  
	cin >> n;  
	cin >> k1; 
	d1.resize(k1); 
	for (int i = 0; i < k1; i++){
		cin >> d1[i];  
	}
	cin >> k2;  
	d2.resize(k2); 
	for (int i = 0; i < k2; i++){
		cin >> d2[i];  
	}
	int cnt = 0; 
	int ans = solve(cnt); 
	if (ans == -1){
		cout << ans << endl;
	}else{
		cout << cnt << " " << ans << endl; 
	}
	return 0; 
}
