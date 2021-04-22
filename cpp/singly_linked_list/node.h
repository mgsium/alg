#pragma once

template <class T>
class DNode {
private:
    T data;
    T* foot;
    T* head;
public:
    DNode(T data) : data(data), foot(NULL), head(NULL) {};
    DNode(DNode* foot, T data) : data(data), foot(foot), head(NULL) {};
    DNode(T data, DNode* head) : data(data), foot(NULL), head(head) {};
    DNode(DNode* foot, T data, DNode* head) : data(data), foot(foot), head(head) {};
    ~DNode() { printf("Node at address %p removed.", &(this->data)); }
    void set_head(DNode* head) { this->head = head; }
    DNode* get_head() { return this->head; }
    void set_foot(DNode* foot) { this->foot = foot; }
    DNode* get_foot() { return this->foot; }
    void set_data(T data) { this->data = data; }
    T get_data() { return this->data; }
};

template <class T>
class DLinkList {
private:
    std::list<DNode<T>> nodes;
    DNode<T>* get_first() {
        return this->nodes.back();
    }
    DNode<T>* get_last() {
        int size = nodes.size();
        return &((this->nodes)[size - 1]);
    };
public:
    DLinkList() { puts("Doubly Linked List Initialized!"); };
    void add(T val) {
        DNode<T>* last_node = this->get_last();
        DNode<T> node(&last_node, val, NULL);
        (this->nodes).push_back(node);
    };
    T pop() {
        DNode* last_node = this->get_last();
        DNode* penul_node = last_node->get_foot();
        penul_node->set_head(NULL);
        int val = last_node->get_data();
        (this->node).pop();
        return val;
    };
    void add_first(T val) {
        DNode<T>* first_node_ptr = this->get_first();
        DNode node(val, first_node_ptr);
        first_node_ptr->set_foot(&node);
        (this->nodes).push_front(node);
    }
    T pop_first() {
        DNode<T>* first_node_ptr = this->get_first();
        DNode<T>* sec_node_ptr = first_node_ptr.get_head();
        sec_node_ptr.set_foot(NULL);
        int val = first_node_ptr->get_data();
        (this->nodes).pop_front();
        return val;
    }
};