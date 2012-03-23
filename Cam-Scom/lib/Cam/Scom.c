/*
 * This file was generated automatically by ExtUtils::ParseXS version 2.2203 from the
 * contents of Scom.xs. Do not edit this file, edit Scom.xs instead.
 *
 *	ANY CHANGES MADE HERE WILL BE LOST! 
 *
 */

#line 1 "lib/Cam/Scom.xs"
//  Copyright 2006,2007 Doug Campbell
//
//  This file is part of Cam-Scom.
//
//  Cam-Scom is free software; you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation; either version 3 of the License, or
//  (at your option) any later version.
//
//  Cam-Scom is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with Cam-Scom; if not, see <http://www.gnu.org/licenses/>.

#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"
#include <unistd.h>
#include <fcntl.h>
#include <sys/select.h>
#include <sys/types.h>
#include <sys/socket.h>

#line 37 "lib/Cam/Scom.c"
#ifndef PERL_UNUSED_VAR
#  define PERL_UNUSED_VAR(var) if (0) var = var
#endif

#ifndef PERL_ARGS_ASSERT_CROAK_XS_USAGE
#define PERL_ARGS_ASSERT_CROAK_XS_USAGE assert(cv); assert(params)

/* prototype to pass -Wmissing-prototypes */
STATIC void
S_croak_xs_usage(pTHX_ const CV *const cv, const char *const params);

STATIC void
S_croak_xs_usage(pTHX_ const CV *const cv, const char *const params)
{
    const GV *const gv = CvGV(cv);

    PERL_ARGS_ASSERT_CROAK_XS_USAGE;

    if (gv) {
        const char *const gvname = GvNAME(gv);
        const HV *const stash = GvSTASH(gv);
        const char *const hvname = stash ? HvNAME(stash) : NULL;

        if (hvname)
            Perl_croak(aTHX_ "Usage: %s::%s(%s)", hvname, gvname, params);
        else
            Perl_croak(aTHX_ "Usage: %s(%s)", gvname, params);
    } else {
        /* Pants. I don't think that it should be possible to get here. */
        Perl_croak(aTHX_ "Usage: CODE(0x%"UVxf")(%s)", PTR2UV(cv), params);
    }
}
#undef  PERL_ARGS_ASSERT_CROAK_XS_USAGE

#ifdef PERL_IMPLICIT_CONTEXT
#define croak_xs_usage(a,b)	S_croak_xs_usage(aTHX_ a,b)
#else
#define croak_xs_usage		S_croak_xs_usage
#endif

#endif

/* NOTE: the prototype of newXSproto() is different in versions of perls,
 * so we define a portable version of newXSproto()
 */
#ifdef newXS_flags
#define newXSproto_portable(name, c_impl, file, proto) newXS_flags(name, c_impl, file, proto, 0)
#else
#define newXSproto_portable(name, c_impl, file, proto) (PL_Sv=(SV*)newXS(name, c_impl, file), sv_setpv(PL_Sv, proto), (CV*)PL_Sv)
#endif /* !defined(newXS_flags) */

#line 89 "lib/Cam/Scom.c"

XS(XS_Cam__Scom__mask_to_array_in_c); /* prototype to pass -Wmissing-prototypes */
XS(XS_Cam__Scom__mask_to_array_in_c)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 2)
       croak_xs_usage(cv,  "maskvar, maskbitlenvar");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	SV *	maskvar = ST(0);
	SV *	maskbitlenvar = ST(1);
#line 34 "lib/Cam/Scom.xs"
    AV *intlist;
    int i;
    int maskbitlen;
    char *mask;
#line 111 "lib/Cam/Scom.c"
#line 39 "lib/Cam/Scom.xs"
    maskbitlen = SvIV(maskbitlenvar);
    mask = SvPV (maskvar, PL_na);
    intlist = newAV();
    for (i = 0; i < maskbitlen; ++i)
    {
	if (FD_ISSET (i, (fd_set *) mask))
	{
	    av_push (intlist, newSViv (i));
	};
    };
    XPUSHs (sv_2mortal (newRV_noinc ((SV*) intlist)));
