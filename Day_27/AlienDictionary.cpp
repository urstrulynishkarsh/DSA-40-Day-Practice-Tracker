#include<iostream>
#include<queue>
#include<vector>
using namespace std;

string alien(vector<string> &words)
{
    vector<vector<int> >adj(26);
    vector<int> indegree(26,0);
    vector<bool> present(26,0);
    for(auto word:words)
    {
        for(auto ch:word)
        {
            present[ch-'a']=1;
        }
    }
    for(int i=0;i<words.size()-1;i++)
    {
        string word1=words[i];
        string word2=words[i+1];
        int len=min(word1.size(),word2.size());
        bool found=false;
        for(int j=0;j<len;j++)
        {
            if(word1[j]!=word2[j])
            {
                int u=word1[j]-'a';
                int v=word2[j]-'a';
                adj[u].push_back(v);
                indegree[v]++;
                found=true;
                break;
            }
        }
        if(!found && word1.size()>word2.size())
        {
            return "";
        }
    }



    queue<int> q;
    for(int i=0;i<26;i++)
    {
        if(present[i] && indegree[i]==0)
        {
            q.push(i);
        }
    }
    string ans;
    while(!q.empty())
    {
        int front=q.front();
        q.pop();
        ans.push_back(front+'a');
        for(auto nbr:adj[front])
        {
            indegree[nbr]--;
            if(indegree[nbr]==0)
            {
                q.push(nbr);
            }
        }
    }

    // check cycle
    int totalcharacters=0;
    for(int i=0;i<26;i++)
    {
        if(present[i])
        {
            totalcharacters++;
        }
    }
    if(ans.size()!=totalcharacters)
    {
        return "";
    }
    return ans;
}
int main()
{
     int n;

    cout << "Enter the size of words: ";
    cin >> n;

    vector<string> words(n);

    for(int i = 0; i < n; i++)
    {
        cin >> words[i];
    }
    cout<<alien(words);
}

