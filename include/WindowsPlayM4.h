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
#define  PLAYM4_INVALID_SYNCGROUP               35  // ��Чͬ���ط������
#define  PLAYM4_FAIL_UNKNOWN                    99  //Fail, but the reason is unknown;	

//���۹��ܴ�����
#define PLAYM4_FEC_ERR_ENABLEFAIL               100 // ����ģ�����ʧ��
#define PLAYM4_FEC_ERR_NOTENABLE                101 // ����ģ��û�м���
#define PLAYM4_FEC_ERR_NOSUBPORT                102 // �Ӷ˿�û�з���
#define PLAYM4_FEC_ERR_PARAMNOTINIT             103 // û�г�ʼ����Ӧ�˿ڵĲ���
#define PLAYM4_FEC_ERR_SUBPORTOVER              104 // �Ӷ˿��Ѿ�����
#define PLAYM4_FEC_ERR_EFFECTNOTSUPPORT         105 // �ð�װ��ʽ������Ч����֧��
#define PLAYM4_FEC_ERR_INVALIDWND               106 // �Ƿ��Ĵ���
#define PLAYM4_FEC_ERR_PTZOVERFLOW              107 // PTZλ��Խ��
#define PLAYM4_FEC_ERR_RADIUSINVALID            108 // Բ�Ĳ����Ƿ�
#define PLAYM4_FEC_ERR_UPDATENOTSUPPORT         109 // ָ���İ�װ��ʽ�ͽ���Ч�����ò������²�֧��
#define PLAYM4_FEC_ERR_NOPLAYPORT               110 // ���ſ�˿�û������
#define PLAYM4_FEC_ERR_PARAMVALID               111 // ����Ϊ��
#define PLAYM4_FEC_ERR_INVALIDPORT              112 // �Ƿ��Ӷ˿�
#define PLAYM4_FEC_ERR_PTZZOOMOVER              113 // PTZ������ΧԽ��
#define PLAYM4_FEC_ERR_OVERMAXPORT              114 // ����ͨ�����ͣ����֧�ֵĽ���ͨ��Ϊ64��
#define PLAYM4_FEC_ERR_ENABLED                  115 // �ö˿��Ѿ�����������ģ��
#define PLAYM4_FEC_ERR_D3DACCENOTENABLE         116 // D3D����û�п���
#define PLAYM4_FEC_ERR_PLACETYPE                117 // ��װ��ʽ����.һ�����ſ�port����Ӧһ�ְ�װ��ʽ
#define PLAYM4_FEC_ERR_CorrectType              118 // ������ʽ�����������ʽ����,���ܿ����������һ�����ſ�port,�趨����PTZ�����۰��������ʽ��,�����Ľ�����ʽ��ֻ�ܿ�һ·;����180�Ƚ������ܺ�ptz����һ�𿪣���������������������޹����ԡ�
#define PLAYM4_FEC_ERR_NULLWND                  119 // ���۴���Ϊ��
#define PLAYM4_FEC_ERR_PARA                     120 // ���۲�������
#define PLAYM4_FEC_ERR_INVALID_OPERATION        121 // ���۱仯�����У�������Ч

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

// ���º궨������HIK_MEDIAINFO�ṹ
#define FOURCC_HKMI         0x484B4D49  // "HKMI" HIK_MEDIAINFO�ṹ���

// ϵͳ��װ��ʽ
#define SYSTEM_NULL         0x0         // û��ϵͳ�㣬����Ƶ������Ƶ��
#define SYSTEM_HIK          0x1         // �����ļ���
#define SYSTEM_MPEG2_PS     0x2         // PS��װ
#define SYSTEM_MPEG2_TS     0x3         // TS��װ
#define SYSTEM_RTP          0x4         // rtp��װ
#define SYSTEM_MPEG4        0x5         ///< MP4��װ
#define SYSTEM_AVI          0x7         ///< AVI��װ
#define SYSTEM_RTMP         0xD         // rtmp��װ
#define SYSTEM_RTPHIK       0x401       // rtp��װhik
#define SYSTEM_RTP_JT       0x104       // rtpjt��װ
#define SYSTEM_DAH          0x8001      // �󻪷�װ
#define SYSTEM_FLV          0x000A          ///< FLV��װ֧��

// ��Ƶ��������
#define VIDEO_NULL          0x0 // û����Ƶ
#define VIDEO_H264          0x1 // ����H.264
#define VIDEO_MPEG2         0x2 // ��׼MPEG2
#define VIDEO_MPEG4         0x3 // ��׼MPEG4
#define VIDEO_MJPEG         0x4
#define VIDEO_AVC265        0x5 // ��׼H265/AVC
#define VIDEO_SVAC          0x6
#define VIDEO_AVC264        0x0100

// ��Ƶ��������
#define AUDIO_NULL          0x0000 // û����Ƶ
#define AUDIO_ADPCM         0x1000 // ADPCM
#define AUDIO_MPEG          0x2000 // MPEG ϵ����Ƶ��������������Ӧ����MPEG��Ƶ
#define AUDIO_AAC           0X2001 // AAC ����
#define AUDIO_RAW_DATA8     0x7000 //������Ϊ8k��ԭʼ����
#define AUDIO_RAW_UDATA16   0x7001 //������Ϊ16k��ԭʼ���ݣ���L16
// Gϵ����Ƶ
#define AUDIO_RAW_DATA8     0x7000      //������Ϊ8k��ԭʼ����
#define AUDIO_RAW_UDATA16   0x7001      //������Ϊ16k��ԭʼ���ݣ���L16
#define AUDIO_G711_U        0x7110
#define AUDIO_G711_A        0x7111
#define AUDIO_G722_1        0x7221
#define AUDIO_G723_1        0x7231
#define AUDIO_G726_U        0x7260
#define AUDIO_G726_A        0x7261
#define AUDIO_G726_16       0x7262
#define AUDIO_G729          0x7290
#define AUDIO_AMR_NB        0x3000

#define SYNCDATA_VEH        1 //ͬ������:������Ϣ
#define SYNCDATA_IVS        2 //ͬ������:������Ϣ

//motion flow type
#define	MOTION_FLOW_NONE    0
#define MOTION_FLOW_CPU     1
#define MOTION_FLOW_GPU     2

//����Ƶ��������
#define ENCRYPT_AES_3R_VIDEO     1
#define ENCRYPT_AES_10R_VIDEO    2
#define ENCRYPT_AES_3R_AUDIO     1
#define ENCRYPT_AES_10R_AUDIO    2

///<��ת�Ƕ�
#define R_ANGLE_0           -1      //����ת
#define R_ANGLE_L90         0       //������ת90��
#define R_ANGLE_R90         1       //������ת90��
#define R_ANGLE_180         2       //��ת180��


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
    DWORD dwDataType;       //����������ͬ���ĸ�����Ϣ���ͣ�Ŀǰ�У�������Ϣ��������Ϣ
    DWORD dwDataLen;        //������Ϣ���ݳ���
    BYTE* pData;            //ָ������Ϣ���ݽṹ��ָ��,����IVS_INFO�ṹ
} SYNCDATA_INFO;

// ��չ��Ϣ�ṹ��
typedef struct
{
    unsigned char        privt_type;                     // �û���չ����:���IVS_PRIVT_INFO��10��ʾ��ɫ+Υ��Ʒ����
    unsigned char        reseverd[6];                    // Ŀ��������չ
    unsigned char        privt_len;                      // �û���չ��Ϣ����
    unsigned char        privt_data[32];                 // �û���չ��Ϣ
}IS_PRIVT_INFO;

// ��ɫ�ṹ��
typedef struct
{
    unsigned char red;
    unsigned char green;
    unsigned char blue;
    unsigned char alpha;
}IS_PRIVT_INFO_COLOR;

// Υ������ɫ�ṹ��
typedef struct
{
    IS_PRIVT_INFO_COLOR color;                  // ��ɫ
    unsigned char       confidence;             // Υ��Ʒ���Ŷ�
    unsigned char       pos_len;                // Υ��Ʒ���Ƴ���
    unsigned char       pos_data[22];           // Υ��Ʒ����
    unsigned int        type;                   // Υ��Ʒ����
}IS_PRIVT_INFO_CONTRABAND;

typedef struct _VCA_RECT_F_
{
    float x;         //�������Ͻ�X������
    float y;         //�������Ͻ�Y������
    float width;     //���ο��
    float height;    //���θ߶�
}VCA_RECT_F;

//Ŀ����Ϣ�ṹ��
typedef struct _VCA_TARGET_EX
{
    unsigned int      ID;          //ID
    unsigned char     reserved[8]; //�����ֽ�
    VCA_RECT_F        rect;        //Ŀ���
    unsigned char     reserved1[40]; //˽����Ϣ��չ�ֶΣ���ʱ��unsigned char�����ʾ������ⲿ�������ٸ�֪����ṹ����Ϣ
}VCA_TARGET_EX;

typedef struct _VCA_TARGET_LIST_EX
{
    unsigned int    target_num;             //Ŀ������
    VCA_TARGET_EX   *pstTarget;             //Ŀ�����ݣ�����VCA_TARGET_EX�Ĵ�С����ƫ�ƶ�ȡ����Ŀ��������Ϣ����
}VCA_TARGET_LIST_EX;

//������Ϣ�ṹ��ص���
typedef struct _INTEL_INFO_EX
{
    unsigned int                   type;               ///< ��ǻص�������Щ˽����Ϣ����
    VCA_TARGET_LIST_EX             stTarget;           ///< Ŀ��
    VCA_TARGET_LIST_EX             stTarget_EX;        ///< ��������Ŀ��
}INTEL_INFO_EX;
/////////////////////////////////////////////////////////////////////////////////////////////
//IVS��������Ϣ�ص��ӿڽṹ�嶨��
/////////////////////////////////////////////////////////////////////////////////////////////

///                                Ŀ���                           ///
typedef struct _VCA_POINT_F_
{
    float x;
    float y;
}VCA_POINT_F;

//�����(������)
typedef struct _VCA_POLYGON_F_
{
    unsigned int  vertex_num;                  //������
    VCA_POINT_F   point[10];   //����
}VCA_POLYGON_F;

//��ת����
typedef struct _VCA_ROTATE_RECT_F_
{
    float				  cx;						// �������ĵ�X������
    float				  cy;						// �������ĵ�Y������
    float				  width;					// ���ο��
    float				  height;					// ���θ߶�
    float				  theta;				   // ��ת���νǶ�
}VCA_ROTATE_RECT_F;

//����������
typedef struct _VCA_REGION_
{
    unsigned int region_type;           // �ο�VCA_REGION_TYPE��2��ʾ����Σ�3��ʾ����
    char         reserved[12];
    union
    {
        unsigned char		size[84];
        VCA_POLYGON_F       polygon;                // �����
        VCA_RECT_F          rect;                   // ����
        VCA_ROTATE_RECT_F 	rotate_rect;	 		 // ��ת����,�ݲ�֧��
    };
}VCA_REGION;

//����Ŀ���ṹ��
typedef struct 
{
    unsigned int            id;
    unsigned int            blob_type;        // Ŀ����_OBJ_TYPE
    short                   confidence;       // Ŀ������Ŷ�
    char                    reserved[14];
    VCA_REGION              region;           // Ŀ��λ������
    unsigned char           privt_info[40];   // ��չ��Ϣ
}HIK_TARGET_BLOB_EX;

//Ŀ����б���Ϣ���壺
typedef struct _VCA_TARGET_LIST_V1_EX_
{
    unsigned int         LineType;      //�����ͣ�0��ʾ���ο�1��ʾ�Ľǿ�
    unsigned int         target_num;    //Ŀ������
    HIK_TARGET_BLOB_EX   *pstTarget;    //Ŀ�����ݣ�����HIK_TARGET_BLOB_EX�Ĵ�С����ƫ�ƶ�ȡ����Ŀ��������Ϣ����
}VCA_TARGET_LIST_V1_EX;

///                                �����                           ///
//���������ṹ��
typedef struct _VCA_RULE_EX
{
    unsigned char       ID;               //����ID
    unsigned char       reserved[15];       //�����ֽ�
    VCA_POLYGON_F       polygon;         //�����Ӧ�Ķ��������
    unsigned char       privt_info[40];      // ��չ��Ϣ
}VCA_RULE_EX;

//������б���Ϣ���壺
typedef struct _VCA_RULE_LIST_V3_EX_
{
    unsigned int  LineType;      //�����ͣ�0��ʾ���ο�1 ��ʾ�Ľǿ�
    unsigned int  rule_num;     //�����й�������
    VCA_RULE_EX   *pstRule;   //�������ݣ�����VCA_RULE_EX�Ĵ�С����ƫ�ƶ�ȡ����Ŀ��������Ϣ����
}VCA_RULE_LIST_V3_EX;

///                                ������                           ///

typedef struct  _VCA_ALERT_EX_
{
    unsigned char     alert;           //���ޱ�����Ϣ: 0-û�У�1-��
    unsigned char     reserved[7];     //�����ֽ�
    VCA_RULE_EX       rule_info;       //����������Ϣ
    VCA_TARGET_EX        target;          //����Ŀ����Ϣ
    unsigned char     privt_info[40];  // ��չ��Ϣ
}VCA_ALERT_EX;

//������Ϣ���壺
typedef struct  _VCA_ALERT_LIST_EX_
{
    unsigned int           alert_num;  //��������
    VCA_ALERT_EX           *pstAlert; 
}VCA_ALERT_LIST_EX;

//������Ϣ��
typedef struct  _VCA_INTEL_INFO_
{
	unsigned int   nDataLen;        //������Ϣ���ݳ���
	unsigned char  *pData;          //ָ������Ϣ���ݽṹ��ָ��
}VCA_INTEL_INFO;

typedef struct PlAYM4_TI_OSD_LINT_EX 
{
    unsigned int     nOffsetX;        ///< For the x coordinate of the OSD
    unsigned int     nOffsetY;        ///< For the y coordinate of the OSD
    unsigned short   nLength;         ///< The length of this osd line
    unsigned char    chAlignment;      ///< Horizontal/Vertical Alignment Refers to the relative position of the upper left corner of the string
    unsigned char    chType;          //0xD2��ʾˮӡ��������
    unsigned char    chRes[16];         //16�������ֽڣ���ʾ��������չ�ṹ�壬������ʱ�ٸ���chType���нṹ��ת��
    unsigned char    chCode[128];    ///<  @Def:    the string on osd. This must be ROUND_UP(strlen(code), 0x10)
}PlAYM4_TI_OSD_LINE_EX;

/**	@struct PlAYM4_TI_OSD_INFO_EX_
 *	@brief  �����ı���Ϣͷ�ṹ��
 */
typedef struct  PlAYM4_TI_OSD_INFO_EX_
{
	unsigned char           chDepartment;      ///<����
	unsigned char           chARType;         ///<�㷨����
    unsigned char           chRes[14];          //�����ֽ�
    unsigned short          nLanguage;    ///<  @Def:    osd language    
	unsigned short          nColor;       ///<  @Arg:    TI_OSD_COLOR_##
    unsigned int            nLineNum;     ///<  @Def:    OSD line numbers   
    unsigned int            nCharWidth;   ///<  @Def:    Char width of OSD  
	unsigned int            nCharHeight;  ///<  @Def:    Char height of OSD 
	unsigned int            nWinWidth;    ///<  @Def:    Window width of OSD
	unsigned int            nWinHeight;   ///<  @Def:    Window height of OSD
    PlAYM4_TI_OSD_LINE_EX   *pstLine;    ///<  @Def:    This is followed by "nLineNum" in line
}PlAYM4_POS_OSD_INFO_EX;

//������Ϣ�ṹ��ص���
typedef struct _PRIVATE_INFO_
{
	unsigned int                  type;      ///< ��ǻص�������Щ˽����Ϣ����
	VCA_TARGET_LIST_V1_EX         stTarget;           ///< ��ͨĿ������� 1
	VCA_TARGET_LIST_V1_EX         stTarget_EX;        ///< ��������Ŀ������� 2
	VCA_RULE_LIST_V3_EX           stRule;             ///< ��ͨ��������� 4
	VCA_RULE_LIST_V3_EX           stRule_EX;          ///< ����������������� 8
	VCA_ALERT_LIST_EX             stAlert;            ///< ������Ϣ������ 16
	VCA_INTEL_INFO                stTempInfo;         ///< ������Ϣ������ 32
	PlAYM4_POS_OSD_INFO_EX        stPosInfo_EX;       ///< ��ȷ�ı�POS��Ϣ������ 64
	PlAYM4_POS_OSD_INFO_EX        stPosInfo;          ///< ��ͨ�ı�POS��Ϣ������ 128
} PRIVATE_INFO;

