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

    void print() {
        Node* curr = head;
        while (curr) {
            std::cout << curr->data << " -> ";
            curr = curr->next;
        }
        std::cout << "NULL\n";
    }

    T get(int index) {
        Node* curr = head;
        for (int i = 0; curr && i < index; ++i) {
            curr = curr->next;
        }
        if (!curr) throw std::out_of_range("Index out of range");
        return curr->data;
    }

    bool find(T data) {
        Node* curr = head;
        while (curr) {
            if (curr->data == data) return true;
            curr = curr->next;
        }
        return false;
    }

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

private:
    struct Node {
        T data;
        Node* next;
    };
    Node* head;
};

// ==========================
// Static Linked List
// ==========================
template <typename T, int SIZE>
class StaticList {
public:
    StaticList() : head(-1), free_index(0) {
        for (int i = 0; i < SIZE - 1; ++i) {
            nodes[i].next = i + 1;
        }
        nodes[SIZE - 1].next = -1;
    }

    void insert(T data) {
        if (free_index == -1) {
            std::cout << "No more space to insert.\n";
            return;
        }
        int new_idx = allocate_node();
        nodes[new_idx].data = data;
        nodes[new_idx].next = -1;

        if (head == -1) {
            head = new_idx;
        } else {
            int curr = head;
            while (nodes[curr].next != -1) {
                curr = nodes[curr].next;
            }
            nodes[curr].next = new_idx;
        }
    }

    void print() {
        int curr = head;
        while (curr != -1) {
            std::cout << nodes[curr].data << " -> ";
            curr = nodes[curr].next;
        }
        std::cout << "NULL\n";
    }

private:
    struct Node {
        T data;
        int next;
    };
    Node nodes[SIZE];
    int head;
    int free_index;

    int allocate_node() {
        if (free_index == -1) return -1;
        int idx = free_index;
        free_index = nodes[free_index].next;
        return idx;
    }
};

// ==========================
// Main Testing
// ==========================
int main() {
    std::cout << "Testing Dynamic Linked List:\n";
    DynamicList<int> dyn_list;
    dyn_list.insert(10);
    dyn_list.insert(20);
    dyn_list.insert(30);
    dyn_list.print();
    assert(dyn_list.get(0) == 10);
    assert(dyn_list.get(1) == 20);
    assert(dyn_list.find(30) == true);
    dyn_list.update_element(20, 25);
    dyn_list.print();
    dyn_list.delete_element(10);
    dyn_list.print();

    std::cout << "\nTesting Static Linked List:\n";
    StaticList<int, 10> stat_list;
    stat_list.insert(100);
    stat_list.insert(200);
    stat_list.insert(300);
    stat_list.print();

    std::cout << "\nAll tests completed successfully!\n";
    return 0;
