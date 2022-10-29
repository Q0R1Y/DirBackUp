#include<scanfile.h>
#include<datatrans.h>
#include<iostream>
#include<sys/wait.h>

std::string SRC_DIR;
std::string BACKUP_DIR;

int main()
{
	printf("Input A_DIR:\n");
	std::cin>>SRC_DIR;
	printf("Input B_DIR:\n");
	std::cin>>BACKUP_DIR;

	printf("1.BACKUP A TO B\n");
	printf("2.SYNC A FROM B\n");
	printf("3.SYNC B FROM A\n");
	printf("0.EXIT\n");
	int op;
	std::cin>>op;

	pthread_t thread;
	pthread_create(&thread,NULL,progress_bar,NULL);
	
		
	switch(op)
	{
case 1:
	sync_dir(SRC_DIR,BACKUP_DIR,1);
	break;
case 2:
	sync_dir(BACKUP_DIR,SRC_DIR,0);
	break;
case 3:
	sync_dir(SRC_DIR,BACKUP_DIR,0);
	break;
default:
	break;
	}
	pthread_join(thread,NULL);
	return 0;
}
