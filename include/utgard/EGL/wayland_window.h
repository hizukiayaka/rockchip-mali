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
 * @file wayland_window.h
 * @brief A window type for the wayland platform (used by egl and tests)
 */

#ifndef _WAYLAND_WINDOW_H_
#define _WAYLAND_WINDOW_H_

#ifdef __cplusplus
extern "C" {
#endif

struct wl_surface;

typedef struct wl_egl_window
{
	struct wl_surface *surface;
	void *egl_surface_list;
	int dx;
	int dy;
	int width;
	int height;
	int refcnt;
} wl_egl_window;

#ifdef __cplusplus
}
#endif


#endif
