#include<iostream>
using namespace std;
int front=-1;
int rear=-1;
struct adjlist{
    int val;
    adjlist* next;
};
struct graph{
    adjlist** list;
};
void initialise(graph* g,int v){
    g->list=new adjlist*[v];
    for(int i=0;i<v;i++){
        g->list[i]=NULL;
    }
}
void addEdge(graph* g,int start, int end){
    adjlist* newnode1=new adjlist;
    newnode1->val=end;
    newnode1->next=NULL;
    adjlist* newnode2=new adjlist;
    newnode2->val=start;
    newnode2->next=NULL;
    if(g->list[start]==NULL){
        g->list[start]=newnode1;
    }
    else{
        newnode1->next=g->list[start];
        g->list[start]=newnode1;
    }
    if(g->list[end]==NULL){
        g->list[end]=newnode2;
    }
    else{
        //insertion at tail
        //adjlist* head=g->list[end];
        /*while(ptr){
            pre=ptr;
            ptr=ptr->next;
        }
        pre->next=newnode2;*/

        //insertion at head to reduce time complexity
        newnode2->next=g->list[end];
        g->list[end]=newnode2;
    }
}
void enqueue(int q[],int s,int v){
    if (rear == v - 1)
      cout<<"Queue Overflow"<<endl;
   else {
      if (front == -1){
        front = 0;
        rear=0;
      }
      else{rear++; }
      q[rear] = s;
   }
}
int dequeue(int q[], int v){
int f=front;
front++;
return q[f];
}
void bfs(graph* g,int s,int v){
    int q[v];
    char visited[v];
    for(int i=0; i<v; i++){
        visited[i]='w';
    }
    int d[v];
    //int dist=0;
    visited[s]='g';
    d[s]=0;
enqueue(q,s,v);
while(front<=rear){
        int u=dequeue(q,v);
        cout<<u<<" ";
        adjlist* ptr=g->list[u];
    while(ptr){
            if(visited[ptr->val]=='w'){
                 visited[ptr->val]='g';
                d[ptr->val]= d[u]+1;
                enqueue(q,ptr->val,v);
            }
        ptr=ptr->next;
    }
    visited[u]='b';
}
cout<<endl<<"distance vector ";
for(int i=0; i<v; i++){
    cout<<d[i]<<" ";
}
cout<<endl;
}
int time=0;
int d[5];
int f[5];
int pre[5]={0};
char visited[5];
void dfs_visit(graph* g,int u ){
    time=time+1;
    d[u]=time;
    visited[u]='g';
    cout<<u<<"->"<<d[u]<<endl;
    adjlist* ptr=g->list[u];
    while(ptr){
        if(visited[ptr->val]=='w'){
             pre[ptr->val]=u;
            dfs_visit(g,ptr->val);
        }
        ptr=ptr->next;
    }
    visited[u]='b';
    time=time+1;
    f[u]=time;
}
void dfs(graph* g,int v){
    //char visited[v];
    // int d[v];
    //int f[v];
    //int time=0;
    for(int i=0; i<v; i++){
        visited[i]='w';
    }
    for(int i=0; i<v; i++){
        if(visited[i]=='w'){
            dfs_visit(g,i);
        }
    }
}
int main(){
    //allocate memory to graph pointer
    graph* g= new graph;
    int v=5;
    initialise(g,v);
    addEdge(g,0,1);
    addEdge(g,0,2);
    addEdge(g,1,2);
    addEdge(g,2,3);
    addEdge(g,3,4);
    addEdge(g,4,0);
    for(int i=0;i<v; i++){
        adjlist* temp=g->list[i];
        cout<<i<<"->";
        while(temp){
            cout<< temp->val<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
    cout<<"bfs : ";
    bfs(g,0,v);
    cout<<"dfs : "<<endl;
    dfs(g,v);
return 0;
}
