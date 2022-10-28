//#include<datatrans.h>
#include<iostream>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<vector>

std::string SRC_DIR;
std::string BACKUP_DIR;


int del_file(const std::string &src)
{
	DIR* path=opendir(src.c_str());
	if(path==NULL)
		return remove(src.c_str());
	else
	{
		struct dirent *dir_info=NULL;
		while((dir_info=readdir(path)))
		{
			if(strcmp(dir_info->d_name,".")==0||strcmp(dir_info->d_name,".."))
				continue;
			std::string temp=(src+"/")+dir_info->d_name;
			del_file(temp);
		}
		remove(src.c_str());
	}
	if(closedir(path)==-1)
	{
		perror("closedir error");
		exit(EXIT_FAILURE);
	}
	return 0;
}

// src is a relative path of a file.
// dir is a relative path of a dir.
int file_exist(const std::string &src,const std::string &dir)
{
	std::vector<std::string> src_split_path;
	size_t prepos=0,nowpos=0;
	while((nowpos=src.find("/",nowpos))!=std::string::npos)
	{
		src_split_path.push_back(src.substr(prepos,nowpos-prepos));
		prepos=++nowpos;
	}
	src_split_path.push_back(src.substr(prepos,nowpos-prepos));
	std::string rela_path=dir+"/";
	int flag=0;
	int size=src_split_path.size();
	for(int i=0;i<size;++i)
	{
		if(flag)
			rela_path=rela_path+src_split_path[i]+"/";
		if(src_split_path[i]==SRC_DIR.substr(SRC_DIR.rfind("/")+1))
			flag=1;
	}
	rela_path.pop_back();
	if(access(rela_path.c_str(),F_OK)==0)
		return 1;
	return 0;
}

int main()
{
	SRC_DIR="./src";
	BACKUP_DIR="./dir";
	if(file_exist("./src/tttt","./dir"))
		printf("exist\n");
	else printf("No\n");
	return 0;
}
