/*************************************************************************/
/*****  Module:     VrExerciser.cpp                                  *****/
/*****  Contents:   CVrExerciserApp()                                *****/
/*****              InitInstance()                                   *****/
/*****                                                               *****/
/*****  Description:                                                 *****/
/*****    This module contains the application functions.            *****/
/*****                                                               *****/
/*****                                                               *****/
/*****  History:                                                     *****/
/*****  Version   ---Date----  Who  ----------Description ---------- *****/
/*****  01.00.00  01 Oct 2003  DEW  Initial version                  *****/
/*****                                                               *****/
/*****  Copyright(c)   2003     Veritec, Inc.                        *****/
/*************************************************************************/
/*****  Start of Visual SourceSafe Information  ******
 * $History: VrExerciser.cpp $
 * 
 * *****************  Version 1  *****************
 * User: Cnguyen      Date: 3/08/05    Time: 3:41p
 * Created in $/RELEASE/VrExerciser
 * New EDAC
 * 
 * *****************  Version 1  *****************
 * User: Cnguyen      Date: 3/08/05    Time: 3:39p
 * Created in $/RELEASE/vrExercise/VrExerciser
 * New EDAC 
 * 
 * *****************  Version 1  *****************
 * User: Dwood        Date: 4/06/04    Time: 9:48a
 * Created in $/Tools/VrExerciser
 * 
 * $NoKeywords: $
******  End of Visual SourceSafe Information    *****/
// VrExerciser.cpp : Defines the class behaviors for the application.
//

/////////////////////////////////////////////////////////////////////////////
// Includes    
/////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "VrExerciser.h"
#include "VrExerciserDlg.h"

/////////////////////////////////////////////////////////////////////////////
// Defines     
/////////////////////////////////////////////////////////////////////////////
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CVrExerciserApp
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
// CVrExerciserApp message map
/////////////////////////////////////////////////////////////////////////////
BEGIN_MESSAGE_MAP(CVrExerciserApp, CWinApp)
	//{{AFX_MSG_MAP(CVrExerciserApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVrExerciserApp construction
/////////////////////////////////////////////////////////////////////////////

/*************************************************************************/
/*****  Module:     VrExerciser.cpp                                  *****/
/*****  Procedure:  CVrExerciserApp()                   [Constructor]*****/
/*****  Parameters: None                                             *****/
/*****  Return:     None                                             *****/
/*****  Uses:       None                                             *****/
/*****                                                               *****/
/*****  Description:                                                 *****/
/*****    This procedure constructs the application class.           *****/
/*****                                                               *****/
/*****  History:                                                     *****/
/*****  Version   ---Date----  Who  ----------Description ---------- *****/
/*****  01.00.00  01 Oct 2003  DEW  Initial version                  *****/
/*****                                                               *****/
/*************************************************************************/
CVrExerciserApp::CVrExerciserApp()
{
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CVrExerciserApp object
/////////////////////////////////////////////////////////////////////////////
CVrExerciserApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CVrExerciserApp initialization
/////////////////////////////////////////////////////////////////////////////
/*************************************************************************/
/*****  Module:     VrExerciser.cpp                                  *****/
/*****  Procedure:  InitInstance()                      [Function]   *****/
/*****  Parameters: None                                             *****/
/*****  Return:     None                                             *****/
/*****  Uses:       None                                             *****/
/*****                                                               *****/
/*****  Description:                                                 *****/
/*****    This procedure constructs the application class.           *****/
/*****                                                               *****/
/*****  History:                                                     *****/
/*****  Version   ---Date----  Who  ----------Description ---------- *****/
/*****  01.00.00  01 Oct 2003  DEW  Initial version                  *****/
/*****                                                               *****/
/*************************************************************************/
BOOL CVrExerciserApp::InitInstance()
{
	m_hMutex = ::CreateMutex(NULL,FALSE, "VCR_Mutex");
	if (m_hMutex != NULL)
	{
		if (::GetLastError() == ERROR_ALREADY_EXISTS) 
		{
			//AfxMessageBox("프로그램이 이미 실행중입니다.\n프로그램을 종료합니다.", MB_OK | MB_ICONERROR);
			return FALSE;
		}
	}

	AfxEnableControlContainer();

	#ifdef _AFXDLL
		Enable3dControls();			// Call this when using MFC in a shared DLL
	#else
		Enable3dControlsStatic();	// Call this when linking to MFC statically
	#endif

	CVrExerciserDlg dlg;
	int				nResponse;

	m_pMainWnd = &dlg;
	nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// There is no processing here. The button ends the program.	
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}

int CVrExerciserApp::ExitInstance()
{
	CloseHandle(m_hMutex);

	return CWinApp::ExitInstance();
}