#include "KedaMctfDenoise.h"

/*====================================================================
函数名      ：KedaMctfCopyImageFromYUV420
功能    	：YUV420数据分别获取Y U V数据
引用全局变量：无
输入参数说明：pu8BufY：	        Y数据指针		Out
			  pu8BufU：		    U数据指针		Out
			  pu8BufV：         V数据指针		Out
			  s32Width：		图像列数		in
			  s32Height：		图像行数		in
			  pu8YUV：			YUV数据指针		in		Planar型
返回值说明  ：无
====================================================================*/
s32 KedaMctfCopyImageFromYUV420(u8 *pu8BufY, u8 *pu8BufU, u8 *pu8BufV, s32 s32Width, s32 s32Height, u8 *pu8YUV)
{
	s32 s32Row, s32Col;
	s32 s32UOffset, s32VOffset;

	s32UOffset = s32Width * s32Height;
	s32VOffset = s32Width * s32Height + s32Width * s32Height / 4;

	for(s32Row = 0;s32Row < s32Height; s32Row++)
	{
		for(s32Col = 0;s32Col < s32Width; s32Col++)
		{
			pu8BufY[s32Row * s32Width + s32Col] = pu8YUV[s32Row * s32Width + s32Col];
		}
	}

	for(s32Row = 0;s32Row < s32Height / 2; s32Row++)
	{
		for(s32Col = 0;s32Col < s32Width / 2; s32Col++)
		{
			pu8BufU[s32Row * s32Width / 2 + s32Col] = pu8YUV[s32UOffset + s32Row * s32Width / 2 + s32Col];
		}
	}

	for(s32Row = 0;s32Row < s32Height / 2; s32Row++)
	{
		for(s32Col = 0;s32Col < s32Width / 2; s32Col++)
		{
			pu8BufV[s32Row * s32Width / 2 + s32Col] = pu8YUV[s32VOffset + s32Row * s32Width / 2 + s32Col];
		}
	}

	return 0;
}

/*====================================================================
函数名      ：KedaMctfCopyImageFromYUV422
功能    	：YUV422数据分别获取Y U V数据
引用全局变量：无
输入参数说明：pu8BufY：	        Y数据指针		out
			  pu8BufU：		    U数据指针		out
			  pu8BufV：         V数据指针		out
			  s32Width：		图像列数		in
			  s32Height：		图像行数		in
			  pu8YUV：			YUV数据指针		planar型
返回值说明  ：无
====================================================================*/
s32 KedaMctfCopyImageFromYUV422(u8 *pu8BufY, u8 *pu8BufU, u8 *pu8BufV, s32 s32Width, s32 s32Height, u8 *pu8YUV)
{
	s32 s32Row, s32Col;
	s32 s32UOffset, s32VOffset;

	s32UOffset = s32Width * s32Height;
	s32VOffset = s32Width * s32Height + s32Width * s32Height / 2;

	for(s32Row = 0;s32Row < s32Height; s32Row++)
	{
		for(s32Col = 0;s32Col < s32Width; s32Col++)
		{
			pu8BufY[s32Row * s32Width + s32Col] = pu8YUV[s32Row * s32Width + s32Col];
		}
	}

	for(s32Row = 0;s32Row < s32Height; s32Row++)
	{
		for(s32Col = 0;s32Col < s32Width / 2; s32Col++)
		{
			pu8BufU[s32Row * s32Width / 2 + s32Col] = pu8YUV[s32UOffset + s32Row * s32Width / 2 + s32Col];
		}
	}

	for(s32Row = 0;s32Row < s32Height; s32Row++)
	{
		for(s32Col = 0;s32Col < s32Width / 2; s32Col++)
		{
			pu8BufV[s32Row * s32Width / 2 + s32Col] = pu8YUV[s32VOffset + s32Row * s32Width / 2 + s32Col];
		}
	}

	return 0 ;
}

/*====================================================================
函数名      ：KedaMctfSaveImageFromYUV420
功能    	：将Y U V数据保存成YUV420数据
引用全局变量：无
输入参数说明：pu8BufY：	        Y数据指针		in
			  pu8BufU：		    U数据指针		in
			  pu8BufV：         V数据指针		in
			  s32Width：		图像列数		in
			  s32Height：		图像行数		in
			  pu8YUV：			YUV数据指针		out
返回值说明  ：无
====================================================================*/
s32 KedaMctfSaveImageFromYUV420(u8 *pu8BufY, u8 *pu8BufU, u8 *pu8BufV, s32 s32Width, s32 s32Height, u8 *pu8YUV)
{
	s32 s32Row, s32Col;
	s32 s32UOffset, s32VOffset;

	s32UOffset = s32Width * s32Height;
	s32VOffset = s32Width * s32Height + s32Width * s32Height / 4;

	for(s32Row = 0; s32Row < s32Height; s32Row++)
	{
		for(s32Col = 0; s32Col < s32Width; s32Col++)
		{
			pu8YUV[s32Row * s32Width + s32Col] = pu8BufY[s32Row * s32Width + s32Col];
		}
	}

	for(s32Row = 0; s32Row < s32Height / 2; s32Row++)
	{
		for(s32Col = 0; s32Col < s32Width / 2; s32Col++)
		{
			pu8YUV[s32UOffset + s32Row * s32Width / 2 + s32Col] = pu8BufU[s32Row * s32Width / 2 + s32Col];
		}
	}

	for(s32Row = 0;s32Row < s32Height / 2; s32Row++)
	{
		for(s32Col = 0;s32Col < s32Width / 2; s32Col++)
		{
			pu8YUV[s32VOffset + s32Row * s32Width / 2 + s32Col] = pu8BufV[s32Row * s32Width / 2 + s32Col];
		}
	}

	return 0;
}

