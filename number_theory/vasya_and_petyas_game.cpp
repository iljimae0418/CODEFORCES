#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector> 
using namespace std; 
#define MAXN 1000
#define IOFAST() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
int prime[MAXN+1]; 
void eratos(){
	for (int i = 0; i <= MAXN; i++){
		prime[i] = 1;  
	}
	prime[0] = prime[1] = 0; 
	for (int i = 2; i <= MAXN; i++){
		if (prime[i]){
			for (int j = i*i; j <= MAXN; j += i){
				prime[j] = 0;  
			}
		}
	}
}
int main(){
	IOFAST(); 
	int n; 
	cin >> n; 
	eratos();  
	vector<int> questions; 
	for (int i = 1; i <= n; i++){
		if (prime[i]){
			questions.push_back(i); 
			for (int j = i*i; j <= n; j *= i){
				questions.push_back(j);  
			}
		}
	}
	cout << questions.size() << endl; 
	for (int i = 0; i < questions.size(); i++){
		cout << questions[i] << " ";  
	}
	cout << endl; 
	return 0;  
}
