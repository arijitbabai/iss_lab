#include <stdio.h>

int encrypt(int a, int b, int n);
int decrypt(int a, int b, int n);
int gcd(int a, int b);

int main(void){

	//Key generation
	int p,q,n,fi;
	p = 61;
	q = 53;
	n = p * q;
	fi = (p - 1)*(q - 1);
	//public key
	int i,e;
	for(i = fi - 1 ; i > 1 ; i--){
		if(gcd(fi,i) == 1){
			e = i;
			break;
		}
	}
	printf("Public : %d, %d\n",e,n);
	//private key
	int d;
	i = 0;
	while(++i){
		d = e * i;
		if(d % fi == 1){
			break;
		}
	}
	d = i;
	printf("private : %d, %d\n",d,n);
	int c,plaintext = 88;
	c = encrypt(plaintext,e,n);
	printf(" Cypher : %d\n",c);
	plaintext =decrypt(c,d,n);
	printf("Plain : %d\n",plaintext);
	 return 0;
}

int gcd ( int a, int b )
{
  if ( a==0 ) return b;
  return gcd( b%a, a );
}

int encrypt(int a, int b, int n){
	int i,f;
	int x = 1;
	int k = 0;
	while( b > x -1 ){
		x = x << 1;
		k++;
	}
	// printf("%d\n",k);
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
	return f;
}

int decrypt(int a, int b, int n){
	int i,f;
	int x = 1;
	int k = 0;
	while( b > x -1 ){
		x = x << 1;
		k++;
	}
	// printf("%d\n",k);
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
	return f;
}
		
	
			
	
	
		
