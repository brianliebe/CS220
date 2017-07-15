#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>

int main() {
	char line[1024];
	int pid, i, j;
	int foundAmpersand = 0;
	char *args1[100];
	char *args2[100];
	char *token;
	while (1) {
		printf("\x1B[32mHello!>\x1B[37m ");
		if (!fgets(line, 1023, stdin)) {
			printf("\n");
			break;
		}
		if (strcmp(line, "exit\n") == 0) {
			break;
		}

		for (i = 0; i < strlen(line); i++) {
			if (line[i] == '\n') {
				line[i] = '\0';
			}
		}
		
		token = strtok(line, " ");
		
		i = 0; j = 0;
		int switcher = 0;
		while (token != NULL) {
			args1[i] = token;
			token = strtok(NULL, " ");
			i++;
		} args1[i] = NULL;

		int temp = i;
		int temp2 = 0;
		for (i = 0; i < temp; i++) {
			if (strcmp(args1[i], "&&") == 0) {
				foundAmpersand = 1;
				temp2 = i;
				args1[i] = NULL;

				if (i + 1 != temp) {
					for (i = i + 1; i < temp; i++) {

						args2[j] = args1[i];
						j++;
					}
					i = temp;
				} 
				args2[j] = NULL;
				break;
				
			}
		}

		pid = fork();
		if (pid == 0) { /* This is the child */
			execvp(args1[0], args1);
			fprintf(stderr, "Hello!: %s\n", strerror(errno));
			exit(errno);
		} else {

		    int status;
		    wait(&status);

		    if(WIFEXITED(status)) {
		    	if (foundAmpersand) {
		    		if (!WEXITSTATUS(status)) {
		    			pid = fork();
		    			if (pid == 0) {
							execvp(args2[0], args2);
							fprintf(stderr, "Hello!: %s\n", strerror(errno));
							exit(errno);
						}
					}
				}
		    }
			wait(NULL);
		}

		for (i = 0; i < 100; i++) {
			args2[i] = NULL;
		}

	}
	return 0;
}