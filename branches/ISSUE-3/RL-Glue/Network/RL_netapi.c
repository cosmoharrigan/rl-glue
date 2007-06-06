/* Standard Headers */
#include <string.h>

/* Network Headers */
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>

/* RLnet Library Header */
#include <Network/RL_netapi.h>

rlSocket rlOpen(short thePort)
{
  int flag = 1;
  rlSocket theSocket = 0;

  theSocket = socket(PF_INET, SOCK_STREAM, 0);
  setsockopt(theSocket, IPPROTO_TCP, TCP_NODELAY, (char*)&flag, sizeof(int));

  return theSocket;
}

rlSocket rlAcceptConnection(rlSocket theSocket)
{
  rlSocket theClient = 0;
  struct sockaddr_in theClientAddress = {0};
  unsigned int theSocketSize = sizeof(struct sockaddr_in);
  theClient = accept(theSocket, (struct sockaddr*)&theClientAddress, &theSocketSize);
  return theClient;
}

int rlConnect(rlSocket theSocket, const char* theAddress, short thePort)
{
  int theStatus = 0;
  struct sockaddr_in theDestination;
  theDestination.sin_family = AF_INET;
  theDestination.sin_port = htons(thePort);
  theDestination.sin_addr.s_addr = inet_addr(theAddress);
  memset(&theDestination.sin_zero, '\0', 8);

  theStatus = connect(theSocket, 
		      (struct sockaddr*)&theDestination, 
		      sizeof(struct sockaddr));

  return theStatus;
}

int rlListen(rlSocket theSocket, short thePort)
{
  struct sockaddr_in theServer;
  int theStatus = 0;
  int yes = 1;
  
  theServer.sin_family = AF_INET;
  theServer.sin_port = htons(thePort);
  theServer.sin_addr.s_addr = INADDR_ANY;
  memset(&theServer.sin_zero, '\0', 8);
  
  /* We don't really care if this fails... */
  setsockopt(theSocket, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));

  theStatus = bind(theSocket, 
		   (struct sockaddr*)&theServer, 
		   sizeof(struct sockaddr));

  if (theStatus == -1) return -1;
  
  theStatus = listen(theSocket, 10);
  if (theStatus == -1) return -1;

  return theStatus;
}

int rlClose(rlSocket theSocket)
{
  return close(theSocket);
}

int rlIsValidSocket(rlSocket theSocket)
{
  return theSocket != -1;
}

int rlSendData(rlSocket theSocket, const void* theData, int theLength)
{
  int theBytesSent = 0;
  int theMsgError = 0;

  const char* theDataBuffer = (const char*)theData;
  
  while (theBytesSent < theLength)
  {
    theMsgError = send(theSocket, theDataBuffer + theBytesSent, theLength - theBytesSent, 0);
    if (theMsgError == -1) break;
    else theBytesSent += theMsgError;
  }

  return theBytesSent;
}

int rlRecvData(rlSocket theSocket, void* theData, int theLength)
{
  int theBytesRecv = 0;
  int theMsgError = 0;

  char* theDataBuffer = (char*)theData;

  while (theBytesRecv < theLength)
  {
    theMsgError = recv(theSocket, theDataBuffer + theBytesRecv, theLength - theBytesRecv, 0);
    if (theMsgError <= 0) break;
    else theBytesRecv += theMsgError;
  }

  return theBytesRecv;
}

int rlGetSystemByteOrder()
{
  /*
    Endian will be 1 when we are on a little endian machine,
    and not 1 on a big endian machine.
  */

  const int one = 1;
  const char endian = *(char*)&one;

  return endian;
}
