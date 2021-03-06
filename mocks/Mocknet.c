/* AUTOGENERATED FILE. DO NOT EDIT. */
#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
#include "unity.h"
#include "cmock.h"
#include "Mocknet.h"

typedef struct _CMOCK_readSocket_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  int ReturnVal;
  int Expected_sock;
  char* Expected_recvline;

} CMOCK_readSocket_CALL_INSTANCE;

typedef struct _CMOCK_writeSocket_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  int ReturnVal;
  int Expected_sock;
  char* Expected_sendline;

} CMOCK_writeSocket_CALL_INSTANCE;

typedef struct _CMOCK_connectToServer_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  int ReturnVal;
  void* Expected_sock_desc;

} CMOCK_connectToServer_CALL_INSTANCE;

static struct MocknetInstance
{
  CMOCK_MEM_INDEX_TYPE readSocket_CallInstance;
  CMOCK_MEM_INDEX_TYPE writeSocket_CallInstance;
  CMOCK_MEM_INDEX_TYPE connectToServer_CallInstance;
} Mock;

extern jmp_buf AbortFrame;

void Mocknet_Verify(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.readSocket_CallInstance, cmock_line, "Function 'readSocket' called less times than expected.");
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.writeSocket_CallInstance, cmock_line, "Function 'writeSocket' called less times than expected.");
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.connectToServer_CallInstance, cmock_line, "Function 'connectToServer' called less times than expected.");
}

void Mocknet_Init(void)
{
  Mocknet_Destroy();
}

void Mocknet_Destroy(void)
{
  CMock_Guts_MemFreeAll();
  memset(&Mock, 0, sizeof(Mock));
}

int readSocket(int sock, char* recvline)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_readSocket_CALL_INSTANCE* cmock_call_instance = (CMOCK_readSocket_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.readSocket_CallInstance);
  Mock.readSocket_CallInstance = CMock_Guts_MemNext(Mock.readSocket_CallInstance);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "Function 'readSocket' called more times than expected.");
  cmock_line = cmock_call_instance->LineNumber;
  {
    UNITY_TEST_ASSERT_EQUAL_INT(cmock_call_instance->Expected_sock, sock, cmock_line, "Function 'readSocket' called with unexpected value for argument 'sock'.");
  }
  {
    UNITY_TEST_ASSERT_EQUAL_STRING(cmock_call_instance->Expected_recvline, recvline, cmock_line, "Function 'readSocket' called with unexpected value for argument 'recvline'.");
  }
  return cmock_call_instance->ReturnVal;
}

void CMockExpectParameters_readSocket(CMOCK_readSocket_CALL_INSTANCE* cmock_call_instance, int sock, char* recvline)
{
  cmock_call_instance->Expected_sock = sock;
  cmock_call_instance->Expected_recvline = recvline;
}

void readSocket_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, int sock, char* recvline, int cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_readSocket_CALL_INSTANCE));
  CMOCK_readSocket_CALL_INSTANCE* cmock_call_instance = (CMOCK_readSocket_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "CMock has run out of memory. Please allocate more.");
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.readSocket_CallInstance = CMock_Guts_MemChain(Mock.readSocket_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  CMockExpectParameters_readSocket(cmock_call_instance, sock, recvline);
  cmock_call_instance->ReturnVal = cmock_to_return;
}

int writeSocket(int sock, char* sendline)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_writeSocket_CALL_INSTANCE* cmock_call_instance = (CMOCK_writeSocket_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.writeSocket_CallInstance);
  Mock.writeSocket_CallInstance = CMock_Guts_MemNext(Mock.writeSocket_CallInstance);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "Function 'writeSocket' called more times than expected.");
  cmock_line = cmock_call_instance->LineNumber;
  {
    UNITY_TEST_ASSERT_EQUAL_INT(cmock_call_instance->Expected_sock, sock, cmock_line, "Function 'writeSocket' called with unexpected value for argument 'sock'.");
  }
  {
    UNITY_TEST_ASSERT_EQUAL_STRING(cmock_call_instance->Expected_sendline, sendline, cmock_line, "Function 'writeSocket' called with unexpected value for argument 'sendline'.");
  }
  return cmock_call_instance->ReturnVal;
}

void CMockExpectParameters_writeSocket(CMOCK_writeSocket_CALL_INSTANCE* cmock_call_instance, int sock, char* sendline)
{
  cmock_call_instance->Expected_sock = sock;
  cmock_call_instance->Expected_sendline = sendline;
}

void writeSocket_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, int sock, char* sendline, int cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_writeSocket_CALL_INSTANCE));
  CMOCK_writeSocket_CALL_INSTANCE* cmock_call_instance = (CMOCK_writeSocket_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "CMock has run out of memory. Please allocate more.");
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.writeSocket_CallInstance = CMock_Guts_MemChain(Mock.writeSocket_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  CMockExpectParameters_writeSocket(cmock_call_instance, sock, sendline);
  cmock_call_instance->ReturnVal = cmock_to_return;
}

int connectToServer(void* sock_desc)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_connectToServer_CALL_INSTANCE* cmock_call_instance = (CMOCK_connectToServer_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.connectToServer_CallInstance);
  Mock.connectToServer_CallInstance = CMock_Guts_MemNext(Mock.connectToServer_CallInstance);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "Function 'connectToServer' called more times than expected.");
  cmock_line = cmock_call_instance->LineNumber;
  {
    UNITY_TEST_ASSERT_EQUAL_PTR(cmock_call_instance->Expected_sock_desc, sock_desc, cmock_line, "Function 'connectToServer' called with unexpected value for argument 'sock_desc'.");
  }
  return cmock_call_instance->ReturnVal;
}

void CMockExpectParameters_connectToServer(CMOCK_connectToServer_CALL_INSTANCE* cmock_call_instance, void* sock_desc)
{
  cmock_call_instance->Expected_sock_desc = sock_desc;
}

void connectToServer_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, void* sock_desc, int cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_connectToServer_CALL_INSTANCE));
  CMOCK_connectToServer_CALL_INSTANCE* cmock_call_instance = (CMOCK_connectToServer_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "CMock has run out of memory. Please allocate more.");
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.connectToServer_CallInstance = CMock_Guts_MemChain(Mock.connectToServer_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  CMockExpectParameters_connectToServer(cmock_call_instance, sock_desc);
  cmock_call_instance->ReturnVal = cmock_to_return;
}

