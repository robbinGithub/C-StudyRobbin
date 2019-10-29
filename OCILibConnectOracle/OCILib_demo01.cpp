#include <iostream>
#include "ocilib.hpp"

void err_handler(OCI_Error *err)
{
	printf("%s\n", OCI_ErrorGetString(err));
}

int main_01(void)
{   
	
	OCI_Connection *cn;

	if (!OCI_Initialize(err_handler, NULL, OCI_ENV_DEFAULT))
	{   
		return EXIT_FAILURE;
	}
	cn = OCI_ConnectionCreate("(DESCRIPTION=(ADDRESS_LIST=(ADDRESS=(PROTOCOL=TCP)(HOST=101.37.33.19)(PORT=1521)))(CONNECT_DATA=(SERVER=DEDICATED)(SERVICE_NAME=ORADB)))", "ADMIN", "oracle", OCI_SESSION_DEFAULT);
	printf("Server major    version : %i\n", OCI_GetServerMajorVersion(cn));
	printf("Server minor    version : %i\n", OCI_GetServerMinorVersion(cn));
	printf("Server revision version : %i\n\n", OCI_GetServerRevisionVersion(cn));
	printf("Connection      version : %i\n\n", OCI_GetVersionConnection(cn));

	OCI_ConnectionFree(cn);
	OCI_Cleanup();
	system("PAUSE");

	return EXIT_SUCCESS;
}