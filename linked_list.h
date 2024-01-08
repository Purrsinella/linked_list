#ifndef LINKED_LIST_LINKED_LIST_H
#define LINKED_LIST_LINKED_LIST_H

#include <iostream>

template<typename T>
class linked_list {
    struct Node {
        T data;
        Node *next;

        Node() : data(0), next(nullptr) {}

        Node(T val, Node *tempNext = nullptr) : data(val), next(tempNext) {}

        Node &operator=(const typename linked_list<T>::Node &nd);
    };

private:
    Node *head;
public:
    linked_list();

    ~linked_list();

    int size();

    bool isEmpty();

    void push_back(T val);

    void push_front(T val);

    T front();

    T operator[](int idx);

    void del_front();

    void del_idx(int idx);

    void display(std::ostream &os);
};

template<typename T>
typename linked_list<T>::Node &linked_list<T>::Node::operator=(const typename linked_list<T>::Node &nd) {
    if (this == &nd)
        return *this;

    delete data;
    data = new T(nd.data);

    return *this;
}

template<typename T>
linked_list<T>::linked_list() : head() {}

template<typename T>
linked_list<T>::~linked_list() {
    Node *temp = head;
    Node *tn;
    while (temp != nullptr) {
        tn = temp->next;
        delete temp;
        temp = tn;
    }
}

template<typename T>
int linked_list<T>::size() {
    if (head == nullptr)
        return 0;
    int ct = 0;
    Node *temp = head;
    while (temp != nullptr) {
        ++ct;
        temp = temp->next;
    }

    return ct;
}

template<typename T>
bool linked_list<T>::isEmpty() {
    return head == nullptr;
}

template<typename T>
void linked_list<T>::push_back(T val) {
    Node *temp = new Node(val);
    temp->next = nullptr;

    if (head == nullptr)
        head = temp;

    else {
        Node *temp_h = head;
        while (temp_h->next != nullptr)
            temp_h = temp_h->next;

        temp_h->next = temp;
    }
}

template<typename T>
void linked_list<T>::push_front(T val) {
    Node *temp = new Node(val);

    temp->next = head;

    head = temp;
}

template<typename T>
T linked_list<T>::front() {
    if (head == nullptr) {
        throw std::range_error("No head.\n");
    }

    T *temp = new T(head->data);
    return *temp;
}

template<typename T>
T linked_list<T>::operator[](int idx) {
    if (this->size() < idx) {
        throw std::range_error("Index is bigger than size of list.\n");
    }

    Node *temp = head;
    for (int i = 0; i != idx; ++i)
        temp = temp->next;

    T *ret_val = new T(temp->data);
    return *ret_val;
}

template<typename T>
void linked_list<T>::del_front() {
    if (head == nullptr) {
        throw std::range_error("No front element to delete.\n");
    }

    del_idx(0);
}

template<typename T>
void linked_list<T>::del_idx(int idx) {
    if (this->size() < idx) {
        throw std::range_error("Index is bigger than size of list. Failed to delete object\n");
    }
//
//    if(idx == 0)
//    {
//        Node *temp = head->next;
//        delete head;
//        head = temp;
//        return;
//    }

    Node *prev = nullptr;
    Node *temp = head;

    for (int i = 0; i < idx; ++i)
    {
        prev = temp;
        temp = temp->next;
    }

    Node* next = temp->next;
    delete temp;

    if(prev == nullptr)
    {
        head = next;
        return;
    }

    head->next = next;

}

template<typename T>
void linked_list<T>::display(std::ostream &os) {
    Node *temp = head;
    while (temp != nullptr) {
        os << temp->data << " ";
        temp = temp->next;
    }
    os << std::endl;
}

#endif //LINKED_LIST_LINKED_LIST_H
