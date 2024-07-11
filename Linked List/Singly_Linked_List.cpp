#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// initialising a node class to create a node 
class Node{
    public:
    Node(int data){
        this->data = data;
        this->next  = NULL;
    }
    int data;
    Node *next;
    // a pointer of node datatype pointing upon next node 
    
    // create a destructor to delete the node 
    ~Node(){
        int value = this -> data;
        if(this -> next == NULL){
            delete next;
            this -> next = NULL;
        }
        cout<<"Node is being deleted with data : "<<value<<endl;
    }
};

void insertAtHead(Node* & head , int data){
    Node * tmp = new Node(data);
    tmp -> next =  head;
    head = tmp;
}
// Another way to add data at tail using only head
// void insertAtTail(Node* & head , int data){
//     Node* newNode = new Node(data);
//     Node* tmp = head;
//     while(tmp-> next != NULL){
//         tmp = tmp -> next;
//     }
//     tmp -> next = newNode;
// }
void insertAtTail(Node* &tail , int data){
    Node* tmp = new Node(data);
    tail -> next = tmp;
    tail = tmp;
}
void Print(Node* &head){
    Node* tmp = head;
    while(tmp != NULL){
        cout<<tmp->data<<' ';
        tmp = tmp -> next ;
    }
    cout<<endl;
}
void insertAt(Node* &head , Node* &tail ,int position , int data){
    Node* tmp = head;
    // if we have to add the element at first position
    if(position == 1 ){
        insertAtHead(head , data);
    }
    // keep the track of the traversel
    int cntr = 1;
    while(cntr < position - 1){
        tmp = tmp -> next;
        cntr++;
        // if we have to add element at the last positon
    }
    if(tmp == NULL){
        insertAtTail(tail,data);
        // no need to go furthur just return to the main function
        return;
    }
    Node* newNode = new Node(data);
    newNode -> next = tmp -> next ;
    tmp -> next = newNode;
}
// deleting the node at given position 
void deleteNodeAt(Node* &head , Node* &tail , int position){
    if(position == 1){
        Node* tmp = head;
        head = head -> next;
        delete tmp;
    }
    else{
        Node* curr = head ;
        Node* prev = NULL;
        /*
        never create a  wild pointer , it will any random memery
        eg: Node* pt ;
        NEVER DO IT !
        */
       int cntr = 1;
       while(cntr < position ){
        prev = curr;
        curr = curr -> next;
        cntr++;
       }
       prev -> next = curr -> next;
       // memory deallocation for curr
       delete curr;

    }
}
// ddekete the node of hiven data
void deleteNodeWhere(Node* &head , int data){
    if(head -> data == data){
        Node* tmp = head;
        head = head -> next ;
        delete tmp;
    }
    else{
        Node* curr =  head;
        Node* prev = NULL;
        while(curr -> data != data){
            prev = curr;
            curr = curr -> next;
        }
        prev -> next = curr -> next;
        delete curr;
    }
}
int main(){
    Node * node1;
    node1 = new Node(2);
    Node * head  = node1;
    Node * tail = node1;
    insertAtHead(head , 1);
    insertAtTail(tail, 3);
    insertAtTail(tail, 4);
    insertAtTail(tail, 5);
    insertAtTail(tail, 6);
    insertAt(head ,tail , 6 , 7);
    insertAt(head , tail , 8,99);
    // deleteNodeAt(head , tail , 1);
    Print(head);
    // deleteNodeAt(head , tail , 5);
    // deleteNodeWhere(head , 1);
    Print(head);
    cout<<"Head -> "<<head -> data<<endl;
    cout<<"Tail -> "<<tail -> data<<endl;
    return 0;
}
