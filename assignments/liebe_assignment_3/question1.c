/*
 * Complete the function below.
 */
unsigned int my_strncpy(char *src, char *dst, unsigned int num_bytes) {
    
    int sum = 0;
    
    for (int i = 0; i < sizeof(dst)/sizeof(dst[0]); i++){
        dst[i] = '\0';
    }
    
    
    if (num_bytes > 0) {
        for (int i = 0; i < num_bytes && src[i] != '\0'; i++) {
            dst[i] = src[i];
            sum++;
        }
        for (int i = sum; i < num_bytes; i++) {
            dst[i] = '\0';
        }
        for (int i = sum; src[i] != '\0'; i++) {
            dst[i] = '\0';
        }
    }
    return sum;
}

