#include <iostream>
#include<stdlib.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct node{
	int data;
	node* next;
};
node *start;
node* create(node*);
void read(node*);
node* update(node*);
node* destroy(node*);
node* reverse(node*);
int main(int argc, char** argv) {
	for(;;){	
		int option;
		cout<<"1.Create List\n2.Read List.\n3.Update list.\n4.Destroy\n5.Reverse.\n6.Exit";
		cout<<"\nSelect any of the above options:";cin>>option;
		switch(option){
			case 1:{
				start=create(start);
				break;
			}
			case 2:{
				read(start);
				break;
			}
			case 3:{
				start=update(start);
				break;
			}
			case 4:{
				start=destroy(start);
				break;
			}
			case 5:{
				start=reverse(start);
				break;
			}
			case 6:{
				
				exit(0);
			}
		}
		
		
	}
	return 0;
}
node* create(node *start){
	int data;
	cout<<"Enter data:";cin>>data;
	while(data!=-1){
	
		if(start==NULL){
			start=new node;
			start->data=data;
			start->next=NULL;
		}
		else{
			node *temp=start;
			for(int i=0;temp!=NULL;i++){
				if(temp->next==NULL){
					temp->next=new node;
					temp->next->data=data;
					temp->next->next=NULL;
					break;
				}
				temp=temp->next;
			}
		}
		cout<<"\nEnter data:";cin>>data;
	}
	return start;
}
void read(node* start){
	for(int i=0;start!=NULL;i++){
		cout<<start->data<<endl;
		start=start->next;
	}
}
node* update(node* start){
	int option;
	cout<<"1.Add node befor a number.\n2.Add node after a number.\n3.Add at last.\n4.Add at starting.\n5.Exit";
	cout<<"\nSelect any of the above option:";cin>>option;
	switch(option){
		case 1:{
				int no;
				cout<<"Enter the number before which you have to add new data:";cin>>no;
				node *temp=start;
				for(;temp!=NULL;){
					if(temp->next->data==no)
					{
						node *new_node=new node;
						cout<<"Enter data:";cin>>new_node->data;
						new_node->next=temp->next;
						temp->next=new_node;
						break;
					}
					temp=temp->next;
				}
				break;
		}
		case 2:{
				int no;
				cout<<"Enter the number after which you have to add new data:";cin>>no;
				node *temp=start;
				for(;temp!=NULL;){
					if(temp->data==no)
					{
						node *new_node=new node;
						cout<<"Enter data:";cin>>new_node->data;
						new_node->next=temp->next;
						temp->next=new_node;
						break;
					}
					temp=temp->next;
				}
			break;
		}
		case 3:{
				node *temp=start;
				for(;temp!=NULL;){
					if(temp->next=NULL)
					{
						node *new_node=new node;
						cout<<"Enter data:";cin>>new_node->data;
						new_node->next=temp->next;
						temp->next=new_node;
						break;
					}
					temp=temp->next;
				}
			break;
		}
		case 4:{
			node *new_node=new node;
			cout<<"Enter data:";cin>>new_node->data;
			new_node->next=start->next;
			start=new_node;
			break;
		}
		case 5:{
			
			return start;
		}
	}
	return start;
}
node* destroy(node* start){
	int option;
	cout<<"1.Destroy node befor a number.\n2.Destroy node after a number.\n3.Destroy last node.\n4.Destroy starting node.\n5.Destroy complete list\n6.Exit";
	cout<<"\nSelect any of the above option:";cin>>option;
	switch(option){
		case 1:{
				int no;
				cout<<"Enter the number before which you have to destroy node:";cin>>no;
				node *temp=start;
				if(start->data==no){
					cout<<"No element to destroy\n";
				}
				else if(start->next->data==no){
					start=start->next;
					free(temp);
				}
				else{
				
					for(;temp!=NULL;){
						if(temp->next->next->data==no)
						{
							node *new_node;
							new_node=temp->next;
							temp->next=new_node->next;
							free(new_node);
							break;
						}
						temp=temp->next;
					}
				}
				break;
		}
		case 2:{
				int no;
				cout<<"Enter the number after which you have to destroy node:";cin>>no;
				node *temp=start;
			if(temp->next==NULL){
				cout<<"No node to be destroyed.\n";
			}
			else{
			
				for(;temp!=NULL;){
					if(temp->data==no)
					{
						node *new_node;
						new_node=temp->next;
						temp->next=new_node->next;
						free(new_node);
						break;
					}
					temp=temp->next;
				}
			}
			break;
		}
		case 3:{
				node *temp=start;
				for(;temp!=NULL;){
					if(temp->next->next==NULL)
					{
						node *new_node;
						new_node=temp->next;
						temp->next=new_node->next;
						free(new_node);
						break;
					}
					temp=temp->next;
				}
			break;
		}
		case 4:{
			node *new_node=start;
			start=new_node->next;
			free(new_node);
			break;
		}
		case 5:{
			start=NULL;
			break;
		}
		case 6:{
			return start;
		}
	}
	return start;
}
node* reverse(node * start){
	node *p,*q,*r;
	p=q=r=start;
	p=p->next->next;
	q=q->next;
	r->next=NULL;
	q->next=r;
	while(p!=NULL){
		r=q;
		q=p;
		p=p->next;
		q->next=r;
	}
	start=q;
	return start;
}
