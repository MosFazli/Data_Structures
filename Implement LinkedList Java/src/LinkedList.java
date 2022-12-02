// Implementation of LinkedList with a public class
public class LinkedList {
    // You essentially need to have a head Node
    Node head;

    // You can add end of LinkedList with append method
    public void append(int data){
        // Check if we don't already have a data in linked list, if it's true -> return back to function
        if(head == null){
            head = new Node(data);
            return;
        }

        // Check if we have at least one data in linked list, create a current node to iterative linked list
        Node current = head;
        // Iterative linked list to find last data in linked list
        while (current.next != null){
            current = current.next;
        }
        // Add data to end of linked list
        current.next = new Node(data);
    }

    // Add a data to first of linked list
    public void prepend(int data){
        // Create a new node to change it with head data, set data to newHead and Addressing newHead.next to head
        Node newHead = new Node(data);
        newHead.next = head;
        head = newHead;
    }

    // Remove a Node in linked list with data value
    public void deleteWithValue(int data){
        // Check if head is null to return
        if(head == null){
            return;
        }

        // If head is not null, and equals to 1, check data of input is equals to value of head ?
        if(head.data == data){
            head = head.next;
            return;
        }

        // If we have more two elements, you reach here, use auxiliary variable to iterative linked list and
        // If found a matching node, skip it :)
        Node current = head;
        while(current != null){
            if(current.next.data == data){
                current.next = current.next.next;
                return;
            }
            current = current.next;
        }
    }

// This function using for print all elements of linked list
    public void printElements(){
        // using a auxiliary node to iterative linked list
        Node current = head;
        while (current.next != null){
            // Print all elements of linked list expect last one
            System.out.printf("%d -> ", current.data);
            current = current.next;
        }
        // In the last part, print Last element of linked list
        System.out.printf("%d", current.data);
    }
}