/*====================================================================
函数名      ：KedaMctfSaveImageFromYUV422
功能    	：将Y U V数据保存成YUV422数据
引用全局变量：无
输入参数说明：pu8BufY：	        Y数据指针		in
			  pu8BufU：		    U数据指针		in
			  pu8BufV：         V数据指针		in
			  s32Width：		图像列数		in
			  s32Height：		图像行数		in
			  pu8YUV：			YUV数据指针		out
返回值说明  ：无
====================================================================*/
s32 KedaMctfSaveImageFromYUV422(u8 *pu8BufY, u8 *pu8BufU, u8 *pu8BufV, s32 s32Width, s32 s32Height, u8 *pu8YUV)
{

	s32 s32Row, s32Col;
	s32 s32UOffset, s32VOffset;

	s32UOffset = s32Width * s32Height;
	s32VOffset = s32Width * s32Height + s32Width * s32Height / 2;

	for(s32Row = 0; s32Row < s32Height; s32Row++)
	{
		for(s32Col = 0; s32Col < s32Width; s32Col++)
		{
			pu8YUV[s32Row * s32Width + s32Col] = pu8BufY[s32Row * s32Width + s32Col];
		}
	}

	for(s32Row = 0; s32Row < s32Height; s32Row++)
	{
		for(s32Col = 0; s32Col < s32Width / 2; s32Col++)
		{
			pu8YUV[s32UOffset + s32Row * s32Width / 2 + s32Col] = pu8BufU[s32Row * s32Width / 2 + s32Col];
		}
	}

	for(s32Row = 0;s32Row < s32Height; s32Row++)
	{
		for(s32Col = 0;s32Col < s32Width / 2; s32Col++)
		{
			pu8YUV[s32VOffset + s32Row * s32Width / 2 + s32Col] = pu8BufV[s32Row * s32Width / 2 + s32Col];
		}
	}

	return 0;
}

/*====================================================================
函数名      ：KedaMctfReadImageFromYUV420					从文件中读取YUV数据段（与copy的区别在于，这里的输入时stream，copy的输入是buf）
功能    	：从文件中读取Y U V数据(420格式)
引用全局变量：无
输入参数说明：pu8BufY：	        Y数据指针		out
			  pu8BufU：		    U数据指针		out
			  pu8BufV：         V数据指针		out
			  s32Width：		图像列数		in
			  s32Height：		图像行数		in
			  fp：			    文件指针		in
返回值说明  ：无
====================================================================*/
s32 KedaMctfReadImageFromYUV420(u8 *pu8BufY, u8 *pu8BufU, u8 *pu8BufV, s32 s32Width, s32 s32Height, FILE *fp)
{
	fread(pu8BufY, sizeof(u8), s32Width * s32Height, fp);
	fread(pu8BufU, sizeof(u8), s32Width * s32Height / 4, fp);
	fread(pu8BufV, sizeof(u8), s32Width * s32Height / 4, fp);

	return 0 ;
}

/*====================================================================
函数名      ：KedaMctfReadImageFromYUV422						（同上）
功能    	：从文件中读取Y U V数据(422格式)
引用全局变量：无
输入参数说明：pu8BufY：	        Y数据指针
			  pu8BufU：		    U数据指针
			  pu8BufV：         V数据指针
			  s32Width：		图像列数 
			  s32Height：		图像行数
			  fp：			    文件指针
返回值说明  ：无
====================================================================*/
s32 KedaMctfReadImageFromYUV422(u8 *pu8BufY, u8 *pu8BufU,u8 *pu8BufV, s32 s32Width, s32 s32Height, FILE *fp)
{
	fread(pu8BufY, sizeof(u8), s32Width * s32Height, fp);
	fread(pu8BufU, sizeof(u8), s32Width * s32Height / 2, fp);
	fread(pu8BufV, sizeof(u8), s32Width * s32Height / 2, fp);

	return 0;
}

/*====================================================================
函数名      ：KedaMctfReadImageFromUYVY				
功能    	：从文件中读取Y U V数据(UYVY格式)
引用全局变量：无
输入参数说明：pu8BufY：	        Y数据指针
			  pu8BufU：		    U数据指针
			  pu8BufV：         V数据指针
			  s32Width：		图像列数 
			  s32Height：		图像行数
			  fp：			    文件指针
返回值说明  ：无
====================================================================*/
s32 KedaMctfReadImageFromUYVY(u8 *pu8BufY, u8 *pu8BufU,u8 *pu8BufV, s32 s32Width, s32 s32Height, FILE *fp)
{
	u8  *pu8Image = NULL;
	s32 s32nK;
	s32 s32IndexY = 0;
	s32 s32IndexU = 0;
	s32 s32IndexV = 0;

	//allocate memory
	pu8Image = (u8 *)malloc(2 * s32Width * s32Height * sizeof(u8));
	if (NULL == pu8Image)
	{
		perror("pu8Image allocate memory failed");
		exit(1);
	}

	fread(pu8Image, sizeof(u8), 2 * s32Width * s32Height, fp);

	for (s32nK = 0; s32nK < 2 * s32Width * s32Height; s32nK++)
	{
		if (1 == s32nK % 4 || 3 == s32nK % 4)
		{
			pu8BufY[s32IndexY++] = pu8Image[s32nK];
		}

		if (0 == s32nK % 4)
		{
			pu8BufU[s32IndexU++] = pu8Image[s32nK];
		}

		if (2 == s32nK % 4)
		{
			pu8BufV[s32IndexV++] = pu8Image[s32nK];
		}
	}

	//release memory
	free(pu8Image);

	return 0;
}

