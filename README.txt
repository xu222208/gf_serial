
该SDK目前仅有2个接口函数，具体使用参考sample.c

/*******************************************************************************************************/
1. int sdk_init(VPSS_GRP Grp, VPSS_CHN Chn, HI_U32 u32Width, HI_U32 u32Height, HI_U32 u32PixelFormat)
	
用于jvt-sdk的初始化。成功返回0，失败返回-1。
// Grp：VPSS GROUP 号。
// Chn：VPSS Chn 号。
// u32Width：目标图像宽度。
// u32Height：目标图像高度。
// u32PixelFormat：目标图像像素格式。

/*******************************************************************************************************/
2. int GetOneFrame( VPSS_GRP Grp, VPSS_CHN Chn, char* pBuf, int *pLen )

用于获取一帧视频的YUV数据。成功返回0，失败返回-1。
// Grp：VPSS GROUP 号。
// Chn：VPSS Chn 号。
// pBuf：YUV数据缓存。
// pLen：YUV数据长度。