/////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _HIK_MEDIAINFO_FLAG_
#define _HIK_MEDIAINFO_FLAG_
typedef struct _HIK_MEDIAINFO_
{
    unsigned int    media_fourcc;           // "HKMI": 0x484B4D49 Hikvision Media Information
    unsigned short  media_version;          // �汾�ţ�ָ����Ϣ�ṹ�汾�ţ�ĿǰΪ0x0101,��1.01�汾��01�����汾�ţ�01���Ӱ汾�š�
    unsigned short  device_id;              // �豸ID�����ڷ���
    unsigned short  system_format;          // ϵͳ��װ��
    unsigned short  video_format;           // ��Ƶ��������
    unsigned short  audio_format;           // ��Ƶ��������
    unsigned char   audio_channels;         // ͨ����  
    unsigned char   audio_bits_per_sample;  // ��λ��
    unsigned int    audio_samplesrate;      // ������ 
    unsigned int    audio_bitrate;          // ѹ����Ƶ����,��λ��bit
    unsigned int    reserved[4];            // ����
}HIK_MEDIAINFO;
#endif

#ifndef _HIK_STREAM_INFO_FLAG_
#define _HIK_STREAM_INFO_FLAG_
typedef struct _STREAM_INFO_
{
	unsigned short  system_format;          // ϵͳ��װ��
	unsigned short  video_format;           // ��Ƶ��������
	unsigned short  audio_format;           // ��Ƶ��������
	unsigned char   audio_channels;         // ͨ����  
	unsigned char   audio_bits_per_sample;  // ��λ��
	unsigned int    audio_samplesrate;      // ������ 
	unsigned int    audio_bitrate;          // ѹ����Ƶ����,��λ��bit
	unsigned int    reserved[10];            // ����
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
    long         nPort;        //ͨ����
    char         *pBuf;        //���صĵ�һ·ͼ������ָ��
    unsigned int nBufLen;      //���صĵ�һ·ͼ�����ݴ�С
    char         *pBuf1;       //���صĵڶ�·ͼ������ָ��
    unsigned int nBufLen1;     //���صĵڶ�·ͼ�����ݴ�С
    char         *pBuf2;       //���صĵ���·ͼ������ָ��
    unsigned int nBufLen2;     //���صĵ���·ͼ�����ݴ�С
    unsigned int nWidth;       //�����
    unsigned int nHeight;      //�����
    unsigned int nStamp;       //ʱ����Ϣ����λ����
    unsigned int nType;        //��������
    void         *pUser;       //�û�����
    unsigned int reserved[4];  //����,reserved[0]����֡��,res[1]-res[3]����ȫ��ʱ�䣬res[1]-�����գ�res[2]-ʱ���룬res[3]-����
}DISPLAY_INFO_YUV;

/** @struct PLAYM4_AUDIODISPLAY_INFO_S
 *  @brief  ��Ƶ��ʾ��Ϣ�ṹ��
 */
typedef struct
{
    unsigned int   uSamplesPerSec; // ������
    unsigned int   uChannels;      // ������
    unsigned int   uBitsPerSample; // λ��
    int            nFrameNum;      // ֡��
    unsigned int   uFrameTime;     // ʱ�꣬��λms
    unsigned char  reserved[8];
}PLAYM4_AUDIODISPLAY_INFO_S;

// �ⲿ����ͼƬ��ʽ
typedef enum tagPlayM4PicFormat
{
    // ͼƬ��ʽ
    PLAYM4_PIC_JPEG,       ///< JPEG

    // ���ظ�ʽ
    PLAYM4_PIC_DATA_YV12,       ///< YV12��ʽ
    PLAYM4_PIC_DATA_RGB565,     ///< RGB565��ʽ
    PLAYM4_PIC_DATA_RGBA32      ///< RGBA32��ʽ
}PLAYM4_PIC_FORMAT_E;

// ͼƬ��ʾģʽ
typedef enum tagPlayM4PicDisplayMode
{
    PLAYM4_PIC_MODE_REPLACE,       ///< �����滻ģʽ����ԭ�л����滻Ϊ�ִ���ͼƬ
    PLAYM4_PIC_MODE_OVERLAY        ///< �������ģʽ�����ִ���ͼƬ������ԭ�л�����
}PLAYM4_PIC_DISPLAY_MODE_E;

/** @struct    PlayM4_PicRect
 *  @brief     ͼƬ��������λ��
 */
typedef struct PlayM4_PicRect
{
    float fTopLeftX;    // ���Ͻ�x���꣬��һ��0-1
    float fTopLeftY;    // ���Ͻ�y���꣬��һ��0-1
    float fWidth;       // �����������һ��0-1
    float fHeight;      // ��������ߣ���һ��0-1
}PLAYM4_PIC_RECT_S;

/** @struct    PlayM4_PicOverlayParam
 *  @brief     ͼƬ���Ӳ���
 */
typedef struct PlayM4_PicOverlayParam
{
    unsigned int      uAlpha;       // ͼ��͸����,0-100
    PLAYM4_PIC_RECT_S stPicRect;    // ͼƬ��������λ��
    int               nReserved[2];
}PLAYM4_PIC_OVERLAY_PARAM_S;

/** @struct    PLAYM4_PIC_INFO_S
 *  @brief     ͼƬ��Ϣ
 */
typedef struct PlayM4_PicInfo
{
    unsigned char*             pData;       // ͼ������
    unsigned int               uDataLen;    // ͼ�����ݴ�С
    unsigned int               uPicWidth;   // ͼ���
    unsigned int               uPicHeight;  // ͼ���
    PLAYM4_PIC_FORMAT_E        enPicFormat; // ͼ���ʽ
    PLAYM4_PIC_OVERLAY_PARAM_S stPicRect;   // ͼƬ��������λ�ã�������ģʽ��Ч
    int                        nReserved[8];
}PLAYM4_PIC_INFO_S;

typedef struct PLAYM4_SYSTEM_TIME //����ʱ��
{
    DWORD dwYear;   //��
    DWORD dwMon;    //��
    DWORD dwDay;    //��
    DWORD dwHour;   //ʱ
    DWORD dwMin;    //��
    DWORD dwSec;    //��
    DWORD dwMs;     //����
} PLAYM4_SYSTEM_TIME;

#ifndef CROP_PIC_INFO_TAG
#define CROP_PIC_INFO_TAG
typedef struct
{
    BYTE  *pDataBuf;      //ץͼ����buffer
    DWORD dwPicSize;      //ʵ��ͼƬ��С
    DWORD dwBufSize;      //����buffer��С
    DWORD dwPicWidth;     //��ͼ��
    DWORD dwPicHeight;    //��ͼ��
    DWORD dwReserve;      //���һ��reserve�ֶ�
    RECT  *pCropRect;     //ѡ������NULL, ͬ�ϵ�ץͼ�ӿ�
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
	unsigned char     MosaicType;      //���������ͣ�Ŀǰ֧��4����ʽ�� 1����ʾ��ͨ�����ˣ�2��ʾ��˹ģ�������ˣ�3��ʾ��ɫ���������, 4��ʾĿ����ID��ʾ��ʽ
	IS_INFO_COLOR  MosaicColor;    // ��ɫ��ֻ�е�����������Ϊ3��ɫ���ʱ������ɫ�������ã��������Ͳ�֧����ɫ����
	unsigned char   reserved[7];      //���ֽڶ��룬ͬʱ������չԤ��
} MOSAIC_TYPE_CONFIG;

//������Ŀ��ѡ��
typedef struct _MOSAIC_NODE_LIST_
{
	unsigned int  nID;  //Ŀ��ID
	unsigned int reserved[4]; //������չλ
}MOSAIC_NODE_LIST;

typedef struct _MOSAIC_NEED_DRAW_
{
	MOSAIC_NODE_LIST*   pMosaicNode;  //������Ŀ��ڵ�ָ�룬����nMosaicNum������ƫ�ƶ�ȡ����
	unsigned int               NodeNumber;  //�ڵ����
	unsigned int               reserved[10];  //������չλ
} MOSAIC_NEED_DRAW;

#endif

#ifndef PLAYM4_IMAGE_MATTING_TAG
#define PLAYM4_IMAGE_MATTING_TAG

typedef struct _IMAGE_MATTING_INFO_NODE_
{
	unsigned int    nID;             //��ͼ��Ŀ��ID
	unsigned char  *pBuf;            //��ͼ����ָ��
	unsigned int    nBufLen;         //��ͼ���ݴ�С
	unsigned int    nWidth;          //ͼƬ��
	unsigned int    nHeight;         //ͼƬ��
	unsigned char   privt_info[40];  //��չ��Ϣ,��IVS�����չ��Ϣ��С����һ�·��������չʹ��

}IMAGE_MATTING_INFO_NODE;

typedef struct _IMAGE_MATTING_INFO_
{
	IMAGE_MATTING_INFO_NODE*   pNodeData;    //��ͼ������Ϣ�ڵ�ָ�룬����NodeNumber������ƫ�ƶ�ȡ����
	unsigned int               NodeNumber;   //��ͼ������Ϣ�ڵ����
	unsigned int               reserved[10];  //������չλ

} IMAGE_MATTING_INFO;

typedef struct _IMAGE_MATTING_CONFIG_
{
	unsigned int    TargetType;       //���ͼ��˽����Ϣ�������ã�1:��ʾ���� 2:��ʾ����
	unsigned char   PictureType;      //�ص����������ͣ�1:��ʾJPEG;Ŀǰֻ֧�ֻص�JPEG��ʽ�����������������չ������ʽ
	unsigned char   PrivateInfoType;  //���ͼ��˽����Ϣ�������ã�1:��ʾIVSĿ�꣬Ŀǰ��֧��IVSĿ��
	unsigned char   reserved[2];      //���ֽڶ��룬ͬʱ������չԤ��
} IMAGE_MATTING_CONFIG;

#endif

//ENCRYPT Info
typedef struct{
    long nVideoEncryptType;  //��Ƶ��������
    long nAudioEncryptType;  //��Ƶ��������
    long nSetSecretKey;      //�Ƿ����ã�1��ʾ������Կ��0��ʾû��������Կ
}ENCRYPT_INFO;

///<˽����Ϣģ������
typedef enum _PLAYM4_PRIDATA_RENDER
{
    PLAYM4_RENDER_ANA_INTEL_DATA    = 0x00000001, //���ܷ���
    PLAYM4_RENDER_MD                = 0x00000002, //�ƶ����
    PLAYM4_RENDER_ADD_POS           = 0x00000004, //POS��Ϣ�����
    PLAYM4_RENDER_ADD_PIC           = 0x00000008, //ͼƬ������Ϣ
    PLAYM4_RENDER_FIRE_DETCET       = 0x00000010, //�ȳ�����Ϣ
    PLAYM4_RENDER_TEM               = 0x00000020, //�¶���Ϣ
    PLAYM4_RENDER_TRACK_TEM         = 0x00000040, //Ŀ���ƶ�·����Ϣ
    PLAYM4_RENDER_THERMAL           = 0x00000080, //���������̻�������Ϣ
}PLAYM4_PRIDATA_RENDER;

typedef enum _PLAYM4_THERMAL_FLAG
{
	PLAYM4_THERMAL_FIREMASK           = 0x00000001, //�̻�����
	PLAYM4_THERMAL_RULEGAS            = 0x00000002, //���������⣨���屨�������⸴�ù��������
	PLAYM4_THERMAL_TARGETGAS          = 0x00000004, //Ŀ��������
	PLAYM4_THERMAL_ALERTTARGETGAS     = 0x00000008, //���屨��Ŀ����
    PLAYM4_THERMAL_ISA                = 0x00000010, //��Ե����Ϣ���
}PLAYM4_THERMAL_FLAG;

typedef enum _PLAYM4_FIRE_ALARM
{
    PLAYM4_FIRE_FRAME_DIS           = 0x00000001, //������ʾ
    PLAYM4_FIRE_MAX_TEMP            = 0x00000002, //����¶�
    PLAYM4_FIRE_MAX_TEMP_POSITION   = 0x00000004, //����¶�λ����ʾ
    PLAYM4_FIRE_DISTANCE            = 0x00000008, //����¶Ⱦ���
}PLAYM4_FIRE_ALARM;

typedef enum _PLAYM4_TEM_FLAG
{
    PLAYM4_TEM_REGION_BOX             = 0x00000001, //�����
    PLAYM4_TEM_REGION_LINE            = 0x00000002, //�߲���
    PLAYM4_TEM_REGION_POINT           = 0x00000004, //�����
}PLAYM4_TEM_FLAG;

typedef enum _PLAYM4_TRACK_FLAG
{
    PLAYM4_TRACK_PEOPLE               = 0x00000001, //���ƶ�·��
    PLAYM4_TRACK_VEHICLE              = 0x00000002, //���ƶ�·��
}PLAYM4_TRACK_FLAG;

typedef enum _PLAYM4_INTEL_DATA_FLAG
{
	PLAYM4_INTEL_DATA_TARGET           = 0x00000001, //Ŀ���
	PLAYM4_INTEL_DATA_CONTRABAND       = 0x00000002, //Υ��Ʒ������ʾ
	PLAYM4_INTEL_DATA_FACE             = 0x00000004, //������������
	PLAYM4_INTEL_DATA_BODY             = 0x00000008, //�����������
}PLAYM4_INTEL_DATA_FLAG;

/////////////////////////////////////////////////////////////////////////////////////////////
//Proposed Interface ����ʹ�õĽӿ�
/////////////////////////////////////////////////////////////////////////////////////////////
///<��ʼ��
PLAYM4_API BOOL __stdcall PlayM4_GetPort(LONG* nPort);
PLAYM4_API BOOL __stdcall PlayM4_FreePort(LONG nPort);
PLAYM4_API BOOL __stdcall PlayM4_OpenFile(LONG nPort,LPSTR sFileName);
PLAYM4_API BOOL __stdcall PlayM4_CloseFile(LONG nPort);
PLAYM4_API BOOL __stdcall PlayM4_OpenStream(LONG nPort,PBYTE pFileHeadBuf,DWORD nSize,DWORD nBufPoolSize);
PLAYM4_API BOOL __stdcall PlayM4_CloseStream(LONG nPort);
PLAYM4_API BOOL __stdcall PlayM4_InputData(LONG nPort,PBYTE pBuf,DWORD nSize);
PLAYM4_API BOOL __stdcall PlayM4_SetStreamOpenMode(LONG nPort,DWORD nMode);
PLAYM4_API LONG __stdcall PlayM4_GetStreamOpenMode(LONG nPort);

// ���󱳾���ǰ������mp4��������С�д���4M���������̽��ʧ�ܣ����������ýӿڣ�
// ������ʽ̽������ֵ
// �˽ӿ���Ҫ��getport��openstream����ǰ���ã����򱨴�
// nBufLen����̽������ֵ���ȣ�Ĭ��4M����󲻳���128M
PLAYM4_API BOOL __stdcall PlayM4_SetCheckHeadBufLen(LONG nPort, DWORD nBufLen, void* nReserved);

///<����
PLAYM4_API BOOL __stdcall PlayM4_SetFileRefCallBack(LONG nPort, void (__stdcall *pFileRefDone)(DWORD nPort,void* nUser),void* nUser);
PLAYM4_API BOOL __stdcall PlayM4_GetRefValue(LONG nPort,BYTE *pBuffer, DWORD *pSize);
PLAYM4_API BOOL __stdcall PlayM4_SetRefValue(LONG nPort,BYTE *pBuffer, DWORD nSize);
PLAYM4_API BOOL __stdcall PlayM4_GetRefValueEx(LONG nPort,BYTE *pBuffer, DWORD *pSize);///< ��PlayM4_GetRefValueEx��ȣ���������֡���ͺͳ��Ȼص�
PLAYM4_API BOOL __stdcall PlayM4_GetKeyFramePos(LONG nPort,DWORD nValue, DWORD nType, PFRAME_POS pFramePos);
PLAYM4_API BOOL __stdcall PlayM4_GetNextKeyFramePos(LONG nPort,DWORD nValue, DWORD nType, PFRAME_POS pFramePos);

///<���ſ���
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
    PLAYM4_REVERSE_PLAY_NOMAL  = 0,        //���ſ�Ĭ�ϵ���ģʽ��ʵ�ַ�ʽͬPlayM4_ReversePlay����ʱnValueֵ������
    PLAYM4_REVERSE_PLAY_TIME   = 1,        //�ļ�����ʱ�������ʱ�䶨λ��ָ��λ�ý��е��ţ���ʱnValueֵ��ʾʱ�䣬��λ�Ǻ���

}PLAYM4_REVERSE_PLAY_MODE;

PLAYM4_API int __stdcall PlayM4_ReversePlayEX(long nPort, unsigned int nValue, PLAYM4_REVERSE_PLAY_MODE emType, void* pReserved);

// ��Ƶ���ε�ͼ����
#define  PLAYM4_MODE_TIME      1   //ʱ����������
#define  PLAYM4_MODE_FREQ      2   //Ƶ����������
#define  PLAYM4_MODE_TIME_FREQ 3   //ʱƵ����������

