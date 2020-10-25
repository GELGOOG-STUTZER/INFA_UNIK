#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <errno.h>
#include <stdlib.h>
#include<sys/wait.h>

#define WANT_GO 0
#define ON_BOAT 1
#define ON_BEACH 2
#define ON_RAMP 3
#define RAMP_DOWN 4
#define CRUISE_END 5
#define CRUISE_START 6
#define LAST_TRIP 7
const int NUMBER_SEM = 8;

#define TRY(cmd) if((cmd) < 0) {            \
			perror(#cmd);       \
			exit(EXIT_FAILURE); \
		 }                          \

#define change(SEM_NAME, VAL) do {                           \
				op.sem_num = SEM_NAME;       \
   				op.sem_op = VAL;	     \
				op.sem_flg = 0;              \
				TRY (semop(sem_id, &op, 1)); \
			      } while (0)                    \

void passenger (int sem_id, int pass_num) {
	struct sembuf op; // создаем структуру для операций с семафорами
	while(1)
	{

		change(RAMP_DOWN, 0);
		if (semctl(sem_id, LAST_TRIP, GETVAL))
			break;
		change (ON_BOAT, -1);
		if (semctl(sem_id, LAST_TRIP, GETVAL))
                        break;
                change(ON_RAMP, -1);
		printf("Passenger %d on ramp\n", pass_num);
		change(ON_RAMP, 1);
		printf("Passenger %d on ship\n", pass_num);
		
		change(CRUISE_START, 0);
		change(CRUISE_END, 0);

		change(RAMP_DOWN, 0);
		change(ON_RAMP, -1);
		printf("Passenger %d on ramp\n", pass_num);
		change(ON_RAMP, 1);
		printf("Passenger %d on beach\n", pass_num);
		change(ON_BOAT, 1);
		change(WANT_GO, -1);
	}
}

void ship_cap (int sem_id, int boat_size, int ladder_size, int num_steps) {
	struct sembuf op;
	change(RAMP_DOWN, -1);
	change(CRUISE_START, -1);

	for(int i=0; i < num_steps; ++i) {
		if(i == num_steps - 1) 
			change(LAST_TRIP, 1);
		
		change(ON_BOAT, 0);
		printf("WELCOME ON BOARD\n");
		change(RAMP_DOWN, 1);

		printf("WAITING FOR CLEAR RAMP\n");
		change(ON_RAMP, -ladder_size);
		change(ON_RAMP, ladder_size);

		printf("SHIP IS FULL\n");
		printf("CRUISE STARTED\n");
		printf("CRUISE ENDED\n");

		change(CRUISE_START, 1);
		change(CRUISE_END, -1);

		change(RAMP_DOWN, -1);

		change(WANT_GO, 0);
		change(CRUISE_END, 1);
		change(WANT_GO, boat_size);

		if(i == num_steps - 1)
			break;

		change(CRUISE_START, -1);
	}
}

int main (int argc, char **argv) {
	char print_buf[BUFSIZ];
	setvbuf(stdout, print_buf, _IOLBF, BUFSIZ);	
	int num_pass = 13;
	int boat_size = 7;
	int ladder_size = 3;
	int num_steps = 6;

	if (argc >= 5) {
		num_pass = atoi(argv[1]);
		boat_size = atoi(argv[2]);
		ladder_size = atoi(argv[3]);
		num_steps = atoi(argv[4]);
	}

	int sem_id = semget(IPC_PRIVATE, NUMBER_SEM, 0777);
	TRY(sem_id);
	struct sembuf op;

	change(RAMP_DOWN, 1);
	change(CRUISE_END, 1);
	change(CRUISE_START, 1);
	change(ON_RAMP, ladder_size);
	if (boat_size < num_pass) {
		change(ON_BOAT, boat_size);
		change(WANT_GO, boat_size);
	}
	else {
		change(ON_BOAT, boat_size);
		change(WANT_GO, num_pass);
	}

	pid_t cap_pid = fork();
	TRY(cap_pid);

	if(cap_pid == 0) {
		if(boat_size < num_pass) {
			ship_cap(sem_id, boat_size, ladder_size, num_steps);
			return 0;
		}
		else {
			ship_cap(sem_id, num_pass, ladder_size, num_steps);
			return 0;
		}
	}

	for(int i = 0; i < num_pass; ++i) {
		pid_t pid = fork();
		TRY(pid);

		if(pid == 0) {
			passenger(sem_id, i + 1);
			return 0;
		}
	}
	int wstatus;
	waitpid(cap_pid, &wstatus, 0);
	return 0;
}




