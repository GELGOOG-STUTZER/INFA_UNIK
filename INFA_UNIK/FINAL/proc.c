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
    dir = opendir("/proc");
    current = readdir(dir);
    while(current != NULL) {
    puts(current->d_name);
    }
}

