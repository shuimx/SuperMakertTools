// SMTDataBase.cpp : 实现文件
//

#include "stdafx.h"
#include <iostream>
#include "SuperMarketTools.h"
#include "SMTDataBase.h"
#include <winsock.h>
#include "errmsg.h"
   
#pragma comment(lib, "libmysql.lib") 

using namespace std;


// CSMTDataBase

CSMTDataBase::CSMTDataBase()
{
	//MYSQL mydata;    
        
    mysql_library_init(0,NULL,NULL);  
    mysql_init(&mydata);
    mysql_options(&mydata,MYSQL_SET_CHARSET_NAME,"gbk");
           
   if (mysql_real_connect(&mydata,"localhost","root","root","supermarkettools", 3306, 0, 0)) {
	   AfxMessageBox(_T("connect successfully"), MB_OK);
   }
/*
	// add customer
   if(mysql_query(&mydata, "insert into Customers values(1,'liujing1','female','18101356427','beijing','1')")){
	   char strError[128]={'\0'};
	   sprintf(strError,"Error %s\n", mysql_error(&mydata));
	   TRACE(strError);
   }else{
		AfxMessageBox(_T("insert into customers table successfully"), MB_OK);
   }
   */

 /*  
	// add records
   if(mysql_query(&mydata, "insert into Records values(2,'1','2015-03-08 11:03:00',3.5)")){
	   char strError[128]={'\0'};
	   sprintf(strError,"Error %s\n", mysql_error(&mydata));
	   TRACE(strError);
   }else{
		AfxMessageBox(_T("insert into Records table successfully"), MB_OK);
   }
  */ 

/*
	// query customer
   if(mysql_query(&mydata, "select * from customers where phone='18101356427'")){
	   char strError[128]={'\0'};
	   sprintf(strError,"Error %s\n", mysql_error(&mydata));
	   TRACE(strError);
   }else{
	   MYSQL_RES *result;
	   MYSQL_ROW row;
	   result = mysql_store_result(&mydata);
	   row = mysql_fetch_row(result);
	   if(!row){
			AfxMessageBox(_T("do not find the customer.Please check the phone or add the customer."), MB_OK);
	   }else{
			//AfxMessageBox(_T("find the customer."), MB_OK);

		   if(mysql_query(&mydata, "select sum(amount) from records where user_id=1")){
				char strError[128]={'\0'};
				sprintf(strError,"Error %s\n", mysql_error(&mydata));
				TRACE(strError);
		   }else{
				 result = mysql_store_result(&mydata);
				 row = mysql_fetch_row(result);
				 if(!row){
					AfxMessageBox(_T("fetal error"), MB_OK);
				 }else{
					 char strError[128]={'\0'};
					 sprintf(strError,"totel: %s\n", row[0]);
					TRACE(strError);
					mysql_free_result(result);
				 }
		   }
	   }
   }
   */


}

CSMTDataBase::~CSMTDataBase()
{
	mysql_close(&mydata);
}


// CSMTDataBase 成员函数

// 执行 查询SQL语句
bool CSMTDataBase::Query(const char* cmd)
{
   if(mysql_query(&mydata, cmd)){
	   AfxMessageBox(_T(mysql_error(&mydata)));
   }else{
		//AfxMessageBox(_T("insert into Records table successfully"), MB_OK);
	   return true;
   }
	return false;
}

// 执行 查询SQL语句 并返回 字符串数据
bool CSMTDataBase::QueryAndFetch(const char* cmd, char *res)
{
   if(mysql_query(&mydata, cmd)){
	   AfxMessageBox(_T(mysql_error(&mydata)));
   }else{
		MYSQL_RES *result;
	    MYSQL_ROW row;

		result = mysql_store_result(&mydata);
		row = mysql_fetch_row(result);
		if(!row){
			AfxMessageBox(_T("SQL语句没有返回数据"), MB_OK);
		}else{
			strcpy(res, row[0]);

			mysql_free_result(result);
			return true;
		}
	}
	return false;
}
