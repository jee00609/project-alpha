#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

#define size 200
/*���� ���� ��ȭ��ȣ�θ� ����ڽ��ϴ�.
		1. ����
		2. �˻�
		3. ����
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
				printf("�̸��� �Է��ϼ���:");
				scanf("%s",&add[i].name);
		
				printf("�� ��ȭ��ȣ�� �Է��ϼ���:");
				scanf("%s",&add[i].hnum);
					
				printf("���� ��ȭ��ȣ�� �Է��ϼ���:");
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
			printf("�̸��� �Է��ϼ���.");
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
				printf("������ �����ϴ�\n");
			}
			select=-1;

		}

		if(select==3)//����
		{
			/*
			�����̶� 2���� �˻��� ����ѵ� ������ ����� �ʿ��ϱ⿡ 2���� �˻������ ���� ����ؾ� �� ���̴�.
			*/


			printf("�̸��� �Է��ϼ���.");
			scanf("%s",&search);
			
			for(i=0;i<=o;i++)
			{
				result=strcmp(add[i].name, search);

				if(result==0)
				{
					printf("�̸�: %s\t����ȭ: %s\t������ȭ: %s\t",add[i].name,add[i].hnum,add[i].pnum);
					puts(add[i].memo);

					printf("\n������ �����մϴ�.\n");
					
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

				}
			}

			if(result!=0)
			{
				printf("������ �����ϴ�\n");
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
			return 0;
		}
	}
	
		return 0;
}