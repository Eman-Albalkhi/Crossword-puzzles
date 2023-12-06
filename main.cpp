#include<bits/stdc++.h>
using namespace std;
typedef vector<string>vs;
typedef vector< pair<int,string> >vp;
set<int>IM;
vs board;
vp row,col,wr,wc,temp;
int n,m,r,sz,counter;
string s,t1,t2;
void set_col(int i,int j,vs &board,string word)
{
    for(int k=0; k<word.size(); k++)
    {
        if(word[k] == board[i+k][j] || board[i+k][j]=='#')
        {
            board[i+k][j]=word[k];
        }
        else return ;
    }
}
void set_row(int i,int j,vs &board,string word)
{
    for(int k=0; k<word.size(); k++)
    {
        if(word[k] == board[i][j+k] || board[i][j+k]=='#')
        {
            board[i][j+k]=word[k];
        }
        else return;
    }
}
void pr(vs board,int n,int m)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            cout<<board[i][j];
        cout<<endl;
    }
}

int main()
{
    cin>>n>>m;
    for(int j=0; j<m; j++)
        s+="#";
    for(int i=0; i<n; i++)
    {
        board.push_back(s);
    }
    for(int i=0; i<n; i++)
    {
        int k;
        cin>>k;
        while(k--)
        {
            cin>>s;
            if(s.size()<=m)
                row.push_back(make_pair(i+1,s));
        }
    }
    for(int i=0; i<m; i++)
    {
        int k;
        cin>>k;
        while(k--)
        {
            cin>>s;
            if(s.size()<=n)
                col.push_back(make_pair(i+1,s));
        }
    }

    r=1;
    for(int i=0; i<row.size(); i++)
    {
        counter=0;
        t2="";
        if(r == row[i].first)
        {
            t1=row[i].second;
        }
        else
            break;

        for(int k=0; k<t1.size(); k++)
        {
            for(int j=0; j<col.size(); j++)
            {
                if(k+1 == col[j].first)
                {
                    t2=col[j].second;
                    if(t1[k] == t2[r-1])
                    {
                        temp.push_back(col[j]);
                    }
                }
            }
            if(temp.size()-counter>=1)
            {
                counter=temp.size();
            }
            else
            {
                temp.clear();
                break;
            }
        }
        if(temp.size()>=m)
        {
            for(int ii=0; ii<temp.size(); ii++)
            {
                wc.push_back(temp[ii]);
                IM.insert(temp[ii].first);
            }
        }
        temp.clear();
    }

    if( IM.size()< m)
    {
        cout<<"IMPOSSIPL"<<endl;
        return 0;
    }

    IM.erase(IM.begin(),IM.end());
    for(int i=0; i<row.size(); i++)
    {
        counter=0;
        sz=-1;

        r=row[i].first;
        t1=row[i].second;
        sz=t1.size();

        for(int j=0; j<sz; j++)
        {
            for(int k=0; k<wc.size(); k++)
            {
                if(j+1 == wc[k].first)
                {
                    t2=wc[k].second;
                    if(t2[r-1] == t1[j] ||t2[r-1]=='\0')
                        temp.push_back(wc[k]);
                }
            }
            if(temp.size()-counter>=1)
            {
                counter=temp.size();
            }
            else
            {
                temp.clear();
                break;
            }
        }
        if(temp.size()>=sz)
        {
            wr.push_back(row[i]);
            IM.insert(row[i].first);
        }
        temp.clear();
    }

    if(IM.size()< n)
    {
        cout<<"IMPOSSIPL"<<endl;
        return 0;
    }

    for(int i=0; i<wr.size(); i++)
    {
        set_row(wr[i].first-1,0,board,wr[i].second);
    }
    for(int i=0; i<wc.size(); i++)
    {
        set_col(0,wc[i].first-1,board,wc[i].second);
    }
    cout<<endl;
    pr(board,n,m);
    return 0;
}
