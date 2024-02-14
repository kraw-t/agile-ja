#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

/*----これらの関数を変更する必要はありません----*/

std::vector<std::string> names {"Nick", "Lewis", "Nikos"};

bool contains(const std::string& name, const std::vector<std::string>& list_of_names) {
    return std::find(list_of_names.begin(), list_of_names.end(), name) != list_of_names.end();
}

std::string get_name(const std::string& name, const std::vector<std::string>& list_of_names) {
    if (contains(name, list_of_names)) {
        return name;
    } else {
        return "";
    }
}

void add_name(const std::string& name, std::vector<std::string>& list_of_names) {
    list_of_names.push_back(name);
}

int add_two(int num) {
    return num + 2;
}

double divide_by_two(double num) {
    return num / 2;
}

std::string greeting(const std::string& name, double num) {
    std::string message {"Hello, " + name + ". It is " + std::to_string(num) + " degrees warmer today than yesterday"};
    std::cout << message << std::endl;
    return message;
}

/*----ここにコードを書いてください----*/
/*----難易度: 富士----*/

// `my_assert` をここに定義し、以降のテストに使用してください。
// 1. `expr` はブール値として評価される式です。
// 2. `msg` はオプションのメッセージであり、`expr` が `false` と評価された場合に例外にスローされます。
void my_assert(bool expr, std::string msg) {
    if (!expr) {
        throw std::logic_error(msg);
    }
    return;
}

// `contains` 用のテスト `test_contains` を作成してください
bool test_contains() {
    bool ret {true};
    const std::vector<std::string> inputs_names {"Nick", "Mike", "Lewis", "Takaaki", "Nikos", "Nickos"};
    const std::vector<bool> expected_returns {true, false, true, false, true, false};

    // テスト入力と期待出力のサイズが一致していない場合は失敗扱いとする
    try {
        my_assert(inputs_names.size() == expected_returns.size(), "the size of input/output are different.");
    } catch (const std::logic_error& e) {
        std::cerr << "Error in test_contains: " << e.what() << std::endl;
        return false;
    }

    bool output {};
    for (int i = 0; i < inputs_names.size(); i++) {
        output = contains(inputs_names[i], names);
        try {
            my_assert(output == expected_returns[i], "expected: " + std::to_string(expected_returns[i]) + ", but actual: " + std::to_string(output) + ".");
        } catch (const std::logic_error& e) {
            std::cerr << "Error in contains: " << e.what() << std::endl;
            ret = false;
        }
    }

    return ret;
}

// `get_name` 用のテスト `test_get_name` を作成してください
bool test_get_name(void) {
    bool ret {true};
    const std::vector<std::vector<std::string>> inputs_and_expected_returns {
        // テスト入力, 期待出力 の順
        {"Nick", "Nick"},
        {"Mike", ""},
        {"Lewis", "Lewis"},
        {"Takaaki", ""},
        {"Nikos", "Nikos"},
        {"Nickos", ""}
    };

    std::string output {};
    for (const auto& test : inputs_and_expected_returns) {
        output = get_name(test[0], names);
        try {
            my_assert(output == test[1], "expected: " + test[1] + ", but actual: " + output + ".");
        } catch (const std::logic_error& e) {
            std::cerr << "Error in get_name: " << e.what() << std::endl;
            ret = false;
        }
    }
    return ret;
}

// `add_name` 用のテスト `test_add_name` を作成してください
bool test_add_name(void) {
    bool ret {true};
    int count {0};
    std::vector<std::string> name_vec;

    for (const auto& name : names) {
        add_name(name, name_vec);
        count++;
        try {
            my_assert(name_vec[count - 1] == name, "expected: " + name + ", but actual: " + name_vec[count - 1] + ".");
            my_assert(name_vec.size() == count, "expected size is " + std::to_string(count) + " but actual size is " + std::to_string(name_vec.size()) + ".");
        } catch (const std::logic_error& e) {
            std::cerr << "Error in add_name: " << e.what() << std::endl;
            ret = false;
        }
    }
    return ret;
}

