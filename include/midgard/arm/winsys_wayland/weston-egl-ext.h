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

/* Extensions used by Weston, copied from Mesa's eglmesaext.h, */

#ifndef WESTON_EGL_EXT_H
#define WESTON_EGL_EXT_H

#ifndef EGL_WL_bind_wayland_display
#define EGL_WL_bind_wayland_display 1

#define EGL_WAYLAND_BUFFER_WL		0x31D5 /* eglCreateImageKHR target */
#define EGL_WAYLAND_PLANE_WL		0x31D6 /* eglCreateImageKHR target */

#define EGL_TEXTURE_Y_U_V_WL            0x31D7
#define EGL_TEXTURE_Y_UV_WL             0x31D8
#define EGL_TEXTURE_Y_XUXV_WL           0x31D9
#define EGL_TEXTURE_EXTERNAL_WL         0x31DA

struct wl_display;
struct wl_resource;
#ifdef EGL_EGLEXT_PROTOTYPES
EGLAPI EGLBoolean EGLAPIENTRY eglBindWaylandDisplayWL(EGLDisplay dpy, struct wl_display *display);
EGLAPI EGLBoolean EGLAPIENTRY eglUnbindWaylandDisplayWL(EGLDisplay dpy, struct wl_display *display);
EGLAPI EGLBoolean EGLAPIENTRY eglQueryWaylandBufferWL(EGLDisplay dpy, struct wl_resource *buffer, EGLint attribute, EGLint *value);
#endif
typedef EGLBoolean (EGLAPIENTRYP PFNEGLBINDWAYLANDDISPLAYWL) (EGLDisplay dpy, struct wl_display *display);
typedef EGLBoolean (EGLAPIENTRYP PFNEGLUNBINDWAYLANDDISPLAYWL) (EGLDisplay dpy, struct wl_display *display);
typedef EGLBoolean (EGLAPIENTRYP PFNEGLQUERYWAYLANDBUFFERWL) (EGLDisplay dpy, struct wl_resource *buffer, EGLint attribute, EGLint *value);
#endif

#ifndef EGL_WL_create_wayland_buffer_from_image
#define EGL_WL_create_wayland_buffer_from_image 1

#ifdef EGL_EGLEXT_PROTOTYPES
EGLAPI struct wl_buffer * EGLAPIENTRY eglCreateWaylandBufferFromImageWL(EGLDisplay dpy, EGLImageKHR image);
#endif
typedef struct wl_buffer * (EGLAPIENTRYP PFNEGLCREATEWAYLANDBUFFERFROMIMAGEWL) (EGLDisplay dpy, EGLImageKHR image);
#endif

#ifndef EGL_TEXTURE_EXTERNAL_WL
#define EGL_TEXTURE_EXTERNAL_WL         0x31DA
#endif

#ifndef EGL_BUFFER_AGE_EXT
#define EGL_BUFFER_AGE_EXT              0x313D
#endif

#ifndef EGL_WAYLAND_Y_INVERTED_WL
#define EGL_WAYLAND_Y_INVERTED_WL		0x31DB /* eglQueryWaylandBufferWL attribute */
#endif

/* Mesas gl2ext.h and probably Khronos upstream defined
 * GL_EXT_unpack_subimage with non _EXT suffixed GL_UNPACK_* tokens.
 * In case we're using that mess, manually define the _EXT versions
 * of the tokens here.*/
#if defined(GL_EXT_unpack_subimage) && !defined(GL_UNPACK_ROW_LENGTH_EXT)
#define GL_UNPACK_ROW_LENGTH_EXT                                0x0CF2
#define GL_UNPACK_SKIP_ROWS_EXT                                 0x0CF3
#define GL_UNPACK_SKIP_PIXELS_EXT                               0x0CF4
#endif


#endif
