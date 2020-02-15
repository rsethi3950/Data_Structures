#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node *next, *prev;
}*head = NULL;
int cnt = 0;
void create(){
    int e;
    cout << "enter element : ";
    cin >> e;
    struct node *new_node , *temp;
    while(e!= 0){
        new_node = new node;
        new_node->data = e;
        new_node->next = NULL;
        if(head == NULL){
            new_node->prev = NULL;
            head = new_node;
        }
        else{
            //cout<<"Into else:";
            temp=head;
                while(temp->next!=NULL){
                    temp=temp->next;
                }
              new_node->prev = temp;
              temp->next = new_node;
            }
        cout << "enter element, 0 to exit ";
        cin >> e;
        cnt++;
    }
}
void display(){
    struct node *temp;
    temp = head;
    while(temp!= NULL){
        cout << temp->data << endl;
        temp = temp->next;
    }
}
void insertBeg(){
    int e;
    cout << "enter the element you want to insert at beginning ";
    cin >> e;
    struct node *new_node = new node;
    new_node->data = e;
    new_node->prev = NULL;
    if(head == NULL){
         new_node->next = NULL;
         head = new_node;
    }
    else{
        struct node *ptr = head;
        new_node->next = ptr;
        head = new_node;
    }
    display();
}
void insertEnd(){
    int e;
    cout << "enter the element you want to insert at end ";
    cin >> e;
    struct node *new_node = new node;
    new_node->data = e;
    new_node->next = NULL;
    if(head == NULL){
     new_node->prev = NULL;
     head = new_node;
    }
    else{
        struct node *ptr = head;
        while(ptr->next!=  NULL){
            ptr = ptr->next;
        }
        new_node->prev = ptr;
        ptr->next = new_node;
    }
    display();
}
void ins_pos(){
     int e,pos;
    cout << "enter the element you want to insert ";
    cin >> e;
    cout << "enter the position of element ";
    cin >> pos;
    struct node *newnode, *ptr ;
	newnode = new node;
	newnode->data = e;
	newnode->next = NULL;
	newnode->prev = NULL;
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
		newnode->prev = ptr->prev;
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
void delBeg(){
    if(head == NULL){
        cout << "list is empty";
    }
    else{
        struct node *ptr = head;
        head = head->next;
        if(head!= NULL){head->prev = NULL;}
        delete(ptr);
    }
}
void delEnd(){
         if(head == NULL){
            cout << "list is empty";
        }
        else{
            struct node *ptr = head, *pre = NULL;
        while(ptr->next != NULL){
            pre = ptr;
            ptr = ptr->next;
        }
        pre->next =NULL;
        delete ptr;
        }
}
void del_val(){
    int e;
    cout << "enter node you want to delete ";
    cin >> e;
    if(head == NULL){
        cout << "list is empty\n";
    }
    else{
            struct node *pre = head;
            struct node *ptr;
            ptr = head->next;
            while(ptr!=NULL && ptr->data!=e){
                pre = pre->next;
                ptr = ptr->next;
            }
        if(ptr == NULL){
            cout << "element not present\n";
        }
        else{
          pre->next = ptr->next;
          ptr-> next = ptr->prev;
        }
    cout << "updated list is : \n";
    display();
    }
}
void Search(){
    int e,pos = 1;
    cout << "enter the element you want to search ";
    cin >> e;
    if(head == NULL){
        cout << "list is empty\n";
    }
    else{
        struct node *ptr = head;
        while(ptr!=NULL && ptr->data!=e){
            ptr = ptr->next;
            pos++;
            }
        if(ptr == NULL){
            cout << "element not present\n";
        }
        else{
            cout << "element is found at "<< pos;
        }
    }
}
int main(){
    create();
    display();
    insertBeg();
    insertEnd();
    ins_pos();
    delBeg();
    del_val();
    Search();

return 0;
}
