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
#include "MessageManager.h"

char logo[] = {
    /*--  ������һ��ͼ��C:\Users\Administrator\Desktop\�ޱ���.bmp  --*/
    /*--  ���x�߶�=101x15  --*/
    /*--  ��Ȳ���8�ı������ֵ���Ϊ�����x�߶�=104x15  --*/
    0xF0,0x38,0x00,0x00,0x0F,0x03,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0x78,0x00,
    0x00,0x0F,0x07,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0x78,0x00,0x00,0x0F,0x07,
    0x80,0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0xF9,0xF1,0xFC,0x0F,0x8F,0x9F,0xBF,0xCF,
    0xC7,0xF1,0xF9,0xF8,0xF8,0xFB,0x9B,0x9C,0x0F,0x8F,0x9B,0xFD,0xCD,0xEE,0x73,0xBD,
    0xC0,0xFD,0xFB,0x87,0x1C,0x0F,0xDF,0x81,0xFC,0xE0,0xFC,0x77,0x1D,0xC0,0xFD,0xFB,
    0xE7,0x1C,0x0F,0xDF,0x8F,0xF8,0xE7,0xFC,0x77,0xFD,0xC0,0xEF,0xB8,0xFF,0x1C,0x0E,
    0xFB,0xBD,0xF8,0xFE,0xFC,0x77,0x01,0xC0,0xEF,0xB8,0x3F,0x1C,0x0E,0xFB,0xB9,0xF8,
    0xFC,0xFC,0x77,0x01,0xC0,0xE7,0x3B,0x3B,0x9C,0x0E,0x73,0xBB,0xF8,0xFD,0xEE,0x73,
    0x99,0xC0,0xE7,0x39,0xF1,0xFC,0x0E,0x73,0x9F,0xF8,0xEF,0xE7,0xF1,0xF9,0xC0,0x00,
    0x00,0x00,0x1C,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x00,0x00,0x00,0x00,0x00,0x1C,
    0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x00,0x00,0x00,0x00,0x03,0x3C,0x00,0x00,0x00,
    0x00,0x00,0x0C,0xF0,0x00,0x00,0x00,0x00,0x01,0xF0,0x00,0x00,0x00,0x00,0x00,0x07,
    0xC0,0x00,0x00,
};

char bilibili_logo[] = 
    "                 // \n"
    "     \\\\         // \n"
    "      \\\\       // \n"
    "##DDDDDDDDDDDDDDDDDDDDDD##\n"
    "## DDDDDDDDDDDDDDDDDDDD ##    ________   ___   ___        ___   ________   ___   ___        ___ \n"
    "## hh                hh ##   |\\   __  \\ |\\  \\ |\\  \\      |\\  \\ |\\   __  \\ |\\  \\ |\\  \\      |\\  \\ \n"
    "## hh    //    \\\\    hh ##   \\ \\  \\|\\ /_\\ \\  \\\\ \\  \\     \\ \\  \\\\ \\  \\|\\ /_\\ \\  \\\\ \\  \\     \\ \\  \\ \n"
    "## hh   //      \\\\   hh ##    \\ \\   __  \\\\ \\  \\\\ \\  \\     \\ \\  \\\\ \\   __  \\\\ \\  \\\\ \\  \\     \\ \\  \\ \n"
    "## hh                hh ##     \\ \\  \\|\\  \\\\ \\  \\\\ \\  \\____ \\ \\  \\\\ \\  \\|\\  \\\\ \\  \\\\ \\  \\____ \\ \\  \\ \n"
    "## hh      wwww      hh ##      \\ \\_______\\\\ \\__\\\\ \\_______\\\\ \\__\\\\ \\_______\\\\ \\__\\\\ \\_______\\\\ \\__\\ \n"
    "## hh                hh ##       \\|_______| \\|__| \\|_______| \\|__| \\|_______| \\|__| \\|_______| \\|__| \n"
    "## MMMMMMMMMMMMMMMMMMMM ##\n"
    "##MMMMMMMMMMMMMMMMMMMMMM##                             Release 2.6.1. Powered by jinkela-core 2.5.4.\n"
    "     \\/            \\/\n"
