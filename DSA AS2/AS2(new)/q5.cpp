#include <bits/stdc++.h>
using namespace std;

class DiagonalMatrix {
    int n;
    vector<int> data;
public:
    DiagonalMatrix(int size) : n(size), data(size) {}
    void set(int i, int j, int val) { if(i==j) data[i]=val; }
    int get(int i, int j) { return i==j?data[i]:0; }
};

class TriDiagonalMatrix {
    int n;
    vector<int> data;
public:
    TriDiagonalMatrix(int size) : n(size), data(3*size-2) {}
    void set(int i, int j, int val){
        if(i-j==1) data[i-1]=val;
        else if(i-j==0) data[n-1+i-1]=val;
        else if(i-j==-1) data[2*n-1+i-1]=val;
    }
    int get(int i, int j){
        if(i-j==1) return data[i-1];
        if(i-j==0) return data[n-1+i-1];
        if(i-j==-1) return data[2*n-1+i-1];
        return 0;
    }
};

class LowerTriangularMatrix {
    int n;
    vector<int> data;
    int index(int i,int j){ return i>=j?(i*(i+1))/2+j:-1; }
public:
    LowerTriangularMatrix(int size): n(size), data(size*(size+1)/2) {}
    void set(int i,int j,int val){ int idx=index(i,j); if(idx!=-1) data[idx]=val; }
    int get(int i,int j){ int idx=index(i,j); return idx==-1?0:data[idx]; }
};

class UpperTriangularMatrix {
    int n;
    vector<int> data;
    int index(int i,int j){ return i<=j?(j*(j+1))/2+i:-1; }
public:
    UpperTriangularMatrix(int size): n(size), data(size*(size+1)/2) {}
    void set(int i,int j,int val){ int idx=index(i,j); if(idx!=-1) data[idx]=val; }
    int get(int i,int j){ int idx=index(i,j); return idx==-1?0:data[idx]; }
};

class SymmetricMatrix {
    int n;
    vector<int> data;
    int index(int i,int j){ return i>=j?(i*(i+1))/2+j:(j*(j+1))/2+i; }
public:
    SymmetricMatrix(int size): n(size), data(size*(size+1)/2) {}
    void set(int i,int j,int val){ data[index(i,j)]=val; }
    int get(int i,int j){ return data[index(i,j)]; }
};

int main(){
    DiagonalMatrix d(3);
    d.set(0,0,5); d.set(1,1,8); d.set(2,2,3);
    cout<<"Diagonal Matrix:"<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++) cout<<d.get(i,j)<<" ";
        cout<<endl;
    }

    TriDiagonalMatrix t(3);
    t.set(0,0,1); t.set(0,1,2); t.set(1,0,3); t.set(1,1,4); t.set(1,2,5); t.set(2,1,6); t.set(2,2,7);
    cout<<"Tri-Diagonal Matrix:"<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++) cout<<t.get(i,j)<<" ";
        cout<<endl;
    }

    LowerTriangularMatrix l(3);
    l.set(0,0,1); l.set(1,0,2); l.set(1,1,3); l.set(2,0,4); l.set(2,1,5); l.set(2,2,6);
    cout<<"Lower Triangular Matrix:"<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++) cout<<l.get(i,j)<<" ";
        cout<<endl;
    }

    UpperTriangularMatrix u(3);
    u.set(0,0,1); u.set(0,1,2); u.set(0,2,3); u.set(1,1,4); u.set(1,2,5); u.set(2,2,6);
    cout<<"Upper Triangular Matrix:"<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++) cout<<u.get(i,j)<<" ";
        cout<<endl;
    }

    SymmetricMatrix s(3);
    s.set(0,0,1); s.set(0,1,2); s.set(0,2,3); s.set(1,1,4); s.set(1,2,5); s.set(2,2,6);
    cout<<"Symmetric Matrix:"<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++) cout<<s.get(i,j)<<" ";
        cout<<endl;
    }
    return 0;
}
