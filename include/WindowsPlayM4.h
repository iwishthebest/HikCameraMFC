#ifndef _WINDOWS_PLAYM4_H_
#define _WINDOWS_PLAYM4_H_

#if defined( _WINDLL)
    #define PLAYM4_API  extern "C" __declspec(dllexport)
#else 
    #define PLAYM4_API  extern "C" __declspec(dllimport)
#endif

//Max channel numbers
#define PLAYM4_MAX_SUPPORTS 500
//Wave coef range;
#define MIN_WAVE_COEF -100
#define MAX_WAVE_COEF 100

//Timer type
#define TIMER_1 1 //Only 16 timers for every process.Default TIMER;
#define TIMER_2 2 //Not limit;But the precision less than TIMER_1;

//BUFFER AND DATA TYPE
#define BUF_VIDEO_SRC               (1) //mixed input,total src buffer size;splited input,video src buffer size 
#define BUF_AUDIO_SRC               (2) //mixed input,not defined;splited input,audio src buffer size
#define BUF_VIDEO_RENDER            (3) //video render node count 
#define BUF_AUDIO_RENDER            (4) //audio render node count 
#define BUF_VIDEO_DECODED           (5) //video decoded node count to render
#define BUF_AUDIO_DECODED           (6) //audio decoded node count to render
#define BUF_VIDEO_SRC_EX            (7) //video render node count without hangnode;resetbuf need

//Error code
#define  PLAYM4_NOERROR                         0   //no error
#define  PLAYM4_PARA_OVER                       1   //input parameter is invalid;
#define  PLAYM4_ORDER_ERROR                     2   //The order of the function to be called is error.
#define  PLAYM4_TIMER_ERROR                     3   //Create multimedia clock failed;
#define  PLAYM4_DEC_VIDEO_ERROR                 4   //Decode video data failed.
#define  PLAYM4_DEC_AUDIO_ERROR                 5   //Decode audio data failed.
#define  PLAYM4_ALLOC_MEMORY_ERROR              6   //Allocate memory failed.
#define  PLAYM4_OPEN_FILE_ERROR                 7   //Open the file failed.
#define  PLAYM4_CREATE_OBJ_ERROR                8   //Create thread or event failed
#define  PLAYM4_CREATE_DDRAW_ERROR              9   //Create DirectDraw object failed.
#define  PLAYM4_CREATE_OFFSCREEN_ERROR          10  //failed when creating off-screen surface.
#define  PLAYM4_BUF_OVER                        11  //buffer is overflow
#define  PLAYM4_CREATE_SOUND_ERROR              12  //failed when creating audio device.	
#define  PLAYM4_SET_VOLUME_ERROR                13  //Set volume failed
#define  PLAYM4_SUPPORT_FILE_ONLY               14  //The function only support play file.
#define  PLAYM4_SUPPORT_STREAM_ONLY             15  //The function only support play stream.
#define  PLAYM4_SYS_NOT_SUPPORT                 16  //System not support.
#define  PLAYM4_FILEHEADER_UNKNOWN              17  //No file header.
#define  PLAYM4_VERSION_INCORRECT               18  //The version of decoder and encoder is not adapted.  
#define  PLAYM4_INIT_DECODER_ERROR              19  //Initialize decoder failed.
#define  PLAYM4_CHECK_FILE_ERROR                20  //The file data is unknown.
#define  PLAYM4_INIT_TIMER_ERROR                21  //Initialize multimedia clock failed.
#define  PLAYM4_BLT_ERROR                       22  //Blt failed.
#define  PLAYM4_UPDATE_ERROR                    23  //Update failed.
#define  PLAYM4_OPEN_FILE_ERROR_MULTI           24  //openfile error, streamtype is multi
#define  PLAYM4_OPEN_FILE_ERROR_VIDEO           25  //openfile error, streamtype is video
#define  PLAYM4_JPEG_COMPRESS_ERROR             26  //JPEG compress error
#define  PLAYM4_EXTRACT_NOT_SUPPORT             27  //Don't support the version of this file.
#define  PLAYM4_EXTRACT_DATA_ERROR              28  //extract video data failed.
#define  PLAYM4_SECRET_KEY_ERROR                29  //Secret key is error //add 20071218
#define  PLAYM4_DECODE_KEYFRAME_ERROR           30  //add by hy 20090318
#define  PLAYM4_NEED_MORE_DATA                  31  //add by hy 20100617
#define  PLAYM4_INVALID_PORT                    32  //add by cj 20100913
#define  PLAYM4_NOT_FIND                        33  //add by cj 20110428
#define  PLAYM4_NEED_LARGER_BUFFER              34  //add by pzj 20130528
#define  PLAYM4_INVALID_SYNCGROUP               35  // 无效同步回放组序号
#define  PLAYM4_FAIL_UNKNOWN                    99  //Fail, but the reason is unknown;	

//鱼眼功能错误码
#define PLAYM4_FEC_ERR_ENABLEFAIL               100 // 鱼眼模块加载失败
#define PLAYM4_FEC_ERR_NOTENABLE                101 // 鱼眼模块没有加载
#define PLAYM4_FEC_ERR_NOSUBPORT                102 // 子端口没有分配
#define PLAYM4_FEC_ERR_PARAMNOTINIT             103 // 没有初始化对应端口的参数
#define PLAYM4_FEC_ERR_SUBPORTOVER              104 // 子端口已经用完
#define PLAYM4_FEC_ERR_EFFECTNOTSUPPORT         105 // 该安装方式下这种效果不支持
#define PLAYM4_FEC_ERR_INVALIDWND               106 // 非法的窗口
#define PLAYM4_FEC_ERR_PTZOVERFLOW              107 // PTZ位置越界
#define PLAYM4_FEC_ERR_RADIUSINVALID            108 // 圆心参数非法
#define PLAYM4_FEC_ERR_UPDATENOTSUPPORT         109 // 指定的安装方式和矫正效果，该参数更新不支持
#define PLAYM4_FEC_ERR_NOPLAYPORT               110 // 播放库端口没有启用
#define PLAYM4_FEC_ERR_PARAMVALID               111 // 参数为空
#define PLAYM4_FEC_ERR_INVALIDPORT              112 // 非法子端口
#define PLAYM4_FEC_ERR_PTZZOOMOVER              113 // PTZ矫正范围越界
#define PLAYM4_FEC_ERR_OVERMAXPORT              114 // 矫正通道饱和，最大支持的矫正通道为64个
#define PLAYM4_FEC_ERR_ENABLED                  115 // 该端口已经启用了鱼眼模块
#define PLAYM4_FEC_ERR_D3DACCENOTENABLE         116 // D3D加速没有开启
#define PLAYM4_FEC_ERR_PLACETYPE                117 // 安装方式不对.一个播放库port，对应一种安装方式
#define PLAYM4_FEC_ERR_CorrectType              118 // 矫正方式错误：如矫正方式已有,则不能开多个；比如一个播放库port,设定除了PTZ和鱼眼半球矫正方式外,其他的矫正方式则只能开一路;设置180度矫正不能和ptz矫正一起开，半球矫正与其他矫正则无关联性。
#define PLAYM4_FEC_ERR_NULLWND                  119 // 鱼眼窗口为空
#define PLAYM4_FEC_ERR_PARA                     120 // 鱼眼参数错误
#define PLAYM4_FEC_ERR_INVALID_OPERATION        121 // 鱼眼变化过程中，操作无效

//Max display regions.
#define MAX_DISPLAY_WND     4

//Display type
#define DISPLAY_NORMAL      0x00000001
#define DISPLAY_QUARTER     0x00000002
#define DISPLAY_YC_SCALE    0x00000004
#define DISPLAY_NOTEARING   0x00000008

//Display buffers
#define MAX_DIS_FRAMES      50
#define MIN_DIS_FRAMES      1

//Locate by
#define BY_FRAMENUM         1
#define BY_FRAMETIME        2

//Source buffer
#define SOURCE_BUF_MAX      1024*100000
#define SOURCE_BUF_MIN      1024*50

//Stream type
#define STREAME_REALTIME    0
#define STREAME_FILE        1

//frame type
#define T_AUDIO16           101
#define T_AUDIO8            100
#define T_UYVY              1
#define T_YV12              3
#define T_RGB32             7

//capability
#define SUPPORT_DDRAW       1
#define SUPPORT_BLT         2
#define SUPPORT_BLTFOURCC   4
#define SUPPORT_BLTSHRINKX  8
#define SUPPORT_BLTSHRINKY  16
#define SUPPORT_BLTSTRETCHX 32
#define SUPPORT_BLTSTRETCHY 64
#define SUPPORT_SSE         128
#define SUPPORT_MMX         256

// 以下宏定义用于HIK_MEDIAINFO结构
#define FOURCC_HKMI         0x484B4D49  // "HKMI" HIK_MEDIAINFO结构标记

// 系统封装格式
#define SYSTEM_NULL         0x0         // 没有系统层，纯音频流或视频流
#define SYSTEM_HIK          0x1         // 海康文件层
#define SYSTEM_MPEG2_PS     0x2         // PS封装
#define SYSTEM_MPEG2_TS     0x3         // TS封装
#define SYSTEM_RTP          0x4         // rtp封装
#define SYSTEM_MPEG4        0x5         ///< MP4封装
#define SYSTEM_AVI          0x7         ///< AVI封装
#define SYSTEM_RTMP         0xD         // rtmp封装
#define SYSTEM_RTPHIK       0x401       // rtp封装hik
#define SYSTEM_RTP_JT       0x104       // rtpjt封装
#define SYSTEM_DAH          0x8001      // 大华封装
#define SYSTEM_FLV          0x000A          ///< FLV封装支持

// 视频编码类型
#define VIDEO_NULL          0x0 // 没有视频
#define VIDEO_H264          0x1 // 海康H.264
#define VIDEO_MPEG2         0x2 // 标准MPEG2
#define VIDEO_MPEG4         0x3 // 标准MPEG4
#define VIDEO_MJPEG         0x4
#define VIDEO_AVC265        0x5 // 标准H265/AVC
#define VIDEO_SVAC          0x6
#define VIDEO_AVC264        0x0100

// 音频编码类型
#define AUDIO_NULL          0x0000 // 没有音频
#define AUDIO_ADPCM         0x1000 // ADPCM
#define AUDIO_MPEG          0x2000 // MPEG 系列音频，解码器能自适应各种MPEG音频
#define AUDIO_AAC           0X2001 // AAC 编码
#define AUDIO_RAW_DATA8     0x7000 //采样率为8k的原始数据
#define AUDIO_RAW_UDATA16   0x7001 //采样率为16k的原始数据，即L16
// G系列音频
#define AUDIO_RAW_DATA8     0x7000      //采样率为8k的原始数据
#define AUDIO_RAW_UDATA16   0x7001      //采样率为16k的原始数据，即L16
#define AUDIO_G711_U        0x7110
#define AUDIO_G711_A        0x7111
#define AUDIO_G722_1        0x7221
#define AUDIO_G723_1        0x7231
#define AUDIO_G726_U        0x7260
#define AUDIO_G726_A        0x7261
#define AUDIO_G726_16       0x7262
#define AUDIO_G729          0x7290
#define AUDIO_AMR_NB        0x3000

#define SYNCDATA_VEH        1 //同步数据:车载信息
#define SYNCDATA_IVS        2 //同步数据:智能信息

//motion flow type
#define	MOTION_FLOW_NONE    0
#define MOTION_FLOW_CPU     1
#define MOTION_FLOW_GPU     2

//音视频加密类型
#define ENCRYPT_AES_3R_VIDEO     1
#define ENCRYPT_AES_10R_VIDEO    2
#define ENCRYPT_AES_3R_AUDIO     1
#define ENCRYPT_AES_10R_AUDIO    2

///<旋转角度
#define R_ANGLE_0           -1      //不旋转
#define R_ANGLE_L90         0       //向左旋转90度
#define R_ANGLE_R90         1       //向右旋转90度
#define R_ANGLE_180         2       //旋转180度


//Frame position
typedef struct{
    LONGLONG nFilePos;
    long nFrameNum;
    long nFrameTime;
    long nErrorFrameNum;
    SYSTEMTIME *pErrorTime;
    long nErrorLostFrameNum;
    long nErrorFrameSize;
}FRAME_POS,*PFRAME_POS;

//Frame Info
typedef struct{
    long nWidth;
    long nHeight;
    long nStamp;
    long nType;
    long nFrameRate;
    DWORD dwFrameNum;
}FRAME_INFO;

//Frame 
typedef struct{
    char *pDataBuf;
    long  nSize;
    long  nFrameNum;
    BOOL  bIsAudio;
    long  nReserved;
}FRAME_TYPE;

//Watermark Info
typedef struct{
    char *pDataBuf;
    long  nSize;
    long  nFrameNum;
    BOOL  bRsaRight;
    long  nReserved;
}WATERMARK_INFO;

typedef struct SYNCDATA_INFO 
{
    DWORD dwDataType;       //和码流数据同步的附属信息类型，目前有：智能信息，车载信息
    DWORD dwDataLen;        //附属信息数据长度
    BYTE* pData;            //指向附属信息数据结构的指针,比如IVS_INFO结构
} SYNCDATA_INFO;

// 扩展信息结构体
typedef struct
{
    unsigned char        privt_type;                     // 用户扩展类型:详见IVS_PRIVT_INFO，10表示颜色+违禁品类型
    unsigned char        reseverd[6];                    // 目标类型扩展
    unsigned char        privt_len;                      // 用户扩展信息长度
    unsigned char        privt_data[32];                 // 用户扩展信息
}IS_PRIVT_INFO;

// 颜色结构体
typedef struct
{
    unsigned char red;
    unsigned char green;
    unsigned char blue;
    unsigned char alpha;
}IS_PRIVT_INFO_COLOR;

// 违禁物颜色结构体
typedef struct
{
    IS_PRIVT_INFO_COLOR color;                  // 颜色
    unsigned char       confidence;             // 违禁品置信度
    unsigned char       pos_len;                // 违禁品名称长度
    unsigned char       pos_data[22];           // 违禁品名称
    unsigned int        type;                   // 违禁品类型
}IS_PRIVT_INFO_CONTRABAND;

typedef struct _VCA_RECT_F_
{
    float x;         //矩形左上角X轴坐标
    float y;         //矩形左上角Y轴坐标
    float width;     //矩形宽度
    float height;    //矩形高度
}VCA_RECT_F;

//目标信息结构体
typedef struct _VCA_TARGET_EX
{
    unsigned int      ID;          //ID
    unsigned char     reserved[8]; //保留字节
    VCA_RECT_F        rect;        //目标框
    unsigned char     reserved1[40]; //私有信息扩展字段，暂时以unsigned char数组表示，如果外部有需求再告知具体结构与信息
}VCA_TARGET_EX;

typedef struct _VCA_TARGET_LIST_EX
{
    unsigned int    target_num;             //目标数量
    VCA_TARGET_EX   *pstTarget;             //目标内容，按照VCA_TARGET_EX的大小进行偏移读取各个目标具体的信息即可
}VCA_TARGET_LIST_EX;

//智能信息结构体回调用
typedef struct _INTEL_INFO_EX
{
    unsigned int                   type;               ///< 标记回调出了哪些私有信息类型
    VCA_TARGET_LIST_EX             stTarget;           ///< 目标
    VCA_TARGET_LIST_EX             stTarget_EX;        ///< 海康深眸目标
}INTEL_INFO_EX;
/////////////////////////////////////////////////////////////////////////////////////////////
//IVS新智能信息回调接口结构体定义
/////////////////////////////////////////////////////////////////////////////////////////////

///                                目标框                           ///
typedef struct _VCA_POINT_F_
{
    float x;
    float y;
}VCA_POINT_F;

//多边形(浮点型)
typedef struct _VCA_POLYGON_F_
{
    unsigned int  vertex_num;                  //顶点数
    VCA_POINT_F   point[10];   //顶点
}VCA_POLYGON_F;

//旋转矩形
typedef struct _VCA_ROTATE_RECT_F_
{
    float				  cx;						// 矩形中心点X轴坐标
    float				  cy;						// 矩形中心点Y轴坐标
    float				  width;					// 矩形宽度
    float				  height;					// 矩形高度
    float				  theta;				   // 旋转矩形角度
}VCA_ROTATE_RECT_F;

//区域联合体
typedef struct _VCA_REGION_
{
    unsigned int region_type;           // 参考VCA_REGION_TYPE，2表示多边形，3表示矩形
    char         reserved[12];
    union
    {
        unsigned char		size[84];
        VCA_POLYGON_F       polygon;                // 多边形
        VCA_RECT_F          rect;                   // 矩形
        VCA_ROTATE_RECT_F 	rotate_rect;	 		 // 旋转矩形,暂不支持
    };
}VCA_REGION;

//单个目标框结构体
typedef struct 
{
    unsigned int            id;
    unsigned int            blob_type;        // 目标类_OBJ_TYPE
    short                   confidence;       // 目标框置信度
    char                    reserved[14];
    VCA_REGION              region;           // 目标位置区域
    unsigned char           privt_info[40];   // 扩展信息
}HIK_TARGET_BLOB_EX;

//目标框列表信息定义：
typedef struct _VCA_TARGET_LIST_V1_EX_
{
    unsigned int         LineType;      //框类型，0表示矩形框，1表示四角框
    unsigned int         target_num;    //目标数量
    HIK_TARGET_BLOB_EX   *pstTarget;    //目标内容，按照HIK_TARGET_BLOB_EX的大小进行偏移读取各个目标具体的信息即可
}VCA_TARGET_LIST_V1_EX;

