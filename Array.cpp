#include<iostream>
using namespace std;
int n;
int e,pos,del;
int flag=0;

void getdata(int a[], int n){
   for(int i=0; i<n; i++){
		cin>>a[i];
	}
}

void insertion(int a[]){
    cout<<"enter element you want to insert ";
    	cin>> e;
    	cout<<"enter the position ";
    	cin>> pos;
    	if(pos<=0){
    		cout<<"INVALID POSITION";
		}
		else if(pos > n){
			cout << "not enough elements ";
		}
		else{
			for(int i= n-1; i>=pos-1; i--){
    		a[i+1]=a[i];
		}
		a[pos-1]=e;
		n = n+1;
		for(int i=0; i<n; i++){
		cout<<a[i]<<" ";
	    }
		}
}

void deletion(int a[]){
    cout<<"enter element you want to delete";
		cin>>e;

		for(int i=0; i<n; i++){
		if(a[i]==e){
		flag = 1;
		del = i;
		break;
    	}
	    }
	    if(flag == 0){
	    	cout << "Element you wish to delete does not exist";
		}
		else{
			for(int i=del ; i<n; i++){
				a[i]=a[i+1];
			}
			n-=1;
	    	for(int i=0; i<n; i++){
		cout<<a[i]<< " ";
	    }
		}
}

void traverse(int a[]){
    for(int i=0; i<n; i++){
		cout<<a[i]<<" ";
	    }
}

void searching(int a[]){
    cout << "enter element you want to search";
		cin>>e;
		for(int i=0; i<n; i++){
		if(a[i]==e){
		flag = 1;
		cout << "element is found at position " <<i+1;
		break;
    	}
     }
    	if(flag == 0){
    		cout << "ELEMENT NOT FOUND";
		}
}
int main(){
	int a[7];

	cout << "enter number of elements(between 0 to 7) ";
	cin>> n;
	while(n<0 || n>7){
		cout << "Uh oh! wrong input "<< endl;
		cout <<"enter correct input ";
		cin >> n;
	}
	cout<<"enter the elements\n";
		getdata(a,n);
    cout << "\nMENU\n";
    cout << "1. insertion."<<endl;
    cout << "2. deletion. "<<endl;
    cout << "3. traversal. "<<endl;
    cout << "4. search. "<<endl;

    cout << "choose the option: ";
    int option;

    cin >> option;
    while(option!=5){
    	switch(option){
    case 1:
    	insertion(a);
		break;

	case 2:
		deletion(a);
		break;

	case 3:
		traverse(a);
      break;

	case 4:
		searching(a);
		break;

	default:
		cout << "INVALID OPTION";

	}
	cout << endl << "\nenter another option";
	cin >> option;

	}
return 0;
}
