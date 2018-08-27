/*
 * pub.h
 *
 *  Created on: 2014-3-10
 *      Author: zhujy
 */

#ifndef PUB_H_
#define PUB_H_
//发送文件
int send_work(const char *hostname, int port, const char *filename);
//接收文件
int recv_work(int port);

#endif /* PUB_H_ */
