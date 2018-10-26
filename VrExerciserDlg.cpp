/*************************************************************************/
/*****  Module:     VrExerciserDlg.cpp                               *****/
/*****  Contents:   CVrExerciserDlg()                                *****/
/*****              DoDataExchange()                                 *****/
/*****              OnDecode()                                       *****/
/*****              OnInitDialog()                                   *****/
/*****              OnLoadBitmap()                                   *****/
/*****              OnPaint()                                        *****/
/*****              OnQueryDragIcon()                                *****/
/*****              OnReset()                                        *****/
/*****                                                               *****/
/*****  Description:                                                 *****/
/*****    This module contains the dialog handling functions.        *****/
/*****                                                               *****/
/*****                                                               *****/
/*****  History:                                                     *****/
/*****  Version   ---Date----  Who  ----------Description ---------- *****/
/*****  01.00.00  01 Oct 2003  DEW  Initial version                  *****/
/*****                                                               *****/
/*****  Copyright(c)   2003     Veritec, Inc.                        *****/
/*************************************************************************/
/*****  Start of Visual SourceSafe Information  ******
 * $History: VrExerciserDlg.cpp $
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
// VrExerciserDlg.cpp : implementation file
//

/////////////////////////////////////////////////////////////////////////////
// Includes
/////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "VrExerciser.h"
#include "VrExerciserDlg.h"
#include "VRDll.h"
#include "ImageProc.h"
#include "DataManager.h"


#include <atlimage.h>
/////////////////////////////////////////////////////////////////////////////
// Defines
/////////////////////////////////////////////////////////////////////////////
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define		COPYDATA_VCR				26
#define		UM_DECODE					3421
#define		UM_TRAY						WM_USER + 1002

#define		COPYDATA_VCR_MAX_LENGTH		5000
#define		PROGNAME_AOISERVER			"! Inspection ! D.I.T"
#define		FILE_RESULT_PATH	"d:\\image\\VCR\\Result\\"
#define		FILE_FAIL_PATH		"d:\\image\\VCR\\Fail\\"
#define		FILE_NAME_SOURCE	"d:\\image\\VCR\\VCR.BMP"
#define		SHCU				HKEY_CURRENT_USER
#define		KEY_VRE		_T("Software\\DIT\\VrExerciser\\")

/////////////////////////////////////////////////////////////////////////////
// Global variables for VRDll
/////////////////////////////////////////////////////////////////////////////
VRDLL_API SYM g_vcSym;
VRDLL_API OPTIONS g_vcOpt;

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About
/////////////////////////////////////////////////////////////////////////////
class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/*************************************************************************/
/*****  Module:     VrExerciserDlg.cpp                               *****/
/*****  Procedure:  CAboutDlg()                         [Constructor]*****/
/*****  Parameters: None                                             *****/
/*****  Return:     None                                             *****/
/*****  Uses:       None                                             *****/
/*****                                                               *****/
/*****  Description:                                                 *****/
/*****    This procedure constructs the class and initializes        *****/
/*****    variables.                                                 *****/
/*****                                                               *****/
/*****  History:                                                     *****/
/*****  Version   ---Date----  Who  ----------Description ---------- *****/
/*****  01.00.00  01 Oct 2003  DEW  Initial version                  *****/
/*****                                                               *****/
/*************************************************************************/
CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

/*************************************************************************/
/*****  Module:     VrExerciserDlg.cpp                               *****/
/*****  Procedure:  DoDataExchange()                    [Function]   *****/
/*****  Parameters: pDX - Data exchange object pointer               *****/
/*****  Return:     None                                             *****/
/*****  Uses:       None                                             *****/
/*****                                                               *****/
/*****  Description:                                                 *****/
/*****    This procedure exchanges and validates data between the    *****/
/*****    dialog and data variables.                                 *****/
/*****                                                               *****/
/*****  History:                                                     *****/
/*****  Version   ---Date----  Who  ----------Description ---------- *****/
/*****  01.00.00  01 Oct 2003  DEW  Initial version                  *****/
/*****                                                               *****/
/*************************************************************************/
void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg message map
/////////////////////////////////////////////////////////////////////////////
BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP

END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVrExerciserDlg dialog
/////////////////////////////////////////////////////////////////////////////
/*************************************************************************/
/*****  Module:     VrExerciserDlg.cpp                               *****/
/*****  Procedure:  CVrExerciserDlg()                   [Constructor]*****/
/*****  Parameters: None                                             *****/
/*****  Return:     None                                             *****/
/*****  Uses:       None                                             *****/
/*****                                                               *****/
/*****  Description:                                                 *****/
/*****    This procedure constructs the class and initializes        *****/
/*****    variables.                                                 *****/
/*****                                                               *****/
/*****  History:                                                     *****/
/*****  Version   ---Date----  Who  ----------Description ---------- *****/
/*****  01.00.00  01 Oct 2003  DEW  Initial version                  *****/
/*****                                                               *****/
/*************************************************************************/
CVrExerciserDlg::CVrExerciserDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CVrExerciserDlg::IDD, pParent)
	, m_bCheckAuto(TRUE)
	, m_strResultEdit(_T(""))
{
	//{{AFX_DATA_INIT(CVrExerciserDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	//_CrtSetBreakAlloc(494);
	m_pThread = NULL;
}

CVrExerciserDlg::~CVrExerciserDlg()
{
	if(m_bCheckAuto && m_pThread)
	{
		m_bCheckAuto = FALSE;
		WaitForSingleObject(m_pThread->m_hThread, 5000);
		m_pThread = NULL;
	}
}

/*************************************************************************/
/*****  Module:     VrExerciserDlg.cpp                               *****/
/*****  Procedure:  DoDataExchange()                    [Function]   *****/
/*****  Parameters: pDX - Data exchange object pointer               *****/
/*****  Return:     None                                             *****/
/*****  Uses:       None                                             *****/
/*****                                                               *****/
/*****  Description:                                                 *****/
/*****    This procedure exchanges and validates data between the    *****/
/*****    dialog and data variables.                                 *****/
/*****                                                               *****/
/*****  History:                                                     *****/
/*****  Version   ---Date----  Who  ----------Description ---------- *****/
/*****  01.00.00  01 Oct 2003  DEW  Initial version                  *****/
/*****                                                               *****/
/*************************************************************************/
void CVrExerciserDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CVrExerciserDlg)
	DDX_Control(pDX, IDC_COMBO_CONTRAST, m_cboIsContrastNormal);
	DDX_Control(pDX, IDC_COMBO_SYM, m_cboSymType);
	DDX_Control(pDX, IDC_CHECKPreFilter, m_bPreFilter);
	DDX_Control(pDX, IDC_CHECKFixedMT, m_bMatrixFixed);
	DDX_Control(pDX, IDC_COMBOBitsPerCell, m_cbBitsPerCell);
	DDX_Control(pDX, IDC_COMBOSampleWidth, m_cbSampleWidth);
	DDX_Control(pDX, IDC_COMBOMatSize, m_cboMatSize);
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_LIST_LOG, m_ctrlListLog);
	DDX_Check(pDX, IDC_CHECK_MODE_AUTO, m_bCheckAuto);
	DDX_Text(pDX, IDC_EDIT_RESULT, m_strResultEdit);
}

