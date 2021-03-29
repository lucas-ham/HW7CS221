# Can't see the forest for the trees

## Lucas Hamilton and Harrison Nicholls

In order to build our program, just run "make" in our project's directory. "make test" will run our tests. We have a separate test file for hforest and htree.

For htree.cc, 
`get_child` and `path_to` were the only non-trivial functions. For `get_child`, we simply used a `switch` statement to return the appropriate value. For `path_to`, we recursively checked each child node and pushed either RIGHT or LEFT into the `possible_path_t` list.

test_htree constructs a tree of depth 4, and makes several checks:

- It checks that the paths returned by path_to of a few nodes are correct. This includes testing a node that is not in the constructed tree, and the root node.
- It also tests get\_child on a deep path and a simple path, which we then run the get\_key method on to verify the result.
- Finally, it tests get_value on two nodes - one deeper than the other
