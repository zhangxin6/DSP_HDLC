//#include <stdio.h>
//#include <fstream>


//union CHARTOFLOAT
//	{
//		float d1;
//		unsigned char d2[4];
//	};
//	union CHARTOFLOAT d;

//////////5ms
// 1 ֡��
//unsigned int rti;
// 32 ��̬��thetar
//float thetar;
// 33 ��̬�� psir
//float psir;
// 34 ��̬��gammar
//float gammar;

////////15ms
/////////��һ��15ms����
//1 ��֡ͬ����
//unsigned int Head15;
//24 ��������ctax1
//float ctax1;
//25 ��������ctay1
//float ctay1;
//26 ��������ctaz1
//float ctaz1;
//27 ������߸ߵͽ�2(�ɼ���
//loat deltaqepsilon;
//28 ������߷�λ��2���ɼ���
//float deltaqbeta;
//29 ������߸ߵͽ�2(���⣩
//float Hdeltaqepsilon;
//30 ������߷�λ��2�����⣩
//float Hdeltaqbeta;


/////////�ڶ���15ms����
//1 ��Ŀ����rour
//float rour;
//17 ���߽�2(�ɼ��ߵͣ�qepsilon
//float qepsilon;
//18 ���߽�2(�ɼ���λ��qbeta
//float qbeta;
//19 ���߽�2(�ɼ��ߵͣ�Hqepsilon
//float Hqepsilon;
//20 ���߽�2(�ɼ���λ��Hqbeta
//float Hqbeta;
//23 ����ת��1(����ߵͣ�dHqepsilonj
//float dHqepsilonj;
//24 ����ת��1(���ⷽλ��dHqbetaj
//float dHqbetaj;
//49 ����ת��(�ɼ��ߵͣ�dqepsilonj
//float dqepsilonj;
//50 ����ת��(�ɼ���λ��dqbetaj
//float dqbetaj;

////////������15ms
//24 ����ͼ�񱳾���׼��Hsigma
//float Hsigma;
//27 ��ʱʱ��tgg(0.1ms)
//unsigned int tgg;
//29 ����TG
//unsigned int  TG;
//40 ����ͼ�񱳾���ֵHmean
//unsigned int  Hmean;
//43 �ɼ�֡��frameno
//unsigned int frameno;
//44 ����֡��Hframeno
//unsigned int Hframeno;
int Flag15=0;

