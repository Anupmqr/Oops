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
        newNode -> next = NULL;

        temp -> next = newNode;
        temp = temp -> next;
    }
}

void traverseList(){
    struct node *temp;

    if(head == NULL){
        cout << "List is empty\n";
        return;
    }

    temp = head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

void insertNodeAtBeginning(int data){
   struct node *newNode;
   newNode = new(node);
   
   if(newNode == NULL){
    cout << "Unable to allocate memory\n";
   }
    else{
        newNode->data = data;
        newNode -> next = head;

        head = newNode;

        cout << "DATA INSERTED SUCESSFULLY\n";
    }
}

void insertNodeAtEnd(int data){
    struct node *newNode, *temp;
    newNode = new(node);

    if(newNode == NULL){
    cout << "Unable to allocate memory\n";
    }
    else{
        newNode -> data = data;
        newNode -> next = NULL;
    }

    temp = head;
    while(temp!=NULL && temp->next != NULL){
        temp = temp -> next;
    }
    temp -> next = newNode;
    cout << "DATA INSERTED SUCESSFULLY\n";
}

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

        if(temp != NULL){
            newNode->next = temp -> next;

            temp -> next = newNode;
            cout << "DATA INSERTED SUCESSFULLY\n";
        }
        else{
            cout << "UNABLE TO INSERT DATA AT THE GIVEN POSITION\n";
        }
    }
}

void deleteFirstNode(){

    struct node *toDelete;

    if(head == NULL){
        cout << "List is already empty\n";
    }
    else{
        toDelete = head;
        head = head->next;
        cout << "Data deleted= " << toDelete->data << "\n";
        free(toDelete);
        cout << "SUCCESSFULLY DELETED FIRST NODE FROM THE LIST\n"; 
    }
}

void deleteLastNode(){
   struct node *toDelete, *secondLastNode;

    if(head == NULL){
        cout << "List is already empty\n";
    }
    else{
        toDelete = head;
        secondLastNode = head;
        
        while(toDelete->next!=NULL){
            secondLastNode = toDelete;
            toDelete = toDelete -> next;
        } 

        if(toDelete == head){
            head = NULL;
        }
        else{
            secondLastNode->next = NULL;
            free(toDelete);
            cout << "SUCCESSFULLY DELETED LAST NODE OF LIST\n";
        }
    } 
}

void deleteMiddleNode(int position){
    struct node *toDelete, *prevNode;

    if(head == NULL){
        cout << "List is already empty.\n";
    }
    else{
        toDelete = head;
        prevNode = head;

        for(int i=2; i<=position; i++)
        {
            prevNode = toDelete;
            toDelete = toDelete->next;

            if(toDelete == NULL)
                break;
        }

        if(toDelete != NULL)
        {
            if(toDelete == head)
                head = head->next;

            prevNode->next = toDelete->next;
            toDelete->next = NULL;

            free(toDelete);
            cout  << "SUCCESSFULLY DELETED NODE FROM MIDDLE OF LIST\n";
        }
        else
        {
            cout<<"Invalid position unable to delete.\n";
        }
    }
}

void deleteList(){
    struct node *temp;

    while(head != NULL)
    {
        temp = head;
        head = head->next;

        free(temp);
    }

    cout << "SUCCESSFULLY DELETED ALL NODES OF LINKED LIST\n";
}

void deleteFirstByKey(int key)
{
    struct node *prev, *cur;
    while (head != NULL && head->data == key)
    {
        prev = head;
        head = head->next;
        free(prev);
        return;
    }

    prev = NULL;
    cur  = head;

    while (cur != NULL)
    {
        if (cur->data == key)
        {
            if (prev != NULL) 
                prev->next = cur->next;

            free(cur);
            return;
        } 

        prev = cur;
        cur = cur->next;
    }
}

int countNodes()
{
    int count = 0;
    struct node *temp;

    temp = head;

    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

void reverseList()
{
    struct node *prevNode, *curNode;

    if(head != NULL)
    {
        prevNode = head;
        curNode = head->next;
        head = head->next;

        prevNode->next = NULL;
        while(head != NULL)
        {
            head = head->next;
            curNode->next = prevNode;

            prevNode = curNode;
            curNode = head;
        }

        head = prevNode;

        cout << "SUCCESSFULLY REVERSED LIST\n";
    }
}

int search(int key)
{
    int index;
    struct node *curNode;

    index = 0;
    curNode = head;

    while (curNode != NULL && curNode->data != key)
    {
        index++;
        curNode = curNode->next;
    }


    return (curNode != NULL) ? index : -1;
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