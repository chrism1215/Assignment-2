#include <iostream>
#include <cassert>

// ==========================
// Dynamic Linked List
// ==========================
template <typename T>
class DynamicList {
public:
    DynamicList() : head(nullptr) {}

    ~DynamicList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Insert at the tail of the list
    void insert(T data) {
        Node* new_node = new Node{data, nullptr};
        if (!head) {
            head = new_node;
            return;
        }
        Node* curr = head;
        while (curr->next) curr = curr->next;
        curr->next = new_node;
    }

    // Insert at a specific index
    void insert_at_index(int index, T data) {
        Node* new_node = new Node{data, nullptr};
        if (index == 0) {
            new_node->next = head;
            head = new_node;
            return;
        }
        Node* curr = head;
        for (int i = 0; curr && i < index - 1; ++i) {
            curr = curr->next;
        }
        if (!curr) {
            delete new_node;
            throw std::out_of_range("Index out of range");
        }
        new_node->next = curr->next;
        curr->next = new_node;
    }

    // Print the list
    void print() {
        Node* curr = head;
        while (curr) {
            std::cout << curr->data << " -> ";
            curr = curr->next;
        }
        std::cout << "NULL\n";
    }

    // Get value at index
    T get(int index) {
        Node* curr = head;
        for (int i = 0; curr && i < index; ++i) {
            curr = curr->next;
        }
        if (!curr) throw std::out_of_range("Index out of range");
        return curr->data;
    }

    // Find a value in the list
    bool find(T data) {
        Node* curr = head;
        while (curr) {
            if (curr->data == data) return true;
            curr = curr->next;
        }
        return false;
    }

    // Update first occurrence of an element
    bool update_element(T old_data, T new_data) {
        Node* curr = head;
        while (curr) {
            if (curr->data == old_data) {
                curr->data = new_data;
                return true;
            }
            curr = curr->next;
        }
        return false;
    }

    // Update element at specific index
    bool update_element_at_index(int index, T data) {
        Node* curr = head;
        for (int i = 0; curr && i < index; ++i) {
            curr = curr->next;
        }
        if (!curr) return false;
        curr->data = data;
        return true;
    }

    // Delete by value
    bool delete_element(T data) {
        if (!head) return false;
        if (head->data == data) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return true;
        }
        Node* curr = head;
        while (curr->next && curr->next->data != data) {
            curr = curr->next;
        }
        if (!curr->next) return false;
        Node* temp = curr->next;
        curr->next = curr->next->next;
        delete temp;
        return true;
    }

    // Delete by index
    bool delete_at_index(int index) {
        if (!head) return false;
        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return true;
        }
        Node* curr = head;
        for (int i = 0; curr->next && i < index - 1; ++i) {
            curr = curr->next;
        }
        if (!curr->next) return false;
        Node* temp = curr->next;
        curr->next = curr->next->next;
        delete temp;
        return true;
    }

private:
    struct Node {
        T data;
        Node* next;
    };
    Node* head;
};

// ==========================
// Main Testing
// ==========================
int main() {
    DynamicList<int> dyn_list;

    // Testing insert
    dyn_list.insert(10);
    dyn_list.insert(20);
    dyn_list.insert(30);
    dyn_list.print();

    // Testing insert_at_index
    dyn_list.insert_at_index(1, 15); // Insert 15 at index 1
    dyn_list.print();

    // Testing get
    assert(dyn_list.get(0) == 10);
    assert(dyn_list.get(1) == 15);

    // Testing find
    assert(dyn_list.find(30) == true);

    // Testing update_element
    dyn_list.update_element(20, 25);
    dyn_list.print();

    // Testing update_element_at_index
    assert(dyn_list.update_element_at_index(2, 27) == true);
    dyn_list.print();

    // Testing delete_element
    dyn_list.delete_element(10);
    dyn_list.print();

    // Testing delete_at_index
    dyn_list.delete_at_index(1);
    dyn_list.print();

    std::cout << "\nAll tests completed successfully!\n";
    return 0;
}
