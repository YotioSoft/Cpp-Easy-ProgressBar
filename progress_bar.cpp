#include <stdio.h>
#include <unistd.h>
#include <iostream>

using namespace std;

void progress_bar(unsigned int progress) {
    // 進度を10%刻みに
    progress = (progress / 10) * 10;

    // 100を超えていたら100%に
    if (progress > 100)
        progress = 100;

    // 上書きの準備
    cout << "\r" << string(16, ' ');            // 空白で埋める
    cout << "\r";                               // 先頭へ移動

    // プログレスバーを上書き
    cout << "|";
    cout << string(progress/10, '=');           // (progress/10)文字分をバー(=)で埋める
    if (progress < 100) {
        cout << ">";                            // バーの先端部分（<100%のとき）
        cout << string(10-1-progress/10, ' ');  // (10-1-progress/10)文字分を空白で埋める
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
