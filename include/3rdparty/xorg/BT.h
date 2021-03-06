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

#include "xf86RamDac.h"

extern _X_EXPORT RamDacHelperRecPtr BTramdacProbe(ScrnInfoPtr pScrn,
                                                  RamDacSupportedInfoRecPtr
                                                  ramdacs);
extern _X_EXPORT void BTramdacSave(ScrnInfoPtr pScrn, RamDacRecPtr RamDacRec,
                                   RamDacRegRecPtr RamDacRegRec);
extern _X_EXPORT void BTramdacRestore(ScrnInfoPtr pScrn, RamDacRecPtr RamDacRec,
                                      RamDacRegRecPtr RamDacRegRec);
extern _X_EXPORT void BTramdacSetBpp(ScrnInfoPtr pScrn,
                                     RamDacRegRecPtr RamDacRegRec);

#define ATT20C504_RAMDAC 	(VENDOR_BT << 16) | 0x00
#define ATT20C505_RAMDAC 	(VENDOR_BT << 16) | 0x01
#define BT485_RAMDAC		(VENDOR_BT << 16) | 0x02

/*
 * BT registers
 */

#define BT_WRITE_ADDR		0x00
#define BT_RAMDAC_DATA		0x01
#define BT_PIXEL_MASK		0x02
#define BT_READ_ADDR		0x03
#define BT_CURS_WR_ADDR		0x04
#define BT_CURS_DATA		0x05
#define BT_COMMAND_REG_0	0x06
#define BT_CURS_RD_ADDR		0x07
#define BT_COMMAND_REG_1	0x08
#define BT_COMMAND_REG_2	0x09
#define BT_STATUS_REG		0x0A
#define BT_CURS_RAM_DATA	0x0B
#define BT_CURS_X_LOW		0x0C
#define BT_CURS_X_HIGH		0x0D
#define BT_CURS_Y_LOW		0x0E
#define BT_CURS_Y_HIGH		0x0F
