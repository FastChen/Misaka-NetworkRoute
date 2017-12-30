// Misaka-NetworkRoute.cpp : 定义控制台应用程序的入口点。
//


#include <windows.h> 
#include <stdio.h> 
#include <string> 
using namespace std;

bool AnalysisFile()
{
	bool rState;//返回状态 
	FILE *file;
	char ln[80];
	fopen_s(&file, "MisakaPingData.txt", "r");

	fgets(ln, 80, file);//读入空行，舍弃 
	fgets(ln, 80, file);//读入ping信息，舍弃 
	fgets(ln, 80, file);//读入ping对象返回值，用来分析 

	string data = ln;
	int iPos = data.find("=");
	data = data.substr(iPos + 1, 3);//截取字符串返回字节数 
	int n = atoi(data.c_str());
	rState = n > 0;
	fclose(file);
	return rState;
}
void main()
{
	// -n 1指定发送1位数据,-w  
	// 1000指定超过1000ms为超时 
	// >returnpingdata.txt指定命令行返回值输出到returnpingdata.txt文件中 
	char *cmdstr = "cmd /c ping steamcommunity.com -n 1 -w 1000 >MisakaPingData.txt";
	WinExec(cmdstr, SW_HIDE);
	Sleep(1000);//等待1000ms 
	bool returndata = AnalysisFile();//分析命令行返回文件，得到网络连接情况 
	if (returndata == true)
	{
		printf("steamcommunity.com连接成功\n");
	}
	else
	{
		printf("steamcommunity.com连接失败\n");
	}
	getchar();
}