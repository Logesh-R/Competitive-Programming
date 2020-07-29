//705. Design HashSet

#define MAX_SET_SIZE 1000000

class MyHashSet {
    //hashSet to keep track of added/removed elements
    //All values will be in the range of [0, 1000000]
    bool hashSet[MAX_SET_SIZE];
public:
    MyHashSet() {
        for(int i=0; i<MAX_SET_SIZE; ++i)
            hashSet[i] = false;
    }
    
    void add(int key) {
        hashSet[key] = true;
    }
    
    void remove(int key) {
        hashSet[key] = false;
    }
    
    bool contains(int key) {
        return hashSet[key];
    }
};