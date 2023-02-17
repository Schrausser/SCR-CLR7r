
#include "stdafx.h"
#include "math.h"
#include "time.h"
#include "CLR.h"
#include "CLRDlg.h"
#include "D:\_EIGENEDATEIEN_\1_LAUFENDES\1_SYSTEM\3_C_PROGRAMME\__H_C++_\DATACONV.HPP"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

int swhg;

CCLRDlg::CCLRDlg(CWnd* pParent ): CDialog(CCLRDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCLRDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCLRDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_MOUSEMOVE()
	ON_WM_SHOWWINDOW()
	ON_WM_TIMER()
	ON_WM_SIZE()
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

BOOL CCLRDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	sw=1;
	sw_m=1;
	sw0=1;
	sw_mod=1;
	sw_mod2=-1;

	frb1=1;
	
	color=0;
	color1=0;
	color3=0;
	color4=0;
	zlr=0;

	swhg=-1;

	SIGMA = 34.0/45;

	            x_p=qzufall((time(0)-1234567890));
	y_p=qzufall(x_p/1000);

	r_=qzufall(y_p/10000);
	sgn=qzufall(r_/10000);

	SetTimer(0,1,0);
	ShowCursor(0);
	
	return 1; 
}

void CCLRDlg::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CDialog::OnShowWindow(bShow, nStatus);
	
	ShowWindow(SW_SHOWMAXIMIZED);	
}

