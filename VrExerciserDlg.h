/*************************************************************************/
/*****  Module:     VrExerciserDlg.h                                 *****/
/*****  Contents:   CVrExerciserDlg class                            *****/
/*****                                                               *****/
/*****  Description:                                                 *****/
/*****    This module contains the declarations for the              *****/
/*****    CVrExerciserDlg class.                                     *****/
/*****                                                               *****/
/*****                                                               *****/
/*****  History:                                                     *****/
/*****  Version   ---Date----  Who  ----------Description ---------- *****/
/*****  01.00.00  01 Oct 2003  DEW  Initial version                  *****/
/*****                                                               *****/
/*****  Copyright(c)   2003     Veritec, Inc.                        *****/
/*************************************************************************/
/*****  Start of Visual SourceSafe Information  ******
 * $History: VrExerciserDlg.h $
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
// VrExerciserDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Defines
/////////////////////////////////////////////////////////////////////////////
#if !defined(AFX_VREXERCISERDLG_H__E545EF87_B838_4C40_9499_A44A6CD7B013__INCLUDED_)
#define AFX_VREXERCISERDLG_H__E545EF87_B838_4C40_9499_A44A6CD7B013__INCLUDED_

/////////////////////////////////////////////////////////////////////////////
// Includes
/////////////////////////////////////////////////////////////////////////////
#include "ShowBitmap.h"	// Added by ClassView
#include "afxwin.h"

/////////////////////////////////////////////////////////////////////////////
// Pragmas
/////////////////////////////////////////////////////////////////////////////
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CVrExerciserDlg dialog
/////////////////////////////////////////////////////////////////////////////
class CVrExerciserDlg : public CDialog
{
// Construction
public:
	CVrExerciserDlg(CWnd* pParent = NULL);	// standard constructor
	~CVrExerciserDlg();

// Dialog Data
	//{{AFX_DATA(CVrExerciserDlg)
	enum { IDD = IDD_VREXERCISER_DIALOG };
	CComboBox	m_cboIsContrastNormal;
	CComboBox	m_cboSymType;
	CButton	m_bPreFilter;
	CButton	m_bMatrixFixed;
	CComboBox	m_cbBitsPerCell;
	CComboBox	m_cbSampleWidth;
	CComboBox	m_cboMatSize;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVrExerciserDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	CShowBitmap m_bmp;
	CString m_strFileDir;
	CString m_strTime;
	int m_nMatrixSize;
	int m_nSampleWidth;
	int	m_nBitsPerCell;
	int m_nPrefiltering ;
	int iFlag;
	CString m_StrSymType;
	CWinThread	*m_pThread;

	// Generated message map functions
	//{{AFX_MSG(CVrExerciserDlg)

	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnLoadBitmap();
	afx_msg void OnReset();
	afx_msg void OnDecode();
	afx_msg void OnSelchangeCOMBOMatSize();
	afx_msg void OnSelchangeCOMBOSampleWidth();
	afx_msg void OnSelchangeCOMBOBitsPerCell();
	afx_msg void OnCHECKFixedMT();
	afx_msg void OnCHECKPreFilter();
	afx_msg void OnSelchangeComboSym();
	afx_msg void OnSelchangeComboContrast();
	afx_msg LRESULT OnDecodeMsg(WPARAM wParam, LPARAM lParam);
	afx_msg		void OnBnClickedCheckModeAuto();
	afx_msg		int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg BOOL OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	static UINT ThreadFileRead(LPVOID pParam);

	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public :
	bool	LoadBitmap(LPCSTR strFileName);
	int		Decode(int nThread ,BYTE	*pucUserData);
	void	SetOption(int nImageWidth, int nImageHeight);
	BYTE*	GetBitsWithBinarize(int nTheshold, int &nWidth, int &nHeight);
	int		ReadVC(BYTE* pImage, int nWidth, int nHeight, BYTE* pResult);
	BYTE*	ClipImage(BYTE* pImage, int nWidth, int nHeight, int &nNewWidth, int &nNewHeight);
	BYTE*	HalfImage(BYTE* pImage, int nWidth, int nHeight, int &nNewWidth, int &nNewHeight);
	void	Hybrid_Median_Filter_3by3(BYTE *pSrc, int nWidth, int nHeight);
	void	Hybrid_Median_Filter_5by5(BYTE *pSrc, int nWidth, int nHeight);
	void	Hybrid_Median_Filter_7by7(BYTE *pSrc, int nWidth, int nHeight);
	BYTE	QuickGet_rep(BYTE* src,int size, int index);
	void	GetTimeString();
	BOOL	SaveParam();
	BOOL	LoadParam();
	void	AddFrameColorOnColor(BYTE *pSrc, BYTE *pDest, int nWidth, int nHeight, int nPower);
	void	AddFrameHalfTone(BYTE *pSrc, BYTE *pDest, int nWidth, int nHeight, int nPower);
	CListBox m_ctrlListLog;
	BOOL m_bCheckAuto;
	CString		m_strResultEdit;
	void		GoToTray(void);
	afx_msg void OnDestroy();
	afx_msg void OnClose();
	LRESULT OnTray(WPARAM wParam, LPARAM lParam);
	afx_msg void OnShowApplication();
	afx_msg void OnTrayExit();
	afx_msg void OnBnClickedBtnSave();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VREXERCISERDLG_H__E545EF87_B838_4C40_9499_A44A6CD7B013__INCLUDED_)
