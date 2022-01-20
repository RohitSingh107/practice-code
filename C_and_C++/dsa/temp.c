#include<stdio.h>

char a[50] = "EAS*Y*QUE***ST***IO*N***", s[20], b[30];
int top = -1;

char pop();

void push(char a)
{
  int i=0;
  if (top >= 24)
    printf("Overflow.");
  else
    s[++top]= a;
}
 char pop()
 {
    if (top < 0)
      printf("Underflow");
    else
      
      top--;

    return s[top+1];
 }
 void main()
{
  int i = 0;
  printf("%s\n", a);

  while(a[i] != '\0'){
      if(a[i] == '*'){
          printf("%c", pop());
      }
      else{
          push(a[i]);
      }
      i++;
  }

}