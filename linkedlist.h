#include <iostream>
using namespace std;
  

class Node {
public:
    int da;int occer;
    Node* sec;
  
    Node()// the default constructor
    {
        da = 0;occer=1;
        sec = NULL;
    }
  
    Node(int da)// the parametrized constructor
    {
        this->da = da;
        this->sec = NULL;occer=1;
    }
};
  

class Linkedlist {
    Node* start;
  
public:
    Linkedlist() { start = NULL; }
  
   
  
    void printList();
    int SUMofALLnodes();
   void Vector_to_linkedlist(Node*);
     void Add(Node *N);
    void deleteNode(int);
   
};


    void Linkedlist::deleteNode(int n) {
// If the linked list is empty, return
if (start == nullptr) {
return;
}
// If the start node is to be removed
if (start->da == n) {
    Node* neww = start;
    start = start->sec;
    delete neww;
    return;
}

// Traverse the linked list to find the node to be removed
Node* now = start;
while (now->sec != nullptr) {
    if (now->sec->da == n) {
        Node* neww = now->sec;
        now->sec = neww->sec;
        delete neww;
        return;
    }
    now = now->sec;
}
}


  

void Linkedlist::printList()
{
    Node* dummy = start;
  
    if (start == NULL) {// check if there exists any elements in the linked list
        cout << "List empty" << endl;
        return;
    }
  
    while (dummy != NULL) {
        cout << dummy->da << " "<<"it occured "<<dummy->occer<<" times"<<"\n";// print the number in the node with the number of occurences
        dummy = dummy->sec;// then move to the second node
    }
    cout<<"\n";
}
  int Linkedlist::SUMofALLnodes()
{
    int x=0;
    Node* dummy = start;
  
    if (start == NULL) {// we check if the lost is empty
        cout << "List empty" << endl;
    }
  
    while (dummy != NULL) {
        x+= dummy->da;//we add the values of each node to the sum variable
	    // here it was not clear whether we should take the number of occurences into account so I did not however
	    //if we wanted to take into account we will change the previous line to be x+= dummy->da*dummy->occer;
        dummy = dummy->sec;//we then move to the next move
    }
    return x;
}
void Linkedlist::Add(Node *N)
{int aaa=0;
	if (start == NULL)
	{
		start = N;
	}
	else
	{
        	Node* dummy = start;
		while(dummy->sec != NULL)
		{
			if((N->da) == (dummy->da))
			{
				cout << "This value already exists!!" << endl;
				dummy->occer++; aaa++;
				return;
			}
            if(aaa!=0){return;}
			else{dummy = dummy->sec;}
		}
                    if(aaa!=0){return;}
		else{dummy->sec = N;}
	}
}

void Linkedlist::Vector_to_linkedlist(Node *N)
{
	Node* dummy = start;
	while(dummy != NULL)
	{
		if(N->da == dummy->da)
		{	
			dummy->occer++;//we check if this value has occured before
			return;
		}
		dummy = dummy->sec;//we then move to the next node
	}
	Add(N);
}
