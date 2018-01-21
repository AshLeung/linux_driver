#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define LENGTH 100

int main(int argc, char const *argv[])
{
	int fp, len;
	char str[LENGTH];
	int file_size;

	fp = open("hello.txt", O_CREAT | O_RDWR, S_IRWXU | S_IRWXO);
	if(fp==-1){
		printf("Create file failed.\n");
		exit(1);
	}else{	
		printf("Create file success.\n");
		if(argc!=1)
			write(fp, argv[1], strlen(argv[1]));
		else
			write(fp, "Hello World!", strlen("Hello World!"));
		close(fp);
	}

	fp = open("hello.txt", O_RDONLY);
	if(fp==-1){
		printf("Open file failed.\n");
		exit(1);
	}else{
		printf("Open file success.\n");
		len = read(fp, str, LENGTH);
		str[len] = '\0';
		file_size = lseek(fp, 0, SEEK_END)-lseek(fp, 0, SEEK_SET);
		printf("File size: %d Byte.\n", file_size);
		close(fp);
	}

	printf("%s\n", str);
	return 0;
}