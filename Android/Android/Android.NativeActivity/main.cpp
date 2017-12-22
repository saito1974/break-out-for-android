//①	『ソリューションエクスプローラー』と書かれているリストにある『main.cpp』をダブルクリックして内容を
//表示した状態でメニューから『ファイル(F)』→『名前を付けて main.cpp を保存(A)...』を選択して
//『名前を付けてファイルを保存』ダイアログを表示します。
//
//②　『名前を付けてファイルを保存』ダイアログの右下にある『上書き保存(S)』の項目を『エンコード付きで保存(V)...』
//に変更します。すると変更した瞬間に『名前を付けて保存の確認』ダイアログが表示されますので『はい(Y)』を選択してください。
//
//③　次に『保存オプションの詳細設定』ダイアログが表示されたら、その中の『エンコード(E) :』の項目を
//『日本語(シフトJIS) - コードページ 932』から『Unicode(UTF - 8 シグネチャ付き) - コードページ 65001』に
//変更して『OK』ボタンを押します。
//
//これで『main.cpp』の文字コード形式が『UTF - 8』になります。
//因みに cppファイルや hファイルを新規作成した場合も、初期状態では『シフトJIS』となっていますので、
//ソースファイルを新規作成した際もこの操作を行って文字コード形式を『シフトJIS』から『UTF - 8』に変更
//するようにしてください。

#include "./DxLib/DxLib.h"

int android_main(void)
{

	const int SCREEN_WIDIH = 720;
	const int SCREEN_HEIGHT = 1280;
	//ログ消し
	SetOutApplicationLogValidFlag(FALSE);

	//画面サイズ変更
	SetGraphMode(SCREEN_WIDIH, SCREEN_HEIGHT, 32);
	//ウィンドウモード変更と初期化と裏画面設定

	if (DxLib_Init() == -1)  { return -1; }
		         
	SetDrawScreen(DX_SCREEN_BACK);

	int y = 0;

	while (ProcessMessage() == 0)
	{
		ClearDrawScreen();
		DrawBox(10, ++y, 100, 100, GetColor(255, 255, 255), true);	//四角が下に伸びる
		DrawFormatString(10, 0, GetColor(255, 0, 0), "タップで鳴らせるよ");
		ScreenFlip();
	}

	DxLib_End();
	return 0;
}