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
void freeList(struct node* head)
{
   struct node* tmp;

   while (head != NULL)
    {
       tmp = head;
       head = head->next;
       free(tmp);
    }

}

// trimming whitespace and non-alphabetical letter
struct node * insert(struct node *front,char * word)
{
  struct node *prev = front;
  struct node *ptr = front;
  int len1 = strlen(word);
  int len2 = strlen(ptr->str);
 //// 1:word 2:ptr
  while(ptr!=NULL)
  {
    int max = 0;

    len2 =strlen(ptr->str);
    // Comparasion
    int word_bigger=0;
    // word_bigger is a flag to show that when word is bigger than ptr, ptr should move to the next node
    int i=0;
    char * ptr_str = ptr->str;
    while(i < len1 && i <len2)
  {
    if( word[i] == ptr_str[i])
    {
      //printf("0 word is %c ptr_str is %c\n",word[i],ptr_str[i] );
      //printf("i is %d, len1 is %d, len2 is %d\n",i,len1,len2 );

      i++;
      continue;
    }
    else
    {
      /*
          1. both characters are lowercase or Capital case
         1:word 2:ptr
      */
      if(((word[i] >= 65 && word[i] <= 90)&&(ptr_str[i] >= 65 && ptr_str[i] <= 90))
      ||(((word[i] >= 97 && word[i] <= 122)&&(ptr_str[i] >= 97 && ptr_str[i] <= 122))))
      {
        //printf("1 word is %c ptr_str is %c\n",word[i],ptr_str[i] );
        //printf("i is %d, len1 is %d, len2 is %d\n",i,len1,len2 );
        word[i]<(ptr_str[i])?max=2:(max=1);
        if(max==1)
        {
          word_bigger=1;
          break;
        }
      else
        {
        //  printf("2 word is %c ptr_str is %c\n",word[i],ptr_str[i] );
        //  printf("i is %d, len1 is %d, len2 is %d\n",i,len1,len2 );

          if(ptr==front)
            {
              struct node * new = malloc(sizeof(struct node));
              new->str = word;
              new->next = ptr;
              //printList(new);
              return new;
            }
            else
            {
              struct node * new = malloc(sizeof(struct node));
              new->str = word;
              new->next = prev->next;
              prev->next = new;
              //printList(front);
              return front;
            }

          }
        }
      // 2. one of the character is Capital case and the other is lowercase
      else if(((word[i] >= 65 &&word[i] <= 90)||(ptr_str[i] >= 97 && ptr_str[i] <= 122))
      ||((word[i] >= 97 &&word[i] <= 122)||(ptr_str[i] >= 65 && ptr_str[i] <= 90)))
      {
        //printf("3 word is %c ptr_str is %c\n",word[i],ptr_str[i] );
        //printf("i is %d, len1 is %d, len2 is %d\n",i,len1,len2 );

        word[i]<(ptr_str[i])?max=1:(max=2);
        if(max==2) //word is word_bigger
        {
          word_bigger=1;
          break;
        }
        else
        {
          //printf("4 word is %c ptr_str is %c\n",word[i],ptr_str[i] );
          //printf("i is %d, len1 is %d, len2 is %d\n",i,len1,len2 );

          if(ptr==front)
            {
              struct node * new = malloc(sizeof(struct node));
              new->str = word;
              new->next = ptr;
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
    //printf("5 word is %c ptr_str is %c\n",word[i],ptr_str[i] );
    //printf("i is %d, len1 is %d, len2 is %d\n",i,len1,len2 );

    if(len1 < len2)
    {
      if(ptr==front)
      {
        struct node * new = malloc(sizeof(struct node));
        new->str = word;
        new->next = ptr;
        //printList(front);

        return new;
      }
      else
      {
        struct node * new = malloc(sizeof(struct node));
        new->str = word;
        new->next = prev->next;
        prev->next = new;
        //printList(front);
        //printList(front);

        return front;
      }
    }
      else if(len1 > len2)
      {
        prev = ptr;
        ptr = ptr->next;
        i++;
        //printList(front);

        continue;
      }
      else
      {
        struct node * new = malloc(sizeof(struct node));
        new->str = word;
        new->next= ptr->next;
        ptr->next = new;
        return front;
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
        //printf ("insert: %s\n",pch);
        front = insert(front,pch);
      }
      pch = strtok(NULL, " ");
    }
    printList(front);
    //freeList(front);
    //free(input);
    return 0;
}
