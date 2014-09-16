#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define maxn 150
struct node
{
    char s[2];
    int x,y;
    int live;
    int dir;
    int ne,wu,hp;
}q[maxn];
int st[maxn];
bool cmp(node a,node b)
{
    if (a.live != b.live)
        return a.live<b.live;
    else if (a.x!=b.x)
        return a.x<b.x;
    else return a.y<b.y;
}
int cal(node x)
{
    if (x.s[0] == 'S')
        return (int)((0.5*x.ne+0.5*x.wu)*(x.hp+10.0)/100.0);
    if (x.s[0] == 'W')
        return (int)((0.8*x.ne+0.2*x.wu)*(x.hp+10.0)/100.0);
    if (x.s[0] == 'E')
        return (int)((0.2*x.ne+0.8*x.wu)*(x.hp+10.0)/100.0);
}
int m;
void move()
{
    int i;
    for (i=0; i<m; i++)
    {
        if (q[i].s[0] == 'S')
        {
            if (q[i].dir == 0)
            {
                if (q[i].x<12)
                    q[i].x++;
                else {
                    q[i].x--;
                    q[i].dir=1;
                }
            }
            else
            {
               if (q[i].x>1)
                   q[i].x--;
                else{
                    q[i].x++;
                    q[i].dir=0;
                }
            }
        }
        else if (q[i].s[0] == 'W')
        {
            if (q[i].dir == 0)
            {
                if (q[i].y<12)
                    q[i].y++;
                else{
                    q[i].y--;
                    q[i].dir =1;
                }
            }
            else{
                if (q[i].y>1)
                    q[i].y--;
                 else{
                     q[i].y++;
                     q[i].dir = 0;
                 }
            }
        }
        else {
            if ((q[i].x==1&&q[i].y==12)||(q[i].x==12&&q[i].y==1))
                continue;
            if (q[i].dir == 0)
            {
                if (q[i].x<12 && q[i].y<12)
                    q[i].x++,q[i].y++;
                else{
                    q[i].x--,q[i].y--;
                    q[i].dir = 1;
                }
            }
            else {
                if (q[i].x>1 && q[i].y>1)
                     q[i].x--,q[i].y--;
                else{
                    q[i].x++,q[i].y++;
                    q[i].dir = 0;
                }
            }
        }
    }
}
int main()
{
    int top = 0;
    int t;
    int n;
    int i,j,k;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&n);
        m = 0;
        while(scanf("%s",q[m].s),q[m].s[0]!='0')
        {
            q[m].dir = 0;
            q[m].live = 1;
            scanf("%d %d %d %d %d",&q[m].x,&q[m].y,&q[m].ne,&q[m].wu,&q[m].hp);
            m++;
        }

        while (n--)
        {
            top = 0;
            sort(q,q+m,cmp);
            for (i=0; i<m; i++)
            {
                if (q[i].live==0)
                    continue;
                st[top++] = i;
                if (i==m-1 || q[i].x!=q[i+1].x || q[i].y!=q[i+1].y)
                {
                    if (top==2 && q[st[0]].s[0]!=q[st[1]].s[0])
                    {
                            int ga = cal(q[st[0]]);
                            int gb = cal(q[st[1]]);
                            q[st[0]].hp -= gb;
                            q[st[1]].hp -= ga;
                            if (q[st[0]].hp <=0)
                                q[st[0]].live = 0;
                            if (q[st[1]].hp <=0)
                                q[st[1]].live = 0;
                    }
                    top = 0;
                }
            }
            move();
        }
        int sn=0,wn=0,en=0;
        int sh=0,wh=0,eh=0;
        for (i=0; i<m; i++)
        {
            if (q[i].hp<=0)
                continue;
            if (q[i].s[0]=='S')
            {
                sn++;
                sh+=q[i].hp;
            }
            else if (q[i].s[0]=='W')
            {
                wn++;
                wh+=q[i].hp;
            }
            else if (q[i].s[0]=='E')
            {
                en++;
                eh+=q[i].hp;
            }
        }
        printf("%d %d\n%d %d\n%d %d\n***\n",sn,sh,wn,wh,en,eh);
   }
    return 0;
}
