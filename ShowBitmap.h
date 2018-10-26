/*************************************************************************/
/*****  Module:     ShowBitmap.h                                     *****/
/*****  Contents:   CShowBitmap class                                *****/
/*****                                                               *****/
/*****  Description:                                                 *****/
/*****    This module contains the declarations for the              *****/
/*****    CShowBitmap class.                                         *****/
/*****                                                               *****/
/*****                                                               *****/
/*****  History:                                                     *****/
/*****  Version   ---Date----  Who  ----------Description ---------- *****/
/*****  01.00.00  01 Oct 2003  DEW  Initial version                  *****/
/*****                                                               *****/
/*****  Copyright(c)   2003     Veritec, Inc.                        *****/
/*************************************************************************/
/*****  Start of Visual SourceSafe Information  ******
 * $History: ShowBitmap.h $
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
// ShowBitmap.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Defines             
/////////////////////////////////////////////////////////////////////////////
#if !defined(AFX_SHOWBITMAP_H__15F3A979_1789_4912_91F1_91C55E05919B__INCLUDED_)
#define AFX_SHOWBITMAP_H__15F3A979_1789_4912_91F1_91C55E05919B__INCLUDED_

/////////////////////////////////////////////////////////////////////////////
// Pragmas             
/////////////////////////////////////////////////////////////////////////////
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CShowBitmap window
/////////////////////////////////////////////////////////////////////////////
class CShowBitmap : public CStatic
{
// Construction
public:
	CShowBitmap();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShowBitmap)
	//}}AFX_VIRTUAL

// Implementation
public:
	void ResetBitmap();
	BOOL LoadBitmapFile(CString strFilePath);
	long GetBitmapSize();
	SIZE GetBitmapDimension();
	BOOL GetBitmapData(unsigned char *ucBitmap);
	long GetBitmapColors();
	virtual ~CShowBitmap();

	// Generated message map functions
protected:
	//{{AFX_MSG(CShowBitmap)
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()

private:
	CDC			m_dc;
	HBITMAP		m_hbm, m_hbm_default;
	DIBSECTION	m_dib;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHOWBITMAP_H__15F3A979_1789_4912_91F1_91C55E05919B__INCLUDED_)