;

AppInfo app;
short old_min = -1;
WORD last_tip = 0;
WORD last_error = 0;

BOOL init_arg() {
	app.pUserName = getenv("USERNAME");
	app.pUserDomain = getenv("USERDOMAIN");
	SL_GetLocalIp(app.self_ip);
	strcpy(app.to_ip, "");
	sprintf(app.pPathPublicDocument, "C:\\Users\\%s\\Documents\\%s\\", app.pUserName, APPNAME);
	sprintf(app.pPathMsgLog, "C:\\Users\\%s\\Documents\\%s\\%s", app.pUserName, APPNAME, MSGLOG);
	app.connection_status = FALSE;

	//printf("Path Lists:\n%s\n%s\n", app.pPathPublicDocument, app.pPathMsgLog);
	return TRUE;
}

BOOL init_dir() {
	/**
	 * ��ʼ��ϵͳĿ¼���ļ�
	 */
 	FILE *fp;

	// �ж��ļ����Ƿ����
	if(access(app.pPathPublicDocument, 0) == -1) {
		// �������򴴽�
		mkdir(app.pPathPublicDocument);
	}

	// �ж���Ϣ��¼�ļ��Ƿ����
	if(access(app.pPathMsgLog, 0) == -1) {
		// �������򴴽�
		fp = fopen(app.pPathMsgLog, "wb+");
		if(fp != NULL) {
			fclose(fp);
		}
	}

	return TRUE;
}

