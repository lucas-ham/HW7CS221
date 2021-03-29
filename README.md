# Can't see the forest for the trees

## Lucas Hamilton and Harrison Nicholls

In order to build our program, just run `make` in our project's directory. `make test` will run our tests. We have separate test code for htree and hforest. `make testT` will test only htree, and `make testF` will test only hforest.

For **htree.cc**,
`get_child` and `path_to` were the only non-trivial functions. For `get_child`, we simply used a `switch` statement to return the appropriate value. For `path_to`, we recursively checked each child node and pushed either RIGHT or LEFT into the `possible_path_t` list.

For **hforest.cc**, `add_tree` adds a tree to the vector representing our forest, and then calls `std::makeheap` on it.
`pop_tree` returns a tree pointer to what was at the 0th position of our forest vector, and then calls `std::pop_heap`, which is a standard function that removes the top element and remakes the heap.

**test_htree** constructs a tree of depth 4, and makes several checks:

- It checks that the paths returned by `path_to` of a few nodes are correct. This includes testing a node that is not in the constructed tree, and the root node.
- It also tests `get_child` on a deep path and a simple path, which we then run the `get_key` method on to verify the result.
- Finally, it tests `get_value` on two nodes - one deeper than the other

**test_hforest** constructs a forest with 4 trees, and then performs the following tests:

- It checks that the size of the forest is 4
- It tests `pop_tree` by popping a tree and checking its key
- It checks the size is now 1 smaller after calling `pop_tree`
- It tests `pop_tree` a second time
- It pops the two remaining values, and checks that the size is now 0 and pop returns a nullptr
