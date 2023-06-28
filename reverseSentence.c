#include<stdio.h>

void ReverseString(char str[], int len)//reverse only one word
{
    char ts;
    for(int i=0;i<len/2;++i)
    {
        ts=str[i];
        str[i]=str[len-i-1];
        str[len-i-1]=ts;
       
    }
}

void reverse_words(char str[])//reverse a sentence
{

    int w_start=0;
    for(int i=0;str[i]!='\0';++i)
    {
        //take the starting position of the string
        
        if(str[i]==' ')//end of a word
        {
          
           ReverseString(&str[w_start],i-w_start);
           w_start=i+1;//store the starting position of next word
        }
        else if(str[i+1]=='\0')
        {
          
           ReverseString(&str[w_start],i-w_start+1);
           w_start=0;//store the starting position of next word
        }
          
     


         
    }
  
}



int main(int argi,char* argv[])
{

    char sentence[100]="Programming is a good skill!!";
    reverse_words(sentence);
    
   printf("\n%s\n",sentence);
   
   if(argi>1)
      reverse_words(argv[1]);
   printf("\n%s\n",argv[1]);
}