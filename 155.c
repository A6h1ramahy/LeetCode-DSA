


typedef struct {
    int stack[30000];
    int mstack[30000];
    int top;
} MinStack;


MinStack* minStackCreate() {
    MinStack* s = malloc(sizeof(MinStack));
    s->top = -1;
    return s;
}

void minStackPush(MinStack* obj, int value) {
    obj->top++;
    obj->stack[obj->top] = value;
    if(!obj->top)
    {
        obj->mstack[obj->top] = value;
    }
    else
    {
        int min = obj->mstack[obj->top-1];
        if(value<min)
        {
            obj->mstack[obj->top] = value;
        }
        else
        {
            obj->mstack[obj->top] = min;
        }
    }
}

void minStackPop(MinStack* obj) {
    obj->top--;
}

int minStackTop(MinStack* obj) {
    return obj->stack[obj->top];
}

int minStackGetMin(MinStack* obj) {
    return obj->mstack[obj->top];
}

void minStackFree(MinStack* obj) {
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, value);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
