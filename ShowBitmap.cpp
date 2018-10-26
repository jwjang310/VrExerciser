/*************************************************************************/
/*****  Module:     ShowBitmap.cpp                                   *****/
/*****  Contents:   CShowBitmap()                                    *****/
/*****              ~CShowBitmap()                                   *****/
/*****              GetBitmapColors()                                *****/
/*****              GetBitmapData()                                  *****/
/*****              GetBitmapDimension()                             *****/
/*****              GetBitmapSize()                                  *****/
/*****              LoadBitmapFile()                                 *****/
/*****              OnPaint()                                        *****/
/*****              OnSize()                                         *****/
/*****              ResetBitmap()                                    *****/
/*****                                                               *****/
/*****  Description:                                                 *****/
/*****    This module contains the bitmap handling functions.        *****/
/*****                                                               *****/
/*****                                                               *****/
/*****  History:                                                     *****/
/*****  Version  ---Date----  Who  ----------Description ----------  *****/
/*****  01.00.00 01 Oct 2003  DEW  Initial version                   *****/
/*****                                                               *****/
/*****  Copyright(c)   2003     Veritec, Inc.                        *****/
/*************************************************************************/
/*****  Start of Visual SourceSafe Information  ******
 * $History: ShowBitmap.cpp $
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
// ShowBitmap.cpp : implementation file
//

/////////////////////////////////////////////////////////////////////////////
// Includes    
/////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "VrExerciser.h"
#include "ShowBitmap.h"

/////////////////////////////////////////////////////////////////////////////
// Defines     
/////////////////////////////////////////////////////////////////////////////
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CShowBitmap
/////////////////////////////////////////////////////////////////////////////
/*************************************************************************/
/*****  Module:     ShowBitmap.cpp                                   *****/
/*****  Procedure:  CShowBitmap()                       [Constructor]*****/
/*****  Parameters: None                                             *****/
/*****  Return:     None                                             *****/
/*****  Uses:       None                                             *****/
/*****                                                               *****/
/*****  Description:                                                 *****/
/*****    This procedure constructs the class and initializes        *****/
/*****    required variables.                                        *****/
/*****                                                               *****/
/*****  History:                                                     *****/
/*****  Version   ---Date----  Who  ----------Description ---------- *****/
/*****  01.00.00   01 Oct 03   DEW  Initial version                  *****/
/*****                                                               *****/
/*************************************************************************/
CShowBitmap::CShowBitmap()
{
	// Create the memory device context
	m_dc.CreateCompatibleDC(NULL);
	m_hbm = NULL;
}

/*************************************************************************/
/*****  Module:     ShowBitmap.cpp                                   *****/
/*****  Procedure:  ~CShowBitmap()                      [Destructor] *****/
/*****  Parameters: None                                             *****/
/*****  Return:     None                                             *****/
/*****  Uses:       None                                             *****/
/*****                                                               *****/
/*****  Description:                                                 *****/
/*****    This procedure destroys the class, releasing used          *****/
/*****    resources.                                                 *****/
/*****                                                               *****/
/*****  History:                                                     *****/
/*****  Version   ---Date----  Who  ----------Description ---------- *****/
/*****  01.00.00  01 Oct 2003  DEW  Initial version                  *****/
/*****                                                               *****/
/*************************************************************************/
CShowBitmap::~CShowBitmap()
{
	// Restore the memory device context
	SelectObject(m_dc.m_hDC, m_hbm_default);

	if ( m_hbm != NULL)
		DeleteObject(m_hbm);                // Destroy the bitmap object
}


/////////////////////////////////////////////////////////////////////////////
// CShowBitmap message map         
/////////////////////////////////////////////////////////////////////////////
BEGIN_MESSAGE_MAP(CShowBitmap, CStatic)
	//{{AFX_MSG_MAP(CShowBitmap)
	ON_WM_PAINT()
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShowBitmap message handlers
/////////////////////////////////////////////////////////////////////////////
/*************************************************************************/
/*****  Module:     ShowBitmap.cpp                                   *****/
/*****  Procedure:  OnPaint()                           [Event]      *****/
/*****  Parameters: None                                             *****/
/*****  Return:     None                                             *****/
/*****  Uses:       None                                             *****/
/*****                                                               *****/
/*****  Description:                                                 *****/
/*****    This procedure handles to OnPaint window message.          *****/
/*****                                                               *****/
/*****  History:                                                     *****/
/*****  Version   ---Date----  Who  ----------Description ---------- *****/
/*****  01.00.00  01 Oct 2003  DEW  Initial version                  *****/
/*****                                                               *****/
/*************************************************************************/
void CShowBitmap::OnPaint() 
{
	CPaintDC	dcPaint(this);              // Device context for painting
	BOOL		blnResult;
	RECT		rectBM;
	
	if (!m_hbm)
	{
		// No bitmap loaded, paint white area
		dcPaint.Rectangle(&dcPaint.m_ps.rcPaint);
		dcPaint.FillSolidRect(dcPaint.m_ps.rcPaint.left,
						 dcPaint.m_ps.rcPaint.top,
						 dcPaint.m_ps.rcPaint.right - dcPaint.m_ps.rcPaint.left,
						 dcPaint.m_ps.rcPaint.bottom - dcPaint.m_ps.rcPaint.top,
						 RGB(255,255,255) );
	}
	else
	{
		// Bitmap exists, copy it into the device context
		
		GetClientRect(&rectBM);
		dcPaint.SetStretchBltMode(COLORONCOLOR);
		blnResult = dcPaint.StretchBlt(0, 0, rectBM.right, rectBM.bottom, 
				 				&m_dc, 0, 0, m_dib.dsBmih.biWidth,
								m_dib.dsBmih.biHeight, SRCCOPY);
	}
	// Do not call CStatic::OnPaint() for painting messages
}

