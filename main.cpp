#include "header.h"
#include <cassert>

// ═══════════════════════════════════════════════════════════════════════════════
// ARRAY LIST IMPLEMENTATION
// ═══════════════════════════════════════════════════════════════════════════════

template <class elemType>
bool arrayListType<elemType>::isEmpty() const { return (length == 0); }

template <class elemType>
bool arrayListType<elemType>::isFull() const { return (length == maxSize); }

template <class elemType>
int arrayListType<elemType>::listSize() const { return length; }

template <class elemType>
int arrayListType<elemType>::maxListSize() const { return maxSize; }

template <class elemType>
void arrayListType<elemType>::print() const {
    for (int i = 0; i < length; i++)
        cout << list[i] << " ";
    cout << endl;
}

template <class elemType>
bool arrayListType<elemType>::isItemAtEqual(int location, const elemType& item) const {
    return (list[location] == item);
}

template <class elemType>
void arrayListType<elemType>::insertAt(int location, const elemType& insertItem) {
    if (location < 0 || location >= maxSize)
        cerr << "The position of the item to be inserted is out of range." << endl;
    else if (length >= maxSize)
        cerr << "Cannot insert in a full list." << endl;
    else {
        for (int i = length; i > location; i--)
            list[i] = list[i - 1];
        list[location] = insertItem;
        length++;
    }
}

template <class elemType>
void arrayListType<elemType>::insertEnd(const elemType& insertItem) {
    if (length >= maxSize)
        cerr << "Cannot insert in a full list." << endl;
    else {
        list[length] = insertItem;
        length++;
    }
}

template <class elemType>
void arrayListType<elemType>::retrieveAt(int location, elemType& retItem) const {
    if (location < 0 || location >= length)
        cerr << "The location of the item to be retrieved is out of range." << endl;
    else
        retItem = list[location];
}

template <class elemType>
void arrayListType<elemType>::replaceAt(int location, const elemType& repItem) {
    if (location < 0 || location >= length)
        cerr << "The location of the item to be replaced is out of range." << endl;
    else
        list[location] = repItem;
}

template <class elemType>
void arrayListType<elemType>::clearList() { length = 0; }

template <class elemType>
arrayListType<elemType>::arrayListType(int size) {
    if (size < 0) {
        cerr << "Array size must be positive. Creating array of size 100." << endl;
        maxSize = 100;
    } else
        maxSize = size;
    length = 0;
    list = new elemType[maxSize];
    assert(list != NULL);
}

template <class elemType>
arrayListType<elemType>::~arrayListType() { delete[] list; }

template <class elemType>
arrayListType<elemType>::arrayListType(const arrayListType<elemType>& otherList) {
    maxSize = otherList.maxSize;
    length  = otherList.length;
    list    = new elemType[maxSize];
    assert(list != NULL);
    for (int j = 0; j < length; j++)
        list[j] = otherList.list[j];
}

template <class elemType>
const arrayListType<elemType>& arrayListType<elemType>::operator=(const arrayListType<elemType>& otherList) {
    if (this != &otherList) {
        delete[] list;
        maxSize = otherList.maxSize;
        length  = otherList.length;
        list    = new elemType[maxSize];
        assert(list != NULL);
        for (int i = 0; i < length; i++)
            list[i] = otherList.list[i];
    }
    return *this;
}

template <class elemType>
int arrayListType<elemType>::seqSearch(const elemType& item) const {
    for (int loc = 0; loc < length; loc++)
        if (list[loc] == item)
            return loc;
    return -1;
}

template <class elemType>
void arrayListType<elemType>::insert(const elemType& insertItem) {
    if (length == 0)
        list[length++] = insertItem;
    else if (length == maxSize)
        cerr << "Cannot insert in a full list." << endl;
    else {
        if (seqSearch(insertItem) == -1)
            list[length++] = insertItem;
        else
            cerr << "Item already in list. No duplicates allowed." << endl;
    }
}

template <class elemType>
void arrayListType<elemType>::remove(const elemType& removeItem) {
    if (length == 0)
        cerr << "Cannot delete from an empty list." << endl;
    else {
        int loc = seqSearch(removeItem);
        if (loc != -1)
            removeAt(loc);
        else
            cout << "The item to be deleted is not in the list." << endl;
    }
}