// �����ⲿͼƬ������ʾ
// 1.֧�ִ���3�����͵���Ƶ���ε�ͼ��ʱ����������-1��Ƶ����������-2��ʱƵ����������-3
//   PLAYM4_PIC_INFO_S�ṹ����չ�ֽڵ�һ���ֽ���Ϊ��ͼ�����ֶ�;
// 2.֧�ֻ��渲�ǡ��ֲ���������ģʽ��������Ƶ���ε�ͼʱ��enPicDisplayMode��������Ч��
// 3.�ⲿ����ͼƬ��ʽΪjpegʱ���ڲ���ȡ�����Ϣ���ⲿ�����߲�ʹ�ã�
// 4.�ڲ��ᱣ���Ѵ���ͼ��bEnable���ɿ�����ʾ����;
// 5.���渲��ģʽ�ݲ�֧��Ӳ���룬�ֲ�����֧����Ӳ��;
// 6.�ֲ�����ģʽ��YV12��JPEGͼƬ�ľֲ������迪��D3D11��RGBA32��RGB565����Ҫ���Ҹ�ģʽ��D3D9���Ӳ�֧��͸���ȣ�
// 7.��ͣ�����нӿڵ��ò�����Ч����Ҫ�ָ����Ų�����Ч��
PLAYM4_API BOOL __stdcall PlayM4_OverlayPicture(long nPort,PLAYM4_PIC_INFO_S* pstPicInfo,PLAYM4_PIC_DISPLAY_MODE_E enPicDisplayMode,bool bEnable,void* nReserved);

typedef struct
{
	int   nBitrate;    //����
	int   nDelayTime;  //��ʱֵ����λ����
	int   nReserved[4];
}PLAYM4_AUTOSMOOTHPLAYPARAM;

//��������Ӧƽ������
//Ĭ��3����ʱ�������СĬ��Ϊ8M
//����������ֳ���ʱ�ϴ󳬹���ֵʱ��ͨ��nReserved����PLAYM4_AutoSmoothPlayParam�ṹ�壬Ŀǰ��δ����
PLAYM4_API BOOL  __stdcall PlayM4_SetAutoSmoothPlay(LONG nPort, BOOL nEnable, void* nReserved);


#define PLAY_BACK_ACCURACY     1       //�������л�����ȷģʽ
#define PLAY_BACK_NORMAL       2       //�������л����Ǿ�ȷģʽ

//�����������л�ģʽ
//nModeֵ: 
// 1 ��ʾ�������л��ڼ�ľ�ȷģʽ�����Ὣ��/�����л�ǰ���л����ʱ������жԱȣ���֤��/�����л�ǰ����ľ�ȷ�νӣ�����֡��
// 2 ��ʾ�������л��ڼ�ķǾ�ȷģʽ�����л�����������ֱ�Ӳ��ţ�
// 3 ��ʾ�л�Ϊ����״̬��ķǾ�ȷģʽ��������ֱ�Ӳ��ţ���Ҫ���л�Ϊ���ź����
PLAYM4_API BOOL __stdcall PlayM4_SetPlayOrBackSwitchMode(LONG nPort,DWORD nMode);

///<��������
PLAYM4_API BOOL __stdcall PlayM4_PlaySound(LONG nPort);
PLAYM4_API BOOL __stdcall PlayM4_StopSound();
PLAYM4_API BOOL __stdcall PlayM4_PlaySoundShare(LONG nPort);
PLAYM4_API BOOL __stdcall PlayM4_StopSoundShare(LONG nPort);
PLAYM4_API BOOL __stdcall PlayM4_SetVolume(LONG nPort,WORD nVolume);
PLAYM4_API WORD __stdcall PlayM4_GetVolume(LONG nPort);
PLAYM4_API BOOL __stdcall PlayM4_AdjustWaveAudio(LONG nPort,LONG nCoefficient);
PLAYM4_API BOOL	__stdcall PlayM4_SetANRParam(LONG nPort, BOOL nEnable, int nANRLevel);

///<��ȡ��Ϣ
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
///<ʱ���ı�ʾ����Ϊ��λ������Ϊ��������Ϊ��
PLAYM4_API BOOL __stdcall PlayM4_SetSupplementaryTimeZone(int nPort, int nTimeZone); 
///<���Ѿ�����ʱ���򷵻�����ʱ��������ʧ��
PLAYM4_API BOOL __stdcall PlayM4_GetSupplementaryTimeZone(int nPort, int* pTimeZone); 
///<��ȡʱ����Ϣ
PLAYM4_API int __stdcall PlayM4_GetTimeZoneInfo(long nPort, int* pTimeZone);
//��ȡ��װ�ͱ�������
PLAYM4_API int __stdcall PlayM4_GetStreamInfo(long nPort, int* pSysFormat, int* pCodeType);
///<�������
PLAYM4_API DWORD __stdcall PlayM4_GetSourceBufferRemain(LONG nPort);
PLAYM4_API BOOL __stdcall PlayM4_ResetSourceBuffer(LONG nPort);
PLAYM4_API BOOL __stdcall PlayM4_SetSourceBufCallBack(LONG nPort,DWORD nThreShold,void (CALLBACK * SourceBufCallBack)(long nPort,DWORD nBufSize,void* dwUser,void*pResvered),void* dwUser,void *pReserved);
PLAYM4_API BOOL __stdcall PlayM4_ResetSourceBufFlag(LONG nPort);
PLAYM4_API BOOL __stdcall PlayM4_ResetBuffer(LONG nPort,DWORD nBufType);
PLAYM4_API DWORD __stdcall PlayM4_GetBufferValue(LONG nPort,DWORD nBufType);
PLAYM4_API BOOL __stdcall PlayM4_SetDisplayBuf(LONG nPort,DWORD nNum);
PLAYM4_API DWORD __stdcall PlayM4_GetDisplayBuf(LONG nPort);

//�˽ӿ�����¿�����25~100����Ӳ����ֻ��������25~50��������50�����ÿɳɹ����ڲ����50��
PLAYM4_API BOOL __stdcall PlayM4_SetReverseDecodeBuf(LONG nPort,DWORD nNum);

///<ץͼ
PLAYM4_API BOOL __stdcall PlayM4_SetJpegQuality(long nQuality);
PLAYM4_API BOOL __stdcall PlayM4_GetBMP(LONG nPort,PBYTE pBitmap,DWORD nBufSize,DWORD* pBmpSize);
PLAYM4_API BOOL __stdcall PlayM4_GetJPEG(LONG nPort,PBYTE pJpeg,DWORD nBufSize,DWORD* pJpegSize);
PLAYM4_API BOOL __stdcall PlayM4_ConvertToBmpFile(char * pBuf,long nSize,long nWidth,long nHeight,long nType,char *sFileName);
PLAYM4_API BOOL __stdcall PlayM4_ConvertToJpegFile(char * pBuf,long nSize,long nWidth,long nHeight,long nType,char *sFileName);

///< ���ý���ģʽ
// nIdemuxType: 1 ��ʾ������֡,2��ʾ���I֡ǰ���ݣ�4��ʾ�رձ�����
PLAYM4_API BOOL __stdcall PlayM4_SetDemuxModel(LONG nPort, unsigned int nIdemuxType, BOOL bTrue);
PLAYM4_API BOOL __stdcall PlayM4_SetIdemuxPara(LONG nPort, int nChunkSize);

///<����
PLAYM4_API BOOL __stdcall PlayM4_SetSecretKey(LONG nPort, LONG lKeyType, char *pSecretKey, LONG lKeyLen);
PLAYM4_API BOOL __stdcall PlayM4_ThrowBFrameNum(LONG nPort,DWORD nNum);
PLAYM4_API BOOL __stdcall PlayM4_SetDecCBStream(LONG nPort,DWORD nStream);
PLAYM4_API BOOL __stdcall PlayM4_SetDecodeFrameType(LONG nPort,DWORD nFrameType);
PLAYM4_API BOOL __stdcall PlayM4_CheckDiscontinuousFrameNum(LONG nPort, BOOL bCheck);
PLAYM4_API BOOL __stdcall PlayM4_SkipErrorData(LONG nPort, BOOL bSkip);
//���ò�����صȼ�-�ȼ�Խ�ߣ�Խ������ nLevel��Χ[1,2],һ������1����
PLAYM4_API BOOL __stdcall PlayM4_SetDecodeERC(long nPort, unsigned int nLevel);
//���ò�����صȼ�-�ȼ�Խ�ߣ�Խ������ nLevel��Χ[1,2],һ������1���ɣ������ٷֱȲ���-���ڸðٷֱȵĻ���֡�������
PLAYM4_API BOOL __stdcall PlayM4_SetDecodeERCEx(long nPort, unsigned int nLevel, unsigned int nDisplayErrPercentage, int nReserved);
PLAYM4_API BOOL __stdcall PlayM4_SetDecCallBackMend(LONG nPort,void (CALLBACK* DecCBFun)(long nPort,char * pBuf,long nSize,FRAME_INFO * pFrameInfo, void* nUser,void* nReserved2), void* nUser);
PLAYM4_API BOOL __stdcall PlayM4_SetDecCallBackExMend(LONG nPort, void (CALLBACK* DecCBFun)(long nPort, char* pBuf, long nSize, FRAME_INFO* pFrameInfo, void* nUser, void* nReserved2), char* pDest, long nDestSize, void* nUser);
// ���������ص�,nType=0��ʾ�������ܱ��λ�����仯�ͻص���nType=1��ʾ�����м���λ�����ص�-ֻ�ص�һ��
PLAYM4_API BOOL __stdcall PlayM4_SetEncryptTypeCallBack(LONG nPort, DWORD nType, void (CALLBACK* EncryptTypeCBFun)(long nPort, ENCRYPT_INFO* pEncryptInfo, void* nUser, long nReserved2), void* nUser);
//nTypeΪ0ÿ�ζ��ص���nTypeΪ1ֻ�ص�һ��
PLAYM4_API BOOL __stdcall PlayM4_SetStreamInfoCallBack(LONG nPort, DWORD nType, void (CALLBACK* StreamInfoTypeCBFun)(long nPort, STREAM_INFO* pStreamInfo, void* nUser, long nReserved), void* nUser);

//�������ʾ�ص��о���ʱ�����֡�ţ������ʱ�����֡�ţ��Ļص�����;
// nModule ��ʾ�ص�ģ��ѡ��0 ��ʾĬ�Ͻ���ص�����ʾ�ص� 1����ʾ����ص���2����ʾ��ʾ�ص���3����ʾIVS�ص�
// nType ��ʾ�ص�����ʱ�����֡�ţ��������ʱ�����֡�ţ����������ã�0����ʾ�ص����ʱ��������֡�� 1: ��ʾ�ص�����ʱ����;���֡��
//��ʾ�ص���û��֡�Żص��ģ�������ʾ�ص��� 0����ʾ�ص����ʱ��� 1: ��ʾ�ص�����ʱ���
PLAYM4_API BOOL __stdcall PlayM4_SetDecOrDisplayCallbackType(int nPort, int nModule, int nType);

// ������Ƶ��ʾ�ص��ӿڣ��ص��ͽ���Ƶ��Ⱦ��PCM���ݣ�����Ӧ����Ƶ��ʾ��Ϣ
PLAYM4_API BOOL __stdcall PlayM4_SetAudioDisplayCallBack(LONG lPort, 
                                                         void (CALLBACK *pfnAudioDisplayCB)(LONG lPort, const unsigned char* pData, const unsigned int uDataSize, const PLAYM4_AUDIODISPLAY_INFO_S* pstAudioDisplay,void* pUser), 
                                                         void* pUser);

// ������ʾScale���ͣ�scale��1��ʾ����Ƶ�����ʾ��0��ʾ��������
#define PLAYM4_ENUM_SCALE_FILL 0
#define PLAYM4_ENUM_SCALE_FIT  1
PLAYM4_API BOOL __stdcall PlayM4_SetScaleType(int nPort, int nScaleType);

#define YUV_RGB24			        1		///<rgb����
#define YUV_YUYV			     	2		///<YUYV����
#define YUV_YV12					3		///<YV12����,���ſ�Ĭ������
#define YUV_NV12			     	4		///<NV12����

//nMode ��ʾ���ű�����0��ʾ���������ţ�ԭ�ֱ������;����0ʱ��nMode�ĸ�2�ֽڱ�ʾ����2�ֽڱ�ʾ�ߣ���Ҫ��ߺͿ��������128��С��8192
PLAYM4_API  int __stdcall PlayM4_SetYUVCallBackType(LONG nPort, DWORD nType, DWORD nMode);

///< YUV ������ʾ�ص��ӿڣ�֧��Ӳ�����surfaceתyuv���ݻص�������bTrue��ʾ��·������Ҫƴ�Ӻ��ٻص�����bTrue == 1ʱ��ʾ��Ҫ�ڲ�ƴ�ӣ�
//��bTrue == 0ʱ��ʾ����Ҫ�ڲ�ƴ�ӣ���·���ֱ�ص���ȥ��ע�⣺��������ӥ������ֻ��ص���һ·��ȥ����֧������ӥ�۵���·��ƴ�ӻص���
PLAYM4_API BOOL __stdcall PlayM4_SetDisplayCallBackYUV(LONG nPort, void (CALLBACK* DisplayCBFun)(DISPLAY_INFO_YUV *pstDisplayInfo), BOOL bTrue, void* pUser);
PLAYM4_API BOOL __stdcall PlayM4_SetSmartFirstKeyFrameDisplay(long nPort, unsigned int nFlag, void* nReserved);


//nInterval��ʾ�ص������ÿ���nInterval֡����һ��YUV�ص���nIntervalΪ0��ʾȡ������ص����ָ���ÿ֡���ص�
PLAYM4_API  int __stdcall PlayM4_SetYUVCallBackInterval(LONG nPort, DWORD nInterval, void* pReserved);

///<��ʾ
PLAYM4_API BOOL __stdcall PlayM4_SetDisplayRegion(LONG nPort,DWORD nRegionNum, RECT *pSrcRect, HWND hDestWnd, BOOL bEnable);///<���ӷŴ�
PLAYM4_API BOOL __stdcall PlayM4_SetDisplayRegionOnWnd(LONG nPort,DWORD nRegionNum, RECT *pSrcRect, BOOL bEnable);///<�ര�ڷָ�
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
//lType: 1 ��ʾ��ȡ��ǰ��ʾ֡PTZ��Ϣ�����ض��ṹ����ʽ�洢��pInfo�ڣ�plLen���س�����Ϣ;���ȴ���pInfo = null�����Ի�ȡ����Ҫ������ڴ泤��plLen
PLAYM4_API BOOL __stdcall PlayM4_GetStreamAdditionalInfo(LONG nPort, LONG lType, BYTE* pInfo, LONG* plLen);

//˽����Ϣ�ص��ӿڣ�nType��ʾ��Ҫ�ص���˽����Ϣ���ͣ�Ŀǰ֧����������: ��ͨĿ���1; ��������Ŀ��� 2; ֧������ 1|2 ����ʽ��������3��ʾ�������Ͷ���ص�
PLAYM4_API BOOL __stdcall PlayM4_RegisterIVSDrawFunCB_EX(long nPort, void (CALLBACK* IVSDrawFun)(long nPort, HDC hDC, FRAME_INFO* pFrameInfo, INTEL_INFO_EX* pSyncData, void*  dwUser), void*  dwUser, unsigned int nType);

//˽����Ϣ�ص��ӿ�,nStamp��ʾ���ʱ�����Ϣ��pSyncData��ʾ˽����Ϣ����, nType��ʾ��Ҫ�ص���˽����Ϣ���ͣ�֧�ֶ��˽����Ϣ����һ�����ã�
//���統nType����6��ʾ�ⲿ��Ҫ�ص���������Ŀ������ͨ����򣬴�ʱ���ſ�ֻ��ص����������ͣ��������Ҫ�ص���ֱ������nType����0���ɣ���ʱĬ��������Ϣ�ṹ�������Ϣ����ص���
//nMode��ʾ�ص�ע���ģʽ(���ڽӿڵĹ�����չ)��Ŀǰ֧��0��1����ģʽ�����У�0ģʽ��ʾ��������̻ص������ſ��ڲ������к���Ƶ֡��ƥ�䣬Ҳ����ص�HDC; 1ģʽ��ʾ�ص��͵�ǰ��ʾ��Ƶ֡ƥ��ɹ���˽��֡
//�˽ӿ����ý����ص�ʱ���ص�ȫ��������ȷ��IVS˽����Ϣ����ÿ�����Ͷ����ص�������ƥ���ص�ʱ��ֻ�ص�����Ƶ֡ƥ���ϵ�IVS˽����Ϣ��ûƥ���ϵ����ͻص�ֵΪ0����ƥ���ϵ����ͽ��Ի����ʽһ��ص�
PLAYM4_API BOOL __stdcall PlayM4_RegisterIVSIntelInfoCB(LONG nPort, void (CALLBACK* IVSIntelInfoCBFun)(LONG nPort, HDC hDC, LONG nStamp, PRIVATE_INFO* pSyncData, void*  dwUser), void* dwUser, DWORD nType, DWORD nMode);

