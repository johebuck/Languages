% NAME: John Buckley
% DATE: 03/02/2018
% PROGRAM: Dijkstra's algorithm in ASP

%vertices
node(a). node(b). node(c). node(d). node(e). node(f). node(g). node(h). node(i).

% edges of graph and the weight
edge(a,b,4). edge(a,h,10).
edge(b,c,8). edge(b,h,11).
edge(c,i,2). edge(c,d,7). edge(c,f,4).
edge(d,f,14). edge(d,c,9).
edge(e,f,10).
edge(f,g,2).
edge(g,i,6). edge(g,h,1).
edge(h,i,7).

%edges are symmetric, undirected graph
edge(Y,X,Z) :- edge(X,Y,Z).

%a path exists if there is an edge that starts with the same node
{path(X,Y,Z) : edge(X,Y,Z)} :- node(X).
{path(X,Y,Z) : edge(X,Y,Z)} :- node(Y).

%nodes must share an edge between them to be connected
connect(Y) :- path(start,Y,Z).
connect(Y) :- connect(X), path(X,Y,Z).
:- not connect(end), node(end).

%minimize the weight
#minimize{Z,X,Y : path(X,Y,Z), edge(X,Y,Z)}.

#show path/3.
