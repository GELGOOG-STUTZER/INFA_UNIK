#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>
#include <unistd.h>
#include <sys/msg.h>
#include <sys/wait.h>


int athlete (int id, int number, int queue) {
	long msgtyp;
	printf("Athlete №%d came to the stadium\n", id);
	msgtyp = number + 1;
	if(msgsnd(queue, &msgtyp, 0, 0) < 0) {
		perror("msgsnd error\n");
		return errno;
	}
	if(msgrcv(queue, &msgtyp, 0, id, 0) < 0) {
		perror("msgrcv error\n");
		return errno;
	}
	printf("Athlete №%d started the race\n", id);
	msgtyp = msgtyp + 1;
	if(msgsnd(queue, &msgtyp, 0, 0) < 0) {
                perror("msgsnd error\n");
                return errno;
        }
	printf("Athlete №%d finished the race\n", id);
	if(msgrcv(queue, &msgtyp, 0, number + 2, 0) < 0) {
                perror("msgrcv error\n");
                return errno;
        }
	printf("Athlete №%d left the stadium\n", id);
	return 0;
}

int referee (int number, int queue) {
	int i;
	long msgtyp;
	printf("Referee came to the stadium\n");
	for(i = 1; i <= number;i++){
		if(msgrcv(queue, &msgtyp, 0, number+1, 0) < 0) {
                perror("msgrcv error\n");
                return errno;
		}
        }
	printf("All athletes came to the stadium\n");
	printf("Referee starts the race\n");
	msgtyp = 1;
	if(msgsnd(queue, &msgtyp, 0, 0) < 0) {
		perror("msgrcv error\n");
		return errno;
	}
	if(msgrcv(queue, &msgtyp, 0, number+1, 0) < 0) {
                perror("msgrcv error\n");
                return errno;
	}
	printf("Referee starts time announcement\n");
	msgtyp = number + 2;
	for(i = 1; i <= number; i++) {
		if(msgsnd(queue, &msgtyp, 0, 0) < 0) {
			perror("msgrcv error\n");
                	return errno;
        	}
	}
	printf("Referee left the stadium\n");
	return 0;

}

int main(int argc, char **argv) {
	setlinebuf(stdin);
	int queue = msgget(IPC_PRIVATE, 0700);
	if(queue < 0) {
		perror("msgget error\n");
		return errno;
	}

	int number = 13;
	if(argc > 1) {
		number = atoi(argv[1]);
	}

	for(int i = 1; i <= number; i++) {
		int pid = fork();
		if (pid < 0) {
			perror("fork error\n");
			return errno;
		}

		if(pid == 0) {
			return athlete(i, number, queue);
		}
	}

	int pid = fork();
	if (pid < 0) {
		perror("fork error\n");
		return errno;
	}

	if(pid == 0) {
		return referee(number, queue);
	}

	for (int i = 0; i < number; i++) {
		waitpid(-1, NULL, 0);
	}

	if (msgctl(queue, IPC_RMID, 0) < 0) {
		perror("queue close error:");
		return errno;
	}
}