void CCLRDlg::OnPaint() 
{
	UpdateWindow();

	CPaintDC CRender(this); 

	if(sw0==1)
	{	
		color3=0;
		color4=0;
		zlr2=0;
		zlr3=0;
		n_=0;
		qX.sum=0;
		qX.sum2=0;
		qX.am=0;
		qX.sd=0;

		qY.sum=0;
		qY.sum2=0;
		qY.am=0;
		qY.sd=0;

		qxy=0;
		qR=0;
		
		if(sw_mod==-1) r_=qzufall(sgn*1000); 
		if(sw_mod== 1) r_=0.01;
		    sgn=qzufall(sgn); 
		if (sgn<=0.5)r_*=-1; 

                                      CRect Rect(0,0, dlg.x, dlg.y); 
		     CRender.FillSolidRect(Rect, 0 );
			 

		if(sw_mod2==-1)
		{
			 
							 CPen pen; 
								  pen.CreatePen(PS_SOLID, 1,frb1*35);
			 CRender.SelectObject(pen);
			 CRender.MoveTo(0      , dlg.y/2);
			 CRender.LineTo(dlg.x  , dlg.y/2);
			 CRender.MoveTo(dlg.x/2, 0      );
			 CRender.LineTo(dlg.x/2, dlg.y  );
		}
		sw0=0; 
	}

		     CRender.SetTextColor (color1);
			 CRender.SetBkMode(TRANSPARENT);
			 CRender.SetBkColor(1);//
				    
	                         CFont Font; 
					               Font.CreateStockObject(ANSI_VAR_FONT);
	         CRender.SelectObject(&Font);              

								   x_p=qzufall(x_p);                 
	x_p1=zp_funktion(x_p); 
	
		                                       y_p=qzufall(y_p); 
	y_p1=r_*x_p1+sqrt(1-fabs(r_))*(zp_funktion(y_p)*(1+((3.1415926535897932384626433832795/8)*fabs(r_))));



	if(sw_mod2==-1) 
	{
								CRect Rect3((dlg.x/2.0)+(x_p1*dlg.x/8.0),   dlg.y/2.0+(y_p1*dlg.y/6.0),    
											(dlg.x/2.0)+(x_p1*dlg.x/8.0)+3, dlg.y/2.0+(y_p1*dlg.y/6.0)+3); 
				CRender.FillSolidRect(Rect3,color1);
	}
			
	if(sw_mod2==1)
	{
				CRender.SelectObject(Font);
				CRender.TextOut((dlg.x/2.0-80)+(x_p1*dlg.x/8.0),       dlg.y/2.0+(y_p1*dlg.y/6.0),"SCHRAUSSER - MAT");
	}
         
	n_++;  
			

		    qX.sum+= x_p1;
			qX.sum2+=pow(x_p1,2);
			qX.am= qX.sum/n_;
			qX.sd= sqrt(qX.sum2/n_-pow(qX.am,2));
			
  
		    qY.sum+= y_p1;
			qY.sum2+=pow(y_p1,2);
			qY.am= qY.sum/n_;
			qY.sd= sqrt(qY.sum2/n_-pow(qY.am,2));

		   qxy+=x_p1*y_p1;
	   qR=(qxy/n_-qX.am*qY.am)/(qX.sd*qY.sd); 
	tr=qR*sqrt(n_-2)/sqrt(1-pow(qR,2));      

	if(sw_mod2==-1)if(n_>3000)
	{
				CRender.SetBkMode(OPAQUE);
				CRender.SetBkColor(color);
				
		        posx1=(dlg.x/2.0)+(-3*dlg.x/8.0);
				posx2=(dlg.x/2.0)+( 3*dlg.x/8.0);

				posy1=dlg.y/2.0+((-3*r_)*dlg.y/6.0);
				posy2=dlg.y/2.0+(( 3*r_)*dlg.y/6.0);
													
								CPen pen1; 
									 pen1.CreatePen(PS_SOLID, 0,color3);
				CRender.SelectObject(pen1);
				CRender.MoveTo(posx1,   posy1); 
				CRender.LineTo(posx2,   posy2); 
				
				CRender.SetBkMode(TRANSPARENT);
			    CRender.SetTextColor (color4);
				CRender.TextOut(10, dlg.y-20,"SCHRAUSSER-MAT "); 
				CRender.TextOut(dlg.x-100, dlg.y-20,"(C) SCHRAUSSER"); 
	}

	if(sw_mod2==-1)
	{
			                          CRect Rect2((dlg.x/2)+5, 5, dlg.x, 20); 
			  CRender.FillSolidRect(Rect2, 0 );
			 

				CRender.SetTextColor (color4);
                if(sqrt(pow(tr,2))>=1.96)
				{
	            CRender.SetTextColor (color3);
				
				}
								                                  char strTextOut[100]; 
							                                   itoa(n_,strTextOut,10);  
							                   const char *cstrTextOut=strTextOut;
							        CString CstrTextOut = "n = ";
							                CstrTextOut += cstrTextOut;
							                CstrTextOut += ", r = ";
							                CstrTextOut += ftoc(-qR,3);
							                CstrTextOut += ", z = ";
							                CstrTextOut += ftoc(-tr,3);
	           CRender.TextOut(dlg.x-170, 5,CstrTextOut);
	}

	           CRender.SetTextColor (color4);
			   CRender.SelectObject(&Font);
			   CRender.TextOut(10, 5,"press [SPACE]");;
			 
	if(sw_mod==-1)if(sw_mod2== 1)if(n_>=100000)OnKeyDown(32, 0, 0); 
	if(sw_mod== 1)if(sw_mod2==-1)if(n_>=100000)OnKeyDown(32, 0, 0); 
	if(sw_mod==-1)if(sw_mod2==-1)if(n_>=100000){swhg=!swhg;sw_mod2=1;sw0=1;sw_mod=1;OnTimer(0);}
	if(sw_mod== 1)if(sw_mod2== 1)if(n_>=100000){swhg=!swhg;sw_mod2=-1;sw0=1;sw_mod=1;OnTimer(0);}
}

void CCLRDlg::OnTimer(UINT nIDEvent) 
{
	if(sw==1){color+=frb1; zlr++;}
	if(sw==0){color-=frb1; zlr--;}
	
	if(zlr<=0)   sw=1; 
	if(zlr>=150) sw=0; 
	
	color1=color;

	if(n_>=3000)if(zlr2<=250)color3+=frb1;
		           zlr2++;


	

		if(n_>=3000)if(zlr3<=145)color4+=frb1;
					   zlr3++;
					   


	

	RedrawWindow();
	
	CDialog::OnTimer(nIDEvent);
}

HCURSOR CCLRDlg::OnQueryDragIcon(){return (HCURSOR) m_hIcon;}

void CCLRDlg::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);

	dlg.x= cx;         
	dlg.y= cy;
	
	RedrawWindow();	
}

