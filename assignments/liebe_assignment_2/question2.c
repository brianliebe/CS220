/*
 * Complete the function below. Do NOT add main function or any include statement.
 */
unsigned int count_ones(int n) {
    int arr[32];
    for (int i = 0; i < 32; i++) {
        arr[i] = 0;
    }
    
    int temp = n;
    int num = 0;
    int sum = 0;
    if (temp < 0) {
        n = n * (-1);
    }
    int pos = 31;
    while (n > 0) {
        arr[pos] += (n % 2);
        n = n / 2;
        pos -= 1;
    }
    
    if (temp < 0) {
        for (int i = 0; i < 32; i++) {
            if (arr[i] == 0) {
                arr[i] = 1;
            }
            else if (arr[i] == 1) {
                arr[i] = 0;
            }
        }
        int done = 0;
        for (int i = 31; i >= 0; i --) {
            if (done == 0) {
                if (arr[i] == 0) {
                    arr[i] = 1;
                    arr[i+1] = 0;
                    done = 1;
                }
            }
        }
    }
    
    for (int i = 0; i < 32; i ++) {
        printf("%d\n", arr[i]);
        sum += arr[i];
    }
    return sum;
}

