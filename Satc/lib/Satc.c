/*
 * This file was generated automatically by ExtUtils::ParseXS version 2.2203 from the
 * contents of Satc.xs. Do not edit this file, edit Satc.xs instead.
 *
 *	ANY CHANGES MADE HERE WILL BE LOST! 
 *
 */

#line 1 "lib/Satc.xs"
//                    -*-C-*-

//  Copyright (C) 2006-2009 Ampersand Inc., and Doug Campbell
//
//  This file is part of Satc.
//
//  Satc is free software; you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation; either version 3 of the License, or
//  (at your option) any later version.
//
//  Satc is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with Satc; if not, see <http://www.gnu.org/licenses/>.

/*  This is C code, passed unchanged to the .c file  */
#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"
#include <stdio.h>
#include <strings.h>

int _parse_hex_digit (char c)
{
    int result;
    if (c < 48) { result = -1; }
    else if (c < 58) { result = c - 48; }
    else if (c < 65) { result = -1; }
    else if (c < 71) { result = c - 55; }
    else if (c < 97) { result = -1; }
    else if (c < 103) { result = c - 87; }
    else { result = -1; };
    return result;
};

/*  This starts the xsubpp-translated code  */
#line 51 "lib/Satc.c"
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

#line 103 "lib/Satc.c"

XS(XS_Satc__parse_SATC_fields); /* prototype to pass -Wmissing-prototypes */
XS(XS_Satc__parse_SATC_fields)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "sv");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	SV *	sv = ST(0);
#line 45 "lib/Satc.xs"
    char *bytes;
    STRLEN bytes_length;
    char *bytes_end;
    char *field_start;
    char *field_end;
    char *ptr;
    int ok;
    SV *msg;
    AV *av;
    SV *avref;
    char c;
    char quote_char;
    char escape_value;
    char *escape_start;
    int dig1, dig2;
