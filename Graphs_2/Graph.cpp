#include "Graph.h"

/*
	Constructor
*/
Graph::Graph(int n, bool oriented) {
	this->numNodes = n;
	this->oriented = oriented;
	for (int i = 0; i < numNodes; i++) {
		neigh.push_back(vector<int>());
	}
}

/* 
	Adds an edge to the graph (both ways if unoriented)
*/
void Graph::addEdge(int i, int j) {
	neigh[i].push_back(j);
	if (!oriented) {
		neigh[j].push_back(i);
	}
}

/*
	Checks if two nodes are connected by an edge
*/
bool Graph::isEdge(int i, int j) {
	vector<int> v = neigh[i];
	return std::find(v.begin(), v.end(), j) != v.end();
}

void Graph::connectedComponents() {

	/* TODO 1 Initializations */
	
	/* 
		TODO 1 Call dfs for all unvisited nodes
		
		Use: components.push_back(vector<int>());
			to create new component
	*/
}

void Graph::dfs(int node, vector<bool>& visited) {
	/*
		TODO 1 Perform dfs
			To add node to component use:
			components[numConnectedComp].push_back(node);
	*/
}

stack<int> Graph::minPath(int source, int dest) {
	vector<bool> visited(numNodes);
	std::queue<int> q;
	vector<int> dist(numNodes);
	vector<int> parent(numNodes);
	int INF = 1000000000;
	/* TODO 2 Initializations */
	for (int i = 0; i < numNodes; i++) {
		dist[i] = INF;
		parent[i] = -1;
		visited[i] = 0;
	}
	/*
		TODO 2 Perform BFS from source, keeping track of distance and parent
	*/
	int nod;
	dist[source] = 0;
	q.push(source);
	int nr = 0;
	while(!q.empty()) {
		nod = q.front();
		q.pop();
		int noNeigh = neigh[nod].size();
		for (int i = 0; i < noNeigh; i++) {
			if (visited[neigh[nod][i]] == 0) {
				visited[neigh[nod][i]] = 1;
				parent[neigh[nod][i]] = nod;
				dist[neigh[nod][i]] = nr;
				q.push(neigh[nod][i]);
			}
		}
		nr++;
	}

	stack<int> path;
	// There is no path from source to destination
	if (parent[dest] == -1) return path;

	/*
		TODO 2 Start from destination, node becomes its parent and gets
		pushed onto the stack while source is not reached
	*/
	path.push(dest);
	nod = parent[dest];
	while (nod != source) {
		path.push(nod);
		nod = parent[nod];
	}
	path.push(source);
	return path;
}

/*
	Comparator for finTime used in topologicalSort
*/
struct comp {
	vector<int> finTime;
	comp(vector<int>& finTime) {
		this->finTime = finTime;
	}
	bool operator()(int i, int j) const {
		return finTime[i] > finTime[j];
	}
};

vector<int> Graph::topSort() {
	vector<bool> visited;
	vector<int> topSortOrder;
	finTime.resize(numNodes);

	for (int i = 0; i < numNodes; i++) {
		/*
			TODO 3 Initialize visited
		*/
		topSortOrder.push_back(i);
	}
	
	/*
		TODO 3 Call dfsTopSort for each unvisited node
	*/
	
	comp c(finTime);
	
	// Nodes sorted in descending order by finTime
	sort(topSortOrder.begin(), topSortOrder.end(), c);
	return topSortOrder;
}
void Graph::dfsTopSort(int n, vector<bool>& visited) {
	/* 
		TODO 3 Perform DFS keeping track of finTime
	*/
}

bool Graph::isBipartite(pair<vector<int>, vector<int> >& p) {
	vector<int> sides[2];
	vector<Tag> tag(numNodes);
	queue<int> q;

	/*
		TODO 4 Initialize all tags with UNDEFINED
	*/
	
	tag[0] = PAR;
	q.push(0);
	
	/*
		TODO 4 Perform BFS, marking the tags accordingly
	*/
	
	/*
		TODO 4 sides[0] will contain nodes with PAR tag and sides[1]
		the nodes with IMPAR tag
		
		To add node to one side: sides[x].push_back(node);
	*/

	p = make_pair(sides[0], sides[1]);
	return true;
}
void Graph::hamiltonianCycles() {
	vector<bool> included(numNodes, false);
	vector<int> path(numNodes, -1);

	/*
		TODO BONUS Start constructing path from node 0
	*/
	path[0] = 0;
	included[0] = 1;
	buildPath(path, included, 1);
	
}
 
bool Graph::buildPath(vector<int>& path, vector<bool>& included, int length) {
	/*
		TODO BONUS Check if path represents a hamiltonian cycle and add it
		 to the list:
				hamCycles.push_back(path);
		
			Otherwise try to include each node to the path.
			
			Path already has the right size, use [] operator not push_back!
	*/
	if (length == numNodes) {
		int start = path[0];
		int finish = path[length - 1];
		
		if (isEdge(start, finish)) {
			hamCycles.push_back(path);
			return true;
		}
	} else {
		int finish = path[length - 1];
		int noNeigh = neigh[finish].size();
		int nod;	
		for (int i = 0; i < noNeigh; i++) {

			nod = neigh[finish][i];
			if (included[nod] == 0) {

				path[length] = nod;
				included[nod] = 1;

				buildPath(path, included, length + 1);

				included[nod] = 0;
			}
		}
	}
	return false;
}
