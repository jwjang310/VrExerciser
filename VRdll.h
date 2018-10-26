//$Header: /COMPONENTS/viVcSymbol/VRdll.h 2     5/19/06 4:41p Cnguyen $
#ifndef VRDLL_H
#define VRDLL_H


#ifndef DVT
  #ifndef _SH3
    #include "windows.h" 	// trp - included to match Pulnex code
  #else
    #include "stdio.h"
    #include "String.h"
    #ifndef VCHEADER
      typedef char TCHAR; 	// trp - not in Pulnex code
    #endif
  #endif
#endif


/**********************************************************
* Constant Defines
***********************************************************/

/* The following ifdef block is the standard way of creating macros which make exporting
 * from a DLL simpler:
 *
 * All files within this DLL are compiled with the VRDLL_EXPORTS
 * symbol defined on the command line. this symbol should not be defined on any project
 * that uses this DLL.
 * 
 * ALL Win32 PROJECTS that use this DLL are compiled with the VRDLL_IMPORTS
 * symbol defined on the command line.
 *
 * All others (UNIX and Win32-StaticLib's, for instance) leave these symbols undefined.
 *
 * This way any other project whose source files include this file see
 * VRDLL_API functions as being imported from a DLL, wheras this DLL sees symbols
 * defined with this macro as being exported.
 */

#if defined(VRDLL_EXPORTS)
  #define VRDLL_API __declspec(dllexport)
#elif defined(VRDLL_IMPORTS)
  #define VRDLL_API __declspec(dllimport)
#else
  #define VRDLL_API
#endif


#ifndef HIRES
  #define MAXMAT  48
  #define MAXIMAGEWIDTH 800
  #define MAXIMAGEHEIGHT 600	/* Made standard image 800x600, to cover FrameGrabbers  20040613 MC*/

#else
  #define MAXMAT 256      /* 182*182 > 2^15 - fix by using ushort */

  #ifndef MAXRES
    #define MAXIMAGEWIDTH 1600
    #define MAXIMAGEHEIGHT 1200	/* Made HIRES image 1600x1200  20040613 MC*/
  #else
    #define MAXIMAGEWIDTH 3200
    #define MAXIMAGEHEIGHT 2400	/* Made MAXRES image 3200x2400  20040613 MC*/
  #endif
#endif

#define MAXCELLS  ((MAXMAT-2)*(MAXMAT-2))
#define BIGBUFFSIZE (((MAXCELLS / 8) + ((MAXCELLS % 8)!=0) + 2) * 2)

#define SYM_VC 4    /* SymbolType == 0 or 4:  read VeriCode Symbols */
#define SYM_QR 2    /* not active */
#define SYM_DM 1                    /* SymbolType == 1: read DM Symbols */
#define SYM_AUTO (SYM_VC|SYM_DM)    /* SymbolType == 5: Auto(VC or DM) */

 /*      -1 == CRC failure */
 /*      -2 == R-S failure */
#define SHAPE_CHECK_ERR   -3 /* == Shape Check failure */
#define NO_OBJECT_ERR     -4 /* == Nothing found failure */
#define UNKNOWN_ERR       -5 /* == Unknown failure */
#define BAD_FIXED_MATSIZE -7 /* == Bad Fixed Matrix Size */
#define SECURITY_ERR      -9 /* == Security failure */

/**********************************************************
* Global Types for Users
***********************************************************/

#ifndef PIXEL_T
  #define PIXEL_T
  typedef unsigned char PIXEL;
#endif

#ifdef DVT			/* MC  - needed for DVT     */
  #if !defined(VERICODE_MT) && !defined(SIEMENS)
    #define VERICODE_MT
  #endif 					/* #if !defined(VERICODE_MT) */
  typedef char TCHAR; 	/* trp - not in Pulnex code */
#endif					/* #ifdef DVT */


#ifndef VRDLL_TYPES
#define VRDLL_TYPES
typedef struct
{
	short IsMatrixFixed;    /* FALSE: Try each valid from list; TRUE: Use FixedMatrixSize */
	short FixedMatrixSize;  /* # to use for IsMatrixFixed == TRUE */
							/* Valid sizes are even numbers from 10 to 48, and sizes */
							/*  13(=26x8), 17(=34x10), and 21(=42x12) - Rectangular VeriCode */
                            /*           and; 9(=18x8), 11(=32x8), 13(=26x12), 15(=36x12),   */
                            /*            17(=36x16), 19(=48x16) - Rectangular DataMatrix    */

	short MarkingStyle;     /*  (not used) */
	short IndexContrast;    /* sets vcObject_thres = (## * 1024 * 5 / 100) or (0 == Auto) */
	short IsContrastNormal; /* 1 == Black on White, 0 == Inverse, (2 == Edge, 3 == Auto) */
	short EdacLevel;        /* 0 == Auto, 1 == 12.5%, 2 == 25%, (?? == None)  */
	short NumSymbols;       /* 1 == Return first symbol found; n == concatnate upto "n" symbols */
	short IsSizeFixed;      /*  (not used) */
	short Compression;      /* 0 == None (8-bit), -1 == Numeric (4-bit), -2 == UC Alpha (6-bit) */
	double FixedSize;       /*  (not used) */
} SYM;

