/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 */
/* MediaTek Inc. (C) 2010. All rights reserved.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
 * AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
 * NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
 * SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
 * SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
 * THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
 * THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
 * CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
 * SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
 * CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 * AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
 * OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
 * MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 * The following software/firmware and/or related documentation ("MediaTek Software")
 * have been modified by MediaTek Inc. All revisions are subject to any receiver's
 * applicable license agreements with MediaTek Inc.
 */

#ifndef TOUCHPANEL_H
#define TOUCHPANEL_H

#include <linux/wakelock.h>
#include <linux/ioctl.h>
//#define TINNO_ANDROID_S7521

#define TPD_TYPE_CAPACITIVE
#define CONFIG_TOUCHSCREEN_FT5X05_DISABLE_KEY_WHEN_SLIDE
#define CONFIG_TOUCHSCREEN_POWER_DOWN_WHEN_SLEEP

#if (defined(TPD_TYPE_CAPACITIVE))
#define TPD_POWER_SOURCE        MT65XX_POWER_COUNT_END
#define TPD_I2C_NUMBER           0
#define TPD_WAKEUP_TRIAL         15
#define TPD_WAKEUP_DELAY         100
#endif

#define TPD_HAVE_BUTTON
#ifdef TPD_HAVE_BUTTON
#if defined(TINNO_ANDROID_S9091) || defined(TINNO_ANDROID_S9096)
  #define TPD_YMAX_NB		1044
  #define TPD_YMAX_BYD		1044

  #define TPD_BUTTON_HEIGHT		960
  #define TPD_Y_OFFSET		6
#elif defined (TINNO_ANDROID_S8121) || defined(TINNO_ANDROID_S8122)

  #define TPD_YMAX_NB		940
  #define TPD_YMAX_BYD	940

  #define TPD_BUTTON_HEIGHT		854
  #define TPD_Y_OFFSET		6
#elif defined (TINNO_ANDROID_S7811A) ||defined (TINNO_ANDROID_S7810)
  #define TPD_YMAX_NB		940
  #define TPD_YMAX_BYD	940

  #define TPD_BUTTON_HEIGHT		854
  #define TPD_Y_OFFSET		6
#else
  #error "Wrong platform."
#endif

#define KEYCODE_APP_SWITCH KEY_F17

#define TPD_KEY_COUNT           3
#define TPD_KEYS                {KEY_MENU, KEY_HOMEPAGE, KEY_BACK}

#define TPD_BUTTON_SIZE_HEIGHT_NB  (TPD_YMAX_NB - TPD_BUTTON_HEIGHT - TPD_Y_OFFSET)
#define TPD_BUTTON_Y_CENTER_NB   	(TPD_BUTTON_HEIGHT + (TPD_YMAX_NB - TPD_BUTTON_HEIGHT)/2 + TPD_Y_OFFSET)

#define TPD_BUTTON_SIZE_HEIGHT_BYD  (TPD_YMAX_BYD - TPD_BUTTON_HEIGHT - TPD_Y_OFFSET)
#define TPD_BUTTON_Y_CENTER_BYD   	(TPD_BUTTON_HEIGHT + (TPD_YMAX_BYD - TPD_BUTTON_HEIGHT)/2 + TPD_Y_OFFSET)

//TP virtual key customization

// |                                                                                                                       |
// |                                                                                                                       |  Touch Pad area ( H < TPD_BUTTON_HEIGHT)
//  ---------------------------------------------------------------------------------------------------
// |                                           TPD_Y_OFFSET                                                       |  Virtual key area ( H > TPD_BUTTON_HEIGHT)
// |---------------------------------------------------------------------------------------------------
// |TPD_B1_FP | [TPD_B1_W] | TPD_B2_FP | [TPD_B2_W] | TPD_B3_FP | [TPD_B3_W]   |  
// -----------------------------------------------------------------------------------------------------
#if defined(TINNO_ANDROID_S9091) || defined(TINNO_ANDROID_S9096)
  #define TPD_B1_FP	45		//Button 1 pad space
  #define TPD_B1_W	90		//Button 1 Width
  #define TPD_B2_FP	90		//Button 2 pad space
  #define TPD_B2_W	90		//Button 2 Width
  #define TPD_B3_FP	90		//Button 3 pad space
  #define TPD_B3_W	90		//Button 3 Width
#elif defined (TINNO_ANDROID_S8121) || defined(TINNO_ANDROID_S8122)||defined(TINNO_ANDROID_S7811A) ||defined (TINNO_ANDROID_S7810)
  #define TPD_B1_FP	40		//Button 1 pad space
  #define TPD_B1_W	80		//Button 1 Width
  #define TPD_B2_FP	80		//Button 2 pad space
  #define TPD_B2_W	80		//Button 2 Width
  #define TPD_B3_FP	80		//Button 3 pad space
  #define TPD_B3_W	80		//Button 3 Width
#else
  #error "Wrong platform."
#endif

