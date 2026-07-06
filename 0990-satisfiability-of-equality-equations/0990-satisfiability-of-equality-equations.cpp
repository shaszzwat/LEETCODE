class Solution {
public:
    vector<int>parent;
    vector<int>rank;

    int find(int x){
        if(parent[x]==x){
            return x;
        }

        return parent[x]=find(parent[x]);
    }
    void Union(int x,int y){
        int parent_x=find(x);
        int parent_y=find(y);
        if(parent_x ==parent_y){
            return;
        }
        if(rank[parent_x]>rank[parent_y]){
            parent[parent_y]=parent_x;

        }
        else if(rank[parent_x]<rank[parent_y]){
            parent[parent_x]=parent_y;
        }

        else{
            parent[parent_x]=parent_y;
            rank[parent_y]++;
        }
    }



    bool equationsPossible(vector<string>& equations) {

        parent.resize(26);
        rank.resize(26,0);
        for(int i=0;i<26;i++){
            parent[i]=i;
        }

        for(int i=0;i<equations.size();i++){
            if(equations[i][1]=='='){
                Union(equations[i][0]-'a',equations[i][3]-'a');
            }
        }

        for(int i=0;i<equations.size();i++){
            if(equations[i][1]=='!'){
                int a=find(equations[i][0]-'a');
                int b=find(equations[i][3]-'a');
                if(a==b){
                    return false;
                }
            }
        }
        return true;
        
    }
};