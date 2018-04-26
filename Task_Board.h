#pragma warning(disable:4996)
#pragma once
//-------------------------------------------------------------------
//
//-------------------------------------------------------------------
#include "GameEngine_Ver3_7.h"

namespace  Board
{
	//�^�X�N�Ɋ��蓖�Ă�O���[�v���ƌŗL��
	const  string  defGroupName(		"�{�[�h");	//�O���[�v��
	const  string  defName(				"NoName");	//�^�X�N��
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
		//���L����ϐ��͂����ɒǉ�����
	};
	//-------------------------------------------------------------------
	class  Object : public  BTask
	{
	//�ύX�s����������������������������������������������������
	public:
		virtual  ~Object();
		typedef  shared_ptr<Object>		SP;
		typedef  weak_ptr<Object>		WP;
		//�������� ������true�Ń^�X�N�V�X�e���֎����o�^
		static  Object::SP  Create(bool flagGameEnginePushBack_);
		Resource::SP	res;
	private:
		Object();
		bool  B_Initialize();
		bool  B_Finalize();
		bool  Initialize();	//�u�������v�^�X�N�������ɂP�񂾂��s������
		void  UpDate();		//�u���s�v�P�t���[�����ɍs������
		void  Render2D_AF();	//�u2D�`��v�P�t���[�����ɍs������
		bool  Finalize();		//�u�I���v�^�X�N���Ŏ��ɂP�񂾂��s������
	//�ύX������������������������������������������������������
	public:
		//�ǉ��������ϐ��E���\�b�h�͂����ɒǉ�����
		string				BackImg;
		string				CardImg;
		string				PlayerImg;
		int card_arr[3][6] = {     //�J�[�h�̗p��
			{ 0,0,0,0,1,1 },
			{ 1,1,2,2,2,2 },
			{ 3,3,4,4,5,5 } 
		};
		ML::Box2D			card_draw[3][6];
		ML::Box2D			card_src[3][6];
		int					CardMotion[3][6];//0:���G1:�ʂ������G2:�����G3:�s�����G-1:����Ă���G
		int					motion;//0:�~�܂��Ă���G1:�E�ֈړ��G2:���ֈړ��G
		int					keepx;//�J�[�\����easing�ړ����W
		int					keepy;
		int					posx;//�J�[�\���̈ʒu���W
		int					posy;
		int                 clickCnt;//�����ڂ������ꂽ��
		int                 kpCard;//�ꖇ�ڂ̔ԍ�
		bool                flag;//���𔻒�t���O

		bool Object::checkClear();
	};
}