class Solution{
    private:
    Node* solve(int in[], int pre[],int &index, int startIndex, int endIndex, 
                    int n, unordered_map<int, queue<int> > &mp) {
        //base case
        if(index >= n || startIndex > endIndex) {
            return NULL;
        }
        int element = pre[index++];
        Node* ans = new Node(element);
        int pos = mp[element].front();
        mp[element].pop();
        
        ans -> left = solve(in, pre, index, startIndex, pos-1, n, mp);
        ans -> right = solve(in, pre, index, pos+1, endIndex, n, mp);
        
        return ans;
    }
    public:
    Node* buildTree(int in[],int pre[], int n)
    {
        int index = 0;
        unordered_map<int,queue<int> > mp;
        
        for(int i = 0; i<n; i++) {
            mp[in[i]].push(i);
        }
        Node* ans = solve(in, pre, index, 0, n-1, n, mp);
        return ans;
    }