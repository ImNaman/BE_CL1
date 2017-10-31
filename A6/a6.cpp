#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

int main()
{

int n;
cout<<"Enter no. of elements"<<endl;
cin>>n;
double x[n],y[n];

cout<<"Enter elements"<<endl;
for(int i=0;i<n;i++)
{
        cin>>x[i]>>y[i];
}

int clusters;
cout<<"Enter number of clusters"<<endl;
cin>>clusters;

vector<double> *means;
means = new vector<double>[2];

cout<<"Enter cluster means"<<endl;
for(int i=0;i<clusters;i++)
{
        int meanx,meany;
        cin>>meanx>>meany;
        means[0].push_back(meanx);
        means[1].push_back(meany);
}

vector<double> *prevmeans;
prevmeans = new vector<double>[2];

vector<int> *clusteritems;
clusteritems = new vector<int>[n];

int redo=1;
while(redo)
{
        cout<<"iteration"<<redo<<endl;
        
        prevmeans[0] = means[0];
        prevmeans[1] = means[1];
        
        for(int i=0;i<clusters;i++)
        {
                clusteritems[i].erase(clusteritems[i].begin(),clusteritems[i].end());
        }
        
        for(int i=0;i<n;i++)
        {
                double temp,min=99999;
                int pos=0;
                
                for(int j=0;j<clusters;j++)
                {
                        temp= sqrt(pow((x[i]-means[0][j]),2)+pow((y[i]-means[1][j]),2));
                        
                        if(temp<min)
                        {
                                min=temp;
                                pos=j;
                        }
                }
                
                clusteritems[pos].push_back(i); //storing only indexes in clusteritems
        }
        
        for(int i=0;i<clusters;i++)
        {
                double sumx=0,sumy=0;
                for(int j=0;j<clusteritems[i].size();j++)
                {
                        sumx += x[clusteritems[i][j]];
                        sumy += y[clusteritems[i][j]];
                }
                
                means[0][i] = sumx/clusteritems[i].size();
                means[1][i] = sumy/clusteritems[i].size();
        }
        
        if(prevmeans[0]==means[0] && prevmeans[1]==means[1])
        {
                redo=0;
        }
        
        else
        {
        redo++;
        }
}

for(int i=0;i<clusters;i++)
{
        cout<<"Cluster"<< i+1 <<endl;
        cout<<"Cluster mean: "<<means[0][i]<<" "<<means[1][i]<<endl;
        cout<<"Cluster items"<<endl;
        for(int j=0;j<clusteritems[i].size();j++)
        {
                cout<<x[clusteritems[i][j]]<<" "<<y[clusteritems[i][j]]<<endl;
        }
}
return 0;
}
