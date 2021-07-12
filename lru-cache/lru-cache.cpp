class node{  
    public:
       int data;
       int key;
       node* prev;
       node* next;

       node(int k, int val){
           data = val;
           key = k;
           prev = NULL;
           next = NULL;
       }
};


class LRUCache {
public:
    
    node* head;
    node* tail;
    unordered_map<int, node*> m;
    int capa;
    int count;
    
    LRUCache(int capacity) {
        capa = capacity;
        count = 0;
        head = new node(-1, -1);
        tail = new node(-1, -1);
    }
    
    int get(int key) {
        if(m.find(key) != m.end()){
            node* temp = m[key];
            if(temp->prev != head){
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                temp->next = head->next;
                head->next->prev = temp;
                temp->prev = head;
                head->next = temp;
            }
            return temp->data;
        }
        else return -1;
    }
    
    void put(int key, int value) {
        //cout << key << endl;
        if(m.find(key) != m.end()){
            node* temp = m[key];
            if(temp->prev != head){
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                temp->next = head->next;
                head->next->prev = temp;
                temp->prev = head;
                head->next = temp;
            }
            temp->data = value;
        }else{
            if(count == 0){
                node* temp2 = new node(key, value);
                m[key] = temp2;
                head->next = temp2;
                tail->prev = temp2;
                temp2->prev = head;
                temp2->next = tail;
            }else{
                if(count == capa){
                    node* temp3;
                    temp3 = tail->prev;
                    temp3->prev->next = tail;
                    tail->prev = temp3->prev;
                    m.erase(temp3->key);
                    delete(temp3);
                    count--;
                }
                node* temp1 = new node(key, value);
                m[key] = temp1;
                temp1->next = head->next;
                head->next->prev = temp1;
                temp1->prev = head;
                head->next = temp1;
            }
            count++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */