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

/*
 * This file contains declarations for private XFree86 functions and variables,
 * and definitions of private macros.
 *
 * "private" means not available to video drivers.
 */

#ifndef _XF86PRIV_H
#define _XF86PRIV_H

#include "xf86Privstr.h"
#include "propertyst.h"
#include "input.h"

/*
 * Parameters set ONLY from the command line options
 * The global state of these things is held in xf86InfoRec (when appropriate).
 */
extern _X_EXPORT const char *xf86ConfigFile;
extern _X_EXPORT const char *xf86ConfigDir;
extern _X_EXPORT Bool xf86AllowMouseOpenFail;

#ifdef XF86VIDMODE
extern _X_EXPORT Bool xf86VidModeDisabled;
extern _X_EXPORT Bool xf86VidModeAllowNonLocal;
#endif
extern _X_EXPORT Bool xf86fpFlag;
extern _X_EXPORT Bool xf86sFlag;
extern _X_EXPORT Bool xf86bsEnableFlag;
extern _X_EXPORT Bool xf86bsDisableFlag;
extern _X_EXPORT Bool xf86silkenMouseDisableFlag;
extern _X_EXPORT Bool xf86xkbdirFlag;

#ifdef HAVE_ACPI
extern _X_EXPORT Bool xf86acpiDisableFlag;
#endif
extern _X_EXPORT char *xf86LayoutName;
extern _X_EXPORT char *xf86ScreenName;
extern _X_EXPORT char *xf86PointerName;
extern _X_EXPORT char *xf86KeyboardName;
extern _X_EXPORT int xf86FbBpp;
extern _X_EXPORT int xf86Depth;
extern _X_EXPORT Pix24Flags xf86Pix24;
extern _X_EXPORT rgb xf86Weight;
extern _X_EXPORT Bool xf86FlipPixels;
extern _X_EXPORT Gamma xf86Gamma;
extern _X_EXPORT const char *xf86ServerName;

/* Other parameters */

extern _X_EXPORT xf86InfoRec xf86Info;
extern _X_EXPORT const char *xf86ModulePath;
extern _X_EXPORT MessageType xf86ModPathFrom;
extern _X_EXPORT const char *xf86LogFile;
extern _X_EXPORT MessageType xf86LogFileFrom;
extern _X_EXPORT Bool xf86LogFileWasOpened;
extern _X_EXPORT serverLayoutRec xf86ConfigLayout;

extern _X_EXPORT DriverPtr *xf86DriverList;
extern _X_EXPORT int xf86NumDrivers;
extern _X_EXPORT Bool xf86Resetting;
extern _X_EXPORT Bool xf86Initialising;
extern _X_EXPORT int xf86NumScreens;
extern _X_EXPORT const char *xf86VisualNames[];
extern _X_EXPORT int xf86Verbose;       /* verbosity level */
extern _X_EXPORT int xf86LogVerbose;    /* log file verbosity level */

extern _X_EXPORT RootWinPropPtr *xf86RegisteredPropertiesTable;

extern ScrnInfoPtr *xf86GPUScreens;      /* List of pointers to ScrnInfoRecs */
extern int xf86NumGPUScreens;
#ifndef DEFAULT_VERBOSE
#define DEFAULT_VERBOSE		0
#endif
#ifndef DEFAULT_LOG_VERBOSE
#define DEFAULT_LOG_VERBOSE	3
#endif
#ifndef DEFAULT_DPI
#define DEFAULT_DPI		96
#endif

/* Function Prototypes */
#ifndef _NO_XF86_PROTOTYPES

/* xf86Bus.c */
extern _X_EXPORT Bool xf86BusConfig(void);
extern _X_EXPORT void xf86BusProbe(void);
extern _X_EXPORT void xf86AccessEnter(void);
extern _X_EXPORT void xf86AccessLeave(void);
extern _X_EXPORT void xf86PostProbe(void);
extern _X_EXPORT void xf86ClearEntityListForScreen(ScrnInfoPtr pScrn);
extern _X_EXPORT void xf86AddDevToEntity(int entityIndex, GDevPtr dev);
extern _X_EXPORT void xf86RemoveDevFromEntity(int entityIndex, GDevPtr dev);

/* xf86Config.c */

extern _X_EXPORT Bool xf86PathIsSafe(const char *path);

/* xf86DefaultModes */

extern _X_EXPORT const DisplayModeRec xf86DefaultModes[];
extern _X_EXPORT const int xf86NumDefaultModes;

/* xf86Configure.c */
extern _X_EXPORT void
DoConfigure(void)
    _X_NORETURN;
extern _X_EXPORT void
DoShowOptions(void)
    _X_NORETURN;

/* xf86Events.c */

extern _X_EXPORT void
xf86Wakeup(void *blockData, int err, void *pReadmask);
extern _X_HIDDEN int
xf86SigWrapper(int signo);
extern _X_EXPORT void
xf86HandlePMEvents(int fd, void *data);
extern _X_EXPORT int (*xf86PMGetEventFromOs) (int fd, pmEvent * events,
                                              int num);
extern _X_EXPORT pmWait (*xf86PMConfirmEventToOs) (int fd, pmEvent event);

/* xf86Helper.c */
extern _X_EXPORT void
xf86LogInit(void);
extern _X_EXPORT void
xf86CloseLog(enum ExitCode error);

/* xf86Init.c */
extern _X_EXPORT Bool
xf86LoadModules(const char **list, void **optlist);
extern _X_EXPORT int
xf86SetVerbosity(int verb);
extern _X_EXPORT int
xf86SetLogVerbosity(int verb);
extern _X_EXPORT Bool
xf86CallDriverProbe(struct _DriverRec *drv, Bool detect_only);
extern _X_EXPORT Bool
xf86PrivsElevated(void);

#endif                          /* _NO_XF86_PROTOTYPES */

#endif                          /* _XF86PRIV_H */
