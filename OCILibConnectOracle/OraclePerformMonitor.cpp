#include <iostream>
#include "ocilib.hpp"
#include <vector>
#include <list>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
using namespace ocilib;



#ifdef _MSC_VER

#if defined(OCI_CHARSET_WIDE)
#pragma comment(lib, "ocilibw.lib")
#elif defined(OCI_CHARSET_ANSI)
#pragma comment(lib, "ociliba.lib")
#endif

#endif

using namespace ocilib;

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>

/* --------------------------------------------------------------------------------------------- *
* CONSTANTS
* --------------------------------------------------------------------------------------------- */

const int ArgDatabase = 1;
const int ArgUser = 2;
const int ArgPassword = 3;
const int ArgHome = 4;
const int ArgCount = 5;
const int SizeString = 260;
const int SizeBuffer = 2048;
const int ElemCount = 5;

const int DirPathBufferSize = 64000;
const int DirPathLoadSize = 100;
const int DirPathLoadCount = 10;
const int DirPathSizeColumn1 = 20;
const int DirPathSizeColumn2 = 30;
const int DirPathSizeColumn3 = 8;
const int DirPathColumnCount = 3;

/* --------------------------------------------------------------------------------------------- *
* DEFINES
* --------------------------------------------------------------------------------------------- */

#ifndef OCI_SHARED_LIB
#if defined(_WINDOWS)
#if defined(OCI_CHARSET_WIDE)
#define OCI_SHARED_LIB                   "ocilibw.dll"
#else
#define OCI_SHARED_LIB                   "ociliba.dll"
#endif
#elif defined(__APPLE__)
#define OCI_SHARED_LIB                   "libocilib.dylib"
#elif defined(__hppa)
#define OCI_SHARED_LIB                   "libocilib.sl"
#else
#define OCI_SHARED_LIB                   "libocilib.so"
#endif
#endif

#define otext(s) OTEXT(s)
#define oendl  std::endl

#if defined(OCI_CHARSET_WIDE)
#if defined(_MSC_VER)
#define omain           wmain
#define oarg            otext
#define oarglen         wcslen
#else
#define omain           main
#define oarg            char
#define oarglen         strlen
#endif
#else
#define omain             main
#define oarg              char
#define oarglen           strlen
#endif

#if defined(OCI_CHARSET_WIDE)
#define ocout             std::wcout
#define oostringstream    std::wostringstream
#else
#define ocout             std::cout
#define oostringstream    std::ostringstream
#endif

#define ARRAY_COUNT(t) (sizeof(t)/sizeof(t[0]))

#define print_frmt(f, x)    printf(f, x)

/* --------------------------------------------------------------------------------------------- *
* SQL
* --------------------------------------------------------------------------------------------- */

/*
 select 
  sum(a.value) value, s.username, s.sid
  from v$sesstat a, v$statname b, v$session s
 where a.statistic# = b.statistic#
   and s.sid = a.sid
   and b.name = 'opened cursors current'
   and s.username is not null
  group by s.sid, s.username
 order 
by value desc;
*/

// 游标统计
struct CursorStatElem
{
	CursorStatElem()
	{
		printf("====construct CursorStatElem====\n");
	}
	~CursorStatElem()
	{
		printf("====desctruct CursorStatElem====\n");
	}
	ostring username; // 会话名称
	int count;        // 游标数量
	int sid;  // 会话ID
};

// 会话统计
struct SessionStatElem
{    
	SessionStatElem()
	{
		printf("====construct SessionStatElem====\n");
	}
	~SessionStatElem()
	{
		printf("====desctruct SessionStatElem====\n");
	}
	ostring username;
	int count;
};

// Instance Perform Information Struct
struct InstancePerformData
{
	ostring status;
	int total_session_ctn;
	int total_process_ctn;
	list<CursorStatElem> cursor_stat;
	list<SessionStatElem> session_stat;
};


/* --------------------------------------------------------------------------------------------- *
* prototypes
* --------------------------------------------------------------------------------------------- */
void print_version(void);
void print_perform_info(InstancePerformData * data);
void get_perform_info(InstancePerformData * data);

/* --------------------------------------------------------------------------------------------- *
* variables
* --------------------------------------------------------------------------------------------- */
static Connection con;

inline ostring GetArg(oarg *arg)
{
	ostring res;

	if (arg)
	{
		size_t i = 0, size = oarglen(arg);

		res.resize(size);

		while (i < size) { res[i] = static_cast<char>(arg[i]); i++; }
	}

	return res;
}


/* --------------------------------------------------------------------------------------------- *
* main
* --------------------------------------------------------------------------------------------- */

