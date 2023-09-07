#include <iostream>
using namespace std;

int main() 
{
    int n;
    cout<<"Enter number of processes"<<endl;
    cin>>n;
    int bt[n];
    for (int i=0;i<n;i++)
    {
        cout<<"Enter Burst time of Process P"<<i+1<<endl;
        cin>>bt[i];
    }
    int t=0;
    int wt[n];
    int tt[n];
    int o[n];
    cout<<"Enter Process Order"<<endl;
    for (int i=0;i<n;i++)
    {
        cin>>o[i];
        o[i]--;
    }
    for (int i=0;i<n;i++)
    {
        if (i==0)
        {
            wt[o[i]]=0;
            tt[o[i]]=bt[o[i]];
        }
        else
        {
            wt[o[i]]=wt[o[i-1]]+bt[o[i-1]];
            tt[o[i]]=tt[o[i-1]]+bt[o[i]];
        }
        t+=bt[o[i]];
    }
    cout<<"Process Number \t Waiting Time \t Turnaround Time"<<endl;
    double w=0;
    for (int i=0;i<n;i++)
    {
        cout<<i+1<<"\t\t\t\t "<<wt[i]<<"\t\t\t\t "<<tt[i]<<endl;
        w+=wt[i];
    }
    cout<<"Avg Waiting Time : "<<w/n<<endl;
    cout<<"Total execution time : "<<t<<endl;
    return 0;
}