///                                规则框                           ///
//单个规则框结构体
typedef struct _VCA_RULE_EX
{
    unsigned char       ID;               //规则ID
    unsigned char       reserved[15];       //保留字节
    VCA_POLYGON_F       polygon;         //规则对应的多边形区域
    unsigned char       privt_info[40];      // 扩展信息
}VCA_RULE_EX;

//规则框列表信息定义：
typedef struct _VCA_RULE_LIST_V3_EX_
{
    unsigned int  LineType;      //框类型，0表示矩形框，1 表示四角框
    unsigned int  rule_num;     //链表中规则数量
    VCA_RULE_EX   *pstRule;   //规则内容，按照VCA_RULE_EX的大小进行偏移读取各个目标具体的信息即可
}VCA_RULE_LIST_V3_EX;

///                                报警框                           ///

typedef struct  _VCA_ALERT_EX_
{
    unsigned char     alert;           //有无报警信息: 0-没有，1-有
    unsigned char     reserved[7];     //保留字节
    VCA_RULE_EX       rule_info;       //报警规则信息
    VCA_TARGET_EX        target;          //报警目标信息
    unsigned char     privt_info[40];  // 扩展信息
}VCA_ALERT_EX;

//报警信息定义：
typedef struct  _VCA_ALERT_LIST_EX_
{
    unsigned int           alert_num;  //报警数量
    VCA_ALERT_EX           *pstAlert; 
}VCA_ALERT_LIST_EX;

//测温信息：
typedef struct  _VCA_INTEL_INFO_
{
	unsigned int   nDataLen;        //附属信息数据长度
	unsigned char  *pData;          //指向附属信息数据结构的指针
}VCA_INTEL_INFO;

typedef struct PlAYM4_TI_OSD_LINT_EX 
{
    unsigned int     nOffsetX;        ///< For the x coordinate of the OSD
    unsigned int     nOffsetY;        ///< For the y coordinate of the OSD
    unsigned short   nLength;         ///< The length of this osd line
    unsigned char    chAlignment;      ///< Horizontal/Vertical Alignment Refers to the relative position of the upper left corner of the string
    unsigned char    chType;          //0xD2表示水印绘制类型
    unsigned char    chRes[16];         //16个保留字节，表示后续的扩展结构体，到绘制时再根据chType进行结构体转换
    unsigned char    chCode[128];    ///<  @Def:    the string on osd. This must be ROUND_UP(strlen(code), 0x10)
}PlAYM4_TI_OSD_LINE_EX;

/**	@struct PlAYM4_TI_OSD_INFO_EX_
 *	@brief  整个文本信息头结构体
 */
typedef struct  PlAYM4_TI_OSD_INFO_EX_
{
	unsigned char           chDepartment;      ///<部门
	unsigned char           chARType;         ///<算法类型
    unsigned char           chRes[14];          //保留字节
    unsigned short          nLanguage;    ///<  @Def:    osd language    
	unsigned short          nColor;       ///<  @Arg:    TI_OSD_COLOR_##
    unsigned int            nLineNum;     ///<  @Def:    OSD line numbers   
    unsigned int            nCharWidth;   ///<  @Def:    Char width of OSD  
	unsigned int            nCharHeight;  ///<  @Def:    Char height of OSD 
	unsigned int            nWinWidth;    ///<  @Def:    Window width of OSD
	unsigned int            nWinHeight;   ///<  @Def:    Window height of OSD
    PlAYM4_TI_OSD_LINE_EX   *pstLine;    ///<  @Def:    This is followed by "nLineNum" in line
}PlAYM4_POS_OSD_INFO_EX;

//智能信息结构体回调用
typedef struct _PRIVATE_INFO_
{
	unsigned int                  type;      ///< 标记回调出了哪些私有信息类型
	VCA_TARGET_LIST_V1_EX         stTarget;           ///< 普通目标框，类型 1
	VCA_TARGET_LIST_V1_EX         stTarget_EX;        ///< 海康深眸目标框，类型 2
	VCA_RULE_LIST_V3_EX           stRule;             ///< 普通规则框，类型 4
	VCA_RULE_LIST_V3_EX           stRule_EX;          ///< 海康深眸规则框，类型 8
	VCA_ALERT_LIST_EX             stAlert;            ///< 报警信息，类型 16
	VCA_INTEL_INFO                stTempInfo;         ///< 测温信息，类型 32
	PlAYM4_POS_OSD_INFO_EX        stPosInfo_EX;       ///< 精确文本POS信息，类型 64
	PlAYM4_POS_OSD_INFO_EX        stPosInfo;          ///< 普通文本POS信息，类型 128
} PRIVATE_INFO;

/////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _HIK_MEDIAINFO_FLAG_
#define _HIK_MEDIAINFO_FLAG_
typedef struct _HIK_MEDIAINFO_
{
    unsigned int    media_fourcc;           // "HKMI": 0x484B4D49 Hikvision Media Information
    unsigned short  media_version;          // 版本号：指本信息结构版本号，目前为0x0101,即1.01版本，01：主版本号；01：子版本号。
    unsigned short  device_id;              // 设备ID，便于分析
    unsigned short  system_format;          // 系统封装层
    unsigned short  video_format;           // 视频编码类型
    unsigned short  audio_format;           // 音频编码类型
    unsigned char   audio_channels;         // 通道数  
    unsigned char   audio_bits_per_sample;  // 样位率
    unsigned int    audio_samplesrate;      // 采样率 
    unsigned int    audio_bitrate;          // 压缩音频码率,单位：bit
    unsigned int    reserved[4];            // 保留
}HIK_MEDIAINFO;
#endif

#ifndef _HIK_STREAM_INFO_FLAG_
#define _HIK_STREAM_INFO_FLAG_
typedef struct _STREAM_INFO_
{
	unsigned short  system_format;          // 系统封装层
	unsigned short  video_format;           // 视频编码类型
	unsigned short  audio_format;           // 音频编码类型
	unsigned char   audio_channels;         // 通道数  
	unsigned char   audio_bits_per_sample;  // 样位率
	unsigned int    audio_samplesrate;      // 采样率 
	unsigned int    audio_bitrate;          // 压缩音频码率,单位：bit
	unsigned int    reserved[10];            // 保留
}STREAM_INFO;
#endif

typedef struct
{
    long nPort;
    char * pBuf;
    long nBufLen;
    long nWidth;
    long nHeight;
    long nStamp;
    long nType;
    void* nUser;
}DISPLAY_INFO;

typedef struct
{
    long nPort;
    char *pVideoBuf;
    long nVideoBufLen;
    char *pPriBuf;
    long nPriBufLen;
    long nWidth;
    long nHeight;
    long nStamp;
    long nType;
    void* nUser;
}DISPLAY_INFOEX;

typedef struct
{
    long         nPort;        //通道号
    char         *pBuf;        //返回的第一路图像数据指针
    unsigned int nBufLen;      //返回的第一路图像数据大小
    char         *pBuf1;       //返回的第二路图像数据指针
    unsigned int nBufLen1;     //返回的第二路图像数据大小
    char         *pBuf2;       //返回的第三路图像数据指针
    unsigned int nBufLen2;     //返回的第三路图像数据大小
    unsigned int nWidth;       //画面宽
    unsigned int nHeight;      //画面高
    unsigned int nStamp;       //时标信息，单位毫秒
    unsigned int nType;        //数据类型
    void         *pUser;       //用户数据
    unsigned int reserved[4];  //保留,reserved[0]保存帧号,res[1]-res[3]保存全局时间，res[1]-年月日，res[2]-时分秒，res[3]-毫秒
}DISPLAY_INFO_YUV;

/** @struct PLAYM4_AUDIODISPLAY_INFO_S
 *  @brief  音频显示信息结构体
 */
typedef struct
{
    unsigned int   uSamplesPerSec; // 采样率
    unsigned int   uChannels;      // 声道数
    unsigned int   uBitsPerSample; // 位率
    int            nFrameNum;      // 帧号
    unsigned int   uFrameTime;     // 时标，单位ms
    unsigned char  reserved[8];
}PLAYM4_AUDIODISPLAY_INFO_S;

// 外部传入图片格式
typedef enum tagPlayM4PicFormat
{
    // 图片格式
    PLAYM4_PIC_JPEG,       ///< JPEG

    // 像素格式
    PLAYM4_PIC_DATA_YV12,       ///< YV12格式
    PLAYM4_PIC_DATA_RGB565,     ///< RGB565格式
    PLAYM4_PIC_DATA_RGBA32      ///< RGBA32格式
}PLAYM4_PIC_FORMAT_E;

// 图片显示模式
typedef enum tagPlayM4PicDisplayMode
{
    PLAYM4_PIC_MODE_REPLACE,       ///< 画面替换模式，将原有画面替换为现传入图片
    PLAYM4_PIC_MODE_OVERLAY        ///< 画面叠加模式，将现传入图片叠加至原有画面上
}PLAYM4_PIC_DISPLAY_MODE_E;

/** @struct    PlayM4_PicRect
 *  @brief     图片叠加区域位置
 */
typedef struct PlayM4_PicRect
{
    float fTopLeftX;    // 左上角x坐标，归一化0-1
    float fTopLeftY;    // 左上角y坐标，归一化0-1
    float fWidth;       // 矩形区域宽，归一化0-1
    float fHeight;      // 矩形区域高，归一化0-1
}PLAYM4_PIC_RECT_S;

/** @struct    PlayM4_PicOverlayParam
 *  @brief     图片叠加参数
 */
typedef struct PlayM4_PicOverlayParam
{
    unsigned int      uAlpha;       // 图像透明度,0-100
    PLAYM4_PIC_RECT_S stPicRect;    // 图片叠加区域位置
    int               nReserved[2];
}PLAYM4_PIC_OVERLAY_PARAM_S;

/** @struct    PLAYM4_PIC_INFO_S
 *  @brief     图片信息
 */
typedef struct PlayM4_PicInfo
{
    unsigned char*             pData;       // 图像数据
    unsigned int               uDataLen;    // 图像数据大小
    unsigned int               uPicWidth;   // 图像宽
    unsigned int               uPicHeight;  // 图像高
    PLAYM4_PIC_FORMAT_E        enPicFormat; // 图像格式
    PLAYM4_PIC_OVERLAY_PARAM_S stPicRect;   // 图片叠加区域位置，仅叠加模式有效
    int                        nReserved[8];
}PLAYM4_PIC_INFO_S;

typedef struct PLAYM4_SYSTEM_TIME //绝对时间
{
    DWORD dwYear;   //年
    DWORD dwMon;    //月
    DWORD dwDay;    //日
    DWORD dwHour;   //时
    DWORD dwMin;    //分
    DWORD dwSec;    //秒
    DWORD dwMs;     //毫秒
} PLAYM4_SYSTEM_TIME;

#ifndef CROP_PIC_INFO_TAG
#define CROP_PIC_INFO_TAG
typedef struct
{
    BYTE  *pDataBuf;      //抓图数据buffer
    DWORD dwPicSize;      //实际图片大小
    DWORD dwBufSize;      //数据buffer大小
    DWORD dwPicWidth;     //截图宽
    DWORD dwPicHeight;    //截图高
    DWORD dwReserve;      //多加一个reserve字段
    RECT  *pCropRect;     //选择区域NULL, 同老的抓图接口
}CROP_PIC_INFO;
#endif

#ifndef MOSAIC_TAG
#define MOSAIC_TAG

typedef struct
{
	unsigned char red;
	unsigned char green;
	unsigned char blue;
	unsigned char alpha;
}IS_INFO_COLOR;

typedef struct _MOSAIC_TYPE_CONFIG_
{
	unsigned char     MosaicType;      //马赛克类型，目前支持4种样式： 1：表示普通马赛克；2表示高斯模糊马赛克，3表示纯色填充马赛克, 4表示目标框加ID显示样式
	IS_INFO_COLOR  MosaicColor;    // 颜色，只有当马赛克类型为3纯色填充时，该颜色才起作用，其他类型不支持颜色设置
	unsigned char   reserved[7];      //四字节对齐，同时用于扩展预留
} MOSAIC_TYPE_CONFIG;

//马赛克目标选择
typedef struct _MOSAIC_NODE_LIST_
{
	unsigned int  nID;  //目标ID
	unsigned int reserved[4]; //保留扩展位
}MOSAIC_NODE_LIST;

typedef struct _MOSAIC_NEED_DRAW_
{
	MOSAIC_NODE_LIST*   pMosaicNode;  //马赛克目标节点指针，根据nMosaicNum个数来偏移读取即可
	unsigned int               NodeNumber;  //节点个数
	unsigned int               reserved[10];  //保留扩展位
} MOSAIC_NEED_DRAW;

#endif

#ifndef PLAYM4_IMAGE_MATTING_TAG
#define PLAYM4_IMAGE_MATTING_TAG

typedef struct _IMAGE_MATTING_INFO_NODE_
{
	unsigned int    nID;             //抠图的目标ID
	unsigned char  *pBuf;            //抠图数据指针
	unsigned int    nBufLen;         //抠图数据大小
	unsigned int    nWidth;          //图片宽
	unsigned int    nHeight;         //图片高
	unsigned char   privt_info[40];  //扩展信息,与IVS最大扩展信息大小保持一致方便后续扩展使用

}IMAGE_MATTING_INFO_NODE;

typedef struct _IMAGE_MATTING_INFO_
{
	IMAGE_MATTING_INFO_NODE*   pNodeData;    //抠图数据信息节点指针，根据NodeNumber个数来偏移读取即可
	unsigned int               NodeNumber;   //抠图数据信息节点个数
	unsigned int               reserved[10];  //保留扩展位

} IMAGE_MATTING_INFO;

typedef struct _IMAGE_MATTING_CONFIG_
{
	unsigned int    TargetType;       //需抠图的私有信息类型设置，1:表示人体 2:表示人脸
	unsigned char   PictureType;      //回调的数据类型，1:表示JPEG;目前只支持回调JPEG格式，后续有需求可以扩展其他方式
	unsigned char   PrivateInfoType;  //需抠图的私有信息类型设置，1:表示IVS目标，目前仅支持IVS目标
	unsigned char   reserved[2];      //四字节对齐，同时用于扩展预留
} IMAGE_MATTING_CONFIG;

#endif

//ENCRYPT Info
typedef struct{
    long nVideoEncryptType;  //视频加密类型
    long nAudioEncryptType;  //音频加密类型
    long nSetSecretKey;      //是否设置，1表示设置密钥，0表示没有设置密钥
}ENCRYPT_INFO;

///<私有信息模块类型
typedef enum _PLAYM4_PRIDATA_RENDER
{
    PLAYM4_RENDER_ANA_INTEL_DATA    = 0x00000001, //智能分析
    PLAYM4_RENDER_MD                = 0x00000002, //移动侦测
    PLAYM4_RENDER_ADD_POS           = 0x00000004, //POS信息后叠加
    PLAYM4_RENDER_ADD_PIC           = 0x00000008, //图片叠加信息
    PLAYM4_RENDER_FIRE_DETCET       = 0x00000010, //热成像信息
    PLAYM4_RENDER_TEM               = 0x00000020, //温度信息
    PLAYM4_RENDER_TRACK_TEM         = 0x00000040, //目标移动路径信息
    PLAYM4_RENDER_THERMAL           = 0x00000080, //废气检测和烟火屏蔽信息
}PLAYM4_PRIDATA_RENDER;

typedef enum _PLAYM4_THERMAL_FLAG
{
	PLAYM4_THERMAL_FIREMASK           = 0x00000001, //烟火屏蔽
	PLAYM4_THERMAL_RULEGAS            = 0x00000002, //规则废气检测（气体报警规则检测复用规则废气）
	PLAYM4_THERMAL_TARGETGAS          = 0x00000004, //目标废气检测
	PLAYM4_THERMAL_ALERTTARGETGAS     = 0x00000008, //气体报警目标检测
    PLAYM4_THERMAL_ISA                = 0x00000010, //绝缘子信息检测
}PLAYM4_THERMAL_FLAG;

typedef enum _PLAYM4_FIRE_ALARM
{
    PLAYM4_FIRE_FRAME_DIS           = 0x00000001, //火点框显示
    PLAYM4_FIRE_MAX_TEMP            = 0x00000002, //最高温度
    PLAYM4_FIRE_MAX_TEMP_POSITION   = 0x00000004, //最高温度位置显示
    PLAYM4_FIRE_DISTANCE            = 0x00000008, //最高温度距离
}PLAYM4_FIRE_ALARM;

typedef enum _PLAYM4_TEM_FLAG
{
    PLAYM4_TEM_REGION_BOX             = 0x00000001, //框测温
    PLAYM4_TEM_REGION_LINE            = 0x00000002, //线测温
    PLAYM4_TEM_REGION_POINT           = 0x00000004, //点测温
}PLAYM4_TEM_FLAG;

typedef enum _PLAYM4_TRACK_FLAG
{
    PLAYM4_TRACK_PEOPLE               = 0x00000001, //人移动路径
    PLAYM4_TRACK_VEHICLE              = 0x00000002, //车移动路径
}PLAYM4_TRACK_FLAG;

typedef enum _PLAYM4_INTEL_DATA_FLAG
{
	PLAYM4_INTEL_DATA_TARGET           = 0x00000001, //目标框
	PLAYM4_INTEL_DATA_CONTRABAND       = 0x00000002, //违禁品名称显示
	PLAYM4_INTEL_DATA_FACE             = 0x00000004, //马赛克人脸框
	PLAYM4_INTEL_DATA_BODY             = 0x00000008, //马赛克人体框
}PLAYM4_INTEL_DATA_FLAG;

