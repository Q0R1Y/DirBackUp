#include<scanfile.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>

void get_files_name(std::string name,std::deque<std::string> &stor)
{
	DIR *dir=NULL;
	if((dir=opendir(name.c_str()))==NULL)
	{
		stor.push_back(name);
		return ;
	}

	struct dirent *info=NULL;

	while((info=readdir(dir)))
	{
		if(info->d_name[0]=='.')
			continue;
		get_files_name(name+"/"+info->d_name,stor);
	}

}


int total_size(const std::deque<std::string> &files)
{
	int res=0;
	for(int i=0;i<files.size();++i)
		res+=lseek(open(files[i].c_str(),O_WRONLY),0,SEEK_END);
	
	return res;
}
