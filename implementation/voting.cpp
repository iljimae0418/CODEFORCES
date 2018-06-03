#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <queue> 
#include <map> 
using namespace std;  
int gone[200005];  
int main(){
	int n; 
	cin >> n; 
	string s; 
	cin >> s; 
	priority_queue< int, vector<int>, greater<int> > pqD,pqR; 
	for (int i = 0; i < n; i++){
		if (s[i] == 'R'){
			pqR.push(i);  
		}else if (s[i] == 'D'){
			pqD.push(i); 
		}
	}
	while (1){
		if (pqR.empty() && !pqD.empty()){
			cout << "D" << endl; 
			return 0; 
		}
		if (!pqR.empty() && pqD.empty()){
			cout << "R" << endl; 
			return 0; 
		}
		int t = min(pqR.top(),pqD.top());  
		if (t == pqR.top()){
			pqD.pop();  
			pqR.pop();  
			pqR.push(t+n);  
		}else if (t == pqD.top()){
			pqR.pop(); 
			pqD.pop(); 
			pqD.push(t+n); 
		}
	}
	return 0;  
}