/////////////////////////////////////////////////////////////////////////////////////////////
//Proposed Interface 建议使用的接口
/////////////////////////////////////////////////////////////////////////////////////////////
///<初始化
PLAYM4_API BOOL __stdcall PlayM4_GetPort(LONG* nPort);
PLAYM4_API BOOL __stdcall PlayM4_FreePort(LONG nPort);
PLAYM4_API BOOL __stdcall PlayM4_OpenFile(LONG nPort,LPSTR sFileName);
PLAYM4_API BOOL __stdcall PlayM4_CloseFile(LONG nPort);
PLAYM4_API BOOL __stdcall PlayM4_OpenStream(LONG nPort,PBYTE pFileHeadBuf,DWORD nSize,DWORD nBufPoolSize);
PLAYM4_API BOOL __stdcall PlayM4_CloseStream(LONG nPort);
PLAYM4_API BOOL __stdcall PlayM4_InputData(LONG nPort,PBYTE pBuf,DWORD nSize);
PLAYM4_API BOOL __stdcall PlayM4_SetStreamOpenMode(LONG nPort,DWORD nMode);
PLAYM4_API LONG __stdcall PlayM4_GetStreamOpenMode(LONG nPort);

// 需求背景：前置索引mp4的索引大小有大于4M的情况导致探测失败，故增加配置接口；
// 设置流式探测门限值
// 此接口需要在getport后，openstream开流前调用，否则报错
// nBufLen代表探测门限值长度，默认4M，最大不超过128M
PLAYM4_API BOOL __stdcall PlayM4_SetCheckHeadBufLen(LONG nPort, DWORD nBufLen, void* nReserved);

///<索引
PLAYM4_API BOOL __stdcall PlayM4_SetFileRefCallBack(LONG nPort, void (__stdcall *pFileRefDone)(DWORD nPort,void* nUser),void* nUser);
PLAYM4_API BOOL __stdcall PlayM4_GetRefValue(LONG nPort,BYTE *pBuffer, DWORD *pSize);
PLAYM4_API BOOL __stdcall PlayM4_SetRefValue(LONG nPort,BYTE *pBuffer, DWORD nSize);
PLAYM4_API BOOL __stdcall PlayM4_GetRefValueEx(LONG nPort,BYTE *pBuffer, DWORD *pSize);///< 与PlayM4_GetRefValueEx相比，增加索引帧类型和长度回调
PLAYM4_API BOOL __stdcall PlayM4_GetKeyFramePos(LONG nPort,DWORD nValue, DWORD nType, PFRAME_POS pFramePos);
PLAYM4_API BOOL __stdcall PlayM4_GetNextKeyFramePos(LONG nPort,DWORD nValue, DWORD nType, PFRAME_POS pFramePos);

///<播放控制
PLAYM4_API BOOL __stdcall PlayM4_Play(LONG nPort, HWND hWnd);
PLAYM4_API BOOL __stdcall PlayM4_Stop(LONG nPort);
PLAYM4_API BOOL __stdcall PlayM4_Pause(LONG nPort,DWORD nPause);
PLAYM4_API BOOL __stdcall PlayM4_Fast(LONG nPort);
PLAYM4_API BOOL __stdcall PlayM4_Slow(LONG nPort);
PLAYM4_API BOOL __stdcall PlayM4_OneByOne(LONG nPort);
PLAYM4_API BOOL __stdcall PlayM4_OneByOneBack(LONG nPort);
PLAYM4_API BOOL __stdcall PlayM4_ReversePlay(LONG nPort);
PLAYM4_API BOOL __stdcall PlayM4_RefreshPlay(LONG nPort);
PLAYM4_API BOOL __stdcall PlayM4_RefreshPlayEx(LONG nPort,DWORD nRegionNum);
PLAYM4_API BOOL __stdcall PlayM4_OpenAudioStretchPlay(LONG nPort, BOOL nEnable);
PLAYM4_API int  __stdcall PlayM4_SetStretchPlay(long nPort, unsigned int nMillisecond, float fSpeed);

PLAYM4_API int  __stdcall PlayM4_SetDelayPlayTime(long nPort, unsigned int nMillisecond);

PLAYM4_API BOOL __stdcall PlayM4_IdleAutoRefreshEx(long nPort, unsigned int nEnable, unsigned int nWaitTime, unsigned int nStreamType);

PLAYM4_API BOOL __stdcall PlayM4_PlayAudioWaveform(LONG nPort, HWND hWnd, void* nReserved);
PLAYM4_API BOOL __stdcall PlayM4_RegisterAudioDrawFun(LONG nPort,void (CALLBACK* DrawFun)(long nPort,HDC hDc,void* nUser),void* nUser);

typedef enum _PLAYM4_REVERSE_PLAY_MODE
{
    PLAYM4_REVERSE_PLAY_NOMAL  = 0,        //播放库默认倒放模式，实现方式同PlayM4_ReversePlay，此时nValue值无意义
    PLAYM4_REVERSE_PLAY_TIME   = 1,        //文件播放时，按相对时间定位到指定位置进行倒放，此时nValue值表示时间，单位是毫秒

}PLAYM4_REVERSE_PLAY_MODE;

PLAYM4_API int __stdcall PlayM4_ReversePlayEX(long nPort, unsigned int nValue, PLAYM4_REVERSE_PLAY_MODE emType, void* pReserved);

// 音频波形底图类型
#define  PLAYM4_MODE_TIME      1   //时域曲线类型
#define  PLAYM4_MODE_FREQ      2   //频域曲线类型
#define  PLAYM4_MODE_TIME_FREQ 3   //时频域曲线类型

// 设置外部图片叠加显示
// 1.支持传入3种类型的音频波形底图，时域曲线类型-1、频域曲线类型-2、时频域曲线类型-3
//   PLAYM4_PIC_INFO_S结构体扩展字节第一个字节作为底图类型字段;
// 2.支持画面覆盖、局部叠加两种模式，传递音频波形底图时，enPicDisplayMode参数不生效；
// 3.外部传入图片格式为jpeg时，内部获取宽高信息，外部传入宽高不使用；
// 4.内部会保存已传底图，bEnable即可控制显示开关;
// 5.画面覆盖模式暂不支持硬解码，局部叠加支持软硬解;
// 6.局部叠加模式，YV12、JPEG图片的局部叠加需开启D3D11，RGBA32和RGB565不需要，且该模式下D3D9叠加不支持透明度；
// 7.暂停过程中接口调用不会生效，需要恢复播放才能生效。
PLAYM4_API BOOL __stdcall PlayM4_OverlayPicture(long nPort,PLAYM4_PIC_INFO_S* pstPicInfo,PLAYM4_PIC_DISPLAY_MODE_E enPicDisplayMode,bool bEnable,void* nReserved);

typedef struct
{
	int   nBitrate;    //码率
	int   nDelayTime;  //延时值，单位毫秒
	int   nReserved[4];
}PLAYM4_AUTOSMOOTHPLAYPARAM;

//设置自适应平滑播放
//默认3秒延时，缓存大小默认为8M
//如后续特殊现场延时较大超过阈值时可通过nReserved配置PLAYM4_AutoSmoothPlayParam结构体，目前暂未启用
PLAYM4_API BOOL  __stdcall PlayM4_SetAutoSmoothPlay(LONG nPort, BOOL nEnable, void* nReserved);


#define PLAY_BACK_ACCURACY     1       //正倒放切换，精确模式
#define PLAY_BACK_NORMAL       2       //正倒放切换，非精确模式

//设置正倒放切换模式
//nMode值: 
// 1 表示正倒放切换期间的精确模式，即会将正/倒放切换前和切换后的时间戳进行对比，保证正/倒放切换前后画面的精确衔接，不跳帧；
// 2 表示正倒放切换期间的非精确模式，即切换后来了码流直接播放；
// 3 表示切换为倒放状态后的非精确模式，即码流直接播放，需要在切换为倒放后调用
PLAYM4_API BOOL __stdcall PlayM4_SetPlayOrBackSwitchMode(LONG nPort,DWORD nMode);

///<声音播放
PLAYM4_API BOOL __stdcall PlayM4_PlaySound(LONG nPort);
PLAYM4_API BOOL __stdcall PlayM4_StopSound();
PLAYM4_API BOOL __stdcall PlayM4_PlaySoundShare(LONG nPort);
PLAYM4_API BOOL __stdcall PlayM4_StopSoundShare(LONG nPort);
PLAYM4_API BOOL __stdcall PlayM4_SetVolume(LONG nPort,WORD nVolume);
PLAYM4_API WORD __stdcall PlayM4_GetVolume(LONG nPort);
PLAYM4_API BOOL __stdcall PlayM4_AdjustWaveAudio(LONG nPort,LONG nCoefficient);
PLAYM4_API BOOL	__stdcall PlayM4_SetANRParam(LONG nPort, BOOL nEnable, int nANRLevel);

///<获取信息
PLAYM4_API BOOL __stdcall PlayM4_SetPlayPos(LONG nPort,float fRelativePos);
PLAYM4_API float __stdcall PlayM4_GetPlayPos(LONG nPort);
PLAYM4_API DWORD __stdcall PlayM4_GetFileTime(LONG nPort);
PLAYM4_API DWORD __stdcall PlayM4_GetPlayedTime(LONG nPort);
PLAYM4_API DWORD __stdcall PlayM4_GetPlayedFrames(LONG nPort);
PLAYM4_API DWORD __stdcall PlayM4_GetFileTotalFrames(LONG nPort);
PLAYM4_API DWORD __stdcall PlayM4_GetCurrentFrameRate(LONG nPort);
PLAYM4_API DWORD __stdcall PlayM4_GetPlayedTimeEx(LONG nPort);
PLAYM4_API BOOL __stdcall PlayM4_SetPlayedTimeEx(LONG nPort,DWORD nTime);
PLAYM4_API DWORD __stdcall PlayM4_GetCurrentFrameNum(LONG nPort);
PLAYM4_API BOOL __stdcall PlayM4_SetCurrentFrameNum(LONG nPort,DWORD nFrameNum);
PLAYM4_API BOOL __stdcall PlayM4_GetSystemTime(LONG nPort, PLAYM4_SYSTEM_TIME *pstSystemTime);
PLAYM4_API DWORD __stdcall PlayM4_GetSpecialData(LONG nPort);
PLAYM4_API DWORD __stdcall PlayM4_GetAudioSpecialData(LONG nPort);
PLAYM4_API BOOL __stdcall PlayM4_GetPictureSize(LONG nPort,LONG *pWidth,LONG *pHeight);
PLAYM4_API BOOL __stdcall PlayM4_SetFileEndCallback(LONG nPort, void(CALLBACK*FileEndCallback)(long nPort, void *pUser), void *pUser);
PLAYM4_API BOOL __stdcall PlayM4_GetFileTotalTime(LONG nPort, PLAYM4_SYSTEM_TIME *pstBegin, PLAYM4_SYSTEM_TIME *pstStop);
///<时区的表示以秒为单位，东区为正，西区为负
PLAYM4_API BOOL __stdcall PlayM4_SetSupplementaryTimeZone(int nPort, int nTimeZone); 
///<若已经设置时区则返回设置时区，否则失败
PLAYM4_API BOOL __stdcall PlayM4_GetSupplementaryTimeZone(int nPort, int* pTimeZone); 
///<获取时区信息
PLAYM4_API int __stdcall PlayM4_GetTimeZoneInfo(long nPort, int* pTimeZone);
//获取封装和编码类型
PLAYM4_API int __stdcall PlayM4_GetStreamInfo(long nPort, int* pSysFormat, int* pCodeType);
///<缓存操作
PLAYM4_API DWORD __stdcall PlayM4_GetSourceBufferRemain(LONG nPort);
PLAYM4_API BOOL __stdcall PlayM4_ResetSourceBuffer(LONG nPort);
PLAYM4_API BOOL __stdcall PlayM4_SetSourceBufCallBack(LONG nPort,DWORD nThreShold,void (CALLBACK * SourceBufCallBack)(long nPort,DWORD nBufSize,void* dwUser,void*pResvered),void* dwUser,void *pReserved);
PLAYM4_API BOOL __stdcall PlayM4_ResetSourceBufFlag(LONG nPort);
PLAYM4_API BOOL __stdcall PlayM4_ResetBuffer(LONG nPort,DWORD nBufType);
PLAYM4_API DWORD __stdcall PlayM4_GetBufferValue(LONG nPort,DWORD nBufType);
PLAYM4_API BOOL __stdcall PlayM4_SetDisplayBuf(LONG nPort,DWORD nNum);
PLAYM4_API DWORD __stdcall PlayM4_GetDisplayBuf(LONG nPort);

//此接口软解下可设置25~100个，硬解下只可以设置25~50个，超过50个设置可成功但内部最大50个
PLAYM4_API BOOL __stdcall PlayM4_SetReverseDecodeBuf(LONG nPort,DWORD nNum);

///<抓图
PLAYM4_API BOOL __stdcall PlayM4_SetJpegQuality(long nQuality);
PLAYM4_API BOOL __stdcall PlayM4_GetBMP(LONG nPort,PBYTE pBitmap,DWORD nBufSize,DWORD* pBmpSize);
PLAYM4_API BOOL __stdcall PlayM4_GetJPEG(LONG nPort,PBYTE pJpeg,DWORD nBufSize,DWORD* pJpegSize);
PLAYM4_API BOOL __stdcall PlayM4_ConvertToBmpFile(char * pBuf,long nSize,long nWidth,long nHeight,long nType,char *sFileName);
PLAYM4_API BOOL __stdcall PlayM4_ConvertToJpegFile(char * pBuf,long nSize,long nWidth,long nHeight,long nType,char *sFileName);

///< 设置解析模式
// nIdemuxType: 1 表示编码层断帧,2表示输出I帧前数据，4表示关闭编码检测
PLAYM4_API BOOL __stdcall PlayM4_SetDemuxModel(LONG nPort, unsigned int nIdemuxType, BOOL bTrue);
PLAYM4_API BOOL __stdcall PlayM4_SetIdemuxPara(LONG nPort, int nChunkSize);

///<解码
PLAYM4_API BOOL __stdcall PlayM4_SetSecretKey(LONG nPort, LONG lKeyType, char *pSecretKey, LONG lKeyLen);
PLAYM4_API BOOL __stdcall PlayM4_ThrowBFrameNum(LONG nPort,DWORD nNum);
PLAYM4_API BOOL __stdcall PlayM4_SetDecCBStream(LONG nPort,DWORD nStream);
PLAYM4_API BOOL __stdcall PlayM4_SetDecodeFrameType(LONG nPort,DWORD nFrameType);
PLAYM4_API BOOL __stdcall PlayM4_CheckDiscontinuousFrameNum(LONG nPort, BOOL bCheck);
PLAYM4_API BOOL __stdcall PlayM4_SkipErrorData(LONG nPort, BOOL bSkip);
//设置差错隐藏等级-等级越高，越耗性能 nLevel范围[1,2],一般设置1即可
PLAYM4_API BOOL __stdcall PlayM4_SetDecodeERC(long nPort, unsigned int nLevel);
//设置差错隐藏等级-等级越高，越耗性能 nLevel范围[1,2],一般设置1即可，花屏百分比参数-低于该百分比的花屏帧不被输出
PLAYM4_API BOOL __stdcall PlayM4_SetDecodeERCEx(long nPort, unsigned int nLevel, unsigned int nDisplayErrPercentage, int nReserved);
PLAYM4_API BOOL __stdcall PlayM4_SetDecCallBackMend(LONG nPort,void (CALLBACK* DecCBFun)(long nPort,char * pBuf,long nSize,FRAME_INFO * pFrameInfo, void* nUser,void* nReserved2), void* nUser);
PLAYM4_API BOOL __stdcall PlayM4_SetDecCallBackExMend(LONG nPort, void (CALLBACK* DecCBFun)(long nPort, char* pBuf, long nSize, FRAME_INFO* pFrameInfo, void* nUser, void* nReserved2), char* pDest, long nDestSize, void* nUser);
// 加密码流回调,nType=0表示码流加密标记位发生变化就回调，nType=1表示码流有加密位发生回调-只回调一次
PLAYM4_API BOOL __stdcall PlayM4_SetEncryptTypeCallBack(LONG nPort, DWORD nType, void (CALLBACK* EncryptTypeCBFun)(long nPort, ENCRYPT_INFO* pEncryptInfo, void* nUser, long nReserved2), void* nUser);
//nType为0每次都回调，nType为1只回调一次
PLAYM4_API BOOL __stdcall PlayM4_SetStreamInfoCallBack(LONG nPort, DWORD nType, void (CALLBACK* StreamInfoTypeCBFun)(long nPort, STREAM_INFO* pStreamInfo, void* nUser, long nReserved), void* nUser);

//解码或显示回调中绝对时间戳（帧号）或相对时间戳（帧号）的回调设置;
// nModule 表示回调模块选择，0 表示默认解码回调和显示回调 1：表示解码回调，2：表示显示回调；3：表示IVS回调
// nType 表示回调绝对时间戳（帧号）还是相对时间戳（帧号）的类型设置，0：表示回调相对时间戳和相对帧号 1: 表示回调绝对时间戳和绝对帧号
//显示回调是没有帧号回调的，所以显示回调下 0：表示回调相对时间戳 1: 表示回调绝对时间戳
PLAYM4_API BOOL __stdcall PlayM4_SetDecOrDisplayCallbackType(int nPort, int nModule, int nType);

// 设置音频显示回调接口，回调送进音频渲染的PCM数据，和相应的音频显示信息
PLAYM4_API BOOL __stdcall PlayM4_SetAudioDisplayCallBack(LONG lPort, 
                                                         void (CALLBACK *pfnAudioDisplayCB)(LONG lPort, const unsigned char* pData, const unsigned int uDataSize, const PLAYM4_AUDIODISPLAY_INFO_S* pstAudioDisplay,void* pUser), 
                                                         void* pUser);

