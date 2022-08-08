// StringTest.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <cassert>
#include <Windows.h>

// 첫번째 문자열 5
   // std::string을 적극 이용해라
   // 인터넷 검색을 해서 함수들을 확인해라.

// 두번째 파일입출력 5
    // 확장자는 아무의미 없다.
    // 바이너리냐 텍스트냐가 중요한것.
    // 자주 저장해봤어야 합니다.
    // 테스트가 편해집니다.

// 세번째 디버깅 90
    // 디버깅을 잘한다는것은 사실 그냥 프로그래밍을 잘한다는 겁니다.
    // 프로그래머라는 겁니다.
    // 안된다라고 말하는것보다 설명하려고 노력하세요.
    // 단계적으로 설명하려고 노력하는게 가장 중요합니다.
    // 질문에 세부사항을 한꺼번에 보내면 됩니다.

    // 왜 그렇게 될거라고 생각했는지 근본지식을 상대에게 설명해줘야 합니다.
    // => 왜 안되는지를 안다.


std::string StringChange(const std::string& _Src, const std::string& _Old, const std::string& _New)
{
    // std::string NewTest = "asdfasdfasdfsadfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasd";
    // return NewTest;

    std::string NewString = _Src;

    size_t OldSize = _Old.size();
    size_t NewSize = _New.size();

    assert(OldSize == NewSize);

    size_t FindIndex = NewString.find(_Old);

    for (size_t i = 0; i < OldSize; ++i)
    {
        NewString[FindIndex + i] = _New[i];
    }

    return NewString;
}

std::vector<std::string> StringSplit(const std::string& _Src, const std::string& _Value)
{
    std::string Text = _Src;

    std::vector<std::string> vecResult;

    int TextSize = static_cast<int>(Text.size());

    while (TextSize > 0)
    {
        std::string AccText;

        int FindIndex = static_cast<int>(Text.find(_Value));

        for (int i = 0; i < FindIndex + 1; ++i)
        {
            if (i < FindIndex)
                AccText.push_back(*Text.begin());

            Text.erase(Text.begin());
            --TextSize;
        }
        // FindIndex가 -1이라면 찾지못했다는 의미이다
        // 그러므로 해당 스트링배열에 남아있는 녀석이 있다면 모든 녀석을 채워준다.
        if (FindIndex == -1)
        {
            size_t Size = Text.size();
            for (size_t i = 0; i < Size; ++i)
            {
                AccText.push_back(Text[i]);
                --TextSize;
            }
        }

        if (AccText != "")
            vecResult.push_back(AccText);
    }

    return vecResult;
}

int main()
{
    std::string Name = StringChange("AAABBBCCC", "BBB", "abc");

    std::vector<std::string> Test = StringSplit("aaa,bbb,ccc", "a");

    size_t Size = Name.size();
    for (size_t i = 0; i < Size; ++i)
    {
        std::cout << Name[i];

        if (i < Size - 1)
            std::cout << ", ";
    }

    std::cout << "\n";

    Size = Test.size();
    for (size_t i = 0; i < Size; ++i)
    {
        std::cout << Test[i];

        if (i < Size - 1)
            std::cout << ", ";
    }
}
