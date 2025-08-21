#include <iostream>
using namespace std;

void setPotion(int count, int* p_HPPotion, int* p_MPPotion) {
    *p_HPPotion = count;
    *p_MPPotion = count;
}

int main()
{
    const int SIZE = 4;
    int stat[SIZE] = { 0 }; // 0: HP, 1: MP, 2: 공격력, 3: 방어력

    while (1) {
        cout << "HP와 MP를 입력해주세요: ";
        cin >> stat[0] >> stat[1];

        if (stat[0] > 50 && stat[1] > 50) break;
        cout << "HP나 MP의 값이 너무 작습니다. 다시 입력해주세요." << endl;
    }

    while (1) {
        cout << "공격력과 방어력을 입력해주세요: ";
        cin >> stat[2] >> stat[3];

        if (stat[2] > 0 && stat[3] > 0) break;
        cout << "공격력이나 방어력의 값이 너무 작습니다. 다시 입력해주세요." << endl;
    }

    int choice = 0;
    int HPPotion = 0;
    int MPPotion = 0;

    setPotion(5, &HPPotion, &MPPotion);

    cout << "* 포션이 지급되었습니다. (HP, MP 포션 각 5개)" << endl;
    cout << "=============================================" << endl;
    cout << "<스탯 관리 시스템>" << endl;
    cout << "1. HP 포션 사용 (HP +20)" << endl;
    cout << "2. MP 포션 사용 (MP +20)" << endl;
    cout << "3. HP 2배 증가" << endl;
    cout << "4. MP 2배 증가" << endl;
    cout << "5. 공격 스킬 사용 (MP -50)" << endl;
    cout << "6. 현재 스탯 보기" << endl;
    cout << "7. 프로그램 종료" << endl;
    cout << "=============================================" << endl;

    while (1) {
        cout << "번호를 선택해주세요: ";
        cin >> choice;

        if (choice == 7) {
            cout << "프로그램을 종료합니다." << endl;
            break;
        }

        switch (choice) {
        case 1: // HP 포션
            if (HPPotion <= 0) {
                cout << "HP 포션이 부족합니다." << endl;
                break;
            }
            stat[0] += 20;
            HPPotion--;
            cout << "* HP가 20 회복되었습니다. (남은 HP포션: " << HPPotion << ")" << endl;
            break;

        case 2: // MP 포션
            if (MPPotion <= 0) {
                cout << "MP 포션이 부족합니다." << endl;
                break;
            }
            stat[1] += 20;
            MPPotion--;
            cout << "* MP가 20 회복되었습니다. (남은 MP포션: " << MPPotion << ")" << endl;
            break;

        case 3: // HP 2배 증가
            stat[0] *= 2;
            cout << "* HP가 2배 증가했습니다. (현재 HP: " << stat[0] << ")" << endl;
            break;

        case 4: // MP 2배 증가
            stat[1] *= 2;
            cout << "* MP가 2배 증가했습니다. (현재 MP: " << stat[1] << ")" << endl;
            break;

        case 5: // 공격 스킬 사용
            if (stat[1] < 50) {
                cout << "MP가 부족하여 공격 스킬을 사용할 수 없습니다." << endl;
                break;
            }
            stat[1] -= 50;
            cout << "* 공격 스킬 발동! (MP 50 소모, 남은 MP: " << stat[1] << ")" << endl;
            break;

        case 6: // 현재 스탯 보기
            cout << "============================" << endl;
            cout << "HP: " << stat[0] << endl;
            cout << "MP: " << stat[1] << endl;
            cout << "공격력: " << stat[2] << endl;
            cout << "방어력: " << stat[3] << endl;
            cout << "HP 포션: " << HPPotion << ", MP 포션: " << MPPotion << endl;
            cout << "============================" << endl;
            break;

        default:
            cout << "잘못된 입력입니다. 다시 입력해주세요." << endl;
            break;
        }
    }
    return 0;
}
