#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
using namespace std;
class tictoktie
{
private:
    int n;
    string **arr;

public:
    string name1, name2;
    tictoktie(int x, string n1, string n2)
    {
        n = x;
        name1 = n1;
        name2 = n2;
        arr = new string *[n];
        for (int i = 0; i < n; i++)
        {
            arr[i] = new string[n];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                arr[i][j] = "0";
            }
        }
    }
    void display();
    void insert(int x, int player);
    int chek_win();
    int check(int x);
    int tie();
};
int tictoktie::check(int x)
{
    if ((x >= n * n) || (x <= -1))
    {
        return 1;
    }

    int l = x / n, m = x % n;
    if (arr[l][m] != "0")
        return 1;
    else
        return 0;
}
int tictoktie::tie()
{
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == "0")
            {
                ans = 0;
            }
        }
    }
    return ans;
}
void tictoktie::insert(int x, int player)
{

    if (player == 1)
    {
        int i = x / n, j = x % n;
        arr[i][j] = "1";
    }
    else if (player == 2)
    {
        int i = x / n, j = x % n;
        arr[i][j] = "2";
    }
}
int tictoktie::chek_win()
{
    int j, i;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (arr[i][j] == "1")
            {
                continue;
            }
            else
            {
                break;
            }
        }
        if (j == (n))
        {
            printf("1->");
            return 1;
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (arr[j][i] == "1")
            {
                continue;
            }
            else
            {
                break;
            }
        }
        if (j == (n))
        {
            printf("2->");
            return 1;
        }
    }
    for (i = 0; i < n; i++)
    {
        if (arr[i][i] == "1")
        {
            continue;
        }
        else
            break;
    }
    if (i == (n))
    {
        printf("3->");
        return 1;
    }
    for (i = 0; i < n; i++)
    {
        if (arr[i][n - i - 1] == "1")
        {
            continue;
        }
        else
            break;
    }
    if (i == (n))
    {
        printf("4->");
        return 1;
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (arr[i][j] == "2")
            {
                continue;
            }
            else
            {
                break;
            }
        }
        if (j == (n))
        {
            printf("5->");
            return 1;
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (arr[j][i] == "2")
            {
                continue;
            }
            else
            {
                break;
            }
        }
        if (j == (n))
        {
            printf("6->");
            return 1;
        }
    }
    for (i = 0; i < n; i++)
    {
        if (arr[i][i] == "2")
        {
            continue;
        }
        else
            break;
    }
    if (i == (n))
    {
        printf("7->");
        return 1;
    }
    for (i = 0; i < n; i++)
    {
        if (arr[i][n - i - 1] == "2")
        {
            continue;
        }
        else
            break;
    }
    if (i == (n))
    {
        printf("8->");
        return 1;
    }

    return 0;
}
void tictoktie::display()
{
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout <<"/* "<< arr[i][j]<<" */"<<" ("<<k<<")"<< "\t\t";
            k++;
        }
        cout << endl;
    }
}
int main()
{
    int n;
    printf("enter size(n*n): ");
    cin >> n;
    srand(time(NULL));
    int c;
    int xx;
    printf("enter 1. for play with computer 2. for withplayer: ");
    cin >> xx;
    if (xx == 2)
    {
        char name_1[20], name_2[20];
        cout << "enter 1st player name: ";
        scanf(" %[^\n]%*c", &name_1);
        cout << "enter 2nd player name: ";
        scanf(" %[^\n]%*c", &name_2);
        tictoktie t(n, name_1, name_2);
        while (1)
        {
            t.display();
        ss:
            cout << "enter /" << t.name1 << "/ a nmber as your wish that (0 to "<< n*n-1<<" )(for u 1): ";
            scanf("%d", &c);
            if (t.check(c))
            {
                printf("enter again\n");
                goto ss;
            }
            t.insert(c, 1);
            if (t.chek_win())
            {
                cout <<"*******"<< t.name1 << " woned game ***********\n";
                t.display();
                break;
            }
            if (t.tie())
            {
                t.display();
                cout << "********* match tie *************\n";
                break;
            }

            t.display();
        sss:
            cout << "enter /" << t.name2 << "/ a nmber as your wish that (0 to "<< n*n-1<<" )(for u 2): ";
            scanf("%d", &c);
            if (t.check(c))
            {
                printf("enter again\n");
                goto sss;
            }
            t.insert(c, 2);
            if (t.chek_win())
            {
                cout <<"**********"<< t.name2 << " woned game ************\n";
                t.display();
                break;
            }
            if (t.tie())
            {
                t.display();
                cout << "********* match tie *************\n";
                break;
            }
        }
    }
    else if (xx == 1)
    {
        char name_1[20];
        int first_play;
        cout << "enter player name: ";
        scanf(" %[^\n]%*c", &name_1);
        printf("enter 1 for first play computer and for player 2: ");
        scanf("%d", &first_play);
        if (first_play == 1)
        {
            tictoktie t(n, "computer", name_1);
            while (1)
            {
                t.display();
            ss_s:
                cout << "enter /" << t.name1 << "/ a nmber as your wish that (0 to "<< n*n-1<<" )(for u 1): ";

                c = (rand() % 9);
                printf("%d\n", c);
                if (t.check(c))
                {
                    printf("enter again\n");
                    goto ss_s;
                }
                t.insert(c, 1);
                if (t.chek_win())
                {
                    cout <<"*********"<< t.name1 << " woned game ***********\n";
                    t.display();
                    break;
                }
                if (t.tie())
                {
                    t.display();
                    cout << "********* match tie *************\n";
                    break;
                }

                t.display();
            sss_s:
                cout << "enter /" << t.name2 << "/ a nmber as your wish that (0 to "<< n*n-1<<" )(for u 2): ";
                scanf("%d", &c);
                if (t.check(c))
                {
                    printf("enter again\n");
                    goto sss_s;
                }
                t.insert(c, 2);
                if (t.chek_win())
                {
                    cout <<"**********"<< t.name2 << " woned game **********\n";
                    t.display();
                    break;
                }
                if (t.tie())
                {
                    t.display();
                    cout << "********* match tie *************\n";
                    break;
                }
            }
        }
        else if (first_play == 2)
        {
            tictoktie t(n, name_1, "computer");
            while (1)
            {
                t.display();

            sss_sa:
                cout << "enter /" << t.name1 << "/ a nmber as your wish that (0 to "<< n*n-1<<" )(for u 2): ";
                scanf("%d", &c);
                if (t.check(c))
                {
                    printf("enter again\n");
                    goto sss_sa;
                }
                t.insert(c, 2);
                if (t.chek_win())
                {
                    cout <<"**********"<< t.name1 << " woned game ***********\n";
                    t.display();
                    break;
                }
                if (t.tie())
                {
                    t.display();
                    cout << "********* match tie *************\n\n";
                    break;
                }

                t.display();
            ss_sb:
                cout << "enter /" << t.name2 << "/ a nmber as your wish that (0 to "<< n*n-1<<" )(for u 1): ";

                c = (rand() % 9);
                printf("%d\n", c);
                if (t.check(c))
                {
                    printf("enter again\n");
                    goto ss_sb;
                }
                t.insert(c, 1);
                if (t.chek_win())
                {
                    cout <<"***********"<< t.name2 << " woned game ***********\n";
                    t.display();
                    break;
                }
                if (t.tie())
                {
                    t.display();
                    cout << "********* match tie *************\n";
                    break;
                }
            }
        }
    }
    getch();
    return 0;
}