#line 135 "lib/Satc.c"
#line 61 "lib/Satc.xs"
    ok = 1;
    msg = &PL_sv_undef;
    av = newAV();
    avref = newRV_noinc ((SV*) av);
    quote_char = '\x0';

    //  Invariant:
    //    The buffer "bytes" will be self-modified, and fields will thus shrink
    //        as escapes are processed.
    //    av contains all already parsed fields
    //    bytes_end points to one past the last byte in bytes
    //    field_start poirts to start of current field (or NULL if none yet)
    //    field_end points to the furthest-yet-seen end of the current field
    //    quote_char is char used to start the current quote, or '\0' for none
    //    ptr poitnts to byte currently considering
    bytes = SvPV (sv, bytes_length);
    bytes_end = bytes + bytes_length;
    field_start = NULL;
    field_end = NULL;
    ptr = bytes - 1;
    while (++ptr < bytes_end)
    {
	c = *ptr;
	//  Ignore this character if it is just whitespace between fields
        if ((field_start != NULL) ||
	    ((c != ' ') && (c != '\t') && (c != '\r') && (c != '\n')))
        {
	    //  This character is not just whitespace between fields

	    //  Initialize the next field if not already done
	    if (field_start == NULL)
	    {
	        field_start = ptr;
	        field_end = ptr;
	        quote_char = '\0';
	    };

	    //  Check for end of quote
	    if ((quote_char != '\0') && (c == quote_char))
	    {
		//  End of quote
		quote_char = '\0';
	    }
	    //  Check for end of field
	    else if ((quote_char == '\0') &&
		     ((c == ' ') || (c == '\t') || (c == '\r') || (c == '\n')))
	    {
		//  The current field has ended, so put it into the
		//  array and reset the invariant
		av_push (av, newSVpvn (field_start, field_end - field_start));
		field_start = NULL;
	    }
	    //  Check for start of quote
	    else if ((quote_char == '\0') &&
		     ((c == '\'') || (c == '\"')))
	    {
		//  A start-of-quote character
		quote_char = c;
	    }
	    //  Check for an escape sequence
	    else if (c == '\\')
	    {
		//  It is an escape sequence
		escape_start = ptr;
		if (++ptr >= bytes_end)
		{
		    //  Error: unterminated escape sequence
		    ok = 0;
		    msg = sv_2mortal
			(newSVpvf
			 ("Unterminated escape sequence at char %ld",
			  escape_start - bytes));
		    EXTEND (SP, 2);
		    XPUSHs (sv_2mortal (newSViv (ok)));
		    XPUSHs (msg);
		    XSRETURN (2);
		};
		c = *ptr;
		if (c == 'n')
		{
		    escape_value = '\n';
		}
		else if ((c == '\\') || (c == '\'') || (c == '\"'))
		{
		    escape_value = c;
		}
		else if (c == 'x')
		{
		    //  Hex escape
		    if (ptr + 2 >=bytes_end)
		    {
			//  Error: unterminated hex escape sequence
			ok = 0;
			msg = sv_2mortal
			    (newSVpvf
			     ("Unterminated hex escape at char %ld",
			      escape_start - bytes));
			EXTEND (SP, 2);
			XPUSHs (sv_2mortal (newSViv (ok)));
			XPUSHs (msg);
			XSRETURN (2);
		    };
		    dig1 = _parse_hex_digit (*(++ptr));
		    dig2 = _parse_hex_digit (*(++ptr));
		    if ((dig1 == -1) || (dig2 == -1))
		    {
			//  Error: unterminated hex escape sequence
			ok = 0;
			msg = sv_2mortal
			    (newSVpvf
			     ("Bad digits in hex escape at char %ld",
			      escape_start - bytes));
			EXTEND (SP, 2);
			XPUSHs (sv_2mortal (newSViv (ok)));
			XPUSHs (msg);
			XSRETURN (2);
		    };
		    escape_value = (unsigned char) (dig1 * 16 + dig2);
		}
		else
		{
		    //  Error: invalid escape sequence
		    ok = 0;
		    msg = sv_2mortal
			(newSVpvf
			 ("Invalid escape sequence at char %ld",
			  escape_start - bytes));
		    EXTEND (SP, 2);
		    XPUSHs (sv_2mortal (newSViv (ok)));
		    XPUSHs (msg);
		    XSRETURN (2);
		};

		//  Got the escape value, so put it at the end
		*field_end = escape_value;
		++field_end;
	    }
	    else
	    {
		//  Just a regular character
		if (field_end != ptr)
		{
		    *field_end = *ptr;
		};
		++field_end;
	    };
        };
    };

    //  Finish up the last field if there was one
    if (quote_char != '\0')
    {
	//  Error: unterminated quote
	ok = 0;
	msg = sv_2mortal (newSVpvf ("Unterminated quote"));
	EXTEND (SP, 2);
	XPUSHs (sv_2mortal (newSViv (ok)));
	XPUSHs (msg);
	XSRETURN (2);
    };
    if (field_start != NULL)
    {
        av_push (av, newSVpvn (field_start, field_end - field_start));
    };

    EXTEND (SP, 3);
    XPUSHs (sv_2mortal (newSViv (ok)));
    XPUSHs (msg);
    XPUSHs (avref);
#line 306 "lib/Satc.c"
	PUTBACK;
	return;
    }
}


XS(XS_Satc__escape_SATC_string); /* prototype to pass -Wmissing-prototypes */
XS(XS_Satc__escape_SATC_string)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "sv");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	SV *	sv = ST(0);
#line 237 "lib/Satc.xs"
    STRLEN input_bytes_length;
    char *input_bytes = SvPV (sv, input_bytes_length);
    char output_bytes[input_bytes_length * 4 + 3];
    char *input_ptr = input_bytes;
    char *output_ptr = &(output_bytes[0]);
    char *input_end = input_ptr + input_bytes_length;
    char c;
#line 335 "lib/Satc.c"
#line 245 "lib/Satc.xs"
    *(output_ptr++) = '"';

    //  Invariant:
    //    input_ptr points to the next character to be converted
    //    input_end points to one past the last character to be converted
    //    output_ptr points to the next place to put a converted character
    while (input_ptr < input_end)
    {
        c = *(input_ptr++);
        if (c == '\\')
        {
    	    *(output_ptr++) = c;
    	    *(output_ptr++) = c;
        }
        else if (c == '\n')
        {
    	    *(output_ptr++) = '\\';
    	    *(output_ptr++) = 'n';
        }
        else if (c == '\'')
        {
    	    *(output_ptr++) = '\\';
    	    *(output_ptr++) = '\'';
        }
        else if (c == '\"')
        {
    	    *(output_ptr++) = '\\';
    	    *(output_ptr++) = '\"';
        }
        else if ((c < ' ') || (c > '~'))
        {
    	    *(output_ptr++) = '\\';
    	    *(output_ptr++) = 'x';
    	    sprintf (output_ptr, "%.2x", (unsigned char) c);
    	    output_ptr += 2;
        }
        else
        {
	    *(output_ptr++) = c;
        };
    };

    //  Final quote and Null terminate it
    *(output_ptr++) = '\"';
    *(output_ptr++) = '\0';

    EXTEND (SP, 1);
    XPUSHs (sv_2mortal (newSVpv (&output_bytes[0], 0)));