/*====================================================================
函数名      ：KedaMctfWriteImageToYUV420
功能    	：将YUV420格式数据写到文件中
引用全局变量：无
输入参数说明：pu8DstY：	        Y数据指针
			  pu8DstU：		    U数据指针
			  pu8DstV：         V数据指针
			  s32Width：		图像列数 
			  s32Height：		图像行数
			  fyuv：			YUV文件指针
返回值说明  ：无
====================================================================*/
s32 KedaMctfWriteImageToYUV420(u8 *pu8DstY, u8 *pu8DstU, u8 *pu8DstV, s32 s32Width, s32 s32Height, FILE *fyuv)
{
	fwrite(pu8DstY, sizeof(u8), s32Width * s32Height, fyuv);
	fwrite(pu8DstU, sizeof(u8), s32Width * s32Height / 4, fyuv);
	fwrite(pu8DstV, sizeof(u8), s32Width * s32Height / 4, fyuv);

	return 0 ;
}

/*====================================================================
函数名      ：KedaMctfWriteImageToYUV422
功能    	：将YUV422格式数据写到文件中
引用全局变量：无
输入参数说明：pu8DstY：	        Y数据指针
			  pu8DstU：		    U数据指针
			  pu8DstV：         V数据指针
			  s32Width：		图像列数 
			  s32Height：		图像行数
			  fyuv：			YUV文件指针
返回值说明  ：无
====================================================================*/
s32 KedaMctfWriteImageToYUV422(u8 *pu8DstY, u8 *pu8DstU, u8 *pu8DstV, s32 s32Width, s32 s32Height, FILE *fyuv)
{
	fwrite(pu8DstY, sizeof(u8), s32Width * s32Height, fyuv);
	fwrite(pu8DstU, sizeof(u8), s32Width * s32Height / 2, fyuv);
	fwrite(pu8DstV, sizeof(u8), s32Width * s32Height / 2, fyuv);

	return 0 ;
}

/*====================================================================
函数名      ：KedaMctfWriteImageToUYVY
功能    	：将UYVY格式数据写到文件中
引用全局变量：无
输入参数说明：pu8DstY：	        Y数据指针
			  pu8DstU：		    U数据指针
			  pu8DstV：         V数据指针
			  s32Width：		图像列数 
			  s32Height：		图像行数
			  fyuv：			YUV文件指针
返回值说明  ：无
====================================================================*/
s32 KedaMctfWriteImageToUYVY(u8 *pu8DstY, u8 *pu8DstU, u8 *pu8DstV, s32 s32Width, s32 s32Height, FILE *fyuv)
{
	u8  *pu8Image = NULL;
	s32 s32nK;
	s32 s32IndexY = 0;
	s32 s32IndexU = 0;
	s32 s32IndexV = 0;

	//allocate memory
	pu8Image = (u8 *)malloc(2 * s32Width * s32Height * sizeof(u8));
	if (NULL == pu8Image)
	{
		perror("pu8Image allocate memory failed");
		exit(1);
	}


	for (s32nK = 0; s32nK < 2 * s32Width * s32Height; s32nK++)
	{
		if (1 == s32nK % 4 || 3 == s32nK % 4)
		{
			pu8Image[s32nK] = pu8DstY[s32IndexY++];
		}

		if (0 == s32nK % 4)
		{
			pu8Image[s32nK] = pu8DstU[s32IndexU++];
		}

		if (2 == s32nK % 4)
		{
			pu8Image[s32nK] = pu8DstV[s32IndexV++];
		}
	}

	fwrite(pu8Image, sizeof(u8), 2 * s32Width * s32Height, fyuv);

	//release memory
	free(pu8Image);

	return 0;
}

