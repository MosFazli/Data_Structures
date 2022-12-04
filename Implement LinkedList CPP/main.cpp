/* Implementaion of LinkedList with CPP */

// Include libraries
#include <iostream>

using namespace std;

// Create Node class with data and next pointer
class Node {
    // Make all variables public for accessibility
public:
    int data;
    Node *next;

    // Constructor of Node
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// Create a LinkedList that using Node class
class LinkedList {
    // Each LinkedList at least contains a head node
    Node *head;

    // Define public variables and functions for accessibility
public:
    // Constructor of LinkedList
    LinkedList() { head = nullptr; }

    // Functions of LinkedList
    void append(int);

    void prepend(int);

    void deleteWithValue(int);

    void print();

};

/* Define append function, add a new node in the end of LinkedList, this function gets a data which
using in node */
void LinkedList::append(int data) {
    // Check if linkedList is empty, append a new node and make it head and return
    if (head == nullptr) {
        Node *newNode = new Node(data);
        head = newNode;
        return;
    }

    /* Else, if we have at least one node in linkedList, we should iteration of the linkedList for finding
        last node */
    Node *newNode = head;
    while (newNode->next != nullptr) {
        newNode = newNode->next;
    }
    // When we find last node, that means newNode equal to last node and create a newNode after that
    newNode->next = new Node(data);
}

// Prepend function for add a new node to first of LinkedList, it's gets data of node type
void LinkedList::prepend(int data) {
    // Add a newNode and set head in next of that, after just swap them
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

// DeleteWithValue function for Delete element from linkedList with value
void LinkedList::deleteWithValue(int data) {
    // We have 3 Situation, first we have empty linkedList, just return
    if (head == nullptr) {
        return;
    }

    // Second we find that in first node, just skip that
    if (head->data == data) {
        head = head->next;
        return;
    }

    // Third, add a new node, iteration of the linkedList and remove it from linkedList by skipping
    Node *newNode = head;
    while (newNode->next != nullptr) {
        if (newNode->next->data == data) {
            newNode->next = newNode->next->next;
            return;
        }
        newNode = newNode->next;
    }
}

// Print function for show elements of LinkedList
void LinkedList::print() {

    // If linkedList is empty, just return
    if (head == nullptr) {
        return;
    }

    // Else, iteration of the linkedList and print elements
    Node *newNode = head;
    while (newNode->next != nullptr) {
        cout << newNode->data << " -> ";
        newNode = newNode->next;
    }
    cout << newNode->data;
}

// Maint function for testing our LinkedList
int main() {
    // Create a instance of LinkedList
    LinkedList linkedList;

    // Add some elements to end of the linkedList
    linkedList.append(5);
    linkedList.append(10);
    linkedList.append(15);
    linkedList.append(25);

    // Add some elements to first of the linkedList
    linkedList.prepend(1);
    linkedList.prepend(3);
    linkedList.prepend(4);
    linkedList.prepend(2);

    // remove some elements of the linkedList
    linkedList.deleteWithValue(5);
    linkedList.deleteWithValue(4);

    // Print the linkedList
    linkedList.print();
}