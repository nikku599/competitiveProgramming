#include <iostream>

using namespace std;
#include<iostream>
#include<vector>


static int rowNbr[] = {-1, 1, 0, 0}; 
static int colNbr[] = {0, 0, 1, -1};


//To check if the index is an eligible index for our cake
bool iseligible(char** cake, int x, int y, int** visited, int n)
{
    if(x<0 || x>=n || y<0 || y>=n|| visited[x][y] == 1 || cake[x][y] == '0' ){
        return 0;
    }
    else
        return 1; 
}

//Returns the maximum peice of cake that can be taken starting from x,y
int solver(int n, char** cake, int** visited, int x, int y){
    int sum=0;
    
    for(int k=0;k<4;k++){
        if(iseligible(cake,x+rowNbr[k], y+colNbr[k], visited, n)){

            visited[x+rowNbr[k]][y+colNbr[k]]=1;
            sum=sum+solver(n, cake, visited, x+rowNbr[k], y+colNbr[k]);
        }
    }
    return 1+sum;
}


//passes index of each one to solver as starting point and returns max of all 
int solve(int n,char** cake)
{
    int** visited = new int*[n];
    for(int i=0;i<n;i++){
        visited[i]=new int[n];
        for(int j=0;j<n; j++){
            visited[i][j]=0;
        }
    }
    
    int count=-999999;
    int result=0;
    for(int i=0;i<n;i++){

        for(int j=0;j<n;j++){

            if(iseligible(cake, i, j, visited, n)){

                //cout << i << " " << j << endl;
                visited[i][j]=1;
                result = solver(n, cake, visited, i, j);

                count = max(result, count);
            }
        }
    }
    
    return count;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        char** cake = new char*[n];
        for(int i=0;i<n;i++){
            cake[i] = new int[n];
        }
        for(int i=0;i<n;i++){
            string str;
            cin >> str;
            strcpy(cake[i], str.c_str());
        }
        cout << solve(n, cake) << endl;
    }
}