#line 124 "lib/Cam/Scom.c"
	PUTBACK;
	return;
    }
}


XS(XS_Cam__Scom__fcntl_3arg_in_c); /* prototype to pass -Wmissing-prototypes */
XS(XS_Cam__Scom__fcntl_3arg_in_c)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 3)
       croak_xs_usage(cv,  "fdarg, cmdarg, argarg");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	SV *	fdarg = ST(0);
	SV *	cmdarg = ST(1);
	SV *	argarg = ST(2);
#line 59 "lib/Cam/Scom.xs"
    int fd;
    int cmd;
    long arg;
    int r;
#line 152 "lib/Cam/Scom.c"
#line 64 "lib/Cam/Scom.xs"
    fd = SvIV(fdarg);
    cmd = SvIV(cmdarg);
    arg = (long) SvIV(argarg);
    r = fcntl (fd, cmd, arg);
    XPUSHs (sv_2mortal (newSViv (r)));
#line 159 "lib/Cam/Scom.c"
	PUTBACK;
	return;
    }
}


XS(XS_Cam__Scom__c_socket); /* prototype to pass -Wmissing-prototypes */
XS(XS_Cam__Scom__c_socket)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 3)
       croak_xs_usage(cv,  "domainarg, typearg, protocolarg");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	SV *	domainarg = ST(0);
	SV *	typearg = ST(1);
	SV *	protocolarg = ST(2);
#line 79 "lib/Cam/Scom.xs"
  /*  Provides socket(2) system call to perl  */
  /*  Use as:  $fd = _c_socket (domain, type, protocol);  */

    int fd;
    int domain;
    int type;
    int protocol;
#line 190 "lib/Cam/Scom.c"
#line 87 "lib/Cam/Scom.xs"
    domain = SvIV(domainarg);
    type = SvIV(typearg);
    protocol = SvIV(protocolarg);
    fd = socket (domain, type, protocol);
    XPUSHs (sv_2mortal (newSViv (fd)));
#line 197 "lib/Cam/Scom.c"
	PUTBACK;
	return;
    }
}


XS(XS_Cam__Scom__c_socketpair); /* prototype to pass -Wmissing-prototypes */
XS(XS_Cam__Scom__c_socketpair)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 3)
       croak_xs_usage(cv,  "domainarg, typearg, protocolarg");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	SV *	domainarg = ST(0);
	SV *	typearg = ST(1);
	SV *	protocolarg = ST(2);
#line 100 "lib/Cam/Scom.xs"
  /*  Provides socketpair(2) system call to perl  */
  /*  Use as:  ($r, $fd0, $fd1) = _c_socketpair (domain, type, protocol);  */

    int r;
    int fds[2];
    int domain;
    int type;
    int protocol;
#line 229 "lib/Cam/Scom.c"
#line 109 "lib/Cam/Scom.xs"
    domain = SvIV(domainarg);
    type = SvIV(typearg);
    protocol = SvIV(protocolarg);
    r = socketpair (domain, type, protocol, fds);
    XPUSHs (sv_2mortal (newSViv (r)));
    XPUSHs (sv_2mortal (newSViv (fds[0])));
    XPUSHs (sv_2mortal (newSViv (fds[1])));
#line 238 "lib/Cam/Scom.c"
	PUTBACK;
	return;
    }
}


XS(XS_Cam__Scom__c_getsockopt); /* prototype to pass -Wmissing-prototypes */
XS(XS_Cam__Scom__c_getsockopt)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 3)
       croak_xs_usage(cv,  "fdarg, levelarg, optnamearg");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	SV *	fdarg = ST(0);
	SV *	levelarg = ST(1);
	SV *	optnamearg = ST(2);