// 设置显示Scale类型，scale：1表示按视频宽高显示；0表示铺满窗口
#define PLAYM4_ENUM_SCALE_FILL 0
#define PLAYM4_ENUM_SCALE_FIT  1
PLAYM4_API BOOL __stdcall PlayM4_SetScaleType(int nPort, int nScaleType);

#define YUV_RGB24			        1		///<rgb类型
#define YUV_YUYV			     	2		///<YUYV类型
#define YUV_YV12					3		///<YV12类型,播放库默认类型
#define YUV_NV12			     	4		///<NV12类型

//nMode 表示缩放比例，0表示不进行缩放，原分辨率输出;大于0时，nMode的高2字节表示宽，低2字节表示高，且要求高和宽都必须大于128且小于8192
PLAYM4_API  int __stdcall PlayM4_SetYUVCallBackType(LONG nPort, DWORD nType, DWORD nMode);

///< YUV 数据显示回调接口，支持硬解码的surface转yuv数据回调，参数bTrue表示多路流否需要拼接后再回调，当bTrue == 1时表示需要内部拼接，
//当bTrue == 0时表示不需要内部拼接，各路流分别回调出去；注意：对于碗型鹰眼码流只会回调第一路出去，不支持碗型鹰眼的两路流拼接回调；
PLAYM4_API BOOL __stdcall PlayM4_SetDisplayCallBackYUV(LONG nPort, void (CALLBACK* DisplayCBFun)(DISPLAY_INFO_YUV *pstDisplayInfo), BOOL bTrue, void* pUser);
PLAYM4_API BOOL __stdcall PlayM4_SetSmartFirstKeyFrameDisplay(long nPort, unsigned int nFlag, void* nReserved);


//nInterval表示回调间隔，每间隔nInterval帧触发一次YUV回调；nInterval为0表示取消间隔回调，恢复成每帧都回调
PLAYM4_API  int __stdcall PlayM4_SetYUVCallBackInterval(LONG nPort, DWORD nInterval, void* pReserved);

///<显示
PLAYM4_API BOOL __stdcall PlayM4_SetDisplayRegion(LONG nPort,DWORD nRegionNum, RECT *pSrcRect, HWND hDestWnd, BOOL bEnable);///<电子放大
PLAYM4_API BOOL __stdcall PlayM4_SetDisplayRegionOnWnd(LONG nPort,DWORD nRegionNum, RECT *pSrcRect, BOOL bEnable);///<多窗口分割
PLAYM4_API BOOL __stdcall PlayM4_SetDisplayType(LONG nPort,LONG nType);
PLAYM4_API long __stdcall PlayM4_GetDisplayType(LONG nPort);
PLAYM4_API BOOL __stdcall PlayM4_SetDisplayCallBack(LONG nPort,void (CALLBACK* DisplayCBFun)(long nPort,char * pBuf,long nSize,long nWidth,long nHeight,long nStamp,long nType,void* nReserved));
PLAYM4_API BOOL __stdcall PlayM4_SetDisplayCallBackEx(LONG nPort,void (CALLBACK* DisplayCBFun)(DISPLAY_INFO *pstDisplayInfo), void* nUser);
PLAYM4_API BOOL __stdcall PlayM4_RegisterDrawFun(LONG nPort,void (CALLBACK* DrawFun)(long nPort,HDC hDc,void* nUser),void* nUser);
PLAYM4_API BOOL __stdcall PlayM4_SetEncTypeChangeCallBack(LONG nPort,void(CALLBACK *funEncChange)(long nPort,void* nUser),void* nUser);
PLAYM4_API BOOL __stdcall PlayM4_SetCheckWatermarkCallBack(LONG nPort,void(CALLBACK* funCheckWatermark)(long nPort,WATERMARK_INFO* pWatermarkInfo,void* nUser),void* nUser);
PLAYM4_API BOOL __stdcall PlayM4_RenderPrivateData(LONG nPort, int nIntelType, BOOL bTrue);
PLAYM4_API BOOL __stdcall PlayM4_RenderPrivateDataEx(LONG nPort, int nIntelType, int nSubType, BOOL bTrue);
PLAYM4_API BOOL __stdcall PlayM4_SetOverlayPriInfoFlag(LONG nPort, int nIntelType, BOOL bTrue);
PLAYM4_API BOOL __stdcall PlayM4_SetTrackDurationTime(LONG nPort, int nTime);
//lType: 1 表示获取当前显示帧PTZ信息。以特定结构体形式存储在pInfo内，plLen返回长度信息;起先传入pInfo = null，可以获取出需要分配的内存长度plLen
PLAYM4_API BOOL __stdcall PlayM4_GetStreamAdditionalInfo(LONG nPort, LONG lType, BYTE* pInfo, LONG* plLen);

//私有信息回调接口，nType表示需要回调的私有信息类型，目前支持两种类型: 普通目标框：1; 海康深眸目标框； 2; 支持输入 1|2 的形式，即输入3表示两种类型都会回调
PLAYM4_API BOOL __stdcall PlayM4_RegisterIVSDrawFunCB_EX(long nPort, void (CALLBACK* IVSDrawFun)(long nPort, HDC hDC, FRAME_INFO* pFrameInfo, INTEL_INFO_EX* pSyncData, void*  dwUser), void*  dwUser, unsigned int nType);

//私有信息回调接口,nStamp表示相对时间戳信息；pSyncData表示私有信息内容, nType表示需要回调的私有信息类型，支持多个私有信息类型一起设置，
//比如当nType等于6表示外部需要回调海康深眸目标框和普通规则框，此时播放库只会回调这两种类型，如果都需要回调则直接设置nType等于0即可，此时默认智能信息结构体里的信息都会回调；
//nMode表示回调注册的模式(用于接口的功能扩展)，目前支持0和1两种模式，其中，0模式表示解码后立刻回调，播放库内部不进行和视频帧的匹配，也不会回调HDC; 1模式表示回调和当前显示视频帧匹配成功的私有帧
//此接口设置解码后回调时将回调全部解码正确的IVS私有信息，且每种类型独立回调；设置匹配后回调时将只回调与视频帧匹配上的IVS私有信息，没匹配上的类型回调值为0，且匹配上的类型将以或的形式一起回调
PLAYM4_API BOOL __stdcall PlayM4_RegisterIVSIntelInfoCB(LONG nPort, void (CALLBACK* IVSIntelInfoCBFun)(LONG nPort, HDC hDC, LONG nStamp, PRIVATE_INFO* pSyncData, void*  dwUser), void* dwUser, DWORD nType, DWORD nMode);

typedef struct _DB_INFO_NODE_
{
	float fDbValue;					//该采样点的BD值
	bool  bPlusFlag;				//正数 1（坐标轴上方），负数0（坐标轴下方）
	unsigned char  unReserved[3];	//保证四字节对齐

}DBINFONODE;

typedef struct _OUTPUT_DB_INFO_
{
	DBINFONODE* pNodeDataBuffer;
	unsigned int dwDataLen;
    unsigned int nAvgAudioDBValue;  // 一帧音频数据平均幅值的DB值
    unsigned int nReserverd[9];	//保留扩展位

}OUTPUTDBINFO;
///< 音频数据分贝值回调
PLAYM4_API BOOL __stdcall PlayM4_RegisterAudioPlayDBCallBack(LONG nPort, void (CALLBACK* AudioDBCBFun)(long nPort, OUTPUTDBINFO* pstDBInfo, void* pUser), void* pUser);
//nMode表示回调注册的模式(用于接口的功能扩展)，目前支持0和1两种模式，其中，0模式表示解码后回调，1表示渲染后回调
PLAYM4_API BOOL __stdcall PlayM4_RegisterAudioPlayDBCallBackEx(LONG nPort, void (CALLBACK* AudioDBCBFun)(long nPort, OUTPUTDBINFO* pstDBInfo, void* pUser), void* pUser, DWORD nMode, void* nReserved);

///<图像处理
PLAYM4_API BOOL __stdcall PlayM4_SetColor(LONG nPort, DWORD nRegionNum, int nBrightness, int nContrast, int nSaturation, int nHue);
PLAYM4_API BOOL __stdcall PlayM4_GetColor(LONG nPort, DWORD nRegionNum, int *pBrightness, int *pContrast, int *pSaturation, int *pHue);
PLAYM4_API BOOL __stdcall PlayM4_SetImageSharpen(LONG nPort,DWORD nLevel);
PLAYM4_API BOOL __stdcall PlayM4_SetRotateAngle(LONG nPort, DWORD nRegionNum, DWORD dwType);

// 使用背景：设备马赛克海康深眸目标框时间戳不准，故增加补帧接口
// 设置私有信息补帧接口
// 支持按使用次数方式补帧，FrameInterpolationType设置0，当设置这种方式时，需要设置具体的nIntelType值，也需要设置具体的nUsedNum值；
// 支持自动方式补帧，FrameInterpolationType设置1，当设置这种方式时，nIntelType值设置0，nUsedNum值设置0，仅需要设置nFlag开启关闭，播放库自动补帧（针对普通目标框、海康深眸目标框、海康深眸POS），最大补帧帧率为5；
// nIntelType代表私有信息类型，支持海康深眸目标框，类型为2；普通目标框，类型为1；海康深眸POS信息，类型为64；
// nFlag代表开启关闭，0表示关闭补帧，1表示开启补帧，默认关闭

#ifndef FRAME_INTERPOLATION_INFO_TAG
#define FRAME_INTERPOLATION_INFO_TAG

typedef struct
{
	unsigned int          FrameInterpolationType;     //补帧方式
	unsigned int          nUsedNum;                   //使用次数，默认为3
	unsigned int          reserved[4];                //保留字节
}FrameInterpolationInfo;

#endif
PLAYM4_API BOOL __stdcall PlayM4_SetPrivateFrameInterpolation(int nPort, unsigned int nIntelType, unsigned int nFlag, FrameInterpolationInfo* pManualDrawInfo);

///<其他
PLAYM4_API DWORD __stdcall PlayM4_GetFileHeadLength();
PLAYM4_API DWORD __stdcall PlayM4_GetSdkVersion();
PLAYM4_API DWORD __stdcall PlayM4_GetLastError(LONG nPort);
PLAYM4_API BOOL __stdcall PlayM4_SetSycGroup(LONG nPort, DWORD dwGroupIndex);
PLAYM4_API BOOL __stdcall PlayM4_MotionFlow(LONG nPort, DWORD dwAdjustType);

///< 设置音频显示线程模式 true：音频线程分离模式； false： 音视频显示在同一线程模式
PLAYM4_API BOOL __stdcall PlayM4_SetAudioThreadModel(LONG nPort, BOOL bModel);

// 根据相对时间获取MP4封装在线定位偏移
PLAYM4_API int __stdcall PlayM4_GetMpOffset(int nPort, int nTime, int* nOffset);

///< 同步回放相关功能
// 同步回放相关接口，以同步组作为参数，控制整个同步组的所有通道
PLAYM4_API BOOL __stdcall PlayM4_SYNC_Play(unsigned int nGroupIndex);
PLAYM4_API BOOL __stdcall PlayM4_SYNC_ReversePlay(unsigned int nGroupIndex);
PLAYM4_API BOOL __stdcall PlayM4_SYNC_Pause(unsigned int nGroupIndex,unsigned int nPause);
PLAYM4_API BOOL __stdcall PlayM4_SYNC_OneByone(unsigned int nGroupIndex);
PLAYM4_API BOOL __stdcall PlayM4_SYNC_Fast(unsigned int nGroupIndex);
PLAYM4_API BOOL __stdcall PlayM4_SYNC_Slow(unsigned int nGroupIndex);
PLAYM4_API BOOL __stdcall PlayM4_SYNC_ResetBuffer(unsigned int nGroupIndex,unsigned long nBufType);
PLAYM4_API BOOL __stdcall PlayM4_SYNC_SetDecodeFrameType(unsigned int nGroupIndex,unsigned long nFrameType);

// 同步回放接口获取错误码，通过指针偏移出错通道数，读取对应port和错误码
typedef struct tagPlayM4SyncGroupError
{
    int* pErrPort;      // 出错通道号指针
    int* pErrCode;      // 出错通道错误码指针
    int  nErrPortNum;   // 出错通道数
    int  nRsv[5];
}PLAYM4_SYNC_GROUP_ERROR_S;
PLAYM4_API BOOL __stdcall PlayM4_SYNC_GetLastError(unsigned int nGroupIndex,PLAYM4_SYNC_GROUP_ERROR_S& stSyncGroupError);

// 同步回放场景，客户端左向拖动进度条定位时，全局时间的update状态会导致点位依次reset，画面更新不同步，此接口用于设置update状态时的同步reset，避免依次reset导致的画面更新不同步的现象
// 调用逻辑：客户端在同步回放进行定位操作时，先调用此接口再定位，目前该接口解决左向定位时画面更新不同步的问题，右向定位不受影响，后续对此接口有其他功能需求，可考虑扩展字段。
PLAYM4_API BOOL __stdcall PlayM4_NotifySyncPosition(long nPort,void* nReserved);

/** @struct PLAYM4_AUDIOSSTREAM_INFO_S
 *  @brief  音频流信息结构体
 */
typedef struct
{
    unsigned char*      pData;          // PCM数据
    unsigned int        uDataLen;       // PCM数据长度
    unsigned int        uSamplesPerSec; // 采样率
    unsigned int        uChannels;      // 声道数
    unsigned int        uBitsPerSample; // 位率
    unsigned int        uFrameTime;     // 相对时间戳
    unsigned int        uAbsFrameTime;  // 绝对时间戳
    int                 nFrameNum;      // 相对帧号(功能扩展用)
    int                 nAbsFrameNum;   // 绝对帧号(功能扩展用)
    OUTPUTDBINFO        stDBInfo;       // DB值信息
    PLAYM4_SYSTEM_TIME  stSystemTime;  // 全局时间(纯音频场景)
    int                 reserved[8];    // 扩展字段
}PLAYM4_AUDIOSSTREAM_INFO_S;

// 音频流信息回调接口，统一回调所有音频相关的数据和信息，通过参数完成相关配置：
// 1.支持配置音频回调的模式，是否渲染、是否降噪；
// 2.支持配置音频回调的信息，音频帧信息、PCM数据、DB值、(纯音频)全局时间；
// 3.支持配置音频回调的模块，解码模块、渲染模块；
// 4.支持后续新增功能信息回调扩展。

// nCBMode：配置音频回调模式，按位传值配置模式，如配置回调音频开启渲染和降噪，则该值传：PLAYM4_AUDIOCB_DISPLAY_MODE|PLAYM4_AUDIOCB_ANR_MODE
// nCBMode值：0-关闭所有配置（不渲染不降噪等），对应位取值宏定义：
#define    PLAYM4_AUDIOCB_DISPLAY_MODE (1 << 0)  // nCBMode第0位-音频回调开启渲染
#define    PLAYM4_AUDIOCB_ANR_MODE     (1 << 1)  // nCBMode第1位-音频回调开启降噪（暂不支持，后续增加）

// nCBInfo：配置音频回调信息，按位传值配置信息，如配置回调音频PCM数据和DB值，则该值传入：PLAYM4_AUDIO_PCM|PLAYM4_AUDIO_DB
// nCBInfo值：0-仅回调音频帧信息，对应位取值宏定义：
#define    PLAYM4_AUDIO_PCM    (1 << 0)     // nCBInfo第0位-音频回调PCM数据
#define    PLAYM4_AUDIO_DB     (1 << 1)     // nCBInfo第1位-音频回调DB值（暂不支持，后续增加）

// nCBModule：配置音频回调模块，该参数决定回调PCM数据的模块
// 0-音频解码模块，PCM数据解码后回调
// 1-音频渲染模块，PCM数据渲染前回调

// 注：
// 1.回调音频数据前，需调用接口PlayM4_PlaySound开启音频播放；
// 2.PlayM4_PlaySound，PlayM4_PlaySoundShare接口调用后，音频数据才会解码、渲染，回调才会生效，否则音频不做处理；
// 3.多路播放、解码时，想要回调多路的音频数据，应当调用PlayM4_PlaySoundShare接口，而非PlayM4_PlaySound，前者是共享端口播放音频，后者是独占。

PLAYM4_API BOOL __stdcall PlayM4_SetAudioStreamInfoCallBack(int   nPort,
                                                            void (CALLBACK *pfnAudioStreamInfoCB)(int nPort,const PLAYM4_AUDIOSSTREAM_INFO_S* pstAudioStreamInfo,void* pUser),
                                                            void* pUser,
                                                            int   nCBMode,
                                                            int   nCBInfo,
                                                            int   nCBModule,
                                                            void* nReserved);

#ifndef LOG_TAG
#define LOG_TAG
typedef enum _PLAYM4_LOG_LEVEL
{
	PLAYM4_LOG_LEVEL_TRACE  = 0,        //
	PLAYM4_LOG_LEVEL_DEBUG  = 1,        //调试级别
	PLAYM4_LOG_LEVEL_INFO   = 2,        //信息
	PLAYM4_LOG_LEVEL_WARN   = 3,        //警告
	PLAYM4_LOG_LEVEL_ERROR  = 4,        //错误
	PLAYM4_LOG_LEVEL_TEM  = 5           //临时问题专用
}PLAYM4_LOG_LEVEL;
#endif

// 参数配置bFlag：1，pConfigFilePath：日志生成（绝对）路径，emLogLevel：日志等级
// 注：路径传空时，默认在PlayCtrl.dll同级目录生成日志文件
PLAYM4_API BOOL __stdcall PlayM4_SetHLogFlag_Ex(BOOL bFlag, char* pConfigFilePath, PLAYM4_LOG_LEVEL emLogLevel);


