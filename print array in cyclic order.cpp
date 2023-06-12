for (int i = 0; i < n; i++)
    {
        for (int j = i; j < i + n; j++)
        {
            cout << a[j % n] << " ";
        }
        cout << endl;
    }