template <class elemType>
void arrayListType<elemType>::removeAt(int location) {
    if (location < 0 || location >= length) {
        cerr << "The location of the item to be removed is out of range." << endl;
        return;
    }
    for (int i = location; i < length - 1; i++)
        list[i] = list[i + 1];
    length--;
}

template <class elemType>
void arrayListType<elemType>::removeAll(const elemType& removeItem) {
    if (length == 0) {
        cerr << "Cannot delete from an empty list.";
        return;
    }
    int location = seqSearch(removeItem);
    if (location == -1) {
        cout << "Item to be deleted is not in the list.";
        return;
    }
    while (location != -1) {
        removeAt(location);
        location = seqSearch(removeItem);
    }
}

// ═══════════════════════════════════════════════════════════════════════════════
// LINKED LIST IMPLEMENTATION
// ═══════════════════════════════════════════════════════════════════════════════

template <class Type>
const linkedListType<Type>& linkedListType<Type>::operator=(const linkedListType<Type>& otherList) {
    if (this != &otherList)
        copyList(otherList);
    return *this;
}

template <class Type>
bool linkedListType<Type>::isEmptyList() const { return (first == NULL); }

template <class Type>
void linkedListType<Type>::print() const {
    nodeType<Type>* current = first;
    while (current != NULL) {
        cout << current->info << " ";
        current = current->link;
    }
    cout << endl;
}

template <class Type>
int linkedListType<Type>::length() const { return count; }

template <class Type>
void linkedListType<Type>::destroyList() {
    nodeType<Type>* temp;
    while (first != NULL) {
        temp  = first;
        first = first->link;
        delete temp;
    }
    last  = NULL;
    count = 0;
}

template <class Type>
linkedListType<Type>::linkedListType() {
    first = NULL;
    last  = NULL;
    count = 0;
}

template <class Type>
linkedListType<Type>::linkedListType(const linkedListType<Type>& otherList) {
    first = NULL;
    copyList(otherList);
}

template <class Type>
linkedListType<Type>::~linkedListType() { destroyList(); }

template <class Type>
void linkedListType<Type>::copyList(const linkedListType<Type>& otherList) {
    nodeType<Type>* newNode;
    nodeType<Type>* current;
    if (first != NULL)
        destroyList();
    if (otherList.first == NULL) {
        first = NULL; last = NULL; count = 0;
    } else {
        current      = otherList.first;
        count        = otherList.count;
        first        = new nodeType<Type>;
        first->info  = current->info;
        first->link  = NULL;
        last         = first;
        current      = current->link;
        while (current != NULL) {
            newNode        = new nodeType<Type>;
            newNode->info  = current->info;
            newNode->link  = NULL;
            last->link     = newNode;
            last           = newNode;
            current        = current->link;
        }
    }
}

template <class Type>
void unorderedLinkedList<Type>::insertFirst(const Type& newItem) {
    nodeType<Type>* newNode = new nodeType<Type>;
    newNode->info = newItem;
    newNode->link = linkedListType<Type>::first;
    linkedListType<Type>::first = newNode;
    linkedListType<Type>::count++;
    if (linkedListType<Type>::last == NULL)
        linkedListType<Type>::last = newNode;
}

template <class Type>
void unorderedLinkedList<Type>::insertLast(const Type& newItem) {
    nodeType<Type>* newNode = new nodeType<Type>;
    newNode->info = newItem;
    newNode->link = NULL;
    if (linkedListType<Type>::first == NULL) {
        linkedListType<Type>::first = newNode;
        linkedListType<Type>::last  = newNode;
    } else {
        linkedListType<Type>::last->link = newNode;
        linkedListType<Type>::last       = newNode;
    }
    linkedListType<Type>::count++;
}

template <class Type>
bool unorderedLinkedList<Type>::search(const Type& searchItem) const {
    nodeType<Type>* current = linkedListType<Type>::first;
    while (current != NULL) {
        if (current->info == searchItem)
            return true;
        current = current->link;
    }
    return false;
}

