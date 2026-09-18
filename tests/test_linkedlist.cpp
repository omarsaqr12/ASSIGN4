#define main assign4_interactive_main
#include "../c++.cpp"
#undef main

#include <cassert>
#include <sstream>
#include <type_traits>

int main() {
    std::vector<int> equal{2, 2};
    assert(insertAfter(2, 2, equal) == 2);
    assert((equal == std::vector<int>{2, 2, 2, 2}));
    std::vector<int> different{1, 2, 1};
    assert(insertAfter(1, 3, different) == 2);
    assert((different == std::vector<int>{1, 3, 2, 1, 3}));
    std::vector<int> missing{5};
    assert(insertAfter(4, 4, missing) == 0);
    assert(missing.size() == 1);

    auto list = new_linkedlist(std::vector<int>{1, 2, 1, 3, 2});
    assert(list.distinctValues() == 3);
    assert(list.occurrences(1) == 2 && list.occurrences(2) == 2);
    assert(list.SUMofALLnodes() == 6); // unique values, not occurrence-weighted
    assert(list.deleteNode(1));
    assert(list.occurrences(1) == 0 && list.SUMofALLnodes() == 5);
    assert(!list.deleteNode(99));
    assert(list.deleteNode(2) && list.deleteNode(3));
    assert(list.distinctValues() == 0 && list.SUMofALLnodes() == 0);
    std::ostringstream out;
    list.printList(out);
    assert(out.str() == "List empty\n");

    auto moved = new_linkedlist(std::vector<int>{7, 7});
    Linkedlist other(std::move(moved));
    assert(other.occurrences(7) == 2 && moved.distinctValues() == 0);
    static_assert(!std::is_copy_constructible<Linkedlist>::value);
}