typedef struct _DB_INFO_NODE_
{
	float fDbValue;					//�ò������BDֵ
	bool  bPlusFlag;				//���� 1���������Ϸ���������0���������·���
	unsigned char  unReserved[3];	//��֤���ֽڶ���

}DBINFONODE;

typedef struct _OUTPUT_DB_INFO_
{
	DBINFONODE* pNodeDataBuffer;
	unsigned int dwDataLen;
    unsigned int nAvgAudioDBValue;  // һ֡��Ƶ����ƽ����ֵ��DBֵ
    unsigned int nReserverd[9];	//������չλ

}OUTPUTDBINFO;
///< ��Ƶ���ݷֱ�ֵ�ص�
PLAYM4_API BOOL __stdcall PlayM4_RegisterAudioPlayDBCallBack(LONG nPort, void (CALLBACK* AudioDBCBFun)(long nPort, OUTPUTDBINFO* pstDBInfo, void* pUser), void* pUser);
//nMode��ʾ�ص�ע���ģʽ(���ڽӿڵĹ�����չ)��Ŀǰ֧��0��1����ģʽ�����У�0ģʽ��ʾ�����ص���1��ʾ��Ⱦ��ص�
PLAYM4_API BOOL __stdcall PlayM4_RegisterAudioPlayDBCallBackEx(LONG nPort, void (CALLBACK* AudioDBCBFun)(long nPort, OUTPUTDBINFO* pstDBInfo, void* pUser), void* pUser, DWORD nMode, void* nReserved);

///<ͼ����
PLAYM4_API BOOL __stdcall PlayM4_SetColor(LONG nPort, DWORD nRegionNum, int nBrightness, int nContrast, int nSaturation, int nHue);
PLAYM4_API BOOL __stdcall PlayM4_GetColor(LONG nPort, DWORD nRegionNum, int *pBrightness, int *pContrast, int *pSaturation, int *pHue);
PLAYM4_API BOOL __stdcall PlayM4_SetImageSharpen(LONG nPort,DWORD nLevel);
PLAYM4_API BOOL __stdcall PlayM4_SetRotateAngle(LONG nPort, DWORD nRegionNum, DWORD dwType);

// ʹ�ñ������豸�����˺�������Ŀ���ʱ�����׼�������Ӳ�֡�ӿ�
// ����˽����Ϣ��֡�ӿ�
// ֧�ְ�ʹ�ô�����ʽ��֡��FrameInterpolationType����0�����������ַ�ʽʱ����Ҫ���þ����nIntelTypeֵ��Ҳ��Ҫ���þ����nUsedNumֵ��
// ֧���Զ���ʽ��֡��FrameInterpolationType����1�����������ַ�ʽʱ��nIntelTypeֵ����0��nUsedNumֵ����0������Ҫ����nFlag�����رգ����ſ��Զ���֡�������ͨĿ��򡢺�������Ŀ��򡢺�������POS�������֡֡��Ϊ5��
// nIntelType����˽����Ϣ���ͣ�֧�ֺ�������Ŀ�������Ϊ2����ͨĿ�������Ϊ1����������POS��Ϣ������Ϊ64��
// nFlag�������رգ�0��ʾ�رղ�֡��1��ʾ������֡��Ĭ�Ϲر�

#ifndef FRAME_INTERPOLATION_INFO_TAG
#define FRAME_INTERPOLATION_INFO_TAG

typedef struct
{
	unsigned int          FrameInterpolationType;     //��֡��ʽ
	unsigned int          nUsedNum;                   //ʹ�ô�����Ĭ��Ϊ3
	unsigned int          reserved[4];                //�����ֽ�
}FrameInterpolationInfo;

#endif
PLAYM4_API BOOL __stdcall PlayM4_SetPrivateFrameInterpolation(int nPort, unsigned int nIntelType, unsigned int nFlag, FrameInterpolationInfo* pManualDrawInfo);

///<����
PLAYM4_API DWORD __stdcall PlayM4_GetFileHeadLength();
PLAYM4_API DWORD __stdcall PlayM4_GetSdkVersion();
PLAYM4_API DWORD __stdcall PlayM4_GetLastError(LONG nPort);
PLAYM4_API BOOL __stdcall PlayM4_SetSycGroup(LONG nPort, DWORD dwGroupIndex);
PLAYM4_API BOOL __stdcall PlayM4_MotionFlow(LONG nPort, DWORD dwAdjustType);

///< ������Ƶ��ʾ�߳�ģʽ true����Ƶ�̷߳���ģʽ�� false�� ����Ƶ��ʾ��ͬһ�߳�ģʽ
PLAYM4_API BOOL __stdcall PlayM4_SetAudioThreadModel(LONG nPort, BOOL bModel);

// �������ʱ���ȡMP4��װ���߶�λƫ��
PLAYM4_API int __stdcall PlayM4_GetMpOffset(int nPort, int nTime, int* nOffset);

///< ͬ���ط���ع���
// ͬ���ط���ؽӿڣ���ͬ������Ϊ��������������ͬ���������ͨ��
PLAYM4_API BOOL __stdcall PlayM4_SYNC_Play(unsigned int nGroupIndex);
PLAYM4_API BOOL __stdcall PlayM4_SYNC_ReversePlay(unsigned int nGroupIndex);
PLAYM4_API BOOL __stdcall PlayM4_SYNC_Pause(unsigned int nGroupIndex,unsigned int nPause);
PLAYM4_API BOOL __stdcall PlayM4_SYNC_OneByone(unsigned int nGroupIndex);
PLAYM4_API BOOL __stdcall PlayM4_SYNC_Fast(unsigned int nGroupIndex);
PLAYM4_API BOOL __stdcall PlayM4_SYNC_Slow(unsigned int nGroupIndex);
PLAYM4_API BOOL __stdcall PlayM4_SYNC_ResetBuffer(unsigned int nGroupIndex,unsigned long nBufType);
PLAYM4_API BOOL __stdcall PlayM4_SYNC_SetDecodeFrameType(unsigned int nGroupIndex,unsigned long nFrameType);

// ͬ���طŽӿڻ�ȡ�����룬ͨ��ָ��ƫ�Ƴ���ͨ��������ȡ��Ӧport�ʹ�����
typedef struct tagPlayM4SyncGroupError
{
    int* pErrPort;      // ����ͨ����ָ��
    int* pErrCode;      // ����ͨ��������ָ��
    int  nErrPortNum;   // ����ͨ����
    int  nRsv[5];
}PLAYM4_SYNC_GROUP_ERROR_S;
PLAYM4_API BOOL __stdcall PlayM4_SYNC_GetLastError(unsigned int nGroupIndex,PLAYM4_SYNC_GROUP_ERROR_S& stSyncGroupError);

// ͬ���طų������ͻ��������϶���������λʱ��ȫ��ʱ���update״̬�ᵼ�µ�λ����reset��������²�ͬ�����˽ӿ���������update״̬ʱ��ͬ��reset����������reset���µĻ�����²�ͬ��������
// �����߼����ͻ�����ͬ���طŽ��ж�λ����ʱ���ȵ��ô˽ӿ��ٶ�λ��Ŀǰ�ýӿڽ������λʱ������²�ͬ�������⣬����λ����Ӱ�죬�����Դ˽ӿ��������������󣬿ɿ�����չ�ֶΡ�
PLAYM4_API BOOL __stdcall PlayM4_NotifySyncPosition(long nPort,void* nReserved);

/** @struct PLAYM4_AUDIOSSTREAM_INFO_S
 *  @brief  ��Ƶ����Ϣ�ṹ��
 */
typedef struct
{
    unsigned char*      pData;          // PCM����
    unsigned int        uDataLen;       // PCM���ݳ���
    unsigned int        uSamplesPerSec; // ������
    unsigned int        uChannels;      // ������
    unsigned int        uBitsPerSample; // λ��
    unsigned int        uFrameTime;     // ���ʱ���
    unsigned int        uAbsFrameTime;  // ����ʱ���
    int                 nFrameNum;      // ���֡��(������չ��)
    int                 nAbsFrameNum;   // ����֡��(������չ��)
    OUTPUTDBINFO        stDBInfo;       // DBֵ��Ϣ
    PLAYM4_SYSTEM_TIME  stSystemTime;  // ȫ��ʱ��(����Ƶ����)
    int                 reserved[8];    // ��չ�ֶ�
}PLAYM4_AUDIOSSTREAM_INFO_S;

// ��Ƶ����Ϣ�ص��ӿڣ�ͳһ�ص�������Ƶ��ص����ݺ���Ϣ��ͨ���������������ã�
// 1.֧��������Ƶ�ص���ģʽ���Ƿ���Ⱦ���Ƿ��룻
// 2.֧��������Ƶ�ص�����Ϣ����Ƶ֡��Ϣ��PCM���ݡ�DBֵ��(����Ƶ)ȫ��ʱ�䣻
// 3.֧��������Ƶ�ص���ģ�飬����ģ�顢��Ⱦģ�飻
// 4.֧�ֺ�������������Ϣ�ص���չ��

// nCBMode��������Ƶ�ص�ģʽ����λ��ֵ����ģʽ�������ûص���Ƶ������Ⱦ�ͽ��룬���ֵ����PLAYM4_AUDIOCB_DISPLAY_MODE|PLAYM4_AUDIOCB_ANR_MODE
// nCBModeֵ��0-�ر��������ã�����Ⱦ������ȣ�����Ӧλȡֵ�궨�壺
#define    PLAYM4_AUDIOCB_DISPLAY_MODE (1 << 0)  // nCBMode��0λ-��Ƶ�ص�������Ⱦ
#define    PLAYM4_AUDIOCB_ANR_MODE     (1 << 1)  // nCBMode��1λ-��Ƶ�ص��������루�ݲ�֧�֣��������ӣ�

// nCBInfo��������Ƶ�ص���Ϣ����λ��ֵ������Ϣ�������ûص���ƵPCM���ݺ�DBֵ�����ֵ���룺PLAYM4_AUDIO_PCM|PLAYM4_AUDIO_DB
// nCBInfoֵ��0-���ص���Ƶ֡��Ϣ����Ӧλȡֵ�궨�壺
#define    PLAYM4_AUDIO_PCM    (1 << 0)     // nCBInfo��0λ-��Ƶ�ص�PCM����
#define    PLAYM4_AUDIO_DB     (1 << 1)     // nCBInfo��1λ-��Ƶ�ص�DBֵ���ݲ�֧�֣��������ӣ�

// nCBModule��������Ƶ�ص�ģ�飬�ò��������ص�PCM���ݵ�ģ��
// 0-��Ƶ����ģ�飬PCM���ݽ����ص�
// 1-��Ƶ��Ⱦģ�飬PCM������Ⱦǰ�ص�

// ע��
// 1.�ص���Ƶ����ǰ������ýӿ�PlayM4_PlaySound������Ƶ���ţ�
// 2.PlayM4_PlaySound��PlayM4_PlaySoundShare�ӿڵ��ú���Ƶ���ݲŻ���롢��Ⱦ���ص��Ż���Ч��������Ƶ��������
// 3.��·���š�����ʱ����Ҫ�ص���·����Ƶ���ݣ�Ӧ������PlayM4_PlaySoundShare�ӿڣ�����PlayM4_PlaySound��ǰ���ǹ���˿ڲ�����Ƶ�������Ƕ�ռ��

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
	PLAYM4_LOG_LEVEL_DEBUG  = 1,        //���Լ���
	PLAYM4_LOG_LEVEL_INFO   = 2,        //��Ϣ
	PLAYM4_LOG_LEVEL_WARN   = 3,        //����
	PLAYM4_LOG_LEVEL_ERROR  = 4,        //����
	PLAYM4_LOG_LEVEL_TEM  = 5           //��ʱ����ר��
}PLAYM4_LOG_LEVEL;
#endif

// ��������bFlag��1��pConfigFilePath����־���ɣ����ԣ�·����emLogLevel����־�ȼ�
// ע��·������ʱ��Ĭ����PlayCtrl.dllͬ��Ŀ¼������־�ļ�
PLAYM4_API BOOL __stdcall PlayM4_SetHLogFlag_Ex(BOOL bFlag, char* pConfigFilePath, PLAYM4_LOG_LEVEL emLogLevel);


// ���ſ���־����������Ϣ�ṹ��
typedef struct _tagLOGSTREAMCONFIGINFO_
{
    char* pLogPath;          // ��־����·������NULL��Ĭ��������PlayCtrl.dllĿ¼
    char* pStreamPath;       // ��������·������NULL��Ĭ��������PlayCtrl.dllĿ¼

    char  bLogSwitch;        // ��־����
    char  nLogLevel;         // ��־�ȼ�����PLAYM4_LOG_LEVEL����
    char  bStreamSwitch;     // ��������

    char  bReadConfig;       // �Ƿ��ȡ���ſ������ļ�
    // ע����ȡ���ſ������ļ���Ϊ�����ø��ӹ��ܣ��ӿڵ��������ȼ����������ļ�
    char  nReserved[8];      // �����ֶ�
}PLAYM4_LOGSTREAMCONFIG_INFO_S;

// ���¶�ȡ�����ļ�����������־��������·����·����ʱ��Ĭ�ϱ����������ļ���
PLAYM4_API int __stdcall PlayM4_SetLogStreamConfig(PLAYM4_LOGSTREAMCONFIG_INFO_S* pstLogStreamConfigInfo);

#ifndef PLAYM4_HIKD3D11_TAG
#define PLAYM4_HIKD3D11_TAG
///<Ӳ����̽��ֱ���
#define HXVA_RESOLUTION_NONE   0x00      // 0
#define HXVA_RESOLUTION_200W   0x01      // 1920*1080
#define HXVA_RESOLUTION_300W   0x02      // 2048*1536
#define HXVA_RESOLUTION_500W   0x03      // 2560*1920
#define HXVA_RESOLUTION_800W   0x04      // 3840*2160
#define HXVA_RESOLUTION_1600W  0x05      // 4096*4096
#define HXVA_RESOLUTION_6400W  0x06      // 8192*8192(H.265)

///<Ӳ�������Ⱦ������̽������ṹ��
typedef struct _tagHDECODESUPPORT_
{
    unsigned char  chGPUType;                // GPU���ͣ� 0-�ޣ�1-N�����ԣ�2-A�����ԣ�3-����
    unsigned char  bDXVA_D3D9;               // 0-��֧�֣�1-֧��
    unsigned char  bCUVID_D3D11;             // 0-��֧�֣�1-֧��
    unsigned char  chDXVAH264_Max_Resolution;// DXVA,h264����֧�ֵ����ķֱ��ʴ��ֵ-���Ǿ�׼ֵ-���嶨���ö������
    unsigned char  chDXVAH265_Max_Resolution;// DXVA,h265����֧�ֵ����ķֱ��ʴ��ֵ-���Ǿ�׼ֵ-���嶨���ö������
    unsigned char  chCUVIDH264_Max_Resolution;// CUVID,h264����֧�ֵ����ķֱ��ʴ��ֵ-���Ǿ�׼ֵ-���嶨���ö������
    unsigned char  chCUVIDH265_Max_Resolution;// CUVID,h265����֧�ֵ����ķֱ��ʴ��ֵ-���Ǿ�׼ֵ-���嶨���ö������
    unsigned char  chValidFlag;               ///<��Ч
    unsigned char  bD3D11VA;                  // �ж��Ƿ�֧��D3D11VAӲ����:0-��֧�֣�1-֧��
    unsigned char  chD3D11VAH264_Max_Resolution;// D3D11VA,h264����֧�ֵ����ķֱ��ʴ��ֵ-���Ǿ�׼ֵ
    unsigned char  chD3D11VAH265_Max_Resolution;// D3D11VA,h265����֧�ֵ����ķֱ��ʴ��ֵ-���Ǿ�׼ֵ
    unsigned char  nReserved[9];        // �����ֶ�
}HDECODESUPPORT;///< Ӳ����֧����Ϣ

typedef struct _tagRENDERSUPPORT_
{
    unsigned char  bDDraw;              ///< �ж��Ƿ�֧��Draw��Ⱦ
    unsigned char  bD3D9Surface;        ///< �ж��Ƿ�֧��D3D9������Ⱦ
    unsigned char  bD3D9Texture;        ///< �ж��Ƿ�֧��D3D9������Ⱦ
    unsigned char  bD3D11;              ///< �ж��Ƿ�֧��D3D11��Ⱦ
    unsigned char  chValidFlag;         ///< ��Ч
    unsigned char  nGPUType;            ///< ��Ⱦ̽��GPU����  0-��; 1-����;2-NVIDIA;3-AMD
    unsigned char  nReserved[10];       ///< �����ֶ�,��nGPUType����Ϊ3 ����AMD�Կ��£��˴��᷵��AMD�ض����Կ���
                                        ///<Ŀǰ�᷵��RX550��R5 220���Կ����ƣ�ע���ⲿ���дӸ�nReserved�ֶ���Ѱ��RX550��R5 220�ؼ���
}RENDERSUPPORT;///< ��Ⱦ֧����Ϣ

