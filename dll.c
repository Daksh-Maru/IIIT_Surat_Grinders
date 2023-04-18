#include<stdio.h>
#include<stdlib.h>
struct node{
	int val;
	struct node* next;
	struct node* prev;
};
struct node* start=NULL;
main(){
	//declarations
	int ch;
	struct node* newnode;
	int num;
	struct node* t1;
	struct node* t2;
	int ind=0;
	//
	do{
		printf("MENU:\n");
		printf("1. create a doubly linked list\n");
		printf("2. display list\n");
		printf("3. enter element at beginning\n");
		printf("4. enter element at end\n");
		printf("5. enter element after a node at index\n");
		printf("6. delete first element\n");
		printf("7. delete last element\n");
		printf("8. delete element after a node at index\n");
		printf("9. exit\n");
		printf("\nenter choice:");
		scanf("%d", &ch);
		switch(ch){
			case 1:
				printf("Enter -1 to end filling data\n");
				printf("Enter the data:");
				scanf("%d",&num);
				while (num!=-1){
					newnode=(struct node*)malloc(sizeof(struct node));
					newnode->val=num;
					if (start==NULL){
						newnode->next=NULL;
						newnode->prev=NULL;
						start=newnode;
					}
					else{
						t1=start;
						newnode->next=NULL;
						while(t1->next!=NULL){
							t1=t1->next;
						}
						t1->next=newnode;
						newnode->prev=t1;
					}
					printf("Enter the data:");
					scanf("%d",&num);
				}
				break;
			case 2:
				t1=start;
				while (t1!=NULL){
					printf("%d\t",t1->val);
					t1=t1->next;
				}
				printf("\n");
				break;
			case 3:
				newnode=(struct node*)malloc(sizeof(struct node));
				printf("enter new item:");
				scanf("%d", &newnode->val);
				newnode->next=start;
				newnode->prev=NULL;
				start->prev=newnode;
				start=newnode;
				break;
			case 4:
				newnode=(struct node*)malloc(sizeof(struct node));
				printf("enter new item:");
				scanf("%d", &newnode->val);
				newnode->next=NULL;
				t1=start;
				while (t1->next!=NULL){
					t1=t1->next;
				}
				t1->next=newnode;
				newnode->prev=t1;
				break;
			case 5:
				ind=0;
				printf("Enter Index after which node is to be inserted:");
				scanf("%d",&num);
				t1=start;
				if (t1==NULL){
					printf("INDEX OUT OF RANGE\n"); 
					break;
				} 
				while (t1!=NULL){
					ind++;
					if (ind==num){
						break;
					}
					t1=t1->next;
				}
				newnode=(struct node*)malloc(sizeof(struct node));
				printf("Enter data:");
				scanf("%d",&newnode->val);
				newnode->prev=t1;
				newnode->next=t1->next;
				t1->next=newnode;
				newnode->next->prev=newnode;
				break;
			case 6:
				if (start==NULL){
					printf("NOTHING THERE TO DELETE\n");
					break;
				}
				t1=start;
				start=start->next;
				free(t1);
				start->prev=NULL;
				break;
			case 7:
				t1=start;
				if (t1==NULL){
					printf("NOTHING THERE TO DELETE\n");
					break;
				}
				while(t1->next->next!=NULL){
					t1=t1->next;
				}
				free(t1->next);
				t1->next=NULL;
				break;
			case 8:
				ind=0;
				printf("Enter Index after which node is to be deleted:");
				scanf("%d",&num);
				t1=start;
				if (t1==NULL){
					printf("INDEX OUT OF RANGE\n");
					break;
				}
				while(t1!=NULL){
					ind++;
					if (ind==num){
						break;
					}
					t1=t1->next;
				}
				if (t1->next==NULL){
					printf("NOTHING THERE TO DELETE\n");
					break;
				}
				t2=t1->next;
				t1->next=t1->next->next;
				free(t2);
				t2=t1->next;
				t2->prev=t1;
				break;
			case 9:
				break;
			default:
				printf("INVALID CHOICE, TRY AGAIN\n");
		}
	}while(ch!=9);
}
