#include<stdio.h>
#include<stdlib.h>
struct tree
{
    struct tree *left;
    int data;
    struct tree *right;
};

struct tree *root;

struct tree *create_bst(struct tree *root, int item)
{
    struct tree *p, *cur, *prev;
    p = (struct tree *)malloc(sizeof(struct tree));

    p->left = NULL;
    p->right = NULL;
    p->data = item;

    if (root == NULL)
        root = p;

    else
    {
        cur = root;
        while (cur != NULL)
        {
            prev = cur;

            if (item < cur->data)
                cur = cur->left;

            else
                cur = cur->right;
        }
        if (item < prev->data)
            prev->left = p;

        else
            prev->right = p;
    }
    return root;
}

void preorder(struct tree *p)
{
    if (p != NULL)
    {
        printf("%d->", p->data);
        preorder(p->left);
        preorder(p->right);
    }
}

void inorder(struct tree *p)
{
    if (p != NULL)
    {
        inorder(p->left);
        printf("%d->", p->data);
        inorder(p->right);
    }
}
void postorder(struct tree *p)
{
    if (p != NULL)
    {
        postorder(p->left);
        postorder(p->right);
        printf("%d->", p->data);
    }
}

struct tree *del(struct tree *root, int item)
{
    struct tree *cur = root, *par, *child, *insuc;
    int value;
    while (cur->data != item)
    {
        par = cur;
        if (cur->data > item)
            cur = cur->left;
        else
            cur = cur->right;
        if (cur == NULL)
        {
            printf("not found\n");
            return root;
        }
    }
 //Deleted the node with zero child
    if (cur->right == NULL && cur->left == NULL)
    {
        if (cur == root)
        {
            printf("deleted root and the tree is empty\n");
            root = NULL;
            return root;
        }
        if (par->left == cur)
            par->left = NULL;
        else
            par->right = NULL;
    }
    else if (cur->right == NULL || cur->left == NULL)
    {
        if (cur->left != NULL)
            child = cur->left;
        else
            child = cur->right;
        if (cur == root)
        {
            if (cur->left == NULL)
                root = cur->right;
            else
                root = cur->left;
        }
        else
        {
            if (cur == par->left)
                par->left = child;
            else
                par->right = child;
        }
    }
    else
    {
        insuc = cur->right;
        while (insuc->left != NULL)
            insuc = insuc->left;
        value = insuc->data;
        del(root, insuc->data);
        cur->data = value;
    }
    return root;
}

int height(struct tree *root)
{
    if (root==NULL)
    return 0;
int x , y;
x = height(root->right);
y = height(root->left);

return x>y? x+1 : y+1 ;
    
}

void printcurrentlevel(struct tree *root, int level)
{
  if (root==NULL)
  return;

if(level==0){
printf("The nodes are %d\n",root->data);
}

else if(level>0)
{

    printcurrentlevel(root->left, level-1);
    printcurrentlevel(root->right, level-1);
}
}


// int sumAtk(struct tree *root, int k)
// {
//     int level = sum=0;
//     if(root==NULL)
//     return -1;

//     queue<struct tree*>q;
//     q.push(root);
//     q.push(NULL);


//     while(!q.empty())
//     {
//         struct tree *newnode = q.front();
//         q.pop();
        
         
// if(node!=NULL)
// {
//     if(level==k)
//     sum += root->data;


// if(root->right)
//    q.push(root->right);

// if(root->left)
//  q.push(root->left);
// }

// else if(!q.empty())
// {
//     q.push(NULL);
// level++;
// }
          
//             }
// return sum;
// }


int main()
{
    root = NULL;
    int item;
    printf("Enter the elements of the tree....\n");
    scanf("%d", &item);

    while (item != -999)
    {
        root = create_bst(root, item);
        scanf("%d", &item);
    }
  preorder(root);
  printf("\n");
    printf("Please enter the item to be searched and deleted....\n");
    scanf("%d", &item);

    root = del(root, item);
    preorder(root);printf("\n");
// inorder(root);printf("\n");
// postorder(root);printf("\n");
// printf("The Height of given BST is %d\n",height(root));
//for(int i = 0; i<;i++)
printcurrentlevel(root,2);


//printf("\nThe sum at %dth level is %d\n",sumAtk(root,3));
    return 0;
}
