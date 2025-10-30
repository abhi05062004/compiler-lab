#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int m,n,i;
char a[10][10],f[100];

void first(char c);
void follow(char c);

int main()
{
int z;
char c;
  printf("Enter the number of production\n");
  scanf("%d", &n);
  printf("Enter the productions:\n");
  for(int i=0;i<n;i++)
  {
    scanf(" %s",a[i]);
  }
  do
  {
    m=0;
    printf("enter the element whose first and follow to be found\n");
    scanf(" %c", &c);
    first(c);
    printf("FIRST(%c)={",c);
    for(int i=0;i<m;i++)
    {
      printf("%c,",f[i]);
    }
    printf("}\n");
         strcpy(f,"");
    m=0;
    follow(c);
    printf("FOLLOW(%c)={",c);
    for(int i=0;i<m;i++)
    {
      printf("%c,",f[i]);
    }
    printf("}\n");  
   printf("continue(0|1)");
    scanf("%d",&z);
  }while(z==1);
  return 0;
  }
  
void first(char c)
  {
    int k;
    if(islower(c))
    {
      f[m++]=c;
     }
    for(k=0;k<n;k++)
    {
     if(a[k][0]==c)
     {
      if(a[k][2]=='$' || a[k][2]=='e')
        {
          f[m++]=a[k][2];
       }
      else if(islower(a[k][2])) 
          f[m++]=a[k][2];
      else
      first(a[k][2]);
    }
  }
  }
void follow(char c)
{
  int j,i;
  if(a[0][0]==c)
  {
    f[m++]='$';
   }
   for(i=0;i<n;i++)
   {
    for(j=2;j<strlen(a[i]);j++)
    {
      if(a[i][j]==c)
      {
        if(a[i][j+1]=='\0')
        {
          if(c!=a[i][0])
          {
            follow(a[i][0]);
          }
        }
          else
          {
            if(islower(a[i][j+1]))
            {
              f[m++]=a[i][j+1];
            }
              else
              {
              first(a[i][j+1]);
            }
          }
        }
      }
    }
  }
            
    