template <class Type>
void unorderedLinkedList<Type>::deleteNode(const Type& deleteItem) {
    nodeType<Type>* current;
    nodeType<Type>* trailCurrent;
    bool found;
    if (linkedListType<Type>::first == NULL) {
        cout << "Cannot delete from an empty list." << endl;
        return;
    }
    if (linkedListType<Type>::first->info == deleteItem) {
        current = linkedListType<Type>::first;
        linkedListType<Type>::first = linkedListType<Type>::first->link;
        linkedListType<Type>::count--;
        if (linkedListType<Type>::first == NULL)
            linkedListType<Type>::last = NULL;
        delete current;
    } else {
        found        = false;
        trailCurrent = linkedListType<Type>::first;
        current      = linkedListType<Type>::first->link;
        while (current != NULL && !found) {
            if (current->info != deleteItem) {
                trailCurrent = current;
                current      = current->link;
            } else
                found = true;
        }
        if (found) {
            trailCurrent->link = current->link;
            linkedListType<Type>::count--;
            if (linkedListType<Type>::last == current)
                linkedListType<Type>::last = trailCurrent;
            delete current;
        } else
            cout << "The item to be deleted is not in the list." << endl;
    }
}

// ═══════════════════════════════════════════════════════════════════════════════
// DATA STRUCTURES
// ═══════════════════════════════════════════════════════════════════════════════

struct customer {
    int    ID;
    string firstName;
    string lastName;

    bool operator==(const customer& o) const { return ID == o.ID; }
    bool operator!=(const customer& o) const { return ID != o.ID; }

    friend ostream& operator<<(ostream& os, const customer& c) {
        os << "Customer ID: "  << c.ID        << endl
           << "First Name: "   << c.firstName << endl
           << "Last Name: "    << c.lastName  << endl;
        return os;
    }
};

template <class Type>
class customerLinkedList : public unorderedLinkedList<customer> {
public:
    customer get_customer(int id) {
        nodeType<customer>* current = this->first;
        while (current != NULL) {
            if (current->info.ID == id)
                return current->info;
            current = current->link;
        }
        customer empty; empty.ID = -1; empty.firstName = "Not Found"; empty.lastName = "";
        return empty;
    }
};

customerLinkedList<customer> customers;

struct dress {
    int    ID;
    double price;
    string size;
    int    stock;

    bool operator==(const dress& o) const { return ID == o.ID; }

    friend ostream& operator<<(ostream& os, const dress& d) {
        os << "Dress ID: "          << d.ID    << endl
           << "Price in L.E: "      << d.price << endl
           << "Size: "              << d.size  << endl
           << "Available in stock: "<< d.stock << endl;
        return os;
    }
};

arrayListType<dress> store_dresses(100);

struct rentals {
    int    customer_ID;
    int    dress_ID;
    double price;

    bool operator==(const rentals& o) const {
        return (customer_ID == o.customer_ID && dress_ID == o.dress_ID);
    }

    friend ostream& operator<<(ostream& os, const rentals& r) {
        os << "Customer ID: " << r.customer_ID << endl
           << "Dress ID: "    << r.dress_ID    << endl
           << "Price: "       << r.price       << endl;
        return os;
    }
};

arrayListType<rentals> rented(500);

// ═══════════════════════════════════════════════════════════════════════════════
// FUNCTIONS
// ═══════════════════════════════════════════════════════════════════════════════

// FIX: updateCustomer now takes an ID so it actually updates the right customer
void updateCustomer(int id = -1) {
    customer c1;
    if (id == -1) {
        cout << "Enter Customer ID to update: ";
        cin >> c1.ID;
    } else {
        c1.ID = id;
    }
    cout << "First Name: ";  cin >> c1.firstName;
    cout << "Last Name: ";   cin >> c1.lastName;
    customers.deleteNode(c1);
    customers.insertFirst(c1);
    cout << "Customer updated successfully." << endl;
}

void insertCustomer() {
    customer new_customer;
    cout << "Enter Customer ID: ";    cin >> new_customer.ID;
    cout << "First Name: ";           cin >> new_customer.firstName;
    cout << "Last Name: ";            cin >> new_customer.lastName;

    if (customers.search(new_customer)) {
        cout << "Customer already exists. Update instead? (y/n): ";
        char answer; cin >> answer;
        if (answer == 'y' || answer == 'Y')
            updateCustomer(new_customer.ID);
    } else {
        customers.insertFirst(new_customer);
        cout << "Customer added successfully." << endl;
    }
}

void deleteCustomer() {
    customer c;
    cout << "Enter Customer ID to delete: "; cin >> c.ID;
    if (customers.search(c)) {
        customers.deleteNode(c);
        cout << "Customer deleted successfully." << endl;
    } else
        cout << "Customer not found." << endl;
}

