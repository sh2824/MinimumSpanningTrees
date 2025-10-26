# Minimum Spanning Trees

## required external library
sudo apt install nlohmann-json3-dev

nlohmann-json3-dev is required for the loadFromJson function of the graph data structure to work.

### Graph Data Structure
The graph data structure is represented by an adjacency list.
The graph needs to be created in code as either an empty graph or a graph of one node.
There is a supported loadFromJson function that can be used on an empty graph to load one from a .json file.

the structure of the file requires two declared values; "Directed" and "Weighted" to be either 0 or 1.
the file also needs a "vertexList" containing all vertices and an "edgeList" containing all edges in the format:

  {"source":"stringA", "destination":"stringB", "weight":double}


