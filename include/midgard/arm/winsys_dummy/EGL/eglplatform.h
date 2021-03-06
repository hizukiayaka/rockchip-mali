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

/**
 * @file eglplatform.h
 * Platform related definitions
 */

#ifndef _EGLPLATFORM_H_
#define _EGLPLATFORM_H_

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */


#include <KHR/khrplatform.h>
#include <stdint.h>

#include "mali_fbdev_types.h"

#ifndef EGLAPI
#define EGLAPI
#endif

#ifndef EGLAPIENTRY
#define EGLAPIENTRY
#endif

#ifndef EGLAPIENTRYP
#define EGLAPIENTRYP EGLAPIENTRY *
#endif

typedef fbdev_window * EGLNativeWindowType;

typedef int32_t EGLNativePixmapType;

typedef dummy_display * EGLNativeDisplayType;

typedef EGLNativeWindowType NativeWindowType;
typedef EGLNativePixmapType NativePixmapType;
typedef EGLNativeDisplayType NativeDisplayType;

typedef int32_t EGLint;

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _EGLPLATFORM_H_ */