void print_customers() {
    cout << "Number of customers: " << customers.length() << endl;
    customers.print();
}

void get_customerInfo() {
    customer c;
    cout << "Enter Customer ID: "; cin >> c.ID;
    if (customers.search(c))
        cout << customers.get_customer(c.ID) << endl;
    else
        cout << "Customer does not exist." << endl;
}

void insert_dress() {
    dress d;
    cout << "Dress ID: ";                   cin >> d.ID;
    cout << "Price: ";                      cin >> d.price;
    cout << "Size (small/medium/large): ";  cin >> d.size;
    cout << "Available stock: ";            cin >> d.stock;
    store_dresses.insert(d);
    cout << "Dress added successfully." << endl;
}

void remove_dress() {
    dress d;
    cout << "Enter Dress ID to remove: "; cin >> d.ID;
    store_dresses.remove(d);
    cout << "Operation completed." << endl;
}

// FIX: seqSearch returns int, compare with != -1
void update_dress() {
    dress d;
    cout << "Enter Dress ID to update: "; cin >> d.ID;
    int loc = store_dresses.seqSearch(d);   // FIX: was used as bool
    if (loc != -1) {
        store_dresses.retrieveAt(loc, d);
        cout << "Dress found. Update the following:\n";
        cout << "Price: ";                      cin >> d.price;
        cout << "Size (small/medium/large): ";  cin >> d.size;
        cout << "Available stock: ";            cin >> d.stock;
        store_dresses.replaceAt(loc, d);
        cout << "Dress updated successfully." << endl;
    } else
        cout << "Dress not found." << endl;
}

void printDresses() {
    cout << "Number of dresses: " << store_dresses.listSize() << endl;
    store_dresses.print();
}

bool rented_maximum_5(const customer& renter) {
    int count = 0;
    for (int i = 0; i < rented.listSize(); i++) {
        rentals temp;
        rented.retrieveAt(i, temp);
        if (temp.customer_ID == renter.ID)
            count++;
    }
    return (count >= 5);
}

void add_dress_to_customer() {
    customer renter;
    cout << "Enter Customer ID: "; cin >> renter.ID;

    if (!customers.search(renter)) {
        cout << "Customer does not exist." << endl;
        return;
    }
    if (rented_maximum_5(renter)) {
        cout << "Customer has reached the maximum of 5 rentals." << endl;
        return;
    }

    char answer;
    do {
        dress d;
        cout << "Dress ID: "; cin >> d.ID;
        int loc = store_dresses.seqSearch(d);
        if (loc != -1) {
            store_dresses.retrieveAt(loc, d);
            if (d.stock <= 0) {
                cout << "Dress is out of stock." << endl;
            } else {
                rentals r;
                r.customer_ID = renter.ID;
                r.dress_ID    = d.ID;
                r.price       = d.price;
                rented.insertEnd(r);
                d.stock--;
                store_dresses.replaceAt(loc, d);
                cout << "Dress rented successfully." << endl;
            }
        } else
            cout << "Dress does not exist." << endl;

        cout << "Add another dress? (y/n): "; cin >> answer;
    } while ((answer == 'y' || answer == 'Y') && !rented_maximum_5(renter));
}

void remove_dress_from_customer() {
    rentals r;
    cout << "Enter Customer ID: "; cin >> r.customer_ID;
    cout << "Enter Dress ID: ";    cin >> r.dress_ID;

    // find the rental
    bool found = false;
    for (int i = 0; i < rented.listSize(); i++) {
        rentals temp;
        rented.retrieveAt(i, temp);
        if (temp.customer_ID == r.customer_ID && temp.dress_ID == r.dress_ID) {
            rented.removeAt(i);
            found = true;
            break;
        }
    }

    if (found) {
        // return dress to stock
        dress d;
        d.ID = r.dress_ID;
        int dloc = store_dresses.seqSearch(d);
        if (dloc != -1) {
            store_dresses.retrieveAt(dloc, d);
            d.stock++;
            store_dresses.replaceAt(dloc, d);
        }
        cout << "Dress returned successfully." << endl;
    } else
        cout << "Rental not found." << endl;
}

