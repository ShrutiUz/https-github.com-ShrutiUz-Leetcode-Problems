class MyHashMap {
public:

    int size;
    vector<list<pair<int,int>>>m;

    MyHashMap() {
        size = 1000000;
        m.resize(size);
    }

    int hash(int key){
        return key%size;
    }

    list<pair<int,int>> :: iterator search(int key){
        int idx = hash(key);
        list<pair<int,int>> :: iterator it = m[idx].begin();
        while(it != m[idx].end()){
            if(it->first == key){
                return it;
            }
            it++;
        }
        return it;
    }
    
    void put(int key, int value) {
        int idx = hash(key);
        remove(key);
        m[idx].push_back({key, value});
    }
    
    int get(int key) {
        int idx = hash(key);
        list<pair<int,int>>::iterator it = search(key);
        if(it == m[idx].end()) return -1;
        return it->second;
    }
    
    void remove(int key) {
        int idx = hash(key);
        list<pair<int,int>>::iterator it = search(key);
        if(it != m[idx].end()){
            m[idx].erase(it);
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */