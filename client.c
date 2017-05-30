#include "serverClient_TCP.h"

int main()
{
int cfd,result;
struct sockaddr_un caddr;
int value[BUF_SIZE];
char operator[BUF_SIZE];

cfd = socket(AF_UNIX , SOCK_STREAM , 0);
if(cfd == -1)
	perror("socket");

memset(&caddr , 0 ,sizeof(struct sockaddr_un));
caddr.sun_family = AF_UNIX;

strncpy(caddr.sun_path , SOCKNAME , sizeof(caddr.sun_path)-1);

bind(cfd , (struct sockaddr *) &caddr , sizeof(struct sockaddr_un));

if((connect(cfd , (struct sockaddr *) &caddr , sizeof(struct sockaddr_un))) == -1)
	perror("connect");

read(STDIN_FILENO , value , BUF_SIZE);
write(cfd , value, BUF_SIZE);

read(STDIN_FILENO , value , BUF_SIZE);
write(cfd , value , BUF_SIZE);

read(STDIN_FILENO , operator, BUF_SIZE);
write(cfd , operator , BUF_SIZE);

read(cfd , &result , 2);

printf("The server send the result: %d\n", result);

return 0;
}

