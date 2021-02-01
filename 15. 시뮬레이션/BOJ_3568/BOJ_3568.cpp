#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    getline(cin,s);

    string init;
    vector<string> v;
    string temp;

    for (int i = 0; i < s.length(); i++)
    {
        if(s[i]==' '){
            init = temp;
            temp.clear();
            continue;
        }
        else if(s[i]==','){
            v.push_back(temp);
            i++;
            temp.clear();
        }else if(s[i]==';'){
            v.push_back(temp);
            temp.clear();
        }else{
            temp+=s[i];
        }
    }
    for (int i = 0; i < v.size(); i++)
    {
        int idx = -1;
        for (int j = 0; j < v[i].size(); j++)
        {
            if(!((v[i][j]>='a'&&v[i][j]<='z')||(v[i][j]>='A'&&v[i][j]<='Z'))){
                idx=j;
                break;
            }
        }
        cout << init;
        if(idx==-1){
            cout << " " << v[i];
        }else{
            //타입 출력
            for (int j = v[i].size()-1; j >=idx; j--)
            {
                if(v[i][j]==']'){
                    cout << "[]";
                    j--;
                    continue;
                }
                cout << v[i][j];
            }
            cout << " ";
            //변수명 출력
            for (int j = 0; j < idx; j++)
            {
                cout << v[i][j];
            }
        }
        cout << ";" << endl;
    }
    return 0;
}


