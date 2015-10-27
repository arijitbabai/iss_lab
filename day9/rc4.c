#include <stdio.h>

void main(){
	FILE *input,*output;
	input = fopen("input.txt","r");
	output = fopen("output.txt","w");
	int i,j,keylen = 3,t1,k,temp;
	char c;
	int s[256],t[256];
	char key[25];
	//taking key input
	for(i = 0 ; i < keylen ; i++){
		scanf("%c",&key[i]);
	}
	
	//initializing s
	for(i = 0 ; i <= 255 ; i++){
		s[i] = i;
		t[i] = key[i % keylen];
	}
	
	//permute s
	j = 0 ;
	for(i = 0 ; i <= 255 ; i++){
		j = (j + s[i] + t[i]) % 256;
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		//printf("hello\n");
	}
	//strem generation
	i = 0;
	j = 0;
	// fscanf(input,"%c",&c);
	// printf("[%c]\n",c);
	while((c=fgetc(input))!=EOF){
		i = (i + 1) % 256;
		j = (j + s[i]) % 256;
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		t1 = (s[i] + s[j]) % 256;
		k = s[t1];
		// printf("%x, %d,",c, k);
		// printf("Size = %ld  ",sizeof(c));
		fprintf(output,"%02x",c ^ k);				
		
	
	}	
	fclose(input);
	fclose(output);
}

 
	
	
	
	
	
