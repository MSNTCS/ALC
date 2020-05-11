#include <iostream>
#include "Graph.cpp"
#include "Vertex.cpp"
#include "Splitedgraphs.cpp"
#include <fstream>
#include <chrono>


int main(int argc, char *argv[])
{
     Graph* graph = new Graph();
     string file = argv[1];
     graph->loadedgefile(file);
     graph->generate_subgraphs(0);
     for (int i = 0; i < 8 ; ++i) {
         cout << "Label" << i << ": "<< graph->get_labels_edge_size(to_string(i)) << endl;
     }
     for (int j = 0; j < 8 ; ++j) {
        int size = graph->subgraphs.at(j)->edge_size();
        cout << j << ": "<< size << endl;
     }
    cout << graph->BFS_for_subgraphs("2", "9" , {"1","0"});
}