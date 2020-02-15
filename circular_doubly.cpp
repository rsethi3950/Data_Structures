#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node *next, *prev;
};
struct node *head = NULL;
void create(){
	struct node *temp1;
	int n;
	cout<<"enter value, press 0 to exit";
	cin>>n;
	while(n!=0){
		node *newnode = new node;
		newnode->data = n;
		newnode->prev=NULL;
		newnode->next=NULL;
		if(head==NULL){
	    	head = temp1=newnode;
			temp1->next = temp1->prev = newnode;


		}
		else{

			temp1->next=newnode;
			newnode->prev=temp1;
			newnode->next=head;
            temp1=newnode;
			head->prev=newnode;

		}
		cout<<"enter value, press 0 to exit";
	 	cin>>n;
	}
}
void display(){
	node *temp=head;
	if(head==NULL)
	{
		cout<<"empty list";
	}
	else{
		while(temp->next!=head){
		cout<< temp->data<<endl;
		temp=temp->next;
	}
	cout<<temp->data<<endl;
	}
}
void insertBeg(){
	int e;
	cout<<"enter element you want to insert at beginning";
	cin>>e;
	node *temp = new node;
	temp->data =e;
	if(head==NULL){
		head->prev=head->next=temp;
		head = temp;
	}
	else{
		temp->next=head;
		temp->prev=head->prev;
		head->prev->next=temp;
		head->prev=temp;
		head = temp;

	}
	display();
}
void insertEnd(){
    int e;
	cout<<"enter element you want to insert at end";
	cin>>e;
	node *temp = new node;
	temp->data =e;
	if(head==NULL){
		head->prev=head->next=temp;
		head = temp;
	}
	else{
		temp->next=head;
		temp->prev=head->prev;
		head->prev->next=temp;
		head->prev=temp;

	}
	display();
}
void ins_pos(){
	int a,x;
	cout<<"enter the value after which you want to insert ";
	cin>>x;
	cout<<"enter value you want to insert ";
	cin>>a;
	node *temp = new node;
	node *ptr=head;
	temp->data=a;
	if(head==NULL){
		cout << "not found";
	}
	else{
		while(ptr->next!=head && ptr->data!=x){
			ptr=ptr->next;
		}

		if(ptr->data == x){
			temp->prev=ptr;
			temp->next=ptr->next;
			ptr->next->prev=temp;
			ptr->next=temp;
		}
		else{
			cout << "not found";
		}
	}
	display();
}
void delBeg(){
    if(head==NULL){
        cout<<"empty list";
    }
    else{
        node *temp = head;
        if(temp->next == temp){head=NULL;}
        else{
            head->prev->next=head->next;
            head->next->prev=head->prev;
            head = head->next;
        }
        delete temp;
    }
   display();
}
void delEnd(){
    if(head==NULL){
        cout<<"empty list";
    }
    else{
        node *temp = head;
        node *p = NULL;
        if(temp->next == temp){head=NULL;}
        else{
            temp=temp->prev;
            temp->prev->next=head;
            head->prev=temp->prev;

        }
        delete temp;
    }
    display();
}
void delete_e(){
    int e;
    cout<<"enter the element you want to delete";
    cin>>e;
    node *temp = head;
    if(head==NULL){
        cout<<"empty list";
    }
    else if(temp->next == temp){head=NULL; }
    else{
        while(temp->next!=head && temp->data!=e){
            temp=temp->next;
        }
        if(temp->data==e){
            temp->prev->next=temp->next;
            temp->next->prev = temp->prev;
        }
        else{
            cout<<"not found";
        }
    }
    delete temp;
    display();
}
void searchE(){
    int e,pos=1;
    cout<<"enter the element you want to search";
    cin>>e;
    if(head==NULL){
        cout<<"empty list";
    }
    else{
        node *temp = head;
        while(temp->next!=head && temp->data!=e){
            temp=temp->next;
            pos++;
        }
        if(temp->data==e){
            cout<<"element found at position "<<pos;
        }
        else{
            cout<<"not found";
        }
    }
}
int main(){
create();
display();
insertBeg();
insertEnd();
ins_pos();
cout<<"delete beginning";
delBeg();
cout<<"delete end";
delEnd();
delete_e();
searchE();
return 0;
}
