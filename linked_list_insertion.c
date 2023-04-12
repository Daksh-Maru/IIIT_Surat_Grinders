#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node* next;
};
struct node* head=NULL;

int main(){
    int x;
    struct node* t1;
    struct node* new_node;
    struct node* t2;
    int num;
    int pos;

    do{
        printf("Instructions: \n");

        printf("1 --> create a linked list \n");
        printf("2 --> print linked list \n");
        printf("3 --> Insert at beginning \n");
        printf("4 --> Insert at end \n");
        printf("5 --> Insert after a node \n");
        printf("6 --> Delete first element \n");
        printf("7 --> Delete last element \n");
        printf("8 --> Delete after a node \n");
        printf("0 --> exit \n \n");

        printf("Enter any choice from instructions: ");

        scanf("%d", &x);
        
        switch(x){

            case 1:
                printf("\nEnter 0 to end");
                printf("\nEnter the value : ");
                scanf("%d", &num);
                while(num!=0){
                    new_node=(struct node*)malloc(sizeof(struct node));
                    new_node->data=num;
                    if (head==NULL){
                        new_node->next=NULL;
                        head=new_node;
                    }
                    else{
                        t1=head;
                        new_node->next=NULL;

                        while (t1->next!=NULL){
                        t1=t1->next;}
                        t1->next=new_node;
                    }
                    printf("Enter the data : ");
                    scanf("%d", &num);
                }
                break;


            case 2:
                t1=head;
                while (t1!=NULL){
                    printf("%d\t",t1->data);
                    t1=t1->next;
                }
                printf("\n");
                break;


            case 3:
                new_node=(struct node*)malloc(sizeof(struct node));
                printf("enter new data:");
                scanf("%d", &new_node->data);
                new_node->next=head;
                head=new_node;
                break;



            case 4:
                new_node=(struct node*)malloc(sizeof(struct node));
                printf("enter new data:");
                scanf("%d", &new_node->data);
                new_node->next=NULL;
                t1=head;
                while (t1->next!=NULL){
                    t1=t1->next;
                }
                t1->next=new_node;
                break;



            case 5:
                t1=head;
                if (t1==NULL){
                    printf("INDEX OUT OF RANGE\n"); 
                    break;
                } 
                new_node=(struct node*)malloc(sizeof(struct node));
                printf("Enter data:");
                scanf("%d",&new_node->data);
                printf("Enter the value after which data is to be inserted:");
                scanf("%d",&num);
                while (t1!=NULL){
                    if (t1->data==num) {
                        x=9;
                        break;
                    }
                    t1=t1->next;
                }
                if (x==9) {
                    new_node->next=t1->next;
                    t1->next=new_node;
                }
                else{
                    printf("NO SUCH VALUE FOUND IN LINKED LIST\n");
                }
                break;

            case 6:
                t1=head;
                head=head->next;
                free(t1);
                break;


            case 7:
                t1=head;
                while(t1->next->next!=NULL) {
                    t1=t1->next;
                }
                free(t1->next);
                t1->next=NULL;
                break;


            case 8:
                t1=head;
                if (t1==NULL) {
                    printf("INDEX OUT OF RANGE\n");
                    break;
                }
                printf("Enter value after which node is to be deleted:");
                scanf("%d",&num);
                while(t1!=NULL){
                    if (t1->data==num){
                        x=9;
                        break;
                    }
                    t1=t1->next;
                }
                if (x==9){
                    if (t1->next==NULL) {
                        printf("NOTHING THERE TO DELETE\n");
                        break;
                    }
                }
                else{
                    printf("NO SUCH VALUE FOUND IN LINKED LIST\n");
                    break;
                }
                t2=t1->next;
                t1->next=t1->next->next;
                free(t2);
                break;
        }
    } while (x != 0);

    free(head);
}