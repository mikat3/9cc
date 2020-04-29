#include "9cc.h"

int main(int argc, char **argv) {
  if (argc != 2)
    error("引数の個数が正しくありません");
  

  // 文字列全体を保存する
  user_input = argv[1];
  
  // トークナイズする
  token = tokenize(user_input);

  // パースする
  Node *node = expr();

  // アセンブリの前半部分を出力
  printf(".intel_syntax noprefix\n");
  printf(".global main\n");
  printf("main:\n");

  // 抽象構文木を下りながらコード生成
  // Traverse the AST(Abstruct Syntax Tree) to emit assembly.
  gen(node);

  // スタックトップに式全体の値が残っているはずなので
  // それをRAXにロードして関数からの返り値とする
  // A result must be at the top of the stack, so pop it
  // to RAX to make it a program exit code.
  printf("  pop rax\n");
  printf("  ret\n");

  return 0;
}

