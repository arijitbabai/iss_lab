#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>



int main(int argc, char const *argv[])
{
	char **Matrix,str[100],*cypher;
	int ROW , COLUMN,l,i,j,c = 0;
	printf("Enter the key for encryption\n");
	scanf("%d",&ROW);
	printf("Enter the plain text: \n");
	scanf("%s",str);
	l = strlen(str);
	COLUMN = (int)ceil((float)l/ROW);
	printf("%d\n",COLUMN);
	Matrix = (char **)calloc(ROW, sizeof(char *));
	for(i = 0; i < ROW; i++){
 		Matrix[i] = (char *)calloc(COLUMN, sizeof(char));
	}

	for(j = 0; j < COLUMN ; j++)
		for(i = 0 ; i < ROW ; i++ )
		{
			if(c < l)
			{
				Matrix[i][j] = toupper(str[c]);
				c = c + 1;
			}
			else
			{
				Matrix[i][j] = 'X';
			}
		}
	printf("Cypher text is \n");
	for ( i = 0; i < ROW; i++)
	{
		for(j = 0; j <COLUMN; j++)
		{
			printf("%c",Matrix[i][j]);
		}
	}
	printf("\n");
	printf("Plain text is\n");
	for(j = 0; j < COLUMN ; j++)
		for (i = 0; i < ROW; i++)
		 {
		 	printf("%c",tolower(Matrix[i][j]) );
		 } 
	printf("\n");
	return 0;
}


