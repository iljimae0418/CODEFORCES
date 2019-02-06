/*
Introvert takes an unoccupied seat with smallest w_i 
Extrovert takes an occupied seat with largest w_i  
It is guaranteed that for each extrovert there is a suitable row  
*/ 
#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue> 
#include <algorithm> 
using namespace std; 
typedef pair<int,int> P;  
int main(){
	int n; 
	cin >> n; 
	priority_queue < P,vector<P>,greater<P> > introvert; 
	for (int i = 1; i <= n; i++){
		int w; 
		cin >> w; 
		introvert.push(P(w,i));  
	}
	priority_queue< P,vector<P>,less<P> > extrovert; 
	for (int i = 0; i < 2*n; i++){
		char c;  
		cin >> c; 
		if (c == '0'){
			P p = introvert.top(); 
			introvert.pop();  
			cout << p.second << " "; 
			extrovert.push(p); 
		}else if (c == '1'){
			P p = extrovert.top(); 
			extrovert.pop();  
			cout << p.second << " "; 
		}
	}
	cout << endl;
	return 0; 
}
