#include <iostream> 
#include <cstdio> 
#include <cstdlib> 
using namespace std; 
typedef long long ll; 
ll dist(ll x1,ll y1,ll x2,ll y2){
	return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2); 
}
int main(int argc,char **argv){
	ll ax,ay,bx,by,cx,cy; 
	scanf("%lld %lld %lld %lld %lld %lld",
		&ax,&ay,&bx,&by,&cx,&cy);
	// check colinearity 
	if ((ay-by)*(bx-cx) == (by-cy)*(ax-bx)){
		return !printf("No\n"); 
	}
	// check distance 
	if (dist(ax,ay,bx,by) == dist(bx,by,cx,cy)){
		puts("Yes"); 
	}else{
		puts("No");  
	}
	return 0; 
}
