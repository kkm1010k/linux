#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>


int main(int argc, char *argv[])
{
	DIR * dirp;
	struct dirent *dentry;
	struct stat buf;
	int cnt = 0;
	int cnt2 = 0;
	if((dirp=opendir("."))==NULL)
	{
		fprintf(stderr, "Error\n");
	}
	
	while (dentry = readdir(dirp)){
		if(dentry->d_ino!=0){
			lstat(dentry->d_name, &buf);
			if (S_ISDIR(buf.st_mode)){
				cnt++;
			}
			else if (S_ISREG(buf.st_mode)){
				cnt2++;
			}
		}
	}
	printf("%d %d\n",cnt, cnt2);
	closedir(dirp);
}
