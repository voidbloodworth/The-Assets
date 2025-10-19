#include <iostream>
using namespace std;

class Node{
    public:
        Node* prev;
        long long int value;
        Node* next;

        Node(long long int value){
            prev = nullptr;
            this->value = value;
            next = nullptr;
        }
};

class LinkedList{
    Node* head;
    int size = 0;

    public:
        LinkedList(){
            head = nullptr;
        }

        int getListSize(){
            return size;
        }

        void insertAtPosition(int position, long long int value){
            Node* newNode = new Node(value);
            if(position == 1){
                newNode->next = head;
                head = newNode;
                size++;
            }
            else{
                Node* temp = head;

                for(int i = 1; i < position-1; i++){
                    temp = temp->next;
                }
                newNode->next = temp->next;
                newNode->prev = temp;
                temp->next = newNode;
                if(newNode->next != nullptr){temp->next->prev = newNode;}
                size++;
            }
        }

        void updateInList(int position, long long int value){
            Node* temp = head;
            for(int i = 1; i < position; i++){
                temp = temp->next;
            }
            temp->value = value;
        }

        void searchInList(long long int value){
            int counter = 1;
            Node* temp = head;
            bool found = false;
            cout << endl;
            while(temp != nullptr){
                if(temp->value == value){
                    cout << "Value is placed at position: " << counter << endl;
                    found = true;
                }
                temp = temp->next;
                counter++;
            }

            if(!found){
                cout << "\nValue not found...\n";
            }
        }

        void displayList(){
            Node* temp = head;
            cout << "List: ";
            for(int i = 1; i <= size; i++){
                cout << temp->value << " ";
                temp = temp->next;
            }
            cout << endl;
        }

        void deleteAtPostion(int position){
            Node* temp = head;

            if(position == 1){
                head = head->next;
                if(head != nullptr){head->prev = nullptr;}
                delete temp;
                size--;
            }
            else{
                for(int i = 1; i < position-1; i++){
                    temp = temp->next;
                }
                Node* deleteNode = temp->next;
                temp->next = deleteNode->next;
                if(temp->next != nullptr){temp->next->prev = temp;}
                size--;
            }
        }

        void clearList(){
            Node* temp = head;
            while(temp != nullptr){
                Node* copyNode = temp->next;
                delete temp;
                temp = copyNode;
            }
            head == nullptr;
            size = 0;
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
        cout << "7. Exit\n" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice){
        case 1:
            if(list.getListSize() == 0){
                long long int value;
                cout << "Enter Value: ";
                cin >> value;
                list.insertAtPosition(1, value);
                cout << "\nValue added successfully...\n" << endl;
                list.displayList();
            }
            else{
                int entryPosition;
                cout << "Enter Position: ";
                cin >> entryPosition;

                if(entryPosition < 1 || entryPosition > list.getListSize() + 1){
                    cout << "\nError: Position number is not valid...\n";
                }
                else{
                    long long int value;
                    cout << "Enter Value: ";
                    cin >> value;
                    list.insertAtPosition(entryPosition, value);
                    cout << "\nValue added successfully...\n" << endl;
                    list.displayList();
                }
            }
            break;

        case 2:
            if(list.getListSize() < 1){
                cout << "\nError: There is no value in the list...\n";
                continue;
            }
            int updateInPosition;
            cout << "Enter Position: ";
            cin >> updateInPosition;
            if(updateInPosition < 1 || updateInPosition > list.getListSize()){
                cout << "\nError: Position number is not valid...\n";
            }
            else{
                long long int updatedValue;
                cout << "Enter Value: ";
                cin >> updatedValue;
                list.updateInList(updateInPosition, updatedValue);
                cout << "\nValue updated successfully...\n" << endl;
                list.displayList();
            }
            break;

        case 3:
            if(list.getListSize() < 1){
                cout << "\nError: There is no value in the list...\n";
                continue;
            }
            long long int searchValue;
            cout << "Enter Value: ";
            cin >> searchValue;
            list.searchInList(searchValue);
            break;

        case 4:
            if(list.getListSize() < 1){
                cout << "\nError: There is no value in the list...\n";
                continue;
            }
            cout << endl;
            list.displayList();
            break;

        case 5:
            if(list.getListSize() < 1){
                cout << "\nError: There is no value in the list...\n";
                continue;
            }
            int delPosition;
            cout << "Enter Position: ";
            cin >> delPosition;

            if(delPosition < 1 || delPosition > list.getListSize()){
                cout << "\nError: Position number is not valid...\n";
            }
            else{
                list.deleteAtPostion(delPosition);
                cout << "\nValue deleted successfully...\n" << endl;
                list.displayList();
            }
            break;

        case 6:
            if(list.getListSize() < 1){
                cout << "\nError: There is no value in the list...\n";
                continue;
            }
            list.clearList();
            cout << "\nList cleared successfully...\n";
            list.displayList();
            break;
        case 7:
            cout << "\nExitting the program...\n\n";
            break;

        default:
            cout << "\nInvalid choice! Try again...\n";
        }
    } while (choice != 7);

    return 0;
}