// 播放库日志码流配置信息结构体
typedef struct _tagLOGSTREAMCONFIGINFO_
{
    char* pLogPath;          // 日志保存路径，传NULL则默认生成在PlayCtrl.dll目录
    char* pStreamPath;       // 码流保存路径，传NULL则默认生成在PlayCtrl.dll目录

    char  bLogSwitch;        // 日志开关
    char  nLogLevel;         // 日志等级，见PLAYM4_LOG_LEVEL定义
    char  bStreamSwitch;     // 码流开关

    char  bReadConfig;       // 是否读取播放库配置文件
    // 注：读取播放库配置文件是为了配置附加功能，接口的配置优先级高于配置文件
    char  nReserved[8];      // 保留字段
}PLAYM4_LOGSTREAMCONFIG_INFO_S;

// 重新读取配置文件，可设置日志和码流的路径，路径空时则默认保存在配置文件处
PLAYM4_API int __stdcall PlayM4_SetLogStreamConfig(PLAYM4_LOGSTREAMCONFIG_INFO_S* pstLogStreamConfigInfo);

#ifndef PLAYM4_HIKD3D11_TAG
#define PLAYM4_HIKD3D11_TAG
///<硬解码探测分辨率
#define HXVA_RESOLUTION_NONE   0x00      // 0
#define HXVA_RESOLUTION_200W   0x01      // 1920*1080
#define HXVA_RESOLUTION_300W   0x02      // 2048*1536
#define HXVA_RESOLUTION_500W   0x03      // 2560*1920
#define HXVA_RESOLUTION_800W   0x04      // 3840*2160
#define HXVA_RESOLUTION_1600W  0x05      // 4096*4096
#define HXVA_RESOLUTION_6400W  0x06      // 8192*8192(H.265)

///<硬解码和渲染能力集探测输出结构体
typedef struct _tagHDECODESUPPORT_
{
    unsigned char  chGPUType;                // GPU类型： 0-无，1-N卡独显，2-A卡独显，3-核显
    unsigned char  bDXVA_D3D9;               // 0-不支持，1-支持
    unsigned char  bCUVID_D3D11;             // 0-不支持，1-支持
    unsigned char  chDXVAH264_Max_Resolution;// DXVA,h264编码支持的最大的分辨率大概值-不是精准值-具体定义见枚举类型
    unsigned char  chDXVAH265_Max_Resolution;// DXVA,h265编码支持的最大的分辨率大概值-不是精准值-具体定义见枚举类型
    unsigned char  chCUVIDH264_Max_Resolution;// CUVID,h264编码支持的最大的分辨率大概值-不是精准值-具体定义见枚举类型
    unsigned char  chCUVIDH265_Max_Resolution;// CUVID,h265编码支持的最大的分辨率大概值-不是精准值-具体定义见枚举类型
    unsigned char  chValidFlag;               ///<有效
    unsigned char  bD3D11VA;                  // 判断是否支持D3D11VA硬解码:0-不支持，1-支持
    unsigned char  chD3D11VAH264_Max_Resolution;// D3D11VA,h264编码支持的最大的分辨率大概值-不是精准值
    unsigned char  chD3D11VAH265_Max_Resolution;// D3D11VA,h265编码支持的最大的分辨率大概值-不是精准值
    unsigned char  nReserved[9];        // 保留字段
}HDECODESUPPORT;///< 硬解码支持信息

typedef struct _tagRENDERSUPPORT_
{
    unsigned char  bDDraw;              ///< 判断是否支持Draw渲染
    unsigned char  bD3D9Surface;        ///< 判断是否支持D3D9表面渲染
    unsigned char  bD3D9Texture;        ///< 判断是否支持D3D9纹理渲染
    unsigned char  bD3D11;              ///< 判断是否支持D3D11渲染
    unsigned char  chValidFlag;         ///< 有效
    unsigned char  nGPUType;            ///< 渲染探测GPU类型  0-无; 1-核显;2-NVIDIA;3-AMD
    unsigned char  nReserved[10];       ///< 保留字段,当nGPUType类型为3 即是AMD显卡下，此处会返回AMD特定的显卡名
                                        ///<目前会返回RX550和R5 220的显卡名称，注意外部自行从该nReserved字段中寻找RX550和R5 220关键字
}RENDERSUPPORT;///< 渲染支持信息

typedef struct _tagENGINESUPPORT_
{
    HDECODESUPPORT stHDecodeSupport; ///<硬解码能力集
    RENDERSUPPORT  stRenderSupport;  ///<渲染能力集
    unsigned int   chReserved[4];    ///<保留字段
}ENGINESUPPORT;///< 硬解码和渲染支持能力集

typedef struct _tagENGINESUPPORT_EX_
{
    HDECODESUPPORT stHDecodeSupportD3D9[8];
    HDECODESUPPORT stHDecodeSupportD3D11[8];
    RENDERSUPPORT  stRenderSupport[8];
    unsigned char  chD3D9DeviceCount;
    unsigned char  chD3D11DeviceCount;
    unsigned char  chRenderDeviceCount;
    unsigned char  chReserved[13];
}ENGINESUPPORT_EX;///< 硬解码和渲染支持能力集-EX

typedef struct _tagRENDERSUPPORT_EX_
{
    unsigned char  chValidFlag;         ///< 探测有效
    unsigned char  bDDraw;              ///< 判断是否支持Draw渲染
    unsigned char  bD3D9Surface;        ///< 判断是否支持D3D9表面渲染
    unsigned char  bD3D9Texture;        ///< 判断是否支持D3D9纹理渲染
    unsigned char  bD3D11;              ///< 判断是否支持D3D11渲染
    unsigned char  bD3D11VP;            ///< 判断是否支持D3D11VP渲染
    unsigned char  nReserved1[9];        //用于后续的渲染引擎扩展
    unsigned char  nGPUType;            ///< 渲染探测GPU类型  0-无; 1-核显;2-NVIDIA;3-AMD
    unsigned char  nReserved2[256];       ///< 保留字段,当nGPUType类型为3 即是AMD显卡下，此处会返回AMD特定的显卡名
    ///<目前会返回RX550和R5 220的显卡名称，注意外部自行从该nReserved字段中寻找RX550和R5 220关键字
}RENDERSUPPORT_EX;///< 渲染支持信息

///<硬解码和渲染能力集探测输出结构体
typedef struct _tagHDECODESUPPORT_EX_
{
    unsigned char  chValidFlag;              ///<探测是否有效
    unsigned char  chGPUType;                // GPU类型： 0-无，1-N卡独显，2-A卡独显，3-核显，4-兆芯，5-解码卡
    unsigned char  bHardDecSupport;          //判断是否支持硬解码 0-不支持，1-支持
    unsigned char  chH264_Max_Resolution;    // h264编码支持的最大的分辨率大概值-不是精准值
    unsigned char  chH265_Max_Resolution;    // h265编码支持的最大的分辨率大概值-不是精准值
    unsigned char  nReserved[11];            // 保留字段
}HDECODESUPPORT_EX;///< 硬解码支持信息

typedef struct _tagGPU_ENGINE_SUPPORT_
{
    unsigned char  chD3D9DeviceCount;
    unsigned char  chD3D11DeviceCount;
    unsigned char  chRenderDeviceCount;
	unsigned char  chDecodeCardCount;               //解码卡数量
	unsigned char  chReserved1[12];                 //用于后续的设备个数扩展
    HDECODESUPPORT_EX stHDecodeSupportD3D9[8];     //D3D9硬解码支持情况
    HDECODESUPPORT_EX stHDecodeSupportD3D11[8];    //D3D11硬解码支持情况
	HDECODESUPPORT_EX stDecodeCardSupport[8];      //解码卡解码支持情况
	HDECODESUPPORT_EX chReserved2[40];              //用于后续硬解码支持的引擎类型扩展，最大支持6种引擎，每种引擎8个设备
	RENDERSUPPORT_EX  stRenderSupport[8];
}GPU_ENGINE_SUPPORT;///< 硬解码和渲染支持能力集

typedef struct _AUDIOCARDINFO_
{
	unsigned int  nDeviceIndex;     //设备号
	char          sDeviceName[128]; //设备名称
	void          *pDevice;         //设备地址
	unsigned char nReserved[8];     //保留字段
}AUDIOCARDINFO;

typedef struct _tagAUDIODEVICEPARAM_
{
	AUDIOCARDINFO  stAudioCardInfo[8];  ///<声卡设备信息
	unsigned char  chAudioCardCount;    ///<声卡设备个数
	unsigned char  chReserved[7];       ///<保留字段

}AUDIODEVICEPARAM;///< 音频设备探测信息

///<d3d11渲染抓图结构体
typedef struct _tagD3D11_PIC_INFO_
{
    unsigned int   nPicMode;     //抓图模式：0-按照码流实际分辨率抓图(之前抓图模式)；1-按照下面传入的宽高抓图（nPicWidth*nPicHeight为显示窗口宽高时效果最佳）
    unsigned char* pBuf;         //抓图数据buffer
    unsigned int   nBufSize;     //缓存buffer大小-（如果nPicMode为0则为之前的根据获取到的码流分辨率来进行缓存申请；如果nPicMode为1则上层根据设置的分辨率来申请缓存）
    unsigned int*  pPicSize;     //实际图片大小
    unsigned int   nPicWidth;    //设置抓图宽-nPicMode为1时有效，且宽>=32,nPicWidth*nPicHeight<5000w分辨率。
    unsigned int   nPicHeight;   //设置抓图高-nPicMode为1时有效，且高>=32,nPicWidth*nPicHeight<5000w分辨率。
    unsigned char  chReserve[8]; //reserve保留字段
}D3D_PIC_INFO;

/*D3D11图像后处理类型*/
typedef enum tagPLAYM4PostProcType
{
	PLAYM4_PPT_NULL                     = 0x0,
    PLAYM4_PPT_BRIGHTNESS               = 0x1,            ///< 亮度   [-1.0, 1.0]
    PLAYM4_PPT_HUE                      = 0x2,            ///< 色度   [0.0, 1.0]----0.166累加为一种颜色变化及0和1为同一种颜色
    PLAYM4_PPT_SATURATION               = 0x3,            ///< 饱和度 [-1.0, 1.0]
    PLAYM4_PPT_CONTRAST                 = 0x4,            ///< 对比度 [-1.0, 1.0]
    PLAYM4_PPT_SHARPNESS                = 0x5,            ///< 锐度   [ 0.0, 1.0]
    PLAYM4_PPT_DILATATION               = 0x6,            ///< 膨胀度 [ 1.0, 4.0],有效值只有1.0，2.0，3.0，4.0四个等级，类似1.5的小数无效
                                                          //                      底层不做错误判断，需上层使用者自己输入正确的值,错误值可能会导致黑屏
}PLAYM4PostProcType;

#endif

// 设置Devcie序号，选择对应的音频设备，只能在GetPort之后调用
PLAYM4_API BOOL __stdcall PlayM4_SetAudioDeviceIndex(LONG nPort, unsigned int nDeviceIndex);

PLAYM4_API BOOL __stdcall PlayM4_GetAudioDevice(LONG nPort, AUDIODEVICEPARAM* pstAudioDeviceParam);

///< 获取设备硬解码和渲染能力集--getport之后
PLAYM4_API int __stdcall PlayM4_GetEngineSupport(long nPort, ENGINESUPPORT* pstEngineSupport);

///< 获取设备硬解码和渲染能力集--getport之后--(支持多显卡探测，推荐使用该接口)
PLAYM4_API BOOL __stdcall PlayM4_GetEngineSupportEx(long nPort, ENGINESUPPORT_EX* pstEngineSupport);

///<渲染库d3d11抓图-只支持d3d11渲染时有效，d3d9渲染无效:nType:0-jpeg,1-bmp.
PLAYM4_API int __stdcall PlayM4_GetD3DCapture(long nPort, unsigned int nType, D3D_PIC_INFO* pstPicInfo);


///<d3d11图像后处理-暂只支持d3d11渲染后处理-设置参数
PLAYM4_API int __stdcall PlayM4_SetD3DPostProcess(long nPort, PLAYM4PostProcType nPostType, float fValue);

///<d3d11图像后处理-暂只支持d3d11渲染后处理-获取参数
PLAYM4_API int __stdcall PlayM4_GetD3DPostProcess(long nPort, PLAYM4PostProcType nPostType, float* fValue);

///<设置D3D11渲染时(D3D9渲染时设置实际无效)字符叠加的字体库路径（不设置时采用默认字体库）-play前设置
///<目前该接口逻辑修改为设置有效字体库后，均采用渲染库叠加POS，推荐POS语言类型为西文下使用，简体中文及繁文不推荐设置
PLAYM4_API int __stdcall PlayM4_SetConfigFontPath(int nPort, char* pFontPath);

////////////////////////////////////


///<SDP取流接口//////////////////////////////////////////////////////////////////////////
#ifndef PLAYM4_SESSION_INFO_TAG
#define PLAYM4_SESSION_INFO_TAG

//nProtocolType
#define PLAYM4_PROTOCOL_RTSP    1
//nSessionInfoType
#define PLAYM4_SESSION_INFO_SDP 1

typedef struct _PLAYM4_SESSION_INFO_   //交互信息结构
{
    int            nSessionInfoType;   //交互信息类型，暂时只支持SDP
    int            nSessionInfoLen;    //交互信息长度
    unsigned char* pSessionInfoData;   //交互信息数据
} PLAYM4_SESSION_INFO;
#endif

PLAYM4_API BOOL __stdcall PlayM4_OpenStreamAdvanced(LONG nPort, int nProtocolType, PLAYM4_SESSION_INFO* pstSessionInfo, DWORD nBufPoolSize);

///<鱼眼相关接口//////////////////////////////////////////////////////////////////////////
#ifndef FISH_EYE_TAG
#define FISH_EYE_TAG

// 安装类型
typedef enum tagFECPlaceType
{
    FEC_PLACE_WALL    = 0x1,        // 壁装方式     (法线水平)
    FEC_PLACE_FLOOR   = 0x2,        // 地面安装     (法线向上)
    FEC_PLACE_CEILING = 0x3,        // 顶装方式     (法线向下)

}FECPLACETYPE;

typedef enum tagFECCorrectType
{
    FEC_CORRECT_NULL                    = 0x0000, // 不矫正 - (鱼眼原图)
    FEC_CORRECT_PTZ                     = 0x0100, // PTZ
    FEC_CORRECT_180                     = 0x0200, // 180度矫正 - （对应2P） - 顶装/底装
    FEC_CORRECT_360                     = 0x0300, // 360全景矫正 - （对应1P） - 顶装/底装
    FEC_CORRECT_LAT                     = 0x0400, // 纬度展开 - 壁装
    FEC_CORRECT_SEMISPHERE              = 0x0500, // 鱼眼半球矫正 - (球面矫正)
    FEC_CORRECT_CYLINDER                = 0x0600, // 鱼眼圆柱显示 - 顶装/底装
    FEC_CORRECT_CYLINDER_SPLIT          = 0x0700, // 鱼眼切开的圆柱显示 - 顶装/底装
    FEC_CORRECT_PLANET                  = 0x0800, // 鱼眼小行星
    FEC_CORRECT_ARCSPHERE_HORIZONTAL    = 0x0900, // 鱼眼水平弧面 - 壁装
    FEC_CORRECT_ARCSPHERE_VERTICAL      = 0x0A00, // 鱼眼垂直弧面 - 壁装
    FEC_CORRECT_PTZ_SCALE_ANIMATION     = 0x0B00, // 鱼眼PTZ转场缩放动画矫正模式
}FECCORRECTTYPE;

typedef enum tagFECCorrectEffect
{
    FEC_CORRECT_EFFECT_BACK_FACE_CULLING    = 0x100,        // 背面剔除：非0表示启用，为0表示不启用，建议设置整数强转浮点数

}FECCORRECTEFFECT;

typedef struct tagCycleParam
{
    float   fRadiusLeft;    // 圆的最左边X坐标
    float   fRadiusRight;   // 圆的最右边X坐标
    float   fRadiusTop;     // 圆的最上边Y坐标
    float   fRadiusBottom;  // 圆的最下边Y坐标

}CYCLEPARAM;

typedef struct tagPTZParam
{
    float fPTZPositionX;        // PTZ 显示的中心位置 X坐标
    float fPTZPositionY;        // PTZ 显示的中心位置 Y坐标	

}PTZPARAM;

#define         FEC_UPDATE_RADIUS            0x1
#define         FEC_UPDATE_PTZZOOM           0x2
#define         FEC_UPDATE_WIDESCANOFFSET    0x4
#define         FEC_UPDATE_PTZPARAM          0x8
#define         FEC_UPDATT_PTZCOLOR          0x10
#define         FEC_UPDATE_PTZSELECT         0x20

// 色彩结构体
typedef struct tagFECColor
{
    unsigned char nR;     // R分量
    unsigned char nG;	  // G分量
    unsigned char nB;     // B分量
    unsigned char nAlpha; // Alpha分量
}FECCOLOR;

//PTZ框选结构体
typedef struct tagFECRectF
{
    float fTop;
    float fBottom;
    float fLeft;
    float fRight;
}FECRECTF;

