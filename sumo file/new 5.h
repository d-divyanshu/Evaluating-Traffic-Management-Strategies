#include <iostream>
using namespace std;
#include<vector>
#include<queue>
class Graph{
    int v;
    vector<pair<int,int>> *gp;
    public:
    Graph(int v){
        this->v=v;
        gp = new vector<pair<int,int>>[v];
    }
    
    
    void addedge(int x,int y,int wt, bool dt){
        gp[x].push_back(make_pair(y,wt));
        if(dt) gp[y].push_back(make_pair(x,wt));
    }
    void printgp(){
        for(int i=0;i<v;i++){
            cout<<"vertex "<<i<<"->";
            for(auto j:gp[i]) cout<<j.first<<"("<<j.second<<"),";
            cout<<endl;
        }
    }
    void bfs(int src){
        cout<<"bfs: ";
        vector<bool> visited(v);
        queue<int> q;
        q.push(src);
        visited[src]=true;
        cout<<src<<" ";
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(auto c:gp[x]){
                if(!visited[c.first]){
                    q.push(c.first);
                    visited[c.first]=true;
                    cout<<c.first<<" ";
                }
            }
        }
    }
    void dfs_helper(int src,vector<bool> &visited){
        visited[src]=true;
        cout<<src<<" ";
        for(auto i:gp[src]){
            if(!visited[i.first]){
                dfs_helper(i.first,visited);
            }
        }
    }
    void dfs(int src){
        cout<<endl<<"dfs: ";
        vector<bool> visited(v);
        dfs_helper(src,visited);
    }
    void ff_helper(int src,vector<bool> &visited,int &flag,int baap){
        visited[src]=true;
        for(auto i:gp[src]){
            if(!visited[i.first]){
                ff_helper(i.first,visited,flag,src);
            }
            else{
                if(i.first!=baap&&flag!=1 ){
                    cout<<"Cycle present";
                    flag=1;
                    return;
                }
            }
            
        }
        return;
    }
    
    
    
    void floodfill(int src){
        cout<<endl<<"floodfill: ";
        vector<bool> visited(v,false);
        int flag=0;
        ff_helper(src,visited,flag,src);
        if(flag==0) cout<<"Cycle not present";
    }
    
};



int main() {
	Graph g(7);
	g.addedge(0,1,1,true);
	g.addedge(1,2,4,true);
	g.addedge(1,3,3,true);
	g.addedge(3,4,5,true);
	g.addedge(3,6,3,true);
	g.addedge(3,5,2,true);
	g.addedge(4,5,2,true);
	g.printgp();
	g.bfs(0);
	g.dfs(0);
	g.floodfill(0);
	g.bipertite(0);
	return 0;
}
