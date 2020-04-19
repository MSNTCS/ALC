#include <cstdlib>
#include <sstream>
#include <vector>
#include <random>
#include <queue>
#include <algorithm>
#include <string>
#include <math.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <limits>
#include <unistd.h>
#include <sys/time.h>

#include "DGraph.h"

using namespace std;
using namespace graphns;



/*
With this file we can test the speed-up and correctness of queryAll-queries,
i.e. find all nodes v' s.t. for a given v in V and L' subset of L we have that
query(v,v',L) == True
*/
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
