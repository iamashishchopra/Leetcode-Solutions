//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        node *res = head;
        for(int i=0;i<k-1;i++) res = res->next;
        
        node *start = head;
        node *prev = NULL;
        node *next, *present_head, *ptr;
        node *past_tail = NULL;
        
        int adder, stander=0;
        
        while(start != NULL){
            
            adder = stander;
            present_head = start;
            
            for(int i=0;i<k;i++){
                if(start != NULL){
                    next = start->next;
                    start->next = prev;
                    
                    prev = start;
                    start = next;
                    stander = 1;
                }
            }
            
            if(adder != 0) past_tail->next = prev;
            past_tail = present_head;
            prev = NULL;
        }
    
        return res;// Complete this method
    }
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}


// } Driver Code Ends