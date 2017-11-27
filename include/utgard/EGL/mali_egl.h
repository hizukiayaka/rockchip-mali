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
 * This is the Mali egl wrapper, for use in driver development only
 * all applications should be built with the plain gl.h and egl.h
 * available from Khronos
 */

#ifndef EGLAPIENTRY
#define EGLAPIENTRY
#endif

/*
 * if tracing is enabled, include oglestraceredef.h to change gl* to
 * DRVgl*, so that all entry points can be logged by trace library
 */
#ifdef GL_TRACE_WRAPPER
#include <GLES/oglestraceredef.h>
#endif

/* current khronos distributed egl.h, must be on include path */
#include <EGL/egl.h>
