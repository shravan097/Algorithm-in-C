#include <iostream>
#include <cstdlib> //Provides size_t
#include <vector>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <stack>
#include <list>
#include <set>
#include <queue>

using namespace std;

//TEST OF GRAPH
#define NILL -1
const int n = 7;
int neighbors[n][10];
float weight[n][10];
int point[n][2];

void initialize_points()
{
    point[0][0]=0; point[0][1]=0;
    point[1][0]=8; point[1][1]= 0;
    point[2][0]=0; point[2][1] = 5;
    point[3][0]=2; point[3][1]=3;
    point[4][0]=3; point[4][1]=1;
    point[5][0]=8; point[5][1]=4;
    point[6][0]=1; point[6][1]=1;
}


void initialize_graph()
{
    for(int i=0; i<n; ++i){
        for(int j=0; j<10; ++j) neighbors[i][j]=-1;}
    
    neighbors[0][0]=1; neighbors[0][1]=2;neighbors[0][2]=6;
    neighbors[1][0]=0; neighbors[1][1]=4; neighbors[1][2]=5;
    neighbors[2][0]=0; neighbors[2][1]=3; neighbors[2][2]=5;
    neighbors[3][0]=5; neighbors[3][1]= 2;neighbors[3][2]= 6;neighbors[3][3]= 4;
    neighbors[4][0] = 6 ;neighbors[4][1] = 3 ;neighbors[4][2] = 5 ;neighbors[4][3] = 1 ;
    neighbors[5][0] = 1  ;neighbors[5][1] = 4 ;neighbors[5][2] = 3 ; neighbors[5][3] = 2 ;
    neighbors[6][0] = 0 ;neighbors[6][1] = 4 ; neighbors[6][2] = 3 ;
    
}

float calculate_weight(int x1, int x2, int y1, int y2)
{
    return sqrt(pow((x1-y1),2) + pow((x2-y2),2) );
}

void initialize_weight()
{
    for(int i=0 ;i <n; ++i)
        for(int j = 0; j< 10; ++j)
        {
            int adj_vertex= neighbors[i][j];
            if(adj_vertex!=-1)
            {
                weight[i][adj_vertex]=calculate_weight(point[i][0], point[i][1], point[adj_vertex][0], point[adj_vertex][1]);
            }
        }
}


class Vertex
{
public:
    Vertex()
    {
        distance=INT_MAX;
        parent=NILL;
    }
    
    friend bool operator<(const Vertex& source1, const Vertex& source2)
    {
        if(source1.distance>source2.distance) return false;
        return true;
    }

    float distance;
    int id;
    int parent;
};
// To compare two vertex
class Compare
{
public:
    bool operator()(const Vertex& n1, const Vertex& n2)
    {
        if (n1.distance > n2.distance)
            return true;
        else
            return false;
    }
};


void Relax( vector<Vertex>& node_list,int u, int v)
{
    int adj_vertex = neighbors[u][v];
    if(node_list[adj_vertex].distance>=
       (node_list[u].distance+weight[u][adj_vertex]))
    {
        node_list[adj_vertex].distance = node_list[u].distance + weight[u][adj_vertex];
        node_list[adj_vertex].parent = node_list[u].id;
    }
    
    
}


//Implement Dijkstra Algorithm that inputs neighbors


vector<Vertex> Dijkstra(int s)
{
  

    set<int> visited;
    vector<Vertex> node_list;
    //INITIALIZE
    for(int i=0;i<n;++i)
    {
        Vertex v;
        v.id=i;
        node_list.push_back(v);
    }
    node_list[s].distance=0;
    
    //Priority Queue for Keeping Track of Min Dist.
    priority_queue<Vertex,vector<Vertex>,Compare> Q;
    for(int i=0; i<n; ++i)
        Q.push(node_list[i]);
    
    while(!Q.empty())
    {
        Vertex u = Q.top();
        Q.pop();
        visited.insert(u.id); // Union of ALl visited Vertices.
    
            for(int j=0; j<10; ++j)
            {
                if(neighbors[u.id][j]!=-1) Relax(node_list, u.id , j);
            }
        
        vector<Vertex>vertex_left;
        while(!Q.empty())
        {
            vertex_left.push_back(Q.top());
            Q.pop();
        }
        //STL PRIORITY QUEUE copies the vertex so changes in node_lists
        //Does not change the priority queue. So, copying is required.
        for(int i=0; i<vertex_left.size(); ++i)
        {
            Vertex t = vertex_left[i];
            for(int j=0; j<n;++j)
            {
                if(t.id==node_list[j].id)
                    Q.push(node_list[j]);
            }
        }
        
    }
    
    return node_list;
}

void print_path(vector<Vertex> v, int s, int e, vector<int>& store)
{
    
    if(s == v[e].id ){ cout<<s<<" -> "; store.push_back(s);}
    else if(v[e].parent==NILL)cout<<"NO path"<<endl;
    else
    {
        print_path(v, s, v[e].parent,store);
        if(v[e].parent!=s) { cout<<v[e].parent<<" -> "; store.push_back(v[e].parent);}
    }



}

//Subset of Edges

class Edge{
public:
    int u;
    int v;
    
    Edge(int u, int v){ this->u= u; this->v = v;}
    
    friend bool operator == ( const Edge& s1, const Edge& s2)
    {
        if( (s1.u != s2.u) && (s1.u !=s2.v)) return false;
        return true;
    }
    
    void print()
    {
        cout<<"( "<<u<<", "<<v<<" ) "<<endl;
    }
};

int main()
{
    

    int start =0;

    
    initialize_graph();
    initialize_points();

    initialize_weight();
    
    
    vector<Vertex> A = Dijkstra(start);
    
    vector<Vertex>::iterator it;
    for(it = A.begin()+1; it!=A.end(); ++it)
        if(it->id!=start) cout<<"Shortest Distance from "<<start<<" to "<<it->id<<" = "<<it->distance<<endl;
  
     
}





