#include "graph.h"
#include <queue>
#include <list>
#include <unordered_map>
#include <map>

int main()
{
    graph G{"A","B","C","D","E","F","G"};
    G.find_node("A")->add_neighbour({{"D",1},{"B",1}});
    G.find_node("B")->add_neighbour({{"F",1},{"C",1}});
    G.find_node("C")->add_neighbour({{"E",1},{"G",1}});
    G.find_node("D")->add_neighbour({{"F",1}});
    G.find_node("E")->add_neighbour({{"B",1},{"F",1}});
    G.find_node("F")->add_neighbour({{"A",1}});
    G.find_node("G")->add_neighbour({{"E",1}});

    //Maps the node to the total cost of reaching the node
    std::map<std::string,int> node_cost;
    auto start = G.find_node("D");
    frontier(*start);
   
    std::list<Node> reached;
    reached.push_back(*start);

    /*
        map came_from keeps track of the node it came from.
    */
   std::map<std::vector<Node>::iterator,std::vector<Node>::iterator>came_from;

    while(!frontier.empty())
    {
        auto current = frontier.front();
        frontier.pop();
        auto curr_it = G.find_node(current.name);
       for(auto& next_edge: G.get_neighbours(current.name))
        {
            auto next_node_it = G.find_node(next_edge.first);

            auto it = std::find(reached.begin(),reached.end(),*next_node_it);

            if(it == reached.end()){
                reached.push_back(*next_node_it);
                came_from[next_node_it] = curr_it;
                frontier.push(*next_node_it);
            }
        }
    }

    for(auto node:reached)
        std::cout<<node.name<<std::endl;
    
    auto goal_node=G.find_node("G");
    auto current_node = goal_node;

    while(current_node!=start)
    {   
        std::cout<<"Path from bfs: "<<current_node->name<<std::endl;
        current_node = came_from[current_node];
    }
}