/*************************************************************************/
/*****  Module:     ShowBitmap.cpp                                   *****/
/*****  Procedure:  OnSize()                            [Event]      *****/
/*****  Parameters: nType - Resize type                              *****/
/*****              cx    - New width                                *****/
/*****              cy    - New height                               *****/
/*****  Return:     None                                             *****/
/*****  Uses:       None                                             *****/
/*****                                                               *****/
/*****  Description:                                                 *****/
/*****    This procedure handles to OnSize window message.           *****/
/*****                                                               *****/
/*****  History:                                                     *****/
/*****  Version   ---Date----  Who  ----------Description ---------- *****/
/*****  01.00.00   01 Oct 03   DEW  Initial version                  *****/
/*****                                                               *****/
/*************************************************************************/
void CShowBitmap::OnSize(UINT nType, int cx, int cy) 
{
	CStatic::OnSize(nType, cx, cy);
	
	// Force repaint of window                       
	Invalidate();
	UpdateWindow();
}

/////////////////////////////////////////////////////////////////////////////
// Methods     
/////////////////////////////////////////////////////////////////////////////
/*************************************************************************/
/*****  Module:     ShowBitmap.cpp                                   *****/
/*****  Procedure:  GetBitmapColors()                   [Method]     *****/
/*****  Parameters: None                                             *****/
/*****  Return:     Number of bits of color                          *****/
/*****  Uses:       None                                             *****/
/*****                                                               *****/
/*****  Description:                                                 *****/
/*****    This procedure returns the color bits from the             *****/
/*****    bitmap header.                                             *****/
/*****                                                               *****/
/*****  History:                                                     *****/
/*****  Version   ---Date----  Who  ----------Description ---------- *****/
/*****  01.00.00   01 Oct 03   DEW  Initial version                  *****/
/*****                                                               *****/
/*************************************************************************/
long CShowBitmap::GetBitmapColors()
{
	if (m_hbm == NULL)
		return 0;                           // No bitmap loaded
	else
		return m_dib.dsBmih.biBitCount;
}

/*************************************************************************/
/*****  Module:     ShowBitmap.cpp                                   *****/
/*****  Procedure:  GetBitmapData()                     [Method]     *****/
/*****  Parameters: ucBitmap - Buffer to hold bitmap                 *****/
/*****  Return:     TRUE  - Bitmap data copied to buffer             *****/
/*****              FALSE - Bitmap data not copied to buffer         *****/
/*****  Uses:       None                                             *****/
/*****                                                               *****/
/*****  Description:                                                 *****/
/*****    This procedure returns the bitmap data (bits) from         *****/
/*****    the bitmap.                                                *****/
/*****                                                               *****/
/*****  History:                                                     *****/
/*****  Version   ---Date----  Who  ----------Description ---------- *****/
/*****  01.00.00  01 Oct 2003  DEW  Initial version                  *****/
/*****                                                               *****/
/*************************************************************************/
BOOL CShowBitmap::GetBitmapData(unsigned char *ucBitmap)
{
	CBitmap bmTemp;
	DWORD	dwBuffSize;
	DWORD	dwBytes;

	if (m_hbm == NULL)
		return FALSE;
	else
	{
		bmTemp.Attach(m_hbm);
		dwBuffSize = m_dib.dsBmih.biSizeImage;
		
		dwBytes = bmTemp.GetBitmapBits(dwBuffSize,ucBitmap);

		return TRUE;
	}
}

