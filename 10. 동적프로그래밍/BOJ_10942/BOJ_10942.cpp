#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
const int MAX = 2000+1;
int N,S,E,M;

int arr[MAX];
bool cache[MAX][MAX];

void find(){
    for (int i = 1; i <=N; i++)
    {
        cache[i][i] = true;
    }
    for (int i = 1; i <N; i++)
    {
        if(arr[i]==arr[i+1]){
            cache[i][i+1] = true;
        }
    }
    for (int i = 2; i < N; i++)
    {
        for (int j = 1; j <=N-i; j++)
        {
            if(arr[j]==arr[j+i]&&cache[j+1][j+i-1]){
                cache[j][j+i]=true;
            }
        }
        
    }
}

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }
    memset(cache, 0, sizeof(cache));
    find();
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int S, E;
        scanf("%d %d", &S, &E); 
        printf("%d\n", cache[S][E]);
    }
    return 0;
}
