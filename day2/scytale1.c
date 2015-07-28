#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

char* encryption(char *s,int k);
void decryption(char *s, int k);



int main(int argc, char const *argv[])
{
	int n;
	char *s,*cypher;
	printf("Enter the key for encryption\n");
	scanf("%d",&n);
	printf("Enter the plain text: \n");
	scanf("%s",s);
	cypher = encryption(s,n);
	printf("%s",cypher);
	printf("\n");
	decryption(cypher,n);

	// printf("Plain text is\n");
	// for(j = 0; j < COLUMN ; j++)
	// 	for (i = 0; i < ROW; i++)
	// 	 {
	// 	 	printf("%c",tolower(Matrix[i][j]) );
	// 	 } 
	// printf("\n");
	return 0;
}


char* encryption(char* s, int k)
{

	char **Matrix,*cypher;
	int ROW , COLUMN,l,i,j,c = 0;
	ROW = k;
	l = strlen(s);
	COLUMN = (int)ceil((float)l/ROW);
	printf("%s\n",s );
	printf("%d\n",COLUMN);
	cypher = (char *)malloc(sizeof(char));
	Matrix = (char **)calloc(ROW, sizeof(char *));
	for(i = 0; i < ROW; i++){
		Matrix[i] = (char *)calloc(COLUMN, sizeof(char));
	}

	for(j = 0; j < COLUMN ; j++)
	{
		for(i = 0 ; i < ROW ; i++ )
		{
			if(c < l)
			{
				Matrix[i][j] = toupper(s[c]);
				c = c + 1;
			}
			else
			{
				Matrix[i][j] = 'X';
				c = c + 1;
			}
		}
	}
	int t = 0;
	printf("Cypher text is \n");
	for ( i = 0; i < ROW; i++)
	{
		for(j = 0; j < COLUMN; j++)
		{
			cypher[t] = Matrix[i][j];
			t++;
		}
	}
	printf("\n");
	return cypher;
}

void decryption(char* s, int k)
{
	char **Matrix;
	int ROW , COLUMN,l,i,j,c = 0;
	ROW = k;
	l = strlen(s);
	COLUMN = (int)ceil((float)l/ROW);
	printf("%s\n",s );
	printf("%d\n",COLUMN);
	Matrix = (char **)calloc(ROW, sizeof(char *));
	for(i = 0; i < ROW; i++){
		Matrix[i] = (char *)calloc(COLUMN, sizeof(char));
	}

	for(i = 0; i < ROW ; i++)
	{
		for(j = 0 ; j < COLUMN ; j++ )
		{
			
				Matrix[i][j] = tolower(s[c]);
				c = c + 1;
			
		}
	}
	int t = 0;
	printf("plain text is \n");
	for ( j = 0; j < COLUMN; j++)
	{
		for(i = 0; i < ROW; i++)
		{
			printf("%c",Matrix[i][j]);
		}
	}
	printf("\n");
}