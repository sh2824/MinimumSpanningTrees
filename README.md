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

### Tree Data Structure
The tree data structure is created using pointers. The Tree object is a pointer to a root node.
All nodes have a string key, double cost, and vector<Node*> children. the vector of Node pointers allows
us to use this as a n-ary tree which is needed to make minimum spanning trees from graphs.

### Kruskal's algorithm
Kruskal's algorithm is implemented by creating a kruskal object, then using its run method that takes a Graph
object as input and returns a new TreeMST object. The Kruskal run method first makes a list of all edges in the
tree then sorts that list by the weight of the edges. At this point run does a quick check to see it the graph
passed as input had no edges. If the graph has no edges run returns an empty tree. A temporary Graph object is 
created and the edges are added to the temporary graph starting with the lowest cost and skipping any edges that
would create a cycle in the graph. Once that is finished our MST is created as a graph so we go to the selected 
root Node of the Graph, usually the source of the lowest cost edge, and use a DFS algorithm to add nodes to a tree.
Once the DFS finishes traversing the graph we return the tree created and it is a minimum spanning tree.