//-------------------------------------------------------------------------
#define TPD_BUTTON1_X_CENTER	TPD_B1_FP + TPD_B1_W/2
#define TPD_BUTTON2_X_CENTER	TPD_B1_FP + TPD_B1_W + TPD_B2_FP + TPD_B2_W/2
#define TPD_BUTTON3_X_CENTER	TPD_B1_FP + TPD_B1_W + TPD_B2_FP + TPD_B2_W + TPD_B3_FP + TPD_B3_W/2


#define TPD_KEYS_DIM_NB    {{TPD_BUTTON1_X_CENTER, TPD_BUTTON_Y_CENTER_NB, TPD_B1_W, TPD_BUTTON_SIZE_HEIGHT_NB},	\
				 			{TPD_BUTTON2_X_CENTER, TPD_BUTTON_Y_CENTER_NB, TPD_B2_W, TPD_BUTTON_SIZE_HEIGHT_NB},	\
							{TPD_BUTTON3_X_CENTER, TPD_BUTTON_Y_CENTER_NB, TPD_B3_W, TPD_BUTTON_SIZE_HEIGHT_NB}}

#define TPD_KEYS_DIM_BYD  {{TPD_BUTTON1_X_CENTER, TPD_BUTTON_Y_CENTER_BYD, TPD_B1_W, TPD_BUTTON_SIZE_HEIGHT_BYD},	\
				 			{TPD_BUTTON2_X_CENTER, TPD_BUTTON_Y_CENTER_BYD, TPD_B2_W, TPD_BUTTON_SIZE_HEIGHT_BYD},	\
							{TPD_BUTTON3_X_CENTER, TPD_BUTTON_Y_CENTER_BYD, TPD_B3_W, TPD_BUTTON_SIZE_HEIGHT_BYD}}
extern void tpd_button(unsigned int x, unsigned int y, unsigned int down) ;

#endif

#if defined (TINNO_ANDROID_S7811A) ||defined (TINNO_ANDROID_S7810)
#define TPD_I2C_GROUP_ID 1
#else
#define TPD_I2C_GROUP_ID 0
#endif  /* TINNO_ANDROID_S7811A */
//For Android 4.0
#define TPD_I2C_SLAVE_ADDR (0x72 >> 1)

#define TPD_I2C_SLAVE_ADDR1 (0x70 >> 1)
#define TPD_I2C_SLAVE_ADDR2 (0x72 >> 1)

#define MAX_TRANSACTION_LENGTH 8
#define MAX_I2C_TRANSFER_SIZE 6
#define I2C_MASTER_CLOCK       200

#define FTS_EF_DOWN (0)
#define FTS_EF_UP (1)
#define FTS_EF_CONTACT (2)
#define FTS_EF_RESERVED (3)

#define FTS_INVALID_DATA (-1)

#define FTS_IS_TOUCH(p) ( (FTS_EF_DOWN==(p)) || (FTS_EF_CONTACT==(p)) )

#define TINNO_TOUCH_TRACK_IDS 5

typedef struct _tinno_ts_point{
	int x, y, pressure, flag;
}tinno_ts_point;

typedef struct {
	uint8_t	x_h: 4,
		reserved_1: 2,
		event_flag: 2;
	uint8_t	x_l;
	uint8_t	y_h: 4,
		touch_id: 4;
	uint8_t	y_l;
	uint8_t pressure;
	uint8_t speed: 2,
		direction: 2,
		aera:4;
} xy_data_t;

typedef struct {
	uint8_t	reserved_1: 4,
	device_mode: 3,
	reserved_2: 1;
	uint8_t	gesture;
	uint8_t	fingers: 4,
	frame_remaining: 4;
	xy_data_t	 xy_data[TINNO_TOUCH_TRACK_IDS];
} fts_report_data_t;

#define FTS_PROTOCOL_LEN (sizeof(fts_report_data_t))

/* Touch Key State */
typedef enum {
    TKS_IDLE,
    TKS_DOWNED,
    TKS_MOVING,
    TKS_UPPED,
} key_state_t;

typedef struct {
	uint8_t start_reg;
	uint8_t buffer[FTS_PROTOCOL_LEN];
	struct i2c_client *client;
	unsigned long fingers_flag;
	uint8_t last_fingers;
	tinno_ts_point touch_point_pre[TINNO_TOUCH_TRACK_IDS];
	struct task_struct *thread;
	atomic_t isp_opened;
	atomic_t ts_sleepState;
	uint8_t *isp_pBuffer;
	struct wake_lock wake_lock;
	struct mutex mutex;
	struct input_dev *keys_dev;
	key_state_t key_state;
	int mLastKeyCode;
	struct task_struct *thread_isp;
	int isp_code_count;
}tinno_ts_data;


#define FTS_MODE_OPRATE (0x00)
#define FTS_MODE_UPDATE (0x01)
#define FTS_MODE_SYSTEM (0x02)