BOOL main_loop(int argc, char *argv[]) {
	STR str;
	WORD vc = 0x00;	// ����λ��ʾ�������λ��ʾ�������� 
	
    CL_SetSize(120, 30);
    CL_SetColor(0x0a);
	init_arg();
	// init_dir();
    GUI_home();
    if(argc > 1) {
		strcpy(str, argv[1]);
	}
	while(strcmp(str, "-exit") != 0 && strcmp(str, "-quit") != 0) {
    	Cmd cmd[8] = {0};
    	WORD cmd_len = sizeof(cmd) / sizeof(Cmd);

    	goto_enter();
    	CL_Filler(2, ENTERAREA_START_RAW, CONSOLE_COLS - 4, 1, " ");
    	if(argc == 1) {
			gets(str);
		}
    	if(last_tip) {
			CL_Filler(0, IP_RAW + 1, CONSOLE_COLS, 1, " ");
			last_tip = 0;
    	}
        CL_AnalyzeCmd(cmd, cmd_len, str);
        vc = verify_cmd(cmd, cmd_len);
        switch(vc & 0xf0) {
			case CMD_HELP:
				printf("����,key:<%s>,value:<%s>", cmd[vc & 0x0f].key, cmd[vc & 0x0f].value);
				break;
			case CMD_SERVER: {
				if(strcmp(cmd[vc & 0x0f].value, "") == 0) {
					show_tip("��Ч������, ȱ��ֵ'Port'. �﷨��</SERVER [PORT]>.");
					continue;
				}
				STR text = "";
				int port;
				sscanf(cmd[vc & 0x0f].value, "%d", &port);
				SOCKET ListenerSocket;
				SOCKET NewConnection;
				show_tip("�ɹ��������������ȴ��ͻ���������...");
				NewConnection = SL_CreateListener(ListenerSocket, port);
				CL_Filler(0, IP_RAW + 1, CONSOLE_COLS, 1, " ");
				show_tip("�ͻ������ӳɹ�.");
				CL_SetTitle("MessageManager SERVER");
				
				while(1) {
			    	recv(NewConnection, text, 255, 0);
			    	CL_Filler(2, ENTERAREA_START_RAW, CONSOLE_COLS - 4, 1, " ");
			    	goto_enter();
			    	if(strcmp(text, "-close") == 0) {
						printf("�ͻ����ѶϿ�����.");
						closesocket(NewConnection);
						break;
					}
					else {
						printf("�ͻ��˷�����Ϣ��\"%s\"", text);
					}
				}
				argc = 1;
				break;
			}
			case CMD_CLIENT: {
				STR text = "";
				IP ip;
				int port;
				SOCKET client;
				
		    	goto_enter();
		    	CL_Filler(2, ENTERAREA_START_RAW, CONSOLE_COLS - 4, 1, " ");
				printf("������Ŀ�� ip��");
				scanf("%s", ip);
		    	goto_enter();
		    	CL_Filler(2, ENTERAREA_START_RAW, CONSOLE_COLS - 4, 1, " ");
		    	
				printf("������Ŀ�� �˿ںţ�");
				scanf("%d", &port);
		    	goto_enter();
		    	CL_Filler(2, ENTERAREA_START_RAW, CONSOLE_COLS - 4, 1, " ");
  	
				if(SL_CreateClient(&client, ip, port)) {
					CL_SetPosition(60, IP_RAW);
					CL_ColorPrint(COLOR_ONLINE, "�� Ŀ�� IP��%s ", ip);
					show_tip("���ӳɹ�.");
					CL_SetTitle("MessageManager CLIENT");
				}
				else {
					show_tip("����ʧ��.");
				}
				fflush(stdin);
				
				while(1) {
			    	goto_enter();
			    	CL_Filler(2, ENTERAREA_START_RAW, CONSOLE_COLS - 4, 1, " ");
			        gets(text);
			        if(strcmp(text, "-close") == 0) {
						send(client, text, strlen(text), 0);
						closesocket(client);
						break;
					}
			    	else if(strcmp(text, "-exit") == 0 || strcmp(text, "-exit") == 0) {
						exit(0);
					}
				}
				argc = 1;
				break;
			}
			case CMD_CLOSE:
				WSACleanup();
				break;
			case CMD_EXIT:
				exit(0);
				break;
		 	default:
	 			show_bilibili();
		 		show_tip("��Ч������, �������롣");
		}
        // if(key_index != -1) printf("key:<%s>,value:<%s>", cmd[key_index].key, cmd[key_index].value);
	}

    return TRUE;
}

WORD verify_cmd(Cmd cmd[], const WORD cmd_len) {
	STR key;
	char invalid[16][255] = {0};
	WORD invalid_count = 0, i;
	int result = 0;
	
	for(i = 0; i < cmd_len && strcmp(cmd[i].key, ""); i++) {
		strcpy(key, cmd[i].key + 1);
		
		if(strcmp(key, "help") == 0 || strcmp(key, "?") == 0 || strcmp(key, "h") == 0) {	// ���� 
			result = CMD_HELP | i;
		}
		else if(strcmp(key, "server") == 0) {
			result = CMD_SERVER | i;
		}
		else if(strcmp(key, "client") == 0) {
			result = CMD_CLIENT | i;
		}
		else if(strcmp(key, "close") == 0) {
			result = CMD_CLOSE | i;
		}
		else if(strcmp(key, "exit") == 0 || strcmp(key, "e") == 0 || 
				strcmp(key, "quit") == 0 || strcmp(key, "q") == 0) {
			result = CMD_EXIT | i;
		}
		else {
			strcpy(invalid[invalid_count++], cmd[i].key);
		}
	}
	
	if(invalid_count) CL_SetPosition(0, IP_RAW + 1);
	for(i = 0; i < invalid_count; i++) {
		CL_ColorPrint(COLOR_TIP, "'%s'", invalid[i]);
	}
	if(invalid_count) {
		CL_ColorPrint(COLOR_TIP, "���ǿ�ʶ������");
		last_tip = 1;
	}

	return result;
}

