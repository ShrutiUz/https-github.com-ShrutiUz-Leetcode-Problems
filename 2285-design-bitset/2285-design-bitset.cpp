class Bitset {
public:
    string bitset, inv_bitset;
    int counter;
    int siz;

    Bitset(int size) {

        siz = size;
        counter = 0;

        bitset = string(size, '0');
        inv_bitset = string(size, '1');

    }
    
    void fix(int idx) {
        if(bitset[idx] == '0') counter++;
        bitset[idx] = '1';
        inv_bitset[idx] = '0';
    }
    
    void unfix(int idx) {
        if(bitset[idx] == '1')counter--;
        bitset[idx] = '0';
        inv_bitset[idx] = '1';
    }
    
    void flip() {
        swap(bitset, inv_bitset);
        counter = siz-counter;
    }
    
    bool all() {
        return counter == siz;
    }
    
    bool one() {
        return counter>0;
    }
    
    int count() {
        return counter;
    }
    
    string toString() {
        return bitset;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */