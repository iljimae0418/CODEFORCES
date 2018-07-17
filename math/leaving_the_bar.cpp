// referred to https://www.quora.com/What-is-the-randomised-solution-on-leaving-the-bar-on-Codeforces 
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector> 
#include <set>
#include <map> 
#include <climits> 
#include <cmath>
using namespace std;  
typedef long long ll;  
class point{
public: 
	ll x,y; 
	int idx; 
	point(ll a = 0,ll b = 0,int index = 0){
		x = a; 
		y = b; 
		idx = index; 
	}
	point operator+(const point &p){
		return point(x+p.x,y+p.y); 
	}
	point operator-(const point &p){
		return point(x-p.x,y-p.y);  
	}
}; 
ll square(ll n){
	return n*n;  
}
ll square_norm(point p){
	return (p.x*p.x + p.y*p.y);  
}
int main(){
	int n; 
	cin >> n; 
	vector<point> v(n); 
	for (int i = 0; i < n; i++){
		cin >> v[i].x >> v[i].y; 
		v[i].idx = i;  
	}
	const ll O = 1.5e6; 
	point P; 
	vector<int> step(n); 
	do{
		random_shuffle(v.begin(),v.end());  
		P = point(0,0); 
		for (int i = 0; i < n; i++){
			if (square_norm(P+v[i]) <= square_norm(P-v[i])){
				P = P+v[i];  
				step[v[i].idx] = 1; 
			}else{
				P = P-v[i]; 
				step[v[i].idx] = -1; 
			}
		}
	}
	while (square_norm(P) > square(O));  
	for (int i = 0; i < n; i++){
		cout << step[i] << " "; 
	}
	cout << endl; 
	return 0; 
}
