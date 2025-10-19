#include <iostream>
using namespace std;

void displayList(int *&arr, int size){
    cout << "\nNow, your array is: ";
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void updateNum(int *&arr, int size){
    int index;
    cout << "\nOn which index you want to add a number: ";
    cin >> index;

    if (index < size && index >= 0){
        int indexValue;

        cout << "Which value you want to add on index " << index << ": ";
        cin >> indexValue;
        arr[index] = indexValue;
        cout << "Value updated successfully!\n";
    }
    else{
        cout << "Index does not exist!\n";
    }
}

// Find Function
void findNum(int *&arr, int size){
    if (size != 0){
        int num;
        cout << "\nWhich value you want to find: ";
        cin >> num;

        bool found = false;
        for (int i = 0; i < size; i++){
            if (arr[i] == num)
            {
                cout << arr[i] << " is on index " << i << "\n";
                found = true;
            }
        }
        if (!found){
            cout << "Value not found!\n";
        }
    }
    else{
        cout << "There is no value in the list\n";
    }
}

// Add Function
void addNum(int *&arr, int &size){
    int index;
    cout << "\nWhere you want to add? Index: ";
    cin >> index;

    if (index >= 0 && index <= size){
        int indexValue;
        cout << "Which value you want to add at index " << index << ": ";
        cin >> indexValue;

        int *newArr = new int[size + 1];
        for (int i = 0; i < index; i++){
            newArr[i] = arr[i];
        }
        newArr[index] = indexValue;
        for (int i = index; i < size; i++){
            newArr[i + 1] = arr[i];
        }
        delete[] arr;

        arr = newArr;
        ++size;

        cout << "Value added successfully!\n";
    }
    else{
        cout << "Insert correct index!\n";
    }
}

// Remove Function
void removeNum(int *&arr, int &size){
    int index;
    cout << "\nWhich index you want to remove: ";
    cin >> index;

    if (index >= 0 && index < size){
        int *newArr = new int[size - 1];
        for (int i = 0, j = 0; i < size; i++){
            if (i == index)
                continue;
            newArr[j++] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        --size;

        cout << "Value removed successfully!\n";
    }
    else{
        cout << "Error! Insert correct index.\n";
    }
}

// Deep Copy Function
void copyArr(int *&arr, int size){
    if (size != 0){
        int *newArr = new int[size];
        for (int i = 0; i < size; i++)
        {
            newArr[i] = arr[i];
        }
        cout << "\nYour copied array is: ";
        for (int i = 0; i < size; i++)
        {
            cout << newArr[i] << " ";
        }
        cout << "\n";
        delete[] newArr;
    }
    else{
        cout << "There is nothing to copy, list is empty\n";
    }
}

// Clear Function
void clearArr(int *&arr, int &size){
    delete[] arr;
    arr = nullptr;
    size = 0;
    cout << "\nNow your list is empty. Restart the program to fill the list.\n";
}

int main(){
    int size;
    cout << "How much size of list you want: ";
    cin >> size;
    cout << "\n";

    int *list = nullptr;
    list = new int[size];

    for (int i = 0; i < size; i++){
        cout << "Enter number " << i + 1 << ": ";
        cin >> list[i];
    }

    char close;
    do{
        cout << "\n\n==============================\n";
        cout << " Array Operations Menu\n";
        cout << "==============================\n";

        cout << "1. Update\n"
             << "2. Find\n"
             << "3. Add\n"
             << "4. Remove\n"
             << "5. Copy\n"
             << "6. Clear\n";
        cout << "------------------------------\n";

        int choice;
        cout << "Which operation you want to perform? ";
        cin >> choice;
        cout << "\n";

        switch (choice){
        case 1:
            updateNum(list, size);
            displayList(list, size);
            break;

        case 2:
            findNum(list, size);
            break;

        case 3:
            addNum(list, size);
            displayList(list, size);

            break;

        case 4:
            removeNum(list, size);
            displayList(list, size);
            break;

        case 5:
            copyArr(list, size);
            break;

        case 6:
            clearArr(list, size);
            break;

        default:
            cout << "Enter correct choice!\n";
        }

        cout << "\nDo you want to perform another operation? (y/n): ";
        cin >> close;
    } while (close != 'n');

    cout << "\nProgram ended. Goodbye!\n";
    return 0;
}