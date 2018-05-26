/*
NAME: John Buckley III
DATE: 04/15/2018
FILE: Graph.java
*/

import java.util.*;
import java.io.*;

public class Dijkstra {

    public Set <String> treeVertices = new HashSet <String> ();

    public TreeMap <String, TreeMap <String,Integer>> treeMST = new TreeMap <String, TreeMap <String,Integer >> ();

    public static void main(String args[]) {
	String start;
	String end;
	start=args[1];
	end=args[2];
	Graph original = new Graph();
	Dijkstra dijkstra_graph = new Dijkstra();
	original.readFile(args[0]);
	System.out.println("Original: ");
	original.printGraph();
	System.out.println("Source: "+start+" Destination: "+end);
	while(dijkstra_graph.treeVertices.size() != original.graphVertices.size() ){
	    dijkstra_graph.minimize(original);
	}
    }

    public void minimize(Graph original){
	String node1;
	String node2;
	Integer w;
	Map.Entry e;
	String temp1 = new String();
	String temp2 = new String();
	Integer tempw = 10000;
	Set outerKeys = treeVertices;
	Iterator it = outerKeys.iterator();
	Set innerKeys;
	Iterator it2;
	while(it.hasNext()){
	    node1=(String)it.next();
	    innerKeys=original.outer.get(node1).entrySet();
	    it2=innerKeys.iterator();
	    while(it2.hasNext()){
		e=(Map.Entry)it2.next();
		node2=(String)e.getKey();
		w=(Integer)e.getValue();
		if(!outerKeys.contains(node2)){
		    if(w<tempw){
			tempw=w;
			temp1=node1;
			temp2=node2;
		    }
		}
	    }
	}
    }
}
