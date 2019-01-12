#include <iostream>
#include <cstdlib>
#include <cstdio> 
#include <algorithm>
#include <vector> 
#include <stack> 
using namespace std; 
typedef pair<int,int> P; 
bool cmp(P &p1,P &p2){
	return p1.first < p2.first;   
}
int main(int argc,char **argv){
	int T; 
	scanf("%d",&T); 
	while (T--){
		int n; 
		scanf("%d",&n); 
		vector<P> v,given; 
		for (int i = 0; i < n; i++){
			int a,b; 
			scanf("%d %d",&a,&b); 
			v.push_back(P(a,b)); 
			given.push_back(P(a,b)); 
		}
		sort(v.begin(),v.end(),cmp);  
		stack<P> st;  
		st.push(v[0]); 
		for (int i = 1; i < n; i++){
			P p = st.top(); 
			if (p.second < v[i].first){
				st.push(v[i]); 
			}else if (p.second < v[i].second){
				p.second = v[i].second; 
				st.pop();  
				st.push(p); 
			}
		}
		if (st.size() < 2){
			printf("-1\n"); 
		}else{
			P p1 = st.top(); st.pop(); 
			P p2 = st.top(); st.pop(); 
			for (int i = 0; i < given.size(); i++){
				if (p1.first <= given[i].first && 
					given[i].second <= p1.second){
					printf("1 "); 
				}else{
					printf("2 ");  
				}
			}
			puts(""); 
		}
	}
	return 0;  
}
