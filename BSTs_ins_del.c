#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node* root=NULL;

void create_BST(int rdata){
    root=(struct node*)malloc(sizeof(struct node));
    root->data=rdata;
    root->left=NULL;
    root->right=NULL;
}

void insert_BST(struct node* root, int data) {
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    if (root==NULL){
        create_BST(data);
    }
    else{
        struct node*t1=root;
        struct node* preptr=NULL;
        while(t1!=NULL){
            preptr=t1;
            if (data<t1->data){
                t1=t1->left;
            }
            else{
                t1=t1->right;
            }
        }
        if(data<preptr->data) {
            preptr->left = temp;
        }
        else {
            preptr->right = temp;
        }
    }
}

bool search_BST(struct node *root, int data) {
    struct node *t1 = root;
    while(t1!=NULL) {
        if(t1->data == data) {
            return 1;
        }
        else if(data > t1->data) {
            t1 = t1->right;
        }
        else {
            t1 = t1->left;
        }
    }
    return 0;
}

void delete_BST(struct node *root, int data) {

    if(search_BST(root, data)) {
        struct node *t1=root;
        struct node *prevt1 = root;
        while(t1->data != data) {
            prevt1 = t1;
            if(t1->data < data) {
                t1 = t1->right;
            }
            else {
                t1 = t1->left;
            }
        }

        if(t1->left != NULL) {
            struct node *t2 = t1->left;
            struct node *prevt2 = t1;
            if(t2->right == NULL) {
                t2->right = t1->right;
                if(prevt1->right == t1) {
                    prevt1->right = t2;
                }
                else {
                    prevt1->left = t2;
                }
            }
            else {
                while(t2->right != NULL) {
                    prevt2 = t2;
                    t2 = t2->right;
                }
                prevt2->right = NULL;
                t2->right = t1->right;
                t2->left = t1->left;
                if(prevt1->right == t1) {
                    prevt1->right = t2;
                }
                else {
                    prevt1->left = t2;
                }
            }
        }
        else if(t1->right != NULL) {
            struct node *t2 = t1->right;
            struct node *prevt2 = t1;
            if(t2->left == NULL) {
                t2->left = t1->left;
                if(prevt1->right == t1) {
                    prevt1->right = t2;
                }
                else {
                    prevt2->right = t2;
                }
            }
            else {
                while(t2->left != NULL) {
                    prevt2 = t2;
                    t2 = t2->left;
                }
                prevt2->left = NULL;
                t2->right = t1->right;
                t2->left = t1->left;
                if(prevt1->right == t1) {
                    prevt1->right = t2;
                }
                else {
                    prevt1->left = t2;
                }
            }
        }

        else if(t1->left == NULL && t1->right == NULL){
            if(prevt1->right == t1) {
                prevt1->right = NULL;
            }
            else {
                prevt1->left = NULL;
            }
        }
    }
    else {
        printf("No such node present in the tree\n");
    }
}

void preorder(struct node* root) {
	if(root != NULL){
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(struct node* root) {
	if (root != NULL){
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}

void postorder(struct node* root) {
	if (root != NULL){
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->data);
	}
}

int main(){
    printf("MENU:\n");
    printf("1. Create Binary Search Tree\n");
    printf("2. Insert element\n");
    printf("3. Node present or not\n");
    printf("4. Delete element\n");
    printf("5. Preorder Traversal\n");
    printf("6. Inorder Traversal\n");
    printf("7.Postorder Traversal\n");
    printf("8. Exit\n");
    int ch, data;
    do{
        printf("Enter Choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                // Create root
                printf("Enter root of tree : ");
                scanf("%d",&data);
                create_BST(data);
            break;

            case 2:
                // Insert in tree
                printf("Enter data:");
                scanf("%d",&data);
                insert_BST(root,data);
            break;

            case 3:
                // Search in tree
                printf("Enter data: ");
                scanf("%d",&data);
                if(search_BST(root, data)) {
                    printf("Node Present\n");
                }
                else {
                    printf("Node Absent\n");
                }
            break;
            
            case 4:
                // delete in BST
                printf("Enter data: ");
                scanf("%d", &data);
                delete_BST(root, data);
            break;

            case 5:
                // Preorder traversal
                printf("Preorder -> ");
                preorder(root);
                printf("\n");
            break;

            case 6:
                // Inorder traversal
                printf("Inorder -> ");
                inorder(root);
                printf("\n");
            break;

            case 7:
                // Postorder traversal
                printf("Postorder -> ");
                postorder(root);
                printf("\n");
            break;

            case 8:
                // Program complete.
                printf("Ending the program\n");
            break;

            default:
                printf("Invalid Choice Try Again\n");
            break;
        }
    }while(ch!=8);
}