int omain(int argc, oarg* argv[])
{
	ostring home;
	ostring dbs;
	ostring usr;
	ostring pwd;

	size_t i;

	/* CHECK COMMAND LINE --------------------------------------------------- */

	if (argc < (ArgCount - 1))
	{
		return EXIT_FAILURE;
	}

	/* GET ARGUMENTS ---------------------------------------------------------*/

	dbs = GetArg(argv[ArgDatabase]);
	usr = GetArg(argv[ArgUser]);
	pwd = GetArg(argv[ArgPassword]);

	if (argc == ArgCount)
	{
		home = GetArg(argv[ArgHome]);
	}

	try
	{
		Environment::Initialize(Environment::Default | Environment::Threaded, home);

		Environment::EnableWarnings(true);

		ocout << otext("Connecting to ") << usr << otext("/") << pwd << otext("@") << dbs << oendl << oendl;

		con.Open(dbs, usr, pwd, Environment::SessionSysDba); // SessionDefault

		print_version();

		InstancePerformData performData; //  *performData = new InstancePerformData();
		get_perform_info(&performData);

		print_perform_info(&performData);

		con.Close();
	}
	catch (std::exception &ex)
	{
		ocout << ex.what() << oendl;
	}

	if (con)
	{
		con.Close();
	}

	Environment::Cleanup();

	ocout << otext("\nPress any key to exit...");

	getchar();

	return EXIT_SUCCESS;
}

/* --------------------------------------------------------------------------------------------- *
* 获取Oracle实例状态
* --------------------------------------------------------------------------------------------- */

void get_perform_info(InstancePerformData * performData)
{

	// instance status
	Statement st(con);
	st.Execute(otext("select status from v$instance"));

	Resultset rs = st.GetResultset();
	rs++;
	// rs.Get(1, performData->status);
	ostring status = rs.Get<ostring>(1);
	performData->status = status;


	// session count
	st.Execute(otext("select count(*) from v$session"));
	rs = st.GetResultset();
	rs++;
	rs.Get<int>(1, performData->total_session_ctn);
	


	// session count
	st.Execute(otext("select count(*) from v$process"));
	rs = st.GetResultset();
	rs++;
	rs.Get<int>(1, performData->total_process_ctn);
	

	// session stat
	st.Execute(otext("select username, count(username) as session_ctn from v$session where username is not null group by username"));
	rs = st.GetResultset();
	while (rs++)
	{
		ostring username = rs.Get<ostring>(1);
		int session_ctn = rs.Get<int>(2);
		SessionStatElem elm;
		elm.count = session_ctn;
		elm.username = username;
		performData->session_stat.push_back(elm);
	}

	// cursor stat
	/*st.Execute(otext("select sum(a.value) as value, s.username, s.sid from v$sesstat a, v$statname b, v$session s where a.statistic# = b.statistic# and s.sid = a.sid and b.name = 'opened cursors current' and s.username is not null group by s.sid, s.username order by value desc"));
	rs = st.GetResultset();
	while (rs++)
	{
		CursorStatElem elm;
		elm.count = rs.Get<int>(1);
		elm.username = rs.Get<ostring>(2);
		elm.sid = rs.Get<int>(3);
		performData->cursor_stat.push_back(elm);
	}*/
}

/* --------------------------------------------------------------------------------------------- *
* 打印Oracle实例状态信息
* --------------------------------------------------------------------------------------------- */
void print_perform_info(InstancePerformData * performData)
{  

	list<SessionStatElem>::iterator itor;

	ocout << otext("\n>>>>> ORACLE PERFORM INFORMATION\n\n");
	ocout << otext("Oracle Instance Status: ") << performData->status << oendl;
	ocout << otext("Oracle Session Count: ") << performData->total_session_ctn << oendl;
	ocout << otext("Oracle Process Count: ") << performData->total_process_ctn << oendl;
	ocout << otext("Oracle Session Stat Info: ") << oendl;

	ocout << otext("USERNAME | SESSIONCOUNT ") << oendl;
	itor = performData->session_stat.begin();
	while (itor != performData->session_stat.end())
	{
		SessionStatElem elem = *itor;
		ocout << elem.username << " | " << elem.count << oendl;
		itor++;
	}
}


/* --------------------------------------------------------------------------------------------- *
* print_version
* --------------------------------------------------------------------------------------------- */

void print_version(void)
{
	ocout << otext("\n>>>>> OCILIB BUILD INFORMATION \n\n");

	if (Environment::GetImportMode() == Environment::ImportLinkage)
		ocout << otext("OCI import mode         : LINKAGE\n");
	else
		ocout << otext("OCI import mode         : RUNTIME\n");

	if (Environment::GetCharset() == Environment::CharsetAnsi)
		ocout << otext("Charset type            : ANSI\n");
	else
		ocout << otext("Charset type            : WIDE\n");

	ocout << otext("\n>>>>> VERSIONS INFORMATION \n\n");
	ocout << otext("OCILIB major    version : ") << OCILIB_MAJOR_VERSION << oendl;
	ocout << otext("OCILIB minor    version : ") << OCILIB_MINOR_VERSION << oendl;
	ocout << otext("OCILIB revision version : ") << OCILIB_REVISION_VERSION << oendl;
	ocout << otext("OCI compile     version : ") << Environment::GetCompileMajorVersion() << oendl;
	ocout << otext("OCI runtime     version : ") << Environment::GetRuntimeMajorVersion() << oendl;
	ocout << otext("Server major    version : ") << con.GetServerMajorVersion() << oendl;
	ocout << otext("Server minor    version : ") << con.GetServerMinorVersion() << oendl;
	ocout << otext("Server revision version : ") << con.GetServerRevisionVersion() << oendl;
	ocout << otext("Connection      version : ") << static_cast<unsigned int>(con.GetVersion()) << oendl;

	ocout << otext("\n>>>>> SERVER VERSION BANNER \n\n");
	ocout << con.GetServerVersion() << oendl << oendl;
}

