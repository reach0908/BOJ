#include <iostream>
#include <cstring>

using namespace std;
const int MAX = 100;
int N,L;
int board[MAX][MAX];
int board2[MAX][MAX];

bool Can_Make_Road(int A[][MAX],int x,int y){
    int standard = A[x][y+1];
    for (int i = y+1; i < y+1+L; i++)
    {
        if(A[x][i]!=standard){
            return false;
        }
    }
    return true;
}

int Make_Road(int A[][MAX]){
    int Total_Road =0;
    for (int i = 0; i < N; i++)
    {
        bool Can_Road = true;
        int Before_Road=1;
        for (int j = 0; j < N-1; j++)
        {
            if(A[i][j]==A[i][j+1]){
                Before_Road++;
            }
            else if(A[i][j]==A[i][j+1]+1){
                if(Can_Make_Road(A,i,j)==true){
                    j=j+L-1;
                    Before_Road=0;
                }else{
                    Can_Road=false;
                    break;
                }
            }
            else if(A[i][j]+1==A[i][j+1]){
                if(Before_Road>=L){
                    Before_Road=1;
                }else
                {
                    Can_Road=false;
                    break;
                }
            }
            else if(abs(A[i][j]-A[i][j+1])>=2){
                Can_Road=false;
                break;
            }
        }
        if(Can_Road==true){
            Total_Road++;
        }
    }
    return Total_Road;
}
void solution(){
    int A = Make_Road(board);
    int B = Make_Road(board2);

    cout << A+B << endl;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> L;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
            board2[j][i] = board[i][j];
        }
    }
    solution();
    return 0;
}

