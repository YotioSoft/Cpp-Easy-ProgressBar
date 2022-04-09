#include <stdio.h>
#include <unistd.h>
#include <iostream>

#define INCREMENTS  10

using namespace std;

void progress_bar(unsigned int progress) {
    // 100を超えていたら100%に
    if (progress > 100)
        progress = 100;
    
    // 進度をINCREMENTS%刻みに（100%の場合はそのまま）
    if (progress < 100)
        progress = (progress / INCREMENTS) * INCREMENTS;

    // 上書きの準備
    cout << "\r" << string(16, ' ');            // 空白で埋める
    cout << "\r";                               // 先頭へ移動

    // プログレスバーを上書き
    cout << "|";
    cout << string(progress/INCREMENTS, '=');   // (progress/INCREMENTS)文字分をバー(=)で埋める
    if (progress < 100) {
        cout << ">";                                                // バーの先端部分
        cout << string(100/INCREMENTS-1-progress/INCREMENTS, ' ');  // 残りを空白で埋める
    }
    
    cout << "|";
}

int main() {
    // 1秒おきに5％ずつ増加
    for (int p=0; p<=100; p+=5) {
        progress_bar(p);
        cout << " " << p << "%" << flush;
        sleep(1);   // 1秒間待つ
    }
    cout << endl;
}
