#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
	int m[5][5],*p,i,j,a[26] = {0};
	char *c;
	c =(char *) argv[1];
	p = (int *)m;
	while(*c){
		if(a[*c - 'A'] != 1 && *c != 'J'){
			a[*c - 'A'] = 1;
			*p = *c;
			*p++;
		}
		c++;
	}
	for(i = 0 ; i < 26 ; i++){
		if(a[i] == 0 && ('A' + i != 'J')){
			*p = ('A' + i);
			*p++;			
		}
	}
	for(i = 0 ; i < 5 ; i++){
		for(j = 0 ; j < 5 ; j++){
		printf("%c\t",m[i][j]);
		*p++;
		}
		printf("\n");
	}
	return 0;
}