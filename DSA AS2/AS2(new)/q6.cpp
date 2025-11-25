#include <bits/stdc++.h>
using namespace std;

struct Triplet{ int i,j,val; };
class SparseMatrix{
public:
    int rows,cols;
    vector<Triplet> triplets;
    SparseMatrix(int r,int c):rows(r),cols(c){}
    void add(int i,int j,int val){ if(val!=0) triplets.push_back({i,j,val}); }
    SparseMatrix transpose(){
        SparseMatrix t(cols,rows);
        for(auto &x:triplets) t.add(x.j,x.i,x.val);
        return t;
    }
    SparseMatrix add(SparseMatrix &other){
        SparseMatrix res(rows,cols);
        res.triplets=triplets;
        for(auto &x:other.triplets) res.triplets.push_back(x);
        return res;
    }
    SparseMatrix multiply(SparseMatrix &other){
        SparseMatrix res(rows,other.cols);
        for(auto &a:triplets)
            for(auto &b:other.triplets)
                if(a.j==b.i) res.add(a.i,b.j,a.val*b.val);
        return res;
    }
};

int main(){
    SparseMatrix sp(3,3);
    sp.add(0,0,1); sp.add(0,2,2); sp.add(2,1,3);

    SparseMatrix t=sp.transpose();
    cout<<"Transpose Triplets:"<<endl;
    for(auto &x:t.triplets) cout<<x.i<<" "<<x.j<<" "<<x.val<<endl;

    SparseMatrix sp2(3,3);
    sp2.add(0,0,2); sp2.add(0,2,1); sp2.add(2,1,4);

    SparseMatrix sum=sp.add(sp2);
    cout<<"Addition Triplets:"<<endl;
    for(auto &x:sum.triplets) cout<<x.i<<" "<<x.j<<" "<<x.val<<endl;

    SparseMatrix prod=sp.multiply(sp2);
    cout<<"Multiplication Triplets:"<<endl;
    for(auto &x:prod.triplets) cout<<x.i<<" "<<x.j<<" "<<x.val<<endl;

    return 0;
}