/*====================================================================
函数名      ：KedaMotionEstimation
功能    	：运动估计
引用全局变量：无
输入参数说明：pu8BufYC：	        当前帧Y数据指针
			  pu8BufYPiir：		    上一帧滤波结果Y数据指针
			  pu8BufUC44：          当前帧U数据指针
			  pu8BufUPiir44：	    上一帧滤波结果U数据指针 
			  pu8BufVC44：		    当前帧V数据指针
			  pu8BufVPiir44：       上一帧滤波结果V数据指针
			  ps32SadBuf：			存放SAD数据指针
			  s32WSrc：				图像宽
			  s32HSrc：				图像高
			  ptMV：		        运动矢量指针
返回值说明  ：无
====================================================================*/
s32 KedaMotionEstimation(u8 *pu8BufYC, u8 *pu8BufYPiir,      /* Y */
					     u8 *pu8BufUC44, u8 *pu8BufUPiir44,  /* U */
					     u8 *pu8BufVC44, u8 *pu8BufVPiir44,  /* V */
					     s32 *ps32SadBuf, s32 s32WSrc, s32 s32HSrc, TMV *ptMV)
{
	s32 s32WbSrc;
	s32 s32nI, s32nJ, s32nW, s32nH, s32JJ, s32WW, s32PI, s32PJ, s32CJ;
	s32 s32MVx, s32MVy, s32Sad, s32MinSad;
	s32 s32RefCur = 0, s32RefMatch = 0;

	s32WbSrc = s32WSrc / 3 + ((s32WSrc % 3) != 0);

	// ======== filter process
	for (s32nI = 0; s32nI < s32HSrc; s32nI++)  // for each line, 2 lines are generated
	{
		for (s32nJ = 0; s32nJ < s32WbSrc; s32nJ++)  // for each block
		{
			s32MinSad = 10240;
			s32JJ = s32nJ * 3;
			s32MVx = 0;
			s32MVy = 0;

			for (s32nH = -2; s32nH <= 2; s32nH++)
			{
				for (s32nW = -3; s32nW <= 3; s32nW++)
				{
					// find each 3x1 sad
					s32Sad = 0;  //11 bit
					for (s32WW = 0; s32WW < 3; s32WW++)
					{
						s32PI = s32nI + s32nH;
						s32PJ = s32JJ + s32nW + s32WW;
						if (s32PI >= s32HSrc) s32PI = s32HSrc - 1;
						if (s32PI < 0) s32PI = 0;
						if (s32PJ < 0) s32PJ = 0;
						if (s32PJ >= s32WSrc) s32PJ = s32WSrc - 1;

						s32CJ = s32JJ + s32WW;
						if (s32CJ >= s32WSrc) s32CJ = s32WSrc - 1;

						if (((s32nI * s32WSrc + s32CJ) >= (s32HSrc * s32WSrc)) || ((s32PI * s32WSrc + s32PJ) >= (s32HSrc * s32WSrc)))
						{
							printf("error\n");
							exit(-1);
						}
						s32Sad += (s32)(abs(pu8BufYC[s32nI * s32WSrc + s32CJ] - pu8BufYPiir[s32PI * s32WSrc + s32PJ]) * 2    /* Y */
									 + (abs(pu8BufUC44[s32nI * s32WSrc + s32CJ] - pu8BufUPiir44[s32PI * s32WSrc + s32PJ]))   /* U */
									 + (abs(pu8BufVC44[s32nI * s32WSrc + s32CJ] - pu8BufVPiir44[s32PI * s32WSrc + s32PJ]))); /* V */

					}

					//fixed-2013-10-22-15:29-xc
					if (s32Sad < s32MinSad)
					{
						s32MinSad = s32Sad;
						s32MVx = s32nW;
						s32MVy = s32nH;
					}
					else if (s32Sad == s32MinSad)  //equal
					{
						s32MinSad = s32Sad;
						s32RefCur = (s32JJ - (s32JJ + s32nW))*(s32JJ - (s32JJ + s32nW)) + (s32nI - (s32nI + s32nH))*(s32nI - (s32nI + s32nH));
						s32RefMatch = (s32JJ - (s32JJ + s32MVx))*(s32JJ - (s32JJ + s32MVx)) + (s32nI - (s32nI + s32MVy))*(s32nI - (s32nI + s32MVy));
						if (s32RefCur < s32RefMatch)
						{
							s32MVx = s32nW;
							s32MVy = s32nH;
						}
					}
				}
			}

			ptMV[s32nI * s32WbSrc + s32nJ].s32MVx = s32MVx;
			ptMV[s32nI * s32WbSrc + s32nJ].s32MVy = s32MVy;
			
			ps32SadBuf[s32nI * s32WbSrc + s32nJ] = s32MinSad;
		}
	}

	return 0;
}


