#include "graph.h"

//constructor

graph::graph(std::initializer_list<std::string>node_list){
    for(auto name:node_list)
        nodes.push_back(Node(name));
}

void graph::push_back(Node& n)
{
    nodes.push_back(n);
}

void graph::push_back(std::string node_name){
    nodes.push_back(Node(node_name));
}

std::vector<std::string> graph::get_graph_nodes()
{
    std::vector<std::string> node_names;
    for(auto node:nodes){
        std::cout<<node.name<<std::endl;
        node_names.push_back(node.name);
    }
    return node_names;
}



neighbours graph::get_neighbours(std::string node_name){
    auto it = find_node(node_name);
    if(it != nodes.end())
        return (*it).neighbour_nodes;
    else 
        return {};
}

//Overload function: return a vector of neighbour nodes
//Argument is Node 
neighbours graph::get_neighbours(Node n){
    return get_neighbours(n.name); 
}

std::vector<Node>::iterator graph::find_node(std::string node_name){
     auto result = std::find_if(std::begin(nodes),std::end(nodes),[node_name](Node& n){ 
            if(n.name == node_name) 
                return true;
            return false;
            }
    );

    if(result != nodes.end())
        return result;
    else 
        return nodes.end();

}
