class MinStack{
    stack<int> s, st;
public:
    void push(int val){
        s.push(val);
        if(st.empty() || val <= st.top()) st.push(val);
    }
    void pop(){
        if(st.top() == st.top()) st.pop();
        s.pop();
    }
    int top(){ return s.empty() ? -1 : s.top(); }
    int getMin(){ return s.empty() ? -1 : st.top(); }
};