#include "StdAfx.h"
#include <vector>
#include <map>

using namespace std;

typedef struct _Blob 
{
	int Left;
	int nEnd;
	int y;
	int nLabel;
} Blob;

typedef std::multimap<int, Blob*>				MapBlob;
typedef std::multimap<int, Blob*>::iterator	MapBlobIt;
typedef std::pair<MapBlobIt, MapBlobIt>	MapPair;

typedef std::vector<Blob*>			VectorBlob;
typedef std::vector<Blob*>::iterator	VectorBlobIt;


BYTE* binarization(BYTE* pSrcImage, int nWidth, int nHeight, int nThreshold)
{
	if (pSrcImage == NULL ||
		nWidth <= 0 ||
		nHeight <= 0)
		return NULL;

	int idx = 0;
	int nLength = nWidth*nHeight;
	BYTE* pDstImage = new BYTE[nLength];
	ZeroMemory(pDstImage, sizeof(BYTE)*nLength);

	for (; idx < nLength ; idx++)
	{
		if (pSrcImage[idx]< nThreshold)
			pDstImage[idx] = 0;
		else
			pDstImage[idx] = 255;
	}

	return pDstImage;
}

void Projection(BYTE* pSrcImage, int nWidth, int nHeight, LONG &left,LONG &top, LONG &right, LONG &bottom)
{
	if (pSrcImage == NULL ||
		nWidth <= 0 ||
		nHeight <= 0)
		return ;

	int idx;
	int *pVert = new int[nWidth];
	int *pHorz = new int[nHeight];

	int nMinSubT2B = 255*nWidth;
	int nMaxSubT2B = -255*nWidth;

	int nMaxSubL2R = -255*nHeight;
	int nMinSubL2R = 255*nHeight;

	int sub;

	ZeroMemory(pVert, sizeof(int)*nWidth);
	ZeroMemory(pHorz, sizeof(int)*nHeight);

	for (int y = 0 ; y < nHeight ; y++)
	{
		for (int x = 0 ; x < nWidth ; x++)
		{
			idx = y*nWidth+x;
			pHorz[y]+=pSrcImage[idx];			
		}
	}	

	for (int i = 0 ; i < nHeight-3 ; i++)
	{
		sub = pHorz[i+3]-pHorz[i];
		if (sub < nMinSubT2B)
		{
			nMinSubT2B = sub;
			top = i + 3;
		}

		if (sub > nMaxSubT2B)
		{
			nMaxSubT2B = sub;
			bottom = i + 3;
		}
	}	

	if (top > bottom)
	{
		int Temp = top;
		top = bottom;
		bottom = Temp;
	}	

	if (top < 0 )
		top = 0;

	if (bottom >= nHeight)
		bottom = nHeight-1;

	for (int y = top ; y < bottom ; y++)
	{
		for (int x = 0 ; x < nWidth ; x++)
		{
			idx = y*nWidth+x;
			pVert[x]+=pSrcImage[idx];
		}
	}

	for (int i = 0 ; i < nWidth-3 ; i++)
	{		
		sub = pVert[i+3]-pVert[i];
		if (sub > nMaxSubL2R)
		{
			nMaxSubL2R = sub;
			left = i+3;
		}
		if (sub < nMinSubL2R)
		{
			nMinSubL2R = sub;
			right = i;
		}
	}

	if (left > right)
	{
		int Temp = left;
		left = right;
		right = Temp;
	}

	if (left < 0)
		left = 0;

	if (right >= nWidth)
		right = nWidth-1;

	if (pVert != NULL)
	{
		delete[] pVert;
		pVert = NULL;
	}
	if (pHorz != NULL)
	{
		delete[] pHorz;
		pHorz = NULL;
	}
	return ;
}

