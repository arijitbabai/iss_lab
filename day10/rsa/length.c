#include <stdio.h>

void main(){
	int n = 4,x = 1;
	int i = 0;
	int  p;
	while( n > x - 1){
		x = x << 1;
		i++;
	}
	printf("%d\n",i);
	p = 16 & (1 << 3);
	printf("%d\n",4%5);
	
}

	