BOOL show_bilibili() {
	system("cls");
	printf("%s", bilibili_logo);

	return TRUE;
}

BOOL show_tip(const char *text) {
	CL_SetPosition(0, IP_RAW + 1);
	CL_ColorPrint(COLOR_TIP, text);
	last_tip = 1;
	
	return TRUE;
}

BOOL chat_loop() {
    Msg msg;
	char str[255] = "";

	if(!connect_()) {
        return FALSE;
	}

    CL_SetPosition(2, CONSOLE_LINES - 10);
    printf(" �������ݣ�");
	while(strcmp(str, "-exit") != 0 && strcmp(str, "-quit") != 0 && strcmp(str, "-esc") != 0) {
        CL_Filler(22, CONSOLE_LINES - 7, 80, 6, " ");
		CL_SetPosition(22, CONSOLE_LINES - 7);
		fflush(stdin);
		gets(str);
		if(!strcmp(str, "-h")) {
            char command[255];
            sprintf(command, "notepad %s", app.pPathMsgLog);
            system(command);
		}
		create_msg(msg, str);
		write_msg(msg);
	}


	return TRUE;
}

BOOL GUI_home() {
	CL_SetTitle("Message Manager");
	CL_SetSize(CONSOLE_COLS, CONSOLE_LINES + 3);
	CL_SetBufferSize(CONSOLE_COLS, CONSOLE_LINES + 3);
	CL_SetColor(0x0A);

    // ���� logo
    CL_PrintModePictrue(10 , 3, logo, 104, 15);
    CL_Filler(48, 15, 28, 1, "-");
    CL_SetPosition(48, 16);
    printf("|    Powered By one-ccs    |");
    CL_Filler(48, 17, 28, 1, "-");

    CL_Filler(0, 0, CONSOLE_COLS / 2, 1, "�I");
    CL_Filler(0, 20, CONSOLE_COLS, 1, "-");
    CL_Filler(0, 29, CONSOLE_COLS, 1, "=");
    CL_Filler(0, 1, 1, 28, "|");
    CL_Filler(CONSOLE_COLS - 1, 1, 1, 28, "|");

    CL_SetPosition(2, 20);
    CL_ColorPrint(0x02, " ��ӭʹ�� Message Manager���������-h���鿴������");

    CL_SetPosition(0, 30);
	CL_ColorPrint(COLOR_ONLINE, "�� ���� IP��%s ", app.self_ip);
    CL_SetPosition(60, 30);
	CL_ColorPrint(COLOR_OFFLINE, "�� Ŀ�� IP��- - - ( ���� )");

    return 0;
}

BOOL show_help() {
	system("cls");

    CL_Filler(0, 0, CONSOLE_COLS / 2, 1, "�I");
    CL_Filler(0, 20, CONSOLE_COLS, 1, "-");
    CL_Filler(0, 29, CONSOLE_COLS, 1, "=");
    CL_Filler(0, 1, 1, 28, "|");
    CL_Filler(CONSOLE_COLS - 1, 1, 1, 28, "|");

	return TRUE;
}