typedef struct
{
	short SymbolType;       /* 0 or 4 == Vericode, 1 == DataMatrix, 5 == Auto */
	short EdgeMethod;       /*  (not used) */
	short SampleMethod;     /*  (not used) */
	short BitsPerCell;      /* == 2, 4, 8, 16 (used in locate::MapHorizontal,Vert & DispObjectMap) */
	short SampleWidth;      /*  (used extensivly by locate) */
	short AorLeft;
	short AorRight;
	short AorTop;
	short AorBottom;
	short Noise;            /*  (not used) */
	short Prefiltering;
	short FilterSize;
	short FilterIterations;
	short UsePacket;
	short TriggerCharacter;
	short Terminate1;
	short Terminate2;
	TCHAR  NoReadString[80];
	short Port;
	long  BaudRate;
	char  Parity;
	short DataBits;
	short StopBits;
	short NumRetry;
} OPTIONS;

typedef struct
{
	short DispExtractPoints;    /* used at extract if IsMatrixFixed is TRUE */
	short DispObjectMap;        /* draws g_vcMap on image */
	short DispBorder;           /* draws lines between g_vcVC_corners_sav */
#ifdef PULNIX_LIBRARY
	short DispSymbol;           /* displays raw data & vecoded cells */
#else
	short DispVericode;         /* displays raw data & vecoded cells */
#endif

    short DispStatistics;
	short DispAor;              /* draws rectangle that shows the AOR */
	short DispPlotting;         /*  (not usaed) */
	short Bell;
	short Control;              /*  (not usaed) */
	short FileMode;
	short StopOnNoRead;
	short WriteOnNoRead;
	short DispRates;
} DIAG;

#ifndef _SH3
typedef struct
{
    short MaxImageWidth;
    short MaxImageHeight;
    short MaxMat;
	short Turns;				/* count of rotations for tryall... */
    double vcQualityFactor;
    long vcCorners[4][2];
	short Mirror;
	short MatrixSize;
	short numXcells;
	short numYcells;
    short Contrast;
    short EDAC;
    short vcMessageLength;
    short vcMaxCorrected;
    int hits;
    short LastSymbolRead;     /* Last successful symbol-type decoded (VC or DM) */
    short TrySymbol;          /* Symbol-type to try (for AUTO VC or DM)  */
#ifdef _DEBUG
    short total_steps;
    short strong[4];
    short strongr[4];
    short strongtheta[4];
    short cstrong[4];
    short cstrongr[4];
    short cstrongtheta[4];
	short sample_step;
    short angle_step;
    short sf;
    short AMax;
    short rmax;
    short RMax;
    short center_x;
    short center_y;
    unsigned char strong_rt_map[4][15][15];
#endif

} RESULT;
#endif      /* _SH3  */

#ifndef VERI_MARK_T
  #define VERI_MARK_T
  typedef struct
  {
	 short codetype;
	 short numXcells;
	 short numYcells;
	 PIXEL cellmap[MAXMAT][MAXMAT];
  } VERI_MARK;
#endif

#endif   /* #define VRDLL_TYPES */

#if defined(VERICODE_MT)

  typedef struct _VCGLOBALS VCGLOBALS;

  #define VCGLOBAL_ARG_DEF		, VCGLOBALS * pGlobals
  #define VCGLOBAL_ARG			, pGlobals
  #define VCGLOBAL_ARG_DEF0		VCGLOBALS * pGlobals
  #define VCGLOBAL_ARG0			pGlobals

#else	/* defined(VERICODE_MT) */

  #define VCGLOBAL_ARG_DEF
  #define VCGLOBAL_ARG
  #define VCGLOBAL_ARG_DEF0		void
  #define VCGLOBAL_ARG0

#endif	/* defined(VERICODE_MT) */


/**********************************************************
* API
***********************************************************/

