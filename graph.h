#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include "node.h"

/**
 * @brief class to create graphs
 * @nodes: holds the nodes constituting the graph
 * 
 */



class graph{
    private: 
    std::vector<Node> nodes;
  
    public:
    graph(std::initializer_list<std::string>node_list);

    //Add node to nodelist
    void push_back(Node& n);

    //Create node using nodename and add to nodelist
    void push_back(std::string node_name);
    
    //find the nodes present in the graph
    std::vector<std::string> get_graph_nodes();


    //print and return vector containing all neighbours of node_name
    neighbours get_neighbours(std::string node_name);

    neighbours get_neighbours(Node n);

    //Find and return the iterator of a node if present in the graph
    std::vector<Node>::iterator find_node(std::string node_name);
};