/*====================================================================
函数名      ：KedaMotionCompensation
功能    	：运动补偿
引用全局变量：无
输入参数说明：pu8BufYC：	        当前帧Y数据指针
			  pu8BufYPiir：		    上一帧滤波结果Y数据指针
			  pu8BufYP:				上一帧Y数据指针
			  pu8BufUC44：          当前帧U数据指针
			  pu8BufUPiir44：	    上一帧滤波结果U数据指针 
			  pu8BufUP44：			上一帧U数据指针
			  pu8BufVC44：		    当前帧V数据指针
			  pu8BufVPiir44：       上一帧滤波结果V数据指针
			  pu8BufVP44：			上一帧V数据指针
			  s32WSrc：				图像宽
			  s32HSrc：				图像高
			  ptMV：		        运动矢量指针
			  pu8BufYPiirComp:      运动补偿之后上一帧去噪结果Y数据
			  pu8BufUPiirComp44:    运动补偿之后上一帧去噪结果U数据
			  pu8BufVPiirComp44:    运动补偿之后上一帧去噪结果V数据
			  s32DiffAfter:         当前帧和上一帧补偿之后的去噪结果SAD差值指针
			  s32DiffBefore:        当前帧和上一帧SAD差值指针
返回值说明  ：无
====================================================================*/
s32 KedaMotionCompensation(u8 *pu8BufYPiir, u8 *pu8BufYP, u8 *pu8BufYC,        /* Y */
						   u8 *pu8BufUPiir44, u8 *pu8BufUP44, u8 *pu8BufUC44,  /* U */
						   u8 *pu8BufVPiir44, u8 *pu8BufVP44, u8 *pu8BufVC44,  /* V */
						   s32 s32WSrc, s32 s32HSrc, TMV *ptMV,
			 			   u8 *pu8BufYPiirComp, u8 *pu8BufUPiirComp44, u8 *pu8BufVPiirComp44,
						   s32 *ps32DiffAfter, s32 *ps32DiffBefore)
{
	s32 s32WbSrc;
	s32 s32nI, s32nJ, s32PI, s32PJ, s32BJ;
	s32 s32MVx, s32MVy;
	s32 s32CprH = 0, s32CprW = 0, s32AbsSub = 0, s32SumAbsSub = 0;
	s32 s32Tw = 0, s32Th = 0;
	s32 s32LocW = 0, s32LocH = 0;
	s32 s32BeforeAbsSub = 0, s32BeforeSumAbsSub = 0;

	//set
	s32WbSrc = s32WSrc / 3 + ((s32WSrc % 3) != 0);

	s32LocW = 3;
	s32LocH = 1;

	// ======== filter process
	for (s32nI = 0; s32nI < s32HSrc; s32nI++)  // for each line, 2 lines are generated
	{
		for (s32nJ = 0; s32nJ < s32WSrc; s32nJ++)  // for each block
		{
			s32BJ = s32nJ / 3;
			s32MVx = ptMV[s32nI * s32WbSrc + s32BJ].s32MVx;
			s32MVy = ptMV[s32nI * s32WbSrc + s32BJ].s32MVy;

			//fixed-2013-10-22-13:08-xc
			s32PI = s32nI + s32MVy;
			s32PJ = s32nJ + s32MVx;

			if (s32PI < 0) s32PI = 0;
			if (s32PJ < 0) s32PJ = 0;
			if (s32PI >= s32HSrc) s32PI = s32HSrc - 1;
			if (s32PJ >= s32WSrc) s32PJ = s32WSrc - 1;

			//yuv compensation
			pu8BufYPiirComp[s32nI * s32WSrc + s32nJ] = pu8BufYPiir[s32PI * s32WSrc + s32PJ];
			pu8BufUPiirComp44[s32nI * s32WSrc + s32nJ] = pu8BufUPiir44[s32PI * s32WSrc + s32PJ];
			pu8BufVPiirComp44[s32nI * s32WSrc + s32nJ] = pu8BufVPiir44[s32PI * s32WSrc + s32PJ];
		}
	}

	//diff
	for (s32nI = 0; s32nI < s32HSrc; s32nI++)
	{
		for (s32nJ = 0; s32nJ < s32WSrc; s32nJ++)
		{
			//current frame vs after motion compensation frame
			s32SumAbsSub = 0;  //14 bit
			s32BeforeSumAbsSub = 0;  //14 bit
			for (s32CprH = -s32LocH; s32CprH <= s32LocH; s32CprH++)
			{
				s32Th = s32nI + s32CprH;
				if (s32Th < 0)
				{
					s32Th = 0;
				}
				if (s32Th > s32HSrc - 1)
				{
					s32Th = s32HSrc - 1;
				}

				for (s32CprW = -s32LocW; s32CprW <= s32LocW; s32CprW++)
				{
					s32Tw = s32nJ + s32CprW;
					if (s32Tw < 0)
					{
						s32Tw = 0;
					}
					if (s32Tw > s32WSrc - 1)
					{
						s32Tw = s32WSrc - 1;
					}

					//yuv after compensation
					s32AbsSub = (s32)(abs(pu8BufYC[s32Th * s32WSrc + s32Tw] - pu8BufYPiirComp[s32Th * s32WSrc + s32Tw])  
									+ (abs(pu8BufUC44[s32Th * s32WSrc + s32Tw] - pu8BufUPiirComp44[s32Th * s32WSrc + s32Tw]) >> 1)
									+ (abs(pu8BufVC44[s32Th * s32WSrc + s32Tw] - pu8BufVPiirComp44[s32Th * s32WSrc + s32Tw]) >> 1));
					s32SumAbsSub += s32AbsSub;

					//yuv before compensation
					s32BeforeAbsSub = (s32)(abs(pu8BufYC[s32Th * s32WSrc + s32Tw] - pu8BufYP[s32Th * s32WSrc + s32Tw]) 
										   + (abs(pu8BufUC44[s32Th * s32WSrc + s32Tw] - pu8BufUP44[s32Th * s32WSrc + s32Tw]) >> 1)
										   + (abs(pu8BufVC44[s32Th * s32WSrc + s32Tw] - pu8BufVP44[s32Th * s32WSrc + s32Tw]) >> 1));
					s32BeforeSumAbsSub += s32BeforeAbsSub;
				}
			}

			ps32DiffAfter[s32nI * s32WSrc + s32nJ] = s32SumAbsSub;
			ps32DiffBefore[s32nI * s32WSrc + s32nJ] = s32BeforeSumAbsSub;
		}
	}

	return 0;
}

