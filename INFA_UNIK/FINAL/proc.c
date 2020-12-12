#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <dirent.h>

void dir_count(char* path,int* count) {
     char new_path[1000];
     struct stat* buf1;
     struct stat* buff;
     int status;
     struct dirent *current;
     DIR *dir = opendir(path);
     status = stat("/proc", buff);

     if(!dir) {
        return;
     }

     current = readdir(dir);
     while(current != NULL) {
        if((strcmp(current->d_name, "." ) != 0) && (strcmp(current->d_name, "..") != 0)) { 
            *count = *count + 1;
            status = stat(current->d_name, buf1);
            if(buf1->st_mode == buff->st_mode) {
                strcpy(new_path, path);
            strcat(new_path, "/");
            strcat(new_path, current->d_name);
            printf("%s\n", new_path);
            dir_count(new_path, count);
            }
        }
        current = readdir(dir);
    }
    closedir(dir);
    return;
}


int main (int argc, char* argv[]) {
	struct dirent *current;
    DIR *dir;
    int total_count = 0;
    int proc_count = 0;
    dir = opendir("/proc");
    current = readdir(dir);
    while(current != NULL) {
        if(current->d_name[0] > '0' && current->d_name[0] <= '9')
            proc_count++; 
        current = readdir(dir);
    }
    closedir(dir);
    dir_count("/proc", &total_count);
    printf("Number of processes: %d\n", proc_count);
    printf("Total count: %d\n", total_count);
    return 0;
}

