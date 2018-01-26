#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node {
    char * str;
    struct node *next;
};

struct node *  uu(int i) {
   char * a = "ABC";
   char * b = "ABC";
   int max;
   struct node * front = malloc(sizeof(struct node));
   struct node * ptr = front;
   char * c = "ABC";
   front ->next = NULL;
   struct node * new = malloc(sizeof(struct node));
   new->str = "BCD";
   new->next = NULL;
   ptr -> next = new;
   return front;
  // while(*c!=NULL)
   //{
     //printf("%c\n",*c );
     //*c++;
   //}
  // a==b?max=1:(max=2);
   //printf("%d\n",max );

}
int main()
{

  struct node * c = uu(0);
  while(c!=NULL)
  {
    printf("%s\n",c->str);
  }
  return 1;
}
