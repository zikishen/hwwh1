#ifndef SORTER_H
#define SORTER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char * str;
    struct node *next;
};

void trim(char * str)
// trimming whitespace and non-alphabetical letter
{
  int index;
  index = 0;
  while(index<strlen(str))
    {
      if(str[index]<65)
      {
        str[index]=' ';
      }
      else if(str[index]>90&&str[index]<97)
      {
        str[index]=' ';
      }
      else if(str[index]>122)
      {
        str[index]=' ';
      }
        index++;
  }
}

  void printList(struct node *head)
{
    struct node *temp = head;
    while(temp != NULL)
    {
        printf("%s\n", temp->str);
        temp = temp->next;
    }
}



#endif
