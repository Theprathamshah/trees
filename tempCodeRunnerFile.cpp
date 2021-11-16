
        int k;
        cin >> k;
        if (k < 0)
        {
            for (int i = 0; i < n; i++)
            {
                arr[i] = arr[(i + n - k) % n];
            }
        }

        else
        {
            for (int i = 0; i < n; i++)
            {
                arr[i] = arr[(i + k) % n];
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }