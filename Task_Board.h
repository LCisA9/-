#pragma warning(disable:4996)
#pragma once
//-------------------------------------------------------------------
//
//-------------------------------------------------------------------
#include "GameEngine_Ver3_7.h"

namespace  Board
{
	//タスクに割り当てるグループ名と固有名
	const  string  defGroupName(		"ボード");	//グループ名
	const  string  defName(				"NoName");	//タスク名
	//-------------------------------------------------------------------
	class  Resource
	{
		bool  Initialize();
		bool  Finalize();
		Resource();
	public:
		~Resource();
		typedef  shared_ptr<Resource>	SP;
		typedef  weak_ptr<Resource>		WP;
		static   WP  instance;
		static  Resource::SP  Create();
		//共有する変数はここに追加する
	};
	//-------------------------------------------------------------------
	class  Object : public  BTask
	{
	//変更不可◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆
	public:
		virtual  ~Object();
		typedef  shared_ptr<Object>		SP;
		typedef  weak_ptr<Object>		WP;
		//生成窓口 引数はtrueでタスクシステムへ自動登録
		static  Object::SP  Create(bool flagGameEnginePushBack_);
		Resource::SP	res;
	private:
		Object();
		bool  B_Initialize();
		bool  B_Finalize();
		bool  Initialize();	//「初期化」タスク生成時に１回だけ行う処理
		void  UpDate();		//「実行」１フレーム毎に行う処理
		void  Render2D_AF();	//「2D描画」１フレーム毎に行う処理
		bool  Finalize();		//「終了」タスク消滅時に１回だけ行う処理
	//変更可◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇
	public:
		//追加したい変数・メソッドはここに追加する
		string				BackImg;
		string				CardImg;
		string				PlayerImg;
		int card_arr[3][6] = {     //カードの用意
			{ 0,0,0,0,1,1 },
			{ 1,1,2,2,2,2 },
			{ 3,3,4,4,5,5 } 
		};
		ML::Box2D			card_draw[3][6];
		ML::Box2D			card_src[3][6];
		int					CardMotion[3][6];//0:裏；1:ぬくった；2:正解；3:不正解；-1:回っている；
		int					motion;//0:止まっている；1:右へ移動；2:左へ移動；
		int					keepx;//カーソルのeasing移動座標
		int					keepy;
		int					posx;//カーソルの位置座標
		int					posy;
		int                 clickCnt;//何枚目が押されたか
		int                 kpCard;//一枚目の番号
		bool                flag;//正解判定フラグ

		bool Object::checkClear();
	};
}