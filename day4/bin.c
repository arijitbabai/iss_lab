#include <stdio.h>
int main(int argc, char const *argv[])
{
	int j ,i = 7,c = 0; 
	int a[20][8] = {0};
	char *s = "Arijit";
	char *ch;
	ch = s;
 	while(*ch)
	{
		i =7;
		j = *ch;
		while(j > 0)
		{
			if(j%2 != 0)
			{
				a[c][i] = 1;
			}	
				i--;
			j = j/2;
		}
		c = c + 1;
		ch = ch + 1;
	}
	for(j = 0; j < 5 ; j++)
	{
		for(i = 0 ; i < 8 ; i++)
			printf("%d",a[j][i]);
		printf("\n");
	}
	printf("\n");
	printf("%d\n",*s);
	printf("%d\n",*(s+1));
	return 0;
}