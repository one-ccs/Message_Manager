#ifndef MESSAGEMANAGER_H_INCLUDED
#define MESSAGEMANAGER_H_INCLUDED

/* -*- coding: utf-8 -*-
 *======================================================================
 * 版权    :  one-ccs 版权所有 (C) All rights reserved.
 * 文件名  :
 * 描述    :
 * 日期    :
 * 作者    :  one-ccs
 * 邮箱    :  one-ccs@foxmail.com
 * 官网    :  www.one-ccs.club

 * 修改记录:
 *----------------------------------------------------------------------
 *  版本     日期          作者          修改内容
 *
 *====================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <io.h>
#include "..\MyC_Library\ConsoleLib.h"
#include "..\MyC_Library\SocketLib.h"

//#pragma comment(lib, "ws2_32.lib")                     // 链接静态库

#define reva_list char*                                                         // 参数指针
#define reva_start(ap, arg) (ap = (va_list)&arg + sizeof(arg))                  // 指向可变参数的第一个参数地址
#define reva_arg(ap, type) (*(type*)((ap += sizeof(type)) - sizeof(type)))      // 指向可变参数的下一个参数地址
#define reva_end(ap) (ap = (va_list)0)                                          // 指向空 防止野指针

#define CONSOLE_COLS            120                      // 控制台窗口宽
#define CONSOLE_LINES           30                       // 控制台窗口高度
#define ENTERAREA_START_RAW     22                       // 输入区起始行号
#define IP_RAW                  30                       // ip 地址所在行

#define COLOR_STD               0X0A                     // 标准文本 颜色值
#define COLOR_TIP               0X60                     // 提示文本 颜色值
#define COLOR_ERROR             0XC1                     // 警告文本 颜色值
#define COLOR_ONLINE			0X20					 // 在线     颜色值
#define COLOR_OFFLINE			0X40					 // 离线	 颜色值 

#define CMD_HELP				0X10				     // 显示帮助 
#define CMD_SERVER				0X20                     // 创建服务器
#define CMD_CLIENT				0X30                     // 创建客户端
#define CMD_CLOSE				0X40                     // 关闭连接
#define CMD_EXIT				0XF0                     // 退出程序

#define APPNAME                 "MessageManager"         // 程序名
#define CONFIG                  "config"                 // 消息记录文件
#define MSGLOG                  "chat.rec"               // 消息记录文件

typedef char TIME[20];

typedef struct _appinfo {
    char *pUserName;                                     // 用户名
    char *pUserDomain;                                   // 计算机名
    IP   self_ip;
    IP   to_ip;
    char pPathPublicDocument[255];                       // 公用文档--路径
    char pPathMsgLog[255];                               // 消息记录--路径
    BOOL connection_status;                              // 连接状态
}AppInfo;

typedef struct _msg {
    TIME time;                                           // 发送时间
    IP from_ip;                                          // 本机 IP
    IP to_ip;                                            // 目标 IP
    char text[255];                                      // 消息正文
    int min_t;                                           // 分钟数
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