#line 124 "lib/Cam/Scom.xs"
  /*  Provides getsockopt(2) system call to perl  */
  /*  Use as:  ($r [, $value]) = _c_getsockopt (fd, level, optname);  */

    int r;
    int fd;
    int level;
    int optname;
    char optval[256];
    socklen_t optvalbuflen;
#line 271 "lib/Cam/Scom.c"
#line 134 "lib/Cam/Scom.xs"
    fd = SvIV(fdarg);
    level = SvIV(levelarg);
    optname = SvIV(optnamearg);
    optvalbuflen = 256;
    r = getsockopt (fd, level, optname,
    			(void *) optval, &optvalbuflen);
    XPUSHs (sv_2mortal (newSViv (r)));
    if (r != -1)
    {
	XPUSHs (sv_2mortal (newSVpv (optval, optvalbuflen)));
    };
#line 284 "lib/Cam/Scom.c"
	PUTBACK;
	return;
    }
}


XS(XS_Cam__Scom__c_setsockopt); /* prototype to pass -Wmissing-prototypes */
XS(XS_Cam__Scom__c_setsockopt)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 4)
       croak_xs_usage(cv,  "fdarg, levelarg, optnamearg, optvalarg");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	SV *	fdarg = ST(0);
	SV *	levelarg = ST(1);
	SV *	optnamearg = ST(2);
	SV *	optvalarg = ST(3);
#line 154 "lib/Cam/Scom.xs"
  /*  Provides setsockopt(2) system call to perl  */
  /*  Use as:  $r = _c_setsockopt (fd, level, optname);  */

    int r;
    int fd;
    int level;
    int optname;
    const void *optval;
    STRLEN optvallen;
#line 318 "lib/Cam/Scom.c"
#line 164 "lib/Cam/Scom.xs"
    fd = SvIV(fdarg);
    level = SvIV(levelarg);
    optname = SvIV(optnamearg);
    optval = SvPV(optvalarg, optvallen);
    r = setsockopt (fd, level, optname, optval, (socklen_t) optvallen);
    XPUSHs (sv_2mortal (newSViv (r)));
#line 326 "lib/Cam/Scom.c"
	PUTBACK;
	return;
    }
}


XS(XS_Cam__Scom__c_bind); /* prototype to pass -Wmissing-prototypes */
XS(XS_Cam__Scom__c_bind)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 2)
       croak_xs_usage(cv,  "fdarg, addrarg");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	SV *	fdarg = ST(0);
	SV *	addrarg = ST(1);
#line 177 "lib/Cam/Scom.xs"
  /*  Provides bind(2) system call to perl  */
  /*  Use as:  $r = _c_bind (fd, addr);  */

    int r;
    int fd;
    const struct sockaddr *addr;
    STRLEN addrlen;
#line 356 "lib/Cam/Scom.c"
#line 185 "lib/Cam/Scom.xs"
    fd = SvIV(fdarg);
    addr = (const struct sockaddr *) SvPV(addrarg, addrlen);
    r = bind (fd, addr, (socklen_t) addrlen);
    XPUSHs (sv_2mortal (newSViv (r)));
#line 362 "lib/Cam/Scom.c"
	PUTBACK;
	return;
    }
}


XS(XS_Cam__Scom__c_listen); /* prototype to pass -Wmissing-prototypes */
XS(XS_Cam__Scom__c_listen)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 2)
       croak_xs_usage(cv,  "fdarg, backlogarg");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	SV *	fdarg = ST(0);
	SV *	backlogarg = ST(1);
#line 196 "lib/Cam/Scom.xs"
  /*  Provides listen(2) system call to perl  */
  /*  Use as:  $r = _c_listen (fd, backlog);  */

    int r;
    int fd;
    int backlog;
#line 391 "lib/Cam/Scom.c"
#line 203 "lib/Cam/Scom.xs"
    fd = SvIV(fdarg);
    backlog = SvIV(backlogarg);
    r = listen (fd, backlog);
    XPUSHs (sv_2mortal (newSViv (r)));