typedef struct tagFECParam
{
    unsigned int    nUpDateType;            // 更新的类型
    unsigned int    nPlaceAndCorrect;       // 安装方式和矫正方式，只能用于获取，SetParam的时候无效,该值表示安装方式和矫正方式的和
    PTZPARAM        stPTZParam;             // PTZ 校正的参数
    CYCLEPARAM      stCycleParam;           // 鱼眼图像圆心参数
    float           fZoom;                  // PTZ 显示的范围参数
    float           fWideScanOffset;        // 180或者360度校正的偏移角度
    FECCOLOR        stPTZColor;             // PTZ颜色
    FECRECTF        stPTZSelct;             // PTZ选择区域
    unsigned int    nCut;                   //鱼眼原图是否进行裁剪以填充整个窗口（仅作用于鱼眼原图）
    int             nResver[10];            // 保留字段
}FISHEYEPARAM;

// PTZ在原始鱼眼图上轮廓的显示模式
typedef enum tagFECShowMode
{
    FEC_PTZ_OUTLINE_NULL,   // 不显示
    FEC_PTZ_OUTLINE_RECT,   // 矩形显示
    FEC_PTZ_OUTLINE_RANGE,  // 真实区域显示
}FECSHOWMODE;

#define    FEC_JPEG   0  // JPEG抓图
#define    FEC_BMP    1  // BMP 抓图

// 硬解码标志
#define FEC_DISPLAYSURFACE          0x400  // 鱼眼硬解标识

// 旋转单元结构体
typedef struct tagPLAYM4SRTransformElement
{
    float fAxisX;
    float fAxisY;
    float fAxisZ;
    float fValue; // 旋转的角度

}PLAYM4SRTRANSFERELEMENT;

// 旋转组合参数
typedef struct tagPLAYM4SRTransformParam
{
    PLAYM4SRTRANSFERELEMENT* pTransformElement;		// 旋转的坐标轴
    unsigned int		     nTransformCount;		// 旋转的组合次数
}PLAYM4SRTRANSFERPARAM;


//////////*************鱼眼相关的不建议使用接口和定义(老球面鱼眼)************************//////////////

#define FEC_DISPLAYSPHERE           0x402  // 鱼眼球面渲染显示(老球面鱼眼)-不建议使用

PLAYM4_API BOOL __stdcall PlayM4_FEC_Rotate(LONG nPort, PLAYM4SRTRANSFERPARAM *pstRotateParam);///<此接口为不建议使用接口(老球面鱼眼旋转接口)

//////////////////////**************************/////////////////////////


// 视角变换类型
typedef enum tagPLAYM4HRViewParamType
{
    PLAYM4_HR_VPT_ROTATION_X       = 0x1,          ///<水平旋转
    PLAYM4_HR_VPT_ROTATION_Y       = 0x2,          ///<垂直旋转
    PLAYM4_HR_VPT_SCALE            = 0x3,          ///<缩放(其绝对值为浮点型0值时为黑屏-正常效果)
}PLAYM4HRVIEWPARAMTYPE;

// 鱼眼3D模型参数
typedef enum tagPLAYM4FEC3DModelParam
{
    PLAYM4_FEC_3DMP_CYLINDER_HEIGHT              = 0x1,       ///< 圆柱模型高
    PLAYM4_FEC_3DMP_CYLINDER_RADIUS              = 0x2,       ///< 圆柱模型半径
}PLAYM4FEC3DMODELPARAM;

// 特定视角状态
typedef enum tagPLAYM4FECSpecialViewType
{
    PLAYM4_FEC_SVT_EDGE                          = 0x1        ///<弧面鱼眼模型与窗口贴边视角
}PLAYM4FECSPECIALVIEWTYPE;

typedef void (__stdcall* FISHEYE_CallBack )( void* pUser, unsigned int nSubPort, unsigned int nCBType, void* hDC, unsigned int nWidth, unsigned int nHeight);

#endif
// 启用鱼眼
PLAYM4_API BOOL __stdcall PlayM4_FEC_Enable(LONG nPort);

// 关闭鱼眼模块
PLAYM4_API BOOL __stdcall PlayM4_FEC_Disable(LONG nPort);

// 获取鱼眼矫正处理子端口 [1~31]
PLAYM4_API BOOL __stdcall PlayM4_FEC_GetPort(LONG nPort, unsigned int* nSubPort, FECPLACETYPE emPlaceType, FECCORRECTTYPE emCorrectType);

// 删除鱼眼矫正处理子端口
PLAYM4_API BOOL __stdcall PlayM4_FEC_DelPort(LONG nPort, unsigned int nSubPort);

// 设置鱼眼矫正参数
PLAYM4_API BOOL __stdcall PlayM4_FEC_SetParam(LONG nPort, unsigned int nSubPort, FISHEYEPARAM* pPara);

// 获取鱼眼矫正参数
PLAYM4_API BOOL __stdcall PlayM4_FEC_GetParam(LONG nPort, unsigned int nSubPort, FISHEYEPARAM* pPara);

// 设置显示窗口，可以随时切换
PLAYM4_API BOOL __stdcall PlayM4_FEC_SetWnd(LONG nPort, unsigned int nSubPort, void* hWnd);

// 设置鱼眼窗口的绘图回调
PLAYM4_API BOOL __stdcall PlayM4_FEC_SetCallBack(LONG nPort, unsigned int nSubPort, FISHEYE_CallBack cbFunc, void* pUser);

// 鱼眼抓图
PLAYM4_API BOOL __stdcall PlayM4_FEC_Capture(LONG nPort, unsigned int nSubPort, unsigned int nType, char* pFileName);

// 鱼眼硬解
PLAYM4_API BOOL __stdcall PlayM4_FEC_SetConfig(LONG nPort,unsigned int nType);

PLAYM4_API BOOL __stdcall PlayM4_FEC_GetCurrentPTZPort(LONG nPort, float fPositionX,float fPositionY, unsigned int *pnPort);

PLAYM4_API BOOL __stdcall PlayM4_FEC_SetCurrentPTZPort(LONG nPort, unsigned int nSubPort);

PLAYM4_API BOOL __stdcall PlayM4_FEC_SetPTZOutLineShowMode(LONG nPort,FECSHOWMODE nPTZShowMode);

PLAYM4_API int __stdcall PlayM4_FEC_PTZ2Window(LONG nPort, unsigned int nSubPort, PTZPARAM stPTZRefOrigin, PTZPARAM stPTZRefWindow, PTZPARAM stPTZWindow, float * fXWindow, float * fYWindow);

PLAYM4_API int __stdcall PlayM4_FEC_PTZ2WindowEx(LONG nPort , unsigned int nSubPortF,unsigned int nSubPortS,PTZPARAM stPTZRefOrigin , PTZPARAM stPTZRefWindow , PTZPARAM stPTZWindow , float * fXWindow , float * fYWindow);
PLAYM4_API int __stdcall PlayM4_SetDecodeOrDisplayMode(long nPort, unsigned int nDecodeType, unsigned int nDisplayEngine);
PLAYM4_API int __stdcall PlayM4_FEC_Scan(LONG nPort, unsigned int nSubPort, float fAngle, float* fXWindow, float* fYWindow, FECPLACETYPE emType);

//bEnable 为true表示PTZ由鱼眼原图样式进入放大，为false表示由放大退出，恢复为鱼眼原图样式，注意此接口必须是在鱼眼顶装PTZ缩放动画矫正模式下才起作用
PLAYM4_API BOOL __stdcall PlayM4_FEC_SetPTZAnimationScale(LONG nPort, unsigned int nSubPort,BOOL bEnable);


//新的鱼眼半球矫正视角变化(旋转)两个相关接口
//获取半球矫正视角参数(设置前先获取当前的值)
PLAYM4_API BOOL __stdcall PlayM4_FEC_GetViewParam(LONG nPort, unsigned int nSubPort, PLAYM4HRVIEWPARAMTYPE enViewParamType, float* fValue);
//设置半球矫正视角变化参数(设置的值为获取值加上要偏移值)
PLAYM4_API BOOL __stdcall PlayM4_FEC_SetViewParam(LONG nPort, unsigned int nSubPort, PLAYM4HRVIEWPARAMTYPE enViewParamType, float fValue);

//鱼眼电子放大 nType = 0，
//鱼眼窗口分割 nType = 1，
//注意，窗口分割时hDestWnd无效，请设置为NULL（20180813暂不支持）
//目前电子放大不支持其他窗口上放大，nRegionNum置为0，hDestWnd置为NULL，bEnable置为0取消电子放大，非0为电子放大
//pSrcRect区域归一化，乘以1000除以宽或者高（其值在0-1000之间）
//只推荐原图、180、360、纬度展开进行电子放大-3D鱼眼不建议使用此接口(用视角变化接口进行缩放），ptz和3D矫正方式不支持电子放大
PLAYM4_API BOOL __stdcall PlayM4_FEC_SetDisplayRegion(LONG nPort, unsigned int nSubPort,unsigned int nType, DWORD nRegionNum, RECT *pSrcRect, HWND hDestWnd, BOOL bEnable);
//背面剔除：非0表示启用，为0表示不启用，建议设置整数强转浮点数
PLAYM4_API BOOL __stdcall PlayM4_FEC_SetCorrectEffect(LONG nPort, unsigned int nSubPort, FECCORRECTEFFECT nCorrectEffect, float fValue);

// 设置3D模型参数-针对3D圆柱展开有效
PLAYM4_API BOOL __stdcall PlayM4_FEC_Set3DModelParam(int nPort, unsigned int nSubPort, PLAYM4FEC3DMODELPARAM enType, float fValue);

// 获取特定视角参数 - 只适用于弧面，跟SetViewParam接口配合使用
PLAYM4_API BOOL __stdcall PlayM4_FEC_GetSpecialViewParam(int nPort, unsigned int nSubPort, PLAYM4FECSPECIALVIEWTYPE enSVType, PLAYM4HRVIEWPARAMTYPE enVPType, float* pValue);

///<全景360相关接口//////////////////////////////////////

//全景播放展示效果
#ifndef PLAYM4_PANORAMA_TAG
#define PLAYM4_PANORAMA_TAG
typedef enum tagPLAYM4PanoramaDisplayEffect
{
	PANORAMA_PLANET  = 0,///< 全景平面展示
	PANORAMA_SPHERE = 1, ///< 全景球面展示
	PANORAMA_AUTO = 2,   ///< 自动展示
    PANORAMA_ASTEROID = 3, ///< 全景小行星展示
}PLAYM4PANORAMADISPLAYEFFECT;
#endif

/** @fn int  __stdcall  PlayM4_SetPanoramaDisplayEffect(LONG nPort, PLAYM4PANORAMADISPLAYEFFECT eDisplayEffect, void *nReserved)
*  @brief  设置全景播放展示效果
*  @param nPort                 [IN] 端口号
*  @param eDisplayEffect        [IN] 播放展示效果,枚举：0代表全景平面展示，1代表全景球面展示
*  @param nReserved             [IN] 保留位
*  @return 1成功，否则失败
*/
PLAYM4_API BOOL __stdcall PlayM4_SetPanoramaDisplayEffect(LONG nPort, PLAYM4PANORAMADISPLAYEFFECT eDisplayEffect, void *nReserved);

/** @fn int  __stdcall  PlayM4_GetPanoramaSphereViewParam(LONG nPort, PLAYM4HRVIEWPARAMTYPE enViewParamType, float* fValue, void *nReserved)
*  @brief  获取360全景球形视角参数(设置前先获取当前的值)
*  @param nPort         [IN] 端口号
*  @param enViewParamType       [IN] 视角变换类型
*  @param fValue                [IN/OUT] 矫正角度，获取值
*  @param nReserved             [IN] 保留位
*  @return 1成功，否则失败
*/
PLAYM4_API BOOL __stdcall PlayM4_GetPanoramaSphereViewParam(LONG nPort, PLAYM4HRVIEWPARAMTYPE enViewParamType, float* fValue, void *nReserved);

/** @fn int  __stdcall  PlayM4_SetPanoramaSphereViewParam(LONG nPort, PLAYM4HRVIEWPARAMTYPE enViewParamType, float fValue, void *nReserved)
*  @brief  设置360全景球形视角参数(设置的值为获取值加上要偏移值)
*  @param nPort         [IN] 端口号
*  @param enViewParamType       [IN] 视角变换类型
*  @param fValue                [IN] 矫正角度，设置值
*  @param nReserved             [IN] 保留位
*  @return 1成功，否则失败
*/
PLAYM4_API BOOL __stdcall PlayM4_SetPanoramaSphereViewParam(LONG nPort, PLAYM4HRVIEWPARAMTYPE enViewParamType, float fValue, void *nReserved);
//////////////////////////////////////////////////////////////////

///<图像增强相关接口//////////////////////////////////////////////////////////////////////////
#ifndef PLAYM4_HIKVIE_TAG
#define PLAYM4_HIKVIE_TAG

typedef struct _PLAYM4_VIE_DYNPARAM_
{
    int moduFlag;      //启用的算法处理模块，在PLAYM4_VIE_MODULES中定义，如 PLAYM4_VIE_MODU_ADJ | PLAYM4_VIE_MODU_EHAN，模块启用后，必须设置相应的参数；
    //PLAYM4_VIE_MODU_ADJ
    int brightVal;     //亮度调节值，[-255, 255]
    int contrastVal;   //对比度调节值，[-256, 255]
    int colorVal;      //饱和度调节值，[-256, 255]
    //PLAYM4_VIE_MODU_EHAN
    int toneScale;     //滤波范围，[0, 100]
    int toneGain;      //对比度调节，全局对比度增益值，[-256, 255]
    int toneOffset;    //亮度调节，亮度平均值偏移，[-255, 255]
    int toneColor;     //颜色调节，颜色保真值，[-256, 255]
    //PLAYM4_VIE_MODU_DEHAZE
    int dehazeLevel;   //去雾强度，[0, 255]
    int dehazeTrans;   //透射值，[0, 255]
    int dehazeBright;  //亮度补偿，[0, 255]
    //PLAYM4_VIE_MODU_DENOISE
    int denoiseLevel;  //去噪强度，[0, 255]
    //PLAYM4_VIE_MODU_SHARPEN
    int usmAmount;     //锐化强度，[0, 255]
    int usmRadius;     //锐化半径，[1, 15]
    int usmThreshold;  //锐化阈值，[0, 255]
    //PLAYM4_VIE_MODU_DEBLOCK
    int deblockLevel;  //去块强度，[0, 100]
    //PLAYM4_VIE_MODU_LENS
    int lensWarp;      //畸变量，[-256, 255]
    int lensZoom;      //缩放量，[-256, 255]
    //PLAYM4_VIE_MODU_CRB
    //无响应参数
} PLAYM4_VIE_PARACONFIG;

typedef enum _PLAYM4_VIE_MODULES
{
    PLAYM4_VIE_MODU_ADJ      = 0x00000001, //图像基本调节
    PLAYM4_VIE_MODU_EHAN     = 0x00000002, //局部增强模块
    PLAYM4_VIE_MODU_DEHAZE   = 0x00000004, //去雾模块
    PLAYM4_VIE_MODU_DENOISE  = 0x00000008, //去噪模块
    PLAYM4_VIE_MODU_SHARPEN  = 0x00000010, //锐化模块
    PLAYM4_VIE_MODU_DEBLOCK  = 0x00000020, //去块滤波模块
    PLAYM4_VIE_MODU_CRB      = 0x00000040, //色彩平衡模块
    PLAYM4_VIE_MODU_LENS     = 0x00000080, //镜头畸变矫正模块
}PLAYM4_VIE_MODULES;
#endif

//设置关闭/开启模块
//dwModuFlag对应PLAYM4_VIE_MODULES宏,可组合
//先设置模块开启，再设置模块参数；期间采用默认的参数;
//关闭模块后，上次设置的参数清空
//其他接口调用，必须在该接口开启模块后；否则，返回错误
PLAYM4_API BOOL __stdcall PlayM4_VIE_SetModuConfig(LONG lPort,int nModuFlag,BOOL bEnable);

//设置图像增强区域，NULL全图；超过全图，采用全图；最小区域32*32像素
//可支持设置区域，最多比较说4个，第一个版本可以只支持一个。多个区域要求不能重叠，有重叠就报错
PLAYM4_API BOOL __stdcall PlayM4_VIE_SetRegion(LONG lPort,LONG lRegNum,RECT* pRect);

//获取开启模块
PLAYM4_API BOOL __stdcall PlayM4_VIE_GetModuConfig(LONG lPort,int* pdwModuFlag);

//设置参数，未开启模块的参数设置被忽略
PLAYM4_API BOOL __stdcall PlayM4_VIE_SetParaConfig(LONG lPort,PLAYM4_VIE_PARACONFIG* pParaConfig);

//获取开启模块的参数
PLAYM4_API BOOL __stdcall PlayM4_VIE_GetParaConfig(LONG lPort,PLAYM4_VIE_PARACONFIG* pParaConfig);

/**********************基线UTC差异开始**********************************************/
#define REF_ALWAYS 0 
#define REF_ONCE   1

#ifndef _TEXT_INFO_
#define _TEXT_INFO_
typedef struct _TEXT_INFO_
{
	DWORD  dwLanguage;
	char*  strText;
	DWORD  dwReserved[4];//dwReserved[0] specify length
} TEXT_INFO;
#endif

#define   PD_VEH   1

#ifndef _PRIVATE_DATA_INFO_
#define _PRIVATE_DATA_INFO_
typedef struct _PRIVATE_DATA_INFO_
{
	DWORD dwDataType;
	BYTE* pData;
	DWORD dwDataLen;
} PRIVATE_DATA_INFO;
#endif
/**********************基线UTC差异结束**********************************************/

typedef struct
{
    long    lDataType;          //私有数据类型
    long    lDataStrVersion;    //数据返回的结构体版本，主要是为了兼容性
    long    lDataTimeStamp;
    long    lDataLength;
    char*   pData;
}AdditionDataInfo;

