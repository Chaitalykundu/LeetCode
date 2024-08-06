class Solution {
public:

    int minimumPushes(string word) 
    {
int *alphaDone;
alphaDone=(int *)calloc(26,sizeof(int));
priority_queue<int> pushes;
for(int i=0;i<word.size();i++)
{
int index=word[i]-97;
alphaDone[index]++;
}
for(int i=0;i<26;i++)
{
pushes.push(alphaDone[i]);
}
int totalPushes=0;
for(int i=0;i<26;i++)
{
if(i<8) totalPushes+=(pushes.top());
if(i<16 && i>=8) totalPushes+=(pushes.top()*2);
if(i<24 && i>=16) totalPushes+=(pushes.top()*3);
if(i<26 && i>=24) totalPushes+=(pushes.top()*4);
pushes.pop();
if(pushes.empty()) break;
}
free(alphaDone);
return totalPushes;
}
};