typedef struct _tagENGINESUPPORT_
{
    HDECODESUPPORT stHDecodeSupport; ///<Ӳ����������
    RENDERSUPPORT  stRenderSupport;  ///<��Ⱦ������
    unsigned int   chReserved[4];    ///<�����ֶ�
}ENGINESUPPORT;///< Ӳ�������Ⱦ֧��������

typedef struct _tagENGINESUPPORT_EX_
{
    HDECODESUPPORT stHDecodeSupportD3D9[8];
    HDECODESUPPORT stHDecodeSupportD3D11[8];
    RENDERSUPPORT  stRenderSupport[8];
    unsigned char  chD3D9DeviceCount;
    unsigned char  chD3D11DeviceCount;
    unsigned char  chRenderDeviceCount;
    unsigned char  chReserved[13];
}ENGINESUPPORT_EX;///< Ӳ�������Ⱦ֧��������-EX

typedef struct _tagRENDERSUPPORT_EX_
{
    unsigned char  chValidFlag;         ///< ̽����Ч
    unsigned char  bDDraw;              ///< �ж��Ƿ�֧��Draw��Ⱦ
    unsigned char  bD3D9Surface;        ///< �ж��Ƿ�֧��D3D9������Ⱦ
    unsigned char  bD3D9Texture;        ///< �ж��Ƿ�֧��D3D9������Ⱦ
    unsigned char  bD3D11;              ///< �ж��Ƿ�֧��D3D11��Ⱦ
    unsigned char  bD3D11VP;            ///< �ж��Ƿ�֧��D3D11VP��Ⱦ
    unsigned char  nReserved1[9];        //���ں�������Ⱦ������չ
    unsigned char  nGPUType;            ///< ��Ⱦ̽��GPU����  0-��; 1-����;2-NVIDIA;3-AMD
    unsigned char  nReserved2[256];       ///< �����ֶ�,��nGPUType����Ϊ3 ����AMD�Կ��£��˴��᷵��AMD�ض����Կ���
    ///<Ŀǰ�᷵��RX550��R5 220���Կ����ƣ�ע���ⲿ���дӸ�nReserved�ֶ���Ѱ��RX550��R5 220�ؼ���
}RENDERSUPPORT_EX;///< ��Ⱦ֧����Ϣ

///<Ӳ�������Ⱦ������̽������ṹ��
typedef struct _tagHDECODESUPPORT_EX_
{
    unsigned char  chValidFlag;              ///<̽���Ƿ���Ч
    unsigned char  chGPUType;                // GPU���ͣ� 0-�ޣ�1-N�����ԣ�2-A�����ԣ�3-���ԣ�4-��о��5-���뿨
    unsigned char  bHardDecSupport;          //�ж��Ƿ�֧��Ӳ���� 0-��֧�֣�1-֧��
    unsigned char  chH264_Max_Resolution;    // h264����֧�ֵ����ķֱ��ʴ��ֵ-���Ǿ�׼ֵ
    unsigned char  chH265_Max_Resolution;    // h265����֧�ֵ����ķֱ��ʴ��ֵ-���Ǿ�׼ֵ
    unsigned char  nReserved[11];            // �����ֶ�
}HDECODESUPPORT_EX;///< Ӳ����֧����Ϣ

typedef struct _tagGPU_ENGINE_SUPPORT_
{
    unsigned char  chD3D9DeviceCount;
    unsigned char  chD3D11DeviceCount;
    unsigned char  chRenderDeviceCount;
	unsigned char  chDecodeCardCount;               //���뿨����
	unsigned char  chReserved1[12];                 //���ں������豸������չ
    HDECODESUPPORT_EX stHDecodeSupportD3D9[8];     //D3D9Ӳ����֧�����
    HDECODESUPPORT_EX stHDecodeSupportD3D11[8];    //D3D11Ӳ����֧�����
	HDECODESUPPORT_EX stDecodeCardSupport[8];      //���뿨����֧�����
	HDECODESUPPORT_EX chReserved2[40];              //���ں���Ӳ����֧�ֵ�����������չ�����֧��6�����棬ÿ������8���豸
	RENDERSUPPORT_EX  stRenderSupport[8];
}GPU_ENGINE_SUPPORT;///< Ӳ�������Ⱦ֧��������

typedef struct _AUDIOCARDINFO_
{
	unsigned int  nDeviceIndex;     //�豸��
	char          sDeviceName[128]; //�豸����
	void          *pDevice;         //�豸��ַ
	unsigned char nReserved[8];     //�����ֶ�
}AUDIOCARDINFO;

typedef struct _tagAUDIODEVICEPARAM_
{
	AUDIOCARDINFO  stAudioCardInfo[8];  ///<�����豸��Ϣ
	unsigned char  chAudioCardCount;    ///<�����豸����
	unsigned char  chReserved[7];       ///<�����ֶ�

}AUDIODEVICEPARAM;///< ��Ƶ�豸̽����Ϣ

///<d3d11��Ⱦץͼ�ṹ��
typedef struct _tagD3D11_PIC_INFO_
{
    unsigned int   nPicMode;     //ץͼģʽ��0-��������ʵ�ʷֱ���ץͼ(֮ǰץͼģʽ)��1-�������洫��Ŀ��ץͼ��nPicWidth*nPicHeightΪ��ʾ���ڿ��ʱЧ����ѣ�
    unsigned char* pBuf;         //ץͼ����buffer
    unsigned int   nBufSize;     //����buffer��С-�����nPicModeΪ0��Ϊ֮ǰ�ĸ��ݻ�ȡ���������ֱ��������л������룻���nPicModeΪ1���ϲ�������õķֱ��������뻺�棩
    unsigned int*  pPicSize;     //ʵ��ͼƬ��С
    unsigned int   nPicWidth;    //����ץͼ��-nPicModeΪ1ʱ��Ч���ҿ�>=32,nPicWidth*nPicHeight<5000w�ֱ��ʡ�
    unsigned int   nPicHeight;   //����ץͼ��-nPicModeΪ1ʱ��Ч���Ҹ�>=32,nPicWidth*nPicHeight<5000w�ֱ��ʡ�
    unsigned char  chReserve[8]; //reserve�����ֶ�
}D3D_PIC_INFO;

/*D3D11ͼ���������*/
typedef enum tagPLAYM4PostProcType
{
	PLAYM4_PPT_NULL                     = 0x0,
    PLAYM4_PPT_BRIGHTNESS               = 0x1,            ///< ����   [-1.0, 1.0]
    PLAYM4_PPT_HUE                      = 0x2,            ///< ɫ��   [0.0, 1.0]----0.166�ۼ�Ϊһ����ɫ�仯��0��1Ϊͬһ����ɫ
    PLAYM4_PPT_SATURATION               = 0x3,            ///< ���Ͷ� [-1.0, 1.0]
    PLAYM4_PPT_CONTRAST                 = 0x4,            ///< �Աȶ� [-1.0, 1.0]
    PLAYM4_PPT_SHARPNESS                = 0x5,            ///< ���   [ 0.0, 1.0]
    PLAYM4_PPT_DILATATION               = 0x6,            ///< ���Ͷ� [ 1.0, 4.0],��Чֵֻ��1.0��2.0��3.0��4.0�ĸ��ȼ�������1.5��С����Ч
                                                          //                      �ײ㲻�������жϣ����ϲ�ʹ�����Լ�������ȷ��ֵ,����ֵ���ܻᵼ�º���
}PLAYM4PostProcType;

#endif

// ����Devcie��ţ�ѡ���Ӧ����Ƶ�豸��ֻ����GetPort֮�����
PLAYM4_API BOOL __stdcall PlayM4_SetAudioDeviceIndex(LONG nPort, unsigned int nDeviceIndex);

PLAYM4_API BOOL __stdcall PlayM4_GetAudioDevice(LONG nPort, AUDIODEVICEPARAM* pstAudioDeviceParam);

///< ��ȡ�豸Ӳ�������Ⱦ������--getport֮��
PLAYM4_API int __stdcall PlayM4_GetEngineSupport(long nPort, ENGINESUPPORT* pstEngineSupport);

///< ��ȡ�豸Ӳ�������Ⱦ������--getport֮��--(֧�ֶ��Կ�̽�⣬�Ƽ�ʹ�øýӿ�)
PLAYM4_API BOOL __stdcall PlayM4_GetEngineSupportEx(long nPort, ENGINESUPPORT_EX* pstEngineSupport);

///<��Ⱦ��d3d11ץͼ-ֻ֧��d3d11��Ⱦʱ��Ч��d3d9��Ⱦ��Ч:nType:0-jpeg,1-bmp.
PLAYM4_API int __stdcall PlayM4_GetD3DCapture(long nPort, unsigned int nType, D3D_PIC_INFO* pstPicInfo);


///<d3d11ͼ�����-��ֻ֧��d3d11��Ⱦ����-���ò���
PLAYM4_API int __stdcall PlayM4_SetD3DPostProcess(long nPort, PLAYM4PostProcType nPostType, float fValue);

///<d3d11ͼ�����-��ֻ֧��d3d11��Ⱦ����-��ȡ����
PLAYM4_API int __stdcall PlayM4_GetD3DPostProcess(long nPort, PLAYM4PostProcType nPostType, float* fValue);

///<����D3D11��Ⱦʱ(D3D9��Ⱦʱ����ʵ����Ч)�ַ����ӵ������·����������ʱ����Ĭ������⣩-playǰ����
///<Ŀǰ�ýӿ��߼��޸�Ϊ������Ч�����󣬾�������Ⱦ�����POS���Ƽ�POS��������Ϊ������ʹ�ã��������ļ����Ĳ��Ƽ�����
PLAYM4_API int __stdcall PlayM4_SetConfigFontPath(int nPort, char* pFontPath);

////////////////////////////////////


///<SDPȡ���ӿ�//////////////////////////////////////////////////////////////////////////
#ifndef PLAYM4_SESSION_INFO_TAG
#define PLAYM4_SESSION_INFO_TAG

//nProtocolType
#define PLAYM4_PROTOCOL_RTSP    1
//nSessionInfoType
#define PLAYM4_SESSION_INFO_SDP 1

typedef struct _PLAYM4_SESSION_INFO_   //������Ϣ�ṹ
{
    int            nSessionInfoType;   //������Ϣ���ͣ���ʱֻ֧��SDP
    int            nSessionInfoLen;    //������Ϣ����
    unsigned char* pSessionInfoData;   //������Ϣ����
} PLAYM4_SESSION_INFO;
#endif

PLAYM4_API BOOL __stdcall PlayM4_OpenStreamAdvanced(LONG nPort, int nProtocolType, PLAYM4_SESSION_INFO* pstSessionInfo, DWORD nBufPoolSize);

///<������ؽӿ�//////////////////////////////////////////////////////////////////////////
#ifndef FISH_EYE_TAG
#define FISH_EYE_TAG

// ��װ����
typedef enum tagFECPlaceType
{
    FEC_PLACE_WALL    = 0x1,        // ��װ��ʽ     (����ˮƽ)
    FEC_PLACE_FLOOR   = 0x2,        // ���氲װ     (��������)
    FEC_PLACE_CEILING = 0x3,        // ��װ��ʽ     (��������)

}FECPLACETYPE;

typedef enum tagFECCorrectType
{
    FEC_CORRECT_NULL                    = 0x0000, // ������ - (����ԭͼ)
    FEC_CORRECT_PTZ                     = 0x0100, // PTZ
    FEC_CORRECT_180                     = 0x0200, // 180�Ƚ��� - ����Ӧ2P�� - ��װ/��װ
    FEC_CORRECT_360                     = 0x0300, // 360ȫ������ - ����Ӧ1P�� - ��װ/��װ
    FEC_CORRECT_LAT                     = 0x0400, // γ��չ�� - ��װ
    FEC_CORRECT_SEMISPHERE              = 0x0500, // ���۰������ - (�������)
    FEC_CORRECT_CYLINDER                = 0x0600, // ����Բ����ʾ - ��װ/��װ
    FEC_CORRECT_CYLINDER_SPLIT          = 0x0700, // �����п���Բ����ʾ - ��װ/��װ
    FEC_CORRECT_PLANET                  = 0x0800, // ����С����
    FEC_CORRECT_ARCSPHERE_HORIZONTAL    = 0x0900, // ����ˮƽ���� - ��װ
    FEC_CORRECT_ARCSPHERE_VERTICAL      = 0x0A00, // ���۴�ֱ���� - ��װ
    FEC_CORRECT_PTZ_SCALE_ANIMATION     = 0x0B00, // ����PTZת�����Ŷ�������ģʽ
}FECCORRECTTYPE;

typedef enum tagFECCorrectEffect
{
    FEC_CORRECT_EFFECT_BACK_FACE_CULLING    = 0x100,        // �����޳�����0��ʾ���ã�Ϊ0��ʾ�����ã�������������ǿת������

}FECCORRECTEFFECT;

typedef struct tagCycleParam
{
    float   fRadiusLeft;    // Բ�������X����
    float   fRadiusRight;   // Բ�����ұ�X����
    float   fRadiusTop;     // Բ�����ϱ�Y����
    float   fRadiusBottom;  // Բ�����±�Y����

}CYCLEPARAM;

typedef struct tagPTZParam
{
    float fPTZPositionX;        // PTZ ��ʾ������λ�� X����
    float fPTZPositionY;        // PTZ ��ʾ������λ�� Y����	

}PTZPARAM;

#define         FEC_UPDATE_RADIUS            0x1
#define         FEC_UPDATE_PTZZOOM           0x2
#define         FEC_UPDATE_WIDESCANOFFSET    0x4
#define         FEC_UPDATE_PTZPARAM          0x8
#define         FEC_UPDATT_PTZCOLOR          0x10
#define         FEC_UPDATE_PTZSELECT         0x20

// ɫ�ʽṹ��
typedef struct tagFECColor
{
    unsigned char nR;     // R����
    unsigned char nG;	  // G����
    unsigned char nB;     // B����
    unsigned char nAlpha; // Alpha����
}FECCOLOR;

//PTZ��ѡ�ṹ��
typedef struct tagFECRectF
{
    float fTop;
    float fBottom;
    float fLeft;
    float fRight;
}FECRECTF;

typedef struct tagFECParam
{
    unsigned int    nUpDateType;            // ���µ�����
    unsigned int    nPlaceAndCorrect;       // ��װ��ʽ�ͽ�����ʽ��ֻ�����ڻ�ȡ��SetParam��ʱ����Ч,��ֵ��ʾ��װ��ʽ�ͽ�����ʽ�ĺ�
    PTZPARAM        stPTZParam;             // PTZ У���Ĳ���
    CYCLEPARAM      stCycleParam;           // ����ͼ��Բ�Ĳ���
    float           fZoom;                  // PTZ ��ʾ�ķ�Χ����
    float           fWideScanOffset;        // 180����360��У����ƫ�ƽǶ�
    FECCOLOR        stPTZColor;             // PTZ��ɫ
    FECRECTF        stPTZSelct;             // PTZѡ������
    unsigned int    nCut;                   //����ԭͼ�Ƿ���вü�������������ڣ�������������ԭͼ��
    int             nResver[10];            // �����ֶ�
}FISHEYEPARAM;

// PTZ��ԭʼ����ͼ����������ʾģʽ
typedef enum tagFECShowMode
{
    FEC_PTZ_OUTLINE_NULL,   // ����ʾ
    FEC_PTZ_OUTLINE_RECT,   // ������ʾ
    FEC_PTZ_OUTLINE_RANGE,  // ��ʵ������ʾ
}FECSHOWMODE;

#define    FEC_JPEG   0  // JPEGץͼ
#define    FEC_BMP    1  // BMP ץͼ

// Ӳ�����־
#define FEC_DISPLAYSURFACE          0x400  // ����Ӳ���ʶ

// ��ת��Ԫ�ṹ��
typedef struct tagPLAYM4SRTransformElement
{
    float fAxisX;
    float fAxisY;
    float fAxisZ;
    float fValue; // ��ת�ĽǶ�

}PLAYM4SRTRANSFERELEMENT;

// ��ת��ϲ���
typedef struct tagPLAYM4SRTransformParam
{
    PLAYM4SRTRANSFERELEMENT* pTransformElement;		// ��ת��������
    unsigned int		     nTransformCount;		// ��ת����ϴ���
}PLAYM4SRTRANSFERPARAM;


//////////*************������صĲ�����ʹ�ýӿںͶ���(����������)************************//////////////

#define FEC_DISPLAYSPHERE           0x402  // ����������Ⱦ��ʾ(����������)-������ʹ��

