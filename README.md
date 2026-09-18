# Vector insertion and frequency-counting linked list (C++)

A small C++ data-structures assignment: insert a value after every occurrence of a target in a vector, convert the result to a singly linked list containing **one node per distinct integer**, display each node's occurrence count, sum the distinct node values, and remove a node by value. This is a course exercise, not a general-purpose container library.

## Build and run

Requires a C++17 compiler. From the repository root:

```sh
g++ -std=c++17 -Wall -Wextra -Wpedantic 'c++.cpp' -o assign4
./assign4
```

Example input (one integer per line, or whitespace-separated): `3 1 2 1 1 1 2`. The vector is initially `[1, 2, 1]`; inserting `1` after `1` produces `[1, 1, 2, 1, 1]`. The final `2` requests deletion of the node with value `2`.

## Verify

```sh
g++ -std=c++17 -Wall -Wextra -Wpedantic -fsanitize=address,undefined -fno-omit-frame-pointer -g tests/test_linkedlist.cpp -o /tmp/assign4-tests
/tmp/assign4-tests
```

The tests exercise equal-valued insertion (previously nonterminating), unmatched insertion, frequencies, unique-node summation, deletion of head/middle/missing nodes, empty output, and move ownership. Sanitizers check the exercised paths; this is not a proof of freedom from all defects.

## Repository map and semantics

- [`c++.cpp`](c%2B%2B.cpp): interactive program and original-match insertion algorithm.
- [`linkedlist.h`](linkedlist.h): owning singly linked list. Repeated input values increment the stored frequency; the list owns and frees every supplied `Node*`.
- [`tests/test_linkedlist.cpp`](tests/test_linkedlist.cpp): standalone assertions.
- [`report.docx`](report.docx): original submitted assignment report (retained without edits).

`SUMofALLnodes()` deliberately adds each **distinct node value once**, not `value × occurrences`, matching the original implementation. `deleteNode(value)` deletes that entire distinct-value node. The assignment report has not been reconciled with these semantics. The vector insert routine is educational and uses repeated vector insertion, so it is not optimized for very large inputs. No independent grading or external evaluation is claimed.
