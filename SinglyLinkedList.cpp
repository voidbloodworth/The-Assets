#include <iostream>
using namespace std;

class Node{
public:
    int value;
    Node *next;

    Node(int value){
        this->value = value;
        next = nullptr;
    }
};

class LinkedList{
    Node *head;
    int size = 0;

public:
    LinkedList(){
        head = nullptr;
    }

    void insertInList(int position, int value){
        Node *newNode = new Node(value);

        if (position == 1){
            newNode->next = head;
            head = newNode;
        }
        else{
            Node *temp = head;
            for (int i = 1; i < position - 1; ++i)
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
        ++size;
    }

    void updateInList(){
        if (size > 0){
            cout << "\nPosition Number: ";
            int position;
            cin >> position;

            if (position > 0 && position <= size){

                cout << "Enter Value: ";
                int posValue;
                cin >> posValue;

                Node *temp = head;
                for (int i = 1; i < position; i++)
                {
                    temp = temp->next;
                }
                temp->value = posValue;
                cout << "\nList Updated Successfully..." << endl;
            }
            else{
                cout << "\nError: Invalid Position Number\n";
            }
        }
        else{
            cout << "\nError: There is no value in the list...\n";
        }
    }

    void searchInList(){
        if (size > 0){
            Node *temp = head;

            int findValue;

            cout << "Enter Value: ";
            cin >> findValue;
            cout << endl;

            bool found = false;
            for (int i = 1; i <= size; i++){
                if (temp->value == findValue){
                    cout << "Value " << findValue << " is currently at position " << i << endl;
                    found = true;
                }
                temp = temp->next;
            }

            if (!found){
                cout << "Value not found in the list..." << endl;
            }
        }
        else{
            cout << "\nError: There is no value in the list...\n";
        }
    }

    void displayList(){
        if (size > 0 && head != nullptr){
            Node *temp = head;

            cout << "List: ";
            while (temp != nullptr){
                cout << temp->value << " -> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
        else{
            cout << "\nError: There is no value in the list...\n";
        }
    }

    void deleteInList(int position){
        if (head == nullptr || position < 1 || position > size){
            cout << "\nError: Invalid Position Number\n";
            return;
        }

        if (position == 1){
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        else{

            Node *temp = head;
            for (int i = 1; i < position - 1; i++){
                temp = temp->next;
            }

            Node *deleteNode = temp->next;
            temp->next = deleteNode->next;
            delete deleteNode;
        }
        --size;
        cout << "\nNumber Deleted Successfully..." << endl;
    }

    void clearList(){
        if (size > 0){
            Node *temp = head;
            while (temp != nullptr)
            {
                Node *nextNode = temp->next;
                delete temp;
                temp = nextNode;
            }
            head = nullptr;
            size = 0;
        }

        else{
            cout << "\nThere is no value in the list..." << endl;
        }
    }

    int getSize(){
        return size;
    }

    ~LinkedList(){
        Node *temp = head;
        while (temp != nullptr)
        {
            Node *nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }
};

int main(){
    LinkedList list;
    int choice;

    do{

        cout << "\n====== Operations ======\n";
        cout << "1. Insert in List\n";
        cout << "2. Update in List\n";
        cout << "3. Search in List\n";
        cout << "4. Display List\n";
        cout << "5. Delete in List\n";
        cout << "6. Clear List\n";
        cout << "7. Exit\n"
             << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice){
        case 1:
            int position;
            cout << "\nPosition Number: ";
            cin >> position;

            if (position < 1 || position > list.getSize() + 1){
                cout << "\nError: Invalid Position Number\n";
            }
            else{
                int posValue;
                cout << "Value: ";
                cin >> posValue;
                list.insertInList(position, posValue);

                cout << "\nNumber Added Successfully..." << endl;
            }
            break;
        case 2:
            list.updateInList();
            break;
        case 3:
            list.searchInList();
            break;
        case 4:
            list.displayList();
            break;
        case 5:
            if (list.getSize() > 0){
                int delPosition;
                cout << "\nPosition Number: ";
                cin >> delPosition;

                if (delPosition < 1 && delPosition > list.getSize()){
                    cout << "\nError: Invalid Position Number\n";
                }
                else{
                    list.deleteInList(delPosition);
                }
            }

            else{
                cout << "\nThere is no value in the list..." << endl;
            }
            break;
        case 6:
            list.clearList();
            break;
        case 7:
            cout << "\nExiting program...\n";
            return 0;
            break;
        default:
            cout << "\nInvalid choice! Try again.\n";
        }
    } while (choice != 7);

    return 0;
}