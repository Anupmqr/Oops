#include<iostream>

using namespace std;

struct node{
    int data;
    struct node *next;
    struct node *prev;
}*head;

// Create a doubly linked list
void createList(int n){
    struct node *newNode, *temp;
    int data;
    head = new(node); // allocate memory

    if(head == NULL){
        cout << "Unable to allocate memory\n";
        exit(1);
    }

    cout << "Enter the data of node 1: ";
    cin >> data;

    head->data = data;
    head->next = NULL;
    head->prev = NULL;

    temp = head;
    for(int i=2; i<=n; i++){
        newNode = new(node);

        if(head == NULL){
        cout << "Unable to allocate memory\n";
        break;
        }

        cout << "Enter the data of node " << i << ": ";
        cin >> data;

        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = temp;

        temp->next = newNode;
        temp = temp->next;
    }
}

// Traverse and display the doubly linked list
void traverseList(){
    struct node *temp;

    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Insert a node at the beginning of the doubly linked list
void insertNodeAtBeginning(int data){
   struct node *newNode;
    newNode = new(node);

    if (newNode == NULL) {
        cout << "Unable to allocate memory\n";
    } else {
        newNode->data = data;
        newNode->next = head;
        newNode->prev = NULL;

        if (head != NULL) {
            head->prev = newNode;
        }

        head = newNode;

        cout << "DATA INSERTED SUCCESSFULLY\n";
    }
}

// Insert a node at the end of the doubly linked list
void insertNodeAtEnd(int data){
    struct node *newNode, *temp;
    newNode = new(node);

    if (newNode == NULL) {
        cout << "Unable to allocate memory\n";
    } else {
        newNode->data = data;
        newNode->next = NULL;

        temp = head;
        while (temp != NULL && temp->next != NULL) {
            temp = temp->next;
        }

        if (temp != NULL) {
            newNode->prev = temp;
            temp->next = newNode;
            cout << "DATA INSERTED SUCCESSFULLY\n";
        } else {
            cout << "List is empty\n";
            head = newNode;
            cout << "DATA INSERTED SUCCESSFULLY\n";
        }
    }
}

// Insert a node at the middle of the doubly linked list
void insertNodeAtMiddle(int data, int position){
    struct node *newNode, *temp;
    newNode = new(node);

    if(newNode == NULL){
        cout << "Unable to allocate memory\n";
    }
    else{
        newNode -> data = data;
        newNode -> next = NULL;

        temp = head;

        for(int i=2; i<=position-1; i++){
            temp = temp -> next;

            if(temp == NULL){
                break;
            }
        }

        if (temp != NULL) {
            newNode->next = temp->next;
            newNode->prev = temp;
            
            if (temp->next != NULL) {
                temp->next->prev = newNode;
            }

            temp->next = newNode;
            cout << "DATA INSERTED SUCCESSFULLY\n";
        } else {
            cout << "UNABLE TO INSERT DATA AT THE GIVEN POSITION\n";
        }
    }
}

// Delete the first node of the doubly linked list
void deleteFirstNode(){
    if (head == NULL) {
        cout << "List is already empty\n";
    } else {
        struct node *toDelete = head;
        head = head->next;

        if (head != NULL) {
            head->prev = NULL;
        }

        cout << "Data deleted = " << toDelete->data << "\n";
        delete toDelete;
        cout << "SUCCESSFULLY DELETED FIRST NODE FROM THE LIST\n";
    }
}

// Delete the last node of the doubly linked list
void deleteLastNode(){
   if (head == NULL) {
        cout << "List is already empty\n";
    } else {
        struct node *toDelete = head;
        while (toDelete->next != NULL) {
            toDelete = toDelete->next;
        }

        if (toDelete->prev != NULL) {
            toDelete->prev->next = NULL;
        } else {
            head = NULL;
        }

        cout << "SUCCESSFULLY DELETED LAST NODE OF LIST\n";
        delete toDelete;
    }
}

// Delete a node at a given position in the doubly linked list
void deleteMiddleNode(int position){
    if (head == NULL) {
        cout << "List is already empty.\n";
    } else {
        struct node *toDelete = head;
        for (int i = 1; i < position && toDelete != NULL; i++) {
            toDelete = toDelete->next;
        }

        if (toDelete != NULL) {
            if (toDelete->prev != NULL) {
                toDelete->prev->next = toDelete->next;
            } else {
                head = toDelete->next;
            }

            if (toDelete->next != NULL) {
                toDelete->next->prev = toDelete->prev;
            }

            cout << "SUCCESSFULLY DELETED NODE FROM MIDDLE OF LIST\n";
            delete toDelete;
        } else {
            cout << "Invalid position unable to delete.\n";
        }
    }
}

// Delete the entire doubly linked list
void deleteList(){
    struct node *temp;

    while (head != NULL) {
        temp = head;
        head = head->next;

        delete temp;
    }

    cout << "SUCCESSFULLY DELETED ALL NODES OF LINKED LIST\n";
}

// Delete the first node with a given key from the doubly linked list
void deleteFirstByKey(int key)
{
    struct node *current = head;
    while (current != NULL) {
        if (current->data == key) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                head = current->next;
            }

            if (current->next != NULL) {
                current->next->prev = current->prev;
            }

            cout << "Successfully deleted node with key " << key << "\n";
            delete current;
            return;
        }
        current = current->next;
    }
    cout << "Key not found in the list.\n";
}

