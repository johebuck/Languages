import java.util.*;
import java.io.*;

public class Graph{

    TreeMap <String, Integer> inner;
    TreeMap <String, TreeMap <String, Integer >> outer=new TreeMap <String, TreeMap <String, Integer >> ();

    public Set <String> graphVertices = new HashSet <String> ();

    public void readFile (String arg){
	try {
	    Scanner inFile=new Scanner(new File (arg));
	    while(inFile.hasNext()){
		String node1;
		String node2;
		Integer weight;
		node1=inFile.next();
		node2=inFile.next();
		weight=inFile.nextInt();
		addEdge(node1, node2, weight);
		addEdge(node2, node1, weight);
	    }
	    inFile.close();
	}
	catch(FileNotFoundException e) {
	    System.out.println("Cannot open file.");
	}
    }

	public void printGraph(){
	String node1;
	String node2;
	Integer w;
	Map.Entry e;
	Set outerKeys=outer.keySet();
	Iterator it=outerKeys.iterator();
	Set innerKeys;
	Iterator it2;
	while(it.hasNext()){
	    node1=(String)it.next();
	    innerKeys=outer.get(node1).entrySet();
	    it2=innerKeys.iterator();
	    while(it2.hasNext()){
		e=(Map.Entry)it2.next();
		node2=(String)e.getKey();
		w=(Integer)e.getValue();
		System.out.println(node1+" "+node2+" "+ w);
	    }
	}
    }


    public void outer(){
	graphVertices = outer.keySet();
    }


    public void addEdge(String node1,String node2,Integer w){
	inner=outer.get(node1);
	if (inner==null){
	    inner=new TreeMap <String, Integer> ();
	    outer.put(node1, inner);
	}
	inner.put(node2, w);
    }

    public void removeEdge(String node1, String node2, Integer w){
	inner = outer.get(node1);
	if(inner == null){
	    inner = new TreeMap <String, Integer> ();
	    outer.put(node1, inner);
	}
	inner.remove(node2, w);
    }
}
    
