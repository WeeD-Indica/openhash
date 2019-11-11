#include<stdio.h>
#include<stdlib.h>
#define size 10
typedef struct node
{
  int data;
  struct node *link;
}node;
 
node *arr[10];
void insert(int x);
void search(int x);
void display();

void main()
{
  int ch,c=1,key;
  for(int i=0;i<size;i++)
  arr[i]=NULL;
  while(c!=0)
    {
      printf("\n1.Insert\n2.Search\n3.Display\n");
      scanf("%d",&ch);
      switch(ch)
	{
	case 1:printf("Enter value:");
	  scanf("%d",&key);
	  insert(key);
	  break;
	case 2:printf("Enter value:");
	  scanf("%d",&key);
	  search(key);
	  break;
	case 3:display();break;
	default:printf("\nWrong input\n");
	}
      printf("\nDo you want to continue:(1|0)");
      scanf("%d",&c);
    }
}

void insert(int x)
{  
  int mod;
  node *ptr;
  node *newnode=(node*)malloc(sizeof(node*));
  newnode->data=x;
  newnode->link=NULL;
  mod=x%size;
  ptr=arr[mod];
  if(arr[mod]==NULL)
    {
      arr[mod]=newnode;
      return;
    }
  else
    {
      while(ptr!=NULL)
	if(ptr->link==NULL)
	  {
	    ptr->link=newnode;
	    return;
	  }
	else
	  ptr=ptr->link;
    }
  return;
}

void search(int x)
{
  node *ptr;
  int mod;
  mod=x%size;
  ptr=arr[mod];
  while(ptr!=NULL)
    {
      if(ptr->data==x)
	{
	  printf("\nElement found\n");
	  return;
	}
      else
	ptr=ptr->link;
    }
  printf("\nElement not found\n");
  return;
}

void display()
{
  node *ptr;
  for(int i=0;i<size;i++)
    {
      ptr=arr[i];
      while(ptr!=NULL)
	{
	  printf("%d  ",ptr->data);
	  ptr=ptr->link;
	}
      printf("\n");
    }
  return;
}
	
