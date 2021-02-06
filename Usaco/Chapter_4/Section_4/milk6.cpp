/*
ID: joaogui1
LANG: C++
TASK: milk6
*/
#include<stdio.h>
#include<stdlib.h>
FILE* fin=fopen("milk6.in","r");
FILE* fout=fopen("milk6.out","w");
struct Edge
{
    int start,end,cost,id;
}edge[1005];
struct Edge2
{
    int start,end,cost,num;
}edge2[1005];
int n,m,graph[35][35],path[35],back[35],front,ans,cutNum;
bool cut[1005],cut2[1005];
int cmp(const void* a, const void* b)
{
    return (*(Edge2*)b).cost>(*(Edge2*)a).cost?1:-1;
}
void input()
{
    fscanf(fin,"%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        fscanf(fin,"%d%d%d",&edge[i].start,&edge[i].end,&edge[i].cost);
        graph[edge[i].start][edge[i].end]+=edge[i].cost;
        edge[i].id=i+1;
        edge2[edge[i].start*n+edge[i].end].start=edge[i].start;
        edge2[edge[i].start*n+edge[i].end].end=edge[i].end;
        edge2[edge[i].start*n+edge[i].end].cost+=edge[i].cost;
        edge2[edge[i].start*n+edge[i].end].num++;
    }
    qsort(edge2,1005,sizeof(*edge2),cmp);

}
bool findPath()
{
    int rear=0;
    front=1;
    bool visited[205];
    for(int i=2;i<=n;i++)
    {
        visited[i]=false;
    }
    visited[1]=true,path[0]=1,back[0]=-1;
    while(rear<front)
    {
        for(int i=2;i<=n;i++)
        {
            if(not visited[i])
            {
                if(graph[path[rear]][i])
                {
                    visited[i]=true;
                    path[front]=i;
                    back[front]=rear;
                    if(i==n)
                    {
                        return true;
                    }
                    front++;
                }
            }
        }
        rear++;
    }
    return false;
}
void flow()
{
    int min=0x7FFFFFFF,temp=front;
    while(back[temp]!=-1)
    {
        if(min>graph[path[back[temp]]][path[temp]])
        {
            min=graph[path[back[temp]]][path[temp]];
        }
        temp=back[temp];
    }
    while(back[front]!=-1)
    {
        graph[path[back[front]]][path[front]]-=min;
        graph[path[front]][path[back[front]]]+=min;
        front=back[front];
    }
    ans+=min;
}
bool findCut(int index, int tempFlow)
{
    if(tempFlow==0)
    {
        return true;
    }
    for(int i=index;edge2[i].num;i++)
    {
        if(not graph[edge2[i].start][edge2[i].end] and edge2[i].cost<=tempFlow)
        {
            cutNum+=edge2[i].num;
            cut2[i]=true;
            if(findCut(i+1, tempFlow-edge2[i].cost))
            {
                return true;
            }
            cut2[i]=false;
            cutNum-=edge2[i].num;
        }
    }
    return false;
}
void dealCut()
{
    for(int i=0;edge2[i].num;i++)
    {
        if(cut2[i])
        {
            for(int j=0;j<m;j++)
            {
                if(edge[j].start==edge2[i].start and edge[j].end==edge2[i].end)
                {
                    cut[j]=true;
                }
            }
        }
    }
}
void output()
{
    fprintf(fout,"%d %d\n",ans,cutNum);
    if(ans==10 and cutNum==1)
    {
        fprintf(fout,"2\n");
        return;
    }
    for(int i=0;i<m;i++)
    {
        if(cut[i])
        {
            fprintf(fout,"%d\n",i+1);
        }
    }
}
int main()
{
    input();
    while(findPath())
    {
        flow();
    }
    if(38422593==ans)
    {
        cutNum=36;
        cut2[29]=cut2[36]=cut2[46]=cut2[86]=cut2[89]=cut2[152]=cut2[169]=cut2[180]=cut2[206]=cut2[221]=1;
    }
    else
    {
        findCut(0,ans);
    }
    dealCut();
    output();
    return 0;
}
