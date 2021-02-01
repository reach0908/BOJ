#include <iostream>

using namespace std;
const int MAX = 10;

int S;
string N;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> S >> N;

    for (int h = 0; h < 2*S+3; h++)
    {
        for (int i = 0; i < N.length(); i++)
        {
            if(h==0){
                if (N[i] == '0' || N[i] == '2' || N[i] == '3' || N[i] == '5' 
                || N[i] == '6' || N[i] == '7' || N[i] == '8' || N[i] == '9'){
                    cout << " ";
                    for (int j = 0; j < S; j++)
                    {
                        cout << "-";
                    }
                    cout << " ";
                }else{
                    for (int j = 0; j < S+2; j++)
                    {
                        cout << " ";
                    }
                    
                }
            }
            else if(1<=h&&h<=S){
                if (N[i] == '0' || N[i] == '4' 
                ||  N[i] == '8' || N[i] == '9'){
                    cout << "|";
                    for (int j = 0; j < S; j++)
                    {
                        cout <<" ";
                    }
                    cout << "|";
                }else if(N[i] == '1' || N[i] == '2' 
                ||  N[i] == '3' || N[i] == '7'){
                    for (int j = 0; j < S+1; j++)
                    {
                        cout << " ";
                    }
                    cout << "|";
                }else{
                    cout << "|";
                    for (int j = 0; j < S+1; j++)
                    {
                        cout << " ";
                    }
                }
            }
            else if(h==S+1){
                if(N[i] == '0' || N[i] == '1' 
                ||  N[i] == '7'){
                    for (int j = 0; j < S+2; j++)
                    {
                            cout << " ";
                    }
                }
                else{
                    cout << " ";
                    for (int j = 0; j < S; j++)
                    {
                        cout << "-";
                    }
                    cout << " ";
                }
            }
            else if(S+2<=h&&h<=2*S+1){
                if(N[i] == '0' || N[i] == '6' 
                ||  N[i] == '8'){
                    cout << "|";
                    for (int j = 0; j < S; j++)
                    {
                            cout << " ";
                    }
                    cout << "|";
                }
                else if(N[i] == '1' || N[i] == '3' 
                ||  N[i] == '4'||  N[i] == '5'||  N[i] == '7'||  N[i] == '9'){
                    for (int j = 0; j < S+1; j++)
                    {
                        cout << " ";
                    }
                    cout << "|";
                }else{
                    cout << "|";
                    for (int j = 0; j < S+1; j++)
                    {
                        cout << " ";
                    }
                    
                }
            }
            else{
                if(N[i] == '1' || N[i] == '4' 
                ||  N[i] == '7'){
                    for (int j = 0; j < S+2; j++)
                    {
                        cout << " ";
                    }
                }else{
                    cout << " ";
                    for (int j = 0; j < S; j++)
                    {
                        cout << "-";
                    }
                    cout << " ";
                }
            }
            cout << " ";
        }
        cout << endl;
    }
    return 0;
}
