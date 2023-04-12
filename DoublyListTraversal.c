#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node * next;
    struct Node * prev;
};
struct Node * head;

void CreateList()
{
    struct Node *new_node;
    struct Node * temp = head;
    int choice=1;
    while(choice) 
    {
        new_node = (struct Node*)malloc(sizeof(struct Node));
        printf("enter the value in node : \n");
        scanf("%d",&new_node->data);
        new_node->next=NULL;
        new_node->prev=NULL;

        if(head==NULL)
        {
            head = temp = new_node;
        }
        else{
            temp->next=new_node;
            new_node->prev=temp;
            temp=temp->next;
        }
        printf("Do you want to enter another value (1/0) : \n");
        scanf("%d", &choice);
    }
}

void PrintList()
{
    struct Node *temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}


int main()
{
    CreateList();
    PrintList();

}

