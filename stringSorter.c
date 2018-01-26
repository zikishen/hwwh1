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


int insert(struct node *front,char * word)
{
  
  struct node *prev = NULL;
  struct node *ptr = front;
  int len1 = strlen(word);
  int len2 = strlen(ptr->str);
  int max; //// 1:ptr 2:word
  while(ptr!=NULL)
  {
  if(present(ptr,word))
  {
    struct node *new = malloc(sizeof(struct node));
    new->str = word;
    new->next = ptr->next;
    ptr->next = new;
    return 0;
    //return front;
  }
  int br=1;
    // 2.Comparasion
  while(*word!=NULL || *ptr->str!=NULL)
  {
    max = 0;
    if( *word == *ptr->str)
    {
      *word++;
      *ptr->str++;
      continue;
    }
    else
    {
      // both characters are Capital case
      // 1:ptr 2:word
      // int len1 = strlen(word);
      // int len2 = strlen(front->word);
      if((*word >= 65 && *word <= 90)&&(*ptr->str >= 65 && *ptr->str <= 90))
      {
        *word<(*ptr->str)?max=1:(max=2);
        br=0;
        break;
      }
      // one of the character is Capital case
      else if((*word >= 65 && *word <= 90)||(*ptr->str >= 65 && *ptr->str <= 90))
      {
        *word<(*ptr->str)?max=1:(max=2);
        br=0;
        break;
      }
      else
      {
        *word<(*ptr->str)?max=2:(max=1);
        br=0;
        break;
      }
    }
  }

  if(max==0)
  {
    if(len1>len2)
      return 2;
    else
      return 1;
  }
  else if(br==0)
  {
    return max;
  }

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
      printf ("%s\n",pch);
      if(front== NULL)
      {
        front = malloc(sizeof(struct node));
        front ->str = pch;
        front ->next = NULL;
      }
      else
      {
        insert(front,pch);
        printf("true\n");
      }
    //  printf ("%s\n",pch);
      pch = strtok(NULL, " ");
    }


  return 0;
}