int* Blobbing(BYTE* pSrcImage, int nWidth, int nHeight, int nPixelVal,int nMinSize, int nMaxSize)
{
	if (pSrcImage == NULL ||
		nWidth <= 0 ||
		nHeight <= 0)
		return NULL;
	
	int nLength = nHeight*nWidth;
	int nIdx;
	int nBlobCount = 0;
	int nMergedCount = 0;
	int nSrcNum;
	int nDstNum;

	int* pLookUpTable = NULL;
	int* pLookUpCount = NULL;
	int* pTempImage = new int[nLength];
	ZeroMemory(pTempImage, nLength*sizeof(int));

	for (int y = 0 ; y < nHeight ; y++)
	{
		for (int x = 0 ; x < nWidth ; x++)
		{
			nIdx = y*nWidth+x;
			if (pSrcImage[nIdx] == nPixelVal)
			{
				if (y - 1 >= 0 && pTempImage[nIdx - nWidth] != 0 )
				{
					pTempImage[nIdx] = pTempImage[nIdx - nWidth];
				}else if (y - 1 >= 0 && x - 1 >= 0 && pTempImage[nIdx - nWidth - 1] != 0)
				{
					pTempImage[nIdx] = pTempImage[nIdx - nWidth - 1];
				}else if (x - 1 >= 0 && pTempImage[nIdx - 1] != 0)
				{
					pTempImage[nIdx] = pTempImage[nIdx - 1];
				}else
				{
					nBlobCount++;
					pTempImage[nIdx] = nBlobCount;
				}
			}
		}
	}

	pLookUpTable = new int[nBlobCount+1];
	pLookUpCount = new int[nBlobCount+1];

	for (int i = 1 ; i < nBlobCount+1 ; i++)
		pLookUpTable[i] = i;
	ZeroMemory(pLookUpCount, sizeof(int)*nBlobCount+1);
	
	do 
	{
		nMergedCount = 0;

		for (int y = 0 ; y < nHeight ; y++)
		{
			for (int x = 0 ; x < nWidth ; x++)
			{
				nIdx = y*nWidth+x;
				if (pTempImage[nIdx] != 0)
				{
					if (y - 1 >= 0 && pTempImage[nIdx - nWidth] > 0)
					{
						nSrcNum = pTempImage[nIdx];
						while (nSrcNum != pLookUpTable[nSrcNum])
							nSrcNum = pLookUpTable[nSrcNum];


						nDstNum = pTempImage[nIdx - nWidth];
						while (nDstNum != pLookUpTable[nDstNum])
							nDstNum = pLookUpTable[nDstNum];

						if (nSrcNum == nDstNum)
							continue;
					
						if (nSrcNum < nDstNum)
							pLookUpTable[nDstNum] = nSrcNum;
						else
							pLookUpTable[nSrcNum] = nDstNum;

						nMergedCount++;
					}else if (x - 1 >= 0 && pTempImage[nIdx - 1] > 0)
					{
						nSrcNum = pTempImage[nIdx];
						while (nSrcNum != pLookUpTable[nSrcNum])
							nSrcNum = pLookUpTable[nSrcNum];

						nDstNum = pTempImage[nIdx - 1];
						while (nDstNum != pLookUpTable[nDstNum])
							nDstNum = pLookUpTable[nDstNum];

						if (nSrcNum == nDstNum)
							continue;

						if (nSrcNum < nDstNum)
							pLookUpTable[nDstNum] = nSrcNum;
						else
							pLookUpTable[nSrcNum] = nDstNum;
						nMergedCount++;
					}else if (y - 1 >= 0 && x - 1 >= 0 && pTempImage[nIdx - nWidth - 1] > 0)
					{
						nSrcNum = pTempImage[nIdx];
						while (nSrcNum != pLookUpTable[nSrcNum])
							nSrcNum = pLookUpTable[nSrcNum];


						nDstNum = pTempImage[nIdx - nWidth - 1];
						while (nDstNum != pLookUpTable[nDstNum])
							nDstNum = pLookUpTable[nDstNum];

						if (nSrcNum == nDstNum)
							continue;

						if (nSrcNum < nDstNum)
							pLookUpTable[nDstNum] = nSrcNum;
						else
							pLookUpTable[nSrcNum] = nDstNum;
						nMergedCount++;
					}
				}
			}
		}
	} while (nMergedCount);

	for (int y = 0 ; y < nHeight ; y++)
	{
		for (int x = 0 ; x < nWidth ; x++)
		{
			nIdx = y*nWidth+x;
			if (pTempImage[nIdx] > 0)
			{
				nSrcNum = pTempImage[nIdx];
				while (nSrcNum != pLookUpTable[nSrcNum])
					nSrcNum = pLookUpTable[nSrcNum];
				pTempImage[nIdx] = nSrcNum;
				pLookUpCount[nSrcNum]++;
			}
		}
	}

	int *nArrBlobInx = new int[nBlobCount+1];

	int nCount = 0;
	for (int i = 1 ; i <= nBlobCount+1 ; i++)
	{
		if (pLookUpCount[i] > 0)
		{
			nArrBlobInx[nCount] = i;
			nCount++;
		}

	}



	delete[] pLookUpTable;
	return pTempImage;
}