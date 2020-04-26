#include<iostream>
using namespace std;
struct bst{
    bst* left;
    bst* right;
    int data;
};
bst* root=NULL;
bst* insertion(bst* root, int val,bst* newnode){
    bst* ptr=root;
    if(root == NULL){
        root = newnode;
        return root;
    }
    else{
        if(newnode->data<ptr->data){
            ptr->left =insertion(ptr->left, val,newnode);
        }
        else{
            ptr->right =insertion(ptr->right, val,newnode);
        }
        return ptr;
    }
}
void insertion_e(int val){
    bst* newnode = new bst;
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;
    root=insertion(root, val,newnode);
}
bst* insertion_it(int val){
    bst* newnode = new bst;
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;
    bst* ptr=root;
    bst* pre=NULL;
    if(root == NULL){root=newnode;}
    else{
        while(ptr){
            pre=ptr;
            if(val<ptr->data){ptr=ptr->left;}
            else ptr=ptr->right;
            }
            if(val<pre->data){pre->left=newnode;}
            else pre->right=newnode;
    }
    return root;
}
void preorder(bst* root){
    bst* ptr=root;
    if(ptr == NULL){return;}
    else{
        cout<<ptr->data<<endl;
        preorder(ptr->left);
        preorder(ptr->right);
    }
}
void inorder(bst* root){
    bst* ptr=root;
    if(ptr == NULL){return;}
    else{
        inorder(ptr->left);
        cout<<ptr->data<<endl;
        inorder(ptr->right);
    }
}
void postorder(bst* root){
    bst* ptr=root;
    if(ptr == NULL){return;}
    else{
        postorder(ptr->left);
        postorder(ptr->right);
        cout<<ptr->data<<endl;
    }
}
bst* search_e(bst* T,int val){
    bst* ptr=T;
    if(ptr==NULL || val==ptr->data){return ptr;}
    if(val<ptr->data){
        return search_e(ptr->left, val);
    }
    else{
        return search_e(ptr->right,val);
    }
}
int mini(bst* root){
    bst* ptr=root;
    while(ptr->left!=NULL){
        ptr = ptr->left;
    }
    return ptr->data;
}
int maxi(bst* root){
    bst* ptr=root;
    while(ptr->right!=NULL){
        ptr = ptr->right;
    }
    return ptr->data;
}
int succ(bst* root,int val){
    bst* ptr=root;
    bst* p=root;
    while(p->data!=val){
        if(val<p->data){p=p->left;}
        else p=p->right;
    }
    bst* x=p;
    if(x->right!=NULL){
        return mini(x->right);
    }
    bst* succ=NULL;
    while(1){
        if(val<ptr->data){
            succ=ptr;
            ptr=ptr->left;
        }
        else if(val>ptr->data){
            ptr=ptr->right;
        }
        else break;
    }
    return succ->data;
}
int pred(bst* root,int val){
    bst* ptr=root;
    bst* p=root;
    while(p->data!=val){
        if(val<p->data){p=p->left;}
        else p=p->right;
    }
    bst* x=p;
    if(x->left!=NULL){
        return maxi(x->left);
    }
    bst* pre=NULL;
    while(1){
        if(val>ptr->data){
            pre=ptr;
            ptr=ptr->right;
        }
        else if(val<ptr->data){
            ptr=ptr->left;
        }
        else break;
    }
    return pre->data;
}
bst* deletion(bst* root, int val){
    bst* ptr=root;
    if(ptr==NULL)
        return ptr;
    if(val < ptr->data){
        ptr->left= deletion(ptr->left,val);
    }
    else if(val > ptr->data){
         ptr->right= deletion(ptr->right,val);
    }
    else{
            bst* temp;
        if (ptr->left == NULL){
            temp= ptr->right;
            delete ptr;
            return temp;
        }
        else if(ptr->right == NULL){
            temp= ptr->left;
            delete ptr;
            return temp;
        }
        temp->data = mini(ptr->right);
        ptr->data=temp->data;
        ptr->right=deletion(ptr->right, temp->data);
        return ptr;
    }
}
int main(){
    bst* a=NULL;
    insertion_e(15);
    insertion_e(6);
    insertion_e(3);
    insertion_e(7);
    insertion_e(18);
    insertion_e(17);
    insertion_e(2);
    insertion_e(4);
    insertion_e(9);
    inorder(root);
    a=insertion_it(10);
    cout<<"update a ";
    inorder(a);
    cout<<"minimum ";
    cout<<mini(root)<<endl;
    cout<<"maximum ";
    cout<<maxi(root)<<endl;
    bst* ans;
    ans=search_e(root,5);
    if(ans==NULL){cout<<"not found"<<endl;}
    else{cout<<"found"<<endl;}
    cout<<"successor ";
    cout<<succ(root,7)<<endl;
    cout<<"predecessor ";
    cout<<pred(root,7)<<endl;
    bst* del;
    del=deletion(root, 7);
    cout<<del->data<<endl;
    del=deletion(root, 3);
    cout<<del->data<<endl;
    inorder(root);

return 0;
}

