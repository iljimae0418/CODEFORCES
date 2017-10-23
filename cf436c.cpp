/*
Divide into two cases: 
if we are at x = 0, then 
	1) if cur_fuel < f, we cannot go on for k journeys 
	2) else we can reach f. Then we decide if we want to refuel or not. 
	We refuel only if (a-f)*2 > cur_fuel. Else we don't 
if we are at x = a, then 
	1) if cur_fuel < a-g, we cannot reach go on for k journeys 
	2) else we can reach f. Then we decide if we want to refuel or not. 
	We refuel only if 2&f > cur_fuel. Else we don't 
*/  
#include <iostream>
#include <cstdlib>
#include <algorithm> 
using namespace std; 
int main(){
	int a,b,f,k;  
	cin >> a >> b >> f >> k; 
	int cur_pos = 0;  
	int cur_fuel = b; 
	bool cantReach = false; 
	int cnt = 0;  
	for (int i = 1; i <= k; i++){
		// check for all k journeys 
		if (cur_pos == 0){
			if (cur_fuel < f){
				cantReach = true; 
				break; 
			}
			cur_fuel -= f; 
			// edge case: what if this is the last trip, i.e. the kth trip? 
			if (i == k && cur_fuel < (a-f)){
				// we need to re-fill 
				cur_fuel = b; 
				cnt++;  
			}else if (i != k && cur_fuel < 2*(a-f)){
				cur_fuel = b; 
				cnt++;  
			}
			// edge case: what if even after refill, a-f is still greater than 
			// cur_fuel?  
			if (cur_fuel < a-f){
				cantReach = true;  
				break; 
			} 
			cur_pos = a;  
			cur_fuel -= (a-f); // we are done with one journey 
		}else{
			if (cur_fuel < (a-f)){
				cantReach = true; 
				break; 
			}
			cur_fuel -= (a-f);  
			// edge case: this is the kth trip 
			if (i == k && cur_fuel < f){
				// we need to re-fill 
				cur_fuel = b; 
				cnt++; 
			}else if (i != k && cur_fuel < 2*f){
				cur_fuel = b; 
				cnt++; 
			}
			// edge case: what if even after re-fill, f > cur_fuel? 
			if (cur_fuel < f){
				cantReach = true; 
				break; 
			}
			cur_pos = 0; 
			cur_fuel -= f; 
		}
	}
	if (cantReach) cout << -1 << endl; 
	else cout << cnt << endl; 
	return 0; 
}
