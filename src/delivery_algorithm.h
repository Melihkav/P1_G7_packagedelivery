#include "package_distribution.h"

void add_node_to_tree(node_t *new_node, node_t *tree_root);
void a_star(graph_t *graph, node_t start_node, node_t end_node);

int check_in_tree(node_t *node, tree_t tree_root);