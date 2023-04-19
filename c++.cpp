#include"linkedlist.h"
#include <bits/stdc++.h> 
using namespace std;
int insertAfter(int first, int second, vector <int> &Vec)
{
	int count = 0;
	for (int i = 0; i< Vec.size(); i++)
	{
		if (first == Vec.at(i))// if we found the value to insert after we inster the second number after this value and increase the number of occurences of the first number 
		{
			count++;
			Vec.insert(Vec.begin() + (i+1), second);
		}
	}
	return count;
}
Linkedlist new_linkedlist(vector <int> &Vec){Linkedlist LL;
	for(int i=0; i<Vec.size(); i++)
	{
		Node *k = new Node;
		k->da = Vec[i];
		LL.Vector_to_linkedlist(k);// we fill the linked list with the elements of the vector
	}
	return LL;// we return the linked list after filling it
	}
int main(){
	int N, k, tes;
	Node *no = new Node;
	cout << "Enter the number of integers : ";
	cin >> N;
	vector <int> Vec;
	for (int i = 0; i< N; i++)
	{
		cout << "Enter the "<< (i+1) << " integer : ";
		cin >> tes;
		Vec.push_back(tes);
	}
	cout << "Enter the integer you want insert numbers after and that you want to change its occurences : ";
	cin >> k;
	cout << "Enter the integer you want to add to the vector : ";
	cin >> tes;
	tes = insertAfter(k, tes, Vec);
	cout << "The integer " << k << " occurred " << tes << " time/s." << endl;
	N = Vec.size();
	cout<<" the vector after the modification "<<"\n";
	for(int i=0; i<N; i++)
	{
		cout << Vec.at(i) << endl;
	}
	cout << endl;
Linkedlist LL=new_linkedlist(Vec);
cout<<" the linked list "<<" : "<<"\n";
	LL.printList();
	N = LL.SUMofALLnodes();
	cout << "The sum of the nodes = " << N << endl;
	cout<<"enter the number node you want to remove ";
	cin>>tes;
	LL.deleteNode(tes);
	cout<<" the linked list after deletion "<<" : "<<"\n";

	LL.printList();
	N = LL.SUMofALLnodes();
	cout << "The sum of the nodes = " << N << endl;
	return 0;


}