/*====================================================================
函数名      ：KedaYChnlMean
功能    	：计算图像平均亮度
引用全局变量：无
输入参数说明：pu8BufY：	            当前帧Y数据指针
			  s32Width：		    图像宽
			  s32Height：			图像高
返回值说明  ：u8YMean:				图像平均亮度
====================================================================*/
u8 KedaYChnlMean(u8 *pu8BufY, s32 s32Width, s32 s32Height)
{
	s32 s32nW, s32nH;
	s32 s32AccY = 0;
	u8  u8YMean= 0;

	for (s32nH = 0; s32nH < s32Height; s32nH++)
	{
		for (s32nW = 0; s32nW < s32Width; s32nW++)
		{
			s32AccY += pu8BufY[s32nH * s32Width + s32nW];
		}
	}

	u8YMean = (u8)(s32AccY / (s32Width * s32Height)); 

	return u8YMean;
}

/*====================================================================
函数名      ：KedaGetAlphaInt
功能    	：定点化
引用全局变量：无
输入参数说明：f32Alphaiir：	        输入滤波系数
返回值说明  ：s32LocAlphaiir	    定点化之后的滤波系数
====================================================================*/
s32 KedaGetAlphaInt(f32 f32Alphaiir)
{
	s32 s32Precis = 16384;
	f32 f32FracBit = 4.0f;
	f32 f32TAlpha = 0.0f;
	s32 s32LocAlphaiir = 0;
	s32 s32ConstVal = 0;

	s32ConstVal = (s32)(pow(10.0f, f32FracBit));
	s32LocAlphaiir = (s32)(f32Alphaiir * s32ConstVal);
	f32TAlpha = (f32)(s32LocAlphaiir) / (f32)(s32ConstVal);
	s32LocAlphaiir = (s32)(f32TAlpha * s32Precis);

	return s32LocAlphaiir;
}

/*====================================================================
函数名      ：KedaAlphaLUT
功能    	：根据运动强度计算滤波系数
引用全局变量：无
输入参数说明：f64Mot：	            运动强度
			  f64CVal：             预设参数
返回值说明  ：u64AlphaiirInt	    滤波系数
====================================================================*/
u64 KedaAlphaLUT(f64 f64Mot, f64 f64CVal)
{
	f32 f32Alphaiir = 0;
	u64 u64AlphaiirInt = 0;

	if (f64Mot >= 16384)
	{
		u64AlphaiirInt = 16384;
	}
	else
	{
		f32Alphaiir = (f32)((f64)(f64Mot * f64Mot * f64Mot) / (f64)(f64Mot * f64Mot * f64Mot + f64CVal * f64CVal * f64CVal));
		u64AlphaiirInt = KedaGetAlphaInt(f32Alphaiir);
	}

	return u64AlphaiirInt;
}

/*====================================================================
函数名      ：KedaMakeFactorInt
功能    	：定点化降噪强度
引用全局变量：无
输入参数说明：f32Factor：	    降噪强度
返回值说明  ：s32LocFactor	    定点化之后的降噪强度
====================================================================*/
s32 KedaMakeFactorInt(f32 f32Factor)
{
	s32 s32Precis = 256;
	s32 s32LocFactor = 0;
	s32 s32ConstVal = 0;
	f32 f32FracBit = 2.0f;
	f32 f32FlFactor = 0.0f;

	s32ConstVal = (s32)(pow(10.0f, f32FracBit));
	f32FlFactor = 1.0f / f32Factor;
	s32LocFactor = (s32)(f32FlFactor * s32ConstVal);
	f32FlFactor = (f32)(s32LocFactor) / (f32)(s32ConstVal);
	s32LocFactor = (s32)(f32FlFactor * s32Precis);

	return s32LocFactor;
}