// FIX: was an infinite loop — loc never updated inside the while
void calculate_bill() {
    rentals temp;
    int customer_id;
    double bill = 0;
    cout << "Enter Customer ID: "; cin >> customer_id;

    for (int i = 0; i < rented.listSize(); i++) {
        rented.retrieveAt(i, temp);
        if (temp.customer_ID == customer_id)
            bill += temp.price;
    }

    cout << "Total Amount: L.E " << bill << endl;
}

void get_customerRentals() {
    customer c;
    cout << "Enter Customer ID: "; cin >> c.ID;
    if (!customers.search(c)) {
        cout << "Customer does not exist." << endl;
        return;
    }
    cout << customers.get_customer(c.ID) << endl;
    int count = 0;
    for (int i = 0; i < rented.listSize(); i++) {
        rentals temp;
        rented.retrieveAt(i, temp);
        if (temp.customer_ID == c.ID) {
            count++;
            cout << "Rented Dress #" << count
                 << " | ID: " << temp.dress_ID
                 << " | Price: L.E " << temp.price << endl;
        }
    }
    if (count == 0)
        cout << "No rentals found for this customer." << endl;
}

void calculate_profit_ofDay() {
    double total = 0;
    rentals temp;
    for (int i = 0; i < rented.listSize(); i++) {
        rented.retrieveAt(i, temp);
        total += temp.price;
    }
    cout << "Today's total profit: L.E " << total << endl;
}

// ═══════════════════════════════════════════════════════════════════════════════
// MAIN  (FIX: void main → int main)
// ═══════════════════════════════════════════════════════════════════════════════

int main() {
    cout << "\n     WELCOME TO DRESS RENTAL MANAGEMENT SYSTEM\n";
    cout << "     ==========================================\n\n";

    char answer2 = 'y';
    while (answer2 == 'y' || answer2 == 'Y') {
        char choice;
        cout << "\nChoose system to access (a/b/c):\n";
        cout << "  a. Customer Operations\n";
        cout << "  b. Dress Operations\n";
        cout << "  c. Rental Operations\n> ";
        cin >> choice;

        char answer = 'y';

        if (choice == 'a') {
            while (answer == 'y' || answer == 'Y') {
                int choose;
                cout << "\nCustomer Operations:\n";
                cout << "1. Insert Customer\n2. Remove Customer\n3. Update Customer\n"
                     << "4. Display All Customers\n5. Display a Certain Customer\n> ";
                cin >> choose;
                switch (choose) {
                    case 1: insertCustomer();  break;
                    case 2: deleteCustomer();  break;
                    case 3: updateCustomer();  break;   // FIX: no longer prints "Invalid" after valid op
                    case 4: print_customers(); break;
                    case 5: get_customerInfo(); break;  // FIX: added missing break
                    default: cout << "Invalid operation." << endl;
                }
                cout << "\nAnother customer operation? (y/n): "; cin >> answer;
            }
        }
        else if (choice == 'b') {
            while (answer == 'y' || answer == 'Y') {
                int choose;
                cout << "\nDress Operations:\n";
                cout << "1. Add Dress to Stock\n2. Remove Dress from Stock\n"
                     << "3. Update Dress Info\n4. Display All Dresses\n> ";
                cin >> choose;
                switch (choose) {
                    case 1: insert_dress(); break;
                    case 2: remove_dress(); break;
                    case 3: update_dress(); break;
                    case 4: printDresses(); break;
                    default: cout << "Invalid operation." << endl;
                }
                cout << "\nAnother dress operation? (y/n): "; cin >> answer;
            }
        }
        else if (choice == 'c') {
            while (answer == 'y' || answer == 'Y') {
                int choose;
                cout << "\nRental Operations:\n";
                cout << "1. Customer Renting a Dress\n2. Customer Returning a Dress\n"
                     << "3. Display a Customer's Rentals\n4. Calculate a Customer's Bill\n"
                     << "5. Calculate Today's Store Profit\n> ";
                cin >> choose;
                switch (choose) {
                    case 1: add_dress_to_customer();      break;
                    case 2: remove_dress_from_customer(); break;
                    case 3: get_customerRentals();        break;
                    case 4: calculate_bill();             break;
                    case 5: calculate_profit_ofDay();     break;
                    default: cout << "Invalid operation." << endl;
                }
                cout << "\nAnother rental operation? (y/n): "; cin >> answer;
            }
        }
        else
            cout << "Invalid choice." << endl;

        cout << "\nWould you like to do another operation? (y/n): ";
        cin >> answer2;
    }

    return 0;
}
