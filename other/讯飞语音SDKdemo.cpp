/*
//��������
	// ��������-����������
	// VC++Ŀ¼-������Ŀ¼-��include
			   -����Ŀ¼-��libs
*/





#ifdef _WIN64
#pragma comment(lib,"msc_x64.lib")
#else
#pragma comment(lib,"msc.lib")
#endif


#pragma comment(lib,"winMM.lib")

#define  _CRT_SECURE_NO_WARNINGS
#include <msp_cmn.h>
#include <msp_errors.h>
#include <stdio.h>
#include <qtts.h>
#include <string.h>
#include <windows.h>





typedef struct _wave_pcm_hdr
{
	char riff[4];
	int size_8;
	char wave[4];
	char fmt[4];
	int fmt_size;

	short int format_tag;
	short int channels;
	int samples_per_sec;
	int avg_bytes_per_sec;
	short int block_align;
	short int bits_per_sample;

	char data[4];
	int data_size;
}wave_pcm_hdr;

wave_pcm_hdr default_wav_hdr =
{
	{'R','I','F','F'},
	0,
	{'W','A','V','E'},
	{'f','m','t',' '},
	16,
	1,
	1,
	16000,
	32000,
	2,
	16,
	{'d','a','t','a'},
	0
};

int main()
{
	//��ʼ��msc���û���¼
	const char* usr = NULL;
	const char* pwd = NULL;
	const char* lgi_param = "appid = 584bdef9";
	int ret = MSPLogin(usr, pwd, lgi_param);
	if (MSP_SUCCESS != ret)
	{
		printf("MSPLogin failed, error code is: %d", ret);
	}

	//��ʼһ�������ϳɣ����������ϳ���Դ��
	const char * ssb_param = "voice_name = xiaoyan, aue = speex-wb;7, sample_rate = 16000, speed = 50, volume = 50, pitch = 50, rdn = 2";
	ret = -1;
	const char * sessionID = QTTSSessionBegin(ssb_param, &ret);
	if (MSP_SUCCESS != ret)
	{
		printf("QTTSSessionBegin failed, error code is : %d", ret);
	}

	//���ô��ϳ��ı�
	const char* src_text = "�ƴ�Ѷ�ɹɷ����޹�˾";
	unsigned int text_len = strlen(src_text); //textLen����Ϊ�ϳ��ı���ռ�ֽ���
	ret = QTTSTextPut(sessionID, src_text, text_len, NULL);
	if (MSP_SUCCESS != ret)
	{
		printf("QTTSTextPut failed, error code is : %d", ret);
	}

	//��ȡ�ϳ���Ƶ
	FILE* fp = fopen("wrz155.wav", "wb");
	fwrite(&default_wav_hdr, sizeof(default_wav_hdr), 1, fp);
	unsigned int audio_len = 0;
	int synth_status = 0;

	while (1)
	{
		const void * data = QTTSAudioGet(sessionID, &audio_len, &synth_status, &ret);
		if (NULL != data)
		{
			fwrite(data, audio_len, 1, fp);
			default_wav_hdr.data_size += audio_len;
		}
		if (MSP_TTS_FLAG_DATA_END == synth_status || MSP_SUCCESS != ret)
		{
			break;
		}
	}
	
	default_wav_hdr.size_8 += default_wav_hdr.data_size + (sizeof(default_wav_hdr) - 8);
	fseek(fp, 4, 0);
	fwrite(&default_wav_hdr.size_8, sizeof(default_wav_hdr.size_8), 1, fp);
	fseek(fp, 40, 0);
	fwrite(&default_wav_hdr.data_size, sizeof(default_wav_hdr.data_size), 1, fp);
	fclose(fp);



	//�������������ϳ�
	ret = QTTSSessionEnd(sessionID, "normal end");
	if (MSP_SUCCESS != ret)
	{
		printf("QTTSSessionEnd failed, error code is : %d", ret);
	}

	PlaySoundA("wrz155.wav",NULL,SND_ASYNC);

	//�˳���¼
	ret = MSPLogout();
	if (MSP_SUCCESS != ret)
	{
		printf("MSPLogout failed, error code is: %d", ret);
	}

	system("pause");
	return 0;
}