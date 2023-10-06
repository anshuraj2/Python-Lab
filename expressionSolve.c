#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *left, *right;
};

struct node *newNode (int item)
{
  struct node *temporary = (struct node *) malloc (sizeof (struct node));
  temporary->data = item;
  temporary->left = temporary->right = NULL;
  return temporary;
}

void inorder (struct node *root)
{
  if (root != NULL)
    {
      inorder (root->left);
      printf ("%d ", root->data);
      inorder (root->right);
    }
}

struct node *insert (struct node *node, int data)
{
  if (node == NULL)
    return newNode (data);
  if (data < node->data)
    node->left = insert (node->left, data);
  else if (data > node->data)
    node->right = insert (node->right, data);

  return node;
}

int main ()
{
  int n,rt,i=0,val;
  struct node *root = NULL;
  printf("Enter no. of nodes : ");
  scanf("%d",&n);
  printf("Enter root node : ");
  scanf("%d", &rt);
  printf("Enter the nodes other than root \n");
  root = insert (root, rt);
  for(i=0; i<n-1; i++){
      scanf("%d", &val);
      insert (root, val);
  }
  printf ("The inorder is :\n");
  inorder (root);

  return 0;
}