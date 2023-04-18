#include<stdio.h>
#include<stdlib.h>
struct node{
	int val;
	struct node* next;
	struct node* prev;
};
//declarations
	struct node* start=NULL;
	struct node* t1;
	struct node* newnode;
	struct node* t2;
	struct node* last=NULL;
	int ch;
	int num;
	int ind;
//
main(){
	do{
		c=1;
		printf("MENU:\n");
		printf("1. create a linked list\n");
		printf("2. display list\n");
		printf("3. enter element at beginning\n");
		printf("4. enter element at end\n");
		printf("5. enter element after a node at index\n");
		printf("6. delete first element\n");
		printf("7. delete last element\n");
		printf("8. delete element after a node after index\n");
		printf("9. exit\n");
		printf("enter choice:");
		scanf("%d", &ch);
		switch(ch){
			case 1:
				create();
				break;
			case 2:
				display();
				break;
			case 3:
				addatbegin();
				break;
			case 4:
				addatend();
				break;
			case 5:
				addafternode();
				break;
			case 6:
				delfirst();
				break;
			case 7:
				dellast();
				break;
			case 8:
				delafternode();
				break;
			case 9:
				printf("EXITING");
				break;
			default:
				printf("INVALID CHOICE, TRY AGAIN\n");
				break;
		}
	}while(ch!=9);
}
void create(){
	printf("Enter 0 to end");
	printf("\nEnter the data : ");
	scanf("%d", &num);
	while(num!=0){
		newnode=(struct node*)malloc(sizeof(struct node));
		newnode->val=num;
		if (start==NULL){
			start=newnode;
			newnode->prev=start;
			newnode->next=start;
		}
		else{
			t1=start;
			while (t1->next!=start){
				t1=t1->next;
			}
			t1->next=newnode;
			newnode->next=start;
			newnode->prev=t1;
		}
		printf("Enter the data : ");
		scanf("%d", &num);
	}
}
void tolast(){
	t1=start;
	while (t1->next!=start){
		t1=t1->next;
	}
	last=t1;
}
void display(){
	t1=start;
	while (t1->next!=start){
		printf("%d\t",t1->val);
		t1=t1->next;
	}
	printf("%d\t",t1->val);
	printf("\n");
}
void addatbegin(){
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("enter new item:");
	scanf("%d", &newnode->val);
	tolast();
	t1->next=newnode;
	newnode->next=start;
	newnode->prev=last;
	start=newnode;
}
void addatend(){
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("enter new item:");
	scanf("%d", &newnode->val);
	tolast();
	t1->next=newnode;
	newnode->next=start;
	newnode->prev=t1;
}
void addafternode(){
	ind=0;
	printf("Enter Index after which node is to be inserted:");
	scanf("%d",&num);
	t1=start;
	if (t1==NULL){
		printf("INDEX OUT OF RANGE\n");
		return;
	}
	while (t1->next!=start){
		ind++;
		if (ind==num){
			break;
		}
		t1=t1->next;
	}
	if (t1->next==start && ind==num){
		addatend();
	}
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter new item:");
	scanf("%d",&newnode->val);
	t1->next->prev=newnode;
	newnode->next=t1->next;
	newnode->prev=t1;
	t1->next=newnode;
}
void delfirst(){
	t2=start->next;
	t1=start;
	tolast();
	free(start);
	start=t2;
	start->prev=last;
	last->next=t2;
}
void dellast(){
	t1=start;
	while(t1->next->next!=start){
		t1=t1->next;
	}
	start->prev=t1;
	free(t1->next);
	t1->next=start;
}
void delafternode(){
	ind=0;
	printf("Enter Index after which node is to be deleted:");
	scanf("%d",&num);
	t1=start;
	if (t1==NULL){
		printf("INDEX OUT OF RANGE\n");
		return;
	}
	while (t1->next!=start){
		ind++;
		if (ind==num){
			c=0;
			break;
		}
		t1=t1->next;
	}
	if (t1->next==start && ind==num){
		printf("NOTHING THERE TO DELETE\n");
		return;
	}
	t2=t1->next;
	t1->next=t2->next;
	t1->next->prev=t1;
	free(t2);
}
