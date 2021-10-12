# Representation of Grpah
## 1) Edge List
>An edge list is a **list or array of all the edges in a graph**. Edge lists are one of the easier representations of a graph.
>Each object inside the list will hold two things, node u and node v, indicating that an edge exists that connects node u with node v. 
>If the graph is weighted then each object will hold a piece of third information, which is the weight of the edge between nodes u and v.
>
>![Graph](https://cdncontribute.geeksforgeeks.org/wp-content/uploads/undirectedgraph.png)
>
>Graph = [ [0,1], [0,4], [1,4], [1,2], [2,3], [3,1], [3,4] ]       
>***`This data structure is especially helpful with graphs that have a large number of nodes, but only a small number of edges.`***

## 2) Adjacency Matrix 
>Adjacency Matrix is a 2D array of **size V x V** where V is the **number of vertices in a graph**. 
>Let the 2D array be adj[][], a slot adj[i][j]=1 indicates that there is an edge from vertex i to vertex j. Adjacency matrix for **undirected graph is always symmetric**. 
>Adjacency Matrix is also used to represent weighted graphs. If adj[i][j] = w, then there is an edge from vertex i to vertex j with weight w. 
>
> ![Undirected Graph](https://www.softwaretestinghelp.com/wp-content/qa/uploads/2020/05/4-5.png) 
> ![Directed Weighted Graph](https://www.softwaretestinghelp.com/wp-content/qa/uploads/2020/05/6-3.png)
>  
>***`Adjacency matrices are helpful when we need to quickly find whether two nodes are adjacent (connected) or not. The adjacency matrix is a 2D boolean array of a size V^2.`***

## 3) Adjacency List
>An **array of lists** is used. The size of the array is equal to the number of vertices. Let the array be an array[]. An entry array[i] represents the list of vertices 
>adjacent to the ith vertex. This representation can also be used to represent a weighted graph. The weights of edges can be represented as lists of pairs. Following is 
>the adjacency list representation of the above graph. 
>
> ![Undirected Graph](https://www.softwaretestinghelp.com/wp-content/qa/uploads/2020/05/7-6.png)
> ![Directed Graph](https://www.softwaretestinghelp.com/wp-content/qa/uploads/2020/05/9-1.png) 


# Complexity
>With graph data structures, we usually pay attention to the following complexities:           
> ### Space Complexity 
>The approximate amount of memory needed to store a graph in the chosen data structure.        
>
>### Time Complexity
> * **Connection Checking Complexity:** The approximate amount of time needed to find whether two different nodes are neighbors or not.
> * **Neighbors Finding Complexity:** The approximate amount of time needed to find all the neighboring nodes of some goal node.
>We call two different nodes **“neighboring nodes”** if there’s an edge that connects the first node with the second.
>
> ![Complexity](https://www.baeldung.com/wp-content/ql-cache/quicklatex.com-d26a56775312cf9e775e97caf6bdcdbc_l3.svg) 
> 
> ### `Space Complexity`
>* **Edges List:** In this data structure we only have a linked list that stores all the possible edges between all nodes inside the graph. Therefore, the memory complexity is O(E).
>* **Adjacency Matrix:** Since in adjacency matrices we store an array of size V^2, it means that the space complexity is O(V^2), where V is the number of vertices inside the graph.
>* **Adjacency List:** First, we store an array of size V, where each cell stores the information of one of our graph’s nodes. This means that first, we need a space complexity 
>of O(V) to store an empty array. Next, we move to the sum of all linked lists’ sizes. Since we only create an extra linked list object in case of a new edge, it means that 
>the sum of linked lists’ sizes is equal to O(E), where E is the number of edges in our graph. This leads us to a total space complexity of O(V+E). For Undirected graph space
>complexity is O(V + 2E) because every edge will be added twice.
>
> ### `Connection Checking Complexity`
> * **Edges List:** In the edges list case, we don’t have any other option but to iterate over all the edges inside the linked list, and check whether we can find the edge 
> needed between nodes u and v. The complexity is O(E) where E is the number of edges inside the graph.
>* **Adjacency Matrix:** Checking whether two nodes u and v are connected or not is pretty efficient when using adjacency matrices. All we have to do is to look for the value 
>of the cell G_{uv}. Therefore, the time complexity equals O(1).
>* **Adjacency List:** To find whether two nodes u and v are connected or not, we have to iterate over the linked list stored inside G_u. In the worst case, there won’t be an 
>edge between u and v, and we’ll end up making N_u iterations. Hence, the total complexity is O(N_u), where N_u is the number of neighbors of u.
>
> ### `Neighbors Finding Complexity`
>* **Edges List:** Edges list is probably not the best solution to finding all neighboring nodes quickly. We need to iterate over all the stored objects inside the linked list 
>and check if the stored nodes are u and v. Hence, the time complexity is O(E), where E is the number of edges in the graph.
>* **Adjacency Matrix:** To find all the neighboring nodes of some node u, we have to iterate over all the cells in the row u to determine which nodes have a direct edge connecting 
>it to u. In other words, we need to check all cells G{ui}, where i \in [1, V]. Therefore, the time complexity is O(V).
>* **Adjacency List:** Finding all the neighboring nodes quickly is what adjacency list was created for. Since cell G_u stores a linked list that contains all the nodes v connected 
>to u, we just need to iterate over the linked list stored inside G_u. The time complexity of such iterating is O(N_u), where N_u represents the number of the neighbors 
>of node u.

# Advantages and Disadvantages
>**Adjacency matrices** are helpful when we need to quickly check if two nodes have a direct edge or not. However, the main disadvantage is its **large memory complexity**. 
>The adjacency matrix is most helpful in cases where the graph **doesn’t contain a large number of nodes**. 
>Also, when the graph is **almost complete** (every node is connected to almost all the other nodes), using adjacency matrices might be a good solution.
>
>**Adjacency lists**, is a great option when we need to **continuously access all the neighbors of some node u**. In that case, we’ll only be iterating over the needed nodes. 
>Adjacency list **limitations** show when we need to **check if two nodes have a direct edge or not**. However, it’s worth noting that we can use an updated version of 
>adjacency lists. Instead of storing all the neighboring nodes in a linked list, we can store them in a more complex data structure, like a set for example. 
>This would allow us to iterate over the neighboring nodes efficiently. Also, we can check if two nodes are connected in logarithmic time complexity.
>
>**Edges lists are the least used data structure.** Mainly, we use edges lists when we have an **enormous amount of nodes** that can’t be stored inside the memory, with only 
>a few edges. In that case, we wouldn’t have any other option but to use the edges list. So, the only advantage of the edges list is its **low memory space complexity**.
