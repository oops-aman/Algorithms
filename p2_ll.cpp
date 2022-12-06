#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node* jump;

        Node(int val) {
            this -> data = val;
            this -> next = NULL;
            this -> jump = NULL;
        }
};

void insertAtBegin(Node* &head, int val) {
    Node* node = new Node(val);
    node -> next = head;

    if(head != NULL) {
        node -> jump = head -> next;
    } else {
        node -> jump = NULL;
    }

    head = node;
}

void insertAtEnd(Node* &head, int val) {
    if(head == NULL) {
        insertAtBegin(head, val);
        return ;
    }

    Node* node = new Node(val);
    Node* ptr = head;
    while(ptr -> next != NULL) {
        if(ptr -> next -> next == NULL) {
            ptr -> jump = node;
        }
        ptr = ptr -> next;
    }
    ptr -> next = node;
}

void insertAfter(Node* &head, int key, int val) {
    Node* ptr = head;
    Node* node = new Node(val);
    
    if(head -> data == key) {
        insertAtBegin(head, val);
    }
    while(ptr != NULL) {
        if(ptr -> next -> next != NULL and ptr -> next -> next -> data == key) {
            node -> jump = ptr -> next -> next -> jump;
            ptr -> next -> next -> jump = ptr -> next -> next -> next;
            node -> next = ptr -> next -> next -> jump;
            ptr -> next -> next -> next = node;
            ptr -> next -> jump= node;
            return ;
        } else if(ptr -> next != NULL and ptr -> next -> data == key) {
            node -> jump = ptr ->next -> jump;
            ptr -> jump = node;
            node -> next = ptr -> next -> next;
            ptr -> next -> next = node;
            ptr -> next -> jump = node -> next;
            return ;
        }
        ptr = ptr -> next;
    }
    if(ptr -> next == NULL) {
        insertAtEnd(head, val);
    }
}

void display(Node* &head) {
    Node* temp = head;
    cout << "List with its Jump : " << endl;
    while(temp != NULL) {
        cout << temp -> data;
        if(temp -> jump) {
            cout << " and Jump Value : " << temp -> jump -> data << endl;
        } else {
            cout << "NULL" << endl;
        }
        temp = temp -> next;
    }
}

int main() {
    Node* head = NULL;

    int ch1 = 1, ch2;
    int num, key;
    while(ch1 == 1) {
        cout << "Linked List Menu\n";
        cout << "\n1. Insert at begin \n2. Insert at end \n3. Insert after a given element \n4. Display";
        cout << "\nEnter your choice(1-4) : ";
        cin >> ch2;

        switch(ch2) {
            case 1: cout << "Enter data to insert : ";
                    cin >> num;
                    insertAtBegin(head, num);
                    break;

            case 2: cout << "Enter data to insert : ";
                    cin >> num;
                    insertAtEnd(head, num);
                    break;

            case 3: cout << "Enter data to insert : ";
                    cin >> num;
                    cout << "Enter element after which to be inserted : ";
                    cin >> key;
                    insertAfter(head, key, num);
                    break;

            case 4: display(head);
                    break;
        }

        cout << "Enter 1 to continue and 0 to exit : ";
        cin >> ch1;
    }

    return 0;

}