BOOL connect_() {
	IP to_ip = "";
	char str[255] = "";

	CL_SetPosition(2, CONSOLE_LINES - 8);
	CL_ColorPrint(0x8A, "������Ŀ�� ip��");
	scanf("%s", to_ip);
	if(strcmp(to_ip, "-exit") == 0 || strcmp(to_ip, "-quit") == 0 || strcmp(to_ip, "-esc") == 0) {
        exit(0);
    }
    else if(!strcmp(to_ip, ".")) {
        strcpy(to_ip, app.self_ip);
    }
	CL_Filler(0, CONSOLE_LINES, CONSOLE_COLS, 1, " ");
	sprintf(str, "\\\\%s\\Users\\Public\\Documents\\%s\\%s", to_ip, APPNAME, MSGLOG);
	CL_SetPosition(0, CONSOLE_LINES + 1);
	CL_ColorPrint(0x8a, "�������ӣ����Ժ�...");
	if(access(str, 0) == 0) {
        CL_SetPosition(0, CONSOLE_LINES + 1);
        CL_ColorPrint(0x0a, "\t\t\t\t\t");
	    CL_SetPosition(0, CONSOLE_LINES + 1);
        CL_ColorPrint(0x0e, "���ӳɹ�.");
        strcpy(app.to_ip, to_ip);
        app.connection_status = TRUE;
        CL_SetPosition(0, 9);
        CL_ColorPrint(0x0e, to_ip);
	}
	else {
        CL_SetPosition(0, CONSOLE_LINES + 1);
        CL_ColorPrint(0x0a, "\t\t\t\t\t");
	    CL_SetPosition(0, CONSOLE_LINES + 1);
        CL_ColorPrint(0x0e, "����ʧ��,������!");
        app.connection_status = FALSE;
		return FALSE;
	}

    return TRUE;
}

BOOL show_msg(const Msg msg, const int start_row) {
    int deffer_min = msg.min_t - old_min;
    int flag = 0;
    if(old_min == -1 && (deffer_min > 1 || deffer_min < -1)) {
        // ��� 5 ���ӲŸ���ʱ��
        CL_SetPosition(60, start_row);
        CL_ColorPrint(0x71, msg.time);
        flag = 1;
    }
    else {
        flag = 0;
    }

    if(!strcmp(msg.from_ip, app.self_ip)) {
        // ��ʾ���ұ�
        CL_SetPosition(21, start_row + flag);
        CL_ColorPrint(0x0a, "�� %s ��", msg.from_ip);
        CL_SetPosition(21, start_row + flag + 1);
        CL_ColorPrint(0x0a, "    %s", msg.text);
    }
    else {
        CL_SetPosition(21, start_row + flag);
        CL_ColorPrint(0x0a, "�� %s ��", msg.from_ip);
        CL_SetPosition(21, start_row + flag + 1);
        CL_ColorPrint(0x0a, "    %s", msg.text);
    }

    CL_SetPosition(21, 4);

    return TRUE;
}

BOOL create_msg(Msg msg, const char str[]) {
	int RealYear, Real_mon, Real_mday, RealHour, RealMin, RealSec;
    time_t timep;
    struct tm *p;
    time(&timep);
    p = gmtime(&timep);
    RealSec = p -> tm_sec;                //��
    RealMin = p -> tm_min;                //��
    RealHour = 8 + p -> tm_hour;          //ʱ
    Real_mday = p -> tm_mday;             //��
    Real_mon = 1 + p -> tm_mon;           //��
    RealYear = 1900 + p -> tm_year;       //��
    TIME time;
    sprintf(time, "%d/%02d/%02d %02d:%02d:%02d" \
           , RealYear, Real_mon, Real_mday \
           , RealHour, RealMin, RealSec);

    strcpy(msg.time, time);
    strcpy(msg.from_ip, app.self_ip);
    strcpy(msg.to_ip, app.to_ip);
    strcpy(msg.text, str);
    msg.min_t = RealMin;

    show_msg(msg, 1);
    old_min = RealMin;

    return TRUE;
}

BOOL read_msg() {


    return TRUE;
}

BOOL write_msg(Msg msg) {
	FILE *fp;
	char connect[255];

	fp = fopen(app.pPathMsgLog, "ab+");
	if(fp != NULL) {
        printf("[ %s ] From < %s > To < %s > -- %s\n\n", msg.time, msg.from_ip, msg.to_ip, msg.text);
		sprintf(connect, "[ %s ] From < %s > To < %s > -- %s\n", msg.time, msg.from_ip, msg.to_ip, msg.text);
		fprintf(fp, connect);
		fclose(fp);
	}

	return TRUE;
}

BOOL goto_enter() {
    return CL_SetPosition(2, ENTERAREA_START_RAW);
}
