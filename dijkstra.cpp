#include<iostream>
#include<queue>
using namespace std;
int arr[5][5]={{0,10,0,5,0},{0,0,1,2,0},{0,0,0,0,4},{0,3,9,0,2},{7,0,6,0,0}};
priority_queue< <int>,vector<int>,greater<int> > q;
int main()
{
    int v;
    cout<<"enter njumber of vertices\n";
    cin>>v;
    int key[v],i,j;
    bool visited[v];
    for(i=0;i<v;i++)
    {
        key[i]=INT_MAX;
        visited[i]=false;
    }
    key[0]=0;
    int p=1;
    int min=key[0];
    while(p)
    {
        int l=0;
        for(i=0;i<v;i++)
        {
            cout<<key[i]<<" ";
            if(visited[i]==false)
            {
                l=1;
            }
        }
        cout<<"\n";
        if(l==0)
        {
            p=0;
            break;
        }

        for(i=0;i<v;i++)
        {
            if(key[i]<min && visited[i]==false)
            {
                min=i;
            }
        }
        cout<<min<<" L "<<endl;
        visited[min]=true;
        for(j=0;j<v;j++)
        {
            if(arr[min][j]!=0)
            {
                if(key[j]>key[min]+arr[min][j])
                {
                    key[j]=key[min]+arr[min][j];
                }
                if(key[j]<min)
                {
                    min=key[j];
                }
            }
        }
    }
    for(i=1;i<v;i++)
    {
        cout<<key[i]<<endl;
    }

}
