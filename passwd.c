#include <stdio.h>
#include <unistd.h>
#include <string.h>
 
int main(int argc, char const *argv[])
{
	char *pass;//Variable to hold the password
	char *t;
	int i = 0,j = 0 ,k = 0,l = 0;
	//Taking the input
	pass = getpass("Enter your password");
	t = pass;
	//Checkig the string length
	if(strlen(pass) < 6)
	{
		printf("Password is too short....\n");
		printf("%s\n",pass);
		return 0;
	}
	//Charactize the password
	while(*t)
	{
		if(isupper(*t))
			i=1;
		else if(islower(*t))
			j=1;
		else if(isdigit(*t))
			k=1;
		else 
			l=1;
		t = t + 1;
	}
	//Printing the type of password
	
	if(i && j && k && l)
		printf("Very strong\n");
	else if(i && j && k )
		printf("Strong\n");
	else if(i && j)
		printf("Moderate\n");
	else if(i || j || k || l)
		printf("Weak\n");

	return 0;
}