class Node{
    public: 
        int key;
        int val;
        Node* next;
        Node* prev;
        Node(int k,int v): key(k),val(v),next(NULL),prev(NULL){}
};

class LRUCache {
private:
    int capacity;
    unordered_map<int,Node*>cache;
    Node* head;
    Node* tail;

    void insertAtHead(Node* node){
        Node* temp = head -> next;
        head -> next = node;
        temp -> prev = node;
        node -> prev = head;
        node -> next = temp;
    }

    Node* removeLeastRecent(){
        Node* leastRecent = tail -> prev;
        tail -> prev = leastRecent -> prev;
        leastRecent -> prev -> next = tail;
        leastRecent -> prev = NULL;
        leastRecent -> next = NULL;
        return leastRecent;
    }

    void removeNode(Node* node){
        Node* temp = node -> next;
        temp -> prev = node -> prev;
        node -> prev -> next = temp;
        node -> next = NULL;
        node -> prev = NULL;  
    }

public:
    
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head -> next = tail;
        tail -> prev = head;
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end() ) return -1;
        removeNode(cache[key]);
        insertAtHead(cache[key]);
        return cache[key]-> val;
    }
    
    void put(int key, int value) {
        if(cache.find(key) == cache.end()){
            if(cache.size() >= capacity){
                Node* keyToRemove = removeLeastRecent();
                cache.erase(keyToRemove->key);
            }
            Node* newKey = new Node(key,value); 
            insertAtHead(newKey);
            cache[key] = newKey;
        }
        else{
            cache[key] -> val = value;
            removeNode(cache[key]);
            
            insertAtHead(cache[key]);
        }
    }
};
