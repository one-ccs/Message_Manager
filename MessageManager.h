#ifndef MESSAGEMANAGER_H_INCLUDED
#define MESSAGEMANAGER_H_INCLUDED

/* -*- coding: utf-8 -*-
 *======================================================================
 * ��Ȩ    :  one-ccs ��Ȩ���� (C) All rights reserved.
 * �ļ���  :
 * ����    :
 * ����    :
 * ����    :  one-ccs
 * ����    :  one-ccs@foxmail.com
 * ����    :  www.one-ccs.club

 * �޸ļ�¼:
 *----------------------------------------------------------------------
 *  �汾     ����          ����          �޸�����
 *
 *====================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <io.h>
#include "..\MyC_Library\ConsoleLib.h"
#include "..\MyC_Library\SocketLib.h"

//#pragma comment(lib, "ws2_32.lib")                     // ���Ӿ�̬��

#define reva_list char*                                                         // ����ָ��
#define reva_start(ap, arg) (ap = (va_list)&arg + sizeof(arg))                  // ָ��ɱ�����ĵ�һ��������ַ
#define reva_arg(ap, type) (*(type*)((ap += sizeof(type)) - sizeof(type)))      // ָ��ɱ��������һ��������ַ
#define reva_end(ap) (ap = (va_list)0)                                          // ָ��� ��ֹҰָ��

#define CONSOLE_COLS            120                      // ����̨���ڿ�
#define CONSOLE_LINES           30                       // ����̨���ڸ߶�
#define ENTERAREA_START_RAW     22                       // ��������ʼ�к�
#define IP_RAW                  30                       // ip ��ַ������

#define COLOR_STD               0X0A                     // ��׼�ı� ��ɫֵ
#define COLOR_TIP               0X60                     // ��ʾ�ı� ��ɫֵ
#define COLOR_ERROR             0XC1                     // �����ı� ��ɫֵ
#define COLOR_ONLINE			0X20					 // ����     ��ɫֵ
#define COLOR_OFFLINE			0X40					 // ����	 ��ɫֵ 

#define CMD_HELP				0X10				     // ��ʾ���� 
#define CMD_SERVER				0X20                     // ����������
#define CMD_CLIENT				0X30                     // �����ͻ���
#define CMD_CLOSE				0X40                     // �ر�����
#define CMD_EXIT				0XF0                     // �˳�����

#define APPNAME                 "MessageManager"         // ������
#define CONFIG                  "config"                 // ��Ϣ��¼�ļ�
#define MSGLOG                  "chat.rec"               // ��Ϣ��¼�ļ�

typedef char TIME[20];

typedef struct _appinfo {
    char *pUserName;                                     // �û���
    char *pUserDomain;                                   // �������
    IP   self_ip;
    IP   to_ip;
    char pPathPublicDocument[255];                       // �����ĵ�--·��
    char pPathMsgLog[255];                               // ��Ϣ��¼--·��
    BOOL connection_status;                              // ����״̬
}AppInfo;

typedef struct _msg {
    TIME time;                                           // ����ʱ��
    IP from_ip;                                          // ���� IP
    IP to_ip;                                            // Ŀ�� IP
    char text[255];                                      // ��Ϣ����
    int min_t;                                           // ������
}Msg;

BOOL init_arg();
BOOL init_dir();
BOOL GUI_home();
BOOL connect_();
BOOL show_msg(const Msg msg, const int start_row);
BOOL create_msg(Msg msg, const char str[]);
BOOL read_msg();
BOOL write_msg(Msg msg);
BOOL main_loop(int argc, char *argv[]);
WORD verify_cmd(Cmd cmd[], const WORD cmd_len);
BOOL show_tip(const char *text);
BOOL chat_loop();
BOOL goto_enter();

#endif // MESSAGEMANAGER_H_INCLUDED
