// Misaka-NetworkRoute.cpp : �������̨Ӧ�ó������ڵ㡣
//


#include <windows.h> 
#include <stdio.h> 
#include <string> 
using namespace std;

bool AnalysisFile()
{
	bool rState;//����״̬ 
	FILE *file;
	char ln[80];
	fopen_s(&file, "MisakaPingData.txt", "r");

	fgets(ln, 80, file);//������У����� 
	fgets(ln, 80, file);//����ping��Ϣ������ 
	fgets(ln, 80, file);//����ping���󷵻�ֵ���������� 

	string data = ln;
	int iPos = data.find("=");
	data = data.substr(iPos + 1, 3);//��ȡ�ַ��������ֽ��� 
	int n = atoi(data.c_str());
	rState = n > 0;
	fclose(file);
	return rState;
}
void main()
{
	// -n 1ָ������1λ����,-w  
	// 1000ָ������1000msΪ��ʱ 
	// >returnpingdata.txtָ�������з���ֵ�����returnpingdata.txt�ļ��� 
	char *cmdstr = "cmd /c ping steamcommunity.com -n 1 -w 1000 >MisakaPingData.txt";
	WinExec(cmdstr, SW_HIDE);
	Sleep(1000);//�ȴ�1000ms 
	bool returndata = AnalysisFile();//���������з����ļ����õ������������ 
	if (returndata == true)
	{
		printf("steamcommunity.com���ӳɹ�\n");
	}
	else
	{
		printf("steamcommunity.com����ʧ��\n");
	}
	getchar();
}