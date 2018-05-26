#ifndef DIJKSTRA_H_
#define DIJKSTRA_H_

typedef struct {
  int vertex;
  int weight;
} edge_t;

typedef struct {
  edge_t **edges;
  int edges_len;
  int edges_size;
  int dist;
  int prev;
  int visited;
} vertex_t;

typedef struct {
  vertex_t **vertices;
  int vertices_len;
  int vertices_size;
} graph_t;

typedef struct {
  int *data;
  int *prio;
  int *index;
  int len;
  int size;
} heap_t;

/**
 * @author John Buckley
 * @param int i
 * @param graph_t *g
 * @date 04/27/2018
 *
 */
void addVertex (graph_t *g, int i);

/**
 * @author John Buckley
 * @param int a 
 * @param int b 
 * @param int w 
 * @param graph_t *g
 * @date 04/27/2018
 */
void addEdge (graph_t *g, int a, int b, int w);

/**
 * @author John Buckley
 * @param heap_t *h
 * @param int v
 * @param int p
 * @date 04/27/2018
 */
void pushHeap (heap_t *h, int v, int p);

/**
 * @author John Buckley
 * @param heap_t *h
 * @param int i
 * @param int j
 * @param int k
 * @date 04/27/2018
 */
int min (heap_t *h, int i, int j, int k);

/**
 * @author John Buckley
 * @param heap_t *h
 * @date 04/27/2018
 */
int popHeap (heap_t *h);

/**
 * @author John Buckley
 * @param graph_t *g
 * @param int a
 * @param int b
 * @date 04/27/2018
 */
void dijkstra (graph_t *g, int a, int b);

/**
 * @author John Buckley
 * @param graph_t *g
 * @param int i
 * @date 04/27/2018
 */
void printPath (graph_t *g, int i);

#endif //DIJKSTRA_H_
