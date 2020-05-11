# Graph Handler
Graph handler is supposed to handle edge-labeled graphs.

Make sure that you have Boost Library. 
[» Download the latest release «](https://www.boost.org/users/download/).

The make file is not included here. Will be added soon.

## installation
```bash
cd graph_maintenance
g++ main.cc -o graph 
./graph $YOUR_GRAPH.edge
```

# Query Generator 
query generator is supposed to generate false and true queries for labeled graphs. 
## How to use
```bash
cd query_generator
g++ query_generator.cc -o query
./query $YOUR_GRAPH.edge  <k: number of query sets>  <l: number of queries per set per true or false> <k numbers denoting number of labels per query>
./query V1kD3L8exp.edge 3 1000 3 2 4 6 
```
3 = number of query sets,
1000 =  number of query per set,
3 = Number of labels per query for each query set,
2 4 6 = Number of desaired labels for each query set.
