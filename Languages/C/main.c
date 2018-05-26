/**
 * @file graph.c
 * @author John Buckley
 * @date April 27, 2018
 * @brief Implementation of dijkstra.h
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include "dijkstra.h"

/**
 * @author John Buckley
 * @date April 27, 2018
 * @param argv String to get file name and source and destination nodes from command line
 * @return void
 */
int main(int argc,char* argv[]){
  int i;
  char node1[100], node2[100];
  int weight;
  FILE *infile;
  char *mode="r";
  infile=fopen(argv[1],mode);
  graph_t *g=calloc(1,sizeof(graph_t));
  int s=*argv[2]-'0';
  int start=s+48;
  int e=*argv[3]-'0';
  int end=e+48;
  
  printf("Source: ");
  printf(argv[2]);
  printf(" Destination: ");
  printf(argv[3]);
  printf("\n");
  
  printf("Original: \n");
  
  while(fscanf(infile, "%s %s %d", node1, node2, &weight)!=EOF){
    printf("%s %s %d\n", node1, node2, weight);
    addEdge(g, node1[i], node2[i], weight);
    
  }

  printf("Shortest Path: ");
  dijkstra(g, start, end);
  printPath(g, end);
  
  return 0;
}
