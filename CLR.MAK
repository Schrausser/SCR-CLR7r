# Microsoft Developer Studio Generated NMAKE File, Based on CLR.DSP
!IF "$(CFG)" == ""
CFG=CLR - Win32 Debug
!MESSAGE No configuration specified. Defaulting to CLR - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "CLR - Win32 Release" && "$(CFG)" != "CLR - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "CLR.MAK" CFG="CLR - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "CLR - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "CLR - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "CLR - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\CLR.scr" "$(OUTDIR)\CLR.bsc"

!ELSE 

ALL : "$(OUTDIR)\CLR.scr" "$(OUTDIR)\CLR.bsc"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\CLR.obj"
	-@erase "$(INTDIR)\CLR.pch"
	-@erase "$(INTDIR)\CLR.res"
	-@erase "$(INTDIR)\CLR.sbr"
	-@erase "$(INTDIR)\CLRDlg.obj"
	-@erase "$(INTDIR)\CLRDlg.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\CLR.bsc"
	-@erase "$(OUTDIR)\CLR.scr"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS"\
 /FR"$(INTDIR)\\" /Fp"$(INTDIR)\CLR.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Release/
CPP_SBRS=.\Release/
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /o NUL /win32 
RSC_PROJ=/l 0x407 /fo"$(INTDIR)\CLR.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\CLR.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\CLR.sbr" \
	"$(INTDIR)\CLRDlg.sbr" \
	"$(INTDIR)\StdAfx.sbr"

"$(OUTDIR)\CLR.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)\CLR.pdb" /machine:I386 /out:"$(OUTDIR)\CLR.scr" 
LINK32_OBJS= \
	"$(INTDIR)\CLR.obj" \
	"$(INTDIR)\CLR.res" \
	"$(INTDIR)\CLRDlg.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\CLR.scr" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "CLR - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\CLR.scr"

!ELSE 

ALL : "$(OUTDIR)\CLR.scr"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\CLR.obj"
	-@erase "$(INTDIR)\CLR.pch"
	-@erase "$(INTDIR)\CLR.res"
	-@erase "$(INTDIR)\CLRDlg.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\CLR.ilk"
	-@erase "$(OUTDIR)\CLR.pdb"
	-@erase "$(OUTDIR)\CLR.scr"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /Fp"$(INTDIR)\CLR.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /o NUL /win32 
RSC_PROJ=/l 0x407 /fo"$(INTDIR)\CLR.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\CLR.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)\CLR.pdb" /debug /machine:I386 /out:"$(OUTDIR)\CLR.scr"\
 /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\CLR.obj" \
	"$(INTDIR)\CLR.res" \
	"$(INTDIR)\CLRDlg.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\CLR.scr" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<


!IF "$(CFG)" == "CLR - Win32 Release" || "$(CFG)" == "CLR - Win32 Debug"
SOURCE=.\CLR.cpp

!IF  "$(CFG)" == "CLR - Win32 Release"

DEP_CPP_CLR_C=\
	".\CLR.h"\
	".\CLRDlg.h"\
	

"$(INTDIR)\CLR.obj"	"$(INTDIR)\CLR.sbr" : $(SOURCE) $(DEP_CPP_CLR_C)\
 "$(INTDIR)" "$(INTDIR)\CLR.pch"


!ELSEIF  "$(CFG)" == "CLR - Win32 Debug"

DEP_CPP_CLR_C=\
	".\CLR.h"\
	".\CLRDlg.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\CLR.obj" : $(SOURCE) $(DEP_CPP_CLR_C) "$(INTDIR)"\
 "$(INTDIR)\CLR.pch"


!ENDIF 

SOURCE=.\CLR.rc
DEP_RSC_CLR_R=\
	".\res\CLR.ico"\
	".\res\CLR.rc2"\
	

"$(INTDIR)\CLR.res" : $(SOURCE) $(DEP_RSC_CLR_R) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\CLRDlg.cpp

!IF  "$(CFG)" == "CLR - Win32 Release"

DEP_CPP_CLRDL=\
	"..\__h_c++_\dataconv.hpp"\
	".\CLR.h"\
	".\CLRDlg.h"\
	

"$(INTDIR)\CLRDlg.obj"	"$(INTDIR)\CLRDlg.sbr" : $(SOURCE) $(DEP_CPP_CLRDL)\
 "$(INTDIR)" "$(INTDIR)\CLR.pch"


!ELSEIF  "$(CFG)" == "CLR - Win32 Debug"

DEP_CPP_CLRDL=\
	"..\__h_c++_\dataconv.hpp"\
	".\CLR.h"\
	".\CLRDlg.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\CLRDlg.obj" : $(SOURCE) $(DEP_CPP_CLRDL) "$(INTDIR)"\
 "$(INTDIR)\CLR.pch"


!ENDIF 

SOURCE=.\StdAfx.cpp
DEP_CPP_STDAF=\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "CLR - Win32 Release"

CPP_SWITCHES=/nologo /MT /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS"\
 /FR"$(INTDIR)\\" /Fp"$(INTDIR)\CLR.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\CLR.pch" : $(SOURCE)\
 $(DEP_CPP_STDAF) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "CLR - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D\
 "_WINDOWS" /D "_AFXDLL" /Fp"$(INTDIR)\CLR.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\CLR.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