/////////////////////////////////////////////////////////////////////////////
// CVrExerciserDlg message map
/////////////////////////////////////////////////////////////////////////////
BEGIN_MESSAGE_MAP(CVrExerciserDlg, CDialog)
	//{{AFX_MSG_MAP(CVrExerciserDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_LOAD_BITMAP, OnLoadBitmap)
	ON_BN_CLICKED(IDC_RESET, OnReset)
	ON_BN_CLICKED(IDC_DECODE, OnDecode)
	ON_CBN_SELCHANGE(IDC_COMBOMatSize, OnSelchangeCOMBOMatSize)
	ON_CBN_SELCHANGE(IDC_COMBOSampleWidth, OnSelchangeCOMBOSampleWidth)
	ON_CBN_SELCHANGE(IDC_COMBOBitsPerCell, OnSelchangeCOMBOBitsPerCell)
	ON_BN_CLICKED(IDC_CHECKFixedMT, OnCHECKFixedMT)
	ON_BN_CLICKED(IDC_CHECKPreFilter, OnCHECKPreFilter)
	ON_CBN_SELCHANGE(IDC_COMBO_SYM, OnSelchangeComboSym)
	ON_CBN_SELCHANGE(IDC_COMBO_CONTRAST, OnSelchangeComboContrast)

	ON_MESSAGE(UM_DECODE,OnDecodeMsg)
	ON_WM_COPYDATA()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_CHECK_MODE_AUTO, &CVrExerciserDlg::OnBnClickedCheckModeAuto)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_CLOSE()
	//ON_MESSAGE(UM_TRAY, &CMainFrame::OnTray)
	ON_MESSAGE(UM_TRAY, OnTray)
	ON_COMMAND(ID__SHOWAPPLICATION, &CVrExerciserDlg::OnShowApplication)
	ON_COMMAND(ID__EXIT32773, &CVrExerciserDlg::OnTrayExit)
	ON_BN_CLICKED(IDC_BTN_SAVE, &CVrExerciserDlg::OnBnClickedBtnSave)
END_MESSAGE_MAP()

BOOL CVrExerciserDlg::PreTranslateMessage(MSG* pMsg)
{
	if( pMsg->message == WM_KEYDOWN )
	{
		if(pMsg->wParam == VK_RETURN
			|| pMsg->wParam == VK_ESCAPE )
		{
			::TranslateMessage(pMsg);
			::DispatchMessage(pMsg);
			return TRUE;                    // DO NOT process further
		}
	}

	return CDialog::PreTranslateMessage(pMsg);
}


/////////////////////////////////////////////////////////////////////////////
// CVrExerciserDlg message handlers
/////////////////////////////////////////////////////////////////////////////
/*************************************************************************/
/*****  Module:     VrExerciserDlg.cpp                               *****/
/*****  Procedure:  OnDecode()                          [Event]      *****/
/*****  Parameters: None                                             *****/
/*****  Return:     None                                             *****/
/*****  Uses:       GetUserData()                                    *****/
/*****                                                               *****/
/*****  Description:                                                 *****/
/*****    This procedure decodes a bitmap and displays the user      *****/
/*****    data.                                                      *****/
/*****                                                               *****/
/*****  History:                                                     *****/
/*****  Version   ---Date----  Who  ----------Description ---------- *****/
/*****  01.00.00  01 Oct 2003  DEW  Initial version                  *****/
/*****                                                               *****/
/*************************************************************************/

void CVrExerciserDlg::SetOption(int nImageWidth, int nImageHeight)
{
	int				intEDAC = 0;
	g_vcOpt.SymbolType = (short) 0;
	g_vcOpt.SampleWidth = (short) m_nSampleWidth;
	g_vcOpt.BitsPerCell = (short) m_nBitsPerCell;
	g_vcOpt.AorLeft = (short) 0;
	g_vcOpt.AorRight = (short) nImageWidth-1;
	g_vcOpt.AorTop = (short) 0;
	g_vcOpt.AorBottom = (short) nImageHeight-1;
	g_vcOpt.Prefiltering = (short) m_nPrefiltering;
	g_vcOpt.FilterSize = (short) 0;
	g_vcOpt.FilterIterations = (short) 0;
	if (m_nMatrixSize > 0)
	{
		g_vcSym.IsMatrixFixed = (short) 1;
		g_vcSym.FixedMatrixSize = m_nMatrixSize;
	}
	else
	{
		g_vcSym.IsMatrixFixed = (short) 0;
		g_vcSym.FixedMatrixSize = (short) 16;
	}
	g_vcSym.IndexContrast = (short) 0;

	switch (m_cboIsContrastNormal.GetCurSel())
	{
	case 0:
		g_vcSym.IsContrastNormal = (short) 1;	// Black on White
		break;
	case 1:
		g_vcSym.IsContrastNormal = (short) 0;	// Inverse
		break;
	case 2:
		g_vcSym.IsContrastNormal = (short) 2;	// 2 == Edge, 3 == Auto
		break;
	default:
		g_vcSym.IsContrastNormal = (short) 1;
		break;
	}

	g_vcSym.EdacLevel = intEDAC / 2;
	g_vcSym.Compression = (short) 0;

	switch(m_cboSymType.GetCurSel())
	{
	case 0:
		g_vcOpt.SymbolType = (short) 5;		// Auto
		break;
	case 1:
		g_vcOpt.SymbolType = (short) 4;		// Vericode
		break;
	case 2:
		g_vcOpt.SymbolType = (short) 1;		// DataMatrix
		break;
	}
}

BYTE* CVrExerciserDlg::GetBitsWithBinarize(int nTheshold, int &nWidth, int &nHeight)
{
	long			lngBitmapColors;
	SIZE			sizBitmapCoords;
	int				nLength;
	BYTE*			pDst = NULL;
	// Decode only 24 bit True Color
	lngBitmapColors = m_bmp.GetBitmapColors();
	if ((lngBitmapColors != 24)&&(lngBitmapColors != 8))
	{
		SetDlgItemText(IDC_STATIC_BITMAPINFO,
			"ERROR: Bitmap must be 24 bit color or 8 bit gray scale ");
		return NULL;
	}

	BYTE *pucImage = new BYTE [m_bmp.GetBitmapSize()];

	if (m_bmp.GetBitmapData(pucImage))
	{
		sizBitmapCoords = m_bmp.GetBitmapDimension();
		nWidth = sizBitmapCoords.cx;
		nHeight = sizBitmapCoords.cy;
		if(nTheshold == 0)
			return pucImage;
		nLength = nWidth*nHeight;
		// Create monochrome bitmap
		pDst = new BYTE [(nLength)];

		ZeroMemory(pDst,sizeof(BYTE)*nLength);

		switch (lngBitmapColors)
		{
		case 8:
			for (int lngIdx = 0; lngIdx < nLength; lngIdx++)
			{
				if (pucImage[lngIdx] < nTheshold)
					pDst[lngIdx] = 5;
				else
					pDst[lngIdx] = 255;
			}
			break;

		case 24:
			for (int lngIdx = 0; lngIdx < nLength; lngIdx++)
			{

				if (pucImage[lngIdx * 3] < nTheshold)
					pDst[lngIdx] = 5;
				else
					pDst[lngIdx] = 255;
			}
			break;
		}
	}

	if (pucImage != NULL)
	{
		delete[] pucImage;
		pucImage = NULL;
	}

	return pDst;
}

int	CVrExerciserDlg::ReadVC(BYTE* pImage, int nWidth, int nHeight, BYTE* pResult)
{
	SetOption(nWidth, nHeight);

	int nRet = vcRead((short) nWidth, (short) nHeight, pImage, (char *) pResult);
	if (nRet == 0)
	{
		CString strError;
		strError.Format("ERROR: VrDll returned error code: %d",nRet);
		SetDlgItemText(IDC_STATIC_TEXT,strError);
	}
	else
	{
		// Display user data
		SetDlgItemText(IDC_STATIC_TEXT,(const char *) pResult);
	}

	return nRet;

//
// 	int nRet;
// 	g_vcSym.IsContrastNormal = 0;
//
// 	for(int i = 1; i < 9; i++)
// 	{
// 		g_vcSym.IsContrastNormal = 0;
// 		g_vcOpt.SampleWidth = i;
//
// 		nRet = vcRead((short) nWidth, (short) nHeight, pImage, (char *) pResult);
// 		if (nRet == 0)
// 		{
// 			continue;
// 		}
// 		else if(nRet < 0 || strlen((char*)pResult) < 10)
// 		{
// 			g_vcSym.IsContrastNormal = 1;
// 			nRet = vcRead((short) nWidth, (short) nHeight, pImage, (char *) pResult);
// 			if (nRet == 0)
// 			{
// 				continue;
// 			}
// 			else if(nRet < 0 || strlen((char*)pResult) < 10)
// 			{
// 				continue;
// 			}
// 			else
// 			{
// 				// Display user data
// 				SetDlgItemText(IDC_STATIC_TEXT,(const char *) pResult);
// 				return nRet;
// 			}
// 		}
// 		else
// 		{
// 			// Display user data
// 			SetDlgItemText(IDC_STATIC_TEXT,(const char *) pResult);
// 			return nRet;
// 		}
// 	}
//
// 	return nRet;
}

