#include <stdio.h>
#include <stdlib.h>

int main()
{
   char ch,temp;
   int arr[26] = {0};
   int cypher[27] = {0};
   int i,j,k = 7;
   FILE *fp;

   fp = fopen("s.txt","r"); // read mode
   if( fp == NULL )
   {
      perror("Error while opening the file.\n");
      exit(EXIT_FAILURE);
   }
   printf("The cypher text is : \n");
   while( ( ch = fgetc(fp) ) != EOF )
   {
      if(ch >= 'a' && ch <= 'z')
      {
         ++arr[ch - 'a'];
         //encryption by caesar cypher with key 7
         temp = (ch -'a' + 7) % 26;
         ++cypher[temp];
         printf("%c",(temp + 'a'));
      }
      if(ch >= 'A' && ch <= 'Z')
      {
         ++arr[ch - 'A'];
         //encryption by caesar cypher with key 7
         temp = (ch -'A' + 7) % 26;
         ++cypher[temp];
         printf("%c",(temp + 'A'));
      }
   }
   fclose(fp);
   printf("\n\n");
   printf("The frequency of the plain text is :\n");
   ch = 'a';
   for(i = 0 ; i < 26 ; i++)
   {
      printf("%c : ",ch);
      for(j = 1 ; j <= arr[i]; j++)
      {
         printf("-");
      }
      printf("\n");
      ++ch;
   }
   printf("The frequency of the cypher text is :\n");
   ch = 'a';
   for(i = 1 ; i <= 26 ; i++)
   {
      printf("%c : ",ch);
      for(j = 1 ; j <= cypher[i]; j++)
      {
         printf("-");
      }
      printf("\n");
      ++ch;
   }
   return 0;
}