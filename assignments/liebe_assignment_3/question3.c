/*
 * Complete the function below.
 */
void swap_notemp(int *num1, int *num2) {
    *(num2 + 1) = *num1;
    *num1 = *num2;
    *num2 = *(num2 + 1);

}

