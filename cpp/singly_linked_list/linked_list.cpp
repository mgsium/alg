// Example program
#include <iostream>
#include <string>
#include <list>

template <class T>
class Node {
private:
    T data;
    Node<T>* head;
public:
    Node(T data) : data(data), head(NULL) {};
    Node(T data, Node* head) : data(data), head(head) {};
    T get_data() { return this->data; };
    void set_head(Node<T>* head) { this->head = head; };
    Node<T>* get_head() { return this->head; };
};

template <class T>
class LinkedList {
private:
    Node<T>* start;
public:
    LinkedList(Node<T>* node) : start(node) {};
    LinkedList() : start(NULL) {};

    int size() {
        if (this->start == NULL) return 0;
        else {
            int size = 0;
            Node<T>* nextNode = this->start;
            while (nextNode != NULL) {
                size++;
                nextNode = nextNode->get_head();
            }
            return size;
        }
    };

    void add(Node<T>* newNode) {
        for (Node<T>* node = this->start; node; ++node) {
            if (node->get_head() == NULL) {
                node->set_head(newNode);
                break;
            }
        }
    };

    void addFirst(Node<T>* newNode) {
        newNode->set_head(this->start);
        (this->start)--;
        this->start = newNode;
    }

    T first() { return this->start->get_data(); };
    T last() {
        for (Node<T>* node = this->start; node; node++) {
            if (node->get_head() == NULL) {
                return node->get_data();
            }
        }
    }

    Node<T>* get_start() { return this->start; };
};

int main()
{
    Node<int> n(4);
    Node<int> n2(5);
    Node<int> n3(3);

    LinkedList<int> ll(&n);
    printf("Size: %d\n", ll.size());
    ll.add(&n2);
    printf("Size: %d\n", ll.size());
    ll.addFirst(&n3);
    printf("Size: %d\n", ll.size());
    printf("First Value: %d\n", ll.first());
    printf("Last Value: %d\n", ll.last());

    for (Node<int>* node = ll.get_start(); node->get_head(); node++) {
        printf("This: %p and %d\n", node, node->get_data());
    }
    
    // printf("Memory address %p stores the value %x\n", n.head, *(n.head));
    
    return 0;
}