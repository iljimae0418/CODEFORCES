#include <iostream>
#include <cstdlib>
#include <algorithm> 
#include <deque> 
using namespace std;  
int main(){
	deque<int> dq; 	
	int n; 
	cin >> n; 
	for (int i = 0; i < n; i++){
		int x; 
		cin >> x; 
		dq.push_back(x); 
	}
	int s = 0, d = 0, turn = 0; 
	while (!dq.empty()){
		if (!turn){
			// sereja's turn 
			if (dq.size() == 1){
				s += dq[0]; 
				dq.pop_back(); 
				continue;  
			}
			if (dq.front() > dq.back()){	
				s += dq.front(); 
				dq.pop_front(); 
			}else{
				s += dq.back(); 
				dq.pop_back();  
			}	
		}else{
			// dima's turn 
			if (dq.size() == 1){
				d += dq[0]; 
				dq.pop_back(); 
				continue; 				
			}
			if (dq.front() > dq.back()){
				d += dq.front(); 
				dq.pop_front(); 
			}else{
				d += dq.back(); 
				dq.pop_back();  
			}
		}
		turn = !turn; 
	}
	cout << s << " " << d << endl; 
	return 0; 
}	
