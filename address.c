#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

#define size 200
/*���� ���� ��ȭ��ȣ�θ� ����ڽ��ϴ�.
		1. ����
		2. �˻�
		3. ����(����)
		4. ��� 
		5. ����
		*/


typedef struct address{
	char name[20];	
	char hnum[30];
	char pnum[30];
	char memo[100];

}address;

int main()
{
	address add[size];
	
	int i=0; //
	int o=0; //������� ������ �ּ��� ������ ��Ÿ����.��ü ��½� ����Ѵ�.
	int o2=0;//�����Ҷ� [i]�� ���� ���� �����ؾ� �Ǽ� �ѹ� �õ��غ���.
	int select=-1; //������ 1�� �صθ� ó�� if�� ������ ���ϴ�.
	char search[20];//�˻�����
	int result;//�˻����� �� ��Ϻ����� ���� �� �̿� 0�̸� ���� �ƴϸ� �ٸ���.

	int sel=-1;//������ �ұ�ɿ� ���� ����


	while(1)
	{
		printf("-------------------------------------\n");
		printf("��ȭ��ȣ�� ���α׷�\n");
		printf("���ϴ� ����� ��ȣ�� �Է��ϼ���.\n");
		printf("1.���\n");
		printf("2.�˻�\n");
		printf("3.����\n");
		printf("4.��ü���\n");
		printf("5.����\n");
		printf("-------------------------------------\n");
		scanf("%d",&select);

		if(select<1||select>5)
		{
			scanf("%d",&select);
		}

		/*
		���� ������ ���Կ� �־ switch���� if���� �������� �� ����. ��, �����Ϸ� ����ȭ�� ���� �� �� �־ �ӵ��� �� ���� ���̴�.
		�׷��� ���� �ڵ带 �� �� break�� ������ case�� �ν����� ���ؼ� if���� ���.
		*/

		if(select==1)//���
		{
			for(i=o;i<o+1;i++)
			{
				printf("�̸��� �Է��ϼ���(EX:Kimminjee/Jeongminjee):");
				scanf("%s",add[i].name);
		
				printf("�� ��ȭ��ȣ�� �Է��ϼ���(EX: @@@-@@@-@@@@):");
				scanf("%s",&add[i].hnum);
					
				printf("���� ��ȭ��ȣ�� �Է��ϼ���(EX: @@@-@@@@-@@@@):");
				scanf("%s",&add[i].pnum);

				fflush(stdin);//������������ ������ ����.fflush�� ���۸� ���� �Լ��ν� �޸�� ���� �����̽��ٰ� �ʿ���(scanf�� ������) ģ������ ���� õ���.
				printf("�޸� �Է��ϼ���:");
				gets(add[i].memo);
				fflush(stdin);
			}

			o++;
			select=-1;//�ȹٲ��ָ� �ְ� if(select==1)�� ������ �ݺ��ϰ� �ȴ�.
		}

		if(select==2)//�˻�
		{
			printf("�̸��� �Է��ϼ���.(��ҹ��ڸ� ��Ȯ�� �Է��� �ּ���!)\n");
			scanf("%s",&search);

			for(i=0;i<=o;i++)
			{
				result=strcmp(add[i].name, search);

				if(result==0)
				{
					printf("�̸�: %s\t����ȭ: %s\t������ȭ: %s\t�޸�:%s\n",add[i].name,add[i].hnum,add[i].pnum,add[i].memo);
					break;
				}
			}

			if(result!=0)
			{
				printf("������ �����ϴ�.\n");
				break;
			}
		
			select=-1;
		}


		if(select==3)//����
		{
			/*
			�����̶� 2���� �˻��� ����ѵ� ������ ����� �ʿ��ϱ⿡ 2���� �˻������ ���� ����ؾ� �� ���̴�.
			*/


			printf("�̸��� �Է��ϼ���.(��ϵ��� ���� �̸��� �Է��ϸ� �޴�ȭ������ ��ȯ�˴ϴ�!)\n");
			printf("��ҹ��ڸ� ����� �״�� �Է����ּ���!\n");
			scanf("%s",&search);
			
			for(i=0;i<=o;i++)
			{
				result=strcmp(add[i].name, search);

				if(result==0)
				{
					printf("�̸�: %s\t����ȭ: %s\t������ȭ: %s\t�޸�:%s\n",add[i].name,add[i].hnum,add[i].pnum,add[i].memo);

					printf("\n������ �����մϴ�.\n");
					printf("��� �κ��� ��ġ�� �ͽ��ϱ�?\n");
					printf("1.�̸� \t2.����ȭ \t3.������ȭ \t4.�޸� \t5.���\n");
					
					if(sel<1||sel>5)
					{
						scanf("%d",&sel);
					}


					if(sel==1)
					{
						printf("�̸��� �Է��ϼ���:");
						scanf("%s",&add[i].name);
						sel=-1;//�ʱ�ȭ

					}
					if(sel==2)
					{
						printf("�� ��ȭ��ȣ�� �Է��ϼ���:");
						scanf("%s",&add[i].hnum);
						sel=-1;
						
					}
					if(sel==3)
					{
						printf("���� ��ȭ��ȣ�� �Է��ϼ���:");
						scanf("%s",&add[i].pnum);
						sel=-1;
						
					}
					if(sel==4)
					{
						fflush(stdin);
						printf("�޸� �Է��ϼ���:");
						gets(add[i].memo);
						fflush(stdin);
						sel=-1;
						
					}
					if(sel==5)
					{
						printf("�̸��� �Է��ϼ���:");
						scanf("%s",&add[i].name);

						printf("�� ��ȭ��ȣ�� �Է��ϼ���:");
						scanf("%s",&add[i].hnum);

						printf("���� ��ȭ��ȣ�� �Է��ϼ���:");
						scanf("%s",&add[i].pnum);

						fflush(stdin);
						printf("�޸� �Է��ϼ���:");
						gets(add[i].memo);
						fflush(stdin);
						sel=-1;	

					}

				}
			
			}

			select=-1;

			
		}

		if(select==4)//��ü���
		{
			for(i=0;i<o;i++)
			{
				printf("�̸�: %s\t����ȭ: %s\t������ȭ: %s\t�޸�:%s\n",add[i].name,add[i].hnum,add[i].pnum,add[i].memo);
			}
			select=-1;
		}

		if(select==5)
		{
			printf("Good Bye!\n");
			return 0;
		}
	}
	
		return 0;
}