#include<iostream>
using namespace std;
struct stack{
    int size;
    int top;
    int *s;
};

void create( stack *st){
    cout<<"enter size";
    cin>> st->size;
    st->top =-1;
    st->s = new int [st->size];
}

void display(stack st ){
    int i ;
    for(i = st.top;i>=0;i--){
        cout<< st.s[i]<<" ";
    }
}

void push(stack *st, int x){
     if(st->top == st->size-1) cout<<" overflow"<<" ";
     else 
     {
        st->top++;
        st->s[st->top] =x;
     }
}
int pop(stack * st){
    int x =-1;
    if(st->top ==-1) cout<<" underflow"<<" ";
    else{
        x = st->s[st->top];
        st->top--;
    }
    return x;
}
 int peek(stack st,int index){
    int x = -1;
    if(st.top-index+1 <0 )  cout<<"invalid";
    else x = st.s[st.top-index +1];
    return x;
 }

 int stacktop(stack st){
    if(st.top ==-1) return -1;
    else return st.s[st.top];
 }

int isEmpty(stack st){
    if(st.top ==-1) return 1;
    else return 0;
}

int isFull(stack st){
if(st.top == st.size-1) return 1;
else return 0;
}


int main(){
    struct stack st;
    create(&st);
    push(&st,10);
    push(&st,20);
    push(&st,30);
    push(&st,40);
   
    
    cout<< peek(st,1)<<" ";
    display(st);
}