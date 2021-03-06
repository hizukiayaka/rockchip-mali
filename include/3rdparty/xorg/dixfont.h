/*
 * This confidential and proprietary software may be used only as
 * authorised by a licensing agreement from Rockchip.
 * Copyright (c) 2017 FUZHOU ROCKCHIP ELECTRONICS CO., LTD. ("Rockchip").
 * 	http://www.rock-chips.com
 * 		ALL RIGHTS RESERVED
 * The entire notice above must be reproduced on all authorised
 * copies and copies may only be made to the extent permitted
 * by a licensing agreement from Rockchip.
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */
/***********************************************************
Copyright 1987 by Digital Equipment Corporation, Maynard, Massachusetts.

                        All Rights Reserved

Permission to use, copy, modify, and distribute this software and its
documentation for any purpose and without fee is hereby granted,
provided that the above copyright notice appear in all copies and that
both that copyright notice and this permission notice appear in
supporting documentation, and that the name of Digital not be
used in advertising or publicity pertaining to distribution of the
software without specific, written prior permission.

DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING
ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL
DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR
ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,
ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS
SOFTWARE.

******************************************************************/

#ifndef DIXFONT_H
#define DIXFONT_H 1

#include "dix.h"
#include <X11/fonts/font.h>
#include "closure.h"
#include <X11/fonts/fontstruct.h>
#include <X11/fonts/fontproto.h>

#define NullDIXFontProp ((DIXFontPropPtr)0)

typedef struct _DIXFontProp *DIXFontPropPtr;

extern _X_EXPORT Bool SetDefaultFont(const char * /*defaultfontname */ );

extern _X_EXPORT void QueueFontWakeup(FontPathElementPtr /*fpe */ );

extern _X_EXPORT void RemoveFontWakeup(FontPathElementPtr /*fpe */ );

extern _X_EXPORT void FontWakeup(void *data,
                                 int count,
                                 void *LastSelectMask);

extern _X_EXPORT int OpenFont(ClientPtr /*client */ ,
                              XID /*fid */ ,
                              Mask /*flags */ ,
                              unsigned /*lenfname */ ,
                              const char * /*pfontname */ );

extern _X_EXPORT int CloseFont(void *pfont,
                               XID fid);

typedef struct _xQueryFontReply *xQueryFontReplyPtr;

extern _X_EXPORT void QueryFont(FontPtr /*pFont */ ,
                                xQueryFontReplyPtr /*pReply */ ,
                                int /*nProtoCCIStructs */ );

extern _X_EXPORT int ListFonts(ClientPtr /*client */ ,
                               unsigned char * /*pattern */ ,
                               unsigned int /*length */ ,
                               unsigned int /*max_names */ );

extern _X_EXPORT int
 doListFontsWithInfo(ClientPtr /*client */ ,
                     LFWIclosurePtr /*c */ );

extern _X_EXPORT int doPolyText(ClientPtr /*client */ ,
                                PTclosurePtr    /*c */
    );

extern _X_EXPORT int PolyText(ClientPtr /*client */ ,
                              DrawablePtr /*pDraw */ ,
                              GCPtr /*pGC */ ,
                              unsigned char * /*pElt */ ,
                              unsigned char * /*endReq */ ,
                              int /*xorg */ ,
                              int /*yorg */ ,
                              int /*reqType */ ,
                              XID /*did */ );

extern _X_EXPORT int doImageText(ClientPtr /*client */ ,
                                 ITclosurePtr /*c */ );

extern _X_EXPORT int ImageText(ClientPtr /*client */ ,
                               DrawablePtr /*pDraw */ ,
                               GCPtr /*pGC */ ,
                               int /*nChars */ ,
                               unsigned char * /*data */ ,
                               int /*xorg */ ,
                               int /*yorg */ ,
                               int /*reqType */ ,
                               XID /*did */ );

extern _X_EXPORT int SetFontPath(ClientPtr /*client */ ,
                                 int /*npaths */ ,
                                 unsigned char * /*paths */ );

extern _X_EXPORT int SetDefaultFontPath(const char * /*path */ );

extern _X_EXPORT int GetFontPath(ClientPtr client,
                                 int *count,
                                 int *length, unsigned char **result);

extern _X_EXPORT void DeleteClientFontStuff(ClientPtr /*client */ );

/* Quartz support on Mac OS X pulls in the QuickDraw
   framework whose InitFonts function conflicts here. */
#ifdef __APPLE__
#define InitFonts Darwin_X_InitFonts
#endif
extern _X_EXPORT void InitFonts(void);

extern _X_EXPORT void FreeFonts(void);

extern _X_EXPORT FontPtr find_old_font(XID /*id */ );

#define GetGlyphs dixGetGlyphs
extern _X_EXPORT void dixGetGlyphs(FontPtr /*font */ ,
                                   unsigned long /*count */ ,
                                   unsigned char * /*chars */ ,
                                   FontEncoding /*fontEncoding */ ,
                                   unsigned long * /*glyphcount */ ,
                                   CharInfoPtr * /*glyphs */ );

extern _X_EXPORT void QueryGlyphExtents(FontPtr /*pFont */ ,
                                        CharInfoPtr * /*charinfo */ ,
                                        unsigned long /*count */ ,
                                        ExtentInfoPtr /*info */ );

extern _X_EXPORT Bool QueryTextExtents(FontPtr /*pFont */ ,
                                       unsigned long /*count */ ,
                                       unsigned char * /*chars */ ,
                                       ExtentInfoPtr /*info */ );

extern _X_EXPORT Bool ParseGlyphCachingMode(char * /*str */ );

extern _X_EXPORT void InitGlyphCaching(void);

extern _X_EXPORT void SetGlyphCachingMode(int /*newmode */ );

extern _X_EXPORT void register_fpe_functions(void);

#endif                          /* DIXFONT_H */