BYTE* CVrExerciserDlg::ClipImage(BYTE* pImage, int nWidth, int nHeight, int &nNewWidth, int &nNewHeight)
{
	BYTE* pCut = NULL;
	int	nIdx;
	CRect rect = CRect(0,0,0,0);

	Projection(pImage, nWidth, nHeight, rect.left, rect.top, rect.right, rect.bottom);

	rect.left = 0;
	rect.right = nWidth;

	rect.InflateRect(12,12,12,12);

	if (rect.left < 0)
		rect.left = 3;

	if (rect.right >= nWidth)
		rect.right = nWidth -4;

	if (rect.top < 0)
		rect.top = 3;

	if (rect.bottom >= nHeight)
		rect.bottom = nHeight -4;

	nNewHeight		= (rect.Height()+1)/4*4;
	nNewWidth		= (rect.Width()+1)/4*4;



	rect.right = rect.left+nNewWidth-1;
	rect.bottom = rect.top+nHeight-1;

	int newLength	= nNewHeight*nNewWidth;

	pCut = new BYTE[newLength];
	ZeroMemory(pCut, sizeof(BYTE)*(newLength));



	for (int y = 0 ; y < nNewHeight ; y++)
	{
		for (int x = 0 ; x < nNewWidth ; x++)
		{
			nIdx = (rect.top+y)*nWidth+rect.left+x;
			pCut[y*nNewWidth+x] = pImage[nIdx];
		}
	}



	BYTE* pNewCut =  new BYTE[(nNewHeight+20)*(nNewWidth+20)];
	memset(pNewCut, 255, sizeof(BYTE)*(nNewHeight+20)*(nNewWidth+20));
	for (int y = 0 ; y < nNewHeight ; y++)
	{
		for (int x = 0 ; x < nNewWidth ; x++)
		{
			pNewCut[(y+10)*(nNewWidth+20)+(x+10)] = pCut[y*nNewWidth+x];
		}
	}

	nNewHeight += 20;
	nNewWidth += 20;

	//Hybrid_Median_Filter_5by5(pNewCut, nNewWidth, nNewHeight);

	/*
	CImage image;
	image.Create(nNewWidth, nNewHeight, 24);
	for (int y = 0 ; y < nNewHeight ; y++)
	{
		for (int x = 0 ; x < nNewWidth ; x++)
		{
			image.SetPixel(x,y,RGB(pNewCut[y*nNewWidth+x], pNewCut[y*nNewWidth+x],pNewCut[y*nNewWidth+x])) ;
		}
	}
	CString strPath;
	strPath.Format("d:\\test%d.bmp", GetTickCount());
	image.Save(strPath);
	*/

	if (pCut != NULL)
	{
		delete[] pCut;
		pCut = NULL;
	}

	return pNewCut;
}

void CVrExerciserDlg::AddFrameHalfTone(BYTE *pSrc, BYTE *pDest, int nWidth, int nHeight, int nPower)
{
	int nDestWidth = nWidth / nPower;
	int nDestHeight = nHeight / nPower;

	unsigned int nAvg, nIdx, nIdx2, nIdx3 = 0;

	for(int y = 0; y < nDestHeight; y++)
	{
		for(int x = 0; x < nDestWidth; x++)
		{
			nIdx = (y * nWidth + x) * nPower;
			nAvg = 0;

			for(int yy = 0; yy < nPower; yy++)
			{
				nIdx2 = nIdx;

				for(int xx = 0; xx < nPower; xx++)
				{
					nAvg += pSrc[nIdx2];
					nIdx2++;
				}

				nIdx += nWidth;
			}

			nAvg /= (nPower * nPower);
			pDest[nIdx3] = (BYTE)nAvg;
			nIdx3++;
		}
	}
}

void CVrExerciserDlg::AddFrameColorOnColor(BYTE *pSrc, BYTE *pDest, int nWidth, int nHeight, int nPower)
{
	int nDestWidth = nWidth / nPower;
	int nDestHeight = nHeight / nPower;

	unsigned int nIdx = 0;

	for(int y = 0; y < nDestHeight; y++)
	{
		for(int x = 0; x < nDestWidth; x++)
		{
			pDest[nIdx] = pSrc[(y * nWidth + x) * nPower];
			nIdx++;
		}
	}
}

BYTE* CVrExerciserDlg::HalfImage(BYTE* pImage, int nWidth, int nHeight, int &nNewWidth, int &nNewHeight)
{
	BYTE* pCut = NULL;
	int	nIdx;

	nNewHeight		= nHeight/2/4*4;
	nNewWidth		= nWidth/2/4*4;

	int newLength	= nNewHeight*nNewWidth;

	pCut = new BYTE[newLength];
	ZeroMemory(pCut, sizeof(BYTE)*(newLength));

	for (int y = 0 ; y < nNewHeight ; y++)
	{
		for (int x = 0 ; x < nNewWidth ; x++)
		{
			nIdx = y*2*nWidth+x*2;
			pCut[y*nNewWidth+x] = pImage[nIdx];
		}
	}

	/*
	CImage image;
	image.Create(nNewWidth, nNewHeight, 24);
	for (int y = 0 ; y < nNewHeight ; y++)
	{
		for (int x = 0 ; x < nNewWidth ; x++)
		{
			image.SetPixel(x,y,RGB(pCut[y*nNewWidth+x], pCut[y*nNewWidth+x],pCut[y*nNewWidth+x])) ;
		}
	}

	CString strPath;
	strPath.Format("d:\\test0_Half%d.bmp", GetTickCount());
	image.Save(strPath);
	*/

	return pCut;
}

void CVrExerciserDlg::Hybrid_Median_Filter_3by3(BYTE *pSrc, int nWidth, int nHeight)
{
	BYTE cTemp[15];

	int x,y;
	int ny,ny2;

	int ey=nHeight-1;
	int ex=nWidth-1;

	for(y=1;y<ey;y++)
	{
		ny = y*nWidth-nWidth;
		for(x=1;x<ex;x++)
		{
			ny2 = ny+x;
			cTemp[0] = 	pSrc[ny2-1];
			cTemp[1] = 	pSrc[ny2+1];
			cTemp[6] = 	pSrc[ny2];

			ny2 += nWidth;
			cTemp[2] = 	pSrc[ny2];
			cTemp[3] = 	cTemp[2];
			cTemp[7] = 	pSrc[ny2-1];
			cTemp[8] = 	pSrc[ny2+1];
			cTemp[9] = 	cTemp[2];
			cTemp[10] =	cTemp[2];

			ny2 += nWidth;
			cTemp[4] = 	pSrc[ny2-1];
			cTemp[5] = 	pSrc[ny2+1];
			cTemp[11] = pSrc[ny2];

			//대각선 중간값
			cTemp[12]=QuickGet_rep(&cTemp[0],6,3);

			//십자가 중간값
			cTemp[13]=QuickGet_rep(&cTemp[6],6,3);
			cTemp[14]=cTemp[2];
			//세개중 중간값
			pSrc[ny2-nWidth]=QuickGet_rep(&cTemp[12],3,2);
		}
	}
}

