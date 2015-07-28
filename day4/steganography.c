#include <stdio.h>
#include <stdlib.h>

int main()
{
   char name[50];
   size_t n = 100;
   int i,j,ROW,COLUMN,x,count;
   int k,l;
   int max;
   char *str,*msg,*p;
   int **Matrix,a[50][8] = {0};

   FILE *fp,*fp1;

   fp1 = fopen("p.pgm","w");
   if( fp1 == NULL )
   {
      perror("Error while opening the file.\n");
      exit(EXIT_FAILURE);
   }

   fp = fopen("LenaASCII.pgm","r"); // read mode
   if( fp == NULL )
   {
      perror("Error while opening the file.\n");
      exit(EXIT_FAILURE);
   }

   fscanf(fp,"%s\n",name);
   fprintf(fp1,"%s\n",name);
   
   str = (char *)malloc(n + 1);
   getline(&str,&n,fp);
   fprintf(fp1,"%s",str);

   fscanf(fp,"%d %d\n",&ROW,&COLUMN);
   fprintf(fp1, "%d %d\n",ROW,COLUMN);
   
   fscanf(fp,"%d\n",&max);
   fprintf(fp1, "%d\n",max );
   
   // Matrix = (int **)calloc(ROW, sizeof(int *));
   // for(i = 0; i < ROW; i++){
   //    Matrix[i] = (int *)calloc(COLUMN, sizeof(int));
   // }
   
   printf("Enter the message to encrypt\n");
   getline(&msg,&n,stdin);
   
   count = 0;
   p = msg;
   while(*p)
   {
      x = *p;
      i = 7;
      while(x > 0)
      {
         if(x%2 != 0)
         {
            a[count][i] = 1;
         }  
            i--;
         j = j/2;
      }
      count++;
   }

   for(i = 0; i < ROW ; i++)
   {
      k = 0;
      l = 0;
      for(j = 0 ; j < COLUMN ; j++)
      {
         fscanf(fp,"%d",&x);
         if((x%2 == a[k][l]))
         {}
            else 
               if(x%2 == 0)
               x = (x + 1);
               else
                  x = (x - 1);
         
         k = (k + 1) % count;
         l = (l + 1) % count;
         fprintf(fp1,"%d",x);
      }
   }
   


   return 0;
}