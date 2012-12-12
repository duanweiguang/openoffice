/*************************************************************************
 *
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 * 
 * Copyright IBM Corporation 2010.
 * Copyright 2000, 2010 Oracle and/or its affiliates.
 *
 * OpenOffice.org - a multi-platform office productivity suite
 *
 * This file is part of OpenOffice.org.
 *
 * OpenOffice.org is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License version 3
 * only, as published by the Free Software Foundation.
 *
 * OpenOffice.org is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License version 3 for more details
 * (a copy is included in the LICENSE file that accompanied this code).
 *
 * You should have received a copy of the GNU Lesser General Public License
 * version 3 along with OpenOffice.org.  If not, see
 * <http://www.openoffice.org/license.html>
 * for a copy of the LGPLv3 License.
 *
 ************************************************************************/

// stdafx.h : include file for standard system include files,
//      or project specific include files that are used frequently,
//      but are changed infrequently

#if !defined(AFX_STDAFX_H__5E2F9072_190F_47C7_8003_4D44FD308CB9__INCLUDED_)
#define AFX_STDAFX_H__5E2F9072_190F_47C7_8003_4D44FD308CB9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define STRICT
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0400
#endif
//#define _ATL_APARTMENT_THREADED

#include <atlbase.h>
// You may derive a class from CComModule and use it if you want to override
// something, but do not change the name of _Module
extern CComModule _Module;
#include <atlcom.h>

#define ENTER_PROTECTED_BLOCK	\
	try							\
	{

#define LEAVE_PROTECTED_BLOCK	\
	}							\
	catch(...)					\
	{							\
		return E_FAIL;			\
	}

#define SAFE_SYSFREESTRING(x) { ::SysFreeString(x); x=NULL; }

#include <windows.h>
#undef OPAQUE 
#include "CheckEnableAccessible.h"
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__5E2F9072_190F_47C7_8003_4D44FD308CB9__INCLUDED)