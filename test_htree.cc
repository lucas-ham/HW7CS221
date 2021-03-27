/*
 * test_tree: A simple unit test for the Tree data structure.
 */

#include "htree.hh"
#include <cassert>

#include <iostream>

using namespace std;

// Create an elaborate example test tree:
HTree::tree_ptr_t create_test_tree()
{
  return
    make_shared<HTree>(126, 1,
		make_shared<HTree>(50, 1,
			make_shared<HTree>(30, 1, nullptr, 
				make_shared<HTree>(50, 1)
				),
			make_shared<HTree>(20, 1,
				make_shared<HTree>(40, 1,
					make_shared<HTree>(10, 1),
					make_shared<HTree>(5, 1)
					),
				make_shared<HTree>(80, 1,
					make_shared<HTree>(126, 1),
					make_shared<HTree>(40, 1)
					)
				)
		    )
		);
}

void test_htree(const HTree::tree_ptr_t root)
{
  assert(*(root->path_to(126)) == HTree::path_t({ }));
  assert((root->get_child(HTree::Direction::LEFT))->get_key()  == 50);
}

int main()
{
  auto root = create_test_tree();
  test_htree(root);

  return 0;
}
