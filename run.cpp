#include <iostream>
#include "Graph.cpp"
#include "Vertex.cpp"
#include "Splitedgraphs.cpp"
#include <fstream>
#include <chrono>
struct query {
    int src, target;
    vector<int> labels;
};
string labelToString(string label){
        int binaryNum[32];
        int i = 0;
        string s ="";
        int n = std::stoi(label);
        while (n > 0) {
            binaryNum[i] = n % 2;
            n = n / 2;
            i++;
        }
        for (int j = i - 1; j >= 0; j--)
            s += to_string(binaryNum[j]);
    return s;
}
vector<int> labelsofQueries(string label){
    string ls = labelToString(label);
    char ones [ls.size()+1];
    vector <int> labels;
    for (int i = 0; i < ls.size()+1 ; ++i) {
        if (ones[i] == '1'){
            labels.push_back(i);
        }
    }
}

vector<query> load_query(string file) {
    vector<query> q;
    cout << "filename :" << file << endl;
    string line;
    static int var = 0; //set the correspond value;
    fstream edge_file;
    edge_file.open((file));
    vector<query> all_quries;
    if (edge_file.is_open())
    {

        while (getline(edge_file, line))
        {
            stringstream linestream(line);
            string from;
            getline(linestream, from, ' ');
            int src = stoi(from);
            string to;
            getline(linestream, to, ' ');
            int target =  stoi(to);
            string label;
            getline(linestream, label);
            vector<int> labels = labelsofQueries(label);
            query q  = {src, target, labels};
            all_quries.push_back(q);
        }
    }
}
int main(int argc, char *argv[])
{
     Graph* graph = new Graph();
     string file = argv[1];
     int number_of_query_sets = atoi(argv[2]);
     graph->loadedgefile(file);
     graph->generate_subgraphs(0);
    for (int k = 0; k < number_of_query_sets; ++k) {
        string trueFileName = argv[3];
        //string falseFileName = "../Samples/" + file + to_string(k) + ".false";
        vector<query> q_true = load_query(trueFileName);
        //vector<query> q_false = load_query(falseFileName);
        for (int i = 0; i < q_true.size() ; ++i) {
            query q = q_true.at(i);
            cout << q.src << q.target << endl;
            unordered_set<string> labels;
            for (int j = 0; j < q.labels.size() ; ++j) {
                labels.insert(to_string(q.labels.at(i)));
            }
           graph->BFS_for_subgraphs(to_string(q.src), to_string(q.target), labels );
        }
    }
}