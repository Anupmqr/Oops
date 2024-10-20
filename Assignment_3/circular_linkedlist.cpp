#include<iostream>

using namespace std;

struct node{
    int data;
    struct node *next;
}*head;


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

    temp = head;
    for(int i=2; i<=n; i++){
        newNode = new(node);

        if(head == NULL){
        cout << "Unable to allocate memory\n";
        break;
        }

        cout << "Enter the data of node " << i << ": ";
        cin >> data;

        newNode -> data = data;
        newNode -> next = head;

        temp -> next = newNode;
        temp = temp -> next;
    }
}

void traverseList(){
    struct node* temp;

    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }

    temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

void insertNodeAtBeginning(int data){
   struct node* newNode = new node;

    if (newNode == nullptr) {
        cout << "Unable to allocate memory\n";
        return;
    }

    newNode->data = data;
    newNode->next = head; 

    struct node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode; 
    head = newNode; 
    cout << "Data inserted successfully at the beginning\n";
}

void insertNodeAtEnd(int data){
   struct node* newNode = new node;

    if (newNode == nullptr) {
        cout << "Unable to allocate memory\n";
        return;
    }

    newNode->data = data;
    newNode->next = head; 

    struct node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode; 

    cout << "Data inserted successfully at the end\n";
}

void insertNodeAtMiddle(int data, int position){
     if (position < 1) {
        cout << "Invalid position\n";
        return;
    }

    struct node* newNode = new node;

    if (newNode == nullptr) {
        cout << "Unable to allocate memory\n";
        return;
    }

    newNode->data = data;

    if (position == 1) {
        newNode->next = head;
        head = newNode;
    struct node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;

        cout << "Data inserted successfully at position " << position << endl;
    } else {
        struct node* temp = head;
        int currentPosition = 1;

        while (temp != nullptr && currentPosition < position - 1) {
            temp = temp->next;
            currentPosition++;
        }

        if (temp == nullptr) {
            cout << "Invalid position, unable to insert\n";
        } else {
            
            newNode->next = temp->next;
            temp->next = newNode;

            if (temp->next == head) {
                head = newNode;
            }

            cout << "Data inserted successfully at position " << position << endl;
        }
    }
}

void deleteFirstNode(){
if (head == nullptr) {
        cout << "List is already empty\n";
        return;
    }

    struct node* toDelete = head;

    if (head->next == head) {
        // Only one node in the list
        head = nullptr;
    } else {
        struct node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = head->next;
        head = head->next;
    }

    delete toDelete;
    cout << "Successfully deleted the first node from the list\n";
}

void deleteLastNode(){
   if (head == nullptr) {
        cout << "List is already empty\n";
        return;
    }

    struct node* toDelete = head;
    struct node* prevNode = nullptr;

    while (toDelete->next != head) {
        prevNode = toDelete;
        toDelete = toDelete->next;
    }

    if (toDelete == head) {
        head = nullptr;
    } else {
        prevNode->next = head;
    }

    delete toDelete;
    cout << "Successfully deleted the last node from the list\n";
}

void deleteMiddleNode(int position){
    if (head == nullptr) {
        cout << "List is already empty\n";
        return;
    }

    if (position < 1) {
        cout << "Invalid position\n";
        return;
    }

    if (position == 1) {
        // Deleting the first node
        deleteFirstNode();
        return;
    }

    struct node* toDelete = head;
    struct node* prevNode = nullptr;

    for (int i = 1; i < position; i++) {
        prevNode = toDelete;
        toDelete = toDelete->next;

        if (toDelete == head) {
            cout << "Invalid position, unable to delete\n";
            return;
        }
    }

    prevNode->next = toDelete->next;
    delete toDelete;
    cout << "Successfully deleted node at position " << position << endl;
}

void deleteList(){
    if (head == nullptr) {
        cout << "List is already empty\n";
        return;
    }

    struct node* temp = head;
    struct node* toDelete;

    do {
        toDelete = temp;
        temp = temp->next;
        delete toDelete;
    } while (temp != head);

    head = nullptr;
    cout << "Successfully deleted all nodes of the linked list\n";
}

void deleteFirstByKey(int key)
{
    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }

    struct node* cur = head;
    struct node* prev = nullptr;
    bool found = false;

    do {
        if (cur->data == key) {
            found = true;
            break;
        }

        prev = cur;
        cur = cur->next;
    } while (cur != head);

    if (found) {
        if (prev != nullptr) {
            prev->next = cur->next;
            if (cur == head) {
                head = cur->next; 
            }
        } else {
            if (cur->next == head) {
                head = nullptr; 
            } else {
                struct node* temp = head;
                while (temp->next != head) {
                    temp = temp->next;
                }
                temp->next = cur->next;
                head = cur->next; 
            }
        }
        delete cur;
        cout << "Successfully deleted the first node with key " << key << endl;
    } else {
        cout << "Key not found in the list\n";
    }
}

int search(int key)
{
    if (head == nullptr) {
        cout << "List is empty\n";
        return -1;
    }

    int index = 0;
    struct node* curNode = head;

    do {
        if (curNode->data == key) {
            return index;
        }

        index++;
        curNode = curNode->next;
    } while (curNode != head);

    cout << key << " not found in the list\n";
    return -1;
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
    cout << "\t\t11. Search an element\n";
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