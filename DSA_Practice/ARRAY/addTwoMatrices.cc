#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int i, j, n, m, m1, m2, sum;

    cout << "Enter number of rows and columns: " << endl;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cout << "Enter two integers for element (" << i << "," << j << "): ";
            cin >> m1 >> m2;

            sum = m1 + m2;
            matrix[i][j] = sum;
        }
    }

    cout << "Resulting summed matrix:\n";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cout << matrix[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}