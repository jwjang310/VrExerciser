/*************************************************************************/
/*****  Module:     VrExerciser.h                                    *****/
/*****  Contents:   CVrExerciser application                         *****/
/*****                                                               *****/
/*****  Description:                                                 *****/
/*****    This module contains the declarations for the              *****/
/*****    CVrExerciser application.                                  *****/
/*****                                                               *****/
/*****                                                               *****/
/*****  History:                                                     *****/
/*****  Version   ---Date----  Who  ----------Description ---------- *****/
/*****  01.00.00  01 Oct 2003  DEW  Initial version                  *****/
/*****                                                               *****/
/*****  Copyright(c)   2003     Veritec, Inc.                        *****/
/*************************************************************************/
/*****  Start of Visual SourceSafe Information  ******
 * $History: VrExerciser.h $
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
// VrExerciser.h : main header file for the VREXERCISER application
//

/////////////////////////////////////////////////////////////////////////////
// Defines
/////////////////////////////////////////////////////////////////////////////
#if !defined(AFX_VREXERCISER_H__4FAA28F2_4392_4EE3_9995_DCD05F22F989__INCLUDED_)
#define AFX_VREXERCISER_H__4FAA28F2_4392_4EE3_9995_DCD05F22F989__INCLUDED_

/////////////////////////////////////////////////////////////////////////////
// Pragmas
/////////////////////////////////////////////////////////////////////////////
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// Error
/////////////////////////////////////////////////////////////////////////////
#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

/////////////////////////////////////////////////////////////////////////////
// Includes
/////////////////////////////////////////////////////////////////////////////
#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CVrExerciserApp:
// See VrExerciser.cpp for the implementation of this class
//
/////////////////////////////////////////////////////////////////////////////
class CVrExerciserApp : public CWinApp
{
public:
	CVrExerciserApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVrExerciserApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CVrExerciserApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	HANDLE			m_hMutex;
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VREXERCISER_H__4FAA28F2_4392_4EE3_9995_DCD05F22F989__INCLUDED_)