void CVrExerciserDlg::Hybrid_Median_Filter_5by5(BYTE *pSrc, int nWidth, int nHeight)
{
	BYTE cTemp[23];

	int x,y;
	int ny,ny2;

	int ey=nHeight-2;
	int ex=nWidth-2;

	for(y=2;y<ey;y++)
	{
		ny = (y-2)*nWidth;
		for(x=2;x<ex;x++)
		{
			ny2 = ny+x;
			cTemp[0] = 	pSrc[ny2-2];
			cTemp[1] = 	pSrc[ny2+2];
			cTemp[10] =	pSrc[ny2];

			ny2 += nWidth;
			cTemp[2] = 	pSrc[ny2-1];
			cTemp[3] = 	pSrc[ny2+1];
			cTemp[11] =	pSrc[ny2];

			ny2 += nWidth;
			cTemp[4] = 	pSrc[ny2];
			cTemp[5] = 	cTemp[4];
			cTemp[12] = pSrc[ny2-2];
			cTemp[13] = pSrc[ny2-1];
			cTemp[14] = cTemp[4];
			cTemp[15] = cTemp[4];
			cTemp[16] = pSrc[ny2+1];
			cTemp[17] = pSrc[ny2+2];

			ny2 += nWidth;
			cTemp[6] = 	pSrc[ny2-1];
			cTemp[7] = 	pSrc[ny2+1];
			cTemp[18] =	pSrc[ny2];

			ny2 += nWidth;
			cTemp[8] = 	pSrc[ny2-2];
			cTemp[9] = 	pSrc[ny2+2];
			cTemp[19] =	pSrc[ny2];

			//대각선 중간값
			cTemp[20]=QuickGet_rep(&cTemp[0],10,5);

			//십자가 중간값
			cTemp[21]=QuickGet_rep(&cTemp[10],10,5);
			cTemp[22]=cTemp[4];
			//세개중 중간값
			pSrc[ny2-nWidth-nWidth]=QuickGet_rep(&cTemp[20],3,2);
		}
	}
}

void CVrExerciserDlg::Hybrid_Median_Filter_7by7(BYTE *pSrc, int nWidth, int nHeight)
{
	BYTE cTemp[31];

	int x,y;
	int ny,ny2;

	int ey=nHeight-3;
	int ex=nWidth-3;

	for(y=3;y<ey;y++)
	{
		ny = (y-3)*nWidth;
		for(x=3;x<ex;x++)
		{
			ny2 = ny+x;
			cTemp[0] = 	pSrc[ny2-3];
			cTemp[1] = 	pSrc[ny2+3];
			cTemp[14] = 	pSrc[ny2];

			ny2 += nWidth;
			cTemp[2] = 	pSrc[ny2-2];
			cTemp[3] = 	pSrc[ny2+2];
			cTemp[15] =	pSrc[ny2];

			ny2 += nWidth;
			cTemp[4] = 	pSrc[ny2-1];
			cTemp[5] = 	pSrc[ny2+1];
			cTemp[16] =	pSrc[ny2];

			ny2 += nWidth;
			cTemp[6] = 	pSrc[ny2];
			cTemp[7] = 	cTemp[6];
			cTemp[17] = pSrc[ny2-3];
			cTemp[18] = pSrc[ny2-2];
			cTemp[19] = pSrc[ny2-1];
			cTemp[20] = cTemp[6];
			cTemp[21] = cTemp[6];
			cTemp[22] = pSrc[ny2+1];
			cTemp[23] = pSrc[ny2+2];
			cTemp[24] = pSrc[ny2+3];

			ny2 += nWidth;
			cTemp[8] = 	pSrc[ny2-1];
			cTemp[9] = 	pSrc[ny2+1];
			cTemp[25] =	pSrc[ny2];

			ny2 += nWidth;
			cTemp[10] = 	pSrc[ny2-2];
			cTemp[11] = pSrc[ny2+2];
			cTemp[26] =	pSrc[ny2];

			ny2 += nWidth;
			cTemp[12] =	pSrc[ny2-3];
			cTemp[13] = pSrc[ny2+3];
			cTemp[27] =	pSrc[ny2];

			//대각선 중간값
			cTemp[28]=QuickGet_rep(&cTemp[0],14,7);

			//십자가 중간값
			cTemp[29]=QuickGet_rep(&cTemp[14],14,7);
			cTemp[30]=cTemp[4];
			//세개중 중간값
			pSrc[ny2-nWidth-nWidth-nWidth]=QuickGet_rep(&cTemp[28],3,2);
		}
	}
}

BYTE CVrExerciserDlg::QuickGet_rep(BYTE* src,int size, int index)
{
	BYTE temp,pivot;
	int change_point;
	while(size>=2)
	{
		pivot=src[0];
		change_point=0;
		for(int i=1;i<size;i++)
		{
			if(pivot>src[i])
			{
				temp=src[++change_point];
				src[change_point]=src[i];
				src[i]=temp;
			}
		}
		src[0]=src[change_point];
		src[change_point]=pivot;

		if(index==change_point+1)
			return src[change_point];
		else if(index<change_point+1)
			size=change_point;
		else
		{
			src+=(change_point+1);
			size-=(change_point+1);
			index-=(change_point+1);
		}
	}
	return src[0];
}

void CVrExerciserDlg::OnDecode()
{

	BYTE*	pMono = NULL;
	BYTE*	pResult = NULL;

	int nWidth	= 0;
	int nHeight = 0;
	//int nVCRetCode;

	if (!(pMono = GetBitsWithBinarize(200, nWidth, nHeight)))
	{
		if (pMono != NULL){
			delete [] pMono;
			pMono = NULL;}
		return ;
	}

	pResult = new BYTE[COPYDATA_VCR_MAX_LENGTH];
	ZeroMemory(pResult, sizeof(BYTE)*COPYDATA_VCR_MAX_LENGTH);

	if(ReadVC(pMono, nWidth, nHeight, pResult) > 0)
	{
		if (pResult != NULL){
			delete[] pResult;
			pResult = NULL;	}

		if (pMono != NULL)
		{
			delete[] pMono;
			pMono = NULL;
		}
		m_strResultEdit.Format("%s", pResult);
		UpdateData(FALSE);
		return;
	}

	BYTE* pClipImage = NULL;
	int	nNewHeight;
	int nNewWidth;
	pClipImage = ClipImage(pMono, nWidth, nHeight, nNewWidth, nNewHeight);

	if (pClipImage == NULL)
		return;

	ZeroMemory(pResult, sizeof(BYTE)*COPYDATA_VCR_MAX_LENGTH);
	ReadVC(pClipImage, nNewWidth, nNewHeight, pResult);
	m_strResultEdit.Format("%s", pResult);
	UpdateData(FALSE);
	if (pClipImage != NULL)
	{
		delete[] pClipImage;
		pClipImage = NULL;
	}

	if (pResult != NULL)
	{
		delete[] pResult;
		pResult = NULL;
	}

	if (pMono != NULL)
	{
		delete[] pMono;
		pMono = NULL;
	}

}

int CVrExerciserDlg::Decode(int nThread ,BYTE	*pResult)
{
	BYTE*	pMono = NULL;

	int nWidth	= 0;
	int nHeight = 0;
	//int nVCRetCode;
	int nRet;

	if (!(pMono = GetBitsWithBinarize(nThread, nWidth, nHeight)))
	{
		if (pMono != NULL)
		{
			delete [] pMono;
			pMono = NULL;
		}
		return 0;
	}

	ZeroMemory(pResult, sizeof(BYTE)*COPYDATA_VCR_MAX_LENGTH);

	if(ReadVC(pMono, nWidth, nHeight, pResult) > 0)
	{
		if (pMono != NULL)
		{
			delete[] pMono;
			pMono = NULL;
		}

		return 1;
	}

	BYTE* pClipImage = NULL;
	int	nNewHeight;
	int nNewWidth;
	pClipImage = ClipImage(pMono, nWidth, nHeight, nNewWidth, nNewHeight);

	if (pClipImage == NULL)
		return 0;

	ZeroMemory(pResult, sizeof(BYTE)*COPYDATA_VCR_MAX_LENGTH);
	if(ReadVC(pClipImage, nNewWidth, nNewHeight, pResult) > 0)
	{
		if (pClipImage != NULL)
		{
			delete[] pClipImage;
			pClipImage = NULL;
		}

		if (pMono != NULL)
		{
			delete[] pMono;
			pMono = NULL;
		}

		return 1;
	}

	BYTE* pHalfImage = NULL;
	int	nHalfHeight;
	int nHalfWidth;
	pHalfImage = HalfImage(pClipImage, nNewWidth, nNewHeight, nHalfWidth, nHalfHeight);

	if (pHalfImage == NULL)
		return 0;

	nRet = ReadVC(pHalfImage, nHalfWidth, nHalfHeight, pResult);

	if (pHalfImage != NULL)
	{
		delete[] pHalfImage;
		pHalfImage = NULL;
	}

	if (pClipImage != NULL)
	{
		delete[] pClipImage;
		pClipImage = NULL;
	}

	if (pMono != NULL)
	{
		delete[] pMono;
		pMono = NULL;
	}

	return nRet;

}

