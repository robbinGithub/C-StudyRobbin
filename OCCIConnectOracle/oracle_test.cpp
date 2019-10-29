/***************************����oracle�����ṩOCCI��ʽ�������ݿ�*******************/

//�����Ŀ�ľ�����֤makefile��oracle��ͷ�ļ���lib�ļ�·���Ƿ���ȷ��
#include <iostream>
#define WIN32COMMON //���⺯���ض������
#include <occi.h>
using namespace std;
using namespace oracle::occi;


int main()
{  
	// static 
	/*string s1 = "robbin";
	string s2 = "robbin";
	cout << "s1 addr:"<< */


	cout << "====================================================================" << endl;
	//system("pause");
	//����OCCI�����Ļ���
	Environment *env = Environment::createEnvironment("AL32UTF8", "UTF8"); 
	if (NULL == env) {
		printf("createEnvironment error.\n");
		return -1;
	}
	else
		cout << "success" << endl;

	string name = "ADMIN";
	string pass = "oracle";
	string srvName = "101.37.33.19:1521/ORADB";

	try
	{
		//�������ݿ�����
		Connection *conn = env->createConnection(name, pass, srvName);//�û��������룬���ݿ���
		if (NULL == conn) {
			printf("createConnection error.\n");
			return -1;
		}
		else
			cout << "conn success" << endl;

		//	���ݲ���,����Statement����
		Statement *pStmt = NULL;    // Statement����
		pStmt = conn->createStatement();
		if (NULL == pStmt) {
			printf("createStatement error.\n");
			return -1;
		}

		// ��ѯ���ݿ�ʱ��  
	    std::string strTemp;
		ResultSet *pRs = pStmt->executeQuery(
			//"SELECT TO_CHAR(SYSDATE, 'YYYY-MM-DD HH24:MI:SS') FROM DUAL"
			"select EID, USERNAME from CRM_APIUSER"
			);

		int i = 1;
		while (pRs->next()) {
			 printf("��%d������\n", i);
			//std::cout << std::setw(30) << std::left << pRs->Get<ostring>("EID")
			 strTemp = pRs->getString(2);
			//static int EID = pRs->getInt(1);
		   //	cout << "EID:" << EID << endl;
			//string var_sa = pRs->getString(2);
			 printf("USER_NAME:%s.\n", strTemp.c_str());
			// int����ȡֵ��getInt()  
			//break;

			/*
			 cout << "EID: " << pRs->getString(1) << "  NAME: "
				 << pRs->getString(2) << endl;*/

			i++;
			break;
		}
		//pStmt->closeResultSet(pRs);

		//--------����---------  
		// ָ��DMLΪ�Զ��ύ  
		//pStmt->setAutoCommit(TRUE);
		// ����ִ�е�SQL���  
		//pStmt->setSQL("INSERT INTO TA (ID, NAME) VALUES (1, 'ZS')");  
		//pStmt->setSQL("INSERT INTO TABLE_TEST_WANG (NAME, NUM, AGE) VALUES ('�˳�', '99', '41')");

		// ִ��SQL���  
		//unsigned int nRet = pStmt->executeUpdate();
		//if (nRet == 0) {
		//	printf("executeUpdate insert error.\n");
		//}

		// ��ֹStatement����  
		conn->terminateStatement(pStmt);

		//	�ر�����
		env->terminateConnection(conn);
		// pEnv->terminateConnection(pConn);  
	}
	catch (SQLException e)
	{
		cout << e.what() << endl;
		system("pause");
		return -1;
	}


	// �ͷ�OCCI�����Ļ���  
	Environment::terminateEnvironment(env);
	cout << "end!" << endl;
	system("pause");
	return 0;
}
