
// cfg_op.h

#ifndef _INC_CFG_OP_H
#define _INC_CFG_OP_H

#ifdef  __cplusplus
extern "C" {
#endif

//获取配置项
int GetCfgItem(char *pFileName /*in*/, char *pKey /*in*/, char * pValue/*in out*/, int * pValueLen /*out*/);
//设置配置项
int SetCfgItem(char *pFileName /*in*/, char *pKey /*in*/, char * pValue/*in*/, int ValueLen /*in*/);


#ifdef  __cplusplus
}
#endif

#endif 
