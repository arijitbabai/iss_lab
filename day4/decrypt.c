#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
	// if (argc < 1){
	// 	printf("Usage: decode FILE_NAME \n");
	// 	exit(0);
	// }
	FILE *img;
	char c;
	int iii,jjj,n,msg,end,r;
	iii = jjj = msg = end =0;


	img = fopen("p1.pgm","r");

	while((c=getc(img)) != EOF ){
		if(iii < 4){
			if (c == '\n'){
				iii++;
			}
			continue;
		}

		if (!end){
			if(jjj == 0 ){
				if(msg == 255){
					end = 1;
					putchar('\n');
				}
				if(iii > 4){
					putchar(msg);
				}
				iii++;
				msg = 0;
			}
					
		// printf("%d\n",jjj);
			if(isdigit(c)) {
				ungetc(c, img);
				fscanf(img,"%d",&n);
				printf("%d",n);
			}
			r = n%2;
			msg <<= 1;
			msg |= r;
			jjj = (jjj + 1)%8;

		}
		else
			break;
	}
 	return 0;
}