#define TOUCH_IO_MAGIC ('F')
#define FT5X36_IOCTL_RESET 				_IO(TOUCH_IO_MAGIC, 0x00)
#define FT5X36_IOCTL_SWITCH_TO 		_IOW(TOUCH_IO_MAGIC, 0x01, int)
#define FT5X36_IOCTL_WRITE_PROTECT 	_IOW(TOUCH_IO_MAGIC, 0x02, int)
#define FT5X36_IOCTL_ERASE 				_IO(TOUCH_IO_MAGIC, 0x03)
#define FT5X36_IOCTL_GET_STATUS		_IOR(TOUCH_IO_MAGIC, 0x04, int)
#define FT5X36_IOCTL_GET_CHECKSUM	_IOR(TOUCH_IO_MAGIC, 0x05, int)
#define FT5X36_IOCTL_GET_TPID			_IOR(TOUCH_IO_MAGIC, 0x06, int)
#define FT5X36_IOCTL_AUTO_CAL 			_IO(TOUCH_IO_MAGIC, 0x07)
#define FT5X36_IOCTL_GET_VENDOR_VERSION _IOR(TOUCH_IO_MAGIC, 0x08, int)
#define FT5X36_IOC_MAXNR				(0x11)
#define FT5X36_IOCTL_LAST_BTYE            _IOW(TOUCH_IO_MAGIC, 0x09, int)
#define FT5X36_IOCTL_READ_BootPara            _IOR(TOUCH_IO_MAGIC, 0x10, int)



#define FTS_CTP_FIRWARE_ID (0x7907) //0x7903---FT5X06, 0x7907---FT5X16
#define FTS_CTP_VENDOR_BYD (0x59)
#define FTS_CTP_VENDOR_TRULY (0x5A)
#define FTS_CTP_VENDOR_NANBO (0x5B)
#define FTS_CTP_VENDOR_BAOMING (0x5D)
#define FTS_CTP_VENDOR_JIEMIAN (0x8B)
#define FTS_CTP_VENDOR_YEJI (0x80)
#define FTS_CTP_VENDOR_LianChuang (0x87)


static tinno_ts_data *g_pts = NULL;
////////////////////////////////////////////////////////////////////
//add by liyaohua
typedef unsigned char         FTS_BYTE;    //8 bit
typedef unsigned short        FTS_WORD;    //16 bit
typedef unsigned int          FTS_DWRD;    //16 bit
typedef unsigned char         FTS_BOOL;    //8 bit
//struct i2c_client *this_client = ts;   //eton,lynn,20121008,for ctp_upgrade
#define FTS_NULL                0x0
#define FTS_TRUE                0x01
#define FTS_FALSE               0x0
#define FTS_DMA_BUF_SIZE 				1024

typedef enum
{
    ERR_OK,
    ERR_MODE,
    ERR_READID,
    ERR_ERASE,
    ERR_STATUS,
    ERR_ECC,
    ERR_DL_ERASE_FAIL,
    ERR_DL_PROGRAM_FAIL,
    ERR_DL_VERIFY_FAIL
}E_UPGRADE_ERR_TYPE;



int fts_5x36_isp_init( tinno_ts_data *ts); 
void fts_5x36_isp_exit(void);
void fts_5x36_hw_reset(void);
int fts_5x36_key_cancel(void);
int fts_5x36_parase_keys(tinno_ts_data *ts, fts_report_data_t *pReportData);
int fts_keys_init(tinno_ts_data *ts);
void fts_keys_deinit(void);
int fts_iic_init( tinno_ts_data *ts );
int tpd_read_touchinfo(tinno_ts_data *ts);
//int fts_write_reg(u8 addr, u8 para);
//int fts_read_reg(u8 addr, unsigned char *pdata);
int fts_i2c_write_block( u8 *txbuf, int len );
u8 fts_cmd_write(u8 btcmd,u8 btPara1,u8 btPara2,u8 btPara3,u8 num);
int get_fw_version_ext(void);
int FT5x36_get_vendor_version(tinno_ts_data *ts, uint8_t *pfw_vendor, uint8_t *pfw_version);
void FT5x36_complete_unfinished_event( void );
FTS_BOOL cmd_write(FTS_BYTE btcmd,FTS_BYTE btPara1,FTS_BYTE btPara2,FTS_BYTE btPara3,FTS_BYTE 
num);
FTS_BOOL byte_read(FTS_BYTE* pbt_buf, FTS_BYTE bt_len);
int ft5x0x_i2c_txdata(char *txdata, int length);
int fts_write_reg( u8 regaddr, u8 regvalue);
int fts_read_reg( u8 regaddr, u8 *regvalue);
int fts_i2c_Write(struct i2c_client *client, char *writebuf, int writelen);
int fts_i2c_Read(struct i2c_client *client, char *writebuf,
			int writelen, char *readbuf, int readlen);
int fts_create_sysfs(struct i2c_client * client);
void fts_release_sysfs(struct i2c_client * client);
// Jake.L, DATE20130701, Test, DATE20130701-01 LINE
#if 1
#define CTP_DBG(fmt, arg...) \
	printk("[CTP-FT5X36] %s (line:%d) :" fmt "\r\n", __func__, __LINE__, ## arg)
#else
#define CTP_DBG(fmt, arg...) do {} while (0)
#endif

#endif