int zhuanfa(int * dst_buf,int * src_buf)
{
	//FILE *f=fopen("20170922_0001.txt","r");

	//��ʼ��
	//rti=0;
	//thetar=0;
	//psir=0;
	//gammar=0;
	//Head15=0;
	//ctax1=0;
	//ctay1=0;
	//ctaz1=0;
	//deltaqepsilon=0;
	//deltaqbeta=0;
	//Hdeltaqepsilon=0;
	//Hdeltaqbeta=0;
	//rour=0;
	//qepsilon=0;
	//qbeta=0;
	//Hqepsilon=0;
	//Hqbeta=0;
	//dHqepsilonj=0;
	//dHqbetaj=0;
	//dqepsilonj=0;
	//dqbetaj=0;
	//Hsigma=0;
	//tgg=0;
	//TG=0;
	//Hmean=0;
	//frameno=0;
	//Hframeno=0;
	//��������
	//FILE *fid5=fopen("20170919_0003_5ms.txt","w+");
	//fprintf(fid5,"%s	%s	%s	%s\n","1 ֡��","32 ��̬��thetar","33 ��̬�� psir","34 ��̬��gammar");

	//FILE *fid15_1=fopen("20170919_0003_15ms_1.txt","w+");
	//fprintf(fid15_1,"%s	%s	%s	%s	%s	%s	%s	%s\n","1 ��֡ͬ����","24 ��������ctax1","25 ��������ctay1","26 ��������ctaz1",
	//	"27 ������߸ߵͽ�2(�ɼ���","28 ������߷�λ��2���ɼ���","29 ������߸ߵͽ�2(���⣩","30 ������߷�λ��2�����⣩");
	//FILE *fid15_2=fopen("20170919_0003_15ms_2.txt","w+");
	//fprintf(fid15_2,"%s	%s	%s	%s	%s	%s	%s	%s	%s\n","1 ��Ŀ����","17 ���߽�2(�ɼ��ߵͣ�","18 ���߽�2(�ɼ���λ��","19 ���߽�2(�ɼ��ߵͣ�",
	//	"20 ���߽�2(�ɼ���λ��","23 ����ת��1(����ߵͣ�","24 ����ת��1(���ⷽλ��","49 ����ת��(�ɼ��ߵͣ�","50 ����ת��(�ɼ���λ��");
	//FILE *fid15_3=fopen("20170919_0003_15ms_3.txt","w+");
	//fprintf(fid15_3,"%s	%s	%s	%s	%s	%s\n","24 ����ͼ�񱳾���׼��","27 ��ʱʱ��(0.1ms)","29 ����TG","40 ����ͼ�񱳾���ֵ",
	//	"43 �ɼ�֡��","44 ����֡��");

	//for (int zii=0;zii<2000;zii++)
	//{
		
		//����
		//for(int i=0;i<466;i++)
		//	data[i]=0;
		//for(int i=0;i<466;i++)
		//	fscanf(f,"%x",&data[i]);

		//��·5ms����
		int Tdata5[198];
		int Tdata15[250];
		int Flag_out;
		int i;
		
		for(i=0;i<198;i++)
			Tdata5[i]=0;
		for(i=0;i<250;i++)
			Tdata15[i]= 0;
		
		if (dst_buf[1]==34)
		{
			for(i=0;i<198;i++)
				Tdata5[i]=dst_buf[i+2];

			/*d.d2[3]=TelData[2+8];
			d.d2[2]=TelData[2+9];
			d.d2[1]=TelData[2+10];
			d.d2[0]=TelData[2+11];
			float q=d.d1*/

			// 1 ֡��
			//rti=(Tdata5[0]<<24)+(Tdata5[1]<<16)+(Tdata5[2]<<8)+Tdata5[3];
			src_buf[6]=Tdata5[0];
			src_buf[7]=Tdata5[1];
			src_buf[8]=Tdata5[2];
			src_buf[9]=Tdata5[3];
			// 32 ��̬��thetar
			//d.d2[3]=Tdata5[124];
			//d.d2[2]=Tdata5[125];
			//d.d2[1]=Tdata5[126];
			//d.d2[0]=Tdata5[127];
			//thetar=d.d1;
			src_buf[10]=Tdata5[124];
			src_buf[11]=Tdata5[125];
			src_buf[12]=Tdata5[126];
			src_buf[13]=Tdata5[127];

			// 33 ��̬�� psir
			//d.d2[3]=Tdata5[128];
			//d.d2[2]=Tdata5[129];
			//d.d2[1]=Tdata5[130];
			//d.d2[0]=Tdata5[131];
			//psir=d.d1;
			src_buf[14]=Tdata5[128];
			src_buf[15]=Tdata5[129];
			src_buf[16]=Tdata5[130];
			src_buf[17]=Tdata5[131];
			// 34 ��̬��gammar
			//d.d2[3]=Tdata5[132];
			//d.d2[2]=Tdata5[133];
			//d.d2[1]=Tdata5[134];
			//d.d2[0]=Tdata5[135];
			//gammar=d.d1;
			src_buf[18]=Tdata5[132];
			src_buf[19]=Tdata5[133];
			src_buf[20]=Tdata5[134];
			src_buf[21]=Tdata5[135];
			//���
			//fprintf(fid5,"%u	%f	%f	%f\n",rti,thetar,psir,gammar);

			//15ms���ݽ���
			for(i=0;i<250;i++)
				Tdata15[i]=dst_buf[i+2+198];
			if (Tdata15[0]==0x65&&Tdata15[1]==0x43&&Tdata15[2]==0x4A&&Tdata15[3]==0xD3)			
				Flag15=1;
			if (Flag15==1)
			{
				src_buf[0]=0x77;
				src_buf[1]=0x22;
				/////////��һ��15ms����
				//1 ��֡ͬ����
				//Head15=(Tdata15[0]<<24)+(Tdata15[1]<<16)+(Tdata15[2]<<8)+Tdata15[3];
				
				src_buf[2]=Tdata15[0];
				src_buf[3]=Tdata15[1];
				src_buf[4]=Tdata15[2];
				src_buf[5]=Tdata15[3];

				//24 ��������ctax1
				//d.d2[3]=Tdata15[92];
				//d.d2[2]=Tdata15[93];
				//d.d2[1]=Tdata15[94];
				//d.d2[0]=Tdata15[95];
				//ctax1=d.d1;
				src_buf[22]=Tdata15[92];
				src_buf[23]=Tdata15[93];
				src_buf[24]=Tdata15[94];
				src_buf[25]=Tdata15[95];
				//25 ��������ctay1
				//d.d2[3]=Tdata15[96];
				//d.d2[2]=Tdata15[97];
				//d.d2[1]=Tdata15[98];
				//d.d2[0]=Tdata15[99];
				//ctay1=d.d1;
				src_buf[26]=Tdata15[96];
				src_buf[27]=Tdata15[97];
				src_buf[28]=Tdata15[98];
				src_buf[29]=Tdata15[99];
				//26 ��������ctaz1
				//d.d2[3]=Tdata15[100];
				//d.d2[2]=Tdata15[101];
				//d.d2[1]=Tdata15[102];
				//d.d2[0]=Tdata15[103];
				//ctaz1=d.d1;
				src_buf[30]=Tdata15[100];
				src_buf[31]=Tdata15[101];
				src_buf[32]=Tdata15[102];
				src_buf[33]=Tdata15[103];
				//27 ������߸ߵͽ�2(�ɼ���deltaqepsilon
				//d.d2[3]=Tdata15[104];
				//d.d2[2]=Tdata15[105];
				//d.d2[1]=Tdata15[106];
				//d.d2[0]=Tdata15[107];				
				//deltaqepsilon=d.d1;
				src_buf[34]=Tdata15[104];
				src_buf[35]=Tdata15[105];
				src_buf[36]=Tdata15[106];
				src_buf[37]=Tdata15[107];
				//28 ������߷�λ��2���ɼ���deltaqbeta
				//d.d2[3]=Tdata15[108];
				//d.d2[2]=Tdata15[109];
				//d.d2[1]=Tdata15[110];
				//d.d2[0]=Tdata15[111];					
				//deltaqbeta=d.d1;
				src_buf[38]=Tdata15[108];
				src_buf[39]=Tdata15[109];
				src_buf[40]=Tdata15[110];
				src_buf[41]=Tdata15[111];
				//29 ������߸ߵͽ�2(���⣩
				//d.d2[3]=Tdata15[112];
				//d.d2[2]=Tdata15[113];
				//d.d2[1]=Tdata15[114];
				//d.d2[0]=Tdata15[115];	
				//Hdeltaqepsilon=d.d1;
				src_buf[42]=Tdata15[112];
				src_buf[43]=Tdata15[113];
				src_buf[44]=Tdata15[114];
				src_buf[45]=Tdata15[115];
				//30 ������߷�λ��2�����⣩
				//d.d2[3]=Tdata15[116];
				//d.d2[2]=Tdata15[117];
				//d.d2[1]=Tdata15[118];
				//d.d2[0]=Tdata15[119];
				//Hdeltaqbeta=d.d1;
				src_buf[46]=Tdata15[116];
				src_buf[47]=Tdata15[117];
				src_buf[48]=Tdata15[118];
				src_buf[49]=Tdata15[119];

				Flag15=2;

				//���
				//fprintf(fid15_1,"%u	%f	%f	%f	%f	%f	%f	%f\n",Head15,ctax1,ctay1,ctaz1,deltaqepsilon,deltaqbeta,Hdeltaqepsilon,Hdeltaqbeta);
			}
			else if (Flag15==2)
			{
				/////////�ڶ���15ms����
				//1 ��Ŀ����rour
				//d.d2[3]=Tdata15[0];
				//d.d2[2]=Tdata15[1];
				//d.d2[1]=Tdata15[2];
				//d.d2[0]=Tdata15[3];
				//rour=d.d1;
				src_buf[50]=Tdata15[0];
				src_buf[51]=Tdata15[1];
				src_buf[52]=Tdata15[2];
				src_buf[53]=Tdata15[3];
				//17 ���߽�2(�ɼ��ߵͣ�qepsilon
				//d.d2[3]=Tdata15[64];
				//d.d2[2]=Tdata15[65];
				//d.d2[1]=Tdata15[66];
				//d.d2[0]=Tdata15[67];
				//qepsilon=d.d1;
				src_buf[54]=Tdata15[64];
				src_buf[55]=Tdata15[65];
				src_buf[56]=Tdata15[66];
				src_buf[57]=Tdata15[67];
				//18 ���߽�2(�ɼ���λ��qbeta
				//d.d2[3]=Tdata15[68];
				//d.d2[2]=Tdata15[69];
				//d.d2[1]=Tdata15[70];
				//d.d2[0]=Tdata15[71];
				//qbeta=d.d1;
				src_buf[58]=Tdata15[68];
				src_buf[59]=Tdata15[69];
				src_buf[60]=Tdata15[70];
				src_buf[61]=Tdata15[71];
				//19 ���߽�1(����ߵͣ�
				//d.d2[3]=Tdata15[72];
				//d.d2[2]=Tdata15[73];
				//d.d2[1]=Tdata15[74];
				//d.d2[0]=Tdata15[75];
				//Hqepsilon=d.d1;
				src_buf[62]=Tdata15[72];
				src_buf[63]=Tdata15[73];
				src_buf[64]=Tdata15[74];
				src_buf[65]=Tdata15[75];
				//20 ���߽�1(���ⷽλ��
				//d.d2[3]=Tdata15[76];
				//d.d2[2]=Tdata15[77];
				//d.d2[1]=Tdata15[78];
				//d.d2[0]=Tdata15[79];
				//Hqbeta=d.d1;
				src_buf[66]=Tdata15[76];
				src_buf[67]=Tdata15[77];
				src_buf[68]=Tdata15[78];
				src_buf[69]=Tdata15[79];
				//23 ����ת��1(����ߵͣ�dHqepsilonj
				//d.d2[3]=Tdata15[88];
				//d.d2[2]=Tdata15[89];
				//d.d2[1]=Tdata15[90];
				//d.d2[0]=Tdata15[91];
				//dHqepsilonj=d.d1;
				src_buf[70]=Tdata15[88];
				src_buf[71]=Tdata15[89];
				src_buf[72]=Tdata15[90];
				src_buf[73]=Tdata15[91];
				//24 ����ת��1(���ⷽλ��dHqbetaj
				//d.d2[3]=Tdata15[92];
				//d.d2[2]=Tdata15[93];
				//d.d2[1]=Tdata15[94];
				//d.d2[0]=Tdata15[95];
				//dHqbetaj=d.d1;
				src_buf[74]=Tdata15[92];
				src_buf[75]=Tdata15[93];
				src_buf[76]=Tdata15[94];
				src_buf[77]=Tdata15[95];

				//49 ����ת��(�ɼ��ߵͣ�dqepsilonj
				//d.d2[3]=Tdata15[192];
				//d.d2[2]=Tdata15[193];
				//d.d2[1]=Tdata15[194];
				//d.d2[0]=Tdata15[195];
				//dqepsilonj=d.d1;
				src_buf[78]=Tdata15[192];
				src_buf[79]=Tdata15[193];
				src_buf[80]=Tdata15[194];
				src_buf[81]=Tdata15[195];
				//50 ����ת��(�ɼ���λ��dqbetaj
				//d.d2[3]=Tdata15[196];
				//d.d2[2]=Tdata15[197];
				//d.d2[1]=Tdata15[198];
				//d.d2[0]=Tdata15[199];
				//dqbetaj=d.d1;
				src_buf[82]=Tdata15[196];
				src_buf[83]=Tdata15[197];
				src_buf[84]=Tdata15[198];
				src_buf[85]=Tdata15[199];


				Flag15=3;
				
				//���
				//fprintf(fid15_2,"%f	%f	%f	%f	%f	%f	%f	%f	%f\n",rour,qepsilon,qbeta,Hqepsilon,Hqbeta,dHqepsilonj,dHqbetaj,dqepsilonj,dqbetaj);

			}
			else if (Flag15==3)
			{
				////////������15ms
				//24 ����ͼ�񱳾���׼��Hsigma
				//d.d2[3]=Tdata15[92];
				//d.d2[2]=Tdata15[93];
				//d.d2[1]=Tdata15[94];
				//d.d2[0]=Tdata15[95];
				//Hsigma=d.d1;
				src_buf[86]=Tdata15[92];
				src_buf[87]=Tdata15[93];
				src_buf[88]=Tdata15[94];
				src_buf[89]=Tdata15[95];
				//27 ��ʱʱ��tgg(0.1ms)
				//tgg=(Tdata15[104]<<24)+(Tdata15[105]<<16)+(Tdata15[106]<<8)+Tdata15[107];
				src_buf[90]=Tdata15[104];
				src_buf[91]=Tdata15[105];
				src_buf[92]=Tdata15[106];
				src_buf[93]=Tdata15[107];
				//29 ����TGunsigned int  TG
				//TG=(Tdata15[112]<<24)+(Tdata15[113]<<16)+(Tdata15[114]<<8)+Tdata15[115];
				src_buf[94]=Tdata15[112];
				src_buf[95]=Tdata15[113];
				src_buf[96]=Tdata15[114];
				src_buf[97]=Tdata15[115];
				//40 ����ͼ�񱳾���ֵHmean
				//Hmean=(Tdata15[150]<<8)+Tdata15[151];
				src_buf[98]=Tdata15[150];
				src_buf[99]=Tdata15[151];
				//43 �ɼ�֡��frameno
				//frameno=(Tdata15[156]<<8)+Tdata15[157];
				src_buf[100]=Tdata15[156];
				src_buf[101]=Tdata15[157];
				//44 ����֡��Hframeno
				//Hframeno=(Tdata15[158]<<8)+Tdata15[159];
				src_buf[102]=Tdata15[158];
				src_buf[103]=Tdata15[159];
				
				//Ԥ�����־
				src_buf[104]=Tdata15[218];

				Flag15=4;
				for(i=105;i<202;i++)
					src_buf[i]=0;
				//���
				//fprintf(fid15_3,"%f	%u	%u	%u	%u	%u\n",Hsigma,tgg,TG,Hmean,frameno,Hframeno);
			}
			
			if (Flag15==4)
				Flag_out=1;
			else
				Flag_out=0;
			
			return Flag_out;
		}
		/*if (data[1]==34)
		{
			fprintf(fid5,"%u	%f	%f	%f\n",rti,thetar,psir,gammar);
			if (Flag15==1)
				fprintf(fid15_1,"%u	%f	%f	%f	%f	%f	%f	%f\n",Head15,ctax1,ctay1,ctaz1,deltaqepsilon,deltaqbeta,Hdeltaqepsilon,Hdeltaqbeta);
			else if(Flag15==2)
				fprintf(fid15_2,"%f	%f	%f	%f	%f	%f	%f	%f	%f\n",rour,qepsilon,qbeta,Hqepsilon,Hqbeta,dHqepsilonj,dHqbetaj,dqepsilonj,dqbetaj);
			else if(Flag15==3)
				fprintf(fid15_3,"%f	%u	%u	%u	%u	%u\n",Hsigma,tgg,TG,Hmean,frameno,Hframeno);
		}*/
	//}
	
}
