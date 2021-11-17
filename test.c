#include <stdio.h>
#include <string.h>
#include <stdlib.h>



#include "/usr/include/mysql/mysql.h"


void main(){
        MYSQL *conn;
        MYSQL_RES *res;
        MYSQL_ROW row;

        char *server = "tjad.asuscomm.com";                            //혹은 ip
        char *user = "admin";
        char *password = "dlgks~123";
        char *database = "dnsserver";

        if( !(conn = mysql_init((MYSQL*)NULL))){        //초기화 함수
                printf("init fail\n");
                exit(1);
        }

        printf("mysql_init sucsess.\n");

        if(!mysql_real_connect(conn, server, user, password, NULL, 3306, NULL, 0)){
                printf("connect error.\n");     //DB접속 (MYSQL*, host, id, pw, null, port, 0)
                exit(1);
        }

        printf("mysql_real_connect suc.\n");


        if(mysql_select_db(conn, database) != 0){
                mysql_close(conn);
                printf("select_db fail.\n");
                exit(1);
        }
        printf("select mydb suc.\n");



        //printf("%d", mysql_query(conn,"select * from testtab" ));   //성공시 0리턴 (false)

        if(mysql_query(conn,"select name,date < now() ,ipA,ipAAAA,cname,mx,spf from domain" )){
                printf("query fail\n");
                exit(1);
        }

        printf("query sucsess\n");

        res = mysql_store_result(conn);                 //쿼리에 대한 결과를 row에 저장
        printf("res suceese\n");



        while( (row=mysql_fetch_row(res))!=NULL){
                printf("[%s %s]\n", row[0],row[1]);       //이전과 같이 디비테이블을 만들었다면 id와 패스워드값이 나온>다.

                if(strcmp(row[1],"1")==0)
                {
                        FILE *fp = NULL;

                        if((fp = popen("/usr/bin/nsupdate -k /usr/bin/Kofficialsite.kr.+157+63315.private -v", "w")) == NULL) {
                                return;
                        }

                        // 오류 위치에 대한 로그를 생성하라는 명령어 전달
                        fprintf(fp, "server officialsite.kr\n");

                        // gdb를 종료하라는 명령어 전달
                        fprintf(fp, "zone officialsite.kr\n");
 
 
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
                                                    printf("update delete %s A\n",row[0]); 
                                                    fprintf(fp, "update delete %s A\n",row[0]); 
                                            }
                                            else
                                            {
                                                    printf("update delete %s.%s A\n", ptr, row[0]);
                                                    fprintf(fp, "update delete %s.%s A\n", ptr, row[0]);   
                                            }      
                                    }
                                    else if(index == 2)
                                    {
                                            index = 0;
                                            if(strcmp(ptr,"-")==0)
                                            {
                                                    printf("update delete %s A\n",row[0]); 
                                                    fprintf(fp, "update delete %s A\n",row[0]); 
                                            }
                                            else
                                            {
                                                    printf("update delete %s.%s A\n", ptr, row[0]);
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
                        printf("일치하지않음\n");
                }
        }

        mysql_close(conn);
}

