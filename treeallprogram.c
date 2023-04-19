#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node* createnode(int data){
    struct node* n=(struct node*)malloc(sizeof(struct node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}
struct node * insert(struct node* root,int data){
    if(root==NULL){
        return createnode(data);
    }
    if(data<root->data){
        root->left=insert(root->left,data);
    }
    else if(data>root->data){
        root->right= insert(root->right,data);

    }
    return root;
}
void inorder(struct node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d",root->data);
    inorder(root->right);
}
void preorder(struct node* root){
    if(root==NULL){
        return ;
    }
    printf("%d",root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct node* root){
    if(root==NULL){
        return ;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d",root->data);
}
int main(){
    struct node* root=NULL;
    int n;
    int choice;
    do{
        printf("\nMenu\n");
        printf("1.create a binary tree:\n");
        printf("2.inorder traversal:\n");
        printf("3.preorder traversal:\n");
        printf("4: postorder traversal\n");
        printf("5.Exit:\n");
        printf("enter your choice:");
        scanf("%d",&choice);

        switch(choice){
            case 1:
            root=NULL;
            int elements;
            printf("enter how many elements you want to store in binary tree:");
            scanf("%d",&n);
            printf("enter the element:");
            for(int i=0;i<n;i++){
                scanf("%d",&elements);
                root=insert(root,elements);
            }
            break;
            case 2:
                printf("inorder traversal:");
                inorder(root);
                break;
            case 3:
                printf("preorder traversal:");
                preorder(root);
                break;
            case 4:
                printf("postorder traversal:");
                postorder(root);
                break;
            case 5:
                exit(0);
                break;
        }
    }
    while(choice!=5);
    return 0;
}