/*************************************************************************/
/*****  Module:     VrExerciserDlg.cpp                               *****/
/*****  Procedure:  OnInitDialog()                      [Event]      *****/
/*****  Parameters: None                                             *****/
/*****  Return:     None                                             *****/
/*****  Uses:       None                                             *****/
/*****                                                               *****/
/*****  Description:                                                 *****/
/*****    This procedure initializes the dialog and subclasses the   *****/
/*****    bitmap control.                                            *****/
/*****                                                               *****/
/*****  History:                                                     *****/
/*****  Version   ---Date----  Who  ----------Description ---------- *****/
/*****  01.00.00  01 Oct 2003  DEW  Initial version                  *****/
/*****                                                               *****/
/*************************************************************************/
BOOL CVrExerciserDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
// Test initalize the Combo Box - Cam V Nguyen
	TCHAR m_strVerVR[100];
	TCHAR m_strVersion[100];
	int intRetCode;
	m_nMatrixSize = 0;
	m_nBitsPerCell = 4;
	m_nPrefiltering = 0;
	m_nSampleWidth = 4;
	m_cboSymType.SetCurSel(0);
	m_cboMatSize.SetCurSel(0);
	m_cbSampleWidth.SetCurSel(3);
	m_cbBitsPerCell.SetCurSel(1);
	m_cboIsContrastNormal.SetCurSel(0);
	intRetCode = GetDllVersion((char *) m_strVerVR,sizeof(m_strVerVR));
	sprintf(m_strVersion,"VRDLL %s", m_strVerVR);
	SetDlgItemText(IDC_STATIC_BITMAPINFO,m_strVersion);

	iFlag = 0;
	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// Subclass the CStatic bitmap control
	m_bmp.SubclassDlgItem( IDC_STATIC_BITMAP, this);

	CreateDirectory(FILE_FAIL_PATH, NULL);
	LoadParam();
	OnBnClickedCheckModeAuto();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

/*************************************************************************/
/*****  Module:     VrExerciserDlg.cpp                               *****/
/*****  Procedure:  OnLoadBitmap()                      [Event]      *****/
/*****  Parameters: None                                             *****/
/*****  Return:     None                                             *****/
/*****  Uses:       <CShowBitmap>.GetBitmapColors()                  *****/
/*****              <CShowBitmap>.GetBitmapDimension()               *****/
/*****              <CShowBitmap>.GetBitmapSize()                    *****/
/*****              <CShowBitmap>.LoadBitmapFile()                   *****/
/*****                                                               *****/
/*****  Description:                                                 *****/
/*****    This procedure loads a bitmap and displays the             *****/
/*****    information about the bitmap.                              *****/
/*****                                                               *****/
/*****  History:                                                     *****/
/*****  Version   ---Date----  Who  ----------Description ---------- *****/
/*****  01.00.00  01 Oct 2003  DEW  Initial version                  *****/
/*****                                                               *****/
/*************************************************************************/
void CVrExerciserDlg::OnLoadBitmap()
{
	CString strFileInfo;
	CString strColor;
	SIZE	sizeBM;
	BOOL	blnResult;
	long	lngColor;
	long	lngSize;

	// create OPEN File dialog box
	CFileDialog dlgOpen(TRUE,
		"bmp",
		NULL,
		OFN_PATHMUSTEXIST |	OFN_EXPLORER | OFN_HIDEREADONLY |
		OFN_FILEMUSTEXIST | OFN_LONGNAMES,
		"Bitmaps (*.bmp)|*.bmp|All Files (*.*)|*.*||",
		this);

	if (m_strFileDir.IsEmpty())
		dlgOpen.m_ofn.lpstrInitialDir = "C:\\";
	else
		dlgOpen.m_ofn.lpstrInitialDir = m_strFileDir;

	dlgOpen.m_ofn.lpstrTitle = "Load Vericode image file";

	// Check for selected file and display information
	if (dlgOpen.DoModal() == IDOK)
	{

		/////
		// Save the current path for use on the next bitmap load
		/////

		CFileFind ffLook;
		BOOL blnFound;

		// Find the selected file to set the CFileFind object
		blnFound = ffLook.FindFile(dlgOpen.m_ofn.lpstrFile);
		if (blnFound != 0)                  // Should always be <> 0, but check anyway
		{
			// Now FindNext to enable root file extraction
			blnFound = ffLook.FindNextFile();
			m_strFileDir = ffLook.GetRoot();
		}

		/////
		// Load the specified bitmap
		/////
		blnResult = m_bmp.LoadBitmapFile(dlgOpen.GetPathName());
		if (!blnResult)
		{
			SetDlgItemText(IDC_STATIC_BITMAPINFO,
						"ERROR: Unable to load specified file");
			GetDlgItem(IDC_STATIC_BITMAP)->MoveWindow(30, 120, 320, 240);
			return;
		}

		lngSize = m_bmp.GetBitmapSize();
		sizeBM = m_bmp.GetBitmapDimension();
		lngColor = m_bmp.GetBitmapColors();

		switch (lngColor)                   // Choose color mode
		{
		case 0:
			strColor = "Defined by JPEG";
			break;
		case 1:
			strColor = "Monochrome (1 bit)";
			break;
		case 4:
			strColor = "16 colors (4 bit)";
			break;
		case 8:
			strColor = "256 colors (8 bit)";
			break;
		case 16:
			strColor = "High Color (16 bit)";
			break;
		case 24:
		case 32:
			strColor.Format("True Color (%d bit)", lngColor);
			break;
		default:
			strColor = "Unknown";
		}

		strFileInfo.Format("File: %s\nDimension: %d x %d\n%s\nSize: %ld",
			               dlgOpen.GetFileName(),sizeBM.cx, sizeBM.cy,
						   strColor, lngSize);

		SetDlgItemText(IDC_STATIC_BITMAPINFO,strFileInfo);

		GetDlgItem(IDC_STATIC_BITMAP)->MoveWindow(30, 120 ,
						(sizeBM.cx > 320 ? 320 : sizeBM.cx),
						(sizeBM.cy > 240 ? 240 : sizeBM.cy));

		GetDlgItem(IDC_DECODE )->EnableWindow(TRUE);

	}
}

bool CVrExerciserDlg::LoadBitmap(LPCSTR strFileName)
{
	CString strFileInfo;
	CString strColor;
	SIZE	sizeBM;
	BOOL	blnResult;
	long	lngColor;
	long	lngSize;

	// create OPEN File dialog box


	// Check for selected file and display information

	blnResult = m_bmp.LoadBitmapFile(strFileName);
	if (!blnResult)
	{
		SetDlgItemText(IDC_STATIC_BITMAPINFO,
			"ERROR: Unable to load specified file");
		GetDlgItem(IDC_STATIC_BITMAP)->MoveWindow(30, 120, 320, 240);
		return FALSE;
	}

	lngSize = m_bmp.GetBitmapSize();
	sizeBM = m_bmp.GetBitmapDimension();
	lngColor = m_bmp.GetBitmapColors();

	switch (lngColor)                   // Choose color mode
	{
	case 0:
		strColor = "Defined by JPEG";
		break;
	case 1:
		strColor = "Monochrome (1 bit)";
		break;
	case 4:
		strColor = "16 colors (4 bit)";
		break;
	case 8:
		strColor = "256 colors (8 bit)";
		break;
	case 16:
		strColor = "High Color (16 bit)";
		break;
	case 24:
	case 32:
		strColor.Format("True Color (%d bit)", lngColor);
		break;
	default:
		strColor = "Unknown";
	}

	strFileInfo.Format("File: %s\nDimension: %d x %d\n%s\nSize: %ld",
		strFileName,sizeBM.cx, sizeBM.cy,
		strColor, lngSize);

	SetDlgItemText(IDC_STATIC_BITMAPINFO,strFileInfo);

	GetDlgItem(IDC_STATIC_BITMAP)->MoveWindow(30, 120 ,
		(sizeBM.cx > 320 ? 320 : sizeBM.cx),
		(sizeBM.cy > 240 ? 240 : sizeBM.cy));

	GetDlgItem(IDC_DECODE )->EnableWindow(TRUE);

	return TRUE;
}

