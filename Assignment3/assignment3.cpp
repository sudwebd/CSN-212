#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <complex>
#define MAX_N 5001
#define MAX_E 25000001
#define INF 987654321
using namespace std;
typedef long long lld;

int v, e;

int dist[MAX_N];
struct Edge
{
    int src, dst, weight;
};
Edge E[MAX_N];
inline int BellmanFord(int source)
{
    for (int i=0;i<v;i++)
    {
        if (i == source) dist[i]=0;
        else dist[i] = INF;
    }
    bool done = false;
    for (int i=0;!done&&i<v;i++)	
    {
        done = true;
        for (int j=0;j<e;j++)
        {
            int so = E[j].src;
            int de = E[j].dst;
            if (dist[so] + E[j].weight < dist[de])
            {
                dist[de] = dist[so] + E[j].weight;
                done=false;
            }
        }
    }
    if (!done) return -1;
    return 0;
}
void prog()
{
	while(1)
	{
		if (getchar())
			break;
	}
	printf("prog() ends \n");
}

int main()
{
	cin>>v>>e;
    for(int j=0;j<e;j++){
    	cin>>E[j].src>>E[j].dst>>E[j].weight;
    }
    
    BellmanFord(0);
    for(int i=0;i<v;i++){
    cout<<i<<" "<<dist[i]<<endl;    }
	clock_t t;
	t = clock();
	prog();
	t = clock() - t;
	double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds

	printf("prog() took %f seconds to execute \n", time_taken);
    return 0;
}