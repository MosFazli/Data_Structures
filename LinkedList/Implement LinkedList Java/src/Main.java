// Main function for testing out LinkedList implementation
public class Main {
    // Main function, as allways
    public static void main(String[] args){
        // Create a new LinkedList
        LinkedList linkedList = new LinkedList();

        // Add some nodes to the end of linked list
        linkedList.append(2);
        linkedList.append(3);
        linkedList.append(4);

        // add some nodes to first of linked list
        linkedList.prepend(5);
        linkedList.prepend(12);

        // Remove a node
        linkedList.deleteWithValue(3);

        // And Print our LinkedList
        linkedList.printElements();


    }
}