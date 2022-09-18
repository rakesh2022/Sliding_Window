#include<bits/stdc++.h>

vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    vector<int>res;
    list<int>l;
    int i=0,j=0;
    int n=A.size();
    while(j<n){
        if(l.empty()){
            l.push_back(A[j]);
        }
        else{
            while(!l.empty() && l.back()<A[j]){
                l.pop_back();
            }
            l.push_back(A[j]);
        }
        if(j-i+1<B) j++;
        else if(j-i+1==B){
            res.push_back(l.front());
            if(l.front()==A[i]) l.pop_front();
            i++;
            j++;
        }
    }
    return res;
}