PLAYM4_API BOOL __stdcall PlayM4_FEC_Rotate(LONG nPort, PLAYM4SRTRANSFERPARAM *pstRotateParam);///<�˽ӿ�Ϊ������ʹ�ýӿ�(������������ת�ӿ�)

//////////////////////**************************/////////////////////////


// �ӽǱ任����
typedef enum tagPLAYM4HRViewParamType
{
    PLAYM4_HR_VPT_ROTATION_X       = 0x1,          ///<ˮƽ��ת
    PLAYM4_HR_VPT_ROTATION_Y       = 0x2,          ///<��ֱ��ת
    PLAYM4_HR_VPT_SCALE            = 0x3,          ///<����(�����ֵΪ������0ֵʱΪ����-����Ч��)
}PLAYM4HRVIEWPARAMTYPE;

// ����3Dģ�Ͳ���
typedef enum tagPLAYM4FEC3DModelParam
{
    PLAYM4_FEC_3DMP_CYLINDER_HEIGHT              = 0x1,       ///< Բ��ģ�͸�
    PLAYM4_FEC_3DMP_CYLINDER_RADIUS              = 0x2,       ///< Բ��ģ�Ͱ뾶
}PLAYM4FEC3DMODELPARAM;

// �ض��ӽ�״̬
typedef enum tagPLAYM4FECSpecialViewType
{
    PLAYM4_FEC_SVT_EDGE                          = 0x1        ///<��������ģ���봰�������ӽ�
}PLAYM4FECSPECIALVIEWTYPE;

typedef void (__stdcall* FISHEYE_CallBack )( void* pUser, unsigned int nSubPort, unsigned int nCBType, void* hDC, unsigned int nWidth, unsigned int nHeight);

#endif
// ��������
PLAYM4_API BOOL __stdcall PlayM4_FEC_Enable(LONG nPort);

// �ر�����ģ��
PLAYM4_API BOOL __stdcall PlayM4_FEC_Disable(LONG nPort);

// ��ȡ���۽��������Ӷ˿� [1~31]
PLAYM4_API BOOL __stdcall PlayM4_FEC_GetPort(LONG nPort, unsigned int* nSubPort, FECPLACETYPE emPlaceType, FECCORRECTTYPE emCorrectType);

// ɾ�����۽��������Ӷ˿�
PLAYM4_API BOOL __stdcall PlayM4_FEC_DelPort(LONG nPort, unsigned int nSubPort);

// �������۽�������
PLAYM4_API BOOL __stdcall PlayM4_FEC_SetParam(LONG nPort, unsigned int nSubPort, FISHEYEPARAM* pPara);

// ��ȡ���۽�������
PLAYM4_API BOOL __stdcall PlayM4_FEC_GetParam(LONG nPort, unsigned int nSubPort, FISHEYEPARAM* pPara);

// ������ʾ���ڣ�������ʱ�л�
PLAYM4_API BOOL __stdcall PlayM4_FEC_SetWnd(LONG nPort, unsigned int nSubPort, void* hWnd);

// �������۴��ڵĻ�ͼ�ص�
PLAYM4_API BOOL __stdcall PlayM4_FEC_SetCallBack(LONG nPort, unsigned int nSubPort, FISHEYE_CallBack cbFunc, void* pUser);

// ����ץͼ
PLAYM4_API BOOL __stdcall PlayM4_FEC_Capture(LONG nPort, unsigned int nSubPort, unsigned int nType, char* pFileName);

// ����Ӳ��
PLAYM4_API BOOL __stdcall PlayM4_FEC_SetConfig(LONG nPort,unsigned int nType);

PLAYM4_API BOOL __stdcall PlayM4_FEC_GetCurrentPTZPort(LONG nPort, float fPositionX,float fPositionY, unsigned int *pnPort);

PLAYM4_API BOOL __stdcall PlayM4_FEC_SetCurrentPTZPort(LONG nPort, unsigned int nSubPort);

PLAYM4_API BOOL __stdcall PlayM4_FEC_SetPTZOutLineShowMode(LONG nPort,FECSHOWMODE nPTZShowMode);

PLAYM4_API int __stdcall PlayM4_FEC_PTZ2Window(LONG nPort, unsigned int nSubPort, PTZPARAM stPTZRefOrigin, PTZPARAM stPTZRefWindow, PTZPARAM stPTZWindow, float * fXWindow, float * fYWindow);

PLAYM4_API int __stdcall PlayM4_FEC_PTZ2WindowEx(LONG nPort , unsigned int nSubPortF,unsigned int nSubPortS,PTZPARAM stPTZRefOrigin , PTZPARAM stPTZRefWindow , PTZPARAM stPTZWindow , float * fXWindow , float * fYWindow);
PLAYM4_API int __stdcall PlayM4_SetDecodeOrDisplayMode(long nPort, unsigned int nDecodeType, unsigned int nDisplayEngine);
PLAYM4_API int __stdcall PlayM4_FEC_Scan(LONG nPort, unsigned int nSubPort, float fAngle, float* fXWindow, float* fYWindow, FECPLACETYPE emType);

//bEnable Ϊtrue��ʾPTZ������ԭͼ��ʽ����Ŵ�Ϊfalse��ʾ�ɷŴ��˳����ָ�Ϊ����ԭͼ��ʽ��ע��˽ӿڱ����������۶�װPTZ���Ŷ�������ģʽ�²�������
PLAYM4_API BOOL __stdcall PlayM4_FEC_SetPTZAnimationScale(LONG nPort, unsigned int nSubPort,BOOL bEnable);


//�µ����۰�������ӽǱ仯(��ת)������ؽӿ�
//��ȡ��������ӽǲ���(����ǰ�Ȼ�ȡ��ǰ��ֵ)
PLAYM4_API BOOL __stdcall PlayM4_FEC_GetViewParam(LONG nPort, unsigned int nSubPort, PLAYM4HRVIEWPARAMTYPE enViewParamType, float* fValue);
//���ð�������ӽǱ仯����(���õ�ֵΪ��ȡֵ����Ҫƫ��ֵ)
PLAYM4_API BOOL __stdcall PlayM4_FEC_SetViewParam(LONG nPort, unsigned int nSubPort, PLAYM4HRVIEWPARAMTYPE enViewParamType, float fValue);

//���۵��ӷŴ� nType = 0��
//���۴��ڷָ� nType = 1��
//ע�⣬���ڷָ�ʱhDestWnd��Ч��������ΪNULL��20180813�ݲ�֧�֣�
//Ŀǰ���ӷŴ�֧�����������ϷŴ�nRegionNum��Ϊ0��hDestWnd��ΪNULL��bEnable��Ϊ0ȡ�����ӷŴ󣬷�0Ϊ���ӷŴ�
//pSrcRect�����һ��������1000���Կ���߸ߣ���ֵ��0-1000֮�䣩
//ֻ�Ƽ�ԭͼ��180��360��γ��չ�����е��ӷŴ�-3D���۲�����ʹ�ô˽ӿ�(���ӽǱ仯�ӿڽ������ţ���ptz��3D������ʽ��֧�ֵ��ӷŴ�
PLAYM4_API BOOL __stdcall PlayM4_FEC_SetDisplayRegion(LONG nPort, unsigned int nSubPort,unsigned int nType, DWORD nRegionNum, RECT *pSrcRect, HWND hDestWnd, BOOL bEnable);
//�����޳�����0��ʾ���ã�Ϊ0��ʾ�����ã�������������ǿת������
PLAYM4_API BOOL __stdcall PlayM4_FEC_SetCorrectEffect(LONG nPort, unsigned int nSubPort, FECCORRECTEFFECT nCorrectEffect, float fValue);

// ����3Dģ�Ͳ���-���3DԲ��չ����Ч
PLAYM4_API BOOL __stdcall PlayM4_FEC_Set3DModelParam(int nPort, unsigned int nSubPort, PLAYM4FEC3DMODELPARAM enType, float fValue);

// ��ȡ�ض��ӽǲ��� - ֻ�����ڻ��棬��SetViewParam�ӿ����ʹ��
PLAYM4_API BOOL __stdcall PlayM4_FEC_GetSpecialViewParam(int nPort, unsigned int nSubPort, PLAYM4FECSPECIALVIEWTYPE enSVType, PLAYM4HRVIEWPARAMTYPE enVPType, float* pValue);

///<ȫ��360��ؽӿ�//////////////////////////////////////

//ȫ������չʾЧ��
#ifndef PLAYM4_PANORAMA_TAG
#define PLAYM4_PANORAMA_TAG
typedef enum tagPLAYM4PanoramaDisplayEffect
{
	PANORAMA_PLANET  = 0,///< ȫ��ƽ��չʾ
	PANORAMA_SPHERE = 1, ///< ȫ������չʾ
	PANORAMA_AUTO = 2,   ///< �Զ�չʾ
    PANORAMA_ASTEROID = 3, ///< ȫ��С����չʾ
}PLAYM4PANORAMADISPLAYEFFECT;
#endif

/** @fn int  __stdcall  PlayM4_SetPanoramaDisplayEffect(LONG nPort, PLAYM4PANORAMADISPLAYEFFECT eDisplayEffect, void *nReserved)
*  @brief  ����ȫ������չʾЧ��
*  @param nPort                 [IN] �˿ں�
*  @param eDisplayEffect        [IN] ����չʾЧ��,ö�٣�0����ȫ��ƽ��չʾ��1����ȫ������չʾ
*  @param nReserved             [IN] ����λ
*  @return 1�ɹ�������ʧ��
*/
PLAYM4_API BOOL __stdcall PlayM4_SetPanoramaDisplayEffect(LONG nPort, PLAYM4PANORAMADISPLAYEFFECT eDisplayEffect, void *nReserved);

/** @fn int  __stdcall  PlayM4_GetPanoramaSphereViewParam(LONG nPort, PLAYM4HRVIEWPARAMTYPE enViewParamType, float* fValue, void *nReserved)
*  @brief  ��ȡ360ȫ�������ӽǲ���(����ǰ�Ȼ�ȡ��ǰ��ֵ)
*  @param nPort         [IN] �˿ں�
*  @param enViewParamType       [IN] �ӽǱ任����
*  @param fValue                [IN/OUT] �����Ƕȣ���ȡֵ
*  @param nReserved             [IN] ����λ
*  @return 1�ɹ�������ʧ��
*/
PLAYM4_API BOOL __stdcall PlayM4_GetPanoramaSphereViewParam(LONG nPort, PLAYM4HRVIEWPARAMTYPE enViewParamType, float* fValue, void *nReserved);

/** @fn int  __stdcall  PlayM4_SetPanoramaSphereViewParam(LONG nPort, PLAYM4HRVIEWPARAMTYPE enViewParamType, float fValue, void *nReserved)
*  @brief  ����360ȫ�������ӽǲ���(���õ�ֵΪ��ȡֵ����Ҫƫ��ֵ)
*  @param nPort         [IN] �˿ں�
*  @param enViewParamType       [IN] �ӽǱ任����
*  @param fValue                [IN] �����Ƕȣ�����ֵ
*  @param nReserved             [IN] ����λ
*  @return 1�ɹ�������ʧ��
*/
PLAYM4_API BOOL __stdcall PlayM4_SetPanoramaSphereViewParam(LONG nPort, PLAYM4HRVIEWPARAMTYPE enViewParamType, float fValue, void *nReserved);
//////////////////////////////////////////////////////////////////

///<ͼ����ǿ��ؽӿ�//////////////////////////////////////////////////////////////////////////
#ifndef PLAYM4_HIKVIE_TAG
#define PLAYM4_HIKVIE_TAG

typedef struct _PLAYM4_VIE_DYNPARAM_
{
    int moduFlag;      //���õ��㷨����ģ�飬��PLAYM4_VIE_MODULES�ж��壬�� PLAYM4_VIE_MODU_ADJ | PLAYM4_VIE_MODU_EHAN��ģ�����ú󣬱���������Ӧ�Ĳ�����
    //PLAYM4_VIE_MODU_ADJ
    int brightVal;     //���ȵ���ֵ��[-255, 255]
    int contrastVal;   //�Աȶȵ���ֵ��[-256, 255]
    int colorVal;      //���Ͷȵ���ֵ��[-256, 255]
    //PLAYM4_VIE_MODU_EHAN
    int toneScale;     //�˲���Χ��[0, 100]
    int toneGain;      //�Աȶȵ��ڣ�ȫ�ֶԱȶ�����ֵ��[-256, 255]
    int toneOffset;    //���ȵ��ڣ�����ƽ��ֵƫ�ƣ�[-255, 255]
    int toneColor;     //��ɫ���ڣ���ɫ����ֵ��[-256, 255]
    //PLAYM4_VIE_MODU_DEHAZE
    int dehazeLevel;   //ȥ��ǿ�ȣ�[0, 255]
    int dehazeTrans;   //͸��ֵ��[0, 255]
    int dehazeBright;  //���Ȳ�����[0, 255]
    //PLAYM4_VIE_MODU_DENOISE
    int denoiseLevel;  //ȥ��ǿ�ȣ�[0, 255]
    //PLAYM4_VIE_MODU_SHARPEN
    int usmAmount;     //��ǿ�ȣ�[0, 255]
    int usmRadius;     //�񻯰뾶��[1, 15]
    int usmThreshold;  //����ֵ��[0, 255]
    //PLAYM4_VIE_MODU_DEBLOCK
    int deblockLevel;  //ȥ��ǿ�ȣ�[0, 100]
    //PLAYM4_VIE_MODU_LENS
    int lensWarp;      //��������[-256, 255]
    int lensZoom;      //��������[-256, 255]
    //PLAYM4_VIE_MODU_CRB
    //����Ӧ����
} PLAYM4_VIE_PARACONFIG;

typedef enum _PLAYM4_VIE_MODULES
{
    PLAYM4_VIE_MODU_ADJ      = 0x00000001, //ͼ���������
    PLAYM4_VIE_MODU_EHAN     = 0x00000002, //�ֲ���ǿģ��
    PLAYM4_VIE_MODU_DEHAZE   = 0x00000004, //ȥ��ģ��
    PLAYM4_VIE_MODU_DENOISE  = 0x00000008, //ȥ��ģ��
    PLAYM4_VIE_MODU_SHARPEN  = 0x00000010, //��ģ��
    PLAYM4_VIE_MODU_DEBLOCK  = 0x00000020, //ȥ���˲�ģ��
    PLAYM4_VIE_MODU_CRB      = 0x00000040, //ɫ��ƽ��ģ��
    PLAYM4_VIE_MODU_LENS     = 0x00000080, //��ͷ�������ģ��
}PLAYM4_VIE_MODULES;
#endif

//���ùر�/����ģ��
//dwModuFlag��ӦPLAYM4_VIE_MODULES��,�����
//������ģ�鿪����������ģ��������ڼ����Ĭ�ϵĲ���;
//�ر�ģ����ϴ����õĲ������
//�����ӿڵ��ã������ڸýӿڿ���ģ��󣻷��򣬷��ش���
PLAYM4_API BOOL __stdcall PlayM4_VIE_SetModuConfig(LONG lPort,int nModuFlag,BOOL bEnable);

//����ͼ����ǿ����NULLȫͼ������ȫͼ������ȫͼ����С����32*32����
//��֧�������������Ƚ�˵4������һ���汾����ֻ֧��һ�����������Ҫ�����ص������ص��ͱ���
PLAYM4_API BOOL __stdcall PlayM4_VIE_SetRegion(LONG lPort,LONG lRegNum,RECT* pRect);

//��ȡ����ģ��
PLAYM4_API BOOL __stdcall PlayM4_VIE_GetModuConfig(LONG lPort,int* pdwModuFlag);

//���ò�����δ����ģ��Ĳ������ñ�����
PLAYM4_API BOOL __stdcall PlayM4_VIE_SetParaConfig(LONG lPort,PLAYM4_VIE_PARACONFIG* pParaConfig);

//��ȡ����ģ��Ĳ���
PLAYM4_API BOOL __stdcall PlayM4_VIE_GetParaConfig(LONG lPort,PLAYM4_VIE_PARACONFIG* pParaConfig);

/**********************����UTC���쿪ʼ**********************************************/
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
/**********************����UTC�������**********************************************/

typedef struct
{
    long    lDataType;          //˽����������
    long    lDataStrVersion;    //���ݷ��صĽṹ��汾����Ҫ��Ϊ�˼�����
    long    lDataTimeStamp;
    long    lDataLength;
    char*   pData;
}AdditionDataInfo;

