#include <algorithm>
#include <iostream>

#include "graph_maintenance/DGraph.cc"

using namespace std;
using namespace graphns;



int main(int argc, char *argv[])
{
    if( argc < 2 )
    {
        cout << "./queryAll <edge_file>" << endl;
        return 1;
    }

    string edge_file = argv[1]; // the file containing the graph
    DGraph* dg = new DGraph(edge_file);

    int N = dg->getNumberOfVertices();
    int L = dg->getNumberOfLabels();

    if( L < 3 || N < 100 )
    {
        cout << "L or N too small" << endl;
        return 1;
    }

    return 0;
}