/*====================================================================
函数名      ：KedaMctfDenoising
功能    	：3d降噪
引用全局变量：无
输入参数说明：pu8BufYC：	     当前帧Y数据指针    
			  pu8BufYPiir：		 上一帧去噪结果Y数据指针
			  pu8BufYP：		 上一帧Y数据指针
			  pu8BufYOut:        当前帧Y数据输出指针
			  pu8BufUC:          当前帧U数据指针
			  pu8BufUPiir:       上一帧去噪结果U数据指针
			  pu8BufUP:          上一帧U数据指针
			  pu8BufUOut:        当前帧U数据输出指针
			  pu8BufVC:          当前帧V数据指针
			  pu8BufVPiir:       上一帧去噪结果V数据指针
			  pu8BufVP:          上一帧V数据指针
			  f32Factor:		 降噪系数
			  s32YMean:          图像亮度均值
返回值说明  ：无
====================================================================*/
s32 KedaMctfDenoising(u8 *pu8BufYC, u8 *pu8BufYPiir, u8 *pu8BufYP, u8 *pu8BufYOut,  /* Y */
					  u8 *pu8BufUC, u8 *pu8BufUPiir, u8 *pu8BufUP, u8 *pu8BufUOut,  /* U */
					  u8 *pu8BufVC, u8 *pu8BufVPiir, u8 *pu8BufVP, u8 *pu8BufVOut,  /* V */
					  s32 s32Width,s32 s32Height, TMctfDenoise *ptMctfDenoise, s32 s32YMean)
{
	TMV *ptMV;
	u8  u8YPxlVal = 0;
	s32 s32nI, s32nJ, s32nH, s32nW, s32WbSrc;
	s32 s32Yc, s32YPiir, s32Outiir, s32Uc, s32UPiir, s32Vc, s32VPiir;
	s32 *ps32DiffAfter, *ps32DiffBefore, *ps32SadBuf;
	s32 s32LowTh, s32NewLowTh, s32HighTh, s32DeltaLowTh;
	s32 s32MotAfter, s32MotBefore, s32FactorInt, s32YMeanRatioInt, s32Delta;
	f32 f32CLow, f32CHigh, f32NewCLow, f32CVal;
	f32 f32Factor, f32DeltaCLow, f32DeltaCHigh;
	u64 u64AlphaiirInt = 0;
	u8  *pu8BufUC44, *pu8BufUP44, *pu8BufUPiir44, *pu8BufUOut44;
	u8  *pu8BufVC44, *pu8BufVP44, *pu8BufVPiir44, *pu8BufVOut44;
	u8  *pu8BufYPiirComp, *pu8BufUPiirComp44, *pu8BufVPiirComp44;

	//init param
	f32Factor = 256.0 / (f32)ptMctfDenoise->s32MctfDenoiseLevel;

	s32WbSrc = s32Width / 3 + ((s32Width % 3) != 0);
	s32FactorInt = KedaMakeFactorInt(f32Factor);

	//allocate memory
	ptMV = (TMV *)malloc(s32Height * s32WbSrc * sizeof(TMV));
	ps32DiffAfter = (s32 *)malloc(s32Height * s32Width * sizeof(s32));
	ps32DiffBefore = (s32 *)malloc(s32Height * s32Width * sizeof(s32));
	ps32SadBuf = (s32 *)malloc(s32Height * s32WbSrc * sizeof(s32));

	pu8BufUC44 = (u8 *)malloc(s32Width * s32Height * sizeof(u8));
	pu8BufVC44 = (u8 *)malloc(s32Width * s32Height * sizeof(u8));

	pu8BufUP44 = (u8 *)malloc(s32Width * s32Height * sizeof(u8));
	pu8BufVP44 = (u8 *)malloc(s32Width * s32Height * sizeof(u8));

	pu8BufUPiir44 = (u8 *)malloc(s32Width * s32Height * sizeof(u8));
	pu8BufVPiir44 = (u8 *)malloc(s32Width * s32Height * sizeof(u8));

	pu8BufUOut44 = (u8 *)malloc(s32Width * s32Height * sizeof(u8));
	pu8BufVOut44 = (u8 *)malloc(s32Width * s32Height * sizeof(u8));

	pu8BufYPiirComp = (u8 *)malloc(s32Width * s32Height * sizeof(u8));
	pu8BufUPiirComp44 = (u8 *)malloc(s32Width * s32Height * sizeof(u8));
	pu8BufVPiirComp44 = (u8 *)malloc(s32Width * s32Height * sizeof(u8));

	//uv 22 to uv44
	for (s32nH = 0; s32nH < s32Height; s32nH++)
	{
		for (s32nW = 0; s32nW < s32Width; s32nW++)
		{
			pu8BufUC44[s32nH * s32Width + s32nW] = pu8BufUC[s32nH * s32Width / 2 + s32nW / 2];
			pu8BufVC44[s32nH * s32Width + s32nW] = pu8BufVC[s32nH * s32Width / 2 + s32nW / 2];

			pu8BufUP44[s32nH * s32Width + s32nW] = pu8BufUP[s32nH * s32Width / 2 + s32nW / 2];
			pu8BufVP44[s32nH * s32Width + s32nW] = pu8BufVP[s32nH * s32Width / 2 + s32nW / 2];

			pu8BufUPiir44[s32nH * s32Width + s32nW] = pu8BufUPiir[s32nH * s32Width / 2 + s32nW / 2];
			pu8BufVPiir44[s32nH * s32Width + s32nW] = pu8BufVPiir[s32nH * s32Width / 2 + s32nW / 2];
		}
	}

	//motion estimation
	KedaMotionEstimation(pu8BufYC, pu8BufYPiir,     
					     pu8BufUC44, pu8BufUPiir44, 
					     pu8BufVC44, pu8BufVPiir44,
					     ps32SadBuf, s32Width, s32Height, ptMV);

	//motion compensation
	KedaMotionCompensation(pu8BufYPiir,    pu8BufYP,    pu8BufYC,     
						   pu8BufUPiir44, pu8BufUP44, pu8BufUC44,  
						   pu8BufVPiir44, pu8BufVP44, pu8BufVC44,   
						   s32Width, s32Height, ptMV,
						   pu8BufYPiirComp, pu8BufUPiirComp44, pu8BufVPiirComp44,
						   ps32DiffAfter, ps32DiffBefore);

	s32NewLowTh = 50;
	s32LowTh = 100;  
	s32HighTh = 300;
	f32NewCLow = 50.0f;  
	f32CLow = 100.0f;  
	f32CHigh = 100.0f;  
	s32DeltaLowTh = 20;
	f32DeltaCLow = 110.0f;
	f32DeltaCHigh = 80.0f; 

	// ======== filter process
	for (s32nI = 0; s32nI < s32Height; s32nI++)  // for each line, 2 lines are generated
	{
		for (s32nJ = 0; s32nJ < s32Width; s32nJ++)  // for each pix
		{
			//current frame y value
			u8YPxlVal = pu8BufYC[s32nI * s32Width + s32nJ];

			s32MotAfter = ps32DiffAfter[s32nI * s32Width + s32nJ];
			s32MotBefore = ps32DiffBefore[s32nI * s32Width + s32nJ];

			s32Delta = ps32DiffBefore[s32nI * s32Width + s32nJ] - ps32DiffAfter[s32nI * s32Width + s32nJ];

			//scaling for mot_after
			if (s32MotAfter < f32Factor)
			{
				s32MotAfter = s32MotAfter;
			}
			else
			{
				s32MotAfter = s32MotAfter * s32FactorInt / 256; 
			}

			//alpha_iir
			if (s32MotAfter < s32NewLowTh)
			{
				f32CVal = f32NewCLow;
			}
			else if (s32MotAfter >= s32NewLowTh && s32MotAfter < s32LowTh)
			{
				f32CVal = f32CLow;  //condition 1:

				if (s32Delta >= s32DeltaLowTh) //condition 2:
				{
					s32YMeanRatioInt = (204 * s32YMean) >> 8;
					if (u8YPxlVal >(u8)(s32YMeanRatioInt))
					{
						f32CVal = f32DeltaCLow;
					}
				}
			}
			else if (s32MotAfter >= s32LowTh && s32MotAfter < s32HighTh) 
			{
				f32CVal = f32CHigh;  //condition 3:

				s32YMeanRatioInt = (204 * s32YMean) >> 8;
				if ((u8YPxlVal >(u8)(s32YMeanRatioInt)))  //condition 4:
				{
					f32CVal = f32DeltaCHigh;
				}
			}
			else //condition 5:
			{
				f32CVal = 0.0f;
				s32MotAfter = 1;
			}

			//calculating alpha_iir using look-up table
			u64AlphaiirInt = KedaAlphaLUT(s32MotAfter, f32CVal);

			/*==== y ====*/
			s32Yc = pu8BufYC[s32nI * s32Width + s32nJ];
			s32YPiir = (pu8BufYPiir[s32nI * s32Width + s32nJ] + pu8BufYPiirComp[s32nI * s32Width + s32nJ]) >> 1;
			s32Outiir = (s32)((u64AlphaiirInt * s32Yc + (16384 - u64AlphaiirInt) * s32YPiir) / 16384);
			s32Outiir = CLIP8(s32Outiir);
			pu8BufYPiir[s32nI * s32Width + s32nJ] = (u8)(s32Outiir);
			pu8BufYOut[s32nI * s32Width + s32nJ] = (u8)(s32Outiir); 

			/*==== u ====*/
			s32Uc = pu8BufUC44[s32nI * s32Width + s32nJ];
			s32UPiir = pu8BufUPiirComp44[s32nI * s32Width + s32nJ];
			s32Outiir = (s32)((u64AlphaiirInt * s32Uc + (16384 - u64AlphaiirInt) * s32UPiir) / 16384);
			s32Outiir = CLIP8(s32Outiir);
			pu8BufUPiir44[s32nI * s32Width + s32nJ] = (u8)(s32Outiir);
			pu8BufUOut44[s32nI * s32Width + s32nJ] = (u8)(s32Outiir); 

			/*==== v ====*/
			s32Vc = pu8BufVC44[s32nI * s32Width + s32nJ];
			s32VPiir = pu8BufVPiirComp44[s32nI * s32Width + s32nJ];
			s32Outiir = (s32)((u64AlphaiirInt * s32Vc + (16384 - u64AlphaiirInt) * s32VPiir) / 16384);
			s32Outiir = CLIP8(s32Outiir);
			pu8BufVPiir44[s32nI * s32Width + s32nJ] = (u8)(s32Outiir);
			pu8BufVOut44[s32nI * s32Width + s32nJ] = (u8)(s32Outiir); 
		}	
	}

	//uv44 to uv22
	for (s32nH = 0; s32nH < s32Height; s32nH++)
	{
		for (s32nW = 0; s32nW < s32Width; s32nW++)
		{
			pu8BufUOut[s32nH * s32Width / 2 + s32nW / 2] = pu8BufUOut44[s32nH * s32Width + s32nW];
			pu8BufVOut[s32nH * s32Width / 2 + s32nW / 2] = pu8BufVOut44[s32nH * s32Width + s32nW];
			pu8BufUPiir[s32nH * s32Width / 2 + s32nW / 2] = pu8BufUPiir44[s32nH * s32Width + s32nW];
			pu8BufVPiir[s32nH * s32Width / 2 + s32nW / 2] = pu8BufVPiir44[s32nH * s32Width + s32nW];
		}
	}

	
	//release memory
	free(pu8BufUC44);
	free(pu8BufVC44);
	free(pu8BufUP44);
	free(pu8BufVP44);
	free(pu8BufUPiir44);
	free(pu8BufVPiir44);
	free(pu8BufUOut44);
	free(pu8BufVOut44);
	free(pu8BufYPiirComp);
	free(pu8BufUPiirComp44);
	free(pu8BufVPiirComp44);
	free(ptMV);
	free(ps32DiffAfter);
	free(ps32DiffBefore);
	free(ps32SadBuf);

	return 0;
}

