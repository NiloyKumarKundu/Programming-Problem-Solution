#include <iostream>
#include <string>

using namespace std;

void pre_order(int bin_tree[], int sz, int nodeind){
    if(nodeind>=sz){
        return ;
    }
    else if(bin_tree[nodeind]==-1){
        return ;
    }
    else{
        cout<< bin_tree[nodeind] <<endl;

        pre_order(bin_tree, sz, 2*nodeind);

        pre_order(bin_tree, sz, 2*nodeind+1);
    }
}

void post_order(int bin_tree[], int sz, int nodeind){
    if(nodeind>=sz){
        return ;
    }
    else if(bin_tree[nodeind]==-1){
        return ;
    }
    else{
        post_order(bin_tree, sz, 2*nodeind);

        post_order(bin_tree, sz, 2*nodeind+1);

        cout<< bin_tree[nodeind] <<endl;
    }
}

int main()   ///CEO
{
    int bin_tree[]={-1,10,11,100,1,-1,4,12,-1,-1,-1,-1,-1,60,37,-1};
    int sz=sizeof(bin_tree)/sizeof(int);

    pre_order(bin_tree, sz, 1);
    cout<<"-------------------------------------"<<endl;
    post_order(bin_tree, sz, 1);

    return 0;
}