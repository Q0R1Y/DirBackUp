#ifndef _DATATRANS_H_
#include<string>
#define _DATATRANS_H_

#define SIGLE_THREAD_MAX_DATA_SIZE (1<<20)*500

// copy form file "src" to file "des" from "begin" with bolck of "size"
// return 0 if success
void data_from_to(const std::string &src,const std::string &des,int begin,int size);

// 0 for success
bool del_file(const std::string &src);

// 1 for exist
bool file_name_exist(const std::string src,const std::string &dir);

// 0 for success
bool cp_file(const std::string &src,const std::string &des);

#endif