#ifdef __cplusplus
  extern "C" {
#endif

#if !defined(VERICODE_MT)
  extern VRDLL_API SYM g_vcSym;
  extern VRDLL_API OPTIONS g_vcOpt;
  extern VRDLL_API OPTIONS g_vctmpOpt;
  extern VRDLL_API DIAG g_vcDiag;
  #ifndef _SH3
    extern VRDLL_API RESULT g_vcRes;
  #endif      /* _SH3  */
#endif	/* !defined(VERICODE_MT) */


/**************************************************************************
**
** vcRead is the entry point to read a Vericode from an image.  This
** is what the image acquisition program calls.
**
** Input:   short xSize       x-dimension of the image
**          short ySize       y-dimension of the image
**          PIXEL *img        Pointer to the 8-bit gray scale image
**
** Output:  char *msg         Pointer to the buffer containing the
**                             decoded message.
**
** Returns: Number of symbols decoded (default =1) or error:
**      -1 == CRC failure
**      -2 == R-S failure
**      -3 == Shape Check failure
**      -4 == Nothing found failure
**      -5 == Unknown failure
**      -7 == Bad Fixed Matrix Size
**      -9 == Security failure
**/
#if !defined(VERICODE_MT)
extern RESULT vcRes;

VRDLL_API short vcRead(short xSize,
                       short ySize, 
                       PIXEL *img,
                       char  *msg);

#else	/* defined(VERICODE_MT) */

VRDLL_API VCGLOBALS * vcAllocateScratchPad();

VRDLL_API void vcFreeScratchPad( VCGLOBALS * pGbl );

VRDLL_API short vcRead(short xSize,
                       short ySize, 
                       PIXEL *img, 
                       char  *msg,
                       SYM * pSym, 
                       OPTIONS * pOpt, 
                       DIAG * pDiag, 
                       RESULT *pRes, 
                       VCGLOBALS * pGbl );

#endif	/* defined(VERICODE_MT) */

#ifndef _SH3
/************************************************************************
**
** GetDllVersion
**
** Input:   nBufSize    length of the buffer provided for the Output string.
**
** Output:  szBuf       a string containing the software Version Number, and the status of the
**                      License Key ("Version x.xx.xxx - NoLicense", "Version x.xx.xxx",
**                      "Version x.xx.xxx - w/Outline", or "*DEMO* x.xx.xxx".)
**
** Returns: TRUE
**
**/

VRDLL_API short GetDllVersion(char* szBuf, 
                              int nBufSize);

VRDLL_API void SetMinMaxSquareLength(int nMin, int nMax, int nDiff VCGLOBAL_ARG_DEF);
#endif      /* _SH3  */

#if defined(DVT)

int VCGetEthernetAddress( unsigned char Addr[6] );
int VCGetKey( char key[100] );
int VCIsKeyValid( void );

#endif	/* defined(DVT) */

#ifndef _SH3

/**************************************************************************
 *
 *  GetDllQualityFactor returns the total number of R-S bits corrected, or
 *
 *      -1 == CRC failure
 *      -2 == R-S failure
 *      -3 == Shape Check failure
 *      -4 == Nothing found failure
 *      -5 == Unknown failure
**      -7 == Bad Fixed Matrix Size
 *      -9 == Security failure
 *
 *  (also present in vcRes.vcQualityFactor).
 */
VRDLL_API void GetDllQualityFactor(double* pdRet VCGLOBAL_ARG_DEF);

/**************************************************************************
 *
 *  GetSymbolCorners returns the x & y position for the four corners
 *      of the decoded symbol (also present in vcRes.vcCorners[4] [2]):
 *
 *               UL == 0      vcX  0
 *               UR == 1      vcY  1
 *               LL == 2
 *               LR == 3
 */
VRDLL_API void GetSymbolCorners(short vcCorners[4][2] VCGLOBAL_ARG_DEF);

#endif      /* _SH3  */


#if !defined(VERICODE_MT)
/**************************************************************************
 *
 *  vcDecode returns the total number of R-S bits corrected, or
 *
 *      -1 == CRC failure
 *      -2 == R-S failure
 *      -3 == Parameter was null
 *      -4 == Nothing found failure
 *      -9 == Security failure
 */
VRDLL_API short vcDecode(VERI_MARK *pVm, 
                         char *msg);

#else	/* defined(VERICODE_MT) */

VRDLL_API short vcDecode(VERI_MARK *pVm, 
                         char *msg,
                         SYM * pSym, 
                         OPTIONS * pOpt, 
                         DIAG * pDiag, 
                         RESULT *vcRes, 
                         VCGLOBALS * pGbl );

#endif	/* defined(VERICODE_MT) */

/*
** DefaultSettings is used to set the settings for the DOS version
*/
/* VRDLL_API void DefaultSettings(void); ** MC **/

#ifdef __cplusplus
}
#endif

#endif
