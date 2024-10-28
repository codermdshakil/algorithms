#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int max_area = 0;
        int max_left = 0;
        int max_right = 0;

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int height = min(arr[i], arr[j]);
                int width = j - i;
                int current_area = height * width;

                if (current_area > max_area)
                {
                    max_area = current_area;
                    max_left = i;
                    max_right = j;
                }
            }
        }

        if (t == 1)
        {
            cout << max_left << " " << max_right - 1 << endl;
        }
        else
        {
            cout << max_left << " " << max_right << endl;
        }
    }

    return 0;
}
