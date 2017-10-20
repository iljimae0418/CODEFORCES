#include <iostream>
#include <algorithm> 
#include <set> 
using namespace std; 
int main(){
	int n,m;
	cin >> n >> m;  
	set<int> a; 
	set<int> b; 
	for (int i = 0; i < n; i++){
		int x; 
		cin >> x; 
		a.insert(x); 
	}
	for (int i = 0; i < m; i++){
		int x; 
		cin >> x;  
		b.insert(x); 
	}
	for (int i = 1; i <= 99; i++){
		if (a.count(i%10) && b.count(i/10)){
			cout << i << endl;
			break; 
		}else if (a.count(i/10) && b.count(i%10)){
			cout << i << endl;
			break; 
		}else if (a.count(i) && b.count(i)){
			cout << i << endl; 
			break; 
		}
	}
	return 0;  
}
