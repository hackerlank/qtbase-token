begin_unit
begin_comment
comment|/* -------------------------------- pktdef.h -------------------------------- */
end_comment
begin_comment
comment|/* Combined 16& 32-bit version. */
end_comment
begin_comment
comment|/*------------------------------------------------------------------------------ The text and information contained in this file may be freely used, copied, or distributed without compensation or licensing restrictions.  This file is copyright 1991-1998 by LCS/Telegraphics. ------------------------------------------------------------------------------*/
end_comment
begin_comment
comment|/*------------------------------------------------------------------------------  How to use pktdef.h:  1. Include wintab.h 2. if using just one packet format: 	a. Define PACKETDATA and PACKETMODE as or'ed combinations of WTPKT bits 	   (use the PK_* identifiers). 	b. Include pktdef.h. 	c. The generated structure typedef will be called PACKET.  Use PACKETDATA 	   and PACKETMODE to fill in the LOGCONTEXT structure. 3. If using multiple packet formats, for each one: 	a. Define PACKETNAME. Its text value will be a prefix for this packet's 	   parameters and names. 	b. Define<PACKETNAME>PACKETDATA and<PACKETNAME>PACKETMODE similar to 	   2.a. above. 	c. Include pktdef.h. 	d. The generated structure typedef will be called<PACKETNAME>PACKET. Compare with 2.c. above and example #2 below. 4. If using extension packet data, do the following additional steps    for each extension: 	a. Before including pktdef.h, define<PACKETNAME>PACKET<EXTENSION> 	   as either PKEXT_ABSOLUTE or PKEXT_RELATIVE. 	b. The generated structure typedef will contain a field for the 	   extension data. 	c. Scan the WTI_EXTENSION categories to find the extension's 	   packet mask bit. 	d. OR the packet mask bit with<PACKETNAME>PACKETDATA and use the 	   result in the lcPktData field of the LOGCONTEXT structure. 	e. If<PACKETNAME>PACKET<EXTENSION> was PKEXT_RELATIVE, OR the 	   packet mask bit with<PACKETNAME>PACKETMODE and use the result 	   in the lcPktMode field of the LOGCONTEXT structure.   Example #1.	-- single packet format  #include<wintab.h> #define PACKETDATA	PK_X | PK_Y | PK_BUTTONS	/@ x, y, buttons @/ #define PACKETMODE	PK_BUTTONS					/@ buttons relative mode @/ #include<pktdef.h> ... 	lc.lcPktData = PACKETDATA; 	lc.lcPktMode = PACKETMODE;  Example #2. -- multiple formats  #include<wintab.h> #define PACKETNAME		MOE #define MOEPACKETDATA	PK_X | PK_Y | PK_BUTTONS	/@ x, y, buttons @/ #define MOEPACKETMODE	PK_BUTTONS					/@ buttons relative mode @/ #include<pktdef.h> #define PACKETNAME		LARRY #define LARRYPACKETDATA	PK_Y | PK_Z | PK_BUTTONS	/@ y, z, buttons @/ #define LARRYPACKETMODE	PK_BUTTONS					/@ buttons relative mode @/ #include<pktdef.h> #define PACKETNAME		CURLY #define CURLYPACKETDATA	PK_X | PK_Z | PK_BUTTONS	/@ x, z, buttons @/ #define CURLYPACKETMODE	PK_BUTTONS					/@ buttons relative mode @/ #include<pktdef.h> ... 	lcMOE.lcPktData = MOEPACKETDATA; 	lcMOE.lcPktMode = MOEPACKETMODE; ... 	lcLARRY.lcPktData = LARRYPACKETDATA; 	lcLARRY.lcPktMode = LARRYPACKETMODE; ... 	lcCURLY.lcPktData = CURLYPACKETDATA; 	lcCURLY.lcPktMode = CURLYPACKETMODE;  Example #3. -- extension packet data "XFOO". 	 #include<wintab.h> #define PACKETDATA	PK_X | PK_Y | PK_BUTTONS	/@ x, y, buttons @/ #define PACKETMODE	PK_BUTTONS					/@ buttons relative mode @/ #define PACKETXFOO	PKEXT_ABSOLUTE				/@ XFOO absolute mode @/ #include<pktdef.h> ... UINT ScanExts(UINT wTag) { 	UINT i; 	UINT wScanTag;  	/@ scan for wTag's info category. @/ 	for (i = 0; WTInfo(WTI_EXTENSIONS + i, EXT_TAG,&wScanTag); i++) { 		 if (wTag == wScanTag) { 			/@ return category offset from WTI_EXTENSIONS. @/ 			return i; 		} 	} 	/@ return error code. @/ 	return 0xFFFF; } ... 	lc.lcPktData = PACKETDATA; 	lc.lcPktMode = PACKETMODE; #ifdef PACKETXFOO 	categoryXFOO = ScanExts(WTX_XFOO); 	WTInfo(WTI_EXTENSIONS + categoryXFOO, EXT_MASK,&maskXFOO); 	lc.lcPktData |= maskXFOO; #if PACKETXFOO == PKEXT_RELATIVE 	lc.lcPktMode |= maskXFOO; #endif #endif 	WTOpen(hWnd,&lc, TRUE);   ------------------------------------------------------------------------------*/
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef
begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/* __cplusplus */
ifndef|#
directive|ifndef
name|PACKETNAME
comment|/* if no packet name prefix */
DECL|macro|__PFX
define|#
directive|define
name|__PFX
parameter_list|(
name|x
parameter_list|)
value|x
DECL|macro|__IFX
define|#
directive|define
name|__IFX
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|x ## y
else|#
directive|else
comment|/* add prefixes and infixes to packet format names */
DECL|macro|__PFX
define|#
directive|define
name|__PFX
parameter_list|(
name|x
parameter_list|)
value|__PFX2(PACKETNAME,x)
DECL|macro|__PFX2
define|#
directive|define
name|__PFX2
parameter_list|(
name|p
parameter_list|,
name|x
parameter_list|)
value|__PFX3(p,x)
DECL|macro|__PFX3
define|#
directive|define
name|__PFX3
parameter_list|(
name|p
parameter_list|,
name|x
parameter_list|)
value|p ## x
DECL|macro|__IFX
define|#
directive|define
name|__IFX
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|__IFX2(x,PACKETNAME,y)
DECL|macro|__IFX2
define|#
directive|define
name|__IFX2
parameter_list|(
name|x
parameter_list|,
name|i
parameter_list|,
name|y
parameter_list|)
value|__IFX3(x,i,y)
DECL|macro|__IFX3
define|#
directive|define
name|__IFX3
parameter_list|(
name|x
parameter_list|,
name|i
parameter_list|,
name|y
parameter_list|)
value|x ## i ## y
endif|#
directive|endif
DECL|macro|__SFX2
define|#
directive|define
name|__SFX2
parameter_list|(
name|x
parameter_list|,
name|s
parameter_list|)
value|__SFX3(x,s)
DECL|macro|__SFX3
define|#
directive|define
name|__SFX3
parameter_list|(
name|x
parameter_list|,
name|s
parameter_list|)
value|x ## s
DECL|macro|__TAG
define|#
directive|define
name|__TAG
value|__IFX(tag,PACKET)
DECL|macro|__TYPES
define|#
directive|define
name|__TYPES
value|__PFX(PACKET), * __IFX(P,PACKET), NEAR * __IFX(NP,PACKET), \ 					FAR * __IFX(LP,PACKET)
DECL|macro|__DATA
define|#
directive|define
name|__DATA
value|(__PFX(PACKETDATA))
DECL|macro|__MODE
define|#
directive|define
name|__MODE
value|(__PFX(PACKETMODE))
DECL|macro|__EXT
define|#
directive|define
name|__EXT
parameter_list|(
name|x
parameter_list|)
value|__SFX2(__PFX(PACKET),x)
DECL|struct|__TAG
typedef|typedef
struct|struct
name|__TAG
block|{
if|#
directive|if
operator|(
name|__DATA
operator|&
name|PK_CONTEXT
operator|)
DECL|member|pkContext
name|HCTX
name|pkContext
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
operator|(
name|__DATA
operator|&
name|PK_STATUS
operator|)
DECL|member|pkStatus
name|UINT
name|pkStatus
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
operator|(
name|__DATA
operator|&
name|PK_TIME
operator|)
DECL|member|pkTime
name|DWORD
name|pkTime
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
operator|(
name|__DATA
operator|&
name|PK_CHANGED
operator|)
DECL|member|pkChanged
name|WTPKT
name|pkChanged
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
operator|(
name|__DATA
operator|&
name|PK_SERIAL_NUMBER
operator|)
DECL|member|pkSerialNumber
name|UINT
name|pkSerialNumber
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
operator|(
name|__DATA
operator|&
name|PK_CURSOR
operator|)
DECL|member|pkCursor
name|UINT
name|pkCursor
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
operator|(
name|__DATA
operator|&
name|PK_BUTTONS
operator|)
DECL|member|pkButtons
name|DWORD
name|pkButtons
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
operator|(
name|__DATA
operator|&
name|PK_X
operator|)
DECL|member|pkX
name|LONG
name|pkX
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
operator|(
name|__DATA
operator|&
name|PK_Y
operator|)
DECL|member|pkY
name|LONG
name|pkY
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
operator|(
name|__DATA
operator|&
name|PK_Z
operator|)
DECL|member|pkZ
name|LONG
name|pkZ
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
operator|(
name|__DATA
operator|&
name|PK_NORMAL_PRESSURE
operator|)
if|#
directive|if
operator|(
name|__MODE
operator|&
name|PK_NORMAL_PRESSURE
operator|)
comment|/* relative */
DECL|member|pkNormalPressure
name|int
name|pkNormalPressure
decl_stmt|;
else|#
directive|else
comment|/* absolute */
DECL|member|pkNormalPressure
name|UINT
name|pkNormalPressure
decl_stmt|;
endif|#
directive|endif
endif|#
directive|endif
if|#
directive|if
operator|(
name|__DATA
operator|&
name|PK_TANGENT_PRESSURE
operator|)
if|#
directive|if
operator|(
name|__MODE
operator|&
name|PK_TANGENT_PRESSURE
operator|)
comment|/* relative */
DECL|member|pkTangentPressure
name|int
name|pkTangentPressure
decl_stmt|;
else|#
directive|else
comment|/* absolute */
DECL|member|pkTangentPressure
name|UINT
name|pkTangentPressure
decl_stmt|;
endif|#
directive|endif
endif|#
directive|endif
if|#
directive|if
operator|(
name|__DATA
operator|&
name|PK_ORIENTATION
operator|)
DECL|member|pkOrientation
name|ORIENTATION
name|pkOrientation
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
operator|(
name|__DATA
operator|&
name|PK_ROTATION
operator|)
DECL|member|pkRotation
name|ROTATION
name|pkRotation
decl_stmt|;
comment|/* 1.1 */
endif|#
directive|endif
ifndef|#
directive|ifndef
name|NOWTEXTENSIONS
comment|/* extensions begin here. */
if|#
directive|if
operator|(
name|__EXT
argument_list|(
name|FKEYS
argument_list|)
operator|==
name|PKEXT_RELATIVE
operator|)
operator|||
operator|(
name|__EXT
argument_list|(
name|FKEYS
argument_list|)
operator|==
name|PKEXT_ABSOLUTE
operator|)
DECL|member|pkFKeys
name|UINT
name|pkFKeys
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
operator|(
name|__EXT
argument_list|(
name|TILT
argument_list|)
operator|==
name|PKEXT_RELATIVE
operator|)
operator|||
operator|(
name|__EXT
argument_list|(
name|TILT
argument_list|)
operator|==
name|PKEXT_ABSOLUTE
operator|)
DECL|member|pkTilt
name|TILT
name|pkTilt
decl_stmt|;
endif|#
directive|endif
endif|#
directive|endif
block|}
DECL|typedef|__TYPES
name|__TYPES
typedef|;
DECL|macro|PACKETNAME
undef|#
directive|undef
name|PACKETNAME
DECL|macro|__TAG
undef|#
directive|undef
name|__TAG
DECL|macro|__TAG2
undef|#
directive|undef
name|__TAG2
DECL|macro|__TYPES
undef|#
directive|undef
name|__TYPES
DECL|macro|__TYPES2
undef|#
directive|undef
name|__TYPES2
DECL|macro|__DATA
undef|#
directive|undef
name|__DATA
DECL|macro|__MODE
undef|#
directive|undef
name|__MODE
DECL|macro|__PFX
undef|#
directive|undef
name|__PFX
DECL|macro|__PFX2
undef|#
directive|undef
name|__PFX2
DECL|macro|__PFX3
undef|#
directive|undef
name|__PFX3
DECL|macro|__IFX
undef|#
directive|undef
name|__IFX
DECL|macro|__IFX2
undef|#
directive|undef
name|__IFX2
DECL|macro|__IFX3
undef|#
directive|undef
name|__IFX3
DECL|macro|__SFX2
undef|#
directive|undef
name|__SFX2
DECL|macro|__SFX3
undef|#
directive|undef
name|__SFX3
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __cplusplus */
end_comment
end_unit
