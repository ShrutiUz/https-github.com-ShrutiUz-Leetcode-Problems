class Solution {
public:

    int findRoot(int n, vector<int>&leftChild, vector<int>&rightChild){
        unordered_set<int>st;
        st.insert(leftChild.begin(), leftChild.end());
        st.insert(rightChild.begin(), rightChild.end());

        for(int i=0; i<n; i++){
            if(st.find(i) == st.end()){
                return i;
            }
        }

        return -1;
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {

        int root = findRoot(n, leftChild, rightChild);
        if(root == -1){
            return false;
        }

        unordered_set<int>seen;
        seen.insert(root);

        stack<int>st;
        st.push(root);

        while(!st.empty()){
            int node = st.top();
            st.pop();

            int children[] = {leftChild[node], rightChild[node]};
            for(int child : children){
                if(child != -1){
                    if(seen.find(child) != seen.end()){
                        return false;
                    }
                    seen.insert(child);
                    st.push(child);
                }
            }
        }

        return seen.size() == n;
    }
};