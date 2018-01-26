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
  int index,i;
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

int cases(char * a)
// 0:lowercase 1:Capital
{
  char  found_lower = false, found_upper = false  ;
  for (int i = 0; str[i] != '\0'; i++)
  {
    found_upper = found_upper || (str[i] >= 65 && str[i] <= 90);
    if (found_upper)
    {
      return 1;
    }
  }
  return 0;
}

int present(struct node *head, char * val)
{
    if(head == NULL)
    {
        return 0;
    }
    struct node *tmp = head;
    while(tmp !=NULL)
    {
        if(strcmp(tmp->str,val)==0)
        {
            return 1;
        }
        tmp = tmp->next;
    }
    return 0;
}


struct node * insert(struct node *front,char * word)
{
  struct node *prev = NULL;
  struct node *ptr = front;
  int case_1= cases(word);

  while(ptr!=NULL)
  {
    // 1.duplicate
  if(present(ptr,word))
  {
    struct node *new = malloc(sizeof(struct node));
    new->str = word;
    new->next = ptr->next;
    ptr->next = new;
    return front;
  }
    // 2.Capital and lowercase
    // 2-1. when front is lowercase but word is Capital case
  int case_2= cases(ptr.str);
  if(case_1>case_2 && ptr==front)
  {
    struct node *new = malloc(sizeof(struct node));
    new->str = word;
    new->next = ptr;
    return new;
  }
    // 2-2. when the inserted word is Capital case as the front, and bigger than ptr
  else if(case_1>case_2)
  {
    struct node *new = malloc(sizeof(struct node));
    new->str = word;
    new->next = prev->next;
    prev->next = new;
    return front;
  }
    // 3. normal condition
    // case_1 stands for the input word
    // case_2 stands for the current node
  else if(case_1 == 1 %% case_1== case_2)
  {
    int i=0;
    for(i;i<)
  }
  else
  {

      {

      }
  }

  int index=0;

  prev = ptr;
  ptr = ptr.next;
  }
}

int main(int argc, char ** argv)
{
  //printf("argc is %d\n",argc);
  if(argc!=2)
    {
      printf("Error\n");
      return 0;
    }
  int len = strlen(argv[1]);
  char * input = malloc(len*sizeof(char));
  input = argv[1];
  trim(input);
  char *pch;
  pch = strtok (input," ");
  struct node *front;
  while(pch != NULL)
    {
      if(front== NULL)
      {
        front = malloc(sizeof(struct node));
        front ->str = pch;
        front ->next = NULL;
      }
      else
      {
        insert(front,pch);
      }
      printf ("%s\n",pch);
      pch = strtok(NULL, " ");
    }


  return 0;
}
