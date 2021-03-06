/*Homework 5
 * 
 * Tushar Narayan
 * tnarayan
 * 
 * Saraf Rahman
 * strahman
 * 
 * Nikhil Godani
 * nsgodani
 * */

import java.util.*;

class Node<T> {
  private T aNode;          // name of element (user profile or city name) at this node
  private LinkedList<Node<T>> getsTo;  // edges from this Node
  
  // constructor only takes the element name as an argument, 
  //   initializing the getsTo list internally
  Node(T aNode) {
    this.aNode = aNode;
    this.getsTo = new LinkedList<Node<T>>();
  }
  
  // adds an edge from this node to the given toNode
  public void addEdge(Node<T> toNode) {
    this.getsTo.add(toNode);
  }
  
  // determines whether there is a route from this Node to the given node
  boolean hasRoute(Node<T> to, LinkedList<Node<T>> visited){
    if(this.equals(to))
      return true;
    else if(visited.contains(this))
      return false;
    else {
      visited.add(this);
      for (Node<T> c : this.getsTo){
        if(c.hasRoute(to, visited)){
          return true;
        }
      }
      return false;
    }
  }
  
  // produce a list of all nodes reachable from this node
  LinkedList<Node<T>> reacheableFrom(LinkedList<Node<T>> visited){
    if(visited.contains(this))
      return visited;
    else {
      visited.add(this);
      for (Node<T> c : this.getsTo){
        c.reacheableFrom(visited);
      }
    }
    return visited;
  }
}