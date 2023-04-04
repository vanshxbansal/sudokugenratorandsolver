#include <bits/stdc++.h>
using namespace std;

void inputsudoku(vector<vector<int>>&a)
{
    cout<<"enter sudoku:\n";
    int temp;
for(int i=0;i<9;i++)
{
    vector<int> b;
    for(int j=0;j<9;j++)
    {
        cin>>temp;
       b.push_back(temp);
    }
    a.push_back(b);
}
}
void printsudoku(vector<vector<int>> a)
{
    int box=0;
    for(int i=0;i<9;i++)
    {
        box=0;
    for(int j=0;j<9;j++)
    {
        box++;
        if(a[i][j]==0)
        {
            if(box%3==0)
            {
                cout<<"_|";
            }
            else{
                cout<<"_ ";
            }
            
        }
        else{
           if(box%3==0)
           {
             cout<<a[i][j]<<"|";
           }
           else{
             cout<<a[i][j]<<" ";
           }
        }
    }if((i+1)%3==0)
    {
        cout<<"\n";
    }
    cout<<"\n";
    }
}
bool check(vector<vector<int>>&a,int row ,int col,int val)
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(a[row][i]==val||a[i][col]==val)
            {
                return false;
            }
            if(a[3*(row/3)+i/3][3*(col/3)+i%3]==val)
            {
                return false;
            }
        }
    }
    return true;
}
bool sudokusolver(vector<vector<int>>&a )
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(a[i][j]==0)
            {
                for(int val=1;val<=9;val++)
                {
                    if(check(a,i,j,val))
                    {
                        a[i][j]=val;
                        bool nextsol=sudokusolver(a);
                        if(nextsol)
                        {
                            return true;
                        }
                        else{
                            a[i][j]=0;
                        }

                    }

                }
                return false;
            }
        }
    }
    return true;
}
void solvesudoku(vector<vector<int>> &arr)
{
    sudokusolver(arr);
}
void fillsudoku(vector<vector<int>> &arr)
{
     int irand;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            irand=(rand()%9);
            if(arr[i][j]==0)
            {
                 if(check(arr,i,j,irand))
                {
                 arr[i][j]=irand;
                }
            }
            
        }
    }
}
void genratesudok(vector<vector<int>> &arr)

{
    vector<int>temp;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            temp.push_back(0);
        }
        arr.push_back(temp);
    }
        for(int i=0;i<=1;++i)
        {
            fillsudoku(arr);
        }

}
void removeelement(vector<vector<int>> &arr,int level)
{
    srand(time(NULL));
    srand(time(NULL));
     int irand;
     int jrand;
    while(level!=0)
    {
        irand=(rand()%9);
        jrand=(rand()%9);
        if(arr[irand][jrand]!=0)
        {
            level--;
            arr[irand][jrand]=0;
        }
    }
}
void genratesudoku(vector<vector<int>> &arr,int level)
{
    vector<int> temp;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            temp.push_back(0);
        }
        arr.push_back(temp);
    }
    solvesudoku(arr);
    removeelement(arr,level);

}
int main()
{
    srand(time(NULL));
    vector<vector<int>> arr;
    int ans;
    cout<<"\n\t press 1 for entering sudoku question:\n";
    cout<<"\n\t press 2 for random sudoku question:\n";
    cin>>ans;
    if(ans==1)
    {
        inputsudoku(arr);
        printsudoku(arr);
        solvesudoku(arr);
        printsudoku(arr);
    }
    else if(ans==2)
    {
        int level;
        cout<<"choose difficulty level \n";
        cout<<"1:Hard\n";
        cout<<"2:medium\n";
        cout<<"3:easy\n";
        cin>>level;
        if(level==1)
        {
            level=50;
        }
        else if(level==2)
        {
            level=30;
        }
        else{
            level=20;
        }
        genratesudoku(arr,level);
        printsudoku(arr);
        cout<<"\n\t do you want ans of above sudoku: (1 for yes 2 for no)";
        int checks;
        cin>>checks;
        if(checks==1)
        {
            solvesudoku(arr);
            printsudoku(arr);
        }

    }
   
    return 0;
}