/*************************************************************************/
/*****  Module:     VrExerciserDlg.cpp                               *****/
/*****  Procedure:  OnPaint()                           [Event]      *****/
/*****  Parameters: None                                             *****/
/*****  Return:     None                                             *****/
/*****  Uses:       None                                             *****/
/*****                                                               *****/
/*****  Description:                                                 *****/
/*****    This procedure either paints the icon (minimized) or the   *****/
/*****    dialog.                                                    *****/
/*****                                                               *****/
/*****  History:                                                     *****/
/*****  Version   ---Date----  Who  ----------Description ---------- *****/
/*****  01.00.00  01 Oct 2003  DEW  Initial version                  *****/
/*****                                                               *****/
/*************************************************************************/
void CVrExerciserDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

/*************************************************************************/
/*****  Module:     VrExerciserDlg.cpp                               *****/
/*****  Procedure:  OnQueryDragIcon()                   [Event]      *****/
/*****  Parameters: None                                             *****/
/*****  Return:     Handle to cursor                                 *****/
/*****  Uses:       None                                             *****/
/*****                                                               *****/
/*****  Description:                                                 *****/
/*****    This procedure returns the cursor to diplay while          *****/
/*****    dragging.                                                  *****/
/*****                                                               *****/
/*****  History:                                                     *****/
/*****  Version   ---Date----  Who  ----------Description ---------- *****/
/*****  01.00.00  01 Oct 2003  DEW  Initial version                  *****/
/*****                                                               *****/
/*************************************************************************/
HCURSOR CVrExerciserDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

/*************************************************************************/
/*****  Module:     VrExerciserDlg.cpp                               *****/
/*****  Procedure:  OnReset()                           [Event]      *****/
/*****  Parameters: None                                             *****/
/*****  Return:     None                                             *****/
/*****  Uses:       None                                             *****/
/*****                                                               *****/
/*****  Description:                                                 *****/
/*****    This procedure resets the controls on the dialog.          *****/
/*****                                                               *****/
/*****  History:                                                     *****/
/*****  Version   ---Date----  Who  ----------Description ---------- *****/
/*****  01.00.00  01 Oct 2003  DEW  Initial version                  *****/
/*****                                                               *****/
/*************************************************************************/
void CVrExerciserDlg::OnReset()
{
	TCHAR m_strVerVR[100];
	TCHAR m_strVersion[100];
	int intRetCode;
	intRetCode = GetDllVersion((char *) m_strVerVR,sizeof(m_strVerVR));
	sprintf(m_strVersion,"VRDLL %s\n",
		         m_strVerVR);
	SetDlgItemText(IDC_STATIC_BITMAPINFO,m_strVersion);
//	SetDlgItemText(IDC_STATIC_BITMAPINFO,"Bitmap Filename");
	SetDlgItemText(IDC_STATIC_TEXT,"Vericode Text");
	m_bmp.ResetBitmap();
	GetDlgItem(IDC_DECODE )->EnableWindow(FALSE);
	GetDlgItem(IDC_STATIC_BITMAP)->MoveWindow(30, 120, 320, 240);
}

/*************************************************************************/
/*****  Module:     VrExerciserDlg.cpp                               *****/
/*****  Procedure:  OnSysCommand()                      [Event]      *****/
/*****  Parameters: None                                             *****/
/*****  Return:     None                                             *****/
/*****  Uses:       None                                             *****/
/*****                                                               *****/
/*****  Description:                                                 *****/
/*****    This procedure executes either the "ABOUT" dialog or       *****/
/*****    performs the "Move" or "Close" sys command functions.      *****/
/*****                                                               *****/
/*****  History:                                                     *****/
/*****  Version   ---Date----  Who  ----------Description ---------- *****/
/*****  01.00.00  01 Oct 2003  DEW  Initial version                  *****/
/*****                                                               *****/
/*************************************************************************/
void CVrExerciserDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}


void CVrExerciserDlg::OnSelchangeCOMBOMatSize()
{
	CString txtStr;
	// TODO: Add your control notification handler code here
	m_cboMatSize.GetLBText(m_cboMatSize.GetCurSel(),txtStr);
	m_nMatrixSize = atoi(txtStr);
	switch (m_nMatrixSize)
	{
	case 0:
		SetDlgItemText(IDC_STATIC_STATUS,"Auto Matrix Size(0) working:\nSquare and  Rectangle VC \nSquare and  Rectangle DM");
		break;
	case 9:
		SetDlgItemText(IDC_STATIC_STATUS,"9-> DM Size 18x8");
		break;
	case 11:
		SetDlgItemText(IDC_STATIC_STATUS,"11-> DM Size 32x8");
		break;
	case 13:
		SetDlgItemText(IDC_STATIC_STATUS,"13-> DM Size 26x12\n  VC Size 26x8");
		break;
	case 15:
		SetDlgItemText(IDC_STATIC_STATUS,"15-> DM Size 32x8");
		break;
	case 17:
		SetDlgItemText(IDC_STATIC_STATUS,"17-> DM Size 36x16\n  VC Size 34x10");
		break;
	case 19:
		SetDlgItemText(IDC_STATIC_STATUS,"19-> DM Size 48x16");
		break;
	case 21:
		SetDlgItemText(IDC_STATIC_STATUS,"21-> VC Size 42x12");
		break;

		default :
			SetDlgItemText(IDC_STATIC_STATUS,"Fixed Matrix Size");
	}
	UpdateData(false);

}

void CVrExerciserDlg::OnSelchangeCOMBOSampleWidth()
{
	CString tmpStr;
	// TODO: Add your control notification handler code here
    m_cbSampleWidth.GetLBText(m_cbSampleWidth.GetCurSel(),tmpStr);
	m_nSampleWidth = atoi(tmpStr);
}

void CVrExerciserDlg::OnSelchangeCOMBOBitsPerCell()
{
	// TODO: Add your control notification handler code here
	CString tmpStr;
    m_cbBitsPerCell.GetLBText(m_cbBitsPerCell.GetCurSel(),tmpStr);
	m_nBitsPerCell = atoi(tmpStr);
}


void CVrExerciserDlg::OnCHECKFixedMT()
{
	CString txtStr;
	// TODO: Add your control notification handler code here
	if(m_bMatrixFixed.GetCheck() == 1)
	{
		m_cboMatSize.EnableWindow(TRUE);
		m_cboMatSize.GetLBText(m_cboMatSize.GetCurSel(),txtStr);
		m_nMatrixSize = atoi(txtStr);
	}
		else
    {
		m_cboMatSize.SetCurSel(0);
		m_cboMatSize.EnableWindow(FALSE);
		m_nMatrixSize = 0;
		SetDlgItemText(IDC_STATIC_STATUS,"Auto Matrix Size(0) working:\nSquare and  Rectangle VC \nSquare and  Rectangle DM");

	}

}

void CVrExerciserDlg::OnCHECKPreFilter()
{
	// TODO: Add your control notification handler code here
	if(m_bPreFilter.GetCheck() == 1)
		m_nPrefiltering = 1;
	else
     	m_nPrefiltering = 0;

}

