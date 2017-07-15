#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

extern int get_ebp();

unsigned int main_val = 0;
unsigned int main_end = 0;

void print_backtrace(int count) {
	int curr_ebp = get_ebp();
	int *next_ebp = (void *)(intptr_t)get_ebp();
	int multiple = 1;
	while (count > 0) {
		unsigned int ret_addr = curr_ebp + (4 * multiple);
		
		/*<- return address which is in [curr_ebp + 4] */
		
		printf("%x\n", ret_addr);
		
		if (ret_addr > main_val && ret_addr < main_end) {
			count = 0;
		}
		curr_ebp = (int)(intptr_t)next_ebp;
		count--;
		multiple++;
	}
	/*
	void (*fp)(void);
	fp = thefunction;

	printf("%p\n", fp);
	(*fp)();
	printf("%p\n", &(main));
	*/
}
/*
void bt(void) {
    int c, i;
    void *addresses[10];
    char **strings; 

    c = backtrace(addresses, 10);
    strings = backtrace_symbols(addresses,c);
    printf("backtrace returned: %dn", c);
    for(i = 0; i < c; i++) {
        printf("%d: %X ", i, (int)addresses[i]);
        printf("%sn", strings[i]);
    }
} 
*/
void pr3(int count) {
	print_backtrace(count);
}

void pr2(int count) {
	pr3(count);
}

void pr1(int count) {
	pr2(count);
}

int main() {
	/* printf("%p\n", &main); */
	main_val = 0x4005fd;
	main_end = 0x40063a;
	pr1(3);
	return 0;
}
