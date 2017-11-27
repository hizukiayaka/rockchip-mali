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

#ifndef _EGLEXT_H_
#define _EGLEXT_H_

#include <EGL/eglext.h>

/* At least up to Android 4.2.2_mr1 the eglext.h in Android doesn't
 * have the EGL_KHR_wait_sync types, only corresponding
 * EGL_ANDROID_wait_sync types */
#ifndef EGL_KHR_wait_sync
#define EGL_KHR_wait_sync 1
#ifdef EGL_EGLEXT_PROTOTYPES
EGLAPI EGLint EGLAPIENTRY eglWaitSyncKHR(EGLDisplay dpy, EGLSyncKHR sync, EGLint flags);
#endif /* EGL_EGLEXT_PROTOTYPES */
typedef EGLint(EGLAPIENTRYP PFNEGLWAITSYNCKHRPROC)(EGLDisplay dpy, EGLSyncKHR sync, EGLint flags);
#endif

/* eglWaitSyncANDROID is not in eglext.h of Android 4.3 (jellybean_mr2)
 * EGL_ANDROID_wait_sync */
#ifndef EGL_ANDROID_wait_sync
#define EGL_ANDROID_wait_sync
#ifdef EGL_EGLEXT_PROTOTYPES
EGLAPI EGLint EGLAPIENTRY eglWaitSyncANDROID(EGLDisplay dpy, EGLSyncKHR sync, EGLint flags);
#endif
typedef EGLint(EGLAPIENTRYP PFNEGLWAITSYNCANDROID)(EGLDisplay dpy, EGLSyncKHR sync, EGLint flags);
#endif

/* EGL_ANDROID_blob_cache extension */
#ifndef EGL_ANDROID_blob_cache
#define EGL_ANDROID_blob_cache 1
typedef khronos_ssize_t EGLsizeiANDROID;
typedef void (*EGLSetBlobFuncANDROID)(const void *key, EGLsizeiANDROID keySize, const void *value, EGLsizeiANDROID valueSize);
typedef EGLsizeiANDROID(*EGLGetBlobFuncANDROID)(const void *key, EGLsizeiANDROID keySize, void *value, EGLsizeiANDROID valueSize);
#ifdef EGL_EGLEXT_PROTOTYPES
EGLAPI void EGLAPIENTRY eglSetBlobCacheFuncsANDROID(EGLDisplay dpy, EGLSetBlobFuncANDROID set, EGLGetBlobFuncANDROID get);
#endif /* EGL_EGLEXT_PROTOTYPES */
typedef void (EGLAPIENTRYP PFNEGLSETBLOBCACHEFUNCSANDROIDPROC)(EGLDisplay dpy, EGLSetBlobFuncANDROID set, EGLGetBlobFuncANDROID get);
#endif

/* Part of EGL_create_context extension. We currently support only debug
 * context creation flag */
#ifndef EGL_CONTEXT_OPENGL_DEBUG_BIT_KHR
#define EGL_CONTEXT_OPENGL_DEBUG_BIT_KHR               0x00000001
#endif

/* Tokens introduced by EGL_KHR_create_context extension */
#ifndef EGL_KHR_create_context
#define EGL_KHR_create_context 1
#define EGL_CONTEXT_MAJOR_VERSION_KHR                       EGL_CONTEXT_CLIENT_VERSION
#define EGL_CONTEXT_MINOR_VERSION_KHR                       0x30FB
#define EGL_CONTEXT_FLAGS_KHR                               0x30FC
#define EGL_CONTEXT_OPENGL_PROFILE_MASK_KHR                 0x30FD
#define EGL_CONTEXT_OPENGL_RESET_NOTIFICATION_STRATEGY_KHR  0x31BD
#define EGL_NO_RESET_NOTIFICATION_KHR                       0x31BE
#define EGL_LOSE_CONTEXT_ON_RESET_KHR                       0x31BF
#define EGL_CONTEXT_OPENGL_DEBUG_BIT_KHR                    0x00000001
#define EGL_CONTEXT_OPENGL_FORWARD_COMPATIBLE_BIT_KHR       0x00000002
#define EGL_CONTEXT_OPENGL_ROBUST_ACCESS_BIT_KHR            0x00000004
#define EGL_CONTEXT_OPENGL_CORE_PROFILE_BIT_KHR             0x00000001
#define EGL_CONTEXT_OPENGL_COMPATIBILITY_PROFILE_BIT_KHR    0x00000002
#define EGL_OPENGL_ES3_BIT_KHR                              0x00000040
#endif

#ifndef EGL_KHR_create_context_no_error
#define EGL_KHR_create_context_no_error 1
#define EGL_CONTEXT_OPENGL_NO_ERROR_KHR   0x31B3
#endif /* EGL_KHR_create_context_no_error */

#ifndef EGL_KHR_swap_buffers_with_damage
#define EGL_KHR_swap_buffers_with_damage 1
typedef EGLBoolean(EGLAPIENTRYP PFNEGLSWAPBUFFERSWITHDAMAGEKHRPROC)(EGLDisplay dpy, EGLSurface surface, EGLint *rects, EGLint n_rects);
#ifdef EGL_EGLEXT_PROTOTYPES
EGLAPI EGLBoolean EGLAPIENTRY eglSwapBuffersWithDamageKHR(EGLDisplay dpy, EGLSurface surface, EGLint *rects, EGLint n_rects);
#endif
#endif /* EGL_KHR_swap_buffers_with_damage */