//该接口只支持以下几种私有信息类型
//0x0101: //定制温度
//0x0103: //基线温度裸数据
//0x0006: //车载行车信息
//0x0009: //车载调试信息
//0x0007: //POS信息解析回调
//0x000F: //碗型鹰眼信息
//0x0010: //汽车电子私有信息
//0x0011: //无人机私有信息
//0x0804: //数立体云防私有数据
//0x1005: //萤石私有数据
//0x000B: //设备扩展信息
//0x0012: //后端私有信息
//0x0014: //前端私有信息
//0x0106: //热成像私有信息
//0x100D: //前端调试私有信息
//0x0801: //过线统计
//0x0102: //测温信息
PLAYM4_API BOOL __stdcall PlayM4_SetAdditionDataCallBack(LONG nPort, DWORD nSyncType, void (CALLBACK* AdditionDataCBFun)(long nPort, AdditionDataInfo* pstAddDataInfo, void* pUser), void* pUser);

//该接口只支持以下几种私有信息类型
//解析模块：
//0x0101: //定制温度
//0x0103: //基线温度裸数据
//0x0006: //车载行车信息
//0x0009: //车载调试信息
//0x0007: //POS信息解析回调
//0x000F: //碗型鹰眼信息
//0x0010: //汽车电子私有信息
//0x0011: //无人机私有信息
//0x0804: //数立体云防私有数据
//0x1005: //萤石私有数据
//0x000B: //设备扩展信息
//0x0012: //后端私有信息
//0x0106: //热成像私有信息
//渲染模块：
//0x0801: //过线统计
//0x0102: //测温信息
PLAYM4_API BOOL __stdcall PlayM4_SetMultiAdditionDataCallBack(long nPort, unsigned int* nSyncTypeNode, unsigned int NodeNumber, void (CALLBACK* AdditionDataCBFun)(long nPort, AdditionDataInfo* pstAddDataInfo, void* pUser), void* pUser, void* pReserved);

// 渲染绘制模式
typedef enum RenderDrawMode
{
    PLAYM4_ODT_DEFAULT = 0,
    PLAYM4_ODT_GDI     = 1,
    PLAYM4_ODT_D3D     = 2
}PLAYM4_RENDER_DRAW_MODE_E;

// 设置渲染的绘制模式D3D和GDI
// 1.此接口用于设置渲染引擎的GDI和D3D两种绘制方式；
// 2.此接口目前仅对渲染库绘制水印信息的情况生效（斜体透明度水印，硬解码下的普通水印绘制），可以修改渲染库绘制水印的方式；
// 3.GDI模式生效需要显卡环境支持DDraw，D3D9或D3D11引擎；
// 4.D3D模式生效需要显卡环境支持D3D9或D3D11引擎；
// 5.斜体透明度水印绘制，效果方面，GDI优于D3D，仅D3D11-GDI支持透明度；
// 6.斜体透明度水印绘制，性能方面，D3D9引擎下，GDI优于D3D，D3D易影响画面卡顿，D3D11引擎下，D3D优于GDI。
PLAYM4_API BOOL __stdcall PlayM4_SetRenderDrawMode(LONG nPort, PLAYM4_RENDER_DRAW_MODE_E enRenderDrawMode,int nReserved);

#define SOFT_DECODE_ENGINE 0 ///<软解码
#define HARD_DECODE_ENGINE 1 ///<硬解码

// 支持无头开流设置硬解码，设置成功说明当前系统环境支持硬解码
// 对于当前码流的格式与分辨率是否支持硬解码，需要播放过程中内部检测，若不支持则自动切软解
PLAYM4_API BOOL  __stdcall PlayM4_SetDecodeEngineEx(LONG nPort, DWORD nDecodeEngine);
PLAYM4_API DWORD __stdcall PlayM4_GetDecodeEngine(LONG nPort);

#define PLAYM4_SOURCE_MODULE             0 // 数据源模块,高8bit的取值范围为[1,10],对应16进制的[0x01,0x0A]



#define PLAYM4_DEMUX_MODULE              1 // 解析模块, 高8bit的取值范围为[11,20],对应16进制的[0x0B,0x14]

#define PLAYM4_RTINFO_IDMX_DATA_ERROR              32 // 数据有误,解析失败
#define PLAYM4_RTINFO_IDMX_PSH_PSM_ERROR         0x100// PSH/PSM有误,解析失败
#define PLAYM4_RTINFO_IDMX_RTP_HEADER_ERROR      0x200// RTP头有误，包括扩展头
#define PLAYM4_RTINFO_IDMX_RTP_HEADER_SEQ_ERROR  0x400// RTP视频包序不连续
#define PLAYM4_RTINFO_IDMX_REDUNDANT_ERROR       0x800// 码流里有冗余数据
#define PLAYM4_RTINFO_IDMX_MEDIA_CHANGE_ERROR             0x1000// 媒体信息发生改变(与hik头的信息不一致或者psm里面的音视频类型发生改变)
#define PLAYM4_RTINFO_IDMX_DIFFERENT_FRAMERATE_ERROR      0x2000// 封装层帧率与编码层帧率不一致
#define PLAYM4_RTINFO_IDMX_DIFFERENT_RESOLUTION_ERROR     0x4000// 封装层分辨率与编码层分辨率不一致
#define PLAYM4_RTINFO_IDMX_DECORD_ERROR                   0x8000// 编码检查异常
#define PLAYM4_RTINFO_IDMX_PRIVT_LEN_ERROR                0x10000// 私有数据长度异常
#define PLAYM4_RTINFO_IDMX_REAL_FRAMERATE                 0x100000 // 实时帧率变化通知，此时的RunTimeInfo结构体里的nFrameTimeStamp表示相邻帧的平均时间间隔，其倒数即为当前实际帧率
#define PLAYM4_RTINFO_IDMX_I_FRAME_FLAG                   0x400000  //RTP流帧帧类型



#define PLAYM4_DECODE_MODULE             2 // 解码模块,高8bit字节的取值范围为[21,30],对应16进制的[0x15,0x1E]

#define PLAYM4_RTINFO_DECODE_PARAM_ERROR                       64 // 参数有误,解码失败
#define PLAYM4_RTINFO_SOFTDECODE_DATA_ERROR                   128 // 软解码数据错误
#define PLAYM4_RTINFO_SOFTDECODE_DATA_FLAKE_ERROR         0x20000 //软解码数据存在花屏错误



#define PLAYM4_RENDER_MODULE             3 // 渲染模块, 高8bit字节的取值范围为[31,40],对应16进制的[0x1F,0x28]

#define PLAYM4_RTINFO_RENDER_OVER                         8 // 渲染一帧结束
#define PLAYM4_RTINFO_ERR_PRESENT                        16 // 渲染显示错误[当前渲染引擎渲染失败,上层重新切换引擎]
#define PLAYM4_RTINFO_RENDER_MEDIAUPDATE_FLAG      0x800000 // 分辨率发生变化通知
#define PLAYM4_RTINFO_RENDER_BEGIN                 0x1F000001 //渲染模块渲染一帧开始
#define PLAYM4_RTINFO_RENDER_WINDOW_IS_NULL        0x1F000002 //渲染模块渲染，但是窗口为空，此时帧数据不会送去显示，但是会触发此回调全局时间,告知当前播放进度


#define PLAYM4_MANAGER_MODULE            4 // 管理模块,高8bit字节的取值范围为[41,50],对应16进制的[0x29,0x32]

#define PLAYM4_RTINFO_RTINFO_SOURCE_DATA_INTERVAL         0x40000
#define PLAYM4_RTINFO_MANAGER_SYC_LONG_WAIT               0x80000
#define PLAYM4_RTINFO_MANAGER_I_FRAME_FLAG                0x200000    //PS流帧类型
#define PLAYM4_RTINFO_MANAGER_DATA_DETECT_FEEDBACK        0x29000001 //探测结果反馈,RunTimeInfo结构体中reserved[0]的值为0表示探测失败，为1表示探测成功


#define PLAYM4_RTINFO_HARDDECODE_ERROR   0 // 硬解码致命(需要切软解)错误
#define PLAYM4_RTINFO_SOFTDECODE_ERROR   1 // 软解码错误(暂无)
#define PLAYM4_RTINFO_MEDIAHEADER_ERROR  2 // 媒体头错误
#define PLAYM4_RTINFO_SWITCH_SOFT_DEC    3 // 切换至软解
#define PLAYM4_RTINFO_ALLOC_MEMORY_ERROR 4 // 内存分配失败
#define PLAYM4_RTINFO_ENCRYPT_ERROR      5 // 秘钥错误 [加密的码流在解析报错时也会回调该错误码]

// 保留字节定义：
// 1.当注册PLAYM4_RTINFO_MANAGER_I_FRAME_FLAG、PLAYM4_RTINFO_IDMX_I_FRAME_FLAG后，reserved[0]代表I帧标记，该值为0表示非I帧，为1表示I帧；
// 2.当注册PLAYM4_RTINFO_RENDER_OVER 8 后，reserved[0]代表该状态码下的扩展字段所回调的信息类型：
//   reserved[0] = 0，表示扩展字段为全局时间,
//       reserved[1]reserved[2] - 年，reserved[3] - 月，reserved[4] - 日，reserved[5] - 时，reserved[6] - 分，reserved[7]，reserved[8]reserved[9] - ms
//   reserved[0] = 1，待后续扩展...
typedef struct
{
	int            nRunTimeModule;     //当前运行模块
	int            nStrVersion;        //结构体版本
	int            nFrameTimeStamp;    //帧号
	int            nFrameNum;          //时间戳
	int            nErrorCode;         //状态码-并非都是错误信息
	unsigned char  reserved[12];       //保留字节，此保留字段不可修改；
}RunTimeInfo;

// 要求不同模块的回调函数必须为同一个，否则后注册的将覆盖掉先注册的
PLAYM4_API BOOL __stdcall PlayM4_SetRunTimeInfoCallBackEx(LONG nPort, int nModule, void (CALLBACK* RunTimeInfoCBFun)(long nPort, RunTimeInfo* pstRunTimeInfo, void* pUser), void* pUser);

// 1、SetRunTimeInfoCallBackEx接口，nErrorCode类型6改为类型8；以后扩展方式 16、32、64，且从8开始消息默认关闭不发送。
// 2、新增实时消息控制接口，控制从8以后的消息，支持从8开始后消息，拼接模式 8|16|32 这种方式，上层主动选择接受类型。
// 3、nType可以通过或的方式将类型传入，nFlag表示清除（为0）或者进行回调（非0）；但是，以实时信息类型0x80000为界限，小于该类型值的
// 可以通过或的形式一次传入多个回调信息类型；大于该类型值的，则必须是回调信息类型的高8bit字节值相等，才可以通过或的形式一次性传入;
// 因此当你比如有0x08、0x80000、0x1F000001、0x1F000002这四种需要回调时，则必须调用两次类型传入接口，0x08 | 0x80000作为一组，调用该接口传入一次; 
// 而0x1F000001 | 0x1F000002作为一组再次调用该接口传入一次；当然也支持你单个传入比如调用4次接口每次传入一个回调类型；
PLAYM4_API int __stdcall PlayM4_SetRunTimeInfoCallbackType(int nPort, int nModule, unsigned int nType, int nFlag);

PLAYM4_API BOOL __stdcall PlayM4_RegisterImageMattingCallBack( long nPort, void (CALLBACK* ImageMattingCBFun) ( long nPort, IMAGE_MATTING_INFO* pstImageInfo, void* pUser), IMAGE_MATTING_CONFIG* ParamConfig, void* pUser);
PLAYM4_API BOOL __stdcall PlayM4_SetMosaicType(LONG nPort, MOSAIC_TYPE_CONFIG* pstMosaicParam);
PLAYM4_API BOOL __stdcall PlayM4_SelectTargetToDrawMosaic(LONG nPort, MOSAIC_NEED_DRAW* pstMosaicParam, BOOL bTrue);

#ifndef INTELINFO_NEED_DRAW_TAG
#define INTELINFO_NEED_DRAW_TAG

typedef struct _INTELINFO_NODE_LIST_
{
	unsigned int  nID;          //ID
	unsigned char nType;        //1代表普通目标，2代表海康深眸目标，4代表普通规则，8代表海康深眸规则
	unsigned char reserved[19]; //保留扩展位
}INTELINFO_NODE_LIST;

typedef struct _INTELINFO_NEED_DRAW_
{
	INTELINFO_NODE_LIST*       pIntelInfoNode;  //目标节点指针，根据NodeNumber个数来偏移读取即可
	unsigned int               NodeNumber;      //节点个数
	unsigned char              reserved[20];    //保留扩展位
}INTELINFO_NEED_DRAW;

#endif
////选择智能私有信息ID绘制,支持海康深眸/普通的目标框、规则框
////nType表示需要回调的私有信息类型
////bTrue为1表示开启功能，为0表示关闭功能
////nMode为0表示绘制选中ID，为1表示不绘制选中ID，目前仅支持选中ID绘制，即需要设置0
PLAYM4_API BOOL __stdcall PlayM4_SelectIntelInfoFeatureToDraw(LONG nPort, INTELINFO_NEED_DRAW* pstIntelInfoParam, BOOL bTrue, DWORD nMode, void* nReserved);

#ifndef PLAYM4_HIKSR_TAG
#define PLAYM4_HIKSR_TAG

#define CFG_DISPLAY_EAGLE_PARAMS_EX    0x497  //离线调参用,新协议
#define CFG_DISPLAY_EAGLE_PARAMS       0x498  //离线调参用,老协议
#define CFG_DISPLAY_MODEL_MODE         0x499  //碗型鹰眼设置

// 模型贴图类型 0 双面 1 外面 2 内面 
typedef enum tagPLAYM4SRTextureMode
{
    PLAYM4_TEXTURE_DOUBLE       = 0x0,           // 双面贴纹理
    PLAYM4_TEXTURE_OUTER        = 0x1,           // 外表面贴纹理
    PLAYM4_TEXTURE_INNER        = 0x2,           // 内表面贴纹理
}PLAYM4SRTEXTUREMODE;

//模型类型
typedef enum tagPLAYM4SRModelType
{
    PLAYM4_MODELTYPE_HEMISPHERE = 0x0,           //鱼眼视频用半球模型
    PLAYM4_MODELTYPE_EAGLE_EYE  = 0x1,           //碗状类半球模型用于鹰眼拼接
    PLAYM4_MODELTYPE_CUBE       = 0x2,           //立方体模型
}PLAYM4SRMODELTYPE;

#define PLAYM4_MODEL_SOLID      0x0001           //实体模型
#define PLAYM4_MODEL_FRAME      0x0010           //边框模型
#define PLAYM4_MODEL_AXIS       0x0100           //坐标轴

//渲染到3D模型的相关参数
typedef struct tagRenderModelMode
{
    bool                          bModelMode;      // 是否将渲染到3D模型上
    PLAYM4SRTEXTUREMODE           emTextureMode;   // 纹理贴图模式 双面 外表面 内表面
    unsigned long                 ulDisplayType;   // 按位组合 SR_MODEL_SOLID | SR_MODEL_FRAME | SR_MODEL_AXIS
    unsigned int                  nTransformMode;  // 0 线框坐标轴随模型变换  1 线框坐标轴不随模型变换
    PLAYM4SRMODELTYPE             emModelType;     // 模型类型，鱼眼半球，鹰眼碗模型等
}PLAYM4SRMODELMODE;

//...................CFG_DISPLAY_EAGLE_PARAMS       0x498  离线调参用,老协议 对应结构体参数...............//
typedef struct tagPLAYM4SREagleEyeParam
{
    unsigned int  nCameraIndex;   //相机编号 0-7
    double        fAlpha;         //alpha角度值，画面垂直运动  -90.0 – 90.0
    double        fBeta;          //beta角度值，画面水平运动   -90.0 – 90.0
    double        fGamma;         //gamma角度值，画面旋转      -90.0 - 90.0
    double        fFov;           //fov，画面放大缩小          40.0  - 80.0
    unsigned char ucReserved[32]; //保留字段
}PLAYM4SREAGLEEYEPRAM;

//...................CFG_DISPLAY_EAGLE_PARAMS_EX    0x497  离线调参用,新协议 对应结构体参数...............//

//新的小鹰眼相机外参结构体
typedef struct tagPLAYM4SRCameraParam
{
    float          fAlpha;                           ///< 相机内参
    float          fBeta;                            ///< 相机内参
    float          fGamma;                           ///< 相机内参
    float          fFov;                             ///< 相机内参
    float          fx;                               ///< fx,fy,cx,cy为相机内参标定量
    float          fy;
    float          cx;
    float          cy;
    float          t1;                              ///< t1, t2, t3为相机外参标定量
    float          t2;
    float          t3;
    float          pReserved[13];                    ///< 保留参数
}PLAYM4_SRCAMERA_PARAM;

//新的小鹰眼相机外参外部输入结构体
typedef struct tagPLAYM4NewEagleEyeParam
{
    int                     nType;                            ///< 参数调整类型, 1为调整nMode, 2为调整nDistance, 4为调整相机外参，上述参数可以进行组合，如3表示同时调整nMode和nDistance
    int                     nCameraIndex;                     ///< 相机编号(目前八个相机编号分别为0-7)
    int                     nMode;                            ///< 外参调整模式，目前有三种模式,0表示手动标定工具，1表示产线标定，2表示自动标定
    float                   nDistance;                        ///< 实际投影距离（产线距离为1.5）,单位为米
    PLAYM4_SRCAMERA_PARAM   stCamParam;                       ///< 相机外参结构体
    float                   pReserved[8];                     ///< 保留参数
}PLAYM4_SRNEW_EAGLEEYE_PARAM;

