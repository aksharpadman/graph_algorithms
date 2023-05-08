#include "node.h"

Node::Node(std::string _name):name{_name}{
}

void Node::add_neighbour(neighbour& n){
    
    neighbour_nodes.push_back(n);
}

void Node::add_neighbour(std::string node_name, int edge_weight)
{
    neighbour n = {node_name,edge_weight};
    add_neighbour(n);
}

void Node::add_neighbour(std::initializer_list<neighbour> neighbour_list){
    neighbour_nodes.insert(neighbour_nodes.end(),neighbour_list.begin(),neighbour_list.end());
    
}

size_t Node::num_neighbours()
{
    return neighbour_nodes.size();
}


 
//This overload only checks for equality of the node names
bool operator==(const Node a, const Node b){
    if(a.name == b.name)
        return true;
    return false;
 }