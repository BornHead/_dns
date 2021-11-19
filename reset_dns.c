#include <stdio.h>
#include <string.h>
#include <stdlib.h>



#include "/usr/include/mysql/mysql.h"


void main(int argc, char *argv[])
{ 
        MYSQL *conn;
        MYSQL_RES *res;
        MYSQL_ROW row;

        char *server = "[your server]";                            // ddns or ip in your own
        char *user = "[your server id]";
        char *password = "[your server pw]";
        char *database = "[your server database]";

        if( !(conn = mysql_init((MYSQL*)NULL))){        // init function
                printf("init fail\n");
                exit(1);
        }

        printf("mysql_init sucsess.\n");

        if(!mysql_real_connect(conn, server, user, password, NULL, 3306, NULL, 0)){   // connect mysql server
                printf("connect error.\n");     
                exit(1);
        }

        printf("mysql_real_connect suc.\n");


        if(mysql_select_db(conn, database) != 0){
                mysql_close(conn);
                printf("select_db fail.\n");
                exit(1);
        }
        printf("select mydb suc.\n");



        //printf("%d", mysql_query(conn,"select * from testtab" ));   // return success 0 
        char query[300];
        sprintf(query, "select name,date < now() ,ipA,ipAAAA,cname,mx,spf from domain where name='%s'",argv[1]);
        if(mysql_query(conn,query)){
                printf("query fail\n");
                exit(1);
        }

        printf("query sucsess\n");

        res = mysql_store_result(conn);                 // save result of query in row
        printf("res suceese\n");



        while( (row=mysql_fetch_row(res))!=NULL){
                printf("[%s %s]\n", row[0],row[1]);       // print row 0 row 1

                if(1 > 0)
                {
                        FILE *fp = NULL;

                        if((fp = popen("/usr/bin/nsupdate -k [your private key file's path] -v", "w")) == NULL) {
                                return;
                        }
 
                        fprintf(fp, "server [your dns_server hostname]\n");
 
                        fprintf(fp, "zone [your dns_server hostname]\n");
 
 
                        int index = 0;
                        char *ptr = NULL;

                        if(row[2] != NULL)
                        {
                            ptr = strtok(row[2], "|,");    //  ipA
                            index = 0;
                            while (ptr != NULL)            
                            {  
                                    if(index == 0)
                                    {
                                            if(strcmp(ptr,"-")==0)
                                            { 
                                                    fprintf(fp, "update delete %s A\n",row[0]); 
                                            }
                                            else
                                            { 
                                                    fprintf(fp, "update delete %s.%s A\n", ptr, row[0]);   
                                            }      
                                    }
                                    else if(index == 2)
                                    {
                                            index = 0;
                                            if(strcmp(ptr,"-")==0)
                                            { 
                                                    fprintf(fp, "update delete %s A\n",row[0]); 
                                            }
                                            else
                                            { 
                                                    fprintf(fp, "update delete %s.%s A\n", ptr, row[0]);   
                                            }         
                                    }
                                    ptr = strtok(NULL, "|,");    
                                    index++;
                            }
                        }
                        if(row[3] != NULL)
                        {
                            ptr = strtok(row[3], "|,");    //  ipAAAA
                            index = 0;
                            while (ptr != NULL)            
                            { 
                                    if(index == 0)
                                    {
                                            if(strcmp(ptr,"-")==0)
                                            {
                                                    fprintf(fp, "update delete %s AAAA\n",row[0]); 
                                            }
                                            else
                                            {
                                                    fprintf(fp, "update delete %s.%s AAAA\n", ptr, row[0]);   
                                            }         
                                    }
                                    else if(index == 2)
                                    {
                                            index = 0;
                                            if(strcmp(ptr,"-")==0)
                                            {
                                                    fprintf(fp, "update delete %s AAAA\n",row[0]); 
                                            }
                                            else
                                            {
                                                    fprintf(fp, "update delete %s.%s AAAA\n", ptr, row[0]);   
                                            }   
                                    }
                                    ptr = strtok(NULL, "|,");    
                                    index++;
                            }
                        }
                        if(row[4] != NULL)
                        {
                            ptr = strtok(row[4], "|,");    //  CNAME
                            index = 0;
                            while (ptr != NULL)            
                            { 
                                    if(index == 0)
                                    {
                                            if(strcmp(ptr,"-")==0)
                                            {
                                                    fprintf(fp, "update delete %s CNAME\n",row[0]); 
                                            }
                                            else
                                            {
                                                    fprintf(fp, "update delete %s.%s CNAME\n", ptr, row[0]);   
                                            }       
                                    }
                                    else if(index == 2)
                                    {
                                            index = 0;
                                            if(strcmp(ptr,"-")==0)
                                            {
                                                    fprintf(fp, "update delete %s CNAME\n",row[0]); 
                                            }
                                            else
                                            {
                                                    fprintf(fp, "update delete %s.%s CNAME\n", ptr, row[0]);   
                                            }   
                                    }
                                    ptr = strtok(NULL, "|,");    
                                    index++;
                            }
                        }
                        if(row[6] != NULL)
                        {
                            ptr = strtok(row[6], "|,");    //  TXT
                            index = 0;
                            while (ptr != NULL)            
                            {  
                                    if(index == 0)
                                    {
                                            if(strcmp(ptr,"-")==0)
                                            {
                                                    fprintf(fp, "update delete %s TXT\n",row[0]); 
                                            }
                                            else
                                            {
                                                    fprintf(fp, "update delete %s.%s TXT\n", ptr, row[0]);   
                                            }       
                                    }
                                    else if(index == 2)
                                    {
                                            index = 0;
                                            if(strcmp(ptr,"-")==0)
                                            {
                                                    fprintf(fp, "update delete %s TXT\n",row[0]); 
                                            }
                                            else
                                            {
                                                    fprintf(fp, "update delete %s.%s TXT\n", ptr, row[0]);   
                                            }     
                                    }
                                    ptr = strtok(NULL, "|,");    
                                    index++;
                            } 
                        }
                        if(row[5] != NULL)
                        {
                            ptr = strtok(row[5], "|,");    //  MX
                            index = 0;
                            while (ptr != NULL)            
                            {
                                    if(index == 0)
                                    {
                                            if(strcmp(ptr,"-")==0)
                                            {
                                                    fprintf(fp, "update delete %s MX\n",row[0]); 
                                            }
                                            else
                                            {
                                                    fprintf(fp, "update delete %s.%s MX\n", ptr, row[0]);   
                                            }      
                                    }
                                    else if(index == 1)
                                    {
                                            printf("update delete %s A\n", ptr);
                                    }
                                    else if(index == 3)
                                    {
                                            index = 0;
                                            if(strcmp(ptr,"-")==0)
                                            {
                                                    fprintf(fp, "update delete %s MX\n",row[0]); 
                                            }
                                            else
                                            {
                                                    fprintf(fp, "update delete %s.%s MX\n", ptr, row[0]);   
                                            }    
                                    }
                                    ptr = strtok(NULL, "|,");    
                                    index++;
                            }
                        }


                        fprintf(fp, "send\n");

                        pclose(fp);

                        // char query[300];
                        // sprintf(query, "delete from domain where name='%s'", row[0]);
                        // printf("%s\n",query);
                        // if(mysql_query(conn,query)){
                        //         printf("query fail\n");
                        //         exit(1);
                        // }


                }
                else{
                        printf("not exist\n");
                }
        }

        mysql_close(conn);
}

