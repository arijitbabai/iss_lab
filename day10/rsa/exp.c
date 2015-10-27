#include <stdio.h>

void main(){
	int a = 11, b = 23, n =  187;
	int i,f;
	int x = 1;
	int k = 0;
	while( b > x -1 ){
		x = x << 1;
		k++;
	}
	printf("%d\n",k);
	x = 0;
	f = 1;
	for(i = k - 1 ; i >= 0 ; i--){
		x = 2 * x;
		f = (f * f) % n;
		if( b & (1 << i)){
			x = x + 1;
			f = (f * a) % n;
		}
	}
	printf("%d\n", f);
} 		
	