// Count the number of nodes in the doubly linked list
int countNodes()
{
    int count = 0;
    struct node *temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}

// Reverse the doubly linked list
void reverseList()
{
    struct node *temp = NULL;
    struct node *current = head;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL) {
        head = temp->prev;
    }

    cout << "SUCCESSFULLY REVERSED LIST\n";
}

// Search for an element in the doubly linked list and return its position
int search(int key)
{
    int index = 0;
    struct node *current = head;

    while (current != NULL && current->data != key) {
        index++;
        current = current->next;
    }

    return (current != NULL) ? index : -1;
}

int main(){
    cout << "************** CHOOSE OPERATION: *****************\n";
    cout << "\t\t1. Creation\n";
    cout << "\t\t2. Traverse(Display)\n";
    cout << "\t\t3. Insert at Begining\n";
    cout << "\t\t4. Insert at End\n";
    cout << "\t\t5. Insert at Middle\n";
    cout << "\t\t6. Delete First\n";
    cout << "\t\t7. Delete Last\n";
    cout << "\t\t8. Delete Middle\n";
    cout << "\t\t9. Delete All\n";
    cout << "\t\t10. Delete by Key\n";
    cout << "\t\t11. Count Nodes\n";
    cout << "\t\t12. Reverse List\n";
    cout << "\t\t13. Search an element\n";
    cout << "\t\t0. Exit\n";
    cout << "**************************************************\n";



    while(1){
        int choice;
        cin >> choice;
    switch (choice){
        case 1 :
        int n;
        cout << "Enter the total no. of nodes: ";
        cin >> n;
        createList(n);
        break;

        case 2:
        traverseList();
        break;

        case 3:
        int data;
        cout << "Enter data to insert at beginning of the list: ";
        cin >> data;
        insertNodeAtBeginning(data);
        break;

        case 4:
        cout << "Enter data to insert at end of the list: ";
        cin >> data;
        insertNodeAtEnd(data);
        break;

        case 5:
        int position;
        cout << "Enter data to insert at middle of the list: ";
        cin >> data;
        cout << "Enter the position to insert new node: ";
        cin >> position;
        insertNodeAtMiddle(data,position);
        break;

        case 6:
        deleteFirstNode();
        break;

        case 7:
        deleteLastNode();
        break;

        case 8:
        cout<<"Enter the node position you want to delete: ";
        cin  >> position;
        deleteMiddleNode(position);
        break;

        case 9:
        deleteList();
        break;

        case 10:
        int key;
        cout << "Enter element to delete with key: ";
        cin >> key;
        deleteFirstByKey(key);
        break;

        case 11:
        cout << "Total number of nodes = " << countNodes() << endl;
        break;

        case 12:
        reverseList();
        break;

        case 13:
        int keyToSearch;
        cout << "Enter element to search: ";
        cin >> keyToSearch;

        if (search(keyToSearch) >= 0)
        cout << keyToSearch << " found in the list at position " << search(keyToSearch) + 1 << endl;
        else
        cout << keyToSearch << " not found in the list.\n";
        break;

        case 0:
        exit(0);
        break;

        default:
        cout << "Invalid choice!!!";
        break;
    }
    }
return 0;

}