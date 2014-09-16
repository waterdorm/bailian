#include <stdio.h>

enum MenPai
{
    WuDang =0,
    ShaoLin =1,
    EMei =2,
};

enum Direction
{
    Forward = 0,
    Back = 1,
};

double nx[3] = {0.8,0.5,0.2};
double wx[3] = {0.2,0.5,0.8};
typedef struct item2
{
    int x,y;
}Position;

typedef struct item4
{
    int person;
    int life;
}Result;

typedef struct item
{
    MenPai mp;
    int neili;
    int wuyi;
    int life;
    double attack;
    Direction d;
    bool still;
    struct item*next;
}Person,*LPerson;

typedef struct item3
{
    LPerson head;
    int count;
}T;
T t[12][12];

Position pos[3][2] = {0,1,0,-1,1,0,-1,0,1,1,-1,-1}; 

void Init()
{
    for(int i = 0;i < 12;i++)
        for(int j = 0;j < 12;j++)
        {
            t[i][j].count = 0;
            t[i][j].head = NULL;
        }
}

void AddPerson(char* tf)
{
    char dh;
    int row,col;
    int neili,wuyi,life;

    sscanf(tf,"%c%d%d%d%d%d",&dh,&row,&col,&neili,&wuyi,&life);

    LPerson p = new Person;
    p->next = NULL;
    p->life = life;
    p->neili = neili;
    p->wuyi = wuyi;
    p->d = Forward;
    p->still = false;
    switch(dh)
    {
    case 'S':
        p->mp = ShaoLin;
        p->attack = (0.5*neili + 0.5*wuyi)*(life+10)/100;
        break;
    case 'W':
        p->mp = WuDang;
        p->attack = (0.8*neili + 0.2*wuyi)*(life+10)/100;
        break;
    case 'E':
        if((row == 12 && col == 1) || (row == 1 && col == 12))
            p->still = true;
        p->mp = EMei;
        p->attack = (0.8*neili + 0.2*wuyi)*(life+10)/100;
        break;
    }
    t[row-1][col-1].count++;
    if(t[row-1][col-1].head == NULL)
    {
        t[row-1][col-1].head = p;
    }
    else
    {
        p->next = t[row-1][col-1].head->next;
        t[row-1][col-1].head->next = p;
    }
    
}

void Attack()
{
    for(int i = 0;i<12;i++)
    {
        for(int j = 0;j < 12;j++)
        {
            if(t[i][j].count == 2)            //该方格有两人
            {
                LPerson p1 = t[i][j].head;
                LPerson p2 = p1->next;

                if(p1->mp != p2->mp)        //不是同一门派的，战斗
                {
                    p1->life -= (int)p2->attack;
                    p2->life -= (int)p1->attack;

                    if(p1->life <= 0)        //死了
                    {
                        t[i][j].count--;
                        t[i][j].head = p2;
                        delete p1;
                        p1 = NULL;
                    }
                    else
                        p1->attack = (nx[p1->mp]*p1->neili + wx[p1->mp]*p1->wuyi)*(p1->life + 10)/100;
                    if(p2->life <= 0)
                    {
                        t[i][j].count--;
                        t[i][j].head = p1;
                        delete p2;
                        p2 = NULL;
                    }
                    else
                        p2->attack = (nx[p2->mp]*p2->neili + wx[p2->mp]*p2->wuyi)*(p2->life + 10)/100;
                }
            }
        }
    }
}

void Move()
{
    int i,j;
    T temp[12][12];
    for(i = 0;i < 12;i++)
    {
        for(j = 0;j < 12;j++)
        {
            temp[i][j].count = 0;
            temp[i][j].head = NULL;
        }
    }
    
    for(i = 0;i < 12;i++)
    {
        for(j = 0;j < 12;j++)
        {
            if(t[i][j].count >0)  //有人才移动
            {
                LPerson p = t[i][j].head;
                LPerson q = p;
                while(q != NULL)
                {
                    p = q;
                    q = q->next; 
    
                    int r,c;
                    r = i+pos[p->mp][p->d].x;
                    c = j+pos[p->mp][p->d].y;
                    if( r < 0 || r >11 || c < 0 || c >11) //出界,往回走
                    {
                        int kk = !((int)p->d);
                        p->d = (Direction)kk;
                        r = i+pos[p->mp][p->d].x;
                        c = j+pos[p->mp][p->d].y;
                        if( r < 0 || r > 11 || c < 0 || c > 11) //只能呆住不动
                        {
                            r = i;
                            c = j;
                        }
                    }
                    temp[r][c].count++;
                    if(temp[r][c].head == NULL)
                    {
                        temp[r][c].head = p;
                        p->next = NULL;
                    }
                    else
                    {
                        p->next = temp[r][c].head->next; 
                        temp[r][c].head->next = p;
                    }
                }
            }

        }
    }

    Init();
    for(i = 0;i < 12;i++)
    {
        for(j = 0;j<12;j++)
        {
            if(temp[i][j].count > 0)
            {
                t[i][j].count = temp[i][j].count;
                t[i][j].head = temp[i][j].head;
            }
        }
    }
}

void Print()
{
    Result r[3];
    int i,j;
    for(i = 0;i < 3;i++)
    {
        r[i].life = 0;
        r[i].person = 0;
    }
    for(i = 0;i < 12;i++)
    {
        for(j = 0;j < 12;j++)
        {
            if(t[i][j].count > 0) // 有人
            {
                LPerson p = t[i][j].head;
                while(p)
                {
                    switch(p->mp)
                    {
                    case ShaoLin:
                        r[0].person++;
                        r[0].life += p->life;
                        break;
                    case WuDang:
                        r[1].person++;
                        r[1].life += p->life;
                        break;
                    case EMei:
                        r[2].person++;
                        r[2].life += p->life;
                        break;
                    }
                    p = p->next;
                }
            }
        }
    }
    for(i = 0;i < 3;i++)
        printf("%d %d\n",r[i].person,r[i].life);
    printf("***\n");
}
int main(int argc, char* argv[])
{
    int n;
    int m;
    char temp[30];
    
    scanf("%d",&n);
    while(n--)
    {
        Init();
        scanf("%d",&m);
        getchar();
        while(1)
        {
            gets(temp);
            if(temp[0] == '0')
                break;
            AddPerson(temp);
        }
        
        for(int i=0;i < m;i++)
        {
            Attack();
            Move();            //移动
        }
        Print();
    }
    return 0;
}
