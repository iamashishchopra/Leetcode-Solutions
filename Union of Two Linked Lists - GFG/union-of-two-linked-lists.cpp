//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};


// } Driver Code Ends
/*
// structure of the node is as follows

struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

*/
class Solution
{
    public:
    struct Node* makeUnion(struct Node* head1, struct Node* head2) {
        set<int> s;
        // Insert all elements of first linked list
        Node* curr1 = head1;
        while (curr1) {
            s.insert(curr1->data);
            curr1 = curr1->next;
        }
        // Insert elements of second linked list that are not already in set
        Node* curr2 = head2;
        while (curr2) {
            if (s.find(curr2->data) == s.end()) {
                s.insert(curr2->data);
            }
            curr2 = curr2->next;
        }
        // Create the resulting linked list
        Node* resHead = NULL;
        Node* resTail = NULL;
        for (int x : s) {
            Node* newNode = new Node(x);
            if (!resHead) {
                resHead = newNode;
                resTail = newNode;
            } else {
                resTail->next = newNode;
                resTail = newNode;
            }
        }
        return resHead;
    }
};


//{ Driver Code Starts.

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution obj;
        Node* head = obj.makeUnion(first,second);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends