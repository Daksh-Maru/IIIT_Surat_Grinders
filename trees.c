#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *left;
    struct node *right;
};
struct node *root = NULL;

struct node* create_BT() {
    int n;
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    if(root == NULL) {
        printf("Enter the data : ");
    }
    scanf("%d", &new_node->data);
    if(new_node->data == -1) {
        return 0;
    }
    if(root==NULL) {
        root = new_node;
    }
    printf("Enter left child of %d : ", new_node->data);
    new_node->left = create_BT();

    printf("Enter right child of %d : ", new_node->data);
    new_node->right = create_BT();
    
    return new_node;

}

struct node * new_node(int new_data) {
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = new_data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
void preorder_traversal(struct node *node) {
    if(node==NULL) {
        return;
    }
    printf("%d ",node->data);
    preorder_traversal(node->left);
    preorder_traversal(node->right);
}
void inorder_traversal(struct node *node) {
    if(node==NULL) return;
    
    inorder_traversal(node->left);
    printf("%d ",node->data);
    inorder_traversal(node->right);
}
void post_order(struct node *node) {
    if(node== NULL) return;

    post_order(node->left);
    post_order(node->right);
    printf("%d ", node->data);
}
int main() {
    // /*
    //         1
    //        / \
    //       2   4
    //      /   / \
    //     3   5   6
    // */

    int n=1;
    while(n) {
        printf("MENU:-\n");
        printf("1. Creation of BT\n");
        printf("2. For preorder traversal\n");
        printf("3. For inorder traversal\n");
        printf("4. For post traversal\n");
        printf("5. End program");
        printf("\n");
        printf("Enter your choice : ");
        scanf("%d", &n);
        switch(n) {
            case 1:
                    root = create_BT();
                    break;
            case 2:
                    preorder_traversal(root);
                    break;
            case 3:
                    inorder_traversal(root);
                    break;
            case 4: 
                    post_order(root);
                    break;
            case 5:
                    printf("Ending the program");
                    return 0;
            default:
                    printf("Not a valid number");
        }
    }
}
   

    /*
    Q-> Why binary tree?
    A-> General trees can cause loss of memory as the child may not
        have as many nodes as that of the parent or parent may not
        be having as many nodes as that of the child.
    */

    /*
    --> Common terms
    1. Root
    2. Parent Node
    3. Child Node
    4. Leaf Node
    5. Non-leaf Node/ Internal Nodes
    6. Path
    7. Ancestors
    8. Descendents
    9. Common ancestors
    10. Common descendents
    11. Subtree
    12. Sibling
    13. Degree(of node)
    14. Degree(of tree)
    15. Depth of node
    16. Height of node
    17. Level of node
    */