#include "linkedlist.h"

#include <iostream>
#include <limits>
#include <vector>

// Returns the number of ORIGINAL matches, never processing elements it inserts.
int insertAfter(int first, int second, std::vector<int>& values) {
    int matches = 0;
    for (std::size_t i = 0; i < values.size(); ++i) {
        if (values[i] == first) {
            values.insert(values.begin() + static_cast<std::ptrdiff_t>(i + 1), second);
            ++matches;
            ++i; // Skip the new element; this matters when first == second.
        }
    }
    return matches;
}

Linkedlist new_linkedlist(const std::vector<int>& values) {
    Linkedlist list;
    for (int value : values) list.Vector_to_linkedlist(new Node(value));
    return list;
}

int main() {
    int count;
    std::cout << "Enter the number of integers: ";
    if (!(std::cin >> count) || count < 0 || count > 100000) {
        std::cerr << "Expected a count between 0 and 100000.\n";
        return 1;
    }
    std::vector<int> values;
    values.reserve(static_cast<std::size_t>(count));
    for (int i = 0, value; i < count; ++i) {
        std::cout << "Enter integer " << i + 1 << ": ";
        if (!(std::cin >> value)) {
            std::cerr << "Expected an integer.\n";
            return 1;
        }
        values.push_back(value);
    }

    int target, inserted;
    std::cout << "Insert after which integer? ";
    if (!(std::cin >> target)) return 1;
    std::cout << "Which integer should be inserted? ";
    if (!(std::cin >> inserted)) return 1;
    const int matches = insertAfter(target, inserted, values);
    std::cout << target << " occurred " << matches << " times in the original vector.\n";
    std::cout << "Vector after insertion:\n";
    for (int value : values) std::cout << value << '\n';

    Linkedlist list = new_linkedlist(values);
    std::cout << "Linked list:\n";
    list.printList();
    std::cout << "Sum of distinct node values = " << list.SUMofALLnodes() << '\n';
    std::cout << "Enter the node value to remove: ";
    if (!(std::cin >> target)) return 1;
    if (!list.deleteNode(target)) std::cout << "Value not found.\n";
    list.printList();
    std::cout << "Sum of distinct node values = " << list.SUMofALLnodes() << '\n';
    return 0;
}
