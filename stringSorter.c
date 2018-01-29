#include "helper.h"

void trim(char * str);
void printList(struct node *head);
// trimming whitespace and non-alphabetical letter
struct node * insert(struct node *front,char * word)
{
  struct node *prev = front;
  struct node *ptr = front;
  int max = 0;
  int len1 = strlen(word);
  int len2 = strlen(ptr->str);
 //// 1:word 2:ptr
  while(ptr!=NULL)
  {
  /*if(present(ptr,word))
  {
    struct node *new = malloc(sizeof(struct node));
    new->str = word;
    new->next = ptr->next;
    ptr->next = new;
    return front;
    //return front;
  }
  */
      // Comparasion
    int word_bigger=0;
    // word_bigger is a flag to show that when word is bigger than ptr, ptr should move to the next node
    int i=0;
    char * ptr_str = ptr->str;
    while(i<=len1&&i<=len2)
    //while(*word!=NULL && *ptr->str!=NULL)
  {
    //printf("*word is %c\n",word[i]);
    //printf("ptr_str is %c\n",ptr_str[i]);
    if( word[i] == ptr_str[i])
    {
      i++;
    //printf("*word is %c\n",word[i]);
    //printf("ptr_str is %c\n",ptr_str[i]);
      continue;
    }
    else
    {
      /* 1. both characters are lowercase or Capital case
      // 1:ptr 2:word
      // int len1 = strlen(word);
      */ int len2 = strlen(ptr->str);
      if(((word[i] >= 65 && word[i] <= 90)&&(ptr_str[i] >= 65 && ptr_str[i] <= 90))
      ||(((word[i] >= 97 && word[i] <= 122)&&(ptr_str[i] >= 97 && ptr_str[i] <= 122))))
      {
        word[i]<(ptr_str[i])?max=2:(max=1);
        if(max==1)
        {
          //printf("%s %d's index: %c is bigger\n",word,i,word[i]);
          int word_bigger=1;
          break;
        }
      else
        {
          //printf("%s %d's index: %c is bigger\n",ptr_str,i,ptr_str[i]);

          if(ptr==front)
            {
              struct node * new = malloc(sizeof(struct node));
              new->str = word;
              new->next = ptr;
              //printf("new->str is %s\n", word);
              //printf("new->str is %s\n", ptr_str);
              return new;
            }
            else
            {
              struct node * new = malloc(sizeof(struct node));
              new->str = word;
              new->next = prev->next;
              prev->next = new;
              return front;
            }

          }
        }
      // 2. one of the character is Capital case and the other is lowercase
      else if(((word[i] >= 65 &&word[i] <= 90)||(ptr_str[i] >= 97 && ptr_str[i] <= 122))
      ||((word[i] >= 97 &&word[i] <= 122)||(ptr_str[i] >= 65 && ptr_str[i] <= 90)))
      {
        word[i]<(ptr_str[i])?max=1:(max=2);
        if(max==2)
        {
          //printf("1 %s %d's index: %c is bigger\n",ptr_str,i,ptr_str[i]);
          int word_bigger=1;
          break;
        }
        else
        {
          //printf("2 %s %d's index: %c is bigger\n",word,i,word[i]);
          if(ptr==front)
            {
              struct node * new = malloc(sizeof(struct node));
              new->str = word;
              new->next = ptr;
              //printf("new->str is %s\n", word);
              //printf("new->str is %s\n", ptr_str);
              return new;
            }
            else
            {
              struct node * new = malloc(sizeof(struct node));
              new->str = word;
              new->next = prev->next;
              prev->next = new;
              return front;
            }
        }
      }
    }
    i++;
  }

  if(word_bigger==1)
  {
    prev = ptr;
    ptr = ptr->next;
    i++;
    continue;
  }
  if(max==0)
  {
    if(len1>len2)
    {
      if(ptr==front)
      {
        struct node * new = malloc(sizeof(struct node));
        new->str = word;
        new->next = ptr;
        printf("new->str is %s\n", word);
        printf("new->str is %s\n", ptr_str);
        return new;
      }
      else
      {
        struct node * new = malloc(sizeof(struct node));
        new->str = word;
        new->next = prev->next;
        prev->next = new;
        return front;
      }
    }
      else
      {
        prev = ptr;
        ptr = ptr->next;
        i++;
        continue;
      }
    }
  prev = ptr;
  ptr = ptr->next;
  i++;
  }
    // when we should place the word in the last place, "Hello there"
    struct node * new = malloc(sizeof(struct node));
    new->str = word;
    new->next = NULL;
    prev->next = new;
    return front;
}


int main(int argc, char ** argv)
{
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
  struct node *front = NULL;
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
        printf ("insert: %s\n",pch);
        front = insert(front,pch);
      }
      pch = strtok(NULL, " ");
    }
    printList(front);
    return 0;
}
