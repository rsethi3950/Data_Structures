#include<bits/stdc++.h>
using namespace std;
//for heterogeneous datatype use structures
struct node{
	int data;
	struct node *next;
};//*head= NULL
struct node *head = NULL; //global
int cnt = 0, flag = 0;
void create(){
	int ele ;
	struct node *newnode, *temp;
	while(ele!=0){

    newnode = new node; //allocate memory
	cout<<"enter the element you want to insert , press zero to exit\n";
	cin >> ele;
	if(ele!=0){
        newnode->data = ele;
	newnode ->next = NULL;
	if(head == NULL){
		temp = newnode;
		head = temp;
	}
	else{
		temp->next = newnode;
		temp = newnode;
	}
	}
	cnt++;
	}
}
void display(){
	struct node *ptr;
	ptr = head;
	while(ptr!= NULL){

		cout << ptr->data << endl;
		ptr = ptr->next;
	}
}
void insert(){
	int pos, ele;
	cout << "enter the position you want to insert " ;
	cin >> pos;
	cout << "enter the element you want to insert ";
	cin>> ele;
	struct node *newnode, *ptr;
	newnode = new node;
	newnode->data = ele;
	newnode->next = NULL;
	cnt++;
	if(pos < cnt +1){
		if(head == NULL){
		head = newnode;
        }
	    else{
		ptr = head;
		if(pos>1){
            while(pos-- - 2){ // at pos 2 less than from 1
			ptr = ptr ->next;
		}
		newnode->next = ptr->next;
		ptr->next = newnode;
		}
		else if(pos == 1){
                ptr = head;
            newnode->next = ptr;
            head = newnode;
		}
        }
	}
	display();

}
void search(){
    int ele, pos=0;
    cout << "enter the element you want to search ";
    cin >> ele;

    if(head == NULL){
        cout << "list is empty\n";
    }
    else{
             struct node *ptr;
        ptr = head;
            while(ptr!=NULL && ptr->data!=ele){
                ptr = ptr->next;
                pos++;
            }
        if(ptr == NULL){
            cout << "element not present\n";
        }
        else{
            cout<< "element is present at " << pos+1 ;
        }
    }
}
void remove(){
    int ele;
    cout << "enter the node you want to delete ";
    cin >> ele;
     if(head == NULL){
        cout << "list is empty\n";
    }
    else{
            struct node *prev = head;
            struct node *ptr;
            ptr = head->next;
            while(ptr!=NULL && ptr->data!=ele){
                prev = prev->next;
                ptr = ptr->next;
            }
        if(ptr == NULL){
            cout << "element not present\n";
        }
        else{
          prev->next = ptr->next;
        }
    cout << "updated list is : \n";
    display();
    }
}
void delete_beg(){

	if (head == NULL){
		cout<<"list is empty";
	}
	else{
		struct node *ptr = head;
		head = head->next;
		int x = ptr->data;
		delete(ptr);
		cout<<"node with value "<< x << "deleted.\n";
	}
	cout << "updated list is\n";
	display();
}
void delete_end(){
	if(head == NULL){
		cout << "list is empty";
	}
	else{
		struct node *ptr = head, *prev = NULL;
		while(ptr->next!= NULL){
			prev = ptr;
			ptr = ptr->next;
		}
		prev->next = NULL;
		int x = ptr->data;
		delete ptr;
		cout << "node with value "<< x << " deleted\n";
	}
	cout << "updated list is\n";
	display();

}
void delete_e(int pos){
	struct node *ptr= head, *prev = NULL;
	while(pos-- - 1){
		prev = ptr;
		ptr= ptr->next;
	}
	prev->next = ptr->next;
	cout << "updated list is\n";
	display();
}
int main(){
    cout << "MENU\n";
    cout << "1. create list.\n";
    cout << "2. display list.\n";
    cout << "3. insert a new node and display new list\n";
    cout << "4. search a node value.\n";
    cout << "5. Delete a node.(by value)\n";
    cout << " delete a node(by value).\n";
    cout << "6. delete head.\n";
    cout<< "7. delete end.\n";
    cout << "8. delete at specific position.\n";
    cout << "9. exit\n";
    int option;
    cout << "choose desired option ";
    cin >> option;
    while(option!=9){
         switch(option){
    case 1:
        create();
        break;
    case 2:
        display();
        break;
    case 3:
        insert();
        break;
    case 4:
        search();
        break;
    case 5:
        remove();
        break;
    case 6:
        delete_beg();
        break;
    case 7:
        delete_end();
        break;
    case 8:
        int pos;
        cout << "enter the position at which you want to delete a node. ";
        cin >> pos;
        delete_e(pos);
        break;
    default:
        cout << "invalid output\n";
        cout << "please enter valid input ";
    }
    cout << "choose desired option ";
    cin >> option;
    }
	return 0;
}

