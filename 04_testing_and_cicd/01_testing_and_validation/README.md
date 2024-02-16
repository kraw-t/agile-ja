# チャレンジ1: テストと検証
​
## 説明
テストに関する知識を活用し、次の要件を満たすようにしてください。
- このチャレンジで必須の要件は「富士」だけです。
- 「キリマンジャロ」はオプションです。
​
## 標準レベルの要件
次の2つの引数を受け取る関数 `my_assert` をC++で書いてください。
1. `expr` はブール値として評価される式です。
2. `msg` はオプションのメッセージであり、`expr` が `false` と評価された場合に例外にスローされます。
​
次に、`my_assert` を使用して、ここに書かれている関数をテストします。「/*----ここにコードを書いてください----*/」というコメント以降にコードを書いてください。
​
```cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
​
/*----これらの関数を変更する必要はありません----*/
​​
bool contains(const std::string& name, const std::vector<std::string>& list_of_names) {
    return std::find(list_of_names.begin(), list_of_names.end(), name) != list_of_names.end();
}
​
void add_name(const std::string& name, std::vector<std::string>& list_of_names) {
    list_of_names.push_back(name);
}
​
int add_two(int num) {
    return num + 2;
}
​
double divide_by_two(double num) {
    return num / 2;
}
​
std::string greeting(const std::string& name, double num) {
    std::string message {"Hello, " + name + ". It is " + std::to_string(num) + " degrees warmer today than yesterday"};
    return message;
}
​
/*----ここにコードを書いてください----*/
/*----難易度: 富士----*/
​
// `my_assert` をここに定義し、以降のテストに使用してください。
​
// `contains` 用のテスト `test_contains` を作成してください
​​
// `add_name` 用のテスト `test_add_name` を作成してください
​
// `add_two` 用のテスト `test_add_two` を作成してください
​
// `divide_by_two` 用のテスト `test_divide_by_two` を作成してください
​
// `greeting` 用のテスト `test_greeting` を作成してください
​
​
/*----難易度: キリマンジャロ----*/
​
// `my_assert` 用のテスト `test_my_assert_false` を作成し、式がfalseと評価されたときに指定したオプションの `msg` を適切に返すかどうかをチェックしてください。
​
// `my_assert` 用のテスト `test_my_assert_true` を作成し、式がtrueと評価されたときに適切に処理するかどうかをチェックしてください。
​
```