#line 397 "lib/Cam/Scom.c"
	PUTBACK;
	return;
    }
}


XS(XS_Cam__Scom__c_accept); /* prototype to pass -Wmissing-prototypes */
XS(XS_Cam__Scom__c_accept)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "fdarg");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	SV *	fdarg = ST(0);
#line 213 "lib/Cam/Scom.xs"
  /*  Provides accept(2) system call to perl  */
  /*  Use as:  ($new_fd [, $addr]) = _c_accept ($fd);  */

    int fd;
    struct sockaddr addr;
    socklen_t addrlen;
    int new_fd;
#line 426 "lib/Cam/Scom.c"
#line 221 "lib/Cam/Scom.xs"
    fd = SvIV(fdarg);
    addrlen = sizeof(addr);
    new_fd = accept (fd, &addr, &addrlen);
    XPUSHs (sv_2mortal (newSViv (fd)));
    if (fd != -1)
    {
        XPUSHs (sv_2mortal (newSVpv ((const char *) &addr, (STRLEN) addrlen)));
    }
#line 436 "lib/Cam/Scom.c"
	PUTBACK;
	return;
    }
}


XS(XS_Cam__Scom__c_connect); /* prototype to pass -Wmissing-prototypes */
XS(XS_Cam__Scom__c_connect)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 2)
       croak_xs_usage(cv,  "fdarg, addrarg");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	SV *	fdarg = ST(0);
	SV *	addrarg = ST(1);
#line 236 "lib/Cam/Scom.xs"
  /*  Provides connect(2) system call to perl  */
  /*  Use as:  $r = _c_connect ($fd, $addr);  */

    int r;
    int fd;
    const struct sockaddr *addr;
    STRLEN addrlen;
#line 466 "lib/Cam/Scom.c"
#line 244 "lib/Cam/Scom.xs"
    fd = SvIV(fdarg);
    addr = (const struct sockaddr *) SvPV(addrarg,addrlen);
    r = connect (fd, addr, (socklen_t) addrlen);
    XPUSHs (sv_2mortal (newSViv (r)));
#line 472 "lib/Cam/Scom.c"
	PUTBACK;
	return;
    }
}

#ifdef __cplusplus
extern "C"
#endif
XS(boot_Cam__Scom); /* prototype to pass -Wmissing-prototypes */
XS(boot_Cam__Scom)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
#if (PERL_REVISION == 5 && PERL_VERSION < 9)
    char* file = __FILE__;
#else
    const char* file = __FILE__;
#endif

    PERL_UNUSED_VAR(cv); /* -W */
    PERL_UNUSED_VAR(items); /* -W */
    XS_VERSION_BOOTCHECK ;

        newXS("Cam::Scom::_mask_to_array_in_c", XS_Cam__Scom__mask_to_array_in_c, file);
        newXS("Cam::Scom::_fcntl_3arg_in_c", XS_Cam__Scom__fcntl_3arg_in_c, file);
        newXS("Cam::Scom::_c_socket", XS_Cam__Scom__c_socket, file);
        newXS("Cam::Scom::_c_socketpair", XS_Cam__Scom__c_socketpair, file);
        newXS("Cam::Scom::_c_getsockopt", XS_Cam__Scom__c_getsockopt, file);
        newXS("Cam::Scom::_c_setsockopt", XS_Cam__Scom__c_setsockopt, file);
        newXS("Cam::Scom::_c_bind", XS_Cam__Scom__c_bind, file);
        newXS("Cam::Scom::_c_listen", XS_Cam__Scom__c_listen, file);
        newXS("Cam::Scom::_c_accept", XS_Cam__Scom__c_accept, file);
        newXS("Cam::Scom::_c_connect", XS_Cam__Scom__c_connect, file);
#if (PERL_REVISION == 5 && PERL_VERSION >= 9)
  if (PL_unitcheckav)
       call_list(PL_scopestack_ix, PL_unitcheckav);
#endif
    XSRETURN_YES;
}