#ifndef EGL_EXT_swap_buffers_with_damage
#define EGL_EXT_swap_buffers_with_damage 1
typedef EGLBoolean(EGLAPIENTRYP PFNEGLSWAPBUFFERSWITHDAMAGEEXTPROC)(EGLDisplay dpy, EGLSurface surface, EGLint *rects, EGLint n_rects);
#ifdef EGL_EGLEXT_PROTOTYPES
EGLAPI EGLBoolean EGLAPIENTRY eglSwapBuffersWithDamageEXT(EGLDisplay dpy, EGLSurface surface, EGLint *rects, EGLint n_rects);
#endif
#endif /* EGL_EXT_swap_buffers_with_damage */

#ifndef EGL_KHR_partial_update
#define EGL_KHR_partial_update 1
#define EGL_BUFFER_AGE_KHR                0x313D
typedef EGLBoolean(EGLAPIENTRYP PFNEGLSETDAMAGEREGIONKHRPROC)(EGLDisplay dpy, EGLSurface surface, EGLint *rects, EGLint n_rects);
#ifdef EGL_EGLEXT_PROTOTYPES
EGLAPI EGLBoolean EGLAPIENTRY eglSetDamageRegionKHR(EGLDisplay dpy, EGLSurface surface, EGLint *rects, EGLint n_rects);
#endif
#endif /* EGL_KHR_partial_update */

#ifndef EGL_EXT_platform_base
#define EGL_EXT_platform_base 1
typedef EGLDisplay(EGLAPIENTRYP PFNEGLGETPLATFORMDISPLAYEXTPROC)(EGLenum platform, void *native_display, const EGLint *attrib_list);
typedef EGLSurface(EGLAPIENTRYP PFNEGLCREATEPLATFORMWINDOWSURFACEEXT)(EGLDisplay dpy, EGLConfig config, void *native_window, const EGLint *attrib_list);
typedef EGLSurface(EGLAPIENTRYP PFNEGLCREATEPLATFORMPIXMAPSURFACEEXT)(EGLDisplay dpy, EGLConfig config, void *native_pixmap, const EGLint *attrib_list);
#ifdef EGL_EGLEXT_PROTOTYPES
EGLAPI EGLDisplay EGLAPIENTRY eglGetPlatformDisplayEXT(EGLenum platform, void *native_display, const EGLint *attrib_list);
EGLAPI EGLSurface EGLAPIENTRY eglCreatePlatformWindowSurfaceEXT(EGLDisplay dpy, EGLConfig config, void *native_window, const EGLint *attrib_list);
EGLAPI EGLSurface EGLAPIENTRY eglCreatePlatformPixmapSurfaceEXT(EGLDisplay dpy, EGLConfig config, void *native_pixmap, const EGLint *attrib_list);
#endif
#endif /* EGL_EXT_platform_base */

#ifndef EGL_KHR_platform_x11
#define EGL_KHR_platform_x11 1
#define EGL_PLATFORM_X11_KHR                    0x31D5
#define EGL_PLATFORM_X11_SCREEN_KHR             0x31D6
#endif /* EGL_KHR_platform_x11 */

#ifndef EGL_KHR_platform_gbm
#define EGL_KHR_platform_gbm 1
#define EGL_PLATFORM_GBM_KHR                    0x31D7
#endif /* EGL_KHR_platform_gbm */

#ifndef EGL_KHR_platform_wayland
#define EGL_KHR_platform_wayland 1
#define EGL_PLATFORM_WAYLAND_KHR                0x31D8
#endif /* EGL_KHR_platform_wayland */

#ifndef EGL_KHR_platform_android
#define EGL_KHR_platform_android 1
#define EGL_PLATFORM_ANDROID_KHR                0x3141
#endif /* EGL_KHR_platform_android */

#ifndef EGL_EXT_protected_surface
#define EGL_EXT_protected_surface 1
#define EGL_PROTECTED_CONTENT_EXT               0x32C0
#endif /* EGL_EXT_protected_surface */

#ifndef EGL_EXT_yuv_surface
#define EGL_EXT_yuv_surface 1
#define EGL_YUV_ORDER_EXT                 0x3301
#define EGL_YUV_NUMBER_OF_PLANES_EXT      0x3311
#define EGL_YUV_SUBSAMPLE_EXT             0x3312
#define EGL_YUV_DEPTH_RANGE_EXT           0x3317
#define EGL_YUV_CSC_STANDARD_EXT          0x330A
#define EGL_YUV_PLANE_BPP_EXT             0x331A
#define EGL_YUV_BUFFER_EXT                0x3300
#define EGL_YUV_ORDER_YUV_EXT             0x3302
#define EGL_YUV_ORDER_YVU_EXT             0x3303
#define EGL_YUV_ORDER_YUYV_EXT            0x3304
#define EGL_YUV_ORDER_UYVY_EXT            0x3305
#define EGL_YUV_ORDER_YVYU_EXT            0x3306
#define EGL_YUV_ORDER_VYUY_EXT            0x3307
#define EGL_YUV_ORDER_AYUV_EXT            0x3308
#define EGL_YUV_SUBSAMPLE_4_2_0_EXT       0x3313
#define EGL_YUV_SUBSAMPLE_4_2_2_EXT       0x3314
#define EGL_YUV_SUBSAMPLE_4_4_4_EXT       0x3315
#define EGL_YUV_DEPTH_RANGE_LIMITED_EXT   0x3318
#define EGL_YUV_DEPTH_RANGE_FULL_EXT      0x3319
#define EGL_YUV_CSC_STANDARD_601_EXT      0x330B
#define EGL_YUV_CSC_STANDARD_709_EXT      0x330C
#define EGL_YUV_CSC_STANDARD_2020_EXT     0x330D
#define EGL_YUV_PLANE_BPP_0_EXT           0x331B
#define EGL_YUV_PLANE_BPP_8_EXT           0x331C
#define EGL_YUV_PLANE_BPP_10_EXT          0x331D
#endif /* EGL_EXT_yuv_surface */

#endif /* _EGLEXT_H_ */
