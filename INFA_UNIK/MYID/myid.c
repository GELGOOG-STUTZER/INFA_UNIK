#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#define _GNU_SOURCE
//
//
//


int main (int argc, char* argv[]) {
	struct passwd* buffer;
	struct group* buff;
       	int uid, gid, size = 0;
	uid = getuid();
	gid = getgid();
	size = getgroups(size, NULL);
	unsigned int groups[size];
	size = getgroups(size, groups); 
	buffer = getpwuid(uid);
	printf("uid=%d(%s)", uid, buffer->pw_name);
	buffer = getpwuid(gid);
	printf(" gid=%d(%s)", gid, buffer->pw_name);
	printf(" groups=%d(%s),", gid, buffer->pw_name);
	unsigned int i = 0;
	while(i < size-2) {
		buff = getgrgid(groups[i]);
		printf("%u(%s),", groups[i], buff->gr_name);
		i++;
	}
	buff = getgrgid(groups[i]);
        printf("%u(%s)\n", groups[i], buff->gr_name);
}

