#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

tlate<typename T>
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
        if (!t && head) {
            tail->next = item;
            item->prev = tail;
            tail = item;
        }
        else if (!t && !head) {
            head = tail = item;
        }
        else if (!t->prev) {
            head->prev = item;
            item->next = head;
            head = item;
        }
        else {
            t->prev->next = item;
            item->prev = t->prev;
            item->next = t;
            t->prev = item;
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
