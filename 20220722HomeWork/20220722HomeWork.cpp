// TextRpg.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <conio.h>

// 객체지향에서는 존재할수 없는 문법입니다.
//  int TestValue = 0;

void Status(int Hp, int Att)
{
    printf_s("----------------------------------------------------\n");
    printf_s("Hp %d\n", Hp);
    printf_s("Att %d\n", Att);
    printf_s("----------------------------------------------------\n");
}

void Damage(int* Hp, int Att)
{
    // printf에는 특수한 기능이 있는
    // %기호를 쓰고 알파뱃을 사용하면
    // 정수를 출력할수 있는 기능이 있습니다.
    // 지금은 그냥 이렇게 사용하면 숫자가 나오는 구나
    printf_s("%d의 데미지를 입었습니다.\n", Att);

    *Hp -= Att;
}

int PlayerHp = 100;

int main()
{
    // 이런 스타일을 절차지향 혹은 c스타일 코딩이라고 합니다.
    // 객체지향을 배운다는 프로그래머라면 정확하게 표현할수가 있어야 하는데.
    // 객체를 지향한다.
    // 객체를 최대한 써서 프로그래밍 한다.
    // 객체가 뭔가?
    // object란 뭔가요?
    // 다들 생각해본적이 없는것 같더라고요?????
    // 객체는 두가지 특성

    // 사물의 특성과 행동을 하나로 모아서 표현할수 있는 문법이 있어야 합니다.
    // 사물 => 모든것 드래곤
    // 특성 => 데이터 방어력
    // 행동 => 함수   불을뿜는다.

    // 그 문법을 기반으로 만들어진 n바이트 이상의 크기를 가지는 메모리를
    // => 객체라고 합니다

    // 모든건 사물을 표현하기 위한 문법으로 표현되어야 합니다.
    // =>전역은 존재할수가 없습니다.

    // c++은 객체지향만 지향하는 언어가 아닙니다.
    // c++ => 객체지향 + 절차지향 + 메타프로그래밍


    int PlayerAtt = 10;
    int MonsterHp = 100;
    int MonsterAtt = 10;

    while (PlayerHp)
    {
        // 콘솔화면을 한번 깨끗하게 삭제해주는 함수
        system("cls");

        //printMesh("gggg.fbx", 100, 200);
        //printImage("aaa.png", 100, 200);

        printf_s("플레이어 스테이터스\n");
        Status(PlayerHp, PlayerAtt);
        printf_s("몬스터 스테이터스\n");
        Status(MonsterHp, MonsterAtt);

        _getch();
        printf_s("몬스터가 ");
        Damage(&MonsterHp, PlayerAtt);
        system("cls");
        printf_s("플레이어 스테이터스\n");
        Status(PlayerHp, PlayerAtt);
        printf_s("몬스터 스테이터스\n");
        Status(MonsterHp, MonsterAtt);
        printf_s("몬스터가 10의 데미지를 받았습니다");

        _getch();
        printf_s("플레이어가 ");
        Damage(&PlayerHp, MonsterAtt);
        system("cls");
        printf_s("플레이어 스테이터스\n");
        Status(PlayerHp, PlayerAtt);
        printf_s("몬스터 스테이터스\n");
        Status(MonsterHp, MonsterAtt);
        printf_s("플레이어 10의 데미지를 받았습니다\n");

        // PlayerHp -= 0;

        if (0 < PlayerHp)
        {
            printf_s("플레이어는 생존했습니다.\n");
        }

        _getch();
    }
}
