#include "serverClient_TCP.h"
#define BLOCKLOG 10
int main()
{
int sfd , cfd , a,b,result;
int value1[BUF_SIZE] ;
char operator[BUF_SIZE] , c;
struct sockaddr_un saddr;

sfd = socket(AF_UNIX , SOCK_STREAM, 0);
if(sfd == -1)
	perror("socket");

remove(SOCKNAME);

memset(&saddr , 0 , sizeof(struct sockaddr_un));

saddr.sun_family = AF_UNIX;
strncpy(saddr.sun_path , SOCKNAME , sizeof(saddr.sun_path)-1);

if((bind(sfd , (struct sockaddr *) &saddr , sizeof(struct sockaddr_un))) == -1)
	perror("bind");

if((listen(sfd , BLOCKLOG)) ==-1)
	perror("listen");

cfd = accept(sfd , NULL ,NULL);
if(cfd == -1)
	perror("accept");

		read(cfd , value1 ,BUF_SIZE);
		a = atoi(value1);


		read(cfd , value1 ,BUF_SIZE);
		b = atoi(value1);

		read(cfd , operator ,BUF_SIZE);
		c = operator[0];



if(c == '+')
	result = a+ b;
if(c == '*')
	result = a* b;
if(c == '-')
	result = a- b;
if(c == '/')
	result = a/ b;

write(cfd , &result , 2);

if(close(cfd) == -1)
	perror("close");

return 0;

}
