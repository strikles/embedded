/**
 * @file server.c
 * @brief server
 * server prototypes
 *
 * @author Claudio Neto
 *
 * @date 3/11/2015
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

#include <pthread.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>

#include "cdefines.h"
#include "cnet.h"
#include "csensors.h"
#include "cxml.h"
#include "server.h"

#define TEST

#ifdef TEST
#include "tests/test.h"
#endif

int socket_desc;

int main(int argc, char *argv[])
{
  int client_sock, c, invalid_status = 0;
  struct sockaddr_in server, client;

  srand (time(NULL));

  struct sigaction  sigIntHandler;

  // prepare for shutdowncb
  // only sigint ? sigstp + sigquit
  sigIntHandler.sa_handler = shutdownHandler;
  sigemptyset(&sigIntHandler.sa_mask);
  sigIntHandler.sa_flags = 0;
  sigaction(SIGINT, &sigIntHandler, NULL);

  // load last know configuration values
  readConfig();

  //Create socket
  if((socket_desc = socket(AF_INET, PROTOCOL_TYPE, 0)) == -1)
  {
    perror("Could not create socket");
    return 1;
  }

  //Prepare the sockaddr_in structure
  bzero(&server, sizeof server);
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = INADDR_ANY;
  server.sin_port = htons(SRV_PORT);

  //Bind
  if(bind(socket_desc, (struct sockaddr *) &server, sizeof(server)) < 0)
  {
    //print the error message
    perror("ERROR: bind failed");
    return 1;
  }

  //Listen
  listen(socket_desc, 3);

  //Accept and incoming connection
  puts("Waiting for incoming connections...");
  c = sizeof(struct sockaddr_in);
  pthread_t thread_id;
  while((client_sock = accept(socket_desc, (struct sockaddr *) &client,
      (socklen_t*) &c)))
  {
    puts("Connection accepted");
    if(pthread_create(&thread_id, NULL, connection_handler,
        (void*) &client_sock) < 0)
    {
      perror("could not create thread");
      invalid_status = 1;
      break;
    }

    // pthread_exit callback ?
    // pthread_join( thread_id , NULL);
    puts("Handler assigned");
  }

  if(client_sock < 0)
  {
    perror("accept failed");
    invalid_status = 1;
  }

  return invalid_status;
}

/*
 * callback for each client
 * */
void *connection_handler(void *socket_desc)
{
  // buffers
  char recvline[MAX_MSG_LEN];
  char sendline[MAX_MSG_LEN];
  // socket fd
  int sock = *(int*) socket_desc;
  // socket status
  int read_size = 0, write_size = 0;
  // xml reply status
  int invalid_response = 0;

  int counter = 0;
  while(1)
  {
    counter++;
    printf("%d\n", counter);

    // zero buffers
    bzero(recvline, sizeof recvline);
    bzero(sendline, sizeof sendline);

    // read client msg
    if((read_size = readSocket(sock, recvline)) == -1)
    {
      perror("ERROR: readSocket");
      break;
    }

    // build XML string response
    if((invalid_response = buildReplyXML(recvline, sendline, read_size)))
    {
      perror("ERROR: invalid response");
      break;
    }

    // write msg to client
    if((write_size = writeSocket(sock, sendline)) == -1)
    {
      perror("ERROR: writeSocket");
      break;
    }

    break;
  }

  puts("callback cleanup: close socket + exit thread");
  close(sock);
  pthread_exit (NULL);

  return 0;
}

/**
 * Unused
 */
void exitHandler()
{
  puts("clean exit ?");
}

/**
 * shutdown handler to write config
 */
void shutdownHandler(int s)
{
  close(socket_desc);
  writeConfig();

  atexit(exitHandler);
  exit (EXIT_SUCCESS);
}
