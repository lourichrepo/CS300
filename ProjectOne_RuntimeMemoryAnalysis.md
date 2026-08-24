# Project One Runtime and Memory Analysis

## Runtime Chart

| Data Structure | Total Cost | Runtime |
|---|---|---|
| Vector | n² + 3n + 2 | O(n²) |
| Hash Table | n² | O(n²) |
| Binary Search Tree | n² | O(n²) |

## Advantages and Disadvantages

**Vector:** A vector is simple to use and stores courses together in memory. It can also be sorted to print the courses in alphanumeric order. A disadvantage is that searching can require checking each course, making searches slower as more courses are added.

**Hash Table:** A hash table provides fast searching when the course number is used as the key. Its disadvantage is that the courses are not stored in sorted order, so they have to be copied and sorted before printing the complete course list.

**Binary Search Tree:** A binary search tree allows efficient searching and can print courses in order using an in-order traversal. A disadvantage is that performance can decrease if the tree becomes unbalanced.

Memory use for all three structures grows with the number of courses, or O(n), although hash tables and trees may require additional memory for buckets, nodes, and pointers.

## Recommendation

I would recommend using a binary search tree for the final program. It can search for a course efficiently by comparing course numbers, and it can print the courses in alphanumeric order using an in-order traversal. A vector would need to be searched or sorted, while a hash table would need extra sorting before printing the full course list. Based on the program requirements and overall analysis, the binary search tree is a good choice for the final program.
