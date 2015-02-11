// SMTDataBase.cpp : 实现文件
//

#include "stdafx.h"
#include <iostream>
#include "SuperMarketTools.h"
#include "SMTDataBase.h"
#include <winsock.h>
#include "mysql.h"
   
#pragma comment(lib, "libmysql.lib") 

using namespace std;


// CSMTDataBase

CSMTDataBase::CSMTDataBase()
{
	MYSQL mydata;    
        
    mysql_library_init(0,NULL,NULL);  
    mysql_init(&mydata);
    mysql_options(&mydata,MYSQL_SET_CHARSET_NAME,"gbk");
           
   if (mysql_real_connect(&mydata,"localhost","root","root","supermarkettools", 3306, 0, 0)) {
	   AfxMessageBox(_T("connect successfully"), MB_OK);
   }

}

CSMTDataBase::~CSMTDataBase()
{
}


// CSMTDataBase 成员函数
