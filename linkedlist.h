#ifndef ASSIGN4_LINKEDLIST_H
#define ASSIGN4_LINKEDLIST_H

#include <cstddef>
#include <iostream>
#include <utility>

// One node per distinct value; occer records how many input elements it represents.
struct Node {
    int da;
    int occer = 1;
    Node* sec = nullptr;

    explicit Node(int value) : da(value) {}
};

class Linkedlist {
public:
    Linkedlist() = default;
    ~Linkedlist() { clear(); }

    Linkedlist(const Linkedlist&) = delete;
    Linkedlist& operator=(const Linkedlist&) = delete;

    Linkedlist(Linkedlist&& other) noexcept : start_(std::exchange(other.start_, nullptr)) {}
    Linkedlist& operator=(Linkedlist&& other) noexcept {
        if (this != &other) {
            clear();
            start_ = std::exchange(other.start_, nullptr);
        }
        return *this;
    }

    // Takes ownership of N. Repeated values increase occer rather than add nodes.
    void Vector_to_linkedlist(Node* N) {
        if (!N) return;
        N->sec = nullptr;
        for (Node* current = start_; current; current = current->sec) {
            if (current->da == N->da) {
                ++current->occer;
                delete N;
                return;
            }
        }
        Add(N);
    }

    // Takes ownership of N. Prefer Vector_to_linkedlist for deduplication.
    void Add(Node* N) {
        if (!N) return;
        N->sec = nullptr;
        if (!start_) {
            start_ = N;
            return;
        }
        Node* tail = start_;
        while (tail->sec) tail = tail->sec;
        tail->sec = N;
    }

    // Removes the first node with this value. Returns whether one was found.
    bool deleteNode(int value) {
        Node** link = &start_;
        while (*link && (*link)->da != value) link = &(*link)->sec;
        if (!*link) return false;
        Node* victim = *link;
        *link = victim->sec;
        delete victim;
        return true;
    }

    // Sums distinct node values, NOT value * frequency (original assignment semantics).
    long long SUMofALLnodes() const {
        long long sum = 0;
        for (const Node* node = start_; node; node = node->sec) sum += node->da;
        return sum;
    }

    int occurrences(int value) const {
        for (const Node* node = start_; node; node = node->sec)
            if (node->da == value) return node->occer;
        return 0;
    }

    std::size_t distinctValues() const {
        std::size_t result = 0;
        for (const Node* node = start_; node; node = node->sec) ++result;
        return result;
    }

    void printList(std::ostream& out = std::cout) const {
        if (!start_) {
            out << "List empty\n";
            return;
        }
        for (const Node* node = start_; node; node = node->sec)
            out << node->da << " it occurred " << node->occer << " times\n";
        out << '\n';
    }

private:
    Node* start_ = nullptr;

    void clear() noexcept {
        while (start_) {
            Node* next = start_->sec;
            delete start_;
            start_ = next;
        }
    }
};

#endif
