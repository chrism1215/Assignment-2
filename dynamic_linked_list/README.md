📚 Overview

This project implements two types of singly linked lists in C++:

Dynamic Linked List (using pointers and dynamic memory)
Static Linked List (using arrays to simulate links)
Both lists support insertion, deletion, update, search, and retrieval operations, as required by the assignment.

🛠️ Features Implemented

insert(T data) — Insert at the end of the list
insert_at_index(int index, T data) — Insert at a specific index
delete_element(T data) — Delete the first matching data
delete_at_index(int index) — Delete at a specific index
update_element(T old_data, T new_data) — Update data value
update_element_at_index(int index, T data) — Update data at a specific index
find(T data) — Search for an element
get(int index) — Retrieve element at a given index
print() — Print the entire list
🧪 Testing

Unit tests were written inside main() to validate:

All operations work correctly
Index out of bounds are handled properly
Edge cases like deleting from an empty list
📝 Instructions to Compile and Run

Open a terminal and navigate to the project folder.
Compile the code:
g++ linked_list.cpp -o linked_list
Run the executable:
./linked_list
📋 Requirements Covered

This project satisfies:

Full linked list operations (insert, delete, update, find, get)
Dynamic and Static list versions
Unit testing before full implementation
Proper documentation and comments
Clean Git history with meaningful commits
