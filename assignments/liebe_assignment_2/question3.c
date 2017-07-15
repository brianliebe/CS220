/*
 * Complete the function below. Do NOT add main function or any include statement.
 */
int swap_bytes(int n) {
    
    int sum = 0;
    int part1 = (0xFF000000 & n);
    int part2 = (0x00FF0000 & n);
    int part3 = (0x0000FF00 & n);
    int part4 = (0x000000FF & n);
    // printf("%d %d %d %d", part1 >> 24, part2 >> 16, part3 >> 8, part4);
    int final = part2 << 8 | part1 >> 8 | part4 << 8 | part3 >> 8;
    
    /* For whatever reason, when I run this the 6th test case fails. However when I try to do this manually using online hex<->decimal converters I        
     * can't seem to get either of the answers, expected or actual output. Not really sure why what I wrote wouldn't work on that last test case...
     * It is something to do with signed ints? It did work once with a negative number for one test case. 
     */
    
    /*
    the following is the product of me incorrectly reading the question... 
    
    int max = 32;
    int arr[max];
    for (int i = 0; i < max; i++) {
        arr[i] = 0;
    }
    
    int temp = n;
    int num = 0;
    int sum = 0;
    if (temp < 0) {
        n = n * (-1);
    }
    int pos = max-1;
    while (n > 0) {
        arr[pos] += (n % 2);
        n = n / 2;
        pos -= 1;
    }
    
    if (temp < 0) {
        for (int i = 0; i < max; i++) {
            if (arr[i] == 0) {
                arr[i] = 1;
            }
            else if (arr[i] == 1) {
                arr[i] = 0;
            }
        }
        int done = 0;
        for (int i = max-1; i >= 0; i --) {
            if (done == 0) {
                if (arr[i] == 0) {
                    arr[i] = 1;
                    arr[i+1] = 0;
                    done = 1;
                }
            }
        }
    }
    
    for (int i = 0; i < max; i++) {
        printf("%d", arr[i]);
    } printf("\n");
    /*
    
    
    /*
    int a1[8];
    int a2[8];
    int a3[8];
    int a4[8];
    
    for (int i = 0; i < 8; i++) {
        a1[i] = arr[i];
        a2[i] = arr[i+8];
        a3[i] = arr[i+16];
        a4[i] = arr[i+24];
    }
    
    for (int i = 0; i < 8; i++) {
        printf("%d", a1[i]);
    } printf("\n");
    for (int i = 0; i < 8; i++) {
        printf("%d", a2[i]);
    } printf("\n");
    for (int i = 0; i < 8; i++) {
        printf("%d", a3[i]);
    } printf("\n");
    for (int i = 0; i < 8; i++) {
        printf("%d", a4[i]);
    } printf("\n");
    */
    
    /*
    int t1 = arr[0];
    int t2 = arr[1];
    int t3 = arr[2];
    int t4 = arr[3];
    int t5 = arr[4];
    int t6 = arr[5];
    int t7 = arr[6];
    int t8 = arr[7];
    arr[0] = arr[8];
    arr[1] = arr[9];
    arr[2] = arr[10];
    arr[3] = arr[11];
    arr[4] = arr[12];
    arr[5] = arr[13];
    arr[6] = arr[14];
    arr[7] = arr[15];
    arr[8] = t1;
    arr[9] = t2;
    arr[10] = t3;
    arr[11] = t4;
    arr[12] = t5;
    arr[13] = t6;
    arr[14] = t7;
    arr[15] = t8;
    
    int t9 = arr[16];
    int t10 = arr[17];
    int t11 = arr[18];
    int t12 = arr[19];
    int t13 = arr[20];
    int t14 = arr[21];
    int t15 = arr[22];
    int t16 = arr[23];
    arr[16] = arr[24];
    arr[17] = arr[25];
    arr[18] = arr[26];
    arr[19] = arr[27];
    arr[20] = arr[28];
    arr[21] = arr[29];
    arr[22] = arr[30];
    arr[23] = arr[31];
    arr[24] = t9;
    arr[25] = t10;
    arr[26] = t11;
    arr[27] = t12;
    arr[28] = t13;
    arr[29] = t14;
    arr[30] = t15;
    arr[31] = t16;
    */
  
    /*
    0110
    0100
    
    
    
    if (temp < 0) {
        int done1 = 0;
        int done2 = 0;
        for (int i = max - 1; i >= 0; i--) {
            if (done1 == 0) {
                if (arr[i] == 1) {
                    arr[i] = 0;
                    done1 = 1;
                    if (i == max - 1) {
                        done2 = 1;
                    }
                    for (int j = i + 1; j < max; j++) {
                        if (done2 = 0) {
                            if (arr[j] == 0) {
                                arr[j] = 1;
                                done2 = 1;
                            }
                        }
                    }
                }
            }
        }
    }
    
    for (int i = 0; i < max; i++) {
        printf("%d", arr[i]);
    } printf("\n");
    */
    
    return final;

}

