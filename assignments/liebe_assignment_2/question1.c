/*
 * Complete the function below. Do NOT add main function or any include statement.
 */
unsigned int count_ones(unsigned int num) {
    switch (num) {
        case 0: return 0; break;
        case 1: return 3; break;
        case 2: return 3; break;
        case 3: return 5; break;
        case 4: return 4; break;
        case 5: return 4; break;
        case 6: return 3; break;
        case 7: return 5; break;
        case 8: return 5; break;
        case 9: return 4; break;
        default: return 0;
    }
    return 0;
}

unsigned int count_tens(unsigned int num) {

    switch (num/10) {
        case 0:
            return count_ones(num); 
            break;
        case 1: 
            switch (num) {
                case 10: return 3; break;
                case 11: return 6; break;
                case 12: return 6; break;
                case 13: return 8; break;
                case 14: return 8; break;
                case 15: return 7; break;
                case 16: return 7; break;
                case 17: return 9; break;
                case 18: return 8; break;
                case 19: return 8; break;
                default: return 0; break;
            }
            break;
        case 2: 
            return count_ones(num % 10) + 6; 
            break;
        case 3: 
            return count_ones(num % 10) + 6; 
            break;
        case 4: 
            return count_ones(num % 10) + 5; 
            break;
        case 5: 
            return count_ones(num % 10) + 5; 
            break;
        case 6: 
            return count_ones(num % 10) + 5; 
            break;
        case 7: 
            return count_ones(num % 10) + 7; 
            break;
        case 8: 
            return count_ones(num % 10) + 6; 
            break;
        case 9: 
            return count_ones(num % 10) + 6; 
            break;
        default: return 0; break;
    }
    return 0;
}

unsigned int count_hundreds(unsigned int num) {
    int sum = 0;
    if (num / 100 != 0) { 
        sum += 7;
        sum += count_ones(num/100);
    }
    
    sum += count_tens(num % 100); 
    
    return sum;
}


unsigned int count_thousands(unsigned int num) {
    unsigned int sum = 0;
    if (num / 1000 != 0) { 
        sum += 8;
        sum += count_hundreds(num / 1000);
    }
    
    sum += count_hundreds(num % 1000);
    
    return sum;
}

unsigned int count_millions(unsigned int num) {
    int sum = 0;
    if (num / 1000000 != 0) {
        sum += 7;
        sum += count_hundreds(num / 1000000);
    }
    
    sum += count_thousands(num % 1000000);

    return sum;
}

unsigned int count_letters(unsigned long num) {
    int sum = 0;
    if (num == 0) return 4;
    if (num > 1000000000) return 0;
    if (num == 1000000000) return 10;
    
    sum += count_millions(num);
    
    // printf("%d ", num/1000000);
    return sum;
}

