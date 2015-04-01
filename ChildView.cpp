
// ChildView.cpp : implementation of the CChildView class
//

#include "stdafx.h"
#include "dung.h"
#include "ChildView.h"

#include "Kaching.h"

#include "DungGen1.h"
#include <sstream>


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

  /*
  Laby laby(101); // 51); // 101);
  laby.combine(); //  buildAll(); // dc);
  laby.draw(dc);
  */

  // shrooms(dc);
  // return;

  
  if (1) { // false) { //true) { // false) {
    Blob blob(0);
    blob.run(&dc);
  }
  


  return; 
	
}



void CChildView::shrooms(CPaintDC& dc) {
  CBrush brush(RGB(240, 240, 240)); // RGB(rnd(255), rnd(255), rnd(255)));

  CPoint p(250, 250);

  for (int i = 0; i < 250; ++i) {

    int dirB = rnd(2) ? 1 : -1;
    int dir1 = dirB * rnd(7, 20); // (2, 7);
    int xy = rnd(2);
    CPoint dir(xy ? dir1 : 0, !xy ? dir1 : 0);

    CPoint next = p + dir;
    dc.MoveTo(p);
    dc.LineTo(next);

    CSize dims(rnd(2, 10), rnd(2, 10));
    CPoint center(dims.cx / 2, dims.cy / 2);
    CRect r(CPoint(next.x - center.x, next.y - center.y), dims); // CPoint(rnd(500), rnd(500)), , rnd(2, 10))); // , 2, 3, 4);
    dc.FillRect(&r, &brush);
    p = next;
  }
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
