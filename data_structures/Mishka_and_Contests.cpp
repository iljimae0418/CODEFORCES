#include <iostream>
#include <cstdlib>
#include <algorithm> 
#include <deque> 
using namespace std;  

int main(){
	int n,k; 
	cin >> n >> k; 
	deque<int> dq(n); 
	for (int i = 0; i < n; i++){
		cin >> dq[i]; 
	}
	while (true){
		if (dq.empty()) break; 
		if (dq[0] > k && dq[dq.size()-1] > k) break; 
		else if (dq[0] > k && dq[dq.size()-1] <= k) dq.pop_back(); 
		else if (dq[0] <= k && dq[dq.size()-1] > k) dq.pop_front(); 
		else dq.pop_front();  
	}
	cout << n-dq.size() << endl; 
	return 0;  
}
