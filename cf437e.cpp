#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue> 
using namespace std; 
int main(){
	priority_queue< int, vector<int>, greater<int> > pq;  
	int n; 
	cin >> n; 
	long long ans = 0;  
	for (int i = 0; i < n; i++){
		int stock_price; 
		cin >> stock_price; 
		pq.push(stock_price);  
		pq.push(stock_price); 
		ans += stock_price-pq.top(); 
		pq.pop(); 
	}
	cout << ans << endl; 
	return 0;  
}
