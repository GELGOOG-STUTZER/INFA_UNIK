#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <dirent.h>


int main (int argc, char* argv[]) {
	struct dirent *current;
    DIR *dir;
    int proc_count = 0;
    dir = opendir("/proc");
    current = readdir(dir);
    while(current != NULL) {
    if(current->d_name[0] > '0' && current->d_name[0] <= '9')
       proc_count++; 
    current = readdir(dir);
    }
    printf("Number of processes: %d\n", proc_count);
}

