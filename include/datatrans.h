#ifndef _DATATRANS_H_
#include<string>

#define _DATATRANS_H_

#define SIGLE_THREAD_MAX_DATA_SIZE (1<<20)*500

struct Data_trans
{
	std::string src;
	std::string des;
	int begin;
	int size;
};

// pass struct Data_trans
void *data_trans_thread(void *args);

// copy form file "src" to file "des" from "begin" with bolck of "size"
// return 0 if success
int data_from_to(const std::string &src,const std::string &des,int begin,int size);

// 0 for success
int del_file(const std::string &src);

// 1 for exist
int file_exist(const std::string &src,const std::string &dir);

// 0 for success
int cp_file(const std::string &src,const std::string &des);
#endif