// `add_two` 用のテスト `test_add_two` を作成してください
bool test_add_two(void) {
    bool ret {true};
    const std::vector<std::vector<int>> inputs_and_expected_returns {
        // テスト入力, 期待出力 の順
        {1, 3},
        {3, 5},
        {-2, 0},
        {-10, -8}
    };

    int output {};
    for (const auto& test : inputs_and_expected_returns) {
        output = add_two(test[0]);
        try {
            my_assert(output == test[1], "expected return is " + std::to_string(test[1]) + " but " + std::to_string(output) + " is returned.");
        } catch (const std::logic_error& e) {
            std::cerr << "Error in add_two: " << e.what() << std::endl;
            ret = false;
        }
    }
    return ret;
}

// `divide_by_two` 用のテスト `test_divide_by_two` を作成してください
bool test_divide_by_two(void) {
    bool ret {true};
    const std::vector<std::vector<double>> inputs_and_expected_returns {
        // テスト入力, 期待出力 の順
        {1.0, 0.5},
        {35.0, 17.5},
        {-200.0, -100.0},
        {0, 0}
    };

    double output {};
    for (const auto& test : inputs_and_expected_returns) {
        output = divide_by_two(test[0]);
        try {
            my_assert(output == test[1], "expected return is " + std::to_string(test[1]) + " but " + std::to_string(output) + " is returned.");
        } catch (const std::logic_error& e) {
            std::cerr << "Error in divide_by_two: " << e.what() << std::endl;
            ret = false;
        }
    }
    return ret;
}

// `greeting` 用のテスト `test_greeting` を作成してください
bool test_greeting(void) {
    int ret {true};
    const std::vector<double> temperatures {3.8, 7.3, 12.6};

    // テスト入力と期待出力のサイズが一致していない場合は失敗扱いとする
    try {
        my_assert(names.size() == temperatures.size(), "the size of input/output are different.");
    } catch (const std::logic_error& e) {
        std::cerr << "Error in test_contains: " << e.what() << std::endl;
        return false;
    }

    std::string output {};
    std::string expected_msg {};
    for (int i = 0; i < names.size(); i++) {
        expected_msg = "Hello, " + names[i] + ". It is " + std::to_string(temperatures[i]) + " degrees warmer today than yesterday";
        output = greeting(names[i], temperatures[i]);
        try {
            my_assert(output == expected_msg, "expected message: \"" + expected_msg + "\"");
        } catch (const std::logic_error& e) {
            std::cerr << "Error in greeting: " << e.what() << std::endl;
            ret = false;
        }
    }
    return ret;
}


/*----難易度: キリマンジャロ----*/

// `my_assert` 用のテスト `test_my_assert_false` を作成し、式がfalseと評価されたときに指定したオプションの `msg` を適切に返すかどうかをチェックしてください。

// `my_assert` 用のテスト `test_my_assert_true` を作成し、式がtrueと評価されたときに適切に処理するかどうかをチェックしてください。

/*----難易度: エベレスト----*/

// 次の式全体をテストする `test_complex_greeting` を `my_assert` を使用して作成してください。式がエラーになった場合は、エラーの理由がわかるメッセージを `msg` に指定してください。
// greeting(get_name("Frosty the Snowman", {"Oatmeal", "Prancer", "Rudolph", "Andy"}), divide_by_two(add_two(2)));


int main() {
    int ret {true};
    ret &= test_contains();
    ret &= test_get_name();
    ret &= test_add_name();
    ret &= test_add_two();
    ret &= test_divide_by_two();
    ret &= test_greeting();

    if (ret) {
        // 全てのretがtrue：エラーなし終了
        return 0;
    } else {
        std::cout << "[FAILED] Some tests ware failed, please check the output logs." << std::endl;
        return 1;
    }
}
