#include <iostream>
using namespace std;
class Partiton
{
public:
    int ProcessNo,PartitionRequired,InternalFragmnent,flag= false,MemoryAssign;
    Partiton()
    {
        ProcessNo=0;
        PartitionRequired=0;
        InternalFragmnent=0;
        MemoryAssign=-1;
        flag= false;
    }
    void Init(int i);
};
void Partiton::Init(int i)
{
    ProcessNo=i;
    cout<<"\n Enter P["<<i<<"] Partition Size : ";
    cin>>PartitionRequired;
    flag= false;
    MemoryAssign=-1;
}
Partiton Internal(Partiton P[],int M[],int I[],int S,int PS)
{
    for(int i=0;i<S;i++)
    {
        if (P[i].flag== false) {
            for (int j = 0; j < PS; ++j)
            {
                if (M[j] >= P[i].PartitionRequired) {
                    P[i].InternalFragmnent = M[j] - P[i].PartitionRequired;
                    //P[i].MemoryAssign = j;
                    P[i].MemoryAssign=I[j];
                    P[i].flag = true;
                    M[j] = 0;
                    break;
                }
            }

        }
    }
    return *P;
}
Partiton Print(Partiton P[],int S)
{
    cout<<"Process No."<<"      "<<"Partition Allocated"<<"      "<<"Internal Fragmentation"<<endl;
    for(int i=0;i<S;i++)
    {
        cout<<"      ";
        cout<<P[i].ProcessNo<<"\t";
        cout<<"\t   \t";
        if(P[i].MemoryAssign!=-1)
        {
            cout<<P[i].MemoryAssign<<"\t";
            cout<<" \t   \t";
            cout<<P[i].InternalFragmnent<<"\t";
            cout<<"      ";
        }
        else
        {
            cout<<"No Allocation"<<"\t";
        }
        cout<<endl;

    }
    return *P;
}
void Sort(int Memory[],int Index[],int N)
{
    for(int i=0;i<N;i++)
    {
        for(int j=1;j<N;j++)
        {
            if(Memory[i]<Memory[j])
            {
                int M1=Memory[i];
                int I1=Index[i];
                Memory[i]=Memory[j];
                Index[i]=Index[j];
                Memory[j]=M1;
                Index[j]=I1;
            }
        }
    }
}
int main() {
    int N,TP;
    cout<<"Enter Number of Free Partition : ";
    cin>>N;
    int Memory[N];
    int Index[N];
    for(int i=0;i<N;i++)
    {
        cout<<"\n Enter P["<<i<<"] Partition Size:";
        cin>>Memory[i];
        Index[i]=i;
    }
    Sort(Memory,Index,N);
    cout<<"\n Enter Number of Process : ";
    cin>>TP;
    Partiton P[TP];
    for(int i=0;i<TP;i++)
    {
        P[i].Init(i);
    }
    Internal(P,Memory,Index,TP,N);
    Print(P,TP);
    return 0;
}