//�ýӿ�ֻ֧�����¼���˽����Ϣ����
//0x0101: //�����¶�
//0x0103: //�����¶�������
//0x0006: //�����г���Ϣ
//0x0009: //���ص�����Ϣ
//0x0007: //POS��Ϣ�����ص�
//0x000F: //����ӥ����Ϣ
//0x0010: //��������˽����Ϣ
//0x0011: //���˻�˽����Ϣ
//0x0804: //�������Ʒ�˽������
//0x1005: //өʯ˽������
//0x000B: //�豸��չ��Ϣ
//0x0012: //���˽����Ϣ
//0x0014: //ǰ��˽����Ϣ
//0x0106: //�ȳ���˽����Ϣ
//0x100D: //ǰ�˵���˽����Ϣ
//0x0801: //����ͳ��
//0x0102: //������Ϣ
PLAYM4_API BOOL __stdcall PlayM4_SetAdditionDataCallBack(LONG nPort, DWORD nSyncType, void (CALLBACK* AdditionDataCBFun)(long nPort, AdditionDataInfo* pstAddDataInfo, void* pUser), void* pUser);

//�ýӿ�ֻ֧�����¼���˽����Ϣ����
//����ģ�飺
//0x0101: //�����¶�
//0x0103: //�����¶�������
//0x0006: //�����г���Ϣ
//0x0009: //���ص�����Ϣ
//0x0007: //POS��Ϣ�����ص�
//0x000F: //����ӥ����Ϣ
//0x0010: //��������˽����Ϣ
//0x0011: //���˻�˽����Ϣ
//0x0804: //�������Ʒ�˽������
//0x1005: //өʯ˽������
//0x000B: //�豸��չ��Ϣ
//0x0012: //���˽����Ϣ
//0x0106: //�ȳ���˽����Ϣ
//��Ⱦģ�飺
//0x0801: //����ͳ��
//0x0102: //������Ϣ
PLAYM4_API BOOL __stdcall PlayM4_SetMultiAdditionDataCallBack(long nPort, unsigned int* nSyncTypeNode, unsigned int NodeNumber, void (CALLBACK* AdditionDataCBFun)(long nPort, AdditionDataInfo* pstAddDataInfo, void* pUser), void* pUser, void* pReserved);

// ��Ⱦ����ģʽ
typedef enum RenderDrawMode
{
    PLAYM4_ODT_DEFAULT = 0,
    PLAYM4_ODT_GDI     = 1,
    PLAYM4_ODT_D3D     = 2
}PLAYM4_RENDER_DRAW_MODE_E;

// ������Ⱦ�Ļ���ģʽD3D��GDI
// 1.�˽ӿ�����������Ⱦ�����GDI��D3D���ֻ��Ʒ�ʽ��
// 2.�˽ӿ�Ŀǰ������Ⱦ�����ˮӡ��Ϣ�������Ч��б��͸����ˮӡ��Ӳ�����µ���ͨˮӡ���ƣ��������޸���Ⱦ�����ˮӡ�ķ�ʽ��
// 3.GDIģʽ��Ч��Ҫ�Կ�����֧��DDraw��D3D9��D3D11���棻
// 4.D3Dģʽ��Ч��Ҫ�Կ�����֧��D3D9��D3D11���棻
// 5.б��͸����ˮӡ���ƣ�Ч�����棬GDI����D3D����D3D11-GDI֧��͸���ȣ�
// 6.б��͸����ˮӡ���ƣ����ܷ��棬D3D9�����£�GDI����D3D��D3D��Ӱ�컭�濨�٣�D3D11�����£�D3D����GDI��
PLAYM4_API BOOL __stdcall PlayM4_SetRenderDrawMode(LONG nPort, PLAYM4_RENDER_DRAW_MODE_E enRenderDrawMode,int nReserved);

#define SOFT_DECODE_ENGINE 0 ///<�����
#define HARD_DECODE_ENGINE 1 ///<Ӳ����

// ֧����ͷ��������Ӳ���룬���óɹ�˵����ǰϵͳ����֧��Ӳ����
// ���ڵ�ǰ�����ĸ�ʽ��ֱ����Ƿ�֧��Ӳ���룬��Ҫ���Ź������ڲ���⣬����֧�����Զ������
PLAYM4_API BOOL  __stdcall PlayM4_SetDecodeEngineEx(LONG nPort, DWORD nDecodeEngine);
PLAYM4_API DWORD __stdcall PlayM4_GetDecodeEngine(LONG nPort);

#define PLAYM4_SOURCE_MODULE             0 // ����Դģ��,��8bit��ȡֵ��ΧΪ[1,10],��Ӧ16���Ƶ�[0x01,0x0A]



#define PLAYM4_DEMUX_MODULE              1 // ����ģ��, ��8bit��ȡֵ��ΧΪ[11,20],��Ӧ16���Ƶ�[0x0B,0x14]

#define PLAYM4_RTINFO_IDMX_DATA_ERROR              32 // ��������,����ʧ��
#define PLAYM4_RTINFO_IDMX_PSH_PSM_ERROR         0x100// PSH/PSM����,����ʧ��
#define PLAYM4_RTINFO_IDMX_RTP_HEADER_ERROR      0x200// RTPͷ���󣬰�����չͷ
#define PLAYM4_RTINFO_IDMX_RTP_HEADER_SEQ_ERROR  0x400// RTP��Ƶ��������
#define PLAYM4_RTINFO_IDMX_REDUNDANT_ERROR       0x800// ����������������
#define PLAYM4_RTINFO_IDMX_MEDIA_CHANGE_ERROR             0x1000// ý����Ϣ�����ı�(��hikͷ����Ϣ��һ�»���psm���������Ƶ���ͷ����ı�)
#define PLAYM4_RTINFO_IDMX_DIFFERENT_FRAMERATE_ERROR      0x2000// ��װ��֡��������֡�ʲ�һ��
#define PLAYM4_RTINFO_IDMX_DIFFERENT_RESOLUTION_ERROR     0x4000// ��װ��ֱ���������ֱ��ʲ�һ��
#define PLAYM4_RTINFO_IDMX_DECORD_ERROR                   0x8000// �������쳣
#define PLAYM4_RTINFO_IDMX_PRIVT_LEN_ERROR                0x10000// ˽�����ݳ����쳣
#define PLAYM4_RTINFO_IDMX_REAL_FRAMERATE                 0x100000 // ʵʱ֡�ʱ仯֪ͨ����ʱ��RunTimeInfo�ṹ�����nFrameTimeStamp��ʾ����֡��ƽ��ʱ�������䵹����Ϊ��ǰʵ��֡��
#define PLAYM4_RTINFO_IDMX_I_FRAME_FLAG                   0x400000  //RTP��֡֡����



#define PLAYM4_DECODE_MODULE             2 // ����ģ��,��8bit�ֽڵ�ȡֵ��ΧΪ[21,30],��Ӧ16���Ƶ�[0x15,0x1E]

#define PLAYM4_RTINFO_DECODE_PARAM_ERROR                       64 // ��������,����ʧ��
#define PLAYM4_RTINFO_SOFTDECODE_DATA_ERROR                   128 // ��������ݴ���
#define PLAYM4_RTINFO_SOFTDECODE_DATA_FLAKE_ERROR         0x20000 //��������ݴ��ڻ�������



#define PLAYM4_RENDER_MODULE             3 // ��Ⱦģ��, ��8bit�ֽڵ�ȡֵ��ΧΪ[31,40],��Ӧ16���Ƶ�[0x1F,0x28]

#define PLAYM4_RTINFO_RENDER_OVER                         8 // ��Ⱦһ֡����
#define PLAYM4_RTINFO_ERR_PRESENT                        16 // ��Ⱦ��ʾ����[��ǰ��Ⱦ������Ⱦʧ��,�ϲ������л�����]
#define PLAYM4_RTINFO_RENDER_MEDIAUPDATE_FLAG      0x800000 // �ֱ��ʷ����仯֪ͨ
#define PLAYM4_RTINFO_RENDER_BEGIN                 0x1F000001 //��Ⱦģ����Ⱦһ֡��ʼ
#define PLAYM4_RTINFO_RENDER_WINDOW_IS_NULL        0x1F000002 //��Ⱦģ����Ⱦ�����Ǵ���Ϊ�գ���ʱ֡���ݲ�����ȥ��ʾ�����ǻᴥ���˻ص�ȫ��ʱ��,��֪��ǰ���Ž���


#define PLAYM4_MANAGER_MODULE            4 // ����ģ��,��8bit�ֽڵ�ȡֵ��ΧΪ[41,50],��Ӧ16���Ƶ�[0x29,0x32]

#define PLAYM4_RTINFO_RTINFO_SOURCE_DATA_INTERVAL         0x40000
#define PLAYM4_RTINFO_MANAGER_SYC_LONG_WAIT               0x80000
#define PLAYM4_RTINFO_MANAGER_I_FRAME_FLAG                0x200000    //PS��֡����
#define PLAYM4_RTINFO_MANAGER_DATA_DETECT_FEEDBACK        0x29000001 //̽��������,RunTimeInfo�ṹ����reserved[0]��ֵΪ0��ʾ̽��ʧ�ܣ�Ϊ1��ʾ̽��ɹ�


#define PLAYM4_RTINFO_HARDDECODE_ERROR   0 // Ӳ��������(��Ҫ�����)����
#define PLAYM4_RTINFO_SOFTDECODE_ERROR   1 // ��������(����)
#define PLAYM4_RTINFO_MEDIAHEADER_ERROR  2 // ý��ͷ����
#define PLAYM4_RTINFO_SWITCH_SOFT_DEC    3 // �л������
#define PLAYM4_RTINFO_ALLOC_MEMORY_ERROR 4 // �ڴ����ʧ��
#define PLAYM4_RTINFO_ENCRYPT_ERROR      5 // ��Կ���� [���ܵ������ڽ�������ʱҲ��ص��ô�����]

// �����ֽڶ��壺
// 1.��ע��PLAYM4_RTINFO_MANAGER_I_FRAME_FLAG��PLAYM4_RTINFO_IDMX_I_FRAME_FLAG��reserved[0]����I֡��ǣ���ֵΪ0��ʾ��I֡��Ϊ1��ʾI֡��
// 2.��ע��PLAYM4_RTINFO_RENDER_OVER 8 ��reserved[0]�����״̬���µ���չ�ֶ����ص�����Ϣ���ͣ�
//   reserved[0] = 0����ʾ��չ�ֶ�Ϊȫ��ʱ��,
//       reserved[1]reserved[2] - �꣬reserved[3] - �£�reserved[4] - �գ�reserved[5] - ʱ��reserved[6] - �֣�reserved[7]��reserved[8]reserved[9] - ms
//   reserved[0] = 1����������չ...
typedef struct
{
	int            nRunTimeModule;     //��ǰ����ģ��
	int            nStrVersion;        //�ṹ��汾
	int            nFrameTimeStamp;    //֡��
	int            nFrameNum;          //ʱ���
	int            nErrorCode;         //״̬��-���Ƕ��Ǵ�����Ϣ
	unsigned char  reserved[12];       //�����ֽڣ��˱����ֶβ����޸ģ�
}RunTimeInfo;

// Ҫ��ͬģ��Ļص���������Ϊͬһ���������ע��Ľ����ǵ���ע���
PLAYM4_API BOOL __stdcall PlayM4_SetRunTimeInfoCallBackEx(LONG nPort, int nModule, void (CALLBACK* RunTimeInfoCBFun)(long nPort, RunTimeInfo* pstRunTimeInfo, void* pUser), void* pUser);

// 1��SetRunTimeInfoCallBackEx�ӿڣ�nErrorCode����6��Ϊ����8���Ժ���չ��ʽ 16��32��64���Ҵ�8��ʼ��ϢĬ�Ϲرղ����͡�
// 2������ʵʱ��Ϣ���ƽӿڣ����ƴ�8�Ժ����Ϣ��֧�ִ�8��ʼ����Ϣ��ƴ��ģʽ 8|16|32 ���ַ�ʽ���ϲ�����ѡ��������͡�
// 3��nType����ͨ����ķ�ʽ�����ʹ��룬nFlag��ʾ�����Ϊ0�����߽��лص�����0�������ǣ���ʵʱ��Ϣ����0x80000Ϊ���ޣ�С�ڸ�����ֵ��
// ����ͨ�������ʽһ�δ������ص���Ϣ���ͣ����ڸ�����ֵ�ģ�������ǻص���Ϣ���͵ĸ�8bit�ֽ�ֵ��ȣ��ſ���ͨ�������ʽһ���Դ���;
// ��˵��������0x08��0x80000��0x1F000001��0x1F000002��������Ҫ�ص�ʱ�����������������ʹ���ӿڣ�0x08 | 0x80000��Ϊһ�飬���øýӿڴ���һ��; 
// ��0x1F000001 | 0x1F000002��Ϊһ���ٴε��øýӿڴ���һ�Σ���ȻҲ֧���㵥������������4�νӿ�ÿ�δ���һ���ص����ͣ�
PLAYM4_API int __stdcall PlayM4_SetRunTimeInfoCallbackType(int nPort, int nModule, unsigned int nType, int nFlag);

PLAYM4_API BOOL __stdcall PlayM4_RegisterImageMattingCallBack( long nPort, void (CALLBACK* ImageMattingCBFun) ( long nPort, IMAGE_MATTING_INFO* pstImageInfo, void* pUser), IMAGE_MATTING_CONFIG* ParamConfig, void* pUser);
PLAYM4_API BOOL __stdcall PlayM4_SetMosaicType(LONG nPort, MOSAIC_TYPE_CONFIG* pstMosaicParam);
PLAYM4_API BOOL __stdcall PlayM4_SelectTargetToDrawMosaic(LONG nPort, MOSAIC_NEED_DRAW* pstMosaicParam, BOOL bTrue);

#ifndef INTELINFO_NEED_DRAW_TAG
#define INTELINFO_NEED_DRAW_TAG

typedef struct _INTELINFO_NODE_LIST_
{
	unsigned int  nID;          //ID
	unsigned char nType;        //1������ͨĿ�꣬2����������Ŀ�꣬4������ͨ����8��������������
	unsigned char reserved[19]; //������չλ
}INTELINFO_NODE_LIST;

typedef struct _INTELINFO_NEED_DRAW_
{
	INTELINFO_NODE_LIST*       pIntelInfoNode;  //Ŀ��ڵ�ָ�룬����NodeNumber������ƫ�ƶ�ȡ����
	unsigned int               NodeNumber;      //�ڵ����
	unsigned char              reserved[20];    //������չλ
}INTELINFO_NEED_DRAW;

#endif
////ѡ������˽����ϢID����,֧�ֺ�������/��ͨ��Ŀ��򡢹����
////nType��ʾ��Ҫ�ص���˽����Ϣ����
////bTrueΪ1��ʾ�������ܣ�Ϊ0��ʾ�رչ���
////nModeΪ0��ʾ����ѡ��ID��Ϊ1��ʾ������ѡ��ID��Ŀǰ��֧��ѡ��ID���ƣ�����Ҫ����0
PLAYM4_API BOOL __stdcall PlayM4_SelectIntelInfoFeatureToDraw(LONG nPort, INTELINFO_NEED_DRAW* pstIntelInfoParam, BOOL bTrue, DWORD nMode, void* nReserved);

#ifndef PLAYM4_HIKSR_TAG
#define PLAYM4_HIKSR_TAG

#define CFG_DISPLAY_EAGLE_PARAMS_EX    0x497  //���ߵ�����,��Э��
#define CFG_DISPLAY_EAGLE_PARAMS       0x498  //���ߵ�����,��Э��
#define CFG_DISPLAY_MODEL_MODE         0x499  //����ӥ������

// ģ����ͼ���� 0 ˫�� 1 ���� 2 ���� 
typedef enum tagPLAYM4SRTextureMode
{
    PLAYM4_TEXTURE_DOUBLE       = 0x0,           // ˫��������
    PLAYM4_TEXTURE_OUTER        = 0x1,           // �����������
    PLAYM4_TEXTURE_INNER        = 0x2,           // �ڱ���������
}PLAYM4SRTEXTUREMODE;

//ģ������
typedef enum tagPLAYM4SRModelType
{
    PLAYM4_MODELTYPE_HEMISPHERE = 0x0,           //������Ƶ�ð���ģ��
    PLAYM4_MODELTYPE_EAGLE_EYE  = 0x1,           //��״�����ģ������ӥ��ƴ��
    PLAYM4_MODELTYPE_CUBE       = 0x2,           //������ģ��
}PLAYM4SRMODELTYPE;

#define PLAYM4_MODEL_SOLID      0x0001           //ʵ��ģ��
#define PLAYM4_MODEL_FRAME      0x0010           //�߿�ģ��
#define PLAYM4_MODEL_AXIS       0x0100           //������

//��Ⱦ��3Dģ�͵���ز���
typedef struct tagRenderModelMode
{
    bool                          bModelMode;      // �Ƿ���Ⱦ��3Dģ����
    PLAYM4SRTEXTUREMODE           emTextureMode;   // ������ͼģʽ ˫�� ����� �ڱ���
    unsigned long                 ulDisplayType;   // ��λ��� SR_MODEL_SOLID | SR_MODEL_FRAME | SR_MODEL_AXIS
    unsigned int                  nTransformMode;  // 0 �߿���������ģ�ͱ任  1 �߿������᲻��ģ�ͱ任
    PLAYM4SRMODELTYPE             emModelType;     // ģ�����ͣ����۰���ӥ����ģ�͵�
}PLAYM4SRMODELMODE;

