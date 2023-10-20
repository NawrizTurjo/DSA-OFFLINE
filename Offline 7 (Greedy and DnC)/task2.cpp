#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countPlatform(vector<int> &a, vector<int> &d, int n)
{
    int curr = 1;
    int i = 1, j = 0;
    int minPlatform = curr;

    while (i < n && j < n)
    {
        if (a[i] < d[j])
        {
            curr++;
            i++;
        }

        else if (a[i] >= d[j])
        {
            curr--;
            j++;
        }

        if (curr > minPlatform)
        {
            minPlatform = curr;
        }
    }
    return minPlatform;
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n;
    cin >> n;

    vector<int> a(n), d(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> d[i];
    }

    sort(a.begin(), a.end());
    sort(d.begin(), d.end());

    cout << "The minimum platforms needed is " << countPlatform(a, d, n) << endl;
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}

/*
11
800 830
820 900
930 1000
1145 1400
950 1045
1015 1130
1120 1200
1145 1330
1250 1500
1430 1540
1200 1600


5
900 940
950 1000
1100 1120
1130 1145
1000 1200

16
0000 2359
0000 2359
0000 2359
0000 2359
0000 2359
0000 2359
0000 2359
0000 2359
0000 2359
1000 1000
1000 1000
1000 1000
1000 1000
1000 1000
1000 1000
1000 1000

*/