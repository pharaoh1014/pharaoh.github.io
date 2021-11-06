#include<stdio.h>
#include<malloc.h>
#define MaxSize 100
typedef struct Node
{
    int data;
    struct Node * ichild;
    struct Node * rchild;
}BiNode,*ab;
typedef struct
{
	BiNode *data[MaxSize];
	int front,rear;
}SqQueue;
int f[1001];
int m[1001];
int n;
BiNode * creatTree(int left,int right)
{
    if(left>right)
        return NULL;
    int mp=-1,temp=-1;
    for(int i=0;i<n;i++)
    {
        for(int j=left;j<=right;j++)
        {
            if(f[i]==m[j])
            {
                mp=j;
                break;
            }
        }
        if(mp!=-1)
        {
            temp=i;
            break;
        }
    }
    BiNode * root=(BiNode *)(malloc(sizeof(BiNode)));
    root->data=f[temp];
    root->ichild=creatTree(left,mp-1);
    root->rchild=creatTree(mp+1,right);
    return root;
}
void last(BiNode * root)
{
    if(root==NULL)
        return;
    if(root->ichild!=NULL)
        last(root->ichild);
    if(root->rchild!=NULL)
        last(root->rchild);
    printf("%d ",root->data);
}

void levelPrint(BiNode * p){
	ab stack[100];
	int front,real;
	front = real = 0;
	BiNode *curr ,*pre;
	pre = p;
	while(pre != NULL){
		printf("%d ",pre->data);
		curr = pre->ichild;
		if(curr != NULL){
			stack[real++] = curr;
		}
		curr = pre->rchild;
		if(curr != NULL){
			stack[real++] = curr;		
		} 
		if( front != real) 
			pre = stack[front++];
		else
			pre = NULL;
		
	}
}
int main()
           {
               scanf("%d",&n);
               for(int i=0;i<n;i++)
               {
                   scanf("%d",&f[i]);
               }
               for(int i=0;i<n;i++)
               {
                   scanf("%d",&m[i]);
               }
               BiNode * root=creatTree(0,n-1);
               levelPrint(root);
           }

