#include<stdio.h>
#include<signal.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

pid_t pid_sender = 0;
pid_t pid_receiver = 0;

char* input = NULL;
char* output = NULL;

size_t cur_byte = 0;
size_t cur_bit = 0;


void Receiver_0(int a) {
    if(cur_bit == 7) {
        cur_bit = 0;
        cur_byte++;
    }
    else
        cur_bit++;

    kill(pid_sender, 6);
}

void Receiver_1(int a) {
    output[cur_byte] |= (1 << cur_bit);

    if(cur_bit == 7) {
        cur_bit = 0;
        cur_byte++;
    }
    else
        cur_bit++;

    kill(pid_sender, 6);
}

void Kill(int a) {
    printf("output: %s", output);
    free(input);
    free(output);
    exit(0);
}

void Sender(int a) {

}

int main(void) {
    size_t temp = 0;
    ssize_t size_input = getline(&input, &temp, stdin); // (описание getline) https://www.opennet.ru/man.shtml?topic=getline&category=3&russian=0
    if(size_input < 0) {
        printf("ERROR\n");
        perror("size_input");
    }
    output = (char*)calloc(size_input + 1, sizeof(output[0]));

    pid_receiver = getpid();
    pid_sender = fork();

    if(pid_sender != 0) {
        struct sigaction action = {}; // структура, описывающая правила установки обработчика сигнала
        action.sa_handler = Receiver_0;
        action.sa_flags = 0;

        if(sigaction(7, &action, NULL) < 0) {  // https://www.man7.org/linux/man-pages/man2/sigaction.2.html
            printf("ERROR\n"); // SIGBUS
            perror("sigaction");
            exit(EXIT_FAILURE);
        }

        action.sa_handler = Receiver_1;
        if(sigaction(8, &action, NULL) < 0) {  // https://www.man7.org/linux/man-pages/man2/sigaction.2.html
            printf("ERROR\n"); // SIGFPE
            perror("sigaction");
            exit(EXIT_FAILURE);
        }

        action.sa_handler = Kill;
        if(sigaction(29, &action, NULL) < 0) {  // https://www.man7.org/linux/man-pages/man2/sigaction.2.html
            printf("ERROR\n"); // SIGIO
            perror("sigaction");
            exit(EXIT_FAILURE);
        }

        sigset_t mask;
        sigemptyset(&mask);
        while(1)
            sigsuspend(&mask);
    }
    else {
        struct sigaction action = {};
        action.sa_handler = Sender;
        action.sa_flags = 0;
        if(sigaction(6, &action, NULL) < 0) {  // https://www.man7.org/linux/man-pages/man2/sigaction.2.html
            printf("ERROR\n"); // SIGABRT
            perror("sigaction");
            exit(EXIT_FAILURE);
        }

        for(size_t bit = 0; bit < (size_t)size_input * 8; ++bit) {
            sigset_t mask;
            if(sigfillset(&mask) < 0) { // https://www.opennet.ru/man.shtml?topic=sigfillset&category=3&russian=2
                printf("ERROR\n");
                perror("sigfillset");
                exit(EXIT_FAILURE);
            }
            if(sigprocmask(SIG_BLOCK, &mask, NULL) < 0) { // https://www.opennet.ru/cgi-bin/opennet/man.cgi?topic=sigprocmask&category=2
                printf("ERROR\n");
                perror("sigprocmask");
                exit(EXIT_FAILURE);
            }
            if(sigemptyset(&mask) < 0) { // https://www.opennet.ru/man.shtml?topic=sigemptyset&category=3&russian=0
                printf("ERROR\n");
                perror("sigemptyset");
                exit(EXIT_FAILURE);
            }

            char bit_val = input[bit/8] & (1 << (bit % 8)); // при помощи логических операций получаем значение конкретного бита

            if(bit_val == 0){
                if(kill(pid_receiver, 7) < 0) {
                    printf("ERROR\n");
                    perror("kill");
                    exit(EXIT_FAILURE);
                }
            }
            else {
                if(kill(pid_receiver, 8) < 0) {
                    printf("ERROR\n");
                    perror("kill");
                    exit(EXIT_FAILURE);
                }
            }

            sigsuspend(&mask);
        }

        if(kill(pid_receiver, 29) < 0) {
            printf("ERROR\n");
            perror("kill");
            exit(EXIT_FAILURE);
        }
    }
    return 0;
}
