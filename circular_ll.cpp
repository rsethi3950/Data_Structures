#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node *next;
};
struct node *head = NULL;
int cnt = 0;
void create(){
    int ele ;
	struct node *newnode, *temp;
	while(ele!=0){
    newnode = new node; //allocate memory
	cout<<"enter the element you want to insert , press zero to exit ";
	cin >> ele;
	if(ele!=0){
        newnode->data = ele;
        newnode ->next = newnode;
	if(head == NULL){
		temp = newnode;
		head = temp;
	}
	else{
        newnode->next = head;
		temp->next = newnode;
		temp = newnode;
	}
	}
	cnt++;
	}
}
void display(){
    struct node *temp = head;
    while(temp->next != head){
        cout << temp->data << endl;
        temp = temp->next;
    }
    cout << temp->data << endl;
}
void insertBeg(){
    int e;
    cout << "enter the element you want to insert at beginning ";
    cin >> e;
    node *new_node = new node;
    new_node->data = e;
    new_node->next = new_node;
    if(head == NULL){
         head = new_node;
    }
    else{
        struct node *ptr = head;
        while(ptr->next != head){
            ptr = ptr->next;
        }
        ptr->next = new_node;
        new_node->next = head;
        head = new_node;
    }
    display();
}
void insertEnd(){
    int e;
    cout << "enter the element you want to insert at end ";
    cin >> e;
    node *new_node = new node;
    new_node->data = e;
    new_node->next = new_node;
    if(head == NULL){
         head = new_node;
    }
    else{
        struct node *ptr = head;
        while(ptr->next != head){
            ptr = ptr->next;
        }
        ptr->next = new_node;
        new_node->next = head;
    }
    display();
}

void ins_pos(){
    int a,x;
    cout << "enter the new value(a) you want to insert after x";
    cin >> a;
    cin >> x;
    if(head == NULL){cout<<"empty list";}
    else{
        node *temp = head;
        while(temp->next!=head && temp->data!=x){
            temp = temp->next;
        }
        if(temp->data == x){
            node *newnode = new node;
            newnode->data = a;
            newnode->next = temp->next;
            temp->next = newnode;
        }
        else{cout << "not found";}
    }
}
void delBeg(){
    if(head == NULL){
        cout << "list is empty";
    }
    else{
         node *temp = head, *ptr=head;
         if(temp->next == head){head=NULL; delete temp; return;}
         while(temp->next!=head){temp= temp->next; }
         head = head->next;
         temp->next = head;
         delete ptr; //to avoid memory leaks and floating data in program
    }
    display();
}
void delEnd(){
     if(head == NULL){
        cout << "list is empty";
     }
     else{
        node *temp = head, *pre=NULL;
        if(temp->next == head){head=NULL; delete temp; return;}
        while(temp->next!=head){
            pre = temp;
            temp = temp->next;
        }
        pre->next = head;
        delete temp;
     }
    display();
}
void del_val(){
     int e;
    cout << "enter value you want to delete ";
    cin>>e;
    if(head == NULL){
            cout << "list is empty";
        }
    else{
        node *temp = head,*pre=NULL;
        if(temp->data == e){head = NULL; delete temp; return;}
        while(temp->next!=head && temp->data!=e){
                pre = temp;
                temp=temp->next;
        }
        if(temp->data == e){
            pre->next = temp->next;
            delete temp;
        }
        else{cout<<"not found"; }
        }
    display();
}
void searchE(){
    int e,pos=1;
    cout << "enter value you want to search ";
    cin>>e;
    if(head == NULL){cout << "list is empty"; }
    else{
        node *temp = head;
        while(temp->next!=head && temp->data!=e){temp=temp->next; pos++; }
        if(temp->data == e){cout<<"element found is at "<< pos;}
        else{cout<<"not found"; }
    }
}
int main(){
    cout << "MENU\n";
    cout << "1. create list.\n";
    cout << "2. display list.\n";
    cout << "3. insert a new node at beginning and display new list\n";
    cout << "4. insert a new node at end and display new list\n";
    cout << "5. insert a new node after a node and display new list\n";
    cout << "6. delete head.\n";
    cout << "7. delete end.\n";
    cout << "8. delete a specific node value.\n";
    cout << "9. search a node value.\n";
    cout << "10. exit\n";
    int option;
    cout << "choose desired option ";
    cin >> option;
    while(option!=10){
         switch(option){
    case 1:
        create();
        break;
    case 2:
        display();
        break;
    case 3:
        insertBeg();
        break;
    case 4:
        insertEnd();
        break;
    case 5:
        ins_pos();
        break;
    case 6:
        delBeg();
        break;
    case 7:
        delEnd();
        break;
    case 8:
        delete_e();
        break;
    case 9:
        searchE();
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