#line 385 "lib/Satc.c"
	PUTBACK;
	return;
    }
}


XS(XS_Satc__hashify); /* prototype to pass -Wmissing-prototypes */
XS(XS_Satc__hashify)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 3)
       croak_xs_usage(cv,  "to_hash, preserve_prefix_count, suffix_blocks_count");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	SV *	to_hash = ST(0);
	int	preserve_prefix_count = (int)SvIV(ST(1));
	int	suffix_blocks_count = (int)SvIV(ST(2));
#line 302 "lib/Satc.xs"
    STRLEN input_bytes_length;
    char *input_bytes = SvPV (to_hash, input_bytes_length);
    char output_bytes[preserve_prefix_count + suffix_blocks_count * 11 + 1];
    char *next_output_byte = &(output_bytes[0]);
    uint64_t buf_num[suffix_blocks_count];
    static char sixbit_code[64] =
    { '_', '-', '0', '1', '2', '3', '4', '5',
      '6', '7', '8', '9', 'A', 'B', 'C', 'D',
      'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
      'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
      'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b',
      'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
      'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
      's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
    };
#line 424 "lib/Satc.c"
#line 318 "lib/Satc.xs"
    //  Zero out output area and hash computation area
    bzero (&(output_bytes[0]),
	   preserve_prefix_count + suffix_blocks_count * 11 + 1);
    bzero (&(buf_num[0]), sizeof(uint64_t) * suffix_blocks_count);

    int buf_nums_used = 0;
    int bits_used = 0;
    int i, bit_shift;

    //  Copy preserved prefix
    bcopy (input_bytes, output_bytes, preserve_prefix_count);
    next_output_byte += preserve_prefix_count;

    //  Compute hash numbers
    for (i = 0; i < input_bytes_length - preserve_prefix_count; ++i)
    {
	char input_char = *(input_bytes + preserve_prefix_count + i);
	int byte_in_num = i % 8;
	int num_index = (i >> 3) % suffix_blocks_count;
	if (buf_nums_used < num_index) {buf_nums_used = num_index;};
	buf_num[num_index] +=
	    ( ((uint64_t) input_char) << (byte_in_num * 8) );
	bits_used += 8;
    };

    //  Convert to hashstring suffix
    for (i = 0; i <= buf_nums_used; ++i)
    {
	for (bit_shift = 0; bit_shift < 64; bit_shift += 6)
	{
	    if (bits_used > 0)
	    {
		*(next_output_byte++) =
		    sixbit_code[(buf_num[i] >> bit_shift) & 0x3f];
		if (bit_shift == 60)
		{
		    bits_used -= 4;
		}
		else
		{
		    bits_used -= 6;
		};
	    };
	};
    };
    *next_output_byte = '\0';

    EXTEND (SP, 1);
    XPUSHs (sv_2mortal (newSVpv (&output_bytes[0], 0)));
#line 475 "lib/Satc.c"
	PUTBACK;
	return;
    }
}

#ifdef __cplusplus
extern "C"
#endif
XS(boot_Satc); /* prototype to pass -Wmissing-prototypes */
XS(boot_Satc)
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

        newXS("Satc::_parse_SATC_fields", XS_Satc__parse_SATC_fields, file);
        newXS("Satc::_escape_SATC_string", XS_Satc__escape_SATC_string, file);
        newXS("Satc::_hashify", XS_Satc__hashify, file);
#if (PERL_REVISION == 5 && PERL_VERSION >= 9)
  if (PL_unitcheckav)
       call_list(PL_scopestack_ix, PL_unitcheckav);
#endif
    XSRETURN_YES;
}
