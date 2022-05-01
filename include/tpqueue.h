// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
private:
    struct ITEM {
        T value;
        ITEM* next, * prev;
    };
    ITEM* head, * tail;
    TPQueue::ITEM* create(const T& value) {
        ITEM* item = new ITEM;
        item->value = value;
        item->next = item->prev = nullptr;
        return item;
    }

public:
    TPQueue() : head(nullptr), tail(nullptr) {}
    void push(const T& value) {
        ITEM* t = head;
        ITEM* item = create(value);
        while (t && t->value.prior >= value.prior)
            t = t->next;
        if (!t && !head) {
            head = tail = item;
        }
        else if (!t && head) {
            tail->next = item;
            item->prev = tail;
            tail = item;
        }
        else if (!t->prev) {
            item->next = head;
            head->prev = item;
            head = item;
        }
        else {
            t->prev->next = item;
            item->prev = t->prev;
            t->prev = item;
            item->next = t;
        }
    }
    T pop() {
        ITEM* t = head->next;
        if (t)
            t->prev = nullptr;
        T value = head->value;
        delete head;
        head = t;
        if (!head)
            tail = nullptr;
        return value;
    }
};

struct SYM {
    char ch;
    int prior;
};

#endif
