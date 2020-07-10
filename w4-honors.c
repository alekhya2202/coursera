#include<stdio.h>
#include<stdlib.h>

typedef struct Btree
{
int data;
struct Btree* left;
struct Btree* right;
}Btree;

//this prints the values of the nodes in order
void inorder(Btree* root)
{
    if(root != NULL)
    {
    inorder (root ->left);
    printf("%i",root ->data);
    inorder (root ->right);
    }
}

Btree* newnode(void)
{
    return malloc(sizeof(Btree));
}

//this initiates node with left and right
Btree* initnode(int d1,Btree* l,Btree* r)
{
    Btree* x=newnode();
    x->data=d1;
    x->left=l;
    x->right=r;
    return x;
}

//this method creates tree using array a[]
Btree* createtree(int a[],int i,int size)
{
    if(i>=size)
    return NULL;
  else
  return initnode(a[i],createtree(a,2*i+1,size),createtree(a,2*i+2,size));
}

void readdata (FILE *ptr,int d[],int *size)
{int n;
*size=0;
rewind(ptr);
fscanf(ptr,"%i",&n);  //n will take value of 1st parameter
//here is for loop to get values in list data of size as that of 1st prameter whic is (n)
for(int i=0;i<n;i++){
fscanf(ptr,"%i",&d[*size]);
(*size)++;
}
}
/*void printdata(int d[],int size)
{int i=0;
    while(i<size){
printf("%i\n",d[i]);
i++;
}
}*/
int main()
{
    int i;
    int sz;
FILE *ifp;
int data[20];  //here we initialize the array that we will put values we read from file inside and then give these values to binary tree
ifp=fopen("test.txt","r+");
readdata(ifp,data,&sz);
    Btree* x;
    x=createtree(data,0,sz);//here we create the binary tree form values inside data array with size(sz)
    inorder(x);//here we printes the values inorder
}
