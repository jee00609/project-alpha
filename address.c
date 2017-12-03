#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

#define size 200
/*이제 부터 전화번호부를 만들겠습니다.
		1. 저장
		2. 검색
		3. 편집(각자)
		4. 출력 
		5. 종료
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
	int o=0; //현재까지 저장한 주소의 갯수를 나타낸다.전체 출력시 사용한다.
	int o2=0;//편집할때 [i]와 같은 수를 저장해야 되서 한번 시도해본다.
	int select=-1; //선택을 1로 해두면 처음 if문 돌릴때 편하다.
	char search[20];//검색변수
	int result;//검색변수 와 등록변수를 비교할 때 이용 0이면 같고 아니면 다르다.

	int sel=-1;//편집의 소기능에 넣을 변수


	while(1)
	{
		printf("-------------------------------------\n");
		printf("전화번호부 프로그램\n");
		printf("원하는 기능의 번호를 입력하세요.\n");
		printf("1.등록\n");
		printf("2.검색\n");
		printf("3.편집\n");
		printf("4.전체출력\n");
		printf("5.종료\n");
		printf("-------------------------------------\n");
		scanf("%d",&select);

		if(select<1||select>5)
		{
			scanf("%d",&select);
		}

		/*
		같은 변수를 비교함에 있어서 switch문이 if보다 가독성이 더 좋다. 또, 컴파일러 최적화를 쉽게 할 수 있어서 속도도 더 빠른 편이다.
		그런데 여러 코드를 쓸 때 break문 이후의 case를 인식하지 못해서 if문을 썼다.
		*/

		if(select==1)//등록
		{
			for(i=o;i<o+1;i++)
			{
				printf("이름을 입력하세요(EX:Kimminjee/Jeongminjee):");
				scanf("%s",add[i].name);
		
				printf("집 전화번호를 입력하세요(EX: @@@-@@@-@@@@):");
				scanf("%s",&add[i].hnum);
					
				printf("개인 전화번호를 입력하세요(EX: @@@-@@@@-@@@@):");
				scanf("%s",&add[i].pnum);

				fflush(stdin);//써주지않으면 루프가 돈다.fflush는 버퍼를 비우는 함수로써 메모와 같은 스페이스바가 필요한(scanf를 못쓰는) 친구들을 위한 천사다.
				printf("메모 입력하세요:");
				gets(add[i].memo);
				fflush(stdin);
			}

			o++;
			select=-1;//안바꿔주면 애가 if(select==1)의 문장을 반복하게 된다.
		}

		if(select==2)//검색
		{
			printf("이름을 입력하세요.(대소문자를 정확히 입력해 주세요!)\n");
			scanf("%s",&search);

			for(i=0;i<=o;i++)
			{
				result=strcmp(add[i].name, search);

				if(result==0)
				{
					printf("이름: %s\t집전화: %s\t개인전화: %s\t메모:%s\n",add[i].name,add[i].hnum,add[i].pnum,add[i].memo);
					break;
				}
			}

			if(result!=0)
			{
				printf("정보가 없습니다.\n");
				break;
			}
		
			select=-1;
		}


		if(select==3)//편집
		{
			/*
			편집이란 2번의 검색과 비슷한데 편집할 대상이 필요하기에 2번의 검색기능을 먼저 사용해야 할 것이다.
			*/


			printf("이름을 입력하세요.(등록되지 않은 이름을 입력하면 메뉴화면으로 전환됩니다!)\n");
			printf("대소문자를 등록한 그대로 입력해주세요!\n");
			scanf("%s",&search);
			
			for(i=0;i<=o;i++)
			{
				result=strcmp(add[i].name, search);

				if(result==0)
				{
					printf("이름: %s\t집전화: %s\t개인전화: %s\t메모:%s\n",add[i].name,add[i].hnum,add[i].pnum,add[i].memo);

					printf("\n편집을 시작합니다.\n");
					printf("어느 부분을 고치고 싶습니까?\n");
					printf("1.이름 \t2.집전화 \t3.개인전화 \t4.메모 \t5.모두\n");
					
					if(sel<1||sel>5)
					{
						scanf("%d",&sel);
					}


					if(sel==1)
					{
						printf("이름을 입력하세요:");
						scanf("%s",&add[i].name);
						sel=-1;//초기화

					}
					if(sel==2)
					{
						printf("집 전화번호를 입력하세요:");
						scanf("%s",&add[i].hnum);
						sel=-1;
						
					}
					if(sel==3)
					{
						printf("개인 전화번호를 입력하세요:");
						scanf("%s",&add[i].pnum);
						sel=-1;
						
					}
					if(sel==4)
					{
						fflush(stdin);
						printf("메모 입력하세요:");
						gets(add[i].memo);
						fflush(stdin);
						sel=-1;
						
					}
					if(sel==5)
					{
						printf("이름을 입력하세요:");
						scanf("%s",&add[i].name);

						printf("집 전화번호를 입력하세요:");
						scanf("%s",&add[i].hnum);

						printf("개인 전화번호를 입력하세요:");
						scanf("%s",&add[i].pnum);

						fflush(stdin);
						printf("메모 입력하세요:");
						gets(add[i].memo);
						fflush(stdin);
						sel=-1;	

					}

				}
			
			}

			select=-1;

			
		}

		if(select==4)//전체출력
		{
			for(i=0;i<o;i++)
			{
				printf("이름: %s\t집전화: %s\t개인전화: %s\t메모:%s\n",add[i].name,add[i].hnum,add[i].pnum,add[i].memo);
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