void CCLRDlg::OnMouseMove(UINT nFlags, CPoint point) 
{
	if(sw_m==1)
	{
		pt1.x=point.x;
		pt1.y=point.y;
		sw_m=0;
	}

	if(pt1.x!=point.x || pt1.y!=point.y) CDialog::OnCancel(); 
	
	CDialog::OnMouseMove(nFlags, point);
}

void CCLRDlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	if(nChar==32){swhg=!swhg;sw0=1;sw_mod*=-1;sw_mod2=-1;RedrawWindow();} 
	else CDialog::OnCancel();
	
	CDialog::OnKeyDown(nChar, nRepCnt, nFlags);
}
void CCLRDlg::OnLButtonDown(UINT nFlags, CPoint point)         {CDialog::OnCancel();CDialog::OnLButtonDown(nFlags, point);}
void CCLRDlg::OnRButtonDown(UINT nFlags, CPoint point)         {CDialog::OnCancel();CDialog::OnRButtonDown(nFlags, point);}

double CCLRDlg::qzufall(double seed)
{
	fn_erg =		   10*( pow(seed,SIGMA) - floor( pow(seed,SIGMA) ) ) 
		      - floor( 10*( pow(seed,SIGMA) - floor( pow(seed,SIGMA) ) ) );
	
	return fn_erg;
};

double CCLRDlg::zp_funktion(double wert) 
{
	long double  p_wert, z_wert, OO[10], RD[10];
	z_wert=RD[0]=RD[2]=RD[3]=RD[4]=0; OO[1]=OO[2]=RD[1]=RD[5]=1;
	
	
	if (wert>=1 || wert<0 ) {printf("\n\nvalue.0 '0<=p<=1'");exit(0);}
   		
		
	p_wert = wert;
	
	if(p_wert!=0.5)
	{
		if(p_wert>0.5) {OO[1]=1-p_wert;} else {OO[1]=p_wert;}
		OO[1]=-1*log(4*OO[1]*(1-OO[1]));
		OO[2]=(-3.231081277e-09*OO[1]+8.360937017e-08)*OO[1]-1.04527497e-06;
		OO[2]=(OO[2]*OO[1]+5.824238515e-06)*OO[1]+6.841218299e-06;
		OO[2]=((OO[2]*OO[1]-2.250947176e-04)*OO[1]-8.36435359e-04)*OO[1]+3.706987906e-02;
		z_wert=OO[2]*OO[1]+1.570796288;
		z_wert=sqrt(OO[1]*z_wert);
		if(p_wert<0.5) z_wert = z_wert * -1;
	}
	
	if(RD[0]==0)
	{
		RD[1]=z_wert; RD[2]=-5;

		
		
		if(RD[1] !=0 )
		{	
			RD[3] = log10(fabs(RD[1]));
			RD[2]=RD[3]+RD[2]; 
			if (RD[3] >= 0) RD[3]= floor(RD[3]);		
			if (RD[3] < 0)  RD[3]= -1*(floor(fabs(RD[3])));
			RD[4]=RD[3]; RD[3]=RD[2]; 
			if (RD[3] >= 0) RD[3]= floor(RD[3]);	
			if (RD[3] < 0)  RD[3]= -1*(floor(fabs(RD[3])));	
			RD[2]=RD[4]-RD[3]-1;
			if (RD[2] < 19 ) 
			{
				if (RD[2] < 0 ) RD[1]=0; 
				if (RD[2] >=0 )
				{
					if (RD[4] >= 90){ RD[1] = RD[1] * 1e-20; RD[3]=RD[4]; RD[4] -= 20;}
					RD[5] = sqrt(pow(RD[1]*pow(10,(-1*RD[4])),2)); RD[5]=floor(RD[5]*pow(10,RD[2])+0.5);
					RD[5] *= pow(10,RD[4])*pow(10,(-1*RD[2]));
					if (RD[3] >= 90) RD[5] = RD[5] * 1e+20;
					if (RD[1] >= 0) RD[1] = RD[5]; 
					if (RD[1] < 0) RD[1] = -1*RD[5];
				}
			}
		}
		z_wert=RD[1]; 
	}
	
	return z_wert;
};

