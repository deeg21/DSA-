#include<stdio.h>

void ReverseString(char str[],int len)//reverse only one word
{
    char ts;
    int start=0,end=len-1;
    
    printf("\n%s\n",str);
    while(start<end) 
    {
         printf("\n %c %c\n",str[start],str[end]);

        
          while((str[start]>=33 && str[start]<48) || (str[start]>=58 && str[start]<65)||(str[start]>=123 && str[start]<127)||(str[start]>=91 && str[start]<=96))//ascii value of all special characters
             start+=1;//ascii
          while((str[end]>=33 && str[end]<48) || (str[end]>=58 && str[end]<65)||(str[end]>=123 && str[end]<127)|| (str[end]>=91 && str[end]<=96))//ascii value of all special characters
             end-=1;
             
          ts=str[start];
          str[start]=str[end];
          str[end]=ts;
          
          ++start;
          --end;
         
    }   //while
        
}

void reverse(char str[])
{
   int i=0,len=0;
   while(str[i++]!='\0')
     len++;

   ReverseString(str,len);
    //printf("\n%s\n",str);
    
}

int main(int argi,char argc[])
{
   /*if(argi>1)
   {
     reverse(argc[1]);
     printf("\n%s\n",argc[1]);
   }*/

  char arr[100]="a..bcdef";
  reverse(arr);
  printf("\n%s\n",arr);
}