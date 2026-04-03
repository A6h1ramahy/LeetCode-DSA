


typedef struct {
    int *arr;
    int rear;
    int front;
    int capacity;
    int size;
} MyCircularDeque;


MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque* obj = malloc(sizeof(MyCircularDeque));
    obj->capacity = k;
    obj->arr = malloc(sizeof(int)*k);
    obj->rear = 0;
    obj->front = 0;
    obj->size = 0;
    for(int i=0; i<k; i++)
    {
        obj->arr[i] = -1;
    }
    return obj;
}

bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    if(obj->size < obj->capacity)
    {
        obj->size++;
        obj->front = (obj->front-1+obj->capacity)%obj->capacity;
        obj->arr[obj->front] = value;
        return true;
    }
    return false;
}

bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    if(obj->size < obj->capacity)
    {
        obj->size++;
        obj->arr[obj->rear] = value;
        obj->rear = (obj->rear+1)%obj->capacity;
        return true;
    }
    return false;
}

bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
    if(obj->size)
    {
        obj->size--;
        obj->arr[obj->front] = -1;
        obj->front = (obj->front+1)%obj->capacity;
        return true;
    }
    return false;
}

bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
        if(obj->size)
    {
        obj->size--;
        obj->rear = (obj->rear-1+obj->capacity)%obj->capacity;
        obj->arr[obj->rear] = -1;
        return true;
    }
    return false;
}

int myCircularDequeGetFront(MyCircularDeque* obj) {
    return obj->arr[obj->front];
}

int myCircularDequeGetRear(MyCircularDeque* obj) {
    return obj->arr[(obj->rear-1+obj->capacity)%obj->capacity];
}

bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
    if(obj->size) return false;
    return true;
}

bool myCircularDequeIsFull(MyCircularDeque* obj) {
    if(obj->size == obj->capacity)
    {
        return true;
    }
    return false;
}

void myCircularDequeFree(MyCircularDeque* obj) {
    free(obj->arr);
    free(obj);
}

/**
 * Your MyCircularDeque struct will be instantiated and called as such:
 * MyCircularDeque* obj = myCircularDequeCreate(k);
 * bool param_1 = myCircularDequeInsertFront(obj, value);
 
 * bool param_2 = myCircularDequeInsertLast(obj, value);
 
 * bool param_3 = myCircularDequeDeleteFront(obj);
 
 * bool param_4 = myCircularDequeDeleteLast(obj);
 
 * int param_5 = myCircularDequeGetFront(obj);
 
 * int param_6 = myCircularDequeGetRear(obj);
 
 * bool param_7 = myCircularDequeIsEmpty(obj);
 
 * bool param_8 = myCircularDequeIsFull(obj);
 
 * myCircularDequeFree(obj);
*/