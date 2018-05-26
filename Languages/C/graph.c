/**
 * @file graph.c
 * @author John Buckley
 * @date April 27, 2018
 * @brief Implementation of dijkstra.h
 * 
 * The implementation of functions from dijkstra.h to be used to find shortest path 
 * using Dijkstra's algorithm
 */


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "dijkstra.h"


void addEdge (graph_t *g,int a,int b,int w){
  a=a-'a';
  b=b-'a';
  addVertex(g,a);
  addVertex(g,b);
  vertex_t *v=g->vertices[a];
  if(v->edges_len>=v->edges_size){
    v->edges_size=v->edges_size?v->edges_size*2:4;
    v->edges=realloc(v->edges,v->edges_size*sizeof(edge_t *));
  }
  edge_t *e=calloc(1,sizeof(edge_t));
  e->vertex=b;
  e->weight=w;
  v->edges[v->edges_len++]=e;
}


heap_t *create_heap(int n){
  heap_t *h=calloc(1,sizeof(heap_t));
  h->data=calloc(n+1,sizeof(int));
  h->prio=calloc(n+1,sizeof(int));
  h->index=calloc(n,sizeof(int));
  return h;
}

void addVertex (graph_t *g,int i){
  if (g->vertices_size<i+1){
    int size=g->vertices_size*2>i?g->vertices_size*2:i+4;
    g->vertices=realloc(g->vertices,size*sizeof(vertex_t *));
    for(int j=g->vertices_size; j<size; j++)
      g->vertices[j]=NULL;
    g->vertices_size=size;
  }
  if(!g->vertices[i]){
    g->vertices[i]=calloc(1,sizeof(vertex_t));
    g->vertices_len++;
  }
}


void pushHeap (heap_t *h,int v,int p) {
  int i=h->index[v]==0?++h->len:h->index[v];
  int j=i/2;
  while(i>1){
    if(h->prio[j]<p)
      break;
    h->data[i]=h->data[j];
    h->prio[i]=h->prio[j];
    h->index[h->data[i]]=i;
    i=j;
    j=j/2;
  }
  h->data[i]=v;
  h->prio[i]=p;
  h->index[v]=i;
}


int popHeap (heap_t *h){
  int v=h->data[1];
  int i=1;
  while(1){
    int j=min(h,h->len,2*i,2*i+1);
    if(j==h->len)
      break;
    h->data[i]=h->data[j];
    h->prio[i]=h->prio[j];
    h->index[h->data[i]]=i;
    i=j;
  }
  h->data[i]=h->data[h->len];
  h->prio[i]=h->prio[h->len];
  h->index[h->data[i]]=i;
  h->len--;
  return v;
}


int min (heap_t *h,int i,int j,int k){
  int m=i;
  if(j<=h->len && h->prio[j]<h->prio[m])
    m=j;
  if(k<=h->len&&h->prio[k]<h->prio[m])
    m=k;
  return m;
}


void dijkstra (graph_t *g,int a,int b) {
  int i, j;
  a=a-'a';
  b=b-'a';
  for(i=0; i<g->vertices_len; i++) {
    vertex_t *v=g->vertices[i];
    v->dist=INT_MAX;
    v->prev=0;
    v->visited=0;
  }
  vertex_t *v=g->vertices[a];
  v->dist=0;
  heap_t *h=create_heap(g->vertices_len);
  pushHeap(h,a,v->dist);
  while(h->len) {
    i=popHeap(h);
    if(i==b)
      break;
    v=g->vertices[i];
    v->visited=1;
    for(j=0; j<v->edges_len; j++) {
      edge_t *e=v->edges[j];
      vertex_t *u=g->vertices[e->vertex];
      if (!u->visited&&v->dist+e->weight<=u->dist) {
	u->prev=i;
	u->dist=v->dist+e->weight;
	pushHeap(h,e->vertex,u->dist);
      }
    }
  }
}


void printPath (graph_t *g, int i){
  int n, j;
  vertex_t *v, *u;
  i=i-'a';
  v=g->vertices[i];
  if(v->dist==INT_MAX) {
    printf("no path\n");
    return;
  }
  for(n=1,u=v; u->dist; u=g->vertices[u->prev],n++)
    ;
  char *path=malloc(n);
  path[n-1]='a'+i;
  for(j=0,u=v;u->dist; u=g->vertices[u->prev],j++)
    path[n-j-2]='a'+u->prev;
  printf("%d %.*s\n",v->dist,n,path);
}
