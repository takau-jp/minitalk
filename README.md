# minitalk

42Tokyoのプロジェクト。UNIXシグナル（SIGUSR1/SIGUSR2）を使用したプロセス間通信プログラム。

## 概要

クライアントからサーバーへテキストメッセージを送信します。メッセージは1ビットずつシグナルに変換され、サーバー側で再構築されます。

- `SIGUSR1`: ビット1
- `SIGUSR2`: ビット0

## ビルド

```bash
# 通常ビルド
make

# ボーナス（UTF-8バリデーション付き）
make bonus

# クリーンアップ
make clean   # オブジェクトファイル削除
make fclean  # 全削除
make re      # リビルド
```

## 使用方法

### サーバー起動

```bash
./server
```

サーバーPIDが表示されます。

### メッセージ送信

```bash
./client <server_pid> "送信するメッセージ"
```

## ファイル構成

```
.
├── Makefile
├── include/          # ヘッダファイル
├── mandatory/        # 必須実装
│   ├── client/       # クライアント側
│   ├── server/       # サーバー側
│   └── common/       # 共通処理
├── bonus/            # ボーナス実装（UTF-8対応）
│   ├── client/
│   ├── server/
│   ├── common/
│   └── utf8/         # UTF-8バリデーション
└── libft/            # 自作ライブラリ
```

## 機能

### Mandatory

- シグナルによるビット単位通信
- タイムアウト処理
- エラーハンドリング

### Bonus

- ACK/NAK応答によるフロー制御
- **Unicode 17.0.0準拠のUTF-8バリデーション**
- **最長部分置換（Maximal Subpart Replacement）の実装**

学習のまとめとして執筆した詳細な解説記事: [【Unicode】UTF-8のエラー処理について）](https://qiita.com/takau-jp/items/13b628e0c5542d396fc3)

Unicodeコンソーシアムの公式ドキュメント「3.9.6 U+FFFD Substitution of Maximal Subparts」に基づき、不正なUTF-8シーケンスを適切に処理します。

#### 最長部分置換とは

W3Cで採用されているUTF-8エラー処理戦略。不正なバイトシーケンスを検出した際、「正しい形式の先頭部分列」を最大限認識し、単一の置換文字（U+FFFD）に変換します。

| パターン | 条件 | 処理 |
|----------|------|------|
| 1 | 先頭バイトが不正 | 当該1バイトをU+FFFDに置換 |
| 2 | 2バイト目が不正 | 既読の有効な1バイトを置換、新バイトを再検査 |
| 3 | 3〜4バイト目が不正 | 既読の複数バイトを単一のU+FFFDに変換 |
