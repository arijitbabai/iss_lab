#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
   if (argc < 2)
   {
      printf("Error in input....\n");
      exit(0);
   }
   char name[50];
   size_t n = 100;
   int i,ROW,COLUMN,x,count,max;
   char *str,*msg,*p;
   int a[50][8] = {{0}};

   FILE *img,*op;

   op = fopen(argv[2],"w");
   
   img = fopen(argv[1],"r"); // read mode
   
   fscanf(img,"%s\n",name);
   fprintf(op,"%s\n",name);
   
   str = (char *)malloc(n + 1);
   getline(&str,&n,img);
   fprintf(op,"%s",str);

   fscanf(img,"%d %d\n%d\n",&ROW,&COLUMN,&max);
   fprintf(op, "%d %d\n%d\n",ROW,COLUMN,max);
   
   printf("Enter the message to encrypt\n");
   msg = (char *)malloc(n+1);
   getline(&msg, &n, stdin);
   
   count = 0;
   p = msg;
   while(*p!= '\0')
   {
      x = *p;
      i = 0;
      while(i < 8)
      {
         if(x%2 != 0)
         {
            a[count][i] = 1;
         }  
            i++;
         x = x/2;
      }
      count++;
      p++;
   }
   for(i = 0 ; i < 8 ; i++)
      a[count][i] = 1;
   int *b;
   b =(int *) a;
   int nturns = ROW * COLUMN;
   for(i = 0; i < nturns ; i++)
   {
         fscanf(img,"%d",&x);
         if(i <= count * 8)
         {
            if(x%2 != *(b++))
            {
               if(x%2 == 0)
                  x = (x + 1);
               else
                  x = (x - 1);
            }
            
         }
            fprintf(op,"%d%s",x, "  ");
   }

   fclose(img);
   fclose(op);
   return 0;
}