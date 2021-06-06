#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>

struct heap{
		unsigned int priority; //the priority of the element
		unsigned int info; //data to be insterted
		struct heap * next; //pointer to heap
};

	struct heap*start=NULL ,*q,*temp,*New;//creating an empty heap called start and defining others , q , temp ,New
	typedef struct heap N;
	
	void insert(){
		int item,itprio;  //defining two variables , item= data to be inserted , itprio = its priority
		struct heap * New =(N*)malloc(sizeof(N)); //creating a new heap
		printf("enter the element to be inserted :\t");
		scanf("%d",&item);
		printf("Enter its priority:\t");
		scanf("%d",&itprio);
		New->info=item;//inserting the data to the heap
		New->priority=itprio;//defining its priority
		if(start==NULL){
			start = New;
		} else if(start!=NULL && itprio <= start->priority){ //if the start is not empty and the the item's priority is lesser than the heap's
			New->next = start; //the next cell wil be equal to start
			start =New ; //now we can assign New's Values to start
		}
	else{
		q=start;
		while(q->next !=NULL && q->next->priority <= itprio){
			q=q->next;
			New->next=q->next;
			q->next=New;
		}
	}
}
	 void del(){
		if(start==NULL){
			printf("\nQueue Underflow\n");
		}
		else{
			New = start ;
			printf("\n Deleted item is %d\n",New->info);
			start = start->next ;
		}
	 }
	void display()	{
		temp=start;
		if(start==NULL)
			{
				printf("QUEUE IS EMPTY\n");
			}
		else
		{
		printf("QUEUE IS:\n");
		
		while(temp!=NULL)
		{
		printf("\n%d priority =%d\n",temp->info,temp->priority);
		temp=temp->next;
			}
		}
	}
	
	
int main(){
	int ch;
	bool check=false;
	do
	{
		printf("\n[1] INSERTION\t[2] DELETION\t[3] DISPLAY [4] EXIT\t:");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:insert();
		   	break;
		case 2:del();
			break;
		case 3:display();
			break;
		case 4:
			check=true;
			break;
		}
	}
		while(check==false);
}