//...................CFG_DISPLAY_EAGLE_PARAMS       0x498  ���ߵ�����,��Э�� ��Ӧ�ṹ�����...............//
typedef struct tagPLAYM4SREagleEyeParam
{
    unsigned int  nCameraIndex;   //������ 0-7
    double        fAlpha;         //alpha�Ƕ�ֵ�����洹ֱ�˶�  -90.0 �C 90.0
    double        fBeta;          //beta�Ƕ�ֵ������ˮƽ�˶�   -90.0 �C 90.0
    double        fGamma;         //gamma�Ƕ�ֵ��������ת      -90.0 - 90.0
    double        fFov;           //fov������Ŵ���С          40.0  - 80.0
    unsigned char ucReserved[32]; //�����ֶ�
}PLAYM4SREAGLEEYEPRAM;

//...................CFG_DISPLAY_EAGLE_PARAMS_EX    0x497  ���ߵ�����,��Э�� ��Ӧ�ṹ�����...............//

//�µ�Сӥ�������νṹ��
typedef struct tagPLAYM4SRCameraParam
{
    float          fAlpha;                           ///< ����ڲ�
    float          fBeta;                            ///< ����ڲ�
    float          fGamma;                           ///< ����ڲ�
    float          fFov;                             ///< ����ڲ�
    float          fx;                               ///< fx,fy,cx,cyΪ����ڲα궨��
    float          fy;
    float          cx;
    float          cy;
    float          t1;                              ///< t1, t2, t3Ϊ�����α궨��
    float          t2;
    float          t3;
    float          pReserved[13];                    ///< ��������
}PLAYM4_SRCAMERA_PARAM;

//�µ�Сӥ���������ⲿ����ṹ��
typedef struct tagPLAYM4NewEagleEyeParam
{
    int                     nType;                            ///< ������������, 1Ϊ����nMode, 2Ϊ����nDistance, 4Ϊ���������Σ������������Խ�����ϣ���3��ʾͬʱ����nMode��nDistance
    int                     nCameraIndex;                     ///< ������(Ŀǰ�˸������ŷֱ�Ϊ0-7)
    int                     nMode;                            ///< ��ε���ģʽ��Ŀǰ������ģʽ,0��ʾ�ֶ��궨���ߣ�1��ʾ���߱궨��2��ʾ�Զ��궨
    float                   nDistance;                        ///< ʵ��ͶӰ���루���߾���Ϊ1.5��,��λΪ��
    PLAYM4_SRCAMERA_PARAM   stCamParam;                       ///< �����νṹ��
    float                   pReserved[8];                     ///< ��������
}PLAYM4_SRNEW_EAGLEEYE_PARAM;

#endif

//nCfgTypeΪ0x499��ʾ��������ӥ�ۣ�pValue��ӦPLAYM4SRMODELMODE������ӥ���������������ô����ͣ�
//nCfgTypeΪ0x498��ʾ��������ӥ�����ߵ����ã���Э���豸��pValue��ӦPLAYM4SREAGLEEYEPRAM��
//nCfgTypeΪ0x497��ʾ��������ӥ�����ߵ����ã���Э���豸��pValue��ӦPLAYM4_SRNEW_EAGLEEYE_PARAM��
PLAYM4_API BOOL __stdcall PlayM4_SR_SetConfig(LONG nPort, int nCfgType, void *pValue);

PLAYM4_API BOOL __stdcall PlayM4_SR_Rotate(LONG nPort, PLAYM4SRTRANSFERPARAM *pstRotateParam);

#define SR_JPEG    0
#define SR_BMP     1

PLAYM4_API BOOL __stdcall PlayM4_SR_Capture(LONG nPort, unsigned int nType, char *pFileName);

#ifndef PLAYM4_PICTURE_FILL_TAG
#define PLAYM4_PICTURE_FILL_TAG

typedef struct _PICTURE_FILL_INFO_   //ͼƬ�����Ϣ
{
    int                 nType;          //֧������ 1����ʾ����ָ��ͼƬ͸���ȵ���
                                        //         2����ʾ������������ϸ
    int                 nAlpha;         //͸���ȷ�Χ[0,100], 0��ʾ��ȫ͸����100��ʾ��͸��
    int                 reserved[10];   //��չԤ�� nType:2ʱ��reserved[0]��ʾ������߿���Χ1-10

}PICTURE_FILL_INFO;

#endif

//ͼƬ�������������������
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

//ˮӡ�����С
typedef struct tagWatermarkFontSize
{
	unsigned int nFontWidth;         // ����� ����0
	unsigned int nFontHeight;        // ����� ����0
}WATERMARK_FONTSIZE;

//ˮӡ���Ӹ���
typedef struct tagWatermarkNumber
{
	unsigned int nRowNumber;        // ����,nFillFullScreenΪtrueʱ����Ҫ�õ��˲���,С��14
	unsigned int nColNumber;        // ������С��14
}WATERMARK_NUMBER;

//ˮӡ����Ӧ��Ϣ
typedef struct tagWatermarkWindowAdapt
{
	unsigned int nWindowAdaptMode;  // 0 �C �̶������С�͹̶�������������������Ӧ���㣬���������WATERMARK_FONTSIZE��WATERMARK_NUMBER��ֵ������ʾ����1 �C ������������������Ӧ�ı䣨�����С���䣬WATERMARK_NUMBER��ֵʧЧ����  2 �C �����С��������Ӧ�ı� �����������䣩
	unsigned int nRowSpace;         // ��������Ӧ�������м�� nWindowAdaptMode == 1ʱ�õ������㷽ʽ��������nRowSpace = 300����ǰ���ڴ�С = 900������ = 900/300 = 3�������ڴ�С����1200ʱ����������Ӧ���� = 1200/300 = 4
	unsigned int nColSpace;         // ��������Ӧ�������м��nWindowAdaptMode == 1ʱ�õ�
	unsigned int nBaseWindowWidth;  // ������������Ļ�׼���ڿ� nWindowAdaptMode == 2ʱ�õ������㷽ʽ������stWatermarkFontSize. nFontWidth = 20��nBaseWindowWidth = 900�������С =��ǰ���ڿ� * 20 / 900 ���統ǰ���ڿ�Ϊ1200ʱ�������С = 1200 * 20 / 900 = 26
	unsigned int nBaseWindowHeight; // ������������Ļ�׼���ڿ�nWindowAdaptMode == 2ʱ�õ�
}WATERMARK_WINDOWADAPT;

//ˮӡ��ת��Ϣ
typedef struct tagWatermarkRotateInfo
{
	float fRotateAngle;               // ��ת�Ƕȣ���λ�ȣ�0~360�ȣ�
	unsigned int nFillFullScreen;     // Ϊtrue��ʾ����ȫ�������ڻ�����б����ʾn����false��ʾֻ��ʾһ��
}WATERMARK_ROTATEINFO;

/*ˮӡ���뷽ʽ*/
typedef enum tagWaterMarkAlignment
{
	CENTER_ALIGNMENT   = 0,       // ���ж���
	LEFT_ALIGNMENT     = 1        // �����
}WATERMARK_ALIGNMENT;

//ˮӡ��Ϣ�ṹ��
typedef struct _WATERMARK_FONT_INFO_
{
	char**                WatermarkFontArray;       //ˮӡ��Ϣ�����ַ����ʾchar*�����׵�ַ��ÿ��char*Ԫ�ر�ʾһ����
	unsigned int*         WatermarkFontLengthArray; //ÿ���ֵ��ַ������ȣ�����С��200
	unsigned int          WatermarkFontNum;         //ˮӡ��Ϣ�����������ʾ�м����֣�С��9
	float                 fFontSpace;               //�����ּ�ࣺ����ȡֵ��Χ��1~2������ʾ����ߵı�����1���ǽ���
	unsigned int          nColorAdapt;              //��ɫ����Ӧ
	WATERMARK_ALIGNMENT   emFontAlign;              //�����ֵĶ��뷽ʽ��
	PTZPARAM              stWatermarkStartPos;      //ˮӡ��������
	FECCOLOR              stWatermarkColor;         //ˮӡ��ɫ
	WATERMARK_FONTSIZE    stWatermarkFontSize;      //ˮӡ�����С
	WATERMARK_ROTATEINFO  stWatermarkRotateInfo;    //ˮӡ��ת��Ϣ
	WATERMARK_NUMBER      stWatermarkNumber;        //ˮӡ���Ӹ���
	WATERMARK_WINDOWADAPT stWatermarkWindowAdapt;   //ˮӡ����Ӧ��Ϣ
	char                  nWatermarkDisplayStyle;   //ˮӡ������ʽ������1��ʾ������ڱ���ʽ������1��ˮӡ��ɫ����ɫ����Ӧ���ܾ�����Ч��
	char                  nOverlayGlobalTime;       //��ʾ�Ƿ���Ҫ���ſ��ڲ�����ȫ��ʱ�䣬����Ϊ1��ʾ��Ҫ���ӣ��򲥷ſ��ڵ�һ��ˮӡ�̶�����ȫ��ʱ�䣬�ⲿ����ˮӡ���ݴӵڶ��п�ʼ��
	char                  reserved[18];             //��������
}WATERMARK_FONT_INFO;

#endif

//1.�˽ӿ�����ˮӡ�����ַ�ֻ֧��utf8��ʽ��
//2.�˽ӿ�ֻ֧���ڻ��沥�ź���ã���PlayM4_Play�ӿں������Ч������ǰ������Ч��
//3.�˽ӿ�ֻ֧����D3D11��Ⱦ��������Ч�����Ե���һ����Ҫ���ò��ſ�ӿ��л�D3D11��Ⱦ���棻
PLAYM4_API BOOL __stdcall PlayM4_SetWatermarkFont(int nPort, WATERMARK_FONT_INFO* pWatermarkFontInfo, void* nReserved);
//PLAYM4_API int __stdcall PlayM4_SetPlayCtrlLogFlag(bool bFlag, char* pConfigFilePath, PLAYM4_LOG_LEVEL emLogLevel);
///�طŲ��Ź����У����������󣬴�����ǰ���һ֡���Ǹ�ʱ�̿�ʼ���ţ������ν�׼ȷ��
//nFlag��1��ʾ�ӿ���Ч���ӵ�ǰ����֡��ʼ�ν�
PLAYM4_API BOOL __stdcall PlayM4_PlayFromCurrentFrame(int nPort, int nFlag, void* pRes);

///������������Ӧ��֡���ܺ󣬵�ǰ�Ƿ񴥷���֡
PLAYM4_API BOOL __stdcall PlayM4_GetLostFrameState(int nPort, int* pLostFrameState, void* pRes);

//Ϊ�ﵽ֡����ƽ���϶������ر任��������������л��Ļ��������ԣ����ſ������һ�ִ󻺴�ģʽ��
//���洢����Ľ�����֡����֤���ر任����ʱ�ܹ�������Ӧ������������½ӿڣ��������󻺴�ģʽ��
//�˽ӿ�����¿��������200����D3D11Ӳ����ֻ�����������50����D3D9Ӳ���벻֧�����ô󻺴棻
PLAYM4_API BOOL __stdcall PlayM4_SetBigBufMode(LONG nPort, DWORD nBufNum, void* pReserved);

//GOP��ϵͳʱ��
typedef struct 
{
	BOOL                 GetGOPSystemTimeFlag; //�Ƿ���Ի�ȡ�����������͵����ſ��GOP����֡��β֡��ϵͳʱ��
	PLAYM4_SYSTEM_TIME   stGOPStartSystemTime; //���������͵����ſ�GOP����֡I֡��ϵͳʱ��
	PLAYM4_SYSTEM_TIME   stGOPEndSystemTime;  //���������͵����ſ��GOPβ֡P֡��ϵͳʱ��
	int                  nReserved[10];       //�����ֽ�
} PLAYM4_GOP_SYSTEM_TIME;

//ƽ���϶�ϵͳʱ��֪ͨ�ӿڣ���Ҫ�����Ǹ�֪���ſⶨλ������һ֡���ýӿ����첽�ӿڣ�
//�ýӿ�ֻ��������ϵͳʱ�䣬���ſ��ڲ��յ�ϵͳʱ��󣬽ӿ����̷��سɹ���Ȼ�󲥷ſ��ڲ��߳�ִ��Ѱ�Ҹ�֡�����в���
//stSystemTime����ʾƽ���϶�Ҫ����ʱ�̵�ϵͳʱ�䣨ʵ���ǽ������ϵ�ϵͳʱ�䣬��֡������ϵͳʱ����ܲ�һ������ʱ���ſ�ֻ���ҵ����Ƶ�֡����
//bFlag����ʾ�Ƿ�����֡�����ƽ���϶���Ϊtrue��ʾ��������ʱstSystemTime�������ã���Ϊfalseʱ����ʾȡ��֡����Ķ�λ���ţ��ָ�ԭ�ȵ�ƽ���϶���ʽ����ֻ����I֡�ķ�ʽ��
//stGOPSystemTime����ʾ֡����ƽ���϶�ʱ���͸����ſ��GOP��ϵͳʱ�䣻

PLAYM4_API BOOL __stdcall PlayM4_PlayOneFrameBySystemTime(LONG nPort, PLAYM4_SYSTEM_TIME stSystemTime, BOOL bFlag, PLAYM4_GOP_SYSTEM_TIME stGOPSystemTime );


///<Ԥ¼����ؽӿ�//////////////////////////////////////////////////////////////////////////
#define PLAYM4_MEDIA_HEAD     1   //ϵͳͷ����
#define PLAYM4_VIDEO_DATA     2   //��Ƶ������
#define PLAYM4_AUDIO_DATA     3   //��Ƶ������
#define PLAYM4_PRIVT_DATA     4   //˽��������

//Ԥ¼��������Ϣ
typedef struct  
{
    long nType;                     // �������ͣ����ļ�ͷ����Ƶ����Ƶ��˽�����ݵ�
    long nStamp;                    // ʱ���
    long nFrameNum;                 // ֡��
    long nBufLen;                   // ���ݳ���
    char* pBuf;                     // ֡���ݣ���֡Ϊ��λ�ص�
    PLAYM4_SYSTEM_TIME  stSysTime;  // ȫ��ʱ��
}RECORD_DATA_INFO;


/////////////////////////////////////////////////////////////////////////////////////////////
//Unproposed Interface ������ʹ�õĽӿ�
/////////////////////////////////////////////////////////////////////////////////////////////
PLAYM4_API BOOL __stdcall PlayM4_RigisterDrawFun(LONG nPort,void (CALLBACK* DrawFun)(long nPort,HDC hDc,void* nUser),void* nUser);
PLAYM4_API BOOL __stdcall PlayM4_SetDecCallBack(LONG nPort,void (CALLBACK* DecCBFun)(long nPort,char * pBuf,long nSize,FRAME_INFO * pFrameInfo, void* nReserved1,void* nReserved2));
PLAYM4_API BOOL __stdcall PlayM4_SetDecCallBackEx(LONG nPort,void (CALLBACK* DecCBFun)(long nPort,char * pBuf,long nSize,FRAME_INFO * pFrameInfo, void* nReserved1,void* nReserved2), char* pDest, long nDestSize);
PLAYM4_API BOOL __stdcall PlayM4_SetSycStartTime(LONG nPort, PLAYM4_SYSTEM_TIME *pstSystemTime);
PLAYM4_API BOOL __stdcall PlayM4_SyncToAudio(LONG nPort, BOOL bSyncToAudio);
PLAYM4_API BOOL __stdcall PlayM4_SetDecodeEngine(LONG nPort, DWORD nDecodeEngine);
PLAYM4_API BOOL __stdcall PlayM4_SetRunTimeInfoCallBack(LONG nPort, void (CALLBACK* RunTimeInfoCBFun)(long nPort, RunTimeInfo* pstRunTimeInfo, void* pUser), void* pUser);

//Hlogд��־���ؽӿڡ���һport�Ŀ��ز����Ըý���������port���������á�Ŀǰ�����ļ�·�������������ã���Ϊ�������ܵ���չ����Ԥ����
PLAYM4_API BOOL __stdcall PlayM4_SetHLogFlag(int nPort, BOOL bFlag, char* pConfigFilePath);

/////////////////////////////////////////////////////////////////////////////////////////////
//Unsupported Interface ����֧�ֵĽӿ�
/////////////////////////////////////////////////////////////////////////////////////////////
//����Ԥ¼�񿪹أ�bFlag=1������bFlag=0�ر�
PLAYM4_API BOOL __stdcall PlayM4_SetPreRecordFlag(LONG lPort, BOOL bFlag);
//Ԥ¼���������ݻص�
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
