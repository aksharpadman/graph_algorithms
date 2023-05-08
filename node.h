#include <iostream>
#include <vector>
#include <utility>
#include <iterator>

//Neighbour Node name and edge weight
typedef std::pair<std::string ,int> neighbour;


typedef std::vector<neighbour> neighbours;

 struct Node{
    std::string name;
    neighbours neighbour_nodes;
    //constructor
    Node(std::string _name);
   
    void add_neighbour(neighbour& n);

    void add_neighbour(std::string node_name,int edge_weight);

    //not sure if using initializer_list is a good idea
    void add_neighbour(std::initializer_list<neighbour> neighbour_list);

    size_t num_neighbours();

    friend bool operator==(const Node a, const Node b);
};