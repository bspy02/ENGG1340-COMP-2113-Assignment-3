#include<stdio.h>
#include<stdlib.h>

typedef struct Node

{
	int info;
	struct Node *next;
}node;

node *head=NULL,*tail=NULL,*temp;


void create(int num)
{
	node *create;
	create=(node*)malloc(sizeof(node));
	create->info=num;
	create->next=NULL;
	if(tail==NULL)
	head=tail=create;
	else
	{
		tail->next=create;
		tail=create;
	}

	tail->next=head;
}

int del(int n)
{
	while(head->next!=NULL){
		for(int i=0;i<n-2;i++){
			head=head->next;
		}
		temp=head->next;

		if(head->info!=temp->next->info){
			head->next=temp->next;
			head=head->next;
		}else{
			head->next=NULL;
		}
		temp=NULL;
		free(temp);
	}
	return head->info;
}

int main()
{

	int num;
	int pos;



	scanf("%d",&num);
	for(int i=1;i<num+1;i++){
		create(i);
	}
	scanf("%d",&pos);

	printf("%d\n",del(pos));
	free(head);
	free(tail);
	free(temp);

	return 0;
}