/*************************************************************************/
/*****  Module:     ShowBitmap.cpp                                   *****/
/*****  Procedure:  GetBitmapDimension()                [Method]     *****/
/*****  Parameters: None                                             *****/
/*****  Return:     SIZE structure with width and height             *****/
/*****  Uses:       None                                             *****/
/*****                                                               *****/
/*****  Description:                                                 *****/
/*****    This procedure returns the bitmap width and height.        *****/
/*****                                                               *****/
/*****  History:                                                     *****/
/*****  Version   ---Date----  Who  ----------Description ---------- *****/
/*****  01.00.00  01 Oct 2003  DEW  Initial version                  *****/
/*****                                                               *****/
/*************************************************************************/
SIZE CShowBitmap::GetBitmapDimension()
{
	SIZE sizeBM;

	if (m_hbm == NULL)
	{
		sizeBM.cx = 0;
		sizeBM.cy = 0;
	}
	else
	{
		sizeBM.cx = m_dib.dsBmih.biWidth;
		sizeBM.cy = m_dib.dsBmih.biHeight;
	}
   
	return sizeBM;
}

/*************************************************************************/
/*****  Module:     ShowBitmap.cpp                                   *****/
/*****  Procedure:  GetBitmapSize()                     [Method]     *****/
/*****  Parameters: None                                             *****/
/*****  Return:     Size of bitmap                                   *****/
/*****  Uses:       None                                             *****/
/*****                                                               *****/
/*****  Description:                                                 *****/
/*****    This procedure returns the bitmap size in bytes.           *****/
/*****                                                               *****/
/*****  History:                                                     *****/
/*****  Version   ---Date----  Who  ----------Description ---------- *****/
/*****  01.00.00  01 Oct 2003  DEW  Initial version                  *****/
/*****                                                               *****/
/*************************************************************************/
long CShowBitmap::GetBitmapSize()
{
	if (m_hbm == NULL)
		return 0;
	else
		return m_dib.dsBmih.biSizeImage;
}

/*************************************************************************/
/*****  Module:     ShowBitmap.cpp                                   *****/
/*****  Procedure:  LoadBitmapFile()                    [Method]     *****/
/*****  Parameters: strFilePath - Name of bitmap file                *****/
/*****  Return:     TRUE  - Bitmap loaded                            *****/
/*****              FALSE - Bitmap not loaded                        *****/
/*****  Uses:       None                                             *****/
/*****                                                               *****/
/*****  Description:                                                 *****/
/*****    This procedure loads a bitmap from file into a             *****/
/*****    bitmap object.                                             *****/
/*****                                                               *****/
/*****  History:                                                     *****/
/*****  Version   ---Date----  Who  ----------Description ---------- *****/
/*****  01.00.00  01 Oct 2003  DEW  Initial version                  *****/
/*****  01.00.10  23 Aug 2003  DEW  Modified LoadBitmap, minor       *****/
/*****                              documentation changes            *****/
/*************************************************************************/
BOOL CShowBitmap::LoadBitmapFile(CString strFilePath)
{
	if (m_hbm != NULL)                      // Delete any existing bitmap    
	{
		SelectObject(m_dc.m_hDC, m_hbm_default);
		DeleteObject(m_hbm);
	}

	// Load bitmap image from file   
	m_hbm = (HBITMAP) LoadImage(NULL, strFilePath, 
								IMAGE_BITMAP, 0, 0, 
								LR_LOADFROMFILE | LR_CREATEDIBSECTION); 

	if (m_hbm == NULL)                      // Bitmap file error   
	{
		// Invalidate the window to clear the area 
		Invalidate();
		UpdateWindow();
		return FALSE; 
	}

	// Select the opened bitmap into the memory dc
	m_hbm_default = (HBITMAP) SelectObject( m_dc.m_hDC , m_hbm);

	// Get source bitmap info
	GetObject(m_hbm, sizeof(DIBSECTION), &m_dib);

	// Re-draw self
	Invalidate();
	UpdateWindow();
 
	return TRUE;
}

/*************************************************************************/
/*****  Module:     ShowBitmap.cpp                                   *****/
/*****  Procedure:  ResetBitmap()                       [Method]     *****/
/*****  Parameters: None                                             *****/
/*****  Return:     None                                             *****/
/*****  Uses:       None                                             *****/
/*****                                                               *****/
/*****  Description:                                                 *****/
/*****    This procedure clears and releases the current             *****/
/*****    bitmap.                                                    *****/
/*****                                                               *****/
/*****  History:                                                     *****/
/*****  Version   ---Date----  Who  ----------Description ---------- *****/
/*****  01.00.00  01 Oct 2003  DEW  Initial version                  *****/
/*****                                                               *****/
/*************************************************************************/
void CShowBitmap::ResetBitmap()
{
	if (m_hbm != NULL)                      // Delete any existing bitmap    
	{
		SelectObject(m_dc.m_hDC, m_hbm_default);
		DeleteObject(m_hbm);
		m_hbm = NULL;
	}

	// Re-draw self
	Invalidate();
	UpdateWindow();

}
