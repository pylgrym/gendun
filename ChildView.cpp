
// ChildView.cpp : implementation of the CChildView class
//

#include "stdafx.h"
#include "dung.h"
#include "ChildView.h"

#include "Kaching.h"

#include "DungGen1.h"
#include <sstream>
#include "BungBrownian.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
  ON_WM_CHAR()
END_MESSAGE_MAP()



// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;

  static CBrush back(RGB(110, 120, 130));

	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), 
    back, //reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), 
    NULL);

	return TRUE;
}












void CChildView::OnPaint() {
	CPaintDC dc(this); // device context for painting


  shrooms(dc);
  return;

  /*
  Laby laby(101); // 51); // 101);
  laby.combine(); //  buildAll(); // dc);
  laby.draw(dc);
  */

  if (0) { 
    Blob blob(0);
    blob.run(&dc);
  }	
}








void CChildView::shrooms(CPaintDC& dc) {
  Brown brown(46,37, &dc); 
  brown.run(dc);
}


void CChildView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) {
  CWnd::OnChar(nChar, nRepCnt, nFlags);

  static int myseed = 42;
  switch (nChar) {
  case '+': case 'x': ++myseed; break;
  case '-': case 'z': --myseed; break;
  }

  srand(myseed);
  std::stringstream ss; ss << myseed;
  std::string s = ss.str();

  CA2T us(s.c_str());
  GetParent()->SetWindowText(us); // s.c_str());

  InvalidateRect(NULL, true); // purpose - to redraw. / new seed.
}