#endif

//nCfgType为0x499表示设置碗型鹰眼，pValue对应PLAYM4SRMODELMODE；碗型鹰眼码流必须先设置此类型；
//nCfgType为0x498表示设置碗型鹰眼离线调参用，老协议设备，pValue对应PLAYM4SREAGLEEYEPRAM；
//nCfgType为0x497表示设置碗型鹰眼离线调参用，新协议设备，pValue对应PLAYM4_SRNEW_EAGLEEYE_PARAM；
PLAYM4_API BOOL __stdcall PlayM4_SR_SetConfig(LONG nPort, int nCfgType, void *pValue);

PLAYM4_API BOOL __stdcall PlayM4_SR_Rotate(LONG nPort, PLAYM4SRTRANSFERPARAM *pstRotateParam);

#define SR_JPEG    0
#define SR_BMP     1

PLAYM4_API BOOL __stdcall PlayM4_SR_Capture(LONG nPort, unsigned int nType, char *pFileName);

#ifndef PLAYM4_PICTURE_FILL_TAG
#define PLAYM4_PICTURE_FILL_TAG

typedef struct _PICTURE_FILL_INFO_   //图片填充信息
{
    int                 nType;          //支持类型 1：表示语义分割的图片透明度调节
                                        //         2：表示规则框的线条粗细
    int                 nAlpha;         //透明度范围[0,100], 0表示完全透明，100表示不透明
    int                 reserved[10];   //扩展预留 nType:2时，reserved[0]表示规则框线宽，范围1-10

}PICTURE_FILL_INFO;

#endif

//图片或者区域的填充参数配置
PLAYM4_API BOOL __stdcall PlayM4_SetPicOrRegionFillPara(LONG nPort, PICTURE_FILL_INFO* pstPicFillInfo);

#ifndef PLAYM4_PICTURE_STREAM_TYPE
#define PLAYM4_PICTURE_STREAM_TYPE

typedef enum tagPLAYM4StreamType
{
	PLAYM4_VIDEO = 0,            
	PLAYM4_AUDIO  = 1,          
	PLAYM4_VIDEOANDAUDIO = 2,               
}PLAYM4StreamType;

#endif

PLAYM4_API BOOL  __stdcall  PlayM4_SetStreamType(LONG nPort, PLAYM4StreamType eType);

#ifndef PLAYM4_WATERMARK_FONT_INFO
#define PLAYM4_WATERMARK_FONT_INFO

//水印字体大小
typedef struct tagWatermarkFontSize
{
	unsigned int nFontWidth;         // 字体宽 大于0
	unsigned int nFontHeight;        // 字体高 大于0
}WATERMARK_FONTSIZE;

//水印叠加个数
typedef struct tagWatermarkNumber
{
	unsigned int nRowNumber;        // 行数,nFillFullScreen为true时，需要用到此参数,小于14
	unsigned int nColNumber;        // 列数，小于14
}WATERMARK_NUMBER;

//水印自适应信息
typedef struct tagWatermarkWindowAdapt
{
	unsigned int nWindowAdaptMode;  // 0 – 固定字体大小和固定行列数（不进行自适应计算，按输入参数WATERMARK_FONTSIZE和WATERMARK_NUMBER的值进行显示）；1 – 字体行列数进行自适应改变（字体大小不变，WATERMARK_NUMBER的值失效）；  2 – 字体大小进行自适应改变 （行列数不变）
	unsigned int nRowSpace;         // 设置自适应行列数行间距 nWindowAdaptMode == 1时用到。计算方式：如输入nRowSpace = 300，当前窗口大小 = 900，行数 = 900/300 = 3。当窗口大小增大到1200时，行数自适应调整 = 1200/300 = 4
	unsigned int nColSpace;         // 设置自适应行列数列间距nWindowAdaptMode == 1时用到
	unsigned int nBaseWindowWidth;  // 设置字体比例的基准窗口宽 nWindowAdaptMode == 2时用到。计算方式：输入stWatermarkFontSize. nFontWidth = 20，nBaseWindowWidth = 900，字体大小 =当前窗口宽 * 20 / 900 。如当前窗口宽为1200时，字体大小 = 1200 * 20 / 900 = 26
	unsigned int nBaseWindowHeight; // 设置字体比例的基准窗口宽nWindowAdaptMode == 2时用到
}WATERMARK_WINDOWADAPT;

//水印旋转信息
typedef struct tagWatermarkRotateInfo
{
	float fRotateAngle;               // 旋转角度，单位度（0~360度）
	unsigned int nFillFullScreen;     // 为true表示铺满全屏，会在画面中斜体显示n个，false表示只显示一行
}WATERMARK_ROTATEINFO;

/*水印对齐方式*/
typedef enum tagWaterMarkAlignment
{
	CENTER_ALIGNMENT   = 0,       // 居中对齐
	LEFT_ALIGNMENT     = 1        // 左对齐
}WATERMARK_ALIGNMENT;

//水印信息结构体
typedef struct _WATERMARK_FONT_INFO_
{
	char**                WatermarkFontArray;       //水印信息数组地址，表示char*数组首地址，每个char*元素表示一行字
	unsigned int*         WatermarkFontLengthArray; //每行字的字符串长度，单行小于200
	unsigned int          WatermarkFontNum;         //水印信息数组个数，表示有几行字，小于9
	float                 fFontSpace;               //多行字间距：建议取值范围（1~2），表示字体高的倍数，1就是紧贴
	unsigned int          nColorAdapt;              //颜色自适应
	WATERMARK_ALIGNMENT   emFontAlign;              //多行字的对齐方式：
	PTZPARAM              stWatermarkStartPos;      //水印叠加坐标
	FECCOLOR              stWatermarkColor;         //水印颜色
	WATERMARK_FONTSIZE    stWatermarkFontSize;      //水印字体大小
	WATERMARK_ROTATEINFO  stWatermarkRotateInfo;    //水印旋转信息
	WATERMARK_NUMBER      stWatermarkNumber;        //水印叠加个数
	WATERMARK_WINDOWADAPT stWatermarkWindowAdapt;   //水印自适应信息
	char                  nWatermarkDisplayStyle;   //水印叠加样式，设置1表示白字描黑边样式，设置1后水印颜色、颜色自适应功能均不生效；
	char                  nOverlayGlobalTime;       //表示是否需要播放库内部叠加全局时间，设置为1表示需要叠加，则播放库在第一行水印固定叠加全局时间，外部设置水印内容从第二行开始；
	char                  reserved[18];             //保留数组
}WATERMARK_FONT_INFO;

#endif

//1.此接口设置水印中文字符只支持utf8格式；
//2.此接口只支持在画面播放后调用，即PlayM4_Play接口后调用生效，播放前调用无效；
//3.此接口只支持在D3D11渲染引擎下生效，集显电脑一般需要调用播放库接口切换D3D11渲染引擎；
PLAYM4_API BOOL __stdcall PlayM4_SetWatermarkFont(int nPort, WATERMARK_FONT_INFO* pWatermarkFontInfo, void* nReserved);
//PLAYM4_API int __stdcall PlayM4_SetPlayCtrlLogFlag(bool bFlag, char* pConfigFilePath, PLAYM4_LOG_LEVEL emLogLevel);
///回放播放过程中，重新送流后，从送流前最后一帧的那个时刻开始播放，保持衔接准确，
//nFlag：1表示接口起效，从当前播放帧开始衔接
PLAYM4_API BOOL __stdcall PlayM4_PlayFromCurrentFrame(int nPort, int nFlag, void* pRes);

///开启倍速自适应丢帧功能后，当前是否触发丢帧
PLAYM4_API BOOL __stdcall PlayM4_GetLostFrameState(int nPort, int* pLostFrameState, void* pRes);

//为达到帧级别平滑拖动的来回变换方向或者正倒放切换的画面流畅性，播放库会增加一种大缓存模式，
//即存储更多的解码后的帧，保证来回变换方向时能够快速响应，因此设置如下接口，来开启大缓存模式；
//此接口软解下可设置最大200个，D3D11硬解下只可以设置最大50个，D3D9硬解码不支持设置大缓存；
PLAYM4_API BOOL __stdcall PlayM4_SetBigBufMode(LONG nPort, DWORD nBufNum, void* pReserved);

//GOP的系统时间
typedef struct 
{
	BOOL                 GetGOPSystemTimeFlag; //是否可以获取到接下来会送到播放库的GOP的首帧和尾帧的系统时间
	PLAYM4_SYSTEM_TIME   stGOPStartSystemTime; //接下来会送到播放库GOP的首帧I帧的系统时间
	PLAYM4_SYSTEM_TIME   stGOPEndSystemTime;  //接下来会送到播放库的GOP尾帧P帧的系统时间
	int                  nReserved[10];       //保留字节
} PLAYM4_GOP_SYSTEM_TIME;

//平滑拖动系统时间通知接口，主要功能是告知播放库定位播放哪一帧，该接口是异步接口，
//该接口只是设置下系统时间，播放库内部收到系统时间后，接口立刻返回成功，然后播放库内部线程执行寻找该帧并进行播放
//stSystemTime：表示平滑拖动要播放时刻的系统时间（实际是进度条上的系统时间，和帧里面打的系统时间可能不一样，此时播放库只能找到近似的帧）；
//bFlag：表示是否启动帧级别的平滑拖动，为true表示启动，此时stSystemTime才有作用，当为false时，表示取消帧级别的定位播放，恢复原先的平滑拖动方式，即只解码I帧的方式；
//stGOPSystemTime：表示帧级别平滑拖动时会送给播放库的GOP的系统时间；

PLAYM4_API BOOL __stdcall PlayM4_PlayOneFrameBySystemTime(LONG nPort, PLAYM4_SYSTEM_TIME stSystemTime, BOOL bFlag, PLAYM4_GOP_SYSTEM_TIME stGOPSystemTime );


///<预录像相关接口//////////////////////////////////////////////////////////////////////////
#define PLAYM4_MEDIA_HEAD     1   //系统头数据
#define PLAYM4_VIDEO_DATA     2   //视频流数据
#define PLAYM4_AUDIO_DATA     3   //音频流数据
#define PLAYM4_PRIVT_DATA     4   //私有流数据

//预录像数据信息
typedef struct  
{
    long nType;                     // 数据类型，如文件头，视频，音频，私有数据等
    long nStamp;                    // 时间戳
    long nFrameNum;                 // 帧号
    long nBufLen;                   // 数据长度
    char* pBuf;                     // 帧数据，以帧为单位回调
    PLAYM4_SYSTEM_TIME  stSysTime;  // 全局时间
}RECORD_DATA_INFO;


/////////////////////////////////////////////////////////////////////////////////////////////
//Unproposed Interface 不建议使用的接口
/////////////////////////////////////////////////////////////////////////////////////////////
PLAYM4_API BOOL __stdcall PlayM4_RigisterDrawFun(LONG nPort,void (CALLBACK* DrawFun)(long nPort,HDC hDc,void* nUser),void* nUser);
PLAYM4_API BOOL __stdcall PlayM4_SetDecCallBack(LONG nPort,void (CALLBACK* DecCBFun)(long nPort,char * pBuf,long nSize,FRAME_INFO * pFrameInfo, void* nReserved1,void* nReserved2));
PLAYM4_API BOOL __stdcall PlayM4_SetDecCallBackEx(LONG nPort,void (CALLBACK* DecCBFun)(long nPort,char * pBuf,long nSize,FRAME_INFO * pFrameInfo, void* nReserved1,void* nReserved2), char* pDest, long nDestSize);
PLAYM4_API BOOL __stdcall PlayM4_SetSycStartTime(LONG nPort, PLAYM4_SYSTEM_TIME *pstSystemTime);
PLAYM4_API BOOL __stdcall PlayM4_SyncToAudio(LONG nPort, BOOL bSyncToAudio);
PLAYM4_API BOOL __stdcall PlayM4_SetDecodeEngine(LONG nPort, DWORD nDecodeEngine);
PLAYM4_API BOOL __stdcall PlayM4_SetRunTimeInfoCallBack(LONG nPort, void (CALLBACK* RunTimeInfoCBFun)(long nPort, RunTimeInfo* pstRunTimeInfo, void* pUser), void* pUser);

//Hlog写日志开关接口。任一port的开关操作对该进程中所有port都会起作用。目前配置文件路径参数不起作用，作为后续可能的扩展功能预留。
PLAYM4_API BOOL __stdcall PlayM4_SetHLogFlag(int nPort, BOOL bFlag, char* pConfigFilePath);

/////////////////////////////////////////////////////////////////////////////////////////////
//Unsupported Interface 不再支持的接口
/////////////////////////////////////////////////////////////////////////////////////////////
//设置预录像开关，bFlag=1开启，bFlag=0关闭
PLAYM4_API BOOL __stdcall PlayM4_SetPreRecordFlag(LONG lPort, BOOL bFlag);
//预录像数据数据回调
PLAYM4_API BOOL __stdcall PlayM4_SetPreRecordCallBack(LONG lPort, void (CALLBACK* PreRecordCBfun)(long nPort, RECORD_DATA_INFO* pRecordDataInfo, void* pUser), void* pUser);
PLAYM4_API BOOL __stdcall PlayM4_InitDDraw(HWND hWnd);
PLAYM4_API BOOL __stdcall PlayM4_RealeseDDraw();
PLAYM4_API BOOL __stdcall PlayM4_SetFileEndMsg(LONG nPort,HWND hWnd,UINT nMsg);
PLAYM4_API int  __stdcall PlayM4_GetCaps();
PLAYM4_API BOOL __stdcall PlayM4_SetOverlayMode(LONG nPort,BOOL bOverlay,COLORREF colorKey);
PLAYM4_API LONG __stdcall PlayM4_GetOverlayMode(LONG nPort);
PLAYM4_API COLORREF __stdcall PlayM4_GetColorKey(LONG nPort);
PLAYM4_API BOOL __stdcall PlayM4_InitDDrawDevice();
PLAYM4_API void __stdcall PlayM4_ReleaseDDrawDevice();
PLAYM4_API DWORD __stdcall PlayM4_GetDDrawDeviceTotalNums();
PLAYM4_API BOOL __stdcall PlayM4_SetDDrawDevice(LONG nPort,DWORD nDeviceNum);
PLAYM4_API BOOL __stdcall PlayM4_GetDDrawDeviceInfo(DWORD nDeviceNum,LPSTR  lpDriverDescription,DWORD nDespLen,LPSTR lpDriverName ,DWORD nNameLen,HMONITOR *hhMonitor);
PLAYM4_API int  __stdcall PlayM4_GetCapsEx(DWORD nDDrawDeviceNum);
PLAYM4_API BOOL __stdcall PlayM4_SetDDrawDeviceEx(LONG nPort,DWORD nRegionNum,DWORD nDeviceNum);
PLAYM4_API BOOL __stdcall PlayM4_OpenStreamEx(LONG nPort,PBYTE pFileHeadBuf,DWORD nSize,DWORD nBufPoolSize);
PLAYM4_API BOOL __stdcall PlayM4_CloseStreamEx(LONG nPort);
PLAYM4_API BOOL __stdcall PlayM4_InputVideoData(LONG nPort,PBYTE pBuf,DWORD nSize);
PLAYM4_API BOOL __stdcall PlayM4_InputAudioData(LONG nPort,PBYTE pBuf,DWORD nSize);
PLAYM4_API BOOL __stdcall PlayM4_SetTimerType(LONG nPort,DWORD nTimerType,DWORD nReserved);
PLAYM4_API BOOL __stdcall PlayM4_GetTimerType(LONG nPort,DWORD *pTimerType,DWORD *pReserved);
PLAYM4_API BOOL __stdcall PlayM4_SetVerifyCallBack(LONG nPort, DWORD nBeginTime, DWORD nEndTime, void (__stdcall * funVerify)(long nPort, FRAME_POS * pFilePos, DWORD bIsVideo, DWORD nUser),  DWORD  nUser);
PLAYM4_API BOOL __stdcall PlayM4_SetAudioCallBack(LONG nPort, void (__stdcall * funAudio)(long nPort, char * pAudioBuf, long nSize, long nStamp, long nType, long nUser), long nUser);
PLAYM4_API BOOL __stdcall PlayM4_SetEncChangeMsg(LONG nPort,HWND hWnd,UINT nMsg);
PLAYM4_API BOOL __stdcall PlayM4_GetOriginalFrameCallBack(LONG nPort, BOOL bIsChange,BOOL bNormalSpeed,long nStartFrameNum,long nStartStamp,long nFileHeader,void(CALLBACK *funGetOrignalFrame)(long nPort,FRAME_TYPE *frameType, long nUser),long nUser);
PLAYM4_API BOOL __stdcall PlayM4_GetFileSpecialAttr(LONG nPort, DWORD *pTimeStamp,DWORD *pFileNum ,DWORD *pReserved);
PLAYM4_API BOOL __stdcall PlayM4_SetPlayMode(LONG nPort,BOOL bNormal);
PLAYM4_API BOOL __stdcall PlayM4_SetOverlayFlipMode(LONG nPort,BOOL bTrue);
PLAYM4_API BOOL __stdcall PlayM4_SetPicQuality(LONG nPort,BOOL bHighQuality);
PLAYM4_API BOOL __stdcall PlayM4_GetPictureQuality(LONG nPort,BOOL *bHighQuality);
/////////////////////////////////////////////////////////////////////////////////////////////

PLAYM4_API BOOL __stdcall PlayM4_SetGlobalBaseTime(long nPort, PLAYM4_SYSTEM_TIME stGlobalBaseTime);

#endif //_PLAYM4_H_
