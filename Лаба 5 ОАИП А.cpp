#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

struct tstk {
    int inf;
    tstk* a;
};

tstk** sv_create(int m)
{
    tstk** H = new tstk * [m];
    for (int i = 0; i < m; i++) H[i] = NULL;
    return H;
}

void sv_add(int inf, int m, tstk** H)
{
    tstk* spt = new tstk;
    spt->inf = inf;
    int i = inf % m;

    if (H[i] == NULL) {
        H[i] = spt;
        spt->a = NULL;
    }
    else {
        spt->a = H[i];
        H[i] = spt;
    }
}

tstk* sv_search(int inf, int m, tstk** H)
{
    int i = abs(inf % m);
    tstk* spt = H[i];
    while (spt != NULL)
    {
        if (spt->inf == inf)
            return spt;
        spt = spt->a;
    }
    return NULL;
}

void sv_delete(int m, tstk** H)
{
    tstk* spt, * sp;
    for (int i = 0; i < m; i++)
    {
        cout << "H[" << i << "]= ";
        sp = H[i];
        while (sp != NULL)
        {
            cout << sp->inf << " ";
            spt = sp;
            sp = sp->a;
            delete spt;
        }
        cout << endl;
    }
    delete[] H;
}

int main() {
    setlocale(0, "ru");
    srand(time(0));
    int n = 8;
    int mass[8];
    cout << "Исходный массив:" << endl;
    for (int i = 0; i < n; i++) {
        mass[i] = 53000 + rand() % (78000 - 53000 + 1);
        cout << mass[i] << endl;
    }
    int m = 10;
    int i;

    tstk** H;

    H = sv_create(m);
    for (i = 0; i < n; i++) sv_add(mass[i], m, H);

    cout << "Хеш-таблица:" << endl;
    for (int i = 0; i < m; i++) {
        cout << "H[" << i << "]: ";
        tstk* spt = H[i];
        while (spt != NULL) {
            cout << spt->inf << " ";
            spt = spt->a;
        }
        cout << endl;
    }

    int ss;
    tstk* p;
    cout << "Введите искомый элемент: ";
    cin >> ss;
    while (ss != -1)
    {
        p = sv_search(ss, m, H);
        if (p == NULL)
            cout << "Нет элемента" << endl;
        else
            cout << "Результат: " << p->inf << endl;
        cout << "Введите искомый элемент: ";
        cin >> ss;
    }
    sv_delete(m, H);

    return 0;
}