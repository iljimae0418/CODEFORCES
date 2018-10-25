#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector> 
using namespace std;  
vector<int> archive; 
void getBinary(int x,int k){ // get all binary strings of length x 
	if (x == 1){
		archive.push_back(k); 
		return; 
	}
	getBinary(x-1,k*10+0); 
	getBinary(x-1,k*10+1); 
} 	
void get(){
	for (int i = 1; i <= 10; i++){
		getBinary(i,1); 
	}
}
int main(){
	int n; 
	cin >> n; 
	get();  
	for (int i = 0; i < archive.size(); i++){
		if (archive[i] > n){
			cout << i << endl; 
			break; 
		}
	}
	return 0;  
}
