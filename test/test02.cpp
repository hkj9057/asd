#include <iostream>
#include <conio.h> // getch �Լ��� ����ϱ� ���� �߰��Ѵ�
#include <unordered_map>
using namespace std;

// �θ��ڸ� ���ڷ� ��ȯ�ϴ� �Լ�
int romanToNumber(string roman) {
    // �θ��ڿ� �ش��ϴ� ���� �����ϴ� unordered_map
    unordered_map<char, int> romanNumerals = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    int result = 0;
    for (int i = 0; i < roman.size(); i++) {
        // �θ��ڰ� �ƴ� ���ڿ��� �ԷµǸ� ���� ó���Ѵ�
        if (romanNumerals.find(roman[i]) == romanNumerals.end()) {
            cout << "�ùٸ� �θ��ڸ� �Է��ϼ���." << endl;
            return 0;
        }

        // ���� ���ڿ� �ش��ϴ� ���� �����´�
        int current = romanNumerals[roman[i]];

        // ���� ���ڿ� �ش��ϴ� ���� �����´�
        int next = 0;
        if (i + 1 < roman.size()) {
            next = romanNumerals[roman[i + 1]];
        }

        // ���� ���ڰ� ���� ���ں��� ������ ����
        if (current < next) {
            result -= current;
        }
        // �� �ܿ��� ���Ѵ�
        else {
            result += current;
        }
    }

    return result;
}

int main() {
    // �θ��ڸ� �Է¹޴´�
    string roman;
    bool running = true;
    cout << "�θ��ڸ� �Է��ϼ���: ";
    cin >> roman;

    // ESC Ű�� �Է¹��� ������ �ݺ��Ѵ�
    while (running) {
        // �θ��ڸ� ���ڷ� ��ȯ�Ѵ�
        int result = romanToNumber(roman);

        if (result > 3999)
        {
            cout << "3999�� ������ �ȵǿ�" << endl;
        }
        else
        {
            cout << "����: " << result << endl;
        }

        // ESC Ű�� �Է¹����� ���α׷��� �����Ѵ�
        if (_kbhit()) {
            char input = _getch();
            if (input == 27) // ESCŰ
            {
                running = false;
            }
        }

        // �ٽ� �θ��ڸ� �Է¹޴´�
        cout << "�θ��ڸ� �Է��ϼ���: ";
        cin >> roman;
    }

    return 0;
}