void CVrExerciserDlg::OnSelchangeComboSym()
{
	int indexMax;
	m_cboSymType.GetLBText(m_cboSymType.GetCurSel(),m_StrSymType);
	indexMax = m_cboMatSize.GetCount();
// iFlag is a flag control for previous selection of Auto, VC or DM
// iFlag =0: "Auto", 1: "VC", 2: "DM"

	if (m_StrSymType=="Auto")
	{
		if (indexMax < 28)
		{
			switch(iFlag)
			{
			case 1:
				m_cboMatSize.InsertString (8,"19");
				m_cboMatSize.InsertString (5,"15");
				m_cboMatSize.InsertString (2,"11");
				m_cboMatSize.InsertString (1,"9");
			break;
			case 2:
				m_cboMatSize.InsertString (20,"46");
				m_cboMatSize.InsertString (19,"42");
				m_cboMatSize.InsertString (18,"38");
				m_cboMatSize.InsertString (17,"34");
				m_cboMatSize.InsertString (16,"30");
				m_cboMatSize.InsertString (16,"28");
				m_cboMatSize.InsertString (13,"21");
			break;
			}

		}//end indexMax
		iFlag =0;
	}//end m_StrSymType=="Auto"



	if(m_StrSymType=="VC")
	{
		if(m_cboIsContrastNormal.GetCount()<3)
		{
			m_cboIsContrastNormal.AddString("Outline Border");
		}
		if (iFlag!=1)
		{
			m_cboMatSize.DeleteString(11);
			m_cboMatSize.DeleteString(7);
			m_cboMatSize.DeleteString(3);
			m_cboMatSize.DeleteString(1);
		}//end iFlag
		if(indexMax <24)
		{
			m_cboMatSize.InsertString (16,"46");
			m_cboMatSize.InsertString (15,"42");
			m_cboMatSize.InsertString (14,"38");
			m_cboMatSize.InsertString (13,"34");
			m_cboMatSize.InsertString (12,"30");
			m_cboMatSize.InsertString (12,"28");
			m_cboMatSize.InsertString (9,"21");
		}//end index<24

		iFlag = 1;
	}//end m_StrSymType=="VC"

	if(m_StrSymType=="DM")
	{
		m_cboIsContrastNormal.DeleteString(2);
		m_cboIsContrastNormal.SetCurSel(0);
		switch(iFlag)
		{
		case 0:
			m_cboMatSize.DeleteString(26);
			m_cboMatSize.DeleteString(24);
			m_cboMatSize.DeleteString(22);
			m_cboMatSize.DeleteString(20);
			m_cboMatSize.DeleteString(18);
			m_cboMatSize.DeleteString(17);
			m_cboMatSize.DeleteString(13);
			break;
		case 1:
			m_cboMatSize.DeleteString(22);
			m_cboMatSize.DeleteString(20);
			m_cboMatSize.DeleteString(18);
			m_cboMatSize.DeleteString(16);
			m_cboMatSize.DeleteString(14);
			m_cboMatSize.DeleteString(13);
			m_cboMatSize.DeleteString(9);
			m_cboMatSize.InsertString(8,"19");
			m_cboMatSize.InsertString(5,"15");
			m_cboMatSize.InsertString(2,"11");
			m_cboMatSize.InsertString(1,"9");
			break;
		case 2:
			break;
		}//end switch
		iFlag = 2;

		} //end m_StrSymType=="DM"

}

void CVrExerciserDlg::OnSelchangeComboContrast()
{

}

LRESULT CVrExerciserDlg::OnDecodeMsg(WPARAM wParam, LPARAM lParam)
{
	CString strMessage;
	COPYDATASTRUCT cds;

	const	int nCNTTrhes = 16;
	int nResult = TRUE;
	BYTE pucUserData[COPYDATA_VCR_MAX_LENGTH];
	ZeroMemory(pucUserData, sizeof(BYTE)*COPYDATA_VCR_MAX_LENGTH);
	int arrThreshold[nCNTTrhes] ={0, 200, 190, 210, 180, 220, 170, 230, 160, 150, 140, 80, 100, 60, 50, 120};
	int nIdxThesh = 0;

	GetTimeString();
	strMessage.Format("%s : VC Read Start!",m_strTime);
	m_ctrlListLog.AddString(strMessage);
	m_ctrlListLog.SetCurSel(m_ctrlListLog.GetCount()-1);


	if(!LoadBitmap(FILE_NAME_SOURCE))
	{
		nResult = FALSE;
		sprintf((char*)pucUserData,"");
		return 0;
	}

	for ( nIdxThesh = 0; nIdxThesh < nCNTTrhes ; nIdxThesh++)
	{
		if(Decode(arrThreshold[nIdxThesh], pucUserData) <= 0)
		{
			nResult = FALSE;
			sprintf((char*)pucUserData,"");
			strMessage.Format("%s : VC Read Fail! Threshold = %d",m_strTime, arrThreshold[nIdxThesh]);
			m_ctrlListLog.AddString(strMessage);
			m_ctrlListLog.SetCurSel(m_ctrlListLog.GetCount()-1);
		}
		else
		{
			m_strResultEdit.Format("%s", pucUserData);
			UpdateData(FALSE);
			nResult = TRUE;
			strMessage.Format("%s : VC Read Success! Threshold = %d",m_strTime, arrThreshold[nIdxThesh]);
			m_ctrlListLog.AddString(strMessage);
			m_ctrlListLog.SetCurSel(m_ctrlListLog.GetCount()-1);
			break;
		}
	}



	cds.dwData = COPYDATA_VCR;
	cds.lpData = pucUserData;
	cds.cbData = COPYDATA_VCR_MAX_LENGTH;

	GetTimeString();
	strMessage.Format("%s : VC Read End : [%s]!",m_strTime, pucUserData);
	m_ctrlListLog.AddString(strMessage);
	m_ctrlListLog.SetCurSel(m_ctrlListLog.GetCount()-1);

	HWND hWnd = ::FindWindow(NULL, PROGNAME_AOISERVER);

	if(hWnd ==0) // 못 찾았을 경우
	{
		GetTimeString();
		strMessage.Format("%s : AOIServer를 찾을 수 없습니다.",m_strTime);
		m_ctrlListLog.AddString(strMessage);
		m_ctrlListLog.SetCurSel(m_ctrlListLog.GetCount()-1);

	}

	else
	{
		GetTimeString();
		strMessage.Format("%s : 결과 전송.",m_strTime);
		m_ctrlListLog.AddString(strMessage);
		m_ctrlListLog.SetCurSel(m_ctrlListLog.GetCount()-1);

		::SendMessage(hWnd, WM_COPYDATA, 0,  (CONST LPARAM)&cds); // 외부로 보낼시에는 "::"를 한다.
	}

	CreateDirectory(FILE_FAIL_PATH,NULL);

	CString strNewFileName;


	if (nResult)
	{
		strNewFileName.Format("%s%s.bmp", FILE_RESULT_PATH, m_strTime);
		if(FALSE == MoveFile(FILE_NAME_SOURCE, strNewFileName))
			DeleteFile(FILE_NAME_SOURCE);
	}
	else
	{
		strNewFileName.Format("%s%s.bmp", FILE_FAIL_PATH, m_strTime);
		MoveFile(FILE_NAME_SOURCE, strNewFileName);
	}


//	OnBnClickedCheckModeAuto();
	return 0;

	//	return CDialog::OnCopyData(pWnd, pCopyDataStruct);
}


BOOL CVrExerciserDlg::OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	return 0;
}

void CVrExerciserDlg::GetTimeString()
{
	CTime time = CTime::GetCurrentTime();
	m_strTime.Format("%02d%02d_%02d%02d%02d",time.GetMonth(),time.GetDay(),time.GetHour(),time.GetMinute(),time.GetSecond());
}


UINT CVrExerciserDlg::ThreadFileRead(LPVOID pParam)
{
	CVrExerciserDlg* pWnd = (CVrExerciserDlg*)pParam;
	FILE* pFile = NULL;
	while (pWnd->m_bCheckAuto)
	{
		if(pFile = fopen(FILE_NAME_SOURCE,"r"))
		{
			fclose(pFile);
			pFile = NULL;
			pWnd->SendMessage(UM_DECODE, NULL, NULL);

		}
		Sleep(1000);
	}
	return 0;
}

void CVrExerciserDlg::OnBnClickedCheckModeAuto()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	if (m_bCheckAuto)
	{
		m_pThread = AfxBeginThread(ThreadFileRead, this);
	}
}

int CVrExerciserDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	GoToTray();

	return 0;
}

void CVrExerciserDlg::GoToTray(void)
{
	NOTIFYICONDATA nid;
	::ZeroMemory(&nid, sizeof(nid));
	nid.cbSize = sizeof(nid);
	nid.hWnd = m_hWnd;
	nid.uID = IDR_MAINFRAME;
	nid.uFlags = NIF_MESSAGE | NIF_ICON | NIF_TIP;
	nid.uCallbackMessage = UM_TRAY;
	nid.hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	wsprintf(nid.szTip, _T("%s"), _T("VCR Reader"));

	::Shell_NotifyIcon(NIM_ADD, &nid);
}

void CVrExerciserDlg::OnDestroy()
{
	SaveParam();

	NOTIFYICONDATA nid;
	nid.cbSize = sizeof(nid);
	nid.hWnd = m_hWnd;
	nid.uID = IDR_MAINFRAME;

	::Shell_NotifyIcon(NIM_DELETE, &nid);


	CDialog::OnDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}

void CVrExerciserDlg::OnClose()
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	ShowWindow(SW_HIDE);

	//CDialog::OnClose();
}

LRESULT CVrExerciserDlg::OnTray(WPARAM wParam, LPARAM lParam)
{
	if(lParam == WM_RBUTTONDOWN)
	{
		SetCapture();
	}
	else if(lParam == WM_RBUTTONUP)
	{
		CMenu menu, *pMenu = NULL;
		CPoint pt;

		//menu.LoadMenuA(IDR_Tray);
		menu.LoadMenu(IDR_TRAY);
		pMenu = menu.GetSubMenu(0);

		GetCursorPos(&pt);
		SetForegroundWindow();
		pMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_LEFTBUTTON,
			pt.x, pt.y, this);
		::PostMessage(m_hWnd, WM_NULL, 0, 0);

		ReleaseCapture();
	}
	else if(lParam == WM_LBUTTONDBLCLK)
	{
		ShowWindow(SW_SHOW);
		SetForegroundWindow();
	}

	return 0;
	//return LRESULT();
}

void CVrExerciserDlg::OnShowApplication()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	ShowWindow(SW_SHOW);
}

void CVrExerciserDlg::OnTrayExit()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	//CDialog::OnDestroy();
	//AfxGetApp()->ExitInstance();
	CDialog::OnOK();
}

void CVrExerciserDlg::OnBnClickedBtnSave()
{
	SaveParam();
}

BOOL CVrExerciserDlg::SaveParam()
{
	UpdateData(TRUE);

	CDataManager Data;

	char strRegBuf[255] = {0,};

	BOOL bRet = TRUE;

	// symboltype
	sprintf_s(strRegBuf, sizeof(char)*255, "%d", (int)m_cboSymType.GetCurSel());
	bRet &= Data.WriteString(SHCU,KEY_VRE,_T("symboltype"),strRegBuf);

	// matrixfixed
	sprintf_s(strRegBuf, sizeof(char)*255, "%d",(int)m_bMatrixFixed.GetCheck());
	bRet &= Data.WriteString(SHCU,KEY_VRE,_T("matrixfixed"),strRegBuf);

	// matrixsize
	sprintf_s(strRegBuf, sizeof(char)*255, "%d",(int)m_cboMatSize.GetCurSel());
	bRet &= Data.WriteString(SHCU,KEY_VRE,_T("matrixsize"),strRegBuf);

	// samplewidth
	sprintf_s(strRegBuf, sizeof(char)*255, "%d",(int)m_cbSampleWidth.GetCurSel());
	bRet &= Data.WriteString(SHCU,KEY_VRE,_T("samplewidth"),strRegBuf);

	// bitspercell
	sprintf_s(strRegBuf, sizeof(char)*255, "%d",(int)m_cbBitsPerCell.GetCurSel());
	bRet &= Data.WriteString(SHCU,KEY_VRE,_T("bitspercell"),strRegBuf);

	// symbol
	sprintf_s(strRegBuf, sizeof(char)*255, "%d",(int)m_cboIsContrastNormal.GetCurSel());
	bRet &= Data.WriteString(SHCU,KEY_VRE,_T("symbol"),strRegBuf);

	// prefiltering
	sprintf_s(strRegBuf, sizeof(char)*255, "%d",(int)m_bPreFilter.GetCheck());
	bRet &= Data.WriteString(SHCU,KEY_VRE,_T("prefiltering"),strRegBuf);


	return bRet;
}

BOOL CVrExerciserDlg::LoadParam()
{
	CDataManager Data;

	char strRegBuf[255] = {0,};

	// symboltype
	memset(strRegBuf,0,sizeof(char)*255);
	if(Data.ReadString(SHCU,KEY_VRE,_T("symboltype"),(LPBYTE)strRegBuf,255) == FALSE)
	{
		strcpy_s(strRegBuf,sizeof(char)*255,"0");
	}
	int nValue = (int)_tstoi( (CString)(CStringA)strRegBuf );
	m_cboSymType.SetCurSel(nValue);
	OnSelchangeComboSym();

	// matrixfixed
	memset(strRegBuf,0,sizeof(char)*255);
	if(Data.ReadString(SHCU,KEY_VRE,_T("matrixfixed"),(LPBYTE)strRegBuf,255) == FALSE)
	{
		strcpy_s(strRegBuf,sizeof(char)*255,"0");
	}
	BOOL bCheck = (BOOL)_tstoi( (CString)(CStringA)strRegBuf );
	m_bMatrixFixed.SetCheck(bCheck);
	OnCHECKFixedMT();

	// matrixsize
	memset(strRegBuf,0,sizeof(char)*255);
	if(Data.ReadString(SHCU,KEY_VRE,_T("matrixsize"),(LPBYTE)strRegBuf,255) == FALSE)
	{
		strcpy_s(strRegBuf,sizeof(char)*255,"0");
	}
	nValue = (int)_tstoi( (CString)(CStringA)strRegBuf );
	if(nValue < 0)
		nValue = 0;
	m_cboMatSize.SetCurSel(nValue);
	OnSelchangeCOMBOMatSize();

	// samplewidth
	memset(strRegBuf,0,sizeof(char)*255);
	if(Data.ReadString(SHCU,KEY_VRE,_T("samplewidth"),(LPBYTE)strRegBuf,255) == FALSE)
	{
		strcpy_s(strRegBuf,sizeof(char)*255,"4");
	}
	nValue = (int)_tstoi( (CString)(CStringA)strRegBuf );
	m_cbSampleWidth.SetCurSel(nValue);
	OnSelchangeCOMBOSampleWidth();

	// bitspercell
	memset(strRegBuf,0,sizeof(char)*255);
	if(Data.ReadString(SHCU,KEY_VRE,_T("bitspercell"),(LPBYTE)strRegBuf,255) == FALSE)
	{
		strcpy_s(strRegBuf,sizeof(char)*255,"4");
	}
	nValue = (int)_tstoi( (CString)(CStringA)strRegBuf );
	m_cbBitsPerCell.SetCurSel(nValue);
	OnSelchangeCOMBOBitsPerCell();

	// symbol
	memset(strRegBuf,0,sizeof(char)*255);
	if(Data.ReadString(SHCU,KEY_VRE,_T("symbol"),(LPBYTE)strRegBuf,255) == FALSE)
	{
		strcpy_s(strRegBuf,sizeof(char)*255,"0");
	}
	nValue = (int)_tstoi( (CString)(CStringA)strRegBuf );
	m_cboIsContrastNormal.SetCurSel(nValue);
	OnSelchangeComboContrast();

	// prefiltering
	memset(strRegBuf,0,sizeof(char)*255);
	if(Data.ReadString(SHCU,KEY_VRE,_T("prefiltering"),(LPBYTE)strRegBuf,255) == FALSE)
	{
		strcpy_s(strRegBuf,sizeof(char)*255,"0");
	}
	bCheck = (int)_tstoi( (CString)(CStringA)strRegBuf );
	m_bPreFilter.SetCheck(bCheck);
	OnCHECKPreFilter();

	return TRUE;
}