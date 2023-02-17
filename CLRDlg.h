#if !defined(AFX_CLRDLG_H__51113773_72DD_4211_A14E_C35C65E2F83B__INCLUDED_)
#define AFX_CLRDLG_H__51113773_72DD_4211_A14E_C35C65E2F83B__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif 

class CCLRDlg : public CDialog
{
	public:
	double CCLRDlg::qzufall(double seed);
	
	CCLRDlg(CWnd* pParent = NULL);

	
	double CCLRDlg::zp_funktion(double wert);
	double fn_erg;
	double x_p;
	double y_p;
	double x_p1;
	double y_p1;
	double r_;
	double sgn;
	double SIGMA;
	double posx1, posx2, posy1, posy2;
	UINT n_;
	typedef struct tagTHETA{double sum; 
	                        double sum2; 
							double sd; 
							double am;}THETA;	      						     					 
	                                   THETA qX;
					                   THETA qY;
	double qxy, qR, tr;
	POINT pt1;
	POINT dlg;
	UINT  sw,  sw0, sw_m, sw_mod, sw_mod2, zlr, zlr2, zlr3 ;
	UINT color, color1, color3, color31, color4;
	BOOL frb1;

	enum { IDD = IDD_CLR_DIALOG };
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	

	protected:
	HICON m_hIcon;

	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#endif
