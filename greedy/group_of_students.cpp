#include <iostream>
using namespace std; 
int c[111]; 
int main(){
	int m, sum = 0, x,y; 
	cin >> m; 
	for (int i = 1; i <= m; i++){
		cin >> c[i]; 
		sum += c[i]; 
	}
	cin >> x >> y;  
	int trail = 0; 
	bool found = false;  
	for (int i = 1; i <= m; i++){
		trail += c[i]; 
		if (trail >= x && trail <= y && 
			sum-trail >= x && sum-trail <= y && i != m){
			found = true; 
			cout << i+1 << endl;
			break; 
		}
	}
	if (!found) cout << 0 << endl